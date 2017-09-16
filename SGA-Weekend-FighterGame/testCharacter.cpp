#include "stdafx.h"
#include "testCharacter.h"
#include "attackHitbox.h"


HRESULT testCharacter::init(vector2D pos)
{
	//�׽�Ʈ �ִϸ��̼��� setupYuhoon���� �����. (���� ���� �� ���� 1���� �������� ��)
	character::init("�׽�Ʈ ĳ����", pos, "�׽�Ʈ_����_������");
	this->changeState(testCharacterState::RIGHT_ATTACK);

	this->setScale(3.0f, 3.0f);

	//�ݹ� �Լ� ���
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((testCharacterState::Enum)msg.data);
	});


	return S_OK;
}

void testCharacter::release()	  
{
	character::release();
}

void testCharacter::update()	  
{
	character::update();

	//���� �� ������Ʈ ó��
	stateUpdate(_state);

}

void testCharacter::render()	  
{
	character::render();
}

void testCharacter::changeState(testCharacterState::Enum state)
{
	//���� ���� �� ó������ �͵��� ������ ���⼭
	switch (state)
	{
		case testCharacterState::RIGHT_ATTACK:
		{
			this->setAnimation("�׽�Ʈ_����_������");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, testCharacterState::RIGHT_MOVE));

			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 50, _pos.y+30), vector2D(30, 30), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;

		case testCharacterState::LEFT_ATTACK:
			this->setAnimation("�׽�Ʈ_����_����");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, testCharacterState::LEFT_MOVE));
		break;

		case testCharacterState::RIGHT_JUMP:
		break;

		case testCharacterState::LEFT_JUMP:
		break;

		case testCharacterState::RIGHT_MOVE:
		{
			this->setAnimation("�׽�Ʈ_�̵�_������");
		}
		break;

		case testCharacterState::LEFT_MOVE:
		{
			this->setAnimation("�׽�Ʈ_�̵�_����");
		}
		break;

		case testCharacterState::RIGHT_RUN:
		break;

		case testCharacterState::LEFT_RUN:
		break;

		case testCharacterState::RIGHT_JUMPATTACK:
		break;

		case testCharacterState::LEFT_JUMPATTACK:
		break;
	}
	_state = state;
}

void testCharacter::stateUpdate(testCharacterState::Enum state)
{
	switch (state)
	{
		case testCharacterState::RIGHT_ATTACK:
		{

		}
		break;

		case testCharacterState::LEFT_ATTACK:
		{

		}
		break;

		case testCharacterState::RIGHT_JUMP:
		{

		}
		break;

		case testCharacterState::LEFT_JUMP:
		{

		}
		break;

		case testCharacterState::RIGHT_MOVE:
		{
			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{
				_pos.x += 5;
			}
			if (KEYMANAGER->isStayKeyDown(keyList[key::ATTACK]))
			{
				changeState(testCharacterState::RIGHT_ATTACK);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
			{
				changeState(testCharacterState::LEFT_MOVE);
			}
		}
		break;

		case testCharacterState::LEFT_MOVE:
		{
			if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
			{
				_pos.x -= 5;
			}
			if (KEYMANAGER->isStayKeyDown(keyList[key::ATTACK]))
			{
				changeState(testCharacterState::LEFT_ATTACK);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
			{
				changeState(testCharacterState::RIGHT_MOVE);
			}
		}
		break;

		case testCharacterState::RIGHT_RUN:
		{

		}
		break;

		case testCharacterState::LEFT_RUN:
		{

		}
		break;

		case testCharacterState::RIGHT_JUMPATTACK:
		{

		}
		break;

		case testCharacterState::LEFT_JUMPATTACK:
		{

		}
		break;
	}
}