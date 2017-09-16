#include "stdafx.h"
#include "solBadGuy.h"
#include "attackHitbox.h"


HRESULT solBadGuy::init(vector2D pos)
{
	//�׽�Ʈ �ִϸ��̼��� setupYuhoon���� �����. (���� ���� �� ���� 1���� �������� ��)
	character::init("�׽�Ʈ ĳ����", pos, "�׽�Ʈ_����_������");
	this->changeState(solBadGuyState::RIGHT_ATTACK);

	this->setScale(3.0f, 3.0f);

	//�ݹ� �Լ� ���
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((solBadGuyState::Enum)msg.data);
	});


	return S_OK;
}

void solBadGuy::release()
{
	character::release();
}

void solBadGuy::update()
{
	character::update();

	//���� �� ������Ʈ ó��
	stateUpdate(_state);

}

void solBadGuy::render()
{
	character::render();
}

void solBadGuy::changeState(solBadGuyState::Enum state)
{
	//���� ���� �� ó������ �͵��� ������ ���⼭
	switch (state)
	{
	case solBadGuyState::RIGHT_ATTACK:
	{
		this->setAnimation("�׽�Ʈ_����_������");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, solBadGuyState::RIGHT_MOVE));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 50, _pos.y + 30), vector2D(30, 30), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;

	case solBadGuyState::LEFT_ATTACK:
		this->setAnimation("�׽�Ʈ_����_����");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, solBadGuyState::LEFT_MOVE));
		break;

	case solBadGuyState::RIGHT_JUMP:
		break;

	case solBadGuyState::LEFT_JUMP:
		break;

	case solBadGuyState::RIGHT_MOVE:
	{
		this->setAnimation("�׽�Ʈ_�̵�_������");
	}
	break;

	case solBadGuyState::LEFT_MOVE:
	{
		this->setAnimation("�׽�Ʈ_�̵�_����");
	}
	break;

	case solBadGuyState::RIGHT_RUN:
		break;

	case solBadGuyState::LEFT_RUN:
		break;

	case solBadGuyState::RIGHT_JUMPATTACK:
		break;

	case solBadGuyState::LEFT_JUMPATTACK:
		break;
	}
	_state = state;
}

void solBadGuy::stateUpdate(solBadGuyState::Enum state)
{
	switch (state)
	{
	case solBadGuyState::RIGHT_ATTACK:
	{

	}
	break;

	case solBadGuyState::LEFT_ATTACK:
	{

	}
	break;

	case solBadGuyState::RIGHT_JUMP:
	{

	}
	break;

	case solBadGuyState::LEFT_JUMP:
	{

	}
	break;

	case solBadGuyState::RIGHT_MOVE:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			_pos.x += 5;
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::ATTACK]))
		{
			changeState(solBadGuyState::RIGHT_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			changeState(solBadGuyState::LEFT_MOVE);
		}
	}
	break;

	case solBadGuyState::LEFT_MOVE:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			_pos.x -= 5;
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::ATTACK]))
		{
			changeState(solBadGuyState::LEFT_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			changeState(solBadGuyState::RIGHT_MOVE);
		}
	}
	break;

	//������ �뽬
	case solBadGuyState::RIGHT_RUN:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			_pos.x += 10;
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::ATTACK]))
		{
			changeState(solBadGuyState::RIGHT_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			changeState(solBadGuyState::LEFT_MOVE);
		}
	}
	break;

	case solBadGuyState::LEFT_RUN:
	{

	}
	break;

	case solBadGuyState::RIGHT_JUMPATTACK:
	{

	}
	break;

	case solBadGuyState::LEFT_JUMPATTACK:
	{

	}
	break;
	}
}
