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

	//�ǰ� �ݹ� �߰�
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

	//Ŀ�ǵ� ������Ʈ
	updaetCommand();
	//�߷� ó��
	if (_isGravity)
		gravity();

	//ĳ������ x��ǥ ����
	RECT cameraRC = CAMERAMANAGER->getRenderRect();
	_pos.fixedPosX(cameraRC.left, cameraRC.right);

	this->_animation->frameUpdate();
}

void character::render()
{
	gameObject::render();

	//����� ����� ��� ��Ʈ�ڽ� ��Ʈ�� �׷��ش�.
	if (_isDebugMode)
	{
		//ī�޶� ������ ����
		RECT cameraRC = CAMERAMANAGER->getRenderRect();
		//�����ǥ ���ϱ�
		POINT renderPos = { _pos.x - cameraRC.left, _pos.y - cameraRC.top };

		//�����ǥ�� �������� ���� ������ ��Ʈ
		vector2D size = getSize();
		RECT renderRC = RectMakeCenter(renderPos.x, renderPos.y, size.x, size.y);

		//�浹 ���� ��Ʈ
		RECT collisionRC = this->getCollisionRect();
		MoveRect(&collisionRC, -cameraRC.left, -cameraRC.top);

		//��Ʈ�ڽ� ���� ǥ��
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

		//�̹��� ��ü ũ�� ǥ��
		HPEN yelloBrush = CreatePen(PS_SOLID, 1, RGB(255, 255, 0));

		oldPen = (HPEN)SelectObject(memDC, yelloBrush);
		oldBrush = (HBRUSH)SelectObject(memDC, GetStockObject(NULL_BRUSH));

		Rectangle(memDC, renderRC.left, renderRC.top, renderRC.right, renderRC.bottom);

		SelectObject(memDC, oldBrush);
		SelectObject(memDC, oldPen);

		DeleteObject(yelloBrush);

		//ĳ������ �߽��� �׸���
		oldBrush = (HBRUSH)SelectObject(memDC, GetStockObject(COLOR_BACKGROUND));
		Ellipse(memDC, renderPos.x - 3, renderPos.y - 3, renderPos.x + 3, renderPos.y + 3);
		SelectObject(memDC, oldBrush);

	}
}

RECT character::getCollisionRect()
{
	//LEFT_TOP ��ǥ�� ���Ѵ�.
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
	//Ŀ�ǵ� �����丮 üũ
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

	//������ Ŀ�ǵ� �ϳ��� ����
	_commandResetTimer -= TIMEMANAGER->getElapsedTime();
	if (_commandResetTimer <= 0)
	{
		if (_commandHistory.size() > 0)
			_commandHistory.pop_back();
		_commandResetTimer = COMMAND_RESET_TIME;
	}

	//Ŀ�ǵ� Ȯ��
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
	//���� ���� ó��
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
	
	//����
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
	//���� �浹 ���� ���
	if (_enemy)
	{
		if (_enemy->isActiveObject())
		{
			RECT temp;
			if (IntersectRect(&temp, &rc, &_enemy->getCollisionRect()))
			{
				vector2D dirEenemyToMe = _pos - _enemy->_pos;
				//���� �� ���ʿ� �ִ���? �����ʿ� �ִ���?
				DIRECTION::Enum dir = (dirEenemyToMe.x > 0) ? DIRECTION::LEFT : DIRECTION::RIGHT;

				//���� �о��.
				_enemy->_pos.x += dir*(moveSpeed*0.5f);
				//���� �ڷ� �и�
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
			//���� �� ���ʿ� �ִ���? �����ʿ� �ִ���?
			DIRECTION::Enum dir = (dirEenemyToMe.x > 0) ? DIRECTION::LEFT : DIRECTION::RIGHT;
			return dir;
		}
	}

	//���� ���� ��� ���� �׳� RIGHT ��ȯ;;
	return DIRECTION::RIGHT;
}