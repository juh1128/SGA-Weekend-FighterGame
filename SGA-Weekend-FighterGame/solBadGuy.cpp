#include "stdafx.h"
#include "solBadGuy.h"
#include "attackHitbox.h"


HRESULT solBadGuy::init(vector2D pos)
{
	//���ҽ� �ε�
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_�̵�", "resource/yuhoon/testCharacter/move.bmp", 625, 168,
		10, 2, true);
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_�޸���", "resource/yuhoon/testCharacter/run.bmp", 624, 126,
		8, 2, true);
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_������", "resource/yuhoon/testCharacter/kick.bmp", 377, 164,
		5, 2, true);
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_����", "resource/yuhoon/testCharacter/jump.bmp", 207, 83,
		3, 2, true);
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_��������", "resource/yuhoon/testCharacter/jump_attack.bmp", 406, 162,
		5, 2, true);
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_����", "resource/yuhoon/testCharacter/attack.bmp", 399, 178,
		5, 2, true);

	//�ִϸ��̼� �ε�
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�̵�_������", "�׽�Ʈ_�̵�", 0, 9, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�̵�_������", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�̵�_����", "�׽�Ʈ_�̵�", 10, 19, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�̵�_����", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�޸���_������", "�׽�Ʈ_�޸���", 0, 7, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�޸���_������", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�޸���_����", "�׽�Ʈ_�޸���", 8, 15, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�޸���_����", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_������_������", "�׽�Ʈ_������", 0, 4, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_������_������", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_������_����", "�׽�Ʈ_������", 5, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_������_����", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_����_������", "�׽�Ʈ_����", 3, 5, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_����_������", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_����_����", "�׽�Ʈ_����", 0, 2, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_����_����", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_��������_������", "�׽�Ʈ_��������", 0, 4, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_��������_������", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_��������_����", "�׽�Ʈ_��������", 5, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_��������_����", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_����_������", "�׽�Ʈ_����", 0, 4, 12, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_����_������", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_����_����", "�׽�Ʈ_����", 5, 9, 12, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_����_����", RectMake(19, 9, 30, 65));


	//�׽�Ʈ �ִϸ��̼��� setupYuhoon���� �����. (���� ���� �� ���� 1���� �������� ��)
	character::init("�׽�Ʈ ĳ����", pos, "�׽�Ʈ_�̵�_������");
	this->changeState(solBadGuyState::RIGHT_MOVE);

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
