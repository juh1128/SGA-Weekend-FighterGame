#include "stdafx.h"
#include "testCharacter.h"
#include "attackHitbox.h"


HRESULT testCharacter::init(vector2D pos)
{
	//�׽�Ʈ �ִϸ��̼��� setupYuhoon���� �����. (���� ���� �� ���� 1���� �������� ��)
	character::init("�׽�Ʈ ĳ����", pos, "�׽�Ʈ_����_������");
	this->changeState(testCharacterState::RIGHT_ATTACK);

	this->setScale(4.0f, 4.0f);

	//�ݹ� �Լ� ���
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((testCharacterState::Enum)msg.data);
	});


	//Ŀ�ǵ� ���
	int command[4] = { key::LEFT, key::JUMP, key::RIGHT, key::ATTACK };
	this->addCommand(command, 4, "skill1");
	int command2[3] = { key::RIGHT, key::RIGHT, key::ATTACK };
	this->addCommand(command2, 3, "skill2");
	int command3[4] = { key::LEFT, key::DOWN, key::RIGHT, key::ATTACK };
	this->addCommand(command3, 4, "skill3");

	//Ŀ�ǵ� �޽����� ���� �ݹ��Լ� ���
	this->addCallback("skill1", [this](tagMessage msg)
	{
		this->skill1();
	});
	this->addCallback("skill2", [this](tagMessage msg)
	{
		this->skill2();
	});
	this->addCallback("skill3", [this](tagMessage msg)
	{
		this->skill3();
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
			hitbox->init(30, vector2D(_pos.x + 70, _pos.y), vector2D(100, 220), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;

		case testCharacterState::LEFT_ATTACK:
		{
			this->setAnimation("�׽�Ʈ_����_����");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, testCharacterState::LEFT_MOVE));

			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 70, _pos.y), vector2D(100, 220), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
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
				_pos.x += 10;
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
				_pos.x -= 10;
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


void testCharacter::skill1()
{
	cout << "��ų1 �ߵ�!" << endl;
}
void testCharacter::skill2()
{
	cout << "��ų2 �ߵ�!" << endl;
}
void testCharacter::skill3()
{
	cout << "��ų3 �ߵ�!" << endl;
}