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

	//this->setScale(4.0f, 4.0f);

	_state = tagWhip::RIGHT_STOP;

	//�ݹ� �Լ� ���
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((tagWhip::Enum)msg.data);
	});

	//ĳ���� �ʱ� �ɷ�ġ ����
	this->setStatus(100, 10);


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
		case RIGHT_STOP:
		{
			this->setAnimation("whip_stop_right");
		}
		break;
		case tagWhip::LEFT_STOP:
		{
			this->setAnimation("whip_stop_left");
		}
		case tagWhip::RIGHT_MOVE:
		{
			this->setAnimation("whip_move_right");
		}
		break;
		case tagWhip::LEFT_JUMP:
		{
			this->setAnimation("whip_move_left");
		}

		case tagWhip::RIGHT_RUN:
		{
			this->setAnimation("����_�޸���_������");
		}
		break;
		case tagWhip::RIGHT_JUMP:
		{
			this->setAnimation("����_����_������");
		}
		break;
		case tagWhip::RIGHT_MOVEJUMP:
		{
			this->setAnimation("����_��������_������");
		}
		break;
	}

	_state = state;
}

void whip::stateUpdate(tagWhip::Enum state)
{
	switch (state)
	{
		case tagWhip::RIGHT_STOP:
		{
			if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
			{
				this->changeState(RIGHT_MOVE);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
			{
				this->changeState(LEFT_MOVE);
			}
		}
		break;
		case tagWhip::RIGHT_MOVE:
		{
			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{
				_pos.x += 10;
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
			{
				this->changeState(LEFT_MOVE);
			}
		}
		break;
		case tagWhip::LEFT_MOVE:
		{
			if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
			{
				_pos.x -= 10;
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
			{
				this->changeState(RIGHT_MOVE);
			}
		}
		case tagWhip::RIGHT_RUN:
		{
			
		}
		break;
		case tagWhip::RIGHT_JUMP:
		{
			
		}
		break;
		case tagWhip::RIGHT_MOVEJUMP:
		{
			
		}
		break;
	}
}


void whip::setupResource()
{
		IMAGEMANAGER->addFrameImage("�׽�Ʈ_�̵�", "resource/yuhoon/testCharacter/move.bmp", 625, 168,
		10, 2, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�̵�_������", "�׽�Ʈ_�̵�", 0, 9, 15, false, true);
		KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�̵�_������", RectMake(19, 9, 30, 65));


		//���ҽ� �ε�
		//�Ϲݿ�����
		IMAGEMANAGER->addFrameImage("����_����", "resource/hyeongjoon/whip/whip_motion/whip_stop.bmp", 5427, 836,
			19, 2, true);
		IMAGEMANAGER->addFrameImage("����_�̵�", "resource/hyeongjoon/whip/whip_motion/whip_move.bmp", 2753, 862,
			8, 2, true);
		//IMAGEMANAGER->addFrameImage("����_�޸���", "resource/hyeongjoon/whip/whip_motion/whip_run.bmp", 2989, 794,
		//	8, 2, true);
		//IMAGEMANAGER->addFrameImage("����_�ɱ�", "resource/hyeongjoon/whip/whip_motion/whip_sit.bmp", 2100, 600,
		//	7, 2, true);
		//IMAGEMANAGER->addFrameImage("����_����", "resource/hyeongjoon/whip/whip_motion/whip_jump.bmp", 2720, 886,
		//	8, 2, true);
		//IMAGEMANAGER->addFrameImage("����_��������", "resource/hyeongjoon/whip/whip_motion/whip_moveJump.bmp", 3102, 1188,
		//	9, 2, true);
		//�Ϲݰ��� 
		//IMAGEMANAGER->addFrameImage("����_���", "resource/hyeongjoon/whip/whip_attack/whip_weakHand.bmp", 11210, 1680,
		//	9, 4, true);
		//IMAGEMANAGER->addFrameImage("����_���", "resource/hyeongjoon/whip/whip_attack/whip_strongFoot.bmp", 3000, 806,
		//	5, 2, true);
		//IMAGEMANAGER->addFrameImage("����_����", "resource/hyeongjoon/whip/whip_attack/whip_strongFoot.bmp", 16500, 2068,
		//	11, 4, true);
		//IMAGEMANAGER->addFrameImage("����_����", "resource/hyeongjoon/whip/whip_attack/whip_strongFoot.bmp", 4950, 912,
		//	11, 2, true);
		//IMAGEMANAGER->addFrameImage("����_�ɱ�_���", "resource/hyeongjoon/whip/whip_attack/whip_weakHand.bmp", 10660, 874,
		//	13, 2, true);
		//IMAGEMANAGER->addFrameImage("����_�ɱ�_���", "resource/hyeongjoon/whip/whip_attack/whip_sitWeakFoot.bmp", 4900, 520,
		//	7, 2, true);
		//IMAGEMANAGER->addFrameImage("����_�ɱ�_����", "resource/hyeongjoon/whip/whip_attack/whip_sitStrongHand.bmp", 11000, 1200,
		//	19, 2, true);
		//IMAGEMANAGER->addFrameImage("����_�ɱ�_����", "resource/hyeongjoon/whip/whip_attack/whip_sitStrongFoot.bmp", 4800, 520,
		//	6, 2, true);
		//IMAGEMANAGER->addFrameImage("����_����_��", "resource/hyeongjoon/whip/whip_attack/whip_jumpHand.bmp", 2280, 819,
		//	8, 2, true);
		//IMAGEMANAGER->addFrameImage("����_����_��", "resource/hyeongjoon/whip/whip_attack/whip_jumpFoot.bmp", 2850, 746,
		//	5, 2, true);
		//
		////��ų1,2 + �ʻ��
		//IMAGEMANAGER->addFrameImage("����_��ų1", "resource/hyeongjoon/whip/whip_skill/whip_skill1.bmp", 12430, 4260,
		//	11, 6, true);
		//IMAGEMANAGER->addFrameImage("����_��ų2", "resource/hyeongjoon/whip/whip_skill/whip_skill2.bmp", 3300, 4836,
		//	10, 4, true);
		//IMAGEMANAGER->addFrameImage("����_�ʻ��", "resource/hyeongjoon/whip/whip_skill/whip_specialSkill.bmp", 12120, 6128,
		//	12, 8, true);

		//����
		//KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�̵�_������", "�׽�Ʈ_�̵�", 0, 9, 15, false, true);
		//KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�̵�_������", RectMakeCenter(20, 10, 30, 67));

		//�Ϲݿ�����
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_stop_right", "����_����", 0, 18, 5, true, true);
		KEYANIMANAGER->setCollisionRect("whip_stop_right", RectMakeCenter(150, 200, 200, 400));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_stop_left", "����_����", 37, 19, 5, true, true);
		KEYANIMANAGER->setCollisionRect("whip_stop_left", RectMakeCenter(150, 200, 200, 400));

		KEYANIMANAGER->addCoordinateFrameAnimation("whip_move_right", "����_�̵�", 0, 7, 5, false, true);
		KEYANIMANAGER->setCollisionRect("whip_move_right", RectMakeCenter(150, 200, 200, 400));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_move_left", "����_�̵�", 15, 8, 5, false, true);
		KEYANIMANAGER->setCollisionRect("whip_move_left", RectMakeCenter(150, 200, 200, 400));
		
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_�޸���_������", "����_�޸���", 0, 7, 5, false, true);
		//KEYANIMANAGER->setCollisionRect("����_�޸���_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_�޸���_����", "����_�޸���", 15, 8, 5, false, true);
		//KEYANIMANAGER->setCollisionRect("����_�޸���_����", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_�ɱ�_������", "����_�ɱ�", 0, 6, 5, true, true);
		//KEYANIMANAGER->setCollisionRect("����_�ɱ�_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_�ɱ�_����", "����_�ɱ�", 13, 7, 5, true, true);
		//KEYANIMANAGER->setCollisionRect("����_�ɱ�_����", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_����_������", "����_����", 0, 7, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_����_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_����_����", "����_����", 15, 8, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_����_����", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_��������_������", "����_��������", 0, 8, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_��������_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_��������_����", "����_��������", 17, 9, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_��������_����", RectMakeCenter(150, 200, 200, 400));


		//�Ϲݰ���
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_���_������", "����_���", 0, 17, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_���_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_���_����", "����_���", 35, 18, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_���_����", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_���_������", "����_���", 0, 4, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_���_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_���_����", "����_���", 9, 5, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_���_����", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_����_������", "����_����", 0, 21, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_����_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_����_����", "����_����", 43, 22, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_����_����", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_����_������", "����_����", 0, 10, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_����_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_����_����", "����_����", 21, 11, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_����_����", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_�ɱ�_���_������", "����_�ɱ�_���", 0, 12, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_�ɱ�_���_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_�ɱ�_���_����", "����_�ɱ�_���", 25, 13, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_�ɱ�_���_����", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_�ɱ�_���_������", "����_�ɱ�_���", 0, 6, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_�ɱ�_���_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_�ɱ�_���_����", "����_�ɱ�_���", 13, 7, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_�ɱ�_���_����", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_�ɱ�_����_������", "����_�ɱ�_����", 0, 18, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_�ɱ�_����_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_�ɱ�_����_����", "����_�ɱ�_����", 37, 19, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_�ɱ�_����_����", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_�ɱ�_����_������", "����_�ɱ�_����", 0, 5, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_�ɱ�_����_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_�ɱ�_����_����", "����_�ɱ�_����", 11, 6, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_�ɱ�_����_����", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_����_��_������", "����_����_��", 0, 7, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_����_��_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_����_��_����", "����_����_��", 15, 8, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_����_��_����", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_����_��_������", "����_����_��", 0, 4, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_����_��_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_����_��_����", "����_����_��", 9, 5, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_����_��_����", RectMakeCenter(150, 200, 200, 400));
		//
		////��ų 
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_��ų1_������", "����_��ų1", 0, 32, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_��ų1_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_��ų1_����", "����_��ų1", 65, 33, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_��ų1_����", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_��ų2_������", "����_��ų2", 0, 19, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_��ų2_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_��ų2_����", "����_��ų2", 39, 20, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_��ų2_����", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_�ʻ��_������", "����_�ʻ��", 0, 48, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_�ʻ��_������	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("����_�ʻ��_����", "����_�ʻ��", 95, 49, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("����_�ʻ��_����", RectMakeCenter(150, 200, 200, 400));
	
}