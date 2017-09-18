#include "stdafx.h"
#include "mai.h"
#include "playGround.h"


//=====================================
//버그노트// changeState 실행과 동시에 깨짐
//=====================================
HRESULT mai::init(vector2D pos)
{
	//이미지와 애니메이션 셋업
	_playGround->setupSunghoon();
	setStatus(100, 10);

	if (pos.x == 200) //적보다 왼쪽에있음(오른쪽을바라봄)
	{
		character::init("mai", pos, "maiRightIdle");
		_posEnum = RIGHT_SEE;
		_state = RIGHT_STOP;
	}
	else//적보다 오른쪽에있음(왼쪽을 바라봄)
	{
		character::init("mai", pos, "maiLeftIdle");
		_posEnum = LEFT_SEE;
		_state = LEFT_STOP;
	}

	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((MAI::state)msg.data);
	});

	//마지막에 누른 키저장
	_lastKey = END;

	_lastKeyTime = LASTKEY_TIME;
	_gravity = 0;

	return S_OK;
}

void mai::release()	
{
	character::release();
}
void mai::update()	
{
	character::update();


	//항상 상대편을 바라보도록 해라
	if (_pos.x < _enemy->_pos.x)
	{
		_posEnum = RIGHT_SEE;
	}
	else
	{
		_posEnum = LEFT_SEE;
	}

	//대쉬키를 사용할때 쓸 라스트키 변수를 일정 시간이 지날때마다 초기화
	_lastKeyTime -= TIMEMANAGER->getElapsedTime();
	if (_lastKeyTime <= 0)
	{
		_lastKeyTime = LASTKEY_TIME;
		_lastKey = END;
	}

	//내 체력이 0이라면 패배
	if (_nowHp <= 0)
	{
		if (_posEnum == RIGHT_SEE)
		{
			setAnimation("maiRightDead");
			_state = RIGHT_DEAD;
		}
		else
		{
			setAnimation("maiLeftDead");
			_state = LEFT_DEAD;
		}
	}
	//상대가 죽었다면 승리
	if (!_enemy->isLive())
	{
		if (_posEnum == RIGHT_SEE)
		{
			setAnimation("maiRightWin");
			_state = RIGHT_WIN;
		}
		else
		{
			setAnimation("maiLeftWin");
			_state = LEFT_WIN;
		}
	}

	stateUpdate(_state);
	changeState(_state);

}
void mai::render()	
{
	character::render();
	TCHAR str[128];
	sprintf(str, TEXT("status:%d"), _state);
	TextOut(getMemDC(), 0, 100, str, strlen(str));

}

//캐릭터의 상태에따른 행동들
void mai::stateUpdate(state) 
{

	switch (_state)
	{
	case MAI::LEFT_STOP:
	{
		
	}
		break;
	case MAI::RIGHT_STOP:
	{
		
	}
		break;
	case MAI::LEFT_MOVE:
	{
		if (_pos.x > 0)
		{
			_pos.x -= MOVESPEED;
		}
	}
		break;
	case MAI::RIGHT_MOVE:
	{
		if (_pos.x < WINSIZEX)
		{
			_pos.x += MOVESPEED;
		}
	}
		break;
	case MAI::LEFT_JUMP:
	{
		if (_pos.y >= GROUND_LINE)
		{
			_pos.y = GROUND_LINE;
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
		_gravity += GRAVITYACCEL;
		_pos.y -= JUMPPOWER - _gravity;
	}
		break;
	case MAI::RIGHT_JUMP:
	{
		if (_pos.y >= GROUND_LINE)
		{
			_pos.y = GROUND_LINE;
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
		_gravity += GRAVITYACCEL;
		_pos.y -= JUMPPOWER - _gravity;
	}
		break;
	case MAI::LEFT_BACK_MOVE:
		if (_pos.x <= WINSIZEX)
		{
			_pos.x += MOVESPEED / 2;
		}
		break;
	case MAI::RIGHT_BACK_MOVE:
		if (_pos.x >= 0)
		{
			_pos.x -= MOVESPEED / 2;
		}
		break;
	case MAI::LEFT_SIT:
		break;
	case MAI::RIGHT_SIT:
		break;
	case MAI::LEFT_PUNCH:
		if (!_animation->isPlay()) //애니메이션이 끝까지 도달하여 플레이가 끝났을때
		{
			setAnimation("maiLeftIdle");//정지상태로 애니메이션을 주고
			_state = LEFT_STOP;			//상태값을 부여
		}
		break;
	case MAI::RIGHT_PUNCH:
		if (!_animation->isPlay())
		{
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
		break;
	case MAI::LEFT_STRONG_PUNCH:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
	}
		break;
	case MAI::RIGHT_STRONG_PUNCH:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
	}
		break;
	case MAI::LEFT_KICK:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
	}
		break;
	case MAI::RIGHT_KICK:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
	}
		break;
	case MAI::LEFT_STRONG_KICK:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
	}
		break;
	case MAI::RIGHT_STRONG_KICK:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
	}
		break;
	case MAI::LEFT_SIT_PUNCH:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiLeftSit");
			_state = LEFT_SIT;
		}
	}
		break;
	case MAI::RIGHT_SIT_PUNCH:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiRightSit");
			_state = RIGHT_SIT;
		}
	}
		break;
	case MAI::LEFT_SIT_KICK:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiLeftSit");
			_state = LEFT_SIT;
		}
	}
		break;
	case MAI::RIGHT_SIT_KICK:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiRightSit");
			_state = RIGHT_SIT;
		}
	}
		break;
	case MAI::LEFT_SIT_STRONG_PUNCH:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiLeftSit");
			_state = LEFT_SIT;
		}
	}
		break;
	case MAI::RIGHT_SIT_STRONG_PUNCH:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiRightSit");
			_state = RIGHT_SIT;
		}
	}
		break;
	case MAI::LEFT_SIT_STRONG_KICK:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiLeftSit");
			_state = LEFT_SIT;
		}
	}
		break;
	case MAI::RIGHT_SIT_STRONG_KICK:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiRightSit");
			_state = RIGHT_SIT;
		}
	}
		break;
	case MAI::LEFT_DEFENCE:
		break;
	case MAI::RIGHT_DEFENCE:
		break;
	case MAI::LEFT_SIT_DEFENCE:
		break;
	case MAI::RIGHT_SIT_DEFENCE:
		break;
	case MAI::LEFT_DASH:
	{
		if (_pos.x >= 0)
		{
			_pos.x -= MOVESPEED * 2;
		}
	}
		break;
	case MAI::RIGHT_DASH:
	{
		if (_pos.x <= WINSIZEX)
		{
			_pos.x += MOVESPEED * 2;
		}
	}
		break;
	case MAI::LEFT_BACK_DASH:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
		else 
		{
			if (_pos.x <= WINSIZEX)
			{
				_pos.x += MOVESPEED;
			}
		}
	}
		break;
	case MAI::RIGHT_BACK_DASH:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
		else
		{
			if (_pos.x >= 0)
			{
				_pos.x -= MOVESPEED * 2;
			}
		}
		
	}
		break;
	case MAI::LEFT_KNOCK_DOWN:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
	}
		break;
	case MAI::RIGHT_KNOCK_DOWN:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
	}
		break;
	case MAI::LEFT_KNOCK_DOWN_BACK_MOVE:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
	}
		break;
	case MAI::RIGHT_KNOCK_DOWN_BACK_MOVE:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
	}
		break;
	case MAI::LEFT_DAMAGED:
	{
		if (!_animation->isPlay())
		{
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
	}
		break;
	case MAI::RIGHT_DAMAGED:
		break;
	case MAI::LEFT_JUMP_LEFT_MOVE:
		break;
	case MAI::RIGHT_JUMP_LFET_MOVE:
		break;
	case MAI::LEFT_JUMP_RIGHT_MOVE:
		break;
	case MAI::RIGHT_JUMP_RIGHT_MOVE:
		break;
	case MAI::STATE_END:
		break;

	}

}

//캐릭터의 상태업데이트(키가눌렸을때)
void mai::changeState(state) 
{

	switch (_state)
	{
	case MAI::LEFT_STOP:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{

			//이전에 왼쪽을 누름
			if (_lastKey == LEFT)
			{
				setAnimation("maiLeftFrontDash");
				_state = LEFT_DASH;
				_lastKey = END;
			}
			else
			{
				//왼쪽으로 이동
				setAnimation("maiLeftBackMove");
				_state = LEFT_MOVE;
			}
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			//오른쪽으로 가기 버튼이라면 대쉬가 발동
			if (_lastKey == RIGHT)
			{
				//이미 한번 대쉬를 했기때문에 중복되는것을 방지하기위한 초기화
				_lastKey = END;
				setAnimation("maiLeftBackDash");
				_state = LEFT_BACK_DASH;
			}
			else
			{
				//오른쪽(뒤로) 이동
				setAnimation("maiLeftBackMove");
				_state = LEFT_BACK_MOVE;
			}
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			//점프
			setAnimation("maiLeftJump");
			_state = LEFT_JUMP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			//앉기
			setAnimation("maiLeftSit");
			_state = LEFT_SIT;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			//약공
			setAnimation("maiLeftPunch");
			_state = LEFT_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			//약발
			setAnimation("maiLeftKick");
			_state = LEFT_KICK;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			//강공
			setAnimation("maiLeftStrongPunch");
			_state = LEFT_STRONG_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			//강발
			setAnimation("maiLeftStrongKick");
			_state = LEFT_STRONG_KICK;
		}

		//상대가 왼쪽에 있지 않다면
		if (_posEnum != LEFT_SEE)
		{
			setAnimation("maiRightStop");
			_state = RIGHT_STOP;
		}
		
		
	}
		break;
	case MAI::RIGHT_STOP:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			if (_lastKey == LEFT)
			{
				setAnimation("maiRightBackDash");
				_state = RIGHT_BACK_DASH;
				_lastKey = END;
			}
			else
			{
				//왼쪽(뒤로) 이동
				setAnimation("maiRightBackMove");
				_state = RIGHT_BACK_MOVE;
			}
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			if (_lastKey == RIGHT)
			{
				setAnimation("maiRightFrontDash");
				_state = RIGHT_DASH;
				_lastKey = END;
			}
			else
			{
				//오른쪽으로 이동
				setAnimation("maiRightBackMove");
				_state = RIGHT_MOVE;
			}
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			//점프
			setAnimation("maiRightJump");
			_state = RIGHT_JUMP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			//앉기
			setAnimation("maiRightSit");
			_state = RIGHT_SIT;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			//약공
			setAnimation("maiRightPunch");
			_state = RIGHT_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			//약발
			setAnimation("maiRightKick");
			_state = RIGHT_KICK;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			//강공
			setAnimation("maiRightStrongPunch");
			_state = RIGHT_STRONG_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			//강발
			setAnimation("maiRightStrongKick");
			_state = RIGHT_STRONG_KICK;
		}

		//상대가 오른쪽에 있지 않다면 바라보는 방향을 바꿔야함
		if (_posEnum != RIGHT_SEE)
		{
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
	}
		break;
	case MAI::LEFT_MOVE:
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
		{
			//왼쪽으로 이동키를 뗌
			//키를 가지고 있을 시간 초기화
			_lastKeyTime = LASTKEY_TIME;
			_lastKey = LEFT;
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
		else if(KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			//이동중에 앉는키를 누름
			setAnimation("maiLeftSit");
			_state = LEFT_SIT;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			setAnimation("maiLeftJump");
			_state = LEFT_JUMP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			setAnimation("maiLeftPunch");
			_state = LEFT_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			setAnimation("maiLeftKick");
			_state = LEFT_KICK;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			setAnimation("maiLeftStrongPunch");
			_state = LEFT_STRONG_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			setAnimation("maiLeftStrongKick");
			_state = LEFT_STRONG_KICK;
		}

		if (_posEnum != LEFT_SEE)
		{
			_posEnum = RIGHT_SEE;
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}

	}
		break;
	case MAI::RIGHT_MOVE:
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))
		{
			//키를 가지고 있을 시간 초기화
			_lastKeyTime = LASTKEY_TIME;
			_lastKey = RIGHT;
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			setAnimation("maiRightJump");
			_state = RIGHT_JUMP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			setAnimation("maiRightSit");
			_state = RIGHT_SIT;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			setAnimation("maiRightPunch");
			_state = RIGHT_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			setAnimation("maiRightKick");
			_state = RIGHT_KICK;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			setAnimation("maiRightStrongPunch");
			_state = RIGHT_STRONG_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			setAnimation("maiRightStrongKick");
			_state = RIGHT_STRONG_KICK;
		}

		if (_posEnum != RIGHT_SEE)
		{
			_posEnum = LEFT_SEE;
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
	}
		break;
	case MAI::LEFT_JUMP:
	{
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			_state = LEFT_JUMP_LEFT_MOVE;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			_state = LEFT_JUMP_RIGHT_MOVE;
		}
	}
		break;
	case MAI::RIGHT_JUMP:
	{
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			_state = RIGHT_JUMP_LFET_MOVE;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			_state = RIGHT_JUMP_RIGHT_MOVE;
		}
	}
		break;
	case MAI::LEFT_BACK_MOVE:
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))
		{
			//키를떼면 마지막까지 누르고 있던 키가 오른쪽으로 가기 버튼
			_lastKey = RIGHT;
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
		else if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			//왼쪽으로 이동
			this->setAnimation("maiLeftBackMove");
			_state = LEFT_MOVE;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			//이동중에 앉는키를 누름
			setAnimation("maiLeftSit");
			_state = LEFT_SIT;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			setAnimation("maiLeftJump");
			_state = LEFT_JUMP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			setAnimation("maiLeftPunch");
			_state = LEFT_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			setAnimation("maiLeftKick");
			_state = LEFT_KICK;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			setAnimation("maiLeftStrongPunch");
			_state = LEFT_STRONG_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			setAnimation("maiLeftStrongKick");
			_state = LEFT_STRONG_KICK;
		}

		if (_posEnum != LEFT_SEE)
		{
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
		
	}
		break;
	case MAI::RIGHT_BACK_MOVE:
	{
		
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
		{
			_lastKey = LEFT;
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			//오른쪽으로 이동
			this->setAnimation("maiRightBackMove");
			_state = RIGHT_MOVE;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			//점프
			this->setAnimation("maiRightJump");
			_state = RIGHT_JUMP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			//앉기
			this->setAnimation("maiRightSit");
			_state = RIGHT_SIT;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			//약공
			setAnimation("maiRightPunch");
			_state = RIGHT_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			//약발
			setAnimation("maiRightKick");
			_state = RIGHT_KICK;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			//강공
			setAnimation("maiRightStrongPunch");
			_state = RIGHT_STRONG_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			//강발
			setAnimation("maiRightStrongKick");
			_state = RIGHT_STRONG_KICK;
		}

		//상대가 오른쪽에 있지 않다면 바라보는 방향을 바꿔야함
		if (_posEnum != RIGHT_SEE)
		{
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
		
	}
		break;
	case MAI::LEFT_SIT:
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))
		{
			//앉는키를 뗀다면
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			//앉은상태에서 점프키를 누르면 킹오파에서는 스탑상태로 바뀐다
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			//앉아서 약공
			setAnimation("maiLeftSitPunch");
			_state = LEFT_SIT_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			//앉아서 약발
			setAnimation("maiLeftSitKick");
			_state = LEFT_SIT_KICK;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			//앉아서 강공
			setAnimation("maiLeftSitStrongPunch");
			_state = LEFT_SIT_STRONG_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			//앉아서 강발
			setAnimation("maiLeftSitStrongKick");
			_state = LEFT_SIT_STRONG_KICK;
		}
		
		if (_posEnum != LEFT_SEE)
		{
			setAnimation("maiRightSit");
			_state = RIGHT_SIT;
		}
	}
		break;
	case MAI::RIGHT_SIT:
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))
		{
			//앉는키를 뗏다면
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			//점프키를 누르면 stop상태로 바뀜
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			//앉아서 약발
			setAnimation("maiRightSitKick");
			_state = RIGHT_SIT_KICK;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			//앉아서 약공
			setAnimation("maiRightSitPunch");
			_state = RIGHT_SIT_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			setAnimation("maiRightSitStrongPunch");
			_state = RIGHT_SIT_STRONG_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			setAnimation("maiRightSitStrongKick");
			_state = RIGHT_SIT_STRONG_KICK;
		}

		if (_posEnum != RIGHT_SEE)
		{
			setAnimation("maiLeftSit");
			_state = LEFT_SIT;
		}
	}
		break;
	case MAI::LEFT_KNOCK_DOWN:
	{
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			setAnimation("maiLeftKnockDownBackMove");
			_state = LEFT_KNOCK_DOWN_BACK_MOVE;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			setAnimation("maiLeftKnockDownBackMove");
			_state = LEFT_KNOCK_DOWN_FRONT_MOVE;
		}
	}
		break;
	case MAI::RIGHT_KNOCK_DOWN:
	{
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			setAnimation("maiRightKnockDownBackMove");
			_state = RIGHT_KNOCK_DOWN_BACK_MOVE;
		}
		else if(KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			setAnimation("maiRightKnockDownBackMove");
			_state = RIGHT_KNOCK_DOWN_FRONT_MOVE;
		}
	}
	case MAI::LEFT_DASH:
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
		{
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
	}
	break;
	case MAI::RIGHT_DASH:
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))
		{
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
	}
	break;
		break;
	default:
		break;
	}

	

}

void mai::skill1()
{
	//KEYANIMANAGER->findAnimation("")->start();
}

void mai::skill2()
{

}

void mai::skill3()
{

}