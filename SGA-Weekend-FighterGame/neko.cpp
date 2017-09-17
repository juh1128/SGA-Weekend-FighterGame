#include "stdafx.h"
#include "neko.h"


//s
HRESULT neko::init(vector2D pos)
{
	//이미지 로드 
	IMAGEMANAGER->addFrameImage("neko1_left", "resource/soonwoo/neko/neko1_left.bmp", 4352, 1790, 17, 7, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("neko1_right", "resource/soonwoo/neko/neko1_right.bmp", 4352, 1790, 17, 7, true, RGB(255, 0, 255));
	//키애니메니져 설정

	//======================STOP======================
	int rightStop[]{ 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightStop", "neko1_right", rightStop, 5, 6, true);
	KEYANIMANAGER->setCollisionRect("nekoRightStop", RectMake(118, 179, 24, 42));

	int leftStop[]{ 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftStop", "neko1_left", leftStop, 5, 6, true);
	KEYANIMANAGER->setCollisionRect("nekoLeftStop", RectMake(122, 179, 24, 42));
	//====================MOVE==========================
	int rightMove[]{ 5,6,7,8,9,10,11,12 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightMove", "neko1_right", rightMove, 8, 7, true);
	KEYANIMANAGER->setCollisionRect("nekoRightMove", RectMake(118, 179, 24, 42));
	int leftMove[]{ 5,6,7,8,9,10,11,12 };

	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftMove", "neko1_left", leftMove, 8, 7, true);
	KEYANIMANAGER->setCollisionRect("nekoLeftMove", RectMake(118, 179, 24, 42));
	//=====================ChangeSIT===========================

	//DOWN
	int rightChangeSit[]{ 13,14,15,16 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightChangeSit", "neko1_right", rightChangeSit, 4, 20, false);
	KEYANIMANAGER->setCollisionRect("nekoRightChangeSit", RectMake(118, 179, 24, 42));
	int leftChangeSit[]{ 13,14,15,16 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftChangeSit", "neko1_left", leftChangeSit, 4, 20, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftChangeSit", RectMake(118, 179, 24, 42));
	//UP
	int rightChangeSitUp[]{ 16,15,14,13 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightChangeSitUp", "neko1_right", rightChangeSitUp, 4, 20, false);
	KEYANIMANAGER->setCollisionRect("nekoRightChangeSitUp", RectMake(118, 179, 24, 42));
	int leftChangeSitUp[]{ 16,15,14,13 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftChangeSitUp", "neko1_left", leftChangeSitUp, 4, 20, false);
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
	int	rightJump[]{ 17,18,19,20,21,22,23,24,25,26,27,28,29 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightJump", "neko1_right", rightJump, 13, 8, false);
	KEYANIMANAGER->setCollisionRect("nekoRightJump", RectMake(118, 179, 24, 42));
	int leftJump[]{ 17,18,19,20,21,22,23,24,25,26,27,28,29 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftJump", "neko1_left", leftJump, 13, 8, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftJump", RectMake(118, 179, 24, 42));





	character::init("네코", pos, "nekoRightStop");

	_state = RIGHT_STOP;
	_isEnemyRight = true;
	
	//_pivot = Pivot::BOTTOM;

	//점프 관련 변수들
	_jumpPower = 0;
	_gravity = 0;
	_savePosY = this->_pos.y;
	_isJump = false;

	//키 저장 변수
	_saveLastKey = key::END;	//아무키도 안누른 END로 초기화  해준다.

	//콜백 함수 등록
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((tagNekoState::ENUM)msg.data);
	});

	this->setScale(3.0, 3.0);

	this->setGravity(0);

	
	return S_OK;
}

void neko::release()
{
	character::release();
}

void neko::update()
{
	character::update();

	this->jumping();

	this->stateUpdate(_state);

	this->enemyPos();
}

void neko::render()
{
	character::render();

	char str[100];
	sprintf(str, "%d ,%d" ,(int)_pos.x, (int)_pos.y);
	TextOut(getMemDC(), 0, 20, str, strlen(str));
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
	case RIGHT_CHANGE_SIT :	//오른쪽 앉을려는 상태
	{
		this->setAnimation("nekoRightChangeSit");		//오른쪽 앉기 모션으로 프레임변경
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));	//앉기 모션 프레임끝나면 앉기로 상태변경
	}
	break;

	case LEFT_CHANGE_SIT :	//왼쪽 앉을려는 상태 
	{
		this->setAnimation("nekoLeftChangeSit");				//왼쪽 앉는 프레임 재생
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_SIT));	//프레임 끝나면 왼쪽 앉기상태로 변환
	}
		break;

	case RIGHT_CHANGE_UP :	//오른쪽 일어서는 상태
	{
		this->setAnimation("nekoRightChangeSitUp");		//오른쪽 일어서는 프레임 재생
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));	//프레임 끝나면 오른쪽 정지상태
	}
	break;

	case LEFT_CHAGNE_UP :	//왼쪽 일어서는 상태
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
				this->changeState(LEFT_JUMP);			//왼쪽 점프 이동 상태로 변환
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
		//================적이 오른쪽에 있다면=======================
		if (_isEnemyRight)
		{
			if(KEYMANAGER->isOnceKeyUp(keyList[key::LEFT])) //왼쪽이동 키에서 손때면 
			{
				this->changeState(RIGHT_STOP);				//오른쪽 정지상태로 변환
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))	//점프키 누르면
			{
				this->changeState(RIGHT_JUMP);				//점프 이동 상태로 변환 
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

	case RIGHT_SIT_MOVE :	//오른쪽 앉기 이동상태
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
	}
	break;
	
	case LEFT_SIT_MOVE :	//왼쪽 앉기 이동
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

		if (_state == RIGHT_JUMP || _state == LEFT_JUMP)	//점프 상태였다면
		{
			if (_isEnemyRight)							//만약 상대가 오른쪽에 있다면 
			{
				if(_saveLastKey == END)this->changeState(RIGHT_STOP);			//마지막에 누른키가 없으면 오른쪽 정지상태로 변환
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
	}
}

