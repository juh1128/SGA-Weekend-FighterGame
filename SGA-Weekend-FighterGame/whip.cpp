#include "stdafx.h"
#include "whip.h"
#include "attackHitbox.h"

using namespace tagWhip;

HRESULT whip::init(vector2D pos)
{
	setupResource();

	//�׽�Ʈ �ִϸ��̼��� setupYuhoon���� �����. (���� ���� �� ���� 1���� �������� ��)
	character::init("����", pos, "whip_stop_right");
	//this->changeState(tagWhip::RIGHT_STOP);

	this->setScale(4.0f, 4.0f);

	_state = tagWhip::RIGHT_STOP;

	//�ݹ� �Լ� ���
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((tagWhip::Enum)msg.data);
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
void whip::release()
{
	character::release();
}

void whip::update()
{
	character::update();

	//���� �� ������Ʈ ó��
	stateUpdate(_state);
}
void whip::render()
{
	character::render();
}
void whip::changeState(tagWhip::Enum state)
{
	//���� ���� �� ó������ �͵��� ������ ���⼭

	
	///�Ϲ� ������
	//	RIGHT_STOP, LEFT_STOP,
	//	RIGHT_MOVE, LEFT_MOVE,
	//	//RIGHT_BACK_MOVE, LEFT_BACK_MOVE,
	//	RIGHT_RUN, LEFT_RUN,
	//	RIGHT_SIT, LEFT_SIT,
	//	RIGHT_JUMP, LEFT_JUMP,
	//	RIGHT_MOVEJUMP, LEFT_MOVEJUMP,
	///�Ϲ� ����
	//	//RIGHT_WEAKHAND, LEFT_WEAKHAND,
	//	//RIGHT_WEAKFOOT, LEFT_WEAKFOOT,
	//	//RIGHT_STRONGHAND, LEFT_STRONGHAND,
	//	//RIGHT_STRONGFOOT, LEFT_STRONGFOOT,
	//	//RIGHT_SITWEAKHAND, LEFT_SITWEAKHAND,
	//	//RIGHT_SITWEAKFOOT, LEFT_SITWEAKFOOT,
	//	//RIGHT_SITSTRONGHAND, LEFT_SITSTRONGHAND,
	//	//RIGHT_SITSTRONGFOOT, LEFT_SITSTRONGFOOT,
	//	//RIGHT_JUMPHAND, LEFT_JUMPFOOT,
	///��ų, �ʻ��
	//	RIGHT_SKILL1, LEFT_SKILL1,
	//	RIGHT_SKILL2, LEFT_SKILL2,
	//	RIGHT_SPECIALSKILL, LEFT_SPECIALSKILL,
	
	switch (state)
	{
		///�⺻ ����
		case RIGHT_STOP:
		{			this->setAnimation("whip_stop_right");		}
		break;
		//�̵�
		case RIGHT_MOVE:
		{			this->setAnimation("whip_move_right");		}
		break;
		//�ڷ� �̵�
		case RIGHT_BACKMOVE:
		{
			this->setAnimation("whip_backMove_right");
		}
		break;
		//�ɱ�
		case RIGHT_SIT:
		{			this->setAnimation("whip_sit_right");		}
		break;
		//����
		case RIGHT_JUMP:
		{		
			this->setAnimation("whip_jump_right");
			jump(32);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));		
		}
		break;
		//�޸���
		case RIGHT_RUN:
		{			this->setAnimation("whip_run_right");		}
		break;

		//��������
		case RIGHT_MOVEJUMP:
		{			this->setAnimation("whip_moveJump_right");		}
		break;

		//�Ϲݰ���
		case RIGHT_WEAKHAND:
		{
			this->setAnimation("whip_attack_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
			
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x+350, _pos.y), vector2D(450, _pos.y), _enemy, 1.0f);
			WORLD->addObject(hitbox);
		}
		break;
		case RIGHT_WEAKFOOT:
		{
			this->setAnimation("whip_kick_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x+150, _pos.y), vector2D(150, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case RIGHT_STRONGHAND:
		{
			this->setAnimation("whip_strongAttack_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 350, _pos.y), vector2D(450, _pos.y), _enemy, 1.0f);
			WORLD->addObject(hitbox);
		}
		break;
	
		case RIGHT_STRONGFOOT:
		{
			this->setAnimation("whip_strongKick_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x+200, _pos.y-100), vector2D(100, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case RIGHT_SITWEAKHAND:
		{
			this->setAnimation("whip_sitAttack_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));

			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x, _pos.y), vector2D(100, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);

		}
		break;
		case RIGHT_SITWEAKFOOT:
		{
			this->setAnimation("whip_sitKick_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x, _pos.y), vector2D(100, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case RIGHT_SITSTRONGHAND:
		{
			this->setAnimation("whip_sitStrongAttack_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x, _pos.y), vector2D(100, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case RIGHT_SITSTRONGFOOT:
		{
			this->setAnimation("whip_sitStrongKick_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x, _pos.y), vector2D(100, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case RIGHT_SKILL1:
		{
			this->setAnimation("����_��ų1_������");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 350, _pos.y), vector2D(450, _pos.y), _enemy, 1.0f);
			WORLD->addObject(hitbox);
		}
		break;
		case RIGHT_SKILL2:
		{
			this->setAnimation("����_��ų2_������");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SKILL2_1));
		}
		break;
		case RIGHT_SKILL2_1:
		{
			_pos.x += 500;
			_pos.y -= 200;
			this->setAnimation("����_��ų2_������2");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x, _pos.y + 350), vector2D(200, 150), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case RIGHT_SPECIALSKILL:
		{
			this->setAnimation("����_�ʻ��_������");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x, _pos.y+100), vector2D(100, 200), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case RIGHT_BLOCK:
		{
			this->setAnimation("����_����_������");
		}
		break;
		case RIGHT_HITED:
		{
			this->setAnimation("����_�±�_������");
		}
		break;
		case RIGHT_DIE:
		{
			this->setAnimation("����_����_������");
		}
		break;
	}

	_state = state;
}

void whip::stateUpdate(tagWhip::Enum state)
{

	switch (state)
	{
		case RIGHT_STOP:
		{
			
			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{				this->changeState(RIGHT_MOVE);			}
			if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
			{				this->changeState(RIGHT_BACKMOVE);			}
			if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				changeState(RIGHT_SIT);

			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
			{
				this->changeState(RIGHT_JUMP);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
			{
				this->changeState(RIGHT_WEAKHAND);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
			{
				this->changeState(RIGHT_WEAKFOOT);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
			{
				this->changeState(RIGHT_STRONGHAND);
			}

			if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
			{
				this->changeState(RIGHT_STRONGFOOT);
			}

			

		}
		break;
		case RIGHT_SIT:
		{
			//if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]) )
			//{
			//	this->changeState(RIGHT_STOP);
			//}
			//

			if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				changeState(RIGHT_STOP);
			}


			if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
			{
				this->changeState(RIGHT_SITWEAKHAND);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
			{
				this->changeState(RIGHT_SITWEAKFOOT);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
			{
				this->changeState(RIGHT_SITSTRONGHAND);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
			{
				this->changeState(RIGHT_SITSTRONGFOOT);
			}

		}
		case RIGHT_MOVE:	
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]) || KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
			{
				this->changeState(RIGHT_STOP);
			}

			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{
					_pos.x += 10;
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
			{
				this->changeState(LEFT_MOVE);
			}

			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
			{
				this->changeState(RIGHT_JUMP);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
			{
				this->changeState(RIGHT_WEAKHAND);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
			{
				this->changeState(RIGHT_WEAKFOOT);

			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
			{
				this->changeState(RIGHT_STRONGHAND);
			}

			if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
			{
				this->changeState(RIGHT_STRONGFOOT);
			}
		}
		break;
		case RIGHT_BACKMOVE:
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]) || KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
			{
				changeState(RIGHT_STOP);
			}
			if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
			{
				_pos.x -= 10;
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
			{
				this->changeState(RIGHT_MOVE);
			}
		}
		case RIGHT_RUN:
		{
			
		}
		break;
		case RIGHT_JUMP:
		{
			
		}
		break;
		case RIGHT_MOVEJUMP:
		{
			
		}
		break;
	}


}

void whip::skill1()
{
	this->changeState(RIGHT_SKILL1);
}
void whip::skill2()
{
	this->changeState(RIGHT_SKILL2);
}
void whip::skill3()
{
	this->changeState(RIGHT_SPECIALSKILL);
}

void whip::hited()
{
	//->changeState(RIGHT_HTIED);
}
void whip::block()
{
	//this->changeState(RIGHT_BLOCK);
}
void whip::die()
{
	//this->changeState(RIGHT_DIE);
}






void whip::setupResource()
{
		IMAGEMANAGER->addFrameImage("�׽�Ʈ_�̵�", "resource/yuhoon/testCharacter/move.bmp", 625, 168,
		10, 2, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�̵�_������", "�׽�Ʈ_�̵�", 0, 9, 15, false, true);
		KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�̵�_������", RectMake(19, 9, 30, 65));


		//���ҽ� �ε�
		//�Ϲݿ�����
		IMAGEMANAGER->addFrameImage("����_����", "resource/hyeongjoon/whip/whip_motion/whip_stop.bmp", 5427/4, 836 / 4,
			19, 2, true);
		IMAGEMANAGER->addFrameImage("����_�̵�", "resource/hyeongjoon/whip/whip_motion/whip_move.bmp", 2753 / 4, 862 / 4,
			8, 2, true);
		IMAGEMANAGER->addFrameImage("����_�޸���", "resource/hyeongjoon/whip/whip_motion/whip_run.bmp", 2989/4, 794/4,
			8, 2, true);
		IMAGEMANAGER->addFrameImage("����_�ɱ�", "resource/hyeongjoon/whip/whip_motion/whip_sit.bmp", 2100/4, 215,
			7, 2, true);
		IMAGEMANAGER->addFrameImage("����_����", "resource/hyeongjoon/whip/whip_motion/whip_jump.bmp", 680,222,
			8, 2, true);
		IMAGEMANAGER->addFrameImage("����_��������", "resource/hyeongjoon/whip/whip_motion/whip_moveJump.bmp", 3102/4, 1188/4,
			9, 2, true);
		//�Ϲݰ��� 
		IMAGEMANAGER->addFrameImage("����_���", "resource/hyeongjoon/whip/whip_attack/whip_weakHand.bmp", 11210/4, 1680/4,
			9, 4, true);
		IMAGEMANAGER->addFrameImage("����_���", "resource/hyeongjoon/whip/whip_attack/whip_weakFoot.bmp",750, 202,
			5, 2, true);
		IMAGEMANAGER->addFrameImage("����_����", "resource/hyeongjoon/whip/whip_attack/whip_strongHand.bmp", 16500/4, 2068/4,
			11, 4, true);
		IMAGEMANAGER->addFrameImage("����_����", "resource/hyeongjoon/whip/whip_attack/whip_stongFoot.bmp", 4950/4, 912/4,
			11, 2, true);
		IMAGEMANAGER->addFrameImage("����_�ɱ�_���", "resource/hyeongjoon/whip/whip_attack/whip_weakHand.bmp", 10660/4, 874/4,
			13, 2, true);
		IMAGEMANAGER->addFrameImage("����_�ɱ�_���", "resource/hyeongjoon/whip/whip_attack/whip_sitWeakFoot.bmp", 4900/4, 520/4,
			7, 2, true);
		IMAGEMANAGER->addFrameImage("����_�ɱ�_����", "resource/hyeongjoon/whip/whip_attack/whip_sitStrongHand.bmp", 11000/4, 1200/4,
			19, 2, true);
		IMAGEMANAGER->addFrameImage("����_�ɱ�_����", "resource/hyeongjoon/whip/whip_attack/whip_sitStrongFoot.bmp", 4800/4, 520/4,
			6, 2, true);
		IMAGEMANAGER->addFrameImage("����_����_��", "resource/hyeongjoon/whip/whip_attack/whip_jumpHand.bmp", 2280/4, 819/4,
			8, 2, true);
		IMAGEMANAGER->addFrameImage("����_����_��", "resource/hyeongjoon/whip/whip_attack/whip_jumpFoot.bmp", 2850/4, 746/4,
			5, 2, true);
		
		//��ų1,2 + �ʻ��
		IMAGEMANAGER->addFrameImage("����_��ų1", "resource/hyeongjoon/whip/whip_skill/whip_skill1.bmp", 12430/4, 4260/4,
			11, 6, true);
		IMAGEMANAGER->addFrameImage("����_��ų2", "resource/hyeongjoon/whip/whip_skill/whip_skill2.bmp", 3300/4, 4836/4,
			10, 6, true);
		IMAGEMANAGER->addFrameImage("����_�ʻ��", "resource/hyeongjoon/whip/whip_skill/ship_specialSkill.bmp", 12120/4, 6128/4,
			12, 8, true);

		//����, �±�, ����
		IMAGEMANAGER->addFrameImage("����_����", "resource/hyeongjoon/whip/����.bmp", 200,100,2,1, true);
		IMAGEMANAGER->addFrameImage("����_�±�", "resource/hyeongjoon/whip/�±�.bmp", 138,100, 2, 1, true);
		IMAGEMANAGER->addFrameImage("����_����", "resource/hyeongjoon/whip/����.bmp", 256, 100, 2, 1, true);


		//����
		//KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�̵�_������", "�׽�Ʈ_�̵�", 0, 9, 15, false, true);
		//KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�̵�_������", RectMakeCenter(20, 10, 30, 67));

		//����, �±�, ����
		int rightBlock[] = { 0 };
		KEYANIMANAGER->addArrayFrameAnimation("����_����_������", "����_����", rightBlock, 1, 10, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("����_����_������", "����_����", 0, 0, 1, true, true);
		int leftBlock[] = { 1 };
		KEYANIMANAGER->addArrayFrameAnimation("����_����_����", "����_����", leftBlock, 1, 10, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("����_����_����", "����_����", 0, 0, 1, true, true);

		int rightHited[] = { 0 };
		KEYANIMANAGER->addArrayFrameAnimation("����_�±�_������", "����_�±�", rightHited, 1, 10, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("�����±�_������", "����_�±�", 0, 0, 1, true, true);
		int leftHited[] = { 1 };
		KEYANIMANAGER->addArrayFrameAnimation("����_�±�_����", "����_�±�", leftHited, 1, 10, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("����_�±�_����", "����_�±�", 0, 0, 1, true, true);

		int rightDie[] = { 0 };
		KEYANIMANAGER->addArrayFrameAnimation("����_����_������", "����_����", rightDie, 1, 10, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("�����±�_������", "����_����", 0, 0, 1, true, true);
		int leftDie[] = { 1 };
		KEYANIMANAGER->addArrayFrameAnimation("����_����_����", "����_����", leftDie, 1, 10, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("����_����_����", "����_����", 0, 0, 1, true, true);

		//�Ϲݿ�����
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_stop_right", "����_����", 0, 18, 15, true, true);
		KEYANIMANAGER->setCollisionRect("whip_stop_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_stop_left", "����_����", 37, 19, 15, true, true);
		KEYANIMANAGER->setCollisionRect("whip_stop_left", RectMakeCenter(35, 51, 35, 105));

		KEYANIMANAGER->addCoordinateFrameAnimation("whip_move_right", "����_�̵�", 0, 7, 15, false, true);
		KEYANIMANAGER->setCollisionRect("whip_move_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_move_left", "����_�̵�", 7, 0, 15, false, true);
		KEYANIMANAGER->setCollisionRect("whip_move_left", RectMakeCenter(35, 51, 35, 105));

		KEYANIMANAGER->addCoordinateFrameAnimation("whip_backMove_right", "����_�̵�", 7, 0, 15, false, true);
		KEYANIMANAGER->setCollisionRect("whip_backMove_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_backMove_left", "����_�̵�", 0, 7, 15, false, true);
		KEYANIMANAGER->setCollisionRect("whip_backMove_left", RectMakeCenter(35, 51, 35, 105));

		KEYANIMANAGER->addCoordinateFrameAnimation("whip_run_right", "����_�޸���", 0, 7, 15, false, true);
		KEYANIMANAGER->setCollisionRect("whip_run_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_run_left", "����_�޸���", 7, 0, 15, false, true);
		KEYANIMANAGER->setCollisionRect("whip_run_left", RectMakeCenter(35, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sit_right", "����_�ɱ�", 0, 6, 15, true, true);
		KEYANIMANAGER->setCollisionRect("whip_sit_right", RectMakeCenter(35, 51+15, 35, 105-30));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sit_left", "����_�ɱ�", 13, 7, 15, true, true);
		KEYANIMANAGER->setCollisionRect("whip_sit_left", RectMakeCenter(35, 51+15, 35, 105-30));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_jump_right", "����_����", 0, 7, 15, false, false);
		KEYANIMANAGER->setCollisionRect("whip_jump_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_jump_left", "����_����", 15, 8, 15, false, false);
		KEYANIMANAGER->setCollisionRect("whip_jump_left", RectMakeCenter(35, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_moveJump_right", "����_��������", 0, 8, 15, false, false);
		KEYANIMANAGER->setCollisionRect("whip_moveJump_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_moveJump_left", "����_��������", 17, 9, 15, false, false);
		KEYANIMANAGER->setCollisionRect("whip_moveJump_left", RectMakeCenter(35, 51, 35, 105));


		//�Ϲݰ���
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_attack_right", "����_���", 0, 17, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_attack_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_attack_left", "����_���", 35, 18, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_attack_left", RectMakeCenter(150, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_kick_right", "����_���", 0, 4, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_kick_right", RectMakeCenter(75, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_kick_left", "����_���", 9, 5, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_kick_left", RectMakeCenter(75, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_strongAttack_right", "����_����", 0, 21, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_strongAttack_right", RectMakeCenter(180, 50+30, 35, 50+40));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_strongAttack_left", "����_����", 43, 22, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_strongAttack_left", RectMakeCenter(180, 50+30, 35, 50+40));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_strongKick_right", "����_����", 0, 10, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_strongKick_right", RectMakeCenter(65, 51, 35, 120));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_strongKick_left", "����_����", 21, 11, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_strongKick_left", RectMakeCenter(65, 51, 35, 120));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitAttack_right", "����_�ɱ�_���", 0, 12, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitAttack_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitAttack_left", "����_�ɱ�_���", 25, 13, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitAttack_left", RectMakeCenter(150, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitKick_right", "����_�ɱ�_���", 0, 6, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitKick_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitKick_left", "����_�ɱ�_���", 13, 7, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitKick_left", RectMakeCenter(150, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitStrongAttack_right", "����_�ɱ�_����", 0, 18, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitStrongAttack_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitStrongAttack_left", "����_�ɱ�_����", 37, 19, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitStrongAttack_left", RectMakeCenter(150, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitStrongKick_right", "����_�ɱ�_����", 0, 5, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitStrongKick_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitStrongKick_left", "����_�ɱ�_����", 11, 6, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitStrongKick_left", RectMakeCenter(150, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_jumpAttack_right", "����_����_��", 0, 7, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_jumpAttack_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_jumpAttack_left", "����_����_��", 15, 8, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_jumpAttack_left", RectMakeCenter(150, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_jumpKick_right", "����_����_��", 0, 4, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_jumpKick_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_jumpKick_left", "����_����_��", 9, 5, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_jumpKick_left", RectMakeCenter(150, 51, 35, 105));
		
		////��ų 
		KEYANIMANAGER->addCoordinateFrameAnimation("����_��ų1_������", "����_��ų1", 0, 32, 20, false, false);
		KEYANIMANAGER->setCollisionRect("����_��ų1_������", RectMakeCenter(160, 120, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("����_��ų1_����", "����_��ų1", 65, 33, 5, false, false);
		KEYANIMANAGER->setCollisionRect("����_��ų1_����",  RectMakeCenter(160, 120, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("����_��ų2_������", "����_��ų2", 0, 13, 20, false, false);
		KEYANIMANAGER->setCollisionRect("����_��ų2_������", RectMakeCenter(160, 120, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("����_��ų2_������2", "����_��ų2", 14, 19, 20, false, false);
		KEYANIMANAGER->setCollisionRect("����_��ų2_������2", RectMakeCenter(160, 120, 35, 105));

		KEYANIMANAGER->addCoordinateFrameAnimation("����_��ų2_����", "����_��ų2", 39, 20, 20, false, false);
		KEYANIMANAGER->setCollisionRect("����_��ų2_����", RectMakeCenter(160, 120, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("����_�ʻ��_������", "����_�ʻ��", 0, 48, 20, false, false);
		KEYANIMANAGER->setCollisionRect("����_�ʻ��_������",   RectMakeCenter(160, 120, 35, 150));
		KEYANIMANAGER->addCoordinateFrameAnimation("����_�ʻ��_����", "����_�ʻ��", 95, 49, 5, false, false);
		KEYANIMANAGER->setCollisionRect("����_�ʻ��_����",   RectMakeCenter(160, 120, 35, 150));
	
}