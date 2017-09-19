#include "stdafx.h"
#include "neko.h"
#include "attackHitbox.h"



//s
HRESULT neko::init(vector2D pos)
{
	//이미지 로드 
	IMAGEMANAGER->addFrameImage("neko1_left", "resource/soonwoo/neko/neko1_left.bmp", 4352, 1795, 17, 7, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("neko1_right", "resource/soonwoo/neko/neko1_right.bmp", 4352, 1790, 17, 7, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("nekoRightFireEffect", "resource/soonwoo/neko/nekoFire.bmp", 7424, 256, 29, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("nekoLeftFireEffect", "resource/soonwoo/neko/nekoFireLeft.bmp", 7424, 256, 29, 1, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("nekoRightBeamEffect", "resource/soonwoo/neko/nekoRightBeam.bmp", 6400, 200, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("nekoRightBeamEffect", "resource/soonwoo/neko/nekoRightBeam2.bmp", 19200, 600, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("nekoLeftBeamEffect", "resource/soonwoo/neko/nekoLeftBeam.bmp", 19200, 600, 16, 1, true, RGB(255, 0, 255));

	//이펙트 로드
	EFFECTMANAGER->addEffect("blockEffect", "resource/soonwoo/neko/blockEffect.bmp", 448, 64, 64, 64, 13, 10,vector2D(3.0,3.0));
	EFFECTMANAGER->addEffect("blockEffectLeft", "resource/soonwoo/neko/blockEffectLeft.bmp", 448, 64, 64, 64, 13, 10, vector2D(3.0, 3.0));
	EFFECTMANAGER->addEffect("skillEffect", "resource/soonwoo/neko/skillEffect.bmp", 480, 80, 80, 80, 10, 5, vector2D(5.0, 5.0));
	//사운드 로드
	

	//키애니메니져 설정

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

	//====================================쳐맞는거=========================
	int rightHit[]{ 108,109,110 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightHit", "neko1_right", rightHit, 3, 10, false);
	KEYANIMANAGER->setCollisionRect("nekoRightHit", RectMake(118, 179, 24, 42));
	int leftHit[]{ 108,109,110 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftHit", "neko1_left", leftHit, 3, 10, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftHit", RectMake(112, 179, 24, 42));
	//====================================이건 뒤져가는 거=============================
	int rightDing[]{ 111,112,113,114,115 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightDing", "neko1_right", rightDing, 5, 7, false);
	KEYANIMANAGER->setCollisionRect("nekoRightDing", RectMake(122, 200, 26, 22));
	int leftDing[]{ 111,112,113,114,115 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftDing", "neko1_left", leftDing, 5, 7, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftDing", RectMake(107, 203, 26, 22));
	//===================================뒤진거=============================================
	int rightDie[]{ 115 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightDie", "neko1_right", rightDie, 1, 1, false);
	KEYANIMANAGER->setCollisionRect("nekoRightDie", RectMake(122, 200, 26, 22));
	int leftDie[]{ 115 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftDie", "neko1_left", leftDie, 1, 1, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftDie", RectMake(107, 203, 26, 22));
	//===============================neko code 초기화=====================================================
	character::init("네코", pos, "nekoRightStop");

	_state = RIGHT_STOP;		//오른쪽 정지상태로 초기화 
	_isEnemyRight = true;		//상대오른쪽에 있는거 트루로 초기화

								//점프 관련 변수들
	_jumpPower = 0;
	_gravity = 0;
	_savePosY = this->_pos.y;
	_isJump = false;

	_effect = NULL;

	//능력치 초기화 (체력 , 공격력)
	this->setStatus(1000, 10);

	//키 저장 변수
	_saveLastKey = key::END;	//아무키도 안누른 END로 초기화  해준다.

								//=====================콜백 함수 등록=========================
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

	this->setGravity(0);		//유훈이형 중력 안씀

	_centerPos = _pos;
	_centerPos.y = _pos.y + 50;

	//====================커맨드 추가====================================
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
	case RIGHT_STOP:	//오른쪽 정지상태
	{
		this->setAnimation("nekoRightStop");	//오른쪽 정지로 프레임 변경
	}
	break;
	case LEFT_STOP:		//왼쪽 정지상태
	{
		this->setAnimation("nekoLeftStop");		//왼쪽 정지로 프레임 변경
	}
	break;
	case RIGHT_MOVE:	//오른쪽 이동 상태 
	{
		this->setAnimation("nekoRightMove");	//오른쪽 이동으로 프레임 변경
	}
	break;
	case LEFT_MOVE:		//왼쪽 이동 상태
	{
		this->setAnimation("nekoLeftMove");		//왼쪽 이동으로 프레임 변경 
	}
	break;
	case RIGHT_SIT:		//오른쪽 앉기 상태
	{
		this->setAnimation("nekoRightSit");		//오른쪽 앉기로 프레임 변경
	}
	break;
	case LEFT_SIT:	//왼쪽 앉기 상태
	{
		this->setAnimation("nekoLeftSit");
	}
	break;
	case RIGHT_CHANGE_SIT:	//오른쪽 앉을려는 상태
	{
		this->setAnimation("nekoRightChangeSit");		//오른쪽 앉기 모션으로 프레임변경
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));	//앉기 모션 프레임끝나면 앉기로 상태변경
	}
	break;

	case LEFT_CHANGE_SIT:	//왼쪽 앉을려는 상태 
	{
		this->setAnimation("nekoLeftChangeSit");				//왼쪽 앉는 프레임 재생
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_SIT));	//프레임 끝나면 왼쪽 앉기상태로 변환
	}
	break;

	case RIGHT_CHANGE_UP:	//오른쪽 일어서는 상태
	{
		this->setAnimation("nekoRightChangeSitUp");		//오른쪽 일어서는 프레임 재생
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));	//프레임 끝나면 오른쪽 정지상태
	}
	break;

	case LEFT_CHAGNE_UP:	//왼쪽 일어서는 상태
	{
		this->setAnimation("nekoLeftChangeSitUp");		//왼쪽 일어서는 프레임 재생 
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));	//프레임 끝나면 왼쪽 정지 상태
	}
	break;

	case RIGHT_SIT_MOVE:	//오른쪽 앉기 이동
	{
		this->setAnimation("nekoRightSitMove");		//오른쪽 앉기 이동으로 프레임 변환 
	}
	break;

	case LEFT_SIT_MOVE:		//왼쪽 앉기 이동
	{
		this->setAnimation("nekoLeftSitMove");		//왼쪽 앉기 이동으로 프레임 변환 
	}
	break;

	case RIGHT_JUMP:							//오른쪽 정프 상태 
	{
		this->setJump();						//점프!
		this->setAnimation("nekoRightJump");	//오른쪽 점프 프레임으로 변환 
	}
	break;
	case LEFT_JUMP:								//왼쪽 점프 상태
	{
		this->setJump();						//점프!
		this->setAnimation("nekoLeftJump");		//왼쪽 점프 프레임으로 변환 
	}
	break;

	case RIGHT_BACK_JUMP:						//오른쪽 백 점프 
	{
		this->setJump();						//점프!
		this->setAnimation("nekoRightBackJump");//오른쪽 백 점프 프레임으로 변환  
	}
	break;

	case LEFT_BACK_JUMP:						//왼쪽 백 점프
	{
		this->setJump();						//점프!
		this->setAnimation("nekoLeftBackJump");	//왼쪽 백 점프 프레임으로 변환
	}
	break;

	case RIGHT_ATTACK:							//오른쪽 약공
	{
		this->setAnimation("nekoRightAttack");	//오른쪽 약공 프레임으로 변환 
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));	//프레임 끝나면 오른쪽 정지로 변환 
																							//공격렉트 생성
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x + 70, _centerPos.y - 5), vector2D(50, 75), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
	break;

	case LEFT_ATTACK:							//왼쪽 약공
	{
		this->setAnimation("nekoLeftAttack");	//왼쪽 약공프레임으로 변환
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));	//프레임 끝나면 왼쪽 정지상태로 변환
																							//공격렉트 생성
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x - 70, _centerPos.y - 5), vector2D(50, 75), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
	break;

	case RIGHT_SIT_ATTACK:						//오른쪽 앉아 약공
	{
		this->setAnimation("nekoRightSitAttack");	//오른쪽 앉아 약공으로 프레임 변환
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));	//프레임 끝나면  오른쪽 앉아 상태로변환
																							//공격랙트 생성
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x + 80, _centerPos.y + 50), vector2D(50, 60), _enemy, 0.1f);
		WORLD->addObject(hitbox);

		
	}
	break;
	case LEFT_SIT_ATTACK:						//왼쪽 앉아 약공
	{
		this->setAnimation("nekoLeftSitAttack");	//왼쪽 앉아약공으로 프레임 변환  
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_SIT));	//프레임 끝나면 왼쪽 앉아 상태로 변환
																							//공격랙트 생성
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x - 80, _centerPos.y + 50), vector2D(50, 60), _enemy, 0.1f);
		WORLD->addObject(hitbox);

		
	}
	break;

	case RIGHT_KICK:					//오른쪽 킥
	{
		this->setAnimation("nekoRightKick");				//오른쪽 킥 프레임으로 변환 
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		//공격랙트 생성 
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x + 60, _centerPos.y + 30), vector2D(50, 60), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
	break;

	case LEFT_KICK:				//왼쪽 킥
	{
		this->setAnimation("nekoLeftKick");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));
		//공격랙트 생성 
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x - 60, _centerPos.y + 30), vector2D(50, 60), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
	break;

	case RIGHT_SIT_KICK:			//오른쪽 앉아 발  
	{
		this->setAnimation("nekoRightSitKick");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));
		//공격랙트 생성 
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x + 90, _centerPos.y + 30), vector2D(100, 120), _enemy, 0.25f);
		WORLD->addObject(hitbox);
	}
	break;

	case LEFT_SIT_KICK:			//왼쪽 앉아 발 
	{
		this->setAnimation("nekoLeftSitKick");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_SIT));
		//공격랙트 생성 
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_centerPos.x - 90, _centerPos.y + 30), vector2D(100, 120), _enemy, 0.25f);
		WORLD->addObject(hitbox);
	}
	break;

	case RIGHT_DEFENSE:						//오른쪽 막기 
	{
		this->setAnimation("nekoRightDefense");	//오른쪽 막기 프레임으로 변환 

		EFFECTMANAGER->play("blockEffect", _pos.x + 10, _pos.y);
	}
	break;
	case LEFT_DEFENSE:							//왼쪽 막기
	{
		this->setAnimation("nekoLeftDefense");	//왼쪽 막기 프레임으로 변환 

		EFFECTMANAGER->play("blockEffect", _pos.x + 20, _pos.y);
	}
	break;

	case RIGHT_SIT_DEFENSE:					//오른쪽 앉아 막기
	{
		this->setAnimation("nekoRightSitDefense");	//오른쪽 앉아 막기 프레임으로 변환 

	
	}
	break;
	case LEFT_SIT_DEFENSE:						//왼쪽 앉아 막기
	{
		this->setAnimation("nekoLeftSitDefense");	//왼쪽 앉아 막기 프레임으로 변환 
	}
	break;

	case RIGHT_FIRE:							//오른쪽 불뿜기
	{
		this->setAnimation("nekoRightFire");	//오른쪽 불뿜기 프레임으로 변경
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, RIGHT_STAY_FIRE));
	}
	break;
	case LEFT_FIRE:								//왼쪽 불뿜기 
	{
		this->setAnimation("nekoLeftFire");	//왼쪽 불뿜기 프레임으로 변경
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, LEFT_STAY_FIRE));
	}
	break;

	case RIGHT_STAY_FIRE:						//오른쪽 불지속뿜기
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
		this->setJump();						//점프!
		_jumpPower = 13.0;
		this->setAnimation("nekoRightDing");
	}
	break;
	case LEFT_DING:
	{
		this->setJump();						//점프!
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
	case tagNekoState::RIGHT_STOP:	//오른쪽 기본상태일 때
	{
		//===================오른쪽 이동으로 상태 변경=================
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			this->changeState(RIGHT_MOVE);	//오른쪽 이동으로 상태 변경
		}

		//========================왼쪽으로 상태변경===================
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			this->changeState(LEFT_MOVE);	//왼쪽 이동으로 상태 변경
		}
		//====================오른쪽 앉기 모션으로 상태 변경============
		if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			this->changeState(RIGHT_CHANGE_SIT);	//오른쪽 앉는 모션으로 상태 변경
		}
		//=====================점프 상태로 변환=====================
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))			//점프키를 한번 눌렀다면
		{
			this->changeState(RIGHT_JUMP);			//오른쪽 점프 상태로 변환 
			_saveLastKey = END;
		}
		//======================공격 상태로 변환====================
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))			//약한 공격키를 눌렀다면
		{
			this->changeState(RIGHT_ATTACK);						//약공상태로 변환
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::KICK]))			//킥을 눌렀다면
		{
			this->changeState(RIGHT_KICK);							//오른쪽 킥 상태로 변환 
		}


		if (!_isEnemyRight)this->changeState(LEFT_STOP);		//적이 왼쪽에 있다면 상태 왼쪽 정지상태로 변환
	}
	break;
	case LEFT_STOP:			//왼쪽 정지상태일 때 
	{
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))		//왼쪽 키를 한번 누르면
		{
			this->changeState(LEFT_MOVE);			//왼쪽 이동 상태로 변환
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))		//오른쪽 키를 한번 누르면
		{
			this->changeState(RIGHT_MOVE);			//오른쪽 이동 상태로  변환 
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))		//아래키를 한번 누르면
		{
			this->changeState(LEFT_CHANGE_SIT);		//왼쪽 앉는 모션 상태로 변환 
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))		//점프키를 한번 누르면
		{
			this->changeState(LEFT_JUMP);			//왼쪽 점프 상태로 변환 
			_saveLastKey = END;
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))		//약공키를 눌렀다면
		{
			this->changeState(LEFT_ATTACK);						//왼쪽 약공 상태로 변환 
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::KICK]))			//킥을 눌렀다면
		{
			this->changeState(LEFT_KICK);							//오른쪽 킥 상태로 변환 
		}


		if (_isEnemyRight)this->changeState(RIGHT_STOP);		//적이 오른쪽에 있다면 상태 오른쪽 정지 상태로 변환
	}
	break;
	case RIGHT_MOVE:	//오른쪽 이동 상태
	{
		//========================오른쪽 이동=====================
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))		//오른쪽 키 길게 누르고 있다면 
		{
			_pos.x += NEKOSPEED;								//오른쪽으로 좌표 이동
			_saveLastKey = RIGHT;					//키 저장
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))		//아래키를 누르면
		{
			this->changeState(RIGHT_SIT_MOVE);					//오른쪽 앉기 이동 상태
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))		//왼쪽 키를 눌렀다면
		{
			this->changeState(LEFT_MOVE);						//왼쪽 움직임 상태로 변환 
		}

		//================적이 오른쪽에 있다면=======================
		if (_isEnemyRight)
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//키에서 손때면
			{
				this->changeState(RIGHT_STOP);		//오른쪽 정지상태
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))	//점프키 누르면
			{
				this->changeState(RIGHT_JUMP);				//오른쪽 점프 이동 상태로 변환 
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))	//어택키를 누르면
			{
				this->changeState(RIGHT_ATTACK);			//오른공격 상태로 변환
			}
		}
		//================적이 왼쪽에 있다면=======================
		else if (!_isEnemyRight)
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//키에서 손때면
			{
				this->changeState(LEFT_STOP);			//왼쪽 정지상태로 변환 
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))	//점프키를 누르면
			{
				this->changeState(LEFT_BACK_JUMP);			//왼쪽 백 점프 상태로 변환
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))	//어택키를 누르면
			{
				this->changeState(LEFT_ATTACK);			//오른공격 상태로 변환
			}

		}
	}
	break;
	case LEFT_MOVE:
	{
		//===========왼쪽으로 이동========================
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//왼쪽 키를 길게 누르고 있다면
		{
			_pos.x -= NEKOSPEED;							//왼쪽으로 좌표 이동
			_saveLastKey = LEFT;					//키 저장
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))	//아래 키를 눌렀다면
		{
			this->changeState(LEFT_SIT_MOVE);				//왼쪽 앉아 이동으로 상태변화
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))	//오른쪽 키를 눌렀다면
		{
			this->changeState(RIGHT_MOVE);					//오른쪽 이동으로 상태 변환 
		}
		//================적이 오른쪽에 있다면=======================
		if (_isEnemyRight)
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT])) //왼쪽이동 키에서 손때면 
			{
				this->changeState(RIGHT_STOP);				//오른쪽 정지상태로 변환
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))	//점프키 누르면
			{
				this->changeState(RIGHT_BACK_JUMP);				//오른쪽 백 점프 상태로 변환 
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))	//어택키를 누르면
			{
				this->changeState(RIGHT_ATTACK);			//오른공격 상태로 변환
			}
		}
		//=================적이  왼쪽에 있다면==============================
		else if (!_isEnemyRight)
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//왼쪽 이동키에서 손때면
			{
				this->changeState(LEFT_STOP);			//왼쪽 정지상태로 변환 
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))	//점프키를 한번 누르면
			{
				this->changeState(LEFT_JUMP);			//왼쪽 점프 이동 상태로 변환 
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))	//어택키를 누르면
			{
				this->changeState(LEFT_ATTACK);			//오른공격 상태로 변환
			}
		}
	}
	break;
	case RIGHT_SIT:	//앉기 상태에서 
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))	//앉기 키에서 손때면
		{
			this->changeState(RIGHT_CHANGE_UP);					//오른쪽 노말상태로 상태 변환
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))	//오른쪽 이동키를 누르면
		{
			this->changeState(RIGHT_SIT_MOVE);				//오른쪽 앉기 이동상태로 변환
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))	//왼쪽키를 누르면
		{
			this->changeState(LEFT_SIT_MOVE);				//왼쪽 앉기 이동상태로 변환 
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))	//공격 키를 누르면
		{
			this->changeState(RIGHT_SIT_ATTACK);			//오른쪽 앉기 공격상태로 변환  
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))	//킥 키를 누르면
		{
			this->changeState(RIGHT_SIT_KICK);				//오른쪽 앉아 발 상태로 변환 
		}

		if (!_isEnemyRight)this->changeState(LEFT_SIT);		//적이 왼쪽에 있다면 왼쪽 앉기 상태로 변환 
	}
	break;
	case LEFT_SIT:			//왼쪽 앉기 상태 
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))		//앉기 키에서 손때면
		{
			this->changeState(LEFT_CHAGNE_UP);			//일어서는 상태로 변환
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))		//왼쪽 키를 한번 눌렀다면
		{
			this->changeState(LEFT_SIT_MOVE);			//왼쪽 앉아 이동상태로 변환 
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))		//오른쪽 키를  한번 눌렀다면 
		{
			this->changeState(RIGHT_SIT_MOVE);			//오른쪽 앉아 이동상태로 변환 
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))		//어택 키를 눌렀다면
		{
			this->changeState(LEFT_SIT_ATTACK);			//왼쪽 공격 상태로 변환 
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))	//킥 키를 누르면
		{
			this->changeState(LEFT_SIT_KICK);				//왼쪽 앉아 발 상태로 변환 
		}

		if (_isEnemyRight)this->changeState(RIGHT_SIT);		//적이 오른쪽에 있다면 오른쪽 앉기 상태로 변환
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

	case RIGHT_SIT_MOVE:	//오른쪽 앉기 이동상태
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))	//오른쪽 키길게 누르면 
		{
			this->_pos.x += NEKOSITSPEED;						//오른쪽으로 이동
			_saveLastKey = RIGHT;					//키 저장
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))		//오른쪽 키에서 손때면
		{
			if (_isEnemyRight)		//만약 적이 오른쪽에 있다면
			{
				this->changeState(RIGHT_SIT);					//오른쪽 앉기 상태로 변환
			}
			else if (!_isEnemyRight)	//만약 적이 왼쪽에 있다면
			{
				this->changeState(LEFT_SIT);					//왼쪽 앉기 상태로 변환 
			}
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))		//키에서 손때면
		{
			this->changeState(RIGHT_MOVE);		//오른쪽 이동 상태로 변환
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))		//왼쪽 키를  누르면
		{
			this->changeState(LEFT_SIT_MOVE);		//왼쪽 앉기 상태로 변환  
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))	//공격키를 눌르면
		{
			if (_isEnemyRight)									//적이 오른쪽에 있다면 
			{
				this->changeState(RIGHT_SIT_ATTACK);			//오른쪽 앉아 공격 
			}
			else												//적이 왼쪽에 있다면
			{
				this->changeState(LEFT_SIT_ATTACK);				//왼쪽 앉아 공격
			}
		}
		if (_isEnemyRight)										//적이 오른쪽에 있다면
		{
			if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))	//킥 키를 눌렀다면
			{
				this->changeState(RIGHT_SIT_KICK);				//오른쪽 앉아 킥상태로 변환해라 
			}
		}
	}
	break;

	case LEFT_SIT_MOVE:	//왼쪽 앉기 이동
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//왼쪽 키 길게 누르고 있으면
		{
			this->_pos.x -= NEKOSITSPEED;					//왼쪽으로 좌표 이동
			_saveLastKey = LEFT;					//키 저장
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//왼쪽 키에서 손을 땐다면 
		{
			if (_isEnemyRight)						//적이 오른쪽에 있다면
			{
				this->changeState(RIGHT_SIT);	//오른쪽 앉는 상태로 변환 
			}
			else if (!_isEnemyRight)				//적이 왼쪽에 있다면
			{
				this->changeState(LEFT_SIT);	//왼쪽 앉는 상태로 변환 
			}
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))	//아래 키에서 손땐다면
		{
			this->changeState(LEFT_MOVE);		//왼쪽 이동상태로  변환
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))	//오른쪽 키를  누른다면
		{
			this->changeState(RIGHT_MOVE);		//오른쪽 이동상태로 변환  
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))	//공격키를 눌르면
		{
			if (_isEnemyRight)									//적이 오른쪽에 있다면 
			{
				this->changeState(RIGHT_SIT_ATTACK);			//오른쪽 앉아 공격 
			}
			else												//적이 왼쪽에 있다면
			{
				this->changeState(LEFT_SIT_ATTACK);				//왼쪽 앉아 공격
			}
		}
		if (!_isEnemyRight)										//적이 왼쪽에 있다면
		{
			if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))	//킥 키를 눌렀다면
			{
				this->changeState(LEFT_SIT_KICK);				//왼쪽 앉아 킥상태로 변환해라 
			}
		}

	}
	break;

	case RIGHT_JUMP:	//오른쪽 제자리 점프 상태
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))	//오른쪽 키 길게 누르면 
		{
			this->_pos.x += NEKOSPEED;						//오른쪽으로 좌표 이동
			_saveLastKey = RIGHT;					//키 저장
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//왼쪽 키 길게 누르면
		{
			this->_pos.x -= NEKOSPEED;						//왼쪽으로 좌표 이동
			_saveLastKey = LEFT;					//키 저장
		}

		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//오른쪽 키에서 손땠다면 
		{
			_saveLastKey = END;								//키 저장 해제 
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//왼쪽 키에서 손땠다면 
		{
			_saveLastKey = END;								//왼쪽 키 저장 해제  
		}
	}
	break;
	case LEFT_JUMP:		//왼쪽 제자리 점프 상태
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))	//오른쪽 키 길게 누르면 
		{
			this->_pos.x += NEKOSPEED;						//오른쪽으로 좌표 이동
			_saveLastKey = RIGHT;					//키 저장
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//왼쪽 키 길게 누르면
		{
			this->_pos.x -= NEKOSPEED;						//왼쪽으로 좌표 이동
			_saveLastKey = LEFT;					//키 저장
		}

		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//오른쪽 키에서 손땠다면 
		{
			_saveLastKey = END;								//키 저장 해제 
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//왼쪽 키에서 손땠다면 
		{
			_saveLastKey = END;								//왼쪽 키 저장 해제  
		}
	}
	break;

	case RIGHT_BACK_JUMP:		//오른쪽 백 점프 상태
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))	//오른쪽 키 길게 누르면 
		{
			this->_pos.x += NEKOSPEED;						//오른쪽으로 좌표 이동
			_saveLastKey = RIGHT;					//키 저장
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//왼쪽 키 길게 누르면
		{
			this->_pos.x -= NEKOSPEED;						//왼쪽으로 좌표 이동
			_saveLastKey = LEFT;					//키 저장
		}

		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//오른쪽 키에서 손땠다면 
		{
			_saveLastKey = END;								//키 저장 해제 
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//왼쪽 키에서 손땠다면 
		{
			_saveLastKey = END;								//왼쪽 키 저장 해제  
		}
	}
	break;

	case LEFT_BACK_JUMP:		//왼쪽 백 점프 상태 
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))	//오른쪽 키 길게 누르면 
		{
			this->_pos.x += NEKOSPEED;						//오른쪽으로 좌표 이동
			_saveLastKey = RIGHT;					//키 저장
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//왼쪽 키 길게 누르면
		{
			this->_pos.x -= NEKOSPEED;						//왼쪽으로 좌표 이동
			_saveLastKey = LEFT;					//키 저장
		}

		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//오른쪽 키에서 손땠다면 
		{
			_saveLastKey = END;								//키 저장 해제 
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//왼쪽 키에서 손땠다면 
		{
			_saveLastKey = END;								//왼쪽 키 저장 해제  
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
		//공격랙트 생성 
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
		//공격랙트 생성 
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
		//공격랙트 생성 
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
		//공격랙트 생성 
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
	if (this->_pos.x > _enemy->_pos.x && _isEnemyRight)			//내 x좌표값이 상대보다 크다면 
	{
		_isEnemyRight = false;						//상대위치 불값 false 
	}
	else if (this->_pos.x < _enemy->_pos.x && !_isEnemyRight)	//내	 x좌표값이 상대보다 작다면 
	{
		_isEnemyRight = true;						//내 위치 불값 true
	}

}

void neko::jumping()
{
	if (!_isJump) return;								//점프 상태라면 리턴으로 빠져나감

	_pos.y -= _jumpPower;								//y값이 점프 파워만큼 감소
	_jumpPower -= _gravity;								//점프 파워에서 중력값만큼 계속 감소

	if (_savePosY <= _pos.y)							//만약 세이브 포지션보다 플레이어의 좌표가 커질려고 하면 
	{													//그건 땅에 착지했다는 거니까 

		_isJump = false;								//점프 상태 불값 false로
		_pos.y = _savePosY;								//y좌표 값은 점프전 saveY좌표 값으로 초기화 

		if (_state == RIGHT_JUMP || _state == LEFT_JUMP ||
			_state == RIGHT_BACK_JUMP || _state == LEFT_BACK_JUMP
			|| _state == RIGHT_FALL || _state == LEFT_FALL)	//점프 상태였다면
		{
			if (_isEnemyRight)							//만약 상대가 오른쪽에 있다면 
			{
				if (_saveLastKey == END)this->changeState(RIGHT_STOP);			//마지막에 누른키가 없으면 오른쪽 정지상태로 변환
				else if (_saveLastKey == RIGHT)this->changeState(RIGHT_MOVE);	//마지막에 누른키가 오른쪽이라면 오른쪽이동상태로변환
				else if (_saveLastKey == LEFT)this->changeState(LEFT_MOVE);		//마지막에 누른키가 왼쪽이라면 왼쪽 이동상태로 변환
			}
			else										//만약 상대가 왼쪽에  있다면 
			{
				if (_saveLastKey == END)this->changeState(LEFT_STOP);			//마지막에 누른키가 없으면 오른쪽 정지상태로 변환
				else if (_saveLastKey == RIGHT)this->changeState(RIGHT_MOVE);	//마지막에 누른키가 오른쪽이라면 오른쪽이동상태로변환
				else if (_saveLastKey == LEFT)this->changeState(LEFT_MOVE);		//마지막에 누른키가 왼쪽이라면 왼쪽 이동상태로 변환
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
	if (_isEnemyRight)					//적이 오른쪽에 있으면 
	{
		this->changeState(RIGHT_FIRE);	//오른쪽 불뿜기상태로
	}
	else								//적이 왼쪽에 있으면
	{
		this->changeState(LEFT_FIRE);	//왼쪽 불뿜기 상태로
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