#include "stdafx.h"
#include "character.h"


HRESULT character::init(string characterName, vector2D pos, string animationKeyName)
{
	gameObject::init(characterName, "", pos);
	this->setAnimation(animationKeyName);
	this->setSize(_animation->getFrameWidth(), _animation->getFrameHeight());

	_commandResetTimer = COMMAND_RESET_TIME;
	_historyCheck = true;

	_isGravity = true;
	_gravitySpeed = 0;

	//피격 콜백 추가
	this->addCallback("attacked", [this](tagMessage msg)
	{
		this->attacked(msg.data, msg.ptData);	
	});


	return S_OK;
}
void character::release()
{
	gameObject::release();
}
void character::update()
{
	gameObject::update();

	//커맨드 업데이트
	updaetCommand();
	//중력 처리
	if (_isGravity)
		gravity();

	//캐릭터의 x좌표 보정
	RECT cameraRC = CAMERAMANAGER->getRenderRect();
	_pos.fixedPosX(cameraRC.left, cameraRC.right);

	this->_animation->frameUpdate();
}

void character::render()
{
	gameObject::render();

	//디버그 모드일 경우 히트박스 렉트를 그려준다.
	if (_isDebugMode)
	{
		//카메라 렌더링 영역
		RECT cameraRC = CAMERAMANAGER->getRenderRect();
		//상대좌표 구하기
		POINT renderPos = { _pos.x - cameraRC.left, _pos.y - cameraRC.top };

		//상대좌표를 기준으로 만든 렌더링 렉트
		vector2D size = getSize();
		RECT renderRC = RectMakeCenter(renderPos.x, renderPos.y, size.x, size.y);

		//충돌 영역 렉트
		RECT collisionRC = this->getCollisionRect();
		MoveRect(&collisionRC, -cameraRC.left, -cameraRC.top);

		//히트박스 영역 표시
		HPEN bluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		HPEN oldPen;
		HBRUSH oldBrush;
		HDC memDC = getMemDC();

		oldPen = (HPEN)SelectObject(memDC, bluePen);
		oldBrush = (HBRUSH)SelectObject(memDC, GetStockObject(NULL_BRUSH));

		Rectangle(memDC, collisionRC.left, collisionRC.top, collisionRC.right, collisionRC.bottom);

		SelectObject(memDC, oldBrush);
		SelectObject(memDC, oldPen);

		DeleteObject(bluePen);

		//이미지 전체 크기 표시
		HPEN yelloBrush = CreatePen(PS_SOLID, 1, RGB(255, 255, 0));

		oldPen = (HPEN)SelectObject(memDC, yelloBrush);
		oldBrush = (HBRUSH)SelectObject(memDC, GetStockObject(NULL_BRUSH));

		Rectangle(memDC, renderRC.left, renderRC.top, renderRC.right, renderRC.bottom);

		SelectObject(memDC, oldBrush);
		SelectObject(memDC, oldPen);

		DeleteObject(yelloBrush);

		//캐릭터의 중심점 그리기
		oldBrush = (HBRUSH)SelectObject(memDC, GetStockObject(COLOR_BACKGROUND));
		Ellipse(memDC, renderPos.x - 3, renderPos.y - 3, renderPos.x + 3, renderPos.y + 3);
		SelectObject(memDC, oldBrush);

	}
}

RECT character::getCollisionRect()
{
	//LEFT_TOP 좌표를 구한다.
	vector2D oldSize = this->getOriginSize();
	vector2D size = this->getSize();

	vector2D leftTop;
	leftTop.x = _pos.x - (size.x * 0.5f);
	leftTop.y = _pos.y - (size.y * 0.5f);

	RECT collisionRC = _animation->getCollisionRect();
	collisionRC.left *= size.x / oldSize.x;
	collisionRC.top *= size.y / oldSize.y;
	collisionRC.right *= size.x / oldSize.x;
	collisionRC.bottom *= size.y / oldSize.y;

	MoveRect(&collisionRC, leftTop.x, leftTop.y);
	return collisionRC;
}

void character::addCommand(int* arrKeyCode, int arrLen, string message)
{
	vector<int> commandList;
	for (int i = arrLen-1; i >=0; --i)
	{
		commandList.emplace_back(arrKeyCode[i]);
	}
	_commandList.emplace_back(make_pair(commandList, message));
}

void character::updaetCommand()
{
	//커맨드 히스토리 체크
	for (int i = 0; i < key::END; ++i)
	{
		if (KEYMANAGER->isOnceKeyDown(keyList[i]))
		{
			_historyCheck = true;
			if (_historyCheck)
			{
				_historyCheck = false;
				_commandResetTimer = COMMAND_RESET_TIME;
				_commandHistory.emplace_front(i);
				if (_commandHistory.size() > 5)
					_commandHistory.pop_back();
			}
		}
	}

	//오래된 커맨드 하나씩 삭제
	_commandResetTimer -= TIMEMANAGER->getElapsedTime();
	if (_commandResetTimer <= 0)
	{
		if (_commandHistory.size() > 0)
			_commandHistory.pop_back();
		_commandResetTimer = COMMAND_RESET_TIME;
	}

	//커맨드 확인
	for (unsigned int i = 0; i < _commandList.size(); ++i)
	{
		unsigned int size = _commandList[i].first.size();
		if (_commandHistory.size() < size) continue;

		for (unsigned int j = 0; j < size; ++j)
		{
			if (_commandHistory[j] != _commandList[i].first[j])
			{
				break;
			}
			if (j >= size - 1)
			{
				this->sendMessage(_commandList[i].second);
				_commandHistory.clear();
				_commandResetTimer = COMMAND_RESET_TIME;
				i = 1000;
				break;
			}
		}
	}
}

void character::gravity()
{
	_gravitySpeed += 1.5f;
	if (_gravitySpeed >= 19.8f) 19.8f;

	RECT rc = this->getCollisionRect();

	if (rc.bottom < GROUND_LINE)
	{
		_pos.y += _gravitySpeed;
		_isJump = true;
	}
	else
	{
		_pos.y = GROUND_LINE - (rc.bottom - _pos.y);
		_gravitySpeed = 0;
		_isJump = false;
	}
	
}

void character::attacked(int damage, vector2D hitedPos)
{
	//막기 여부 처리
	vector2D distance = hitedPos - _pos;
	int direction = DIRECTION::LEFT;;
	if (distance.x > 0)
	{
		direction = DIRECTION::LEFT;
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			_nowHp -= (float)damage*0.1f;
			this->sendMessage("block", 0, direction);
			return;
		}		
	}
	else
	{
		direction = DIRECTION::RIGHT;
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			_nowHp -= (float)damage*0.1f;
			this->sendMessage("block", 0, direction);
			return;
		}
	}

	_nowHp -= damage;
	if (_nowHp >= _maxHp) _nowHp = _maxHp;
	
	//죽음
	if (_nowHp <= 0)
	{
		this->sendMessage("die", 0, direction);
	}
	else
	{
		this->sendMessage("hited", 0, direction);
	}
}

void character::move(float moveSpeed, DIRECTION::Enum dir)
{
	_pos.x += moveSpeed * dir;

	RECT rc = this->getCollisionRect();
	//적과 충돌 했을 경우
	if (_enemy)
	{
		if (_enemy->isActiveObject())
		{
			RECT temp;
			if (IntersectRect(&temp, &rc, &_enemy->getCollisionRect()))
			{
				vector2D dirEenemyToMe = _pos - _enemy->_pos;
				//적이 내 왼쪽에 있는지? 오른쪽에 있는지?
				DIRECTION::Enum dir = (dirEenemyToMe.x > 0) ? DIRECTION::LEFT : DIRECTION::RIGHT;

				//적을 밀어낸다.
				_enemy->_pos.x += dir*(moveSpeed*0.5f);
				//나도 뒤로 밀림
				_pos.x -= dir*moveSpeed;
			}
		}
	}
}

DIRECTION::Enum character::getDirectionEnemy()
{
	if (_enemy)
	{
		if (_enemy->isActiveObject())
		{
			vector2D dirEenemyToMe = _pos - _enemy->_pos;
			//적이 내 왼쪽에 있는지? 오른쪽에 있는지?
			DIRECTION::Enum dir = (dirEenemyToMe.x > 0) ? DIRECTION::LEFT : DIRECTION::RIGHT;
			return dir;
		}
	}

	//적이 없을 경우 대충 그냥 RIGHT 반환;;
	return DIRECTION::RIGHT;
}