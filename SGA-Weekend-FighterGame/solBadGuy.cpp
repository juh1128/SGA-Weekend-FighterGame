#include "stdafx.h"
#include "playGround.h"
#include "solbadGuy.h"
#include "attackHitbox.h"

//using namespace tagSolBadGuy;


HRESULT solBadGuy::init(vector2D pos)
{

	setupResource();

	
	//�׽�Ʈ �ִϸ��̼��� setupYuhoon���� �����. (���� ���� �� ���� 1���� �������� ��)
	character::init("�ֹ��", pos, "�ֹ��_�̵�_������");
	this->changeState(solBadGuyState::RIGHT_MOVE);

	this->setScale(4.0f, 4.0f);

	//�ݹ� �Լ� ���
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((solBadGuyState::Enum)msg.data);
	});

	//Ŀ�ǵ� ���
	int command[4] = { key::LEFT, key::DOWN, key::RIGHT, key::ATTACK };
	this->addCommand(command, 4, "skill1");
	int command2[4] = { key::LEFT, key::DOWN, key::RIGHT, key::KICK };
	this->addCommand(command2, 4, "skill2");
	int command3[5] = { key::LEFT, key::DOWN, key::RIGHT, key::DOWN, key::ATTACK };
	this->addCommand(command3, 5, "skill3");

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

	//ĳ���� �ʱ� �ɷ�ġ ����
	this->setStatus(100, 10);

	//ĳ���� �ǰ� �� �ݹ� ���
	this->addCallback("hited", [this](tagMessage msg)
	{
		this->hited();
	});
	this->addCallback("block", [this](tagMessage msg)
	{
		this->block();
	});
	this->addCallback("die", [this](tagMessage msg)
	{
		this->die();
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

	stateUpdate(_state);
}

void solBadGuy::render()
{
	character::render();
}
void solBadGuy::changeState(solBadGuyState::Enum state)
{

	switch (state)
	{
		///�⺻ ����
	case solBadGuyState::RIGHT_STOP:
	{			this->setAnimation("�ֹ��_�̵�_������");		}
	break;
	//�̵�
	case solBadGuyState::RIGHT_MOVE:
	{			this->setAnimation("�ֹ��_�̵�_������");		}
	break;
	//�ڷ� �̵�
	case solBadGuyState::RIGHT_BACKMOVE:
	{
		this->setAnimation("�ֹ��_�̵�_����");
	}
	break;
	//����
	case solBadGuyState::RIGHT_JUMP:
	{
		this->setAnimation("�ֹ��_����_������");
		jump(32);
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, solBadGuyState::RIGHT_STOP));
	}
	break;
	//�޸���
	case solBadGuyState::RIGHT_RUN:
	{			this->setAnimation("�ֹ��_�޸���_������");		}
	break;

	//��������
	case solBadGuyState::RIGHT_MOVEJUMP:
	{			this->setAnimation("�ֹ��_�����̵�_������");		}
	break;

	//�Ϲݰ���
	case solBadGuyState::RIGHT_WEAKHAND:
	{
		this->setAnimation("�ֹ��_����_������");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, solBadGuyState::RIGHT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 250, _pos.y), vector2D(100, _pos.y), _enemy, 1.0f);
		WORLD->addObject(hitbox);
	}
	break;
	case solBadGuyState::RIGHT_WEAKFOOT:
	{
		this->setAnimation("�ֹ��_������_������");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, solBadGuyState::RIGHT_STOP));
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 150, _pos.y), vector2D(150, 100), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;
	//case solBadGuyState::RIGHT_SKILL1:
	//{
	//	this->setAnimation("����_��ų1_������");
	//	this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, solBadGuyState::RIGHT_STOP));
	//	attackHitbox* hitbox = new attackHitbox;
	//	hitbox->init(30, vector2D(_pos.x + 350, _pos.y), vector2D(450, _pos.y), _enemy, 1.0f);
	//	WORLD->addObject(hitbox);
	//}
	//break;
	//case solBadGuyState::RIGHT_SKILL2:
	//{
	//	this->setAnimation("����_��ų2_������");
	//	this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, solBadGuyState::RIGHT_SKILL2_1));
	//}
	//break;
	//case solBadGuyState::RIGHT_SKILL2_1:
	//{
	//	_pos.x += 500;
	//	_pos.y -= 200;
	//	this->setAnimation("����_��ų2_������2");
	//	this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, solBadGuyState::RIGHT_STOP));
	//	attackHitbox* hitbox = new attackHitbox;
	//	hitbox->init(30, vector2D(_pos.x, _pos.y + 350), vector2D(200, 150), _enemy, 0.5f);
	//	WORLD->addObject(hitbox);
	//}
	//break;
	//case solBadGuyState::RIGHT_SPECIALSKILL:
	//{
	//	this->setAnimation("����_�ʻ��_������");
	//	this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, solBadGuyState::RIGHT_STOP));
	//	attackHitbox* hitbox = new attackHitbox;
	//	hitbox->init(30, vector2D(_pos.x, _pos.y + 100), vector2D(100, 200), _enemy, 0.5f);
	//	WORLD->addObject(hitbox);
	//}
	//break;
	//case solBadGuyState::RIGHT_BLOCK:
	//{
	//	this->setAnimation("����_����_������");
	//}
	//break;
	//case solBadGuyState::RIGHT_HITED:
	//{
	//	this->setAnimation("����_�±�_������");
	//}
	//break;
	//case solBadGuyState::RIGHT_DIE:
	//{
	//	this->setAnimation("����_����_������");
	//}
	//break;
	//}
	break;
	}
	_state = state;
}

void solBadGuy::stateUpdate(solBadGuyState::Enum state)
{

	switch (state)
	{
	case solBadGuyState::RIGHT_STOP:
	{

		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			this->changeState(solBadGuyState::RIGHT_MOVE);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			this->changeState(solBadGuyState::RIGHT_BACKMOVE);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(solBadGuyState::RIGHT_SIT);

		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			this->changeState(solBadGuyState::RIGHT_JUMP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			this->changeState(solBadGuyState::RIGHT_WEAKHAND);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			this->changeState(solBadGuyState::RIGHT_WEAKFOOT);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			this->changeState(solBadGuyState::RIGHT_STRONGHAND);
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			this->changeState(solBadGuyState::RIGHT_STRONGFOOT);
		}



	}
	break;
	case solBadGuyState::RIGHT_SIT:
	{
		//if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]) )
		//{
		//	this->changeState(RIGHT_STOP);
		//}
		//

		if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(solBadGuyState::RIGHT_STOP);
		}


		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			this->changeState(solBadGuyState::RIGHT_SITWEAKHAND);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			this->changeState(solBadGuyState::RIGHT_SITWEAKFOOT);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			this->changeState(solBadGuyState::RIGHT_SITSTRONGHAND);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			this->changeState(solBadGuyState::RIGHT_SITSTRONGFOOT);
		}

	}
	case solBadGuyState::RIGHT_MOVE:
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]) || KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
		{
			this->changeState(solBadGuyState::RIGHT_STOP);
		}

		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			_pos.x += 10;
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			this->changeState(solBadGuyState::LEFT_MOVE);
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			this->changeState(solBadGuyState::RIGHT_JUMP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			this->changeState(solBadGuyState::RIGHT_WEAKHAND);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			this->changeState(solBadGuyState::RIGHT_WEAKFOOT);

		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			this->changeState(solBadGuyState::RIGHT_STRONGHAND);
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			this->changeState(solBadGuyState::RIGHT_STRONGFOOT);
		}
	}
	break;
	case solBadGuyState::RIGHT_BACKMOVE:
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]) || KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
		{
			changeState(solBadGuyState::RIGHT_STOP);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			_pos.x -= 10;
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			this->changeState(solBadGuyState::RIGHT_MOVE);
		}
	}
	case solBadGuyState::RIGHT_RUN:
	{

	}
	break;
	case solBadGuyState::RIGHT_JUMP:
	{

	}
	break;
	case solBadGuyState::RIGHT_MOVEJUMP:
	{

	}
	break;
	}


}

void solBadGuy::skill1()
{
	this->changeState(solBadGuyState::RIGHT_SKILL1);
}
void solBadGuy::skill2()
{
	this->changeState(solBadGuyState::RIGHT_SKILL2);
}
void solBadGuy::skill3()
{
	this->changeState(solBadGuyState::RIGHT_SPECIALSKILL);
}

void solBadGuy::hited()
{
	//->changeState(RIGHT_HTIED);
}
void solBadGuy::block()
{
	//this->changeState(RIGHT_BLOCK);
}
void solBadGuy::die()
{
	//this->changeState(RIGHT_DIE);
}

void solBadGuy::setupResource()
{
	IMAGEMANAGER->addFrameImage("�ֹ��_�̵�", "resource/taesung/solBadGuy/move.bmp", 621, 172, 9, 2, true);

	IMAGEMANAGER->addFrameImage("�ֹ��_�޸���", "resource/taesung/solBadGuy/dash.bmp", 624, 126, 8, 2, true);

	IMAGEMANAGER->addFrameImage("�ֹ��_����", "resource/taesung/solBadGuy/hand_attack.bmp", 435, 156, 5, 2, true);

	IMAGEMANAGER->addFrameImage("�ֹ��_������", "resource/taesung/solBadGuy/kick_attack.bmp", 377, 164, 5, 2, true);

	IMAGEMANAGER->addFrameImage("�ֹ��_����", "resource/taesung/solBadGuy/jump.bmp", 207, 83, 3, 2, true);

	IMAGEMANAGER->addFrameImage("�ֹ��_��������", "resource/taesung/solBadGuy/jump_attack.bmp", 449, 136, 5, 2, true);

	//�ִϸ��̼� �ε�
	KEYANIMANAGER->addCoordinateFrameAnimation("�ֹ��_�̵�_������", "�ֹ��_�̵�", 0, 9, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�ֹ��_�̵�_������", RectMake(20, 10, 25, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("�ֹ��_�̵�_����", "�ֹ��_�̵�", 10, 18, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�ֹ��_�̵�_����", RectMakeCenter(20, 10, 25, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�ֹ��_�޸���_������", "�ֹ��_�޸���", 0, 7, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�ֹ��_�޸���_������", RectMake(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("�ֹ��_�޸���_����", "�ֹ��_�޸���", 8, 15, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�ֹ��_�޸���_����", RectMake(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�ֹ��_������_������", "�ֹ��_������", 0, 4, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�ֹ��_������_������", RectMake(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("�ֹ��_������_����", "�ֹ��_������", 5, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�ֹ��_������_����", RectMake(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�ֹ��_����_������", "�ֹ��_����", 3, 5, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�ֹ��_����_������", RectMake(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("�ֹ��_����_����", "�ֹ��_����", 0, 2, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�ֹ��_����_����", RectMake(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�ֹ��_��������_������", "�ֹ��_��������", 0, 4, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�ֹ��_��������_������", RectMake(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("�ֹ��_��������_����", "�ֹ��_��������", 5, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�ֹ��_��������_����", RectMake(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�ֹ��_����_������", "�ֹ��_����", 0, 4, 12, false, false);
	KEYANIMANAGER->setCollisionRect("�ֹ��_����_������", RectMake(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("�ֹ��_����_����", "�ֹ��_����", 5, 9, 12, false, false);
	KEYANIMANAGER->setCollisionRect("�ֹ��_����_����", RectMake(20, 10, 30, 67));
}
