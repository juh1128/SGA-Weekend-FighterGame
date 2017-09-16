#include "stdafx.h"
#include "character.h"


HRESULT character::init(string characterName, vector2D pos, string animationKeyName)
{
	gameObject::init(characterName, "", pos);
	this->setAnimation(animationKeyName);
	this->setSize(_animation->getFrameWidth(), _animation->getFrameHeight());

	_commandResetTimer = COMMAND_RESET_TIME;
	_historyCheck = true;

	_gravitySpeed = 0;

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
	gravity();

	this->_animation->frameUpdate();
}

void character::render()
{
	gameObject::render();

	//디버그 모드일 경우 히트박스 렉트를 그려준다.
	if (_isDebugMode)
	{

		//히트박스 영역 표시
		HPEN bluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		HPEN oldPen;
		HBRUSH oldBrush;
		HDC memDC = getMemDC();

		oldPen = (HPEN)SelectObject(memDC, bluePen);
		oldBrush = (HBRUSH)SelectObject(memDC, GetStockObject(NULL_BRUSH));

		RECT rc = getCollisionRect();
		Rectangle(memDC, rc.left, rc.top, rc.right, rc.bottom);

		SelectObject(memDC, oldBrush);
		SelectObject(memDC, oldPen);

		DeleteObject(bluePen);

		//이미지 전체 크기 표시
		HPEN yelloBrush = CreatePen(PS_SOLID, 1, RGB(255, 255, 0));

		oldPen = (HPEN)SelectObject(memDC, yelloBrush);
		oldBrush = (HBRUSH)SelectObject(memDC, GetStockObject(NULL_BRUSH));

		RECT imageRC = getRect();
		Rectangle(memDC, imageRC.left, imageRC.top, imageRC.right, imageRC.bottom);

		SelectObject(memDC, oldBrush);
		SelectObject(memDC, oldPen);

		DeleteObject(yelloBrush);

		//캐릭터의 중심점 그리기
		oldBrush = (HBRUSH)SelectObject(memDC, GetStockObject(COLOR_BACKGROUND));
		Ellipse(memDC, _pos.x - 3, _pos.y - 3, _pos.x + 3, _pos.y + 3);
		SelectObject(memDC, oldBrush);

		//입력한 커맨드 표시
	/*	string buf;
		for (int i = 0; i<_commandHistory.size(); ++i)
		{
			switch (_commandHistory[i])
			{
			case key::ATTACK:
				buf.append("[ATTACK] ");
				break;
			case key::RIGHT:
				buf.append("[RIGHT] ");
				break;
			case key::LEFT:
				buf.append("[LEFT] ");
				break;
			case key::JUMP:
				buf.append("[JUMP] ");
				break;
			case key::DOWN:
				buf.append("[DOWN] ");
				break;
			case key::KICK:
				buf.append("[KICK] ");
				break;
			case key::STRONG_ATTACK:
				buf.append("[STRONG_ATTACK] ");
				break;
			case key::STRONG_KICK:
				buf.append("[STRONG_KICK] ");
				break;
			}
		}
		TextOut(getMemDC(), _pos.x, _pos.y - 100, buf.c_str(), buf.length());*/
	}
}

RECT character::getCollisionRect()
{
	//LEFT_TOP 좌표를 구한다.
	vector2D leftTop;
	leftTop.x = _pos.x - this->getSize().x * 0.5f;
	leftTop.y = _pos.y - this->getSize().y * 0.5f;

	RECT collisionRC = _animation->getCollisionRect();
	collisionRC.left *= this->getScale().x;
	collisionRC.top *= this->getScale().y;
	collisionRC.right *= this->getScale().x;
	collisionRC.bottom *= this->getScale().y;

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
	_gravitySpeed += 0.25f;
	if (_gravitySpeed >= 9.8f) 9.8f;

	RECT rc = this->getCollisionRect();

	if (rc.bottom < GROUND_LINE)
	{
		_pos.y += _gravitySpeed;
	}
	else
	{
		_gravitySpeed = 0;
	}
	
}