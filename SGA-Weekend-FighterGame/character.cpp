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

	this->_animation->frameUpdate();
}

void character::render()
{
	gameObject::render();

	//����� ����� ��� ��Ʈ�ڽ� ��Ʈ�� �׷��ش�.
	if (_isDebugMode)
	{

		//��Ʈ�ڽ� ���� ǥ��
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

		//�̹��� ��ü ũ�� ǥ��
		HPEN yelloBrush = CreatePen(PS_SOLID, 1, RGB(255, 255, 0));

		oldPen = (HPEN)SelectObject(memDC, yelloBrush);
		oldBrush = (HBRUSH)SelectObject(memDC, GetStockObject(NULL_BRUSH));

		RECT imageRC = getRect();
		Rectangle(memDC, imageRC.left, imageRC.top, imageRC.right, imageRC.bottom);

		SelectObject(memDC, oldBrush);
		SelectObject(memDC, oldPen);

		DeleteObject(yelloBrush);

		//ĳ������ �߽��� �׸���
		oldBrush = (HBRUSH)SelectObject(memDC, GetStockObject(COLOR_BACKGROUND));
		Ellipse(memDC, _pos.x - 3, _pos.y - 3, _pos.x + 3, _pos.y + 3);
		SelectObject(memDC, oldBrush);

		//LEFT_TOP �׸���
		vector2D size = this->getSize();
		vector2D leftTop;
		leftTop.x = _pos.x - size.x * 0.5f;
		leftTop.y = _pos.y - size.y * 0.5f;
		oldBrush = (HBRUSH)SelectObject(memDC, GetStockObject(COLOR_BACKGROUND));
		Ellipse(memDC, leftTop.x - 3, leftTop.y - 3, leftTop.x + 3, leftTop.y + 3);
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
	}
	else
	{
		_pos.y = GROUND_LINE - (rc.bottom - _pos.y);
		_gravitySpeed = 0;
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