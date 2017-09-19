#include "stdafx.h"
#include "neko.h"
#include "attackHitbox.h"



//s
HRESULT neko::init(vector2D pos)
{
	//�̹��� �ε� 
	IMAGEMANAGER->addFrameImage("neko1_left", "resource/soonwoo/neko/neko1_left.bmp", 4352, 1795, 17, 7, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("neko1_right", "resource/soonwoo/neko/neko1_right.bmp", 4352, 1790, 17, 7, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("nekoRightFireEffect", "resource/soonwoo/neko/nekoFire.bmp", 7424, 256, 29, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("nekoLeftFireEffect", "resource/soonwoo/neko/nekoFireLeft.bmp", 7424, 256, 29, 1, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("nekoRightBeamEffect", "resource/soonwoo/neko/nekoRightBeam.bmp", 6400, 200, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("nekoRightBeamEffect", "resource/soonwoo/neko/nekoRightBeam2.bmp", 19200, 600, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("nekoLeftBeamEffect", "resource/soonwoo/neko/nekoLeftBeam.bmp", 19200, 600, 16, 1, true, RGB(255, 0, 255));

	//����Ʈ �ε�
	EFFECTMANAGER->addEffect("blockEffect", "resource/soonwoo/neko/blockEffect.bmp", 448, 64, 64, 64, 13, 10,vector2D(3.0,3.0));
	EFFECTMANAGER->addEffect("blockEffectLeft", "resource/soonwoo/neko/blockEffectLeft.bmp", 448, 64, 64, 64, 13, 10, vector2D(3.0, 3.0));
	EFFECTMANAGER->addEffect("skillEffect", "resource/soonwoo/neko/skillEffect.bmp", 480, 80, 80, 80, 10, 5, vector2D(5.0, 5.0));
	//���� �ε�
	

	//Ű�ִϸ޴��� ����

	//======================STOP======================
	int rightStop[]{ 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightStop", "neko1_right", rightStop, 5, 6, true);
	KEYANIMANAGER->setCollisionRect("nekoRightStop", RectMake(118, 179, 24, 42));

	int leftStop[]{ 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftStop", "neko1_left", leftStop, 5, 6, true);
	KEYANIMANAGER->setCollisionRect("nekoLeftStop", RectMake(112, 179, 24, 42));
	//====================MOVE==========================
	int rightMove[]{ 5,6,7,8,9,10,11,12 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightMove", "neko1_right", rightMove, 8, 7, true);
	KEYANIMANAGER->setCollisionRect("nekoRightMove", RectMake(118, 179, 24, 42));
	int leftMove[]{ 5,6,7,8,9,10,11,12 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftMove", "neko1_left", leftMove, 8, 7, true);
	KEYANIMANAGER->setCollisionRect("nekoLeftMove", RectMake(112, 179, 24, 42));

	//===================DASH=============================
	int rightDash[]{ 40,41,42,43,44,45,46,47 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightDash", "neko1_right", rightDash, 7, 15, false);
	KEYANIMANAGER->setCollisionRect("nekoRightDash", RectMake(118, 179, 24, 42));
	int leftDash[]{ 40,41,42,43,44,45,46,47 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftDash", "neko1_left", leftDash, 7, 15, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftDash", RectMake(112, 179, 24, 42));
	//===================BACK DASH========================
	int rightBackDash[]{ 34,35,36,37,38,39 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightBackDash", "neko1_right", rightBackDash, 6, 15, false);
	KEYANIMANAGER->setCollisionRect("nekoRightBackDash", RectMake(118, 179, 24, 42));
	int leftBackDash[]{ 34,35,36,37,38,39 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftBackDash", "neko1_left", leftBackDash, 6, 15, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftBackDash", RectMake(112, 179, 24, 42));
	//=====================ChangeSIT===========================

	//DOWN
	int rightChangeSit[]{ 13,14,15,16 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightChangeSit", "neko1_right", rightChangeSit, 4, 25, false);
	KEYANIMANAGER->setCollisionRect("nekoRightChangeSit", RectMake(118, 179, 24, 42));
	int leftChangeSit[]{ 13,14,15,16 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftChangeSit", "neko1_left", leftChangeSit, 4, 25, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftChangeSit", RectMake(118, 179, 24, 42));
	//UP
	int rightChangeSitUp[]{ 16,15,14,13 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightChangeSitUp", "neko1_right", rightChangeSitUp, 4, 25, false);
	KEYANIMANAGER->setCollisionRect("nekoRightChangeSitUp", RectMake(118, 179, 24, 42));
	int leftChangeSitUp[]{ 16,15,14,13 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftChangeSitUp", "neko1_left", leftChangeSitUp, 4, 25, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftChangeSitUp", RectMake(118, 179, 24, 42));
	//========================SIT=============================
	int rightSit[]{ 16 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightSit", "neko1_right", rightSit, 1, 1, false);
	KEYANIMANAGER->setCollisionRect("nekoRightSit", RectMake(122, 200, 26, 22));
	int leftSit[]{ 16 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftSit", "neko1_left", leftSit, 1, 1, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftSit", RectMake(107, 203, 26, 22));
	//=========================SIT MOVE=============================
	int rightSitMove[]{ 30,31 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightSitMove", "neko1_right", rightSitMove, 2, 2, true);
	KEYANIMANAGER->setCollisionRect("nekoRightSitMove", RectMake(122, 200, 26, 22));
	int leftSitMove[]{ 30 , 31 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftSitMove", "neko1_left", leftSitMove, 2, 2, true);
	KEYANIMANAGER->setCollisionRect("nekoLeftSitMove", RectMake(107, 203, 26, 22));
	//=========================JUMP================================
	//normal jump
	int	rightJump[]{ 17,18,19,20,21,22,23,24,25,26,27,28,29 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightJump", "neko1_right", rightJump, 13, 8, false);
	KEYANIMANAGER->setCollisionRect("nekoRightJump", RectMake(118, 179, 24, 42));
	int leftJump[]{ 17,18,19,20,21,22,23,24,25,26,27,28,29 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftJump", "neko1_left", leftJump, 13, 8, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftJump", RectMake(112, 179, 24, 42));

	//neko falling
	int rightFall[]{ 26 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightFall", "neko1_right", rightFall, 1, 1, false);
	KEYANIMANAGER->setCollisionRect("nekoRightFall", RectMake(118, 179, 24, 42));
	int  leftFall[]{ 26 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftFall", "neko1_left", leftFall, 1, 1, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftFall", RectMake(112, 179, 24, 42));

	//back Jump
	int  rightBackJump[]{ 51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightBackJump", "neko1_right", rightBackJump, 17, 12, false);
	KEYANIMANAGER->setCollisionRect("nekoRightBackJump", RectMake(118, 179, 24, 42));
	int  leftBackJump[]{ 51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftBackJump", "neko1_left", leftBackJump, 17, 12, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftBackJump", RectMake(118, 179, 24, 42));

	//========================ATTACK===============================
	int rightAttack[]{ 32,33 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightAttack", "neko1_right", rightAttack, 2, 16, false);
	KEYANIMANAGER->setCollisionRect("nekoRightAttack", RectMake(118, 179, 24, 42));
	int leftAttack[]{ 32,33 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftAttack", "neko1_left", leftAttack, 2, 16, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftAttack", RectMake(112, 179, 24, 42));

	//sit Attack
	int rightSitAttack[]{ 68,69 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightSitAttack", "neko1_right", rightSitAttack, 2, 16, false);
	KEYANIMANAGER->setCollisionRect("nekoRightSitAttack", RectMake(122, 200, 26, 22));
	int leftSitAttack[]{ 68,69 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftSitAttack", "neko1_left", leftSitAttack, 2, 16, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftSitAttack", RectMake(107, 203, 26, 22));

	//kcikAttack
	int rightKick[]{ 78,79,80 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightKick", "neko1_right", rightKick, 3, 15, false);
	KEYANIMANAGER->setCollisionRect("nekoRightKick", RectMake(118, 179, 24, 42));
	int leftKick[]{ 78,79,80 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftKick", "neko1_left", leftKick, 3, 15, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftKick", RectMake(112, 179, 24, 42));

	//sitKickAttack
	int rightSitKick[]{ 74,75,76,77 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightSitKick", "neko1_right", rightSitKick, 4, 10, false);
	KEYANIMANAGER->setCollisionRect("nekoRightSitKick", RectMake(122, 200, 26, 22));
	int leftSitKick[]{ 74,75,76,77 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftSitKick", "neko1_left", leftSitKick, 4, 10, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftSitKick", RectMake(107, 203, 26, 22));

	//skiil Fire
	int rightFire[]{ 96,97,98,99,100,101 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightFire", "neko1_right", rightFire, 6, 10, false);
	KEYANIMANAGER->setCollisionRect("nekoRightFire", RectMake(118, 179, 24, 42));
	int leftFire[]{ 96,97,98,99,100,101 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftFire", "neko1_left", leftFire, 6, 10, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftFire", RectMake(112, 179, 24, 42));

	//skill beam
	int rightBeam[]{ 117,118 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightBeam", "neko1_right", rightBeam, 2, 10, false);
	KEYANIMANAGER->setCollisionRect("nekoRightBeam", RectMake(118, 179, 24, 42));
	int lefttBeam[]{ 117,118 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftBeam", "neko1_left", lefttBeam, 2, 10, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftBeam", RectMake(112, 179, 24, 42));

	//=========================DEFENSE===============================
	//normmal defense
	int rightDefense[]{ 48 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightDefense", "neko1_right", rightDefense, 1, 15, false);
	KEYANIMANAGER->setCollisionRect("nekoRightDefense", RectMake(118, 179, 24, 42));

	int leftDefense[]{ 48 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftDefense", "neko1_left", leftDefense, 1, 15, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftDefense", RectMake(112, 179, 24, 42));
	//sit defense
	int rightSitDefense[]{ 49 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightSitDefense", "neko1_right", rightSitDefense, 1, 1, false);
	KEYANIMANAGER->setCollisionRect("nekoRightSitDefense", RectMake(122, 200, 26, 22));
	int leftSitDefense[]{ 49 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftSitDefense", "neko1_left", leftSitDefense, 1, 1, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftSitDefense", RectMake(107, 203, 26, 22));

	//===================================fly===========================
	int rightFly[]{ 103,104,105,106,107 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightFly", "neko1_right", rightFly, 5, 10, true);
	KEYANIMANAGER->setCollisionRect("nekoRightFly", RectMake(120, 203, 56, 14));
	int leftFly[]{ 103,104,105,106,107 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftFly", "neko1_left", leftFly, 5, 10, true);
	KEYANIMANAGER->setCollisionRect("nekoLeftFly", RectMake(85, 200, 56, 14));

	//====================================�ĸ´°�=========================
	int rightHit[]{ 108,109,110 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightHit", "neko1_right", rightHit, 3, 10, false);
	KEYANIMANAGER->setCollisionRect("nekoRightHit", RectMake(118, 179, 24, 42));
	int leftHit[]{ 108,109,110 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftHit", "neko1_left", leftHit, 3, 10, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftHit", RectMake(112, 179, 24, 42));
	//====================================�̰� �������� ��=============================
	int rightDing[]{ 111,112,113,114,115 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightDing", "neko1_right", rightDing, 5, 7, false);
	KEYANIMANAGER->setCollisionRect("nekoRightDing", RectMake(122, 200, 26, 22));
	int leftDing[]{ 111,112,113,114,115 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftDing", "neko1_left", leftDing, 5, 7, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftDing", RectMake(107, 203, 26, 22));
	//===================================������=============================================
	int rightDie[]{ 115 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightDie", "neko1_right", rightDie, 1, 1, false);
	KEYANIMANAGER->setCollisionRect("nekoRightDie", RectMake(122, 200, 26, 22));
	int leftDie[]{ 115 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftDie", "neko1_left", leftDie, 1, 1, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftDie", RectMake(107, 203, 26, 22));
	//===============================neko code �ʱ�ȭ=====================================================
	character::init("����", pos, "nekoRightStop");

	_state = RIGHT_STOP;		//������ �������·� �ʱ�ȭ 
	_isEnemyRight = true;		//�������ʿ� �ִ°� Ʈ��� �ʱ�ȭ

								//���� ���� ������
	_jumpPower = 0;
	_gravity = 0;
	_savePosY = this->_pos.y;
	_isJump = false;

	_effect = NULL;

	//�ɷ�ġ �ʱ�ȭ (ü�� , ���ݷ�)
	this->setStatus(1000, 10);

	//Ű ���� ����
	_saveLastKey = key::END;	//�ƹ�Ű�� �ȴ��� END�� �ʱ�ȭ  ���ش�.

								//=====================�ݹ� �Լ� ���=========================
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((tagNekoState::ENUM)msg.data);
	});

	this->addCallback("hited", [this](tagMessage msg)
	{
		this->hit(msg);
	});

	this->addCallback("block", [this](tagMessage msg)
	{
		this->block();
	});
	this->addCallback("die", [this](tagMessage msg)
	{
		this->die(msg);
	});


	this->setScale(3.0, 3.0);

	this->setGravity(0);		//�������� �߷� �Ⱦ�

	_centerPos = _pos;
	_centerPos.y = _pos.y + 50;

	//====================Ŀ�ǵ� �߰�====================================
	int command[3] = { DOWN,DOWN,KICK };
	this->addCommand(command, 3, "nekoFire");
	this->addCallback("nekoFire", [this](tagMessage msg)
	{
		this->nekoFire();
	});

	int command2[2] = { RIGHT,RIGHT };
	this->addCommand(command2, 2, "nekoRightFly");
	this->addCallback("nekoRightFly", [this](tagMessage msg)
	{
		this->nekoRightFly();
	});

	int command3[2] = { LEFT,LEFT };
	this->addCommand(command3, 2, "nekoLeftFly");
	this->addCallback("nekoLeftFly", [this](tagMessage msg)
	{
		this->nekoLeftFly();
	});

	int command4[3] = { DOWN,DOWN,ATTACK };
	this->addCommand(command4, 3, "nekoBeam");
	this->addCallback("nekoBeam", [this](tagMessage msg)
	{
		this->nekoBeam();
	});


	return S_OK;
}

void neko::release()
{
	character::release();
}

void neko::update()
{
	character::update();

	_centerPos.x = _pos.x;
	_centerPos.y = _pos.y + 210;

	this->jumping();

	this->stateUpdate(_state);

	this->enemyPos();

	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		EFFECTMANAGER->play("blockEffect", WINSIZEX/2 , WINSIZEY/2);
	}

}

void neko::render()
{
	character::render();

	RECT rc = CAMERAMANAGER->getRenderRect();

	if (_isDebugMode)
	{
		RectangleMakeCenter(getMemDC(), _centerPos.x - rc.left, _centerPos.y - rc.top, 10, 10);
	}
}


void neko::changeState(tagNekoState::ENUM state)
{
	switch (state)
	{
	case RIGHT_STOP:	//������ ��������
	{
		this->setAnimation("nekoRightStop");	//������ ������ ������ ����
	}
	break;
	case LEFT_STOP:		//���� ��������
	{
		this->setAnimation("nekoLeftStop");		//���� ������ ������ ����
	}
	break;
	case RIGHT_MOVE:	//������ �̵� ���� 
	{
		this->setAnimation("nekoRightMove");	//������ �̵����� ������ ����
	}
	break;
	case LEFT_MOVE:		//���� �̵� ����
	{
		this->setAnimation("nekoLeftMove");		//���� �̵����� ������ ���� 
	}
	break;
	case RIGHT_SIT:		//������ �ɱ� ����
	{
		this->setAnimation("nekoRightSit");		//������ �ɱ�� ������ ����
	}
	break;
	case LEFT_SIT:	//���� �ɱ� ����
	{
		this->setAnimation("nekoLeftSit");
	}
	break;
	case RIGHT_CHANGE_SIT:	//������ �������� ����
	{
		this->setAnimation("nekoRightChangeSit");		//������ �ɱ� ������� �����Ӻ���
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));	//�ɱ� ��� �����ӳ����� �ɱ�� ���º���
	}
	break;

	case LEFT_CHANGE_SIT:	//���� �������� ���� 
	{
		this->setAnimation("nekoLeftChangeSit");				//���� �ɴ� ������ ���
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_SIT));	//������ ������ ���� �ɱ���·� ��ȯ
	}
	break;

	case RIGHT_CHANGE_UP:	//������ �Ͼ�� ����
	{
		this->setAnimation("nekoRightChangeSitUp");		//������ �Ͼ�� ������ ���
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));	//������ ������ ������ ��������
	}
	break;

	case LEFT_CHAGNE_UP:	//���� �Ͼ�� ����
	{
		this->setAnimation("nekoLeftChangeSitUp");		//���� �Ͼ�� ������ ��� 
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));	//������ ������ ���� ���� ����
	}
	break;

	case RIGHT_SIT_MOVE:	//������ �ɱ� �̵�
	{
		this->setAnimation("nekoRightSitMove");		//������ �ɱ� �̵����� ������ ��ȯ 
	}
	break;

	case LEFT_SIT_MOVE:		//���� �ɱ� �̵�
	{
		this->setAnimation("nekoLeftSitMove");		//���� �ɱ� �̵����� ������ ��ȯ 
	}
	break;

	case RIGHT_JUMP:							//������ ���� ���� 
	{
		this->setJump();						//����!
		this->setAnimation("nekoRightJump");	//������ ���� ���������� ��ȯ 
	}
	break;
	case LEFT_JUMP:								//���� ���� ����
	{
		this->setJump();						//����!
		this->setAnimation("nekoLeftJump");		//���� ���� ���������� ��ȯ 
	}
	break;

	case RIGHT_BACK_JUMP:						//������ �� ���� 
	{
		this->setJump();						//����!
		this->setAnimation("nekoRightBackJump");//������ �� ���� ���������� ��ȯ  
	}
	break;

	case LEFT_BACK_JUMP:						//���� �� ����
	{
		this->setJump();						//����!
		this->setAnimation("nekoLeftBackJump");	//���� �� ���� ���������� ��ȯ
	}
	break;

	case RIGHT_ATTACK:							//������ ���
	{
		this->setAnimation("nekoRightAttack");	//������ ��� ���������� ��ȯ 
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));	//������ ������ ������ ������ ��ȯ 
																							//���ݷ�Ʈ ����
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x + 70, _centerPos.y - 5), vector2D(50, 75), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
	break;

	case LEFT_ATTACK:							//���� ���
	{
		this->setAnimation("nekoLeftAttack");	//���� ������������� ��ȯ
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));	//������ ������ ���� �������·� ��ȯ
																							//���ݷ�Ʈ ����
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x - 70, _centerPos.y - 5), vector2D(50, 75), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
	break;

	case RIGHT_SIT_ATTACK:						//������ �ɾ� ���
	{
		this->setAnimation("nekoRightSitAttack");	//������ �ɾ� ������� ������ ��ȯ
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));	//������ ������  ������ �ɾ� ���·κ�ȯ
																							//���ݷ�Ʈ ����
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x + 80, _centerPos.y + 50), vector2D(50, 60), _enemy, 0.1f);
		WORLD->addObject(hitbox);

		
	}
	break;
	case LEFT_SIT_ATTACK:						//���� �ɾ� ���
	{
		this->setAnimation("nekoLeftSitAttack");	//���� �ɾƾ������ ������ ��ȯ  
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_SIT));	//������ ������ ���� �ɾ� ���·� ��ȯ
																							//���ݷ�Ʈ ����
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x - 80, _centerPos.y + 50), vector2D(50, 60), _enemy, 0.1f);
		WORLD->addObject(hitbox);

		
	}
	break;

	case RIGHT_KICK:					//������ ű
	{
		this->setAnimation("nekoRightKick");				//������ ű ���������� ��ȯ 
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		//���ݷ�Ʈ ���� 
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x + 60, _centerPos.y + 30), vector2D(50, 60), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
	break;

	case LEFT_KICK:				//���� ű
	{
		this->setAnimation("nekoLeftKick");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));
		//���ݷ�Ʈ ���� 
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x - 60, _centerPos.y + 30), vector2D(50, 60), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
	break;

	case RIGHT_SIT_KICK:			//������ �ɾ� ��  
	{
		this->setAnimation("nekoRightSitKick");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));
		//���ݷ�Ʈ ���� 
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x + 90, _centerPos.y + 30), vector2D(100, 120), _enemy, 0.25f);
		WORLD->addObject(hitbox);
	}
	break;

	case LEFT_SIT_KICK:			//���� �ɾ� �� 
	{
		this->setAnimation("nekoLeftSitKick");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_SIT));
		//���ݷ�Ʈ ���� 
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x - 90, _centerPos.y + 30), vector2D(100, 120), _enemy, 0.25f);
		WORLD->addObject(hitbox);
	}
	break;

	case RIGHT_DEFENSE:						//������ ���� 
	{
		this->setAnimation("nekoRightDefense");	//������ ���� ���������� ��ȯ 

		EFFECTMANAGER->play("blockEffect", _pos.x + 10, _pos.y);
	}
	break;
	case LEFT_DEFENSE:							//���� ����
	{
		this->setAnimation("nekoLeftDefense");	//���� ���� ���������� ��ȯ 

		EFFECTMANAGER->play("blockEffect", _pos.x + 20, _pos.y);
	}
	break;

	case RIGHT_SIT_DEFENSE:					//������ �ɾ� ����
	{
		this->setAnimation("nekoRightSitDefense");	//������ �ɾ� ���� ���������� ��ȯ 

	
	}
	break;
	case LEFT_SIT_DEFENSE:						//���� �ɾ� ����
	{
		this->setAnimation("nekoLeftSitDefense");	//���� �ɾ� ���� ���������� ��ȯ 
	}
	break;

	case RIGHT_FIRE:							//������ �һձ�
	{
		this->setAnimation("nekoRightFire");	//������ �һձ� ���������� ����
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, RIGHT_STAY_FIRE));
	}
	break;
	case LEFT_FIRE:								//���� �һձ� 
	{
		this->setAnimation("nekoLeftFire");	//���� �һձ� ���������� ����
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, LEFT_STAY_FIRE));
	}
	break;

	case RIGHT_STAY_FIRE:						//������ �����ӻձ�
	{
		effectFire* effect = new effectFire;
		effect->init("nekoRightFireEffect", vector2D(_pos.x + 10, _centerPos.y - 190));
		WORLD->addObject(effect);
		_effect = effect;
	}
	break;

	case LEFT_STAY_FIRE:
	{
		effectFire* effect = new effectFire;
		effect->init("nekoLeftFireEffect", vector2D(_pos.x - 250, _centerPos.y - 190));
		WORLD->addObject(effect);
		_effect = effect;


	}
	break;

	case RIGHT_BEAM:
	{
		this->setAnimation("nekoRightBeam");

		effectFire* effect = new effectFire;
		effect->init("nekoRightBeamEffect", vector2D(_pos.x - 110, _centerPos.y - 450));
		WORLD->addObject(effect);
		_effect = effect;

		EFFECTMANAGER->play("skillEffect", _pos.x - 30, _centerPos.y - 50);
	}
	break;

	case LEFT_BEAM:
	{
		this->setAnimation("nekoLeftBeam");

		effectFire* effect = new effectFire;
		effect->init("nekoLeftBeamEffect", vector2D(_pos.x - 1070, _centerPos.y - 470));
		WORLD->addObject(effect);
		_effect = effect;
	}
	break;

	case RIGHT_FLY:
	{
		this->setAnimation("nekoRightFly");
		_isJump = false;
		_jumpPower = 0;
	}
	break;
	case LEFT_FLY:
	{
		this->setAnimation("nekoLeftFly");
		_isJump = false;
		_jumpPower = 0;
	}
	break;

	case RIGHT_FALL:
	{
		this->setAnimation("nekoRightFall");
	}
	break;

	case LEFT_FALL:
	{
		this->setAnimation("nekoLeftFall");
	}
	break;

	case RIGHT_DASH:
	{
		this->setAnimation("nekoRightDash");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, RIGHT_MOVE));
	}
	break;
	case LEFT_DASH:
	{
		this->setAnimation("nekoLeftDash");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, LEFT_MOVE));
	}
	break;

	case RIGHT_BACK_DASH:
	{
		this->setAnimation("nekoRightBackDash");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, RIGHT_STOP));
	}
	break;

	case LEFT_BACK_DASH:
	{
		this->setAnimation("nekoLeftBackDash");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, LEFT_STOP));
	}
	break;

	case RIGHT_HIT:
	{
		this->setAnimation("nekoRightHit");
		if (_isEnemyRight)
		{
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, RIGHT_STOP));
		}
		else if (!_isEnemyRight)
		{
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, LEFT_STOP));
		}
	}
	break;
	case LEFT_HIT:
	{
		this->setAnimation("nekoLeftHit");
		if (_isEnemyRight)
		{
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, RIGHT_STOP));
		}
		else if (!_isEnemyRight)
		{
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, LEFT_STOP));
		}
	}
	break;

	case RIGHT_DING:
	{
		this->setJump();						//����!
		_jumpPower = 13.0;
		this->setAnimation("nekoRightDing");
	}
	break;
	case LEFT_DING:
	{
		this->setJump();						//����!
		_jumpPower = 13.0;
		this->setAnimation("nekoLeftDing");
	}
	break;

	case RIGHT_DIE:
	{

	}
	break;
	case LEFT_DIE:
	{

	}
	break;



	//end
	}
	_state = state;

}

void neko::stateUpdate(tagNekoState::ENUM state)
{
	switch (state)
	{
	case tagNekoState::RIGHT_STOP:	//������ �⺻������ ��
	{
		//===================������ �̵����� ���� ����=================
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			this->changeState(RIGHT_MOVE);	//������ �̵����� ���� ����
		}

		//========================�������� ���º���===================
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			this->changeState(LEFT_MOVE);	//���� �̵����� ���� ����
		}
		//====================������ �ɱ� ������� ���� ����============
		if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			this->changeState(RIGHT_CHANGE_SIT);	//������ �ɴ� ������� ���� ����
		}
		//=====================���� ���·� ��ȯ=====================
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))			//����Ű�� �ѹ� �����ٸ�
		{
			this->changeState(RIGHT_JUMP);			//������ ���� ���·� ��ȯ 
			_saveLastKey = END;
		}
		//======================���� ���·� ��ȯ====================
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))			//���� ����Ű�� �����ٸ�
		{
			this->changeState(RIGHT_ATTACK);						//������·� ��ȯ
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::KICK]))			//ű�� �����ٸ�
		{
			this->changeState(RIGHT_KICK);							//������ ű ���·� ��ȯ 
		}


		if (!_isEnemyRight)this->changeState(LEFT_STOP);		//���� ���ʿ� �ִٸ� ���� ���� �������·� ��ȯ
	}
	break;
	case LEFT_STOP:			//���� ���������� �� 
	{
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))		//���� Ű�� �ѹ� ������
		{
			this->changeState(LEFT_MOVE);			//���� �̵� ���·� ��ȯ
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))		//������ Ű�� �ѹ� ������
		{
			this->changeState(RIGHT_MOVE);			//������ �̵� ���·�  ��ȯ 
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))		//�Ʒ�Ű�� �ѹ� ������
		{
			this->changeState(LEFT_CHANGE_SIT);		//���� �ɴ� ��� ���·� ��ȯ 
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))		//����Ű�� �ѹ� ������
		{
			this->changeState(LEFT_JUMP);			//���� ���� ���·� ��ȯ 
			_saveLastKey = END;
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))		//���Ű�� �����ٸ�
		{
			this->changeState(LEFT_ATTACK);						//���� ��� ���·� ��ȯ 
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::KICK]))			//ű�� �����ٸ�
		{
			this->changeState(LEFT_KICK);							//������ ű ���·� ��ȯ 
		}


		if (_isEnemyRight)this->changeState(RIGHT_STOP);		//���� �����ʿ� �ִٸ� ���� ������ ���� ���·� ��ȯ
	}
	break;
	case RIGHT_MOVE:	//������ �̵� ����
	{
		//========================������ �̵�=====================
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))		//������ Ű ��� ������ �ִٸ� 
		{
			_pos.x += NEKOSPEED;								//���������� ��ǥ �̵�
			_saveLastKey = RIGHT;					//Ű ����
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))		//�Ʒ�Ű�� ������
		{
			this->changeState(RIGHT_SIT_MOVE);					//������ �ɱ� �̵� ����
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))		//���� Ű�� �����ٸ�
		{
			this->changeState(LEFT_MOVE);						//���� ������ ���·� ��ȯ 
		}

		//================���� �����ʿ� �ִٸ�=======================
		if (_isEnemyRight)
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//Ű���� �ն���
			{
				this->changeState(RIGHT_STOP);		//������ ��������
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))	//����Ű ������
			{
				this->changeState(RIGHT_JUMP);				//������ ���� �̵� ���·� ��ȯ 
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))	//����Ű�� ������
			{
				this->changeState(RIGHT_ATTACK);			//�������� ���·� ��ȯ
			}
		}
		//================���� ���ʿ� �ִٸ�=======================
		else if (!_isEnemyRight)
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//Ű���� �ն���
			{
				this->changeState(LEFT_STOP);			//���� �������·� ��ȯ 
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))	//����Ű�� ������
			{
				this->changeState(LEFT_BACK_JUMP);			//���� �� ���� ���·� ��ȯ
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))	//����Ű�� ������
			{
				this->changeState(LEFT_ATTACK);			//�������� ���·� ��ȯ
			}

		}
	}
	break;
	case LEFT_MOVE:
	{
		//===========�������� �̵�========================
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//���� Ű�� ��� ������ �ִٸ�
		{
			_pos.x -= NEKOSPEED;							//�������� ��ǥ �̵�
			_saveLastKey = LEFT;					//Ű ����
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))	//�Ʒ� Ű�� �����ٸ�
		{
			this->changeState(LEFT_SIT_MOVE);				//���� �ɾ� �̵����� ���º�ȭ
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))	//������ Ű�� �����ٸ�
		{
			this->changeState(RIGHT_MOVE);					//������ �̵����� ���� ��ȯ 
		}
		//================���� �����ʿ� �ִٸ�=======================
		if (_isEnemyRight)
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT])) //�����̵� Ű���� �ն��� 
			{
				this->changeState(RIGHT_STOP);				//������ �������·� ��ȯ
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))	//����Ű ������
			{
				this->changeState(RIGHT_BACK_JUMP);				//������ �� ���� ���·� ��ȯ 
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))	//����Ű�� ������
			{
				this->changeState(RIGHT_ATTACK);			//�������� ���·� ��ȯ
			}
		}
		//=================����  ���ʿ� �ִٸ�==============================
		else if (!_isEnemyRight)
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//���� �̵�Ű���� �ն���
			{
				this->changeState(LEFT_STOP);			//���� �������·� ��ȯ 
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))	//����Ű�� �ѹ� ������
			{
				this->changeState(LEFT_JUMP);			//���� ���� �̵� ���·� ��ȯ 
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))	//����Ű�� ������
			{
				this->changeState(LEFT_ATTACK);			//�������� ���·� ��ȯ
			}
		}
	}
	break;
	case RIGHT_SIT:	//�ɱ� ���¿��� 
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))	//�ɱ� Ű���� �ն���
		{
			this->changeState(RIGHT_CHANGE_UP);					//������ �븻���·� ���� ��ȯ
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))	//������ �̵�Ű�� ������
		{
			this->changeState(RIGHT_SIT_MOVE);				//������ �ɱ� �̵����·� ��ȯ
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))	//����Ű�� ������
		{
			this->changeState(LEFT_SIT_MOVE);				//���� �ɱ� �̵����·� ��ȯ 
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))	//���� Ű�� ������
		{
			this->changeState(RIGHT_SIT_ATTACK);			//������ �ɱ� ���ݻ��·� ��ȯ  
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))	//ű Ű�� ������
		{
			this->changeState(RIGHT_SIT_KICK);				//������ �ɾ� �� ���·� ��ȯ 
		}

		if (!_isEnemyRight)this->changeState(LEFT_SIT);		//���� ���ʿ� �ִٸ� ���� �ɱ� ���·� ��ȯ 
	}
	break;
	case LEFT_SIT:			//���� �ɱ� ���� 
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))		//�ɱ� Ű���� �ն���
		{
			this->changeState(LEFT_CHAGNE_UP);			//�Ͼ�� ���·� ��ȯ
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))		//���� Ű�� �ѹ� �����ٸ�
		{
			this->changeState(LEFT_SIT_MOVE);			//���� �ɾ� �̵����·� ��ȯ 
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))		//������ Ű��  �ѹ� �����ٸ� 
		{
			this->changeState(RIGHT_SIT_MOVE);			//������ �ɾ� �̵����·� ��ȯ 
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))		//���� Ű�� �����ٸ�
		{
			this->changeState(LEFT_SIT_ATTACK);			//���� ���� ���·� ��ȯ 
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))	//ű Ű�� ������
		{
			this->changeState(LEFT_SIT_KICK);				//���� �ɾ� �� ���·� ��ȯ 
		}

		if (_isEnemyRight)this->changeState(RIGHT_SIT);		//���� �����ʿ� �ִٸ� ������ �ɱ� ���·� ��ȯ
	}
	break;

	case RIGHT_CHANGE_SIT:
	{

	}
	break;

	case LEFT_CHANGE_SIT:
	{

	}
	break;

	case RIGHT_CHANGE_UP:
	{

	}
	break;

	case LEFT_CHAGNE_UP:
	{

	}
	break;

	case RIGHT_SIT_MOVE:	//������ �ɱ� �̵�����
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))	//������ Ű��� ������ 
		{
			this->_pos.x += NEKOSITSPEED;						//���������� �̵�
			_saveLastKey = RIGHT;					//Ű ����
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))		//������ Ű���� �ն���
		{
			if (_isEnemyRight)		//���� ���� �����ʿ� �ִٸ�
			{
				this->changeState(RIGHT_SIT);					//������ �ɱ� ���·� ��ȯ
			}
			else if (!_isEnemyRight)	//���� ���� ���ʿ� �ִٸ�
			{
				this->changeState(LEFT_SIT);					//���� �ɱ� ���·� ��ȯ 
			}
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))		//Ű���� �ն���
		{
			this->changeState(RIGHT_MOVE);		//������ �̵� ���·� ��ȯ
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))		//���� Ű��  ������
		{
			this->changeState(LEFT_SIT_MOVE);		//���� �ɱ� ���·� ��ȯ  
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))	//����Ű�� ������
		{
			if (_isEnemyRight)									//���� �����ʿ� �ִٸ� 
			{
				this->changeState(RIGHT_SIT_ATTACK);			//������ �ɾ� ���� 
			}
			else												//���� ���ʿ� �ִٸ�
			{
				this->changeState(LEFT_SIT_ATTACK);				//���� �ɾ� ����
			}
		}
		if (_isEnemyRight)										//���� �����ʿ� �ִٸ�
		{
			if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))	//ű Ű�� �����ٸ�
			{
				this->changeState(RIGHT_SIT_KICK);				//������ �ɾ� ű���·� ��ȯ�ض� 
			}
		}
	}
	break;

	case LEFT_SIT_MOVE:	//���� �ɱ� �̵�
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//���� Ű ��� ������ ������
		{
			this->_pos.x -= NEKOSITSPEED;					//�������� ��ǥ �̵�
			_saveLastKey = LEFT;					//Ű ����
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//���� Ű���� ���� ���ٸ� 
		{
			if (_isEnemyRight)						//���� �����ʿ� �ִٸ�
			{
				this->changeState(RIGHT_SIT);	//������ �ɴ� ���·� ��ȯ 
			}
			else if (!_isEnemyRight)				//���� ���ʿ� �ִٸ�
			{
				this->changeState(LEFT_SIT);	//���� �ɴ� ���·� ��ȯ 
			}
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))	//�Ʒ� Ű���� �ն��ٸ�
		{
			this->changeState(LEFT_MOVE);		//���� �̵����·�  ��ȯ
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))	//������ Ű��  �����ٸ�
		{
			this->changeState(RIGHT_MOVE);		//������ �̵����·� ��ȯ  
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))	//����Ű�� ������
		{
			if (_isEnemyRight)									//���� �����ʿ� �ִٸ� 
			{
				this->changeState(RIGHT_SIT_ATTACK);			//������ �ɾ� ���� 
			}
			else												//���� ���ʿ� �ִٸ�
			{
				this->changeState(LEFT_SIT_ATTACK);				//���� �ɾ� ����
			}
		}
		if (!_isEnemyRight)										//���� ���ʿ� �ִٸ�
		{
			if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))	//ű Ű�� �����ٸ�
			{
				this->changeState(LEFT_SIT_KICK);				//���� �ɾ� ű���·� ��ȯ�ض� 
			}
		}

	}
	break;

	case RIGHT_JUMP:	//������ ���ڸ� ���� ����
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))	//������ Ű ��� ������ 
		{
			this->_pos.x += NEKOSPEED;						//���������� ��ǥ �̵�
			_saveLastKey = RIGHT;					//Ű ����
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//���� Ű ��� ������
		{
			this->_pos.x -= NEKOSPEED;						//�������� ��ǥ �̵�
			_saveLastKey = LEFT;					//Ű ����
		}

		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//������ Ű���� �ն��ٸ� 
		{
			_saveLastKey = END;								//Ű ���� ���� 
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//���� Ű���� �ն��ٸ� 
		{
			_saveLastKey = END;								//���� Ű ���� ����  
		}
	}
	break;
	case LEFT_JUMP:		//���� ���ڸ� ���� ����
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))	//������ Ű ��� ������ 
		{
			this->_pos.x += NEKOSPEED;						//���������� ��ǥ �̵�
			_saveLastKey = RIGHT;					//Ű ����
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//���� Ű ��� ������
		{
			this->_pos.x -= NEKOSPEED;						//�������� ��ǥ �̵�
			_saveLastKey = LEFT;					//Ű ����
		}

		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//������ Ű���� �ն��ٸ� 
		{
			_saveLastKey = END;								//Ű ���� ���� 
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//���� Ű���� �ն��ٸ� 
		{
			_saveLastKey = END;								//���� Ű ���� ����  
		}
	}
	break;

	case RIGHT_BACK_JUMP:		//������ �� ���� ����
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))	//������ Ű ��� ������ 
		{
			this->_pos.x += NEKOSPEED;						//���������� ��ǥ �̵�
			_saveLastKey = RIGHT;					//Ű ����
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//���� Ű ��� ������
		{
			this->_pos.x -= NEKOSPEED;						//�������� ��ǥ �̵�
			_saveLastKey = LEFT;					//Ű ����
		}

		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//������ Ű���� �ն��ٸ� 
		{
			_saveLastKey = END;								//Ű ���� ���� 
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//���� Ű���� �ն��ٸ� 
		{
			_saveLastKey = END;								//���� Ű ���� ����  
		}
	}
	break;

	case LEFT_BACK_JUMP:		//���� �� ���� ���� 
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))	//������ Ű ��� ������ 
		{
			this->_pos.x += NEKOSPEED;						//���������� ��ǥ �̵�
			_saveLastKey = RIGHT;					//Ű ����
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//���� Ű ��� ������
		{
			this->_pos.x -= NEKOSPEED;						//�������� ��ǥ �̵�
			_saveLastKey = LEFT;					//Ű ����
		}

		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//������ Ű���� �ն��ٸ� 
		{
			_saveLastKey = END;								//Ű ���� ���� 
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//���� Ű���� �ն��ٸ� 
		{
			_saveLastKey = END;								//���� Ű ���� ����  
		}
	}
	break;

	case RIGHT_ATTACK:
	{

	}
	break;

	case LEFT_ATTACK:
	{

	}
	break;
	case RIGHT_SIT_ATTACK:
	{

	}
	break;
	case LEFT_SIT_ATTACK:
	{

	}
	break;

	case RIGHT_KICK:
	{

	}
	break;

	case LEFT_KICK:
	{

	}
	break;

	case RIGHT_SIT_KICK:
	{

	}
	break;

	case LEFT_SIT_KICK:
	{

	}
	break;

	case RIGHT_DEFENSE:
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
		{
			this->changeState(RIGHT_STOP);
		}
	}
	break;
	case LEFT_DEFENSE:
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))
		{
			this->changeState(LEFT_STOP);
		}
	}
	break;

	case RIGHT_SIT_DEFENSE:
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
		{
			this->changeState(RIGHT_SIT);
		}
	}
	break;
	case LEFT_SIT_DEFENSE:
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))
		{
			this->changeState(LEFT_SIT);
		}
	}
	break;

	case RIGHT_FIRE:
	{

	}
	break;
	case LEFT_FIRE:
	{

	}
	break;

	case RIGHT_STAY_FIRE:
	{
		//���ݷ�Ʈ ���� 
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(1, vector2D(_centerPos.x + 135, _centerPos.y + 10), vector2D(180, 60), _enemy, 0.1f);
		WORLD->addObject(hitbox);

		if (_effect != NULL)
		{
			if (_effect->_frameX >= _effect->_image->getMaxFrameX())
			{
				_effect->setDestroy();
				_effect = NULL;

				this->changeState(RIGHT_STOP);
			}
		}
	}
	break;

	case LEFT_STAY_FIRE:
	{
		//���ݷ�Ʈ ���� 
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(1, vector2D(_centerPos.x - 135, _centerPos.y + 10), vector2D(180, 60), _enemy, 0.1f);
		WORLD->addObject(hitbox);

		if (_effect != NULL)
		{
			if (_effect->_frameX >= _effect->_image->getMaxFrameX())
			{
				_effect->setDestroy();
				_effect = NULL;

				this->changeState(LEFT_STOP);
			}
		}
	}
	break;

	case RIGHT_BEAM:
	{
		//���ݷ�Ʈ ���� 
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(1, vector2D(_centerPos.x + 600, _centerPos.y - 150), vector2D(1200, 200), _enemy, 0.1f);
		WORLD->addObject(hitbox);


		if (_effect != NULL)
		{
			if (_effect->_frameX >= _effect->_image->getMaxFrameX())
			{
				_effect->setDestroy();
				_effect = NULL;

				this->changeState(RIGHT_STOP);
			}
		}
	}
	break;

	case LEFT_BEAM:
	{
		//���ݷ�Ʈ ���� 
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(1, vector2D(_centerPos.x - 600, _centerPos.y - 150), vector2D(1200, 200), _enemy, 0.1f);
		WORLD->addObject(hitbox);

		if (_effect != NULL)
		{
			if (_effect->_frameX >= _effect->_image->getMaxFrameX())
			{
				_effect->setDestroy();
				_effect = NULL;

				this->changeState(LEFT_STOP);
			}
		}

	}
	break;

	case RIGHT_FLY:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			_pos.x += NEKOSPEED;
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))
		{
			this->changeState(RIGHT_FALL);
			_isJump = true;
			_saveLastKey = END;
		}
	}
	break;
	case LEFT_FLY:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			_pos.x -= NEKOSPEED;
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
		{
			this->changeState(LEFT_FALL);
			_isJump = true;
			_saveLastKey = END;
		}
	}
	break;

	case RIGHT_FALL:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			_saveLastKey = RIGHT;
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))
		{
			_saveLastKey = END;
		}
	}
	break;

	case LEFT_FALL:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			_saveLastKey = LEFT;
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))
		{
			_saveLastKey = END;
		}
	}
	break;

	case RIGHT_DASH:
	{
		_pos.x += NEKODASHSPEED;
	}
	break;
	case LEFT_DASH:
	{
		_pos.x -= NEKODASHSPEED;
	}
	break;

	case RIGHT_BACK_DASH:
	{
		_pos.x -= NEKOBACKDASHSPEED;
	}
	break;

	case LEFT_BACK_DASH:
	{
		_pos.x += NEKOBACKDASHSPEED;
	}
	break;

	case LEFT_HIT:
	{

	}
	break;
	case RIGHT_HIT:
	{

	}
	break;

	case RIGHT_DING:
	{
		_pos.x -= 5;
	}
	break;
	case LEFT_DING:
	{
		_pos.x += 5;
	}
	break;

	case RIGHT_DIE:
	{

	}
	break;
	case LEFT_DIE:
	{

	}
	break;


	//end
	}
}

void neko::enemyPos()
{
	if (this->_pos.x > _enemy->_pos.x && _isEnemyRight)			//�� x��ǥ���� ��뺸�� ũ�ٸ� 
	{
		_isEnemyRight = false;						//�����ġ �Ұ� false 
	}
	else if (this->_pos.x < _enemy->_pos.x && !_isEnemyRight)	//��	 x��ǥ���� ��뺸�� �۴ٸ� 
	{
		_isEnemyRight = true;						//�� ��ġ �Ұ� true
	}

}

void neko::jumping()
{
	if (!_isJump) return;								//���� ���¶�� �������� ��������

	_pos.y -= _jumpPower;								//y���� ���� �Ŀ���ŭ ����
	_jumpPower -= _gravity;								//���� �Ŀ����� �߷°���ŭ ��� ����

	if (_savePosY <= _pos.y)							//���� ���̺� �����Ǻ��� �÷��̾��� ��ǥ�� Ŀ������ �ϸ� 
	{													//�װ� ���� �����ߴٴ� �Ŵϱ� 

		_isJump = false;								//���� ���� �Ұ� false��
		_pos.y = _savePosY;								//y��ǥ ���� ������ saveY��ǥ ������ �ʱ�ȭ 

		if (_state == RIGHT_JUMP || _state == LEFT_JUMP ||
			_state == RIGHT_BACK_JUMP || _state == LEFT_BACK_JUMP
			|| _state == RIGHT_FALL || _state == LEFT_FALL)	//���� ���¿��ٸ�
		{
			if (_isEnemyRight)							//���� ��밡 �����ʿ� �ִٸ� 
			{
				if (_saveLastKey == END)this->changeState(RIGHT_STOP);			//�������� ����Ű�� ������ ������ �������·� ��ȯ
				else if (_saveLastKey == RIGHT)this->changeState(RIGHT_MOVE);	//�������� ����Ű�� �������̶�� �������̵����·κ�ȯ
				else if (_saveLastKey == LEFT)this->changeState(LEFT_MOVE);		//�������� ����Ű�� �����̶�� ���� �̵����·� ��ȯ
			}
			else										//���� ��밡 ���ʿ�  �ִٸ� 
			{
				if (_saveLastKey == END)this->changeState(LEFT_STOP);			//�������� ����Ű�� ������ ������ �������·� ��ȯ
				else if (_saveLastKey == RIGHT)this->changeState(RIGHT_MOVE);	//�������� ����Ű�� �������̶�� �������̵����·κ�ȯ
				else if (_saveLastKey == LEFT)this->changeState(LEFT_MOVE);		//�������� ����Ű�� �����̶�� ���� �̵����·� ��ȯ
			}
		}
		else if (_state == RIGHT_DING)
		{
			this->changeState(RIGHT_DIE);
		}
		else if (_state == LEFT_DING)
		{
			this->changeState(LEFT_DIE);
		}
	}
}

void neko::nekoFire()
{
	if (_isEnemyRight)					//���� �����ʿ� ������ 
	{
		this->changeState(RIGHT_FIRE);	//������ �һձ���·�
	}
	else								//���� ���ʿ� ������
	{
		this->changeState(LEFT_FIRE);	//���� �һձ� ���·�
	}
}

void neko::nekoRightFly()
{
	if (_state == RIGHT_JUMP || _state == LEFT_JUMP || _state == RIGHT_FALL || _state == LEFT_FALL
		|| _state == RIGHT_BACK_JUMP || _state == LEFT_BACK_JUMP)
	{
		this->changeState(RIGHT_FLY);
	}
	if (_isEnemyRight)
	{
		if (_state == RIGHT_STOP || _state == RIGHT_MOVE)
		{
			this->changeState(RIGHT_DASH);
		}
	}
	else if (!_isEnemyRight)
	{
		if (_state == LEFT_STOP || _state == RIGHT_MOVE)
		{
			this->changeState(LEFT_BACK_DASH);
		}
	}
}
void neko::nekoLeftFly()
{
	if (_state == RIGHT_JUMP || _state == LEFT_JUMP || _state == RIGHT_FALL || _state == LEFT_FALL
		|| _state == RIGHT_BACK_JUMP || _state == LEFT_BACK_JUMP)
	{
		this->changeState(LEFT_FLY);
	}
	if (_isEnemyRight)
	{
		if (_state == RIGHT_STOP || _state == LEFT_MOVE)
		{
			this->changeState(RIGHT_BACK_DASH);
		}
	}
	else if (!_isEnemyRight)
	{
		if (_state == LEFT_STOP || _state == LEFT_MOVE)
		{
			this->changeState(LEFT_DASH);
		}
	}

}

void neko::nekoBeam()
{
	if (_isEnemyRight)
	{
		this->changeState(RIGHT_BEAM);
	}
	else if (!_isEnemyRight)
	{
		this->changeState(LEFT_BEAM);
	}
}


void neko::hit(tagMessage msg)
{
	tagMessage message = msg;
	if (message.data == DIRECTION::RIGHT)
	{
		this->changeState(RIGHT_HIT);
	}
	else if (message.data == DIRECTION::LEFT)
	{
		this->changeState(LEFT_HIT);
	}
}

void neko::die(tagMessage msg)
{
	tagMessage message = msg;
	if (message.data == DIRECTION::RIGHT)
	{
		this->changeState(RIGHT_DING);
	}
	else if (message.data == DIRECTION::LEFT)
	{
		this->changeState(LEFT_DING);
	}
}

void neko::block()
{
	if (_state == LEFT_MOVE)
	{
		this->changeState(RIGHT_DEFENSE);
		//this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, LEFT_MOVE));
	}
	else if (_state == LEFT_SIT_MOVE)
	{
		this->changeState(RIGHT_SIT_DEFENSE);
		//this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_SIT_MOVE));
	}

	else if (_state == RIGHT_MOVE)
	{
		this->changeState(LEFT_DEFENSE);
		//this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, RIGHT_MOVE));
	}
	else if (_state == RIGHT_SIT_MOVE)
	{
		this->changeState(LEFT_SIT_DEFENSE);
		//this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, RIGHT_SIT_MOVE));
	}
}