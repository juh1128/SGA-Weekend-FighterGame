#include "stdafx.h"
#include "athena.h"
#include "attackHitbox.h"

using namespace athenaState;

HRESULT athena::init(vector2D pos)
{
	//===============================================================================================

	//�ʱ�ȭ
	IMAGEMANAGER->addFrameImage("athena", "resource/siyeong/���,�ɱ�.bmp", 100, WINSIZEY / 2 - 50, 1440, 1260, 8, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("athena2", "resource/siyeong/���ʰȱ�,�ɱ�.bmp", 100, WINSIZEY / 2 - 50, 1440, 1260, 8, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("athenaAction", "resource/siyeong/����չ�.bmp", 100, WINSIZEY / 2 - 50, 1440, 840, 8, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("athenaAction2", "resource/siyeong/���ʰ���չ�.bmp", 100, WINSIZEY / 2 - 50, 1440, 840, 8, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("athenaSKill", "resource/siyeong/��ų.bmp", 100, WINSIZEY / 2 - 50, 1440, 840, 8, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("athenaSkill2", "resource/siyeong/���ʽ�ų.bmp", 100, WINSIZEY / 2 - 50, 1440, 840, 8, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("athenaHit", "resource/siyeong/���ʾƾ�.bmp", 100, WINSIZEY / 2 - 50, 720, 210, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("athenaHit2", "resource/siyeong/�ƾ�.bmp", 100, WINSIZEY / 2 - 50, 720, 210, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("athenaDie", "resource/siyeong/����.bmp", 100, WINSIZEY / 2 - 50, 720, 210, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("athenaDie2", "resource/siyeong/�����ʴ���.bmp", 100, WINSIZEY / 2 - 50, 720, 210, 4, 1, true, RGB(255, 0, 255));

	//��ų �� �̹���
	IMAGEMANAGER->addFrameImage("ball", "resource/siyeong/���׳�����Ʈ.bmp", 100, WINSIZEY / 2 - 50, 1520, 144, 19, 1, true, RGB(255, 0, 255));
	//�ִϸ��̼�

	int rightStop[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightStop", "athena", rightStop, 8, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaRightStop", RectMake(41,29, 103-41, 203-29));

	int leftStop[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftStop", "athena2", leftStop, 8, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftStop", RectMake(83, 29, 136 - 83, 203 - 29));

	int rightMove[] = { 8,9,10,11,12,13,14,15,16,17,18,19 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightMove", "athena", rightMove, 12, 15, true);
	KEYANIMANAGER->setCollisionRect("athenaRightMove", RectMake(62, 23, 108 - 62, 203 - 23));


	int leftMove[] = { 8,9,10,11,12,13,14,15,16,17,18,19 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftMove", "athena2", leftMove, 12, 15, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftMove", RectMake(65, 23, 108 - 62, 203 - 23));

	int rightBackStep[] = { 24,25,26,27,28,29,30,31 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightBackStep", "athena", rightBackStep, 8, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaRightBackStep", RectMake(33, 23, 106-33, 203 - 23));

	int leftBackStep[] = { 24,25,26,27,28,29,30,31 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftBackStep", "athena2", leftBackStep, 8, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftBackStep", RectMake(73, 23, 143-73, 203 -23 ));

	int rightJump[] = { 32,33,34,35,36,37,38,39,40 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightJump", "athena", rightJump, 9, 13, false);
	KEYANIMANAGER->setCollisionRect("athenaRightJump", RectMake(60, 40, 114-60, 134-40));

	int leftJump[] = { 32,33,34,35,36,37,38,39,40 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftJump", "athena", leftJump, 9, 13, false);
	KEYANIMANAGER->setCollisionRect("athenaLeftJump", RectMake(54, 40, 113-54, 134-40));

	int rightSit[] = { 42,43,44,45 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightSit", "athena", rightSit, 4, 8, true);
	KEYANIMANAGER->setCollisionRect("athenaRightSit", RectMake(25, 65, 90- 25, 203 - 65));

	int leftSit[] = { 42,43,44,45 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftSit", "athena2", leftSit, 4, 8, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftSit", RectMake(90, 65, 154 - 90, 203 - 65));

	int rightDash[] = { 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightDash", "athenaAction", rightDash, 5, 15, true);
	KEYANIMANAGER->setCollisionRect("athenaRightDash", RectMake(51, 28, 152-51, 203-28));

	int leftDash[] = { 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftDash", "athenaAction2", leftDash, 5, 15, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftDash", RectMake(26, 28, 129-26, 203 - 28));

	int rightBackDash[] = { 5,6 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightBackDash", "athenaAction", rightBackDash, 2, 10, false);
	KEYANIMANAGER->setCollisionRect("athenaRightBackDash", RectMake(54, 20, 115-54, 203-20));

	int leftBackDash[] = { 5,6 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftBackDash", "athenaAction2", rightBackDash, 2, 10, false);
	KEYANIMANAGER->setCollisionRect("athenaLeftBackDash", RectMake(57, 20, 132-57, 203 - 20));

	int rightHandAttack[] = { 8,9,10,11,12 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightHandAttack", "athenaAction", rightHandAttack, 5, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaRightHandAttack", RectMake(71, 27, 116-71, 203 - 27));

	int rightFootAttack[] = { 13,14 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightFootAttack", "athenaAction", rightFootAttack, 2, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaRightFootAttack", RectMake(44, 15, 101-44, 203-15));

	int rightHandCount[] = { 16,17,18,19,20 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightHandCount", "athenaAction", rightHandCount, 5, 15, true);
	KEYANIMANAGER->setCollisionRect("athenaRightHandCount", RectMake(71, 26, 124-71, 203-26));

	int rightFootCount[] = { 24,25,26,27,28,29,30 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightFootCount", "athenaAction", rightFootCount, 7, 15, true);
	KEYANIMANAGER->setCollisionRect("athenaRightFootCount", RectMake(26, 26, 75, 203-26));

	int leftHandAttack[] = { 8,9,10,11,12 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftHandAttack", "athenaAction2", rightHandAttack, 5, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftHandAttack", RectMake(66, 27, 108-66, 203-27));

	int leftFootAttack[] = { 13,14 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftFootAttack", "athenaAction2", rightFootAttack, 2, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftFootAttack", RectMake(75, 15, 137-75, 203-15));

	int leftHandCount[] = { 16,17,18,19,20 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftHandCount", "athenaAction2", rightHandCount, 5, 15, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftHandCount", RectMake(51, 26, 119-51, 203-26));

	int leftFootCount[] = { 24,25,26,27,28,29,30 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftFootCount", "athenaAction2", rightFootCount, 7, 15, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftFootCount", RectMake(90, 26, 152-90, 203 - 26));

	int rightBall[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightSkill", "athenaSKill", rightBall, 10, 15, false);
	KEYANIMANAGER->setCollisionRect("athenaRightSkill", RectMake(52, 14, 96-52, 203-14));

	int leftBall[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftSkill", "athenaSKill", rightBall, 10, 15, false);
	KEYANIMANAGER->setCollisionRect("athenaLeftSkill", RectMake(82, 14, 128-82, 203-14));

	int rightHit[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightHit", "athenaHit", rightHit, 4, 20, false);
	KEYANIMANAGER->setCollisionRect("athenaRightHit", RectMake(54, 15, 120, 203 - 15));

	int leftHit[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftHit", "athenaHit2", leftHit, 4, 25, false);
	KEYANIMANAGER->setCollisionRect("athenaLeftHit", RectMake(75, 15, 125-75, 203-15));

	int rightDie[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightDie", "athenaDie", rightDie, 4, 10, false);
	KEYANIMANAGER->setCollisionRect("athenaRightDie", RectMake(14, 149, 104-14,203 - 149));

	int leftDie[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftDie", "athenaDie2", leftDie, 4, 10, false);
	KEYANIMANAGER->setCollisionRect("athenaLeftDie", RectMake(13, 140, 116-13, 203 - 140));

	//================================================================================================


	character::init("athena", pos, "athenaRightStop");

	_state = athenaState::LEFT_STOP;

	this->setScale(2.0f, 2.0f);
	

	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((athenaState::Enum)msg.data);
	});

	this->addCallback("hited", [this](tagMessage msg)
	{
		this->hit(msg);
	});

	this->addCallback("die", [this](tagMessage msg)
	{
		this->die(msg);
	});

	_isEnemyDirection = true;		//������ �����ʿ� ������

	this->setStatus(1000, 10);

									//Ŀ���
	int command[2] = { key::RIGHT,key::RIGHT };
	this->addCommand(command, 2, "dashRight");

	int command2[2] = { key::LEFT,key::LEFT };
	this->addCommand(command2, 2, "backDashRight");

	int command3[2] = {key::DOWN,key::ATTACK};
	this->addCommand(command3, 2, "ball");

	//Ŀ��� �ݹ�
	this->addCallback("dashRight", [this](tagMessage msg)
	{
		this->dash();
	});
	this->addCallback("backDashRight", [this](tagMessage msg)
	{
		this->dash();
	});
	this->addCallback("ball", [this](tagMessage msg)
	{
		this->skill();
	});

	_effect = NULL;

	return S_OK;
}

void athena::release()
{
	character::release();
}

void athena::update()
{
	character::update();
	stateUpdate(_state);
	this->enemyDirectiion();

	if (_effect != NULL)
	{
		_effect->_fire.x += 5;
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_effect->_fire.x + 182, _effect->_fire.y + 250), vector2D(130, 100), _enemy, 0.1f);
		WORLD->addObject(hitbox);
		_hitBox = hitbox;
		
		RECT hitRect = _hitBox->getCollisionRect();
		RECT temp;

		if (IntersectRect(&temp, &hitRect, &_enemy->getCollisionRect()))
		{
			_effect->_frameX += 2;
			_effect->_isFrame = true;
		}
	}
	
}

void athena::render()
{
	character::render();
}

void athena::changeState(athenaState::Enum state)					//���°� ���ϴ� ���� �ѹ��� ���Ѵ�.
{
	switch (state)
	{
	case athenaState::RIGHT_STOP:				//������ ���
		this->setAnimation("athenaRightStop");
		break;

	case athenaState::LEFT_STOP:				//���� ���
		this->setAnimation("athenaLeftStop");
		break;
	case athenaState::RIGHT_MOVE:				//������ �̵�
		this->setAnimation("athenaRightMove");
		break;

	case athenaState::RIGHT_BACK_STEP:			//�����ʹ������� �ڷ� �̵�
		this->setAnimation("athenaRightBackStep");
		break;

	case athenaState::LEFT_BACK_STEP:			//���ʹ��� �ڷ� �̵�
		this->setAnimation("athenaLeftBackStep");
		break;

	case athenaState::LEFT_MOVE:				//���� �̵�

		this->setAnimation("athenaLeftMove");
		break;

	case athenaState::RIGHT_JUMP:	case athenaState::RIGHT_MOVE_JUMP:			//������ ����
		this->setAnimation("athenaRightJump");
		jump(33);
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::RIGHT_STOP));
		break;

	case athenaState::LEFT_JUMP: case athenaState::LEFT_MOVE_JUMP:				//���� ����
		this->setAnimation("athenaLeftJump");
		jump(33);
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::LEFT_STOP));
		break;

	case athenaState::RIGHT_DASH:				//������ �뽬
		this->setAnimation("athenaRightDash");
		break;

	case athenaState::RIGHT_BACK_DASH:
		this->setAnimation("athenaRightBackDash");
		jump(12);
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::RIGHT_STOP));
		break;

	case athenaState::LEFT_DASH:				//���� �뽬
		this->setAnimation("athenaLeftDash");
		break;

	case athenaState::LEFT_BACK_DASH:
		this->setAnimation("athenaLeftBackDash");
		jump(12);
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::LEFT_STOP));
		break;

	case athenaState::RIGHT_SIT:				//������ �ɱ�
		this->setAnimation("athenaRightSit");
		break;

	case athenaState::LEFT_SIT:
		this->setAnimation("athenaLeftSit");	//���� �ɱ�
		break;

	case athenaState::RIGHT_FOOT_ATTACK:
	{
		this->setAnimation("athenaRightFootAttack");	//��� ����
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::RIGHT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 120, _pos.y - 70), vector2D(180, 120), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;

	case athenaState::LEFT_FOOT_ATTACK:
	{
		this->setAnimation("athenaLeftFootAttack");	//��� ����
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::LEFT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 120, _pos.y - 70), vector2D(180, 120), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;

	case athenaState::LEFT_HAND_ATTACK:
	{
		this->setAnimation("athenaLeftHandAttack");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::LEFT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x - 120, _pos.y - 70), vector2D(180, 100), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;

	case athenaState::RIGHT_HAND_ATTACK:	//��� ����
	{
		this->setAnimation("athenaRightHandAttack");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::RIGHT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 120, _pos.y - 70), vector2D(180, 100), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;

	case athenaState::RIGHT_FOOT_COUNT:
	{
		this->setAnimation("athenaRightFootCount");

		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::RIGHT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 120, _pos.y - 70), vector2D(180, 120), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;

	case athenaState::LEFT_FOOT_COUNT:
	{
		this->setAnimation("athenaLeftFootCount");

		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::LEFT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 120, _pos.y - 70), vector2D(180, 120), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;

	case athenaState::RIGHT_HAND_COUNT:
	{
		this->setAnimation("athenaRightHandCount");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::RIGHT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 120, _pos.y - 70), vector2D(180, 100), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;


	case athenaState::LEFT_HAND_COUNT:
	{
		this->setAnimation("athenaLeftHandCount");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::LEFT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 120, _pos.y - 70), vector2D(180, 100), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;
	
	case athenaState::RIGHT_SKILL_BALL:		//�������� ������
	{
		this->setAnimation("athenaRightSkill");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::RIGHT_STOP));

		athenaeffect* effect = new athenaeffect;
		effect->init("ball", vector2D(_pos.x + 30, _pos.y - 350));
		WORLD->addObject(effect);
		_effect = effect;
	}
	break;

	case athenaState::RIGHT_HIT:
		this->setAnimation("athenaRightHit");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::RIGHT_STOP));
	break;

	case athenaState::LEFT_HIT:
		this->setAnimation("athenaLeftHit");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::LEFT_STOP));
	break;

	case athenaState::RIGHT_DIE:
		this->setAnimation("athenaRightDie");
		//this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::RIGHT_STOP));
	break;

	case athenaState::LEFT_DIE:
		this->setAnimation("athenaLeftDie");
		//this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::LEFT_STOP));
		break;

	
	}
	_state = state;
}


void athena::stateUpdate(athenaState::Enum state)						//������Ʈ���� ��� ���ư��� ����
{
	switch (state)
	{
	case athenaState::RIGHT_STOP:
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))				//������������ ������Ű�� �ѹ��������� (�������̵����� ���º���)
		{
			changeState(athenaState::RIGHT_MOVE);
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))				//�������� ���� ����Ű�� �ѹ��������� (�ڷ� �齺��)
		{
			changeState(athenaState::RIGHT_BACK_STEP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))				//������ ��������϶� �ѹ������� (���� ����)
		{
			changeState(athenaState::RIGHT_JUMP);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))				//������ ��������϶� �ѹ� ������ (�ɱ�)
		{
			changeState(athenaState::RIGHT_SIT);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			changeState(athenaState::RIGHT_HAND_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			changeState(athenaState::RIGHT_FOOT_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			changeState(athenaState::RIGHT_FOOT_COUNT);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			changeState(athenaState::RIGHT_HAND_COUNT);
		}

		if (!_isEnemyDirection)
		{
			this->changeState(athenaState::LEFT_STOP);
		}
		break;

	case athenaState::LEFT_STOP:
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			changeState(athenaState::LEFT_MOVE);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			changeState(athenaState::LEFT_BACK_STEP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			changeState(athenaState::LEFT_JUMP);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(athenaState::LEFT_SIT);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			changeState(athenaState::LEFT_HAND_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			changeState(athenaState::LEFT_FOOT_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			changeState(athenaState::LEFT_HAND_COUNT);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			changeState(athenaState::LEFT_FOOT_COUNT);
		}

		if (_isEnemyDirection)
		{
			this->changeState(athenaState::RIGHT_STOP);
		}


		break;

	case athenaState::RIGHT_MOVE: case athenaState::RIGHT_DASH:
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))				//�������� ���� ������Ű�� �ڴ������� (������ �̵�)
		{
			_pos.x += 10;
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))				//������ Ű�� ������ (������ ��� ���º���)
		{
			changeState(athenaState::RIGHT_STOP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))				//������ �̵��ÿ� ����Ű�� �ѹ��� �������� (�����̵� ���º���)
		{
			changeState(athenaState::RIGHT_BACK_STEP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			changeState(athenaState::RIGHT_MOVE_JUMP);
		}

		if (_isEnemyDirection)											//������ �����ʿ� �ִٸ�
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))			//Ű���� �ն���
			{
				this->changeState(athenaState::RIGHT_STOP);				//������ ��������
			}
		}

		else if (!_isEnemyDirection)								//������ ���ʿ� �ִٸ�
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))		//Ű���� �ն���
			{
				this->changeState(athenaState::LEFT_STOP);			//���� �������·� ��ȯ 
			}

		}
		break;

	case athenaState::RIGHT_BACK_STEP:
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))				//����Ű�� �� ������ ������ (�������� �̵�)
		{
			_pos.x -= 10;
		}
		else if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))			//���������� �����϶��� �ް����� �齺��
		{
			changeState(athenaState::RIGHT_STOP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			changeState(athenaState::RIGHT_MOVE);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			changeState(athenaState::LEFT_MOVE_JUMP);
		}
		break;

	case athenaState::LEFT_BACK_STEP:
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			_pos.x += 10;
		}
		else if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))
		{
			changeState(athenaState::LEFT_STOP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			changeState(athenaState::LEFT_MOVE);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			changeState(athenaState::RIGHT_MOVE_JUMP);
		}
		break;

	case athenaState::LEFT_MOVE: case athenaState::LEFT_DASH:
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))				//����Ű�� �� ������ ������ (�������� �̵�)
		{
			_pos.x -= 10;
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))				//����Ű�� ������ ���� (������ ��� ���º���)
		{
			changeState(athenaState::LEFT_STOP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))				//�������� �̵����϶� ������Ű�� �ѹ��� �������� (�������̵� ���º���)
		{
			changeState(athenaState::LEFT_BACK_STEP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			changeState(athenaState::LEFT_MOVE_JUMP);
		}

		if (_isEnemyDirection)											//������ �����ʿ� �ִٸ�
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))			//�����̵� Ű���� �ն��� 
			{
				this->changeState(athenaState::RIGHT_STOP);				//������ �������·� ��ȯ
			}
		}

		else if (!_isEnemyDirection)									//������ ���ʿ� �ִٸ�
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))			//���� �̵�Ű���� �ն���
			{
				this->changeState(athenaState::LEFT_STOP);				//���� �������·� ��ȯ 
			}
		}
		break;

	case athenaState::RIGHT_JUMP:
		break;

	case athenaState::RIGHT_MOVE_JUMP:
		_pos.x += 10;
		break;


	case athenaState::LEFT_JUMP:
		break;

	case athenaState::LEFT_MOVE_JUMP:
		_pos.x -= 10;
		break;

	case athenaState::RIGHT_SIT:
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))				//�Ʒ�Ű�� ������ ����(������ ��� ���� ����)
		{
			changeState(athenaState::RIGHT_STOP);
		}
		break;

	case athenaState::LEFT_SIT:
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))				//�Ʒ�Ű�� ������ ����(���� ��� ���� ����)
		{
			changeState(athenaState::LEFT_STOP);
		}
		break;

	case athenaState::RIGHT_BACK_DASH:
		_pos.x -= 20;
		break;

	case athenaState::LEFT_BACK_DASH:
		_pos.x += 20;
		break;

	case athenaState::RIGHT_FOOT_ATTACK:
		break;

	case athenaState::RIGHT_HAND_ATTACK:
		break;

	case athenaState::RIGHT_FOOT_COUNT:
		break;

	case athenaState::RIGHT_HAND_COUNT:
		break;

		//case athenaState::LEFT_DASH:
		//	break;		 

	case athenaState::LEFT_FOOT_ATTACK:
		break;

	case athenaState::LEFT_HAND_ATTACK:
		break;

	case athenaState::LEFT_FOOT_COUNT:
		break;

	case athenaState::LEFT_HAND_COUNT:
		break;

	case athenaState::RIGHT_SKILL_BALL:
		
	break;
	}

}

void athena::enemyDirectiion()
{
	if (_pos.x < _enemy->_pos.x && !_isEnemyDirection)
	{
		_isEnemyDirection = true;
	}
	else if (_pos.x > _enemy->_pos.x&&_isEnemyDirection)
	{
		_isEnemyDirection = false;
	}
}

void athena::dash()
{
	if (_state == athenaState::RIGHT_STOP || _state == athenaState::RIGHT_MOVE)
	{
		changeState(athenaState::RIGHT_DASH);

	}
	if (_state == athenaState::RIGHT_BACK_STEP)
	{
		changeState(athenaState::RIGHT_BACK_DASH);
	}
	if (_state == athenaState::LEFT_STOP || _state == athenaState::LEFT_MOVE)
	{
		changeState(athenaState::LEFT_DASH);

	}
	if (_state == athenaState::LEFT_BACK_STEP)
	{
		changeState(athenaState::LEFT_BACK_DASH);
	}

}

void athena::skill()
{
	if (_state == athenaState::RIGHT_STOP || _state == athenaState::RIGHT_MOVE)
	{
		changeState(athenaState::RIGHT_SKILL_BALL);
	}
}

void athena::hit(tagMessage msg)
{
	tagMessage massege = msg;
	if (massege.data == DIRECTION::LEFT)
	{
	//	if (_state != athenaState::LEFT_HIT)
		//{
			changeState(athenaState::LEFT_HIT);
		//}
	}
	else if (massege.data == DIRECTION::RIGHT)
	{
	//	if (_state != athenaState::RIGHT_HIT)
		//{
			changeState(athenaState::RIGHT_HIT);
		//}
	}
}

void athena::die(tagMessage msg)
{
	tagMessage massege = msg;
	if (massege.data == DIRECTION::LEFT)
	{
		changeState(athenaState::LEFT_DIE);
	}
	else if (massege.data == DIRECTION::RIGHT)
	{
		changeState(athenaState::RIGHT_DIE);
	}
}