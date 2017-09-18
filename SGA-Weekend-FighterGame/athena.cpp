#include "stdafx.h"
#include "athena.h"
#include "attackHitbox.h"


HRESULT athena::init(vector2D pos)
{
//===============================================================================================
	
	//�ʱ�ȭ
	IMAGEMANAGER->addFrameImage("athena", "resource/siyeong/���,�ɱ�.bmp", 100, WINSIZEY / 2 - 50, 1440, 1260, 8, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("athena2", "resource/siyeong/���ʰȱ�,�ɱ�.bmp", 100, WINSIZEY / 2 - 50, 1440, 1260, 8, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("athenaAction", "resource/siyeong/����չ�.bmp", 100, WINSIZEY / 2 - 50, 1440, 840, 8, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("athenaAction2", "resource/siyeong/���ʰ���չ�.bmp", 100, WINSIZEY / 2 - 50, 1440, 840, 8, 4, true, RGB(255, 0, 255));

	////�ִϸ��̼�
	
	int rightStop[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightStop", "athena", rightStop, 8, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaRightStop", RectMake(90, 40, 130, 350));

	int leftStop[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftStop", "athena2", leftStop, 8, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftStop", RectMake(90, 40, 130, 350));

	int rightMove[] = { 8,9,10,11,12,13,14,15,16,17,18,19 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightMove", "athena", rightMove, 12, 15, true);
	KEYANIMANAGER->setCollisionRect("athenaRightMove", RectMake(90, 40, 130, 350));


	int leftMove[] = { 8,9,10,11,12,13,14,15,16,17,18,19 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftMove", "athena2", leftMove, 12, 15, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftMove", RectMake(90, 40, 130, 350));

	int rightBackStep[] = { 24,25,26,27,28,29,30,31 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightBackStep", "athena", rightBackStep, 8, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaRightBackStep", RectMake(90, 40, 130, 350));

	int leftBackStep[] = { 24,25,26,27,28,29,30,31 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftBackStep", "athena2", leftBackStep, 8, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftBackStep", RectMake(90, 40, 130, 350));

	int rightJump[] = { 32,33,34,35,36,37,38,39,40 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightJump", "athena", rightJump, 9, 13, false);
	KEYANIMANAGER->setCollisionRect("athenaRightJump", RectMake(90, 40, 130, 350));

	int leftJump[] = { 32,33,34,35,36,37,38,39,40 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftJump", "athena", leftJump, 9, 13, false);
	KEYANIMANAGER->setCollisionRect("athenaLeftJump", RectMake(90, 40, 130, 350));

	int rightSit[] = { 42,43,44,45 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightSit", "athena", rightSit, 4, 8, true);
	KEYANIMANAGER->setCollisionRect("athenaRightSit", RectMake(90, 130, 130, 260));

	int leftSit[] = { 42,43,44,45 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftSit", "athena2", leftSit, 4, 8, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftSit", RectMake(90, 130, 130, 260));

	//int rightDash[] = { 47,48,49,50,51 };
	//KEYANIMANAGER->addArrayFrameAnimation("athenaLeftDash", "athena", rightDash, 7, 15, true);
	//
	//int rightBackDash[] = { 52,53 };
	//KEYANIMANAGER->addArrayFrameAnimation("athenaLeftBackDash", "athena", rightBackDash, 2, 10, true);
	//
	int rightHandAttack[] = { 8,9,10,11,12 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightHandAttack", "athenaAction", rightHandAttack, 5, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaRightHandAttack", RectMake(90, 40, 130, 350));

	int rightFootAttack[] = { 13,14 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightFootAttack", "athenaAction", rightFootAttack, 2, 5, true);
	KEYANIMANAGER->setCollisionRect("athenaRightFootAttack", RectMake(90, 40, 130, 350));

	int rightHandCount[] = { 16,17,18,19,20 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightHandCount", "athenaAction", rightHandCount, 5, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaRightHandCount", RectMake(90, 40, 130, 350));

	int rightFootCount[] = { 24,25,26,27,28,29,30 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightFootCount", "athenaAction", rightFootCount, 7, 15, true);
	KEYANIMANAGER->setCollisionRect("athenaRightFootCount", RectMake(90, 40, 130, 350));

	int leftHandAttack[] = { 8,9,10,11,12 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftHandAttack", "athenaAction2", rightHandAttack, 5, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftHandAttack", RectMake(90, 40, 130, 350));

	int leftFootAttack[] = { 13,14 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftFootAttack", "athenaAction2", rightFootAttack, 2, 5, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftFootAttack", RectMake(90, 40, 130, 350));

	int leftHandCount[] = { 16,17,18,19,20 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftHandCount", "athenaAction2", rightHandCount, 5, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftHandCount", RectMake(90, 40, 130, 350));

	int leftFootCount[] = { 24,25,26,27,28,29,30 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftFootCount", "athenaAction2", rightFootCount, 7, 15, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftFootCount", RectMake(90, 40, 130, 350));

//================================================================================================
	
	
	character::init("athena", pos, "athenaRightStop");
	
	_state = athenaState::LEFT_STOP;
	
	
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((athenaState::Enum)msg.data);
	});

	_isEnemyDirection = true;		//������ �����ʿ� ������

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
		jump(35);
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::RIGHT_STOP));
		break;

	case athenaState::LEFT_JUMP: case athenaState::LEFT_MOVE_JUMP:				//���� ����
		this->setAnimation("athenaLeftJump");
		jump(35);
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, athenaState::LEFT_STOP));
		break;

	case athenaState::RIGHT_DASH:				//������ �뽬
		this->setAnimation("athenRightDash");
		break;

	case athenaState::LEFT_DASH:				//���� �뽬
		this->setAnimation("athenaLeftDash");
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
		hitbox->init(30, vector2D(_pos.x + 120, _pos.y - 70), vector2D(180, 100), _enemy, 0.5f);
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
	
	case athenaState::RIGHT_MOVE:
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
	
	case athenaState::LEFT_MOVE:
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
	
	case athenaState::RIGHT_DASH:
	break;
	
	case athenaState::RIGHT_FOOT_ATTACK:
	break;
	
	case athenaState::RIGHT_HAND_ATTACK:
	break;
	
	case athenaState::RIGHT_FOOT_COUNT:
	break;
	
	case athenaState::RIGHT_HAND_COUNT:
	break;

	case athenaState::LEFT_DASH:
		break;		 

	case athenaState::LEFT_FOOT_ATTACK:
		break;		

	case athenaState::LEFT_HAND_ATTACK:
		break;		

	case athenaState::LEFT_FOOT_COUNT:
		break;		  

	case athenaState::LEFT_HAND_COUNT:
		break;
	}

}

void athena::enemyDirectiion()
{
	if (_pos.x < _enemy->_pos.x&&!_isEnemyDirection)
	{
		_isEnemyDirection = true;
	}
	else if (_pos.x > _enemy->_pos.x&&_isEnemyDirection)
	{
		_isEnemyDirection = false;
	}
}
