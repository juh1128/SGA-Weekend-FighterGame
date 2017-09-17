#include "stdafx.h"
#include "mai.h"
#include "playGround.h"

HRESULT mai::init(vector2D pos)
{
	//�̹����� �ִϸ��̼� �¾�
	_playGround->setupSunghoon();

	if (pos.x < _enemy->_pos.x) //������ ���ʿ�����(���������ٶ�)
	{
		character::init("mai", pos, "maiRightIdle");
	}
	else//������ �����ʿ�����(������ �ٶ�)
	{
		character::init("mai", pos, "maiLeftIdle");
	}

	return S_OK;
}

void mai::release()	
{
	character::release();
}
void mai::update()	
{
	character::update();

	//�׻� ������� �ٶ󺸵��� �ض� ��
	if (_state == LEFT_IDLE || _state == RIGHT_IDLE)
	{
		if (this->_pos.x > _enemy->_pos.x)
		{
			_state = LEFT_IDLE;
		}
		else
		{
			_state = RIGHT_IDLE;
		}
	}

	stateUpdate();
	changeState();

}
void mai::render()	
{
	character::render();

}

//ĳ������ ���¿����� �ൿ��
void mai::stateUpdate() 
{

	switch (_state)
	{
	case MAI::LEFT_IDLE:
	{
		this->setAnimation("maiLeftIdle");
	}
		break;
	case MAI::RIGHT_IDLE:
	{
		this->setAnimation("maiRightIdle");
	}
		break;
	case MAI::LEFT_MOVE:
	{
		setAnimation("maiLeftMove");
		_pos.x -= MOVESPEED;
	}
		break;
	case MAI::RIGHT_MOVE:
	{
		setAnimation("maiRightMove");
		_pos.x += MOVESPEED;
	}
		break;
	case MAI::LEFT_JUMP:
	{
		setAnimation("maiLeftJump");
		jump(25);
	}
		break;
	case MAI::RIGHT_JUMP:
	{
		setAnimation("maiRightJump");
	}
		break;
	case MAI::LEFT_BACK_MOVE:
		break;
	case MAI::RIGHT_BACK_MOVE:
		break;
	case MAI::LEFT_SIT:
		break;
	case MAI::RIGHT_SIT:
		break;
	case MAI::LEFT_PUNCH:
		break;
	case MAI::RIGHT_PUNCH:
		break;
	case MAI::LEFT_STRONG_PUNCH:
		break;
	case MAI::RIGHT_STRONG_PUNCH:
		break;
	case MAI::LEFT_KICK:
		break;
	case MAI::RIGHT_KICK:
		break;
	case MAI::LEFT_STRONG_KICK:
		break;
	case MAI::RIGHT_STRONG_KICK:
		break;
	case MAI::LEFT_SIT_PUNCH:
		break;
	case MAI::RIGHT_SIT_PUNCH:
		break;
	case MAI::LEFT_SIT_KICK:
		break;
	case MAI::RIGHT_SIT_KICK:
		break;
	case MAI::LEFT_SIT_STRONG_PUNCH:
		break;
	case MAI::RIGHT_SIT_STRONG_PUNCH:
		break;
	case MAI::LEFT_SIT_STRONG_KICK:
		break;
	case MAI::RIGHT_SIT_STRONG_KICK:
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
		break;
	case MAI::RIGHT_DASH:
		break;
	case MAI::LEFT_BACK_DASH:
		break;
	case MAI::RIGHT_BACK_DASH:
		break;
	case MAI::LEFT_KNOCK_DOWN:
		break;
	case MAI::RIGHT_KNOCK_DOWN:
		break;
	case MAI::LEFT_KNOCK_DOWN_BACK_MOVE:
		break;
	case MAI::RIGHT_KNOCK_DOWN_BACK_MOVE:
		break;
	case MAI::LEFT_DAMAGED:
		break;
	case MAI::RIGHT_DAMAGED:
		break;
	case MAI::STATE_END:
		break;

	}

}

//ĳ������ ���¾�����Ʈ(Ű����������)
void mai::changeState() 
{

	switch (_state)
	{
	case MAI::LEFT_IDLE:
	{
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			_state = LEFT_MOVE;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			_state = LEFT_BACK_MOVE;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			_state = LEFT_JUMP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			_state = LEFT_SIT;
		}
		
	}
		break;
	case MAI::RIGHT_IDLE:
	{
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			_state = RIGHT_BACK_MOVE;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			_state = RIGHT_MOVE;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			_state = RIGHT_JUMP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			_state = RIGHT_SIT;
		}
	}
		break;
	case MAI::LEFT_MOVE:
		break;
	case MAI::RIGHT_MOVE:
		break;
	case MAI::LEFT_JUMP:
		break;
	case MAI::RIGHT_JUMP:
		break;
	case MAI::LEFT_BACK_MOVE:
		break;
	case MAI::RIGHT_BACK_MOVE:
		break;
	case MAI::LEFT_SIT:
		break;
	case MAI::RIGHT_SIT:
		break;
	case MAI::LEFT_PUNCH:
		break;
	case MAI::RIGHT_PUNCH:
		break;
	case MAI::LEFT_STRONG_PUNCH:
		break;
	case MAI::RIGHT_STRONG_PUNCH:
		break;
	case MAI::LEFT_KICK:
		break;
	case MAI::RIGHT_KICK:
		break;
	case MAI::LEFT_STRONG_KICK:
		break;
	case MAI::RIGHT_STRONG_KICK:
		break;
	case MAI::LEFT_SIT_PUNCH:
		break;
	case MAI::RIGHT_SIT_PUNCH:
		break;
	case MAI::LEFT_SIT_KICK:
		break;
	case MAI::RIGHT_SIT_KICK:
		break;
	case MAI::LEFT_SIT_STRONG_PUNCH:
		break;
	case MAI::RIGHT_SIT_STRONG_PUNCH:
		break;
	case MAI::LEFT_SIT_STRONG_KICK:
		break;
	case MAI::RIGHT_SIT_STRONG_KICK:
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
		break;
	case MAI::RIGHT_DASH:
		break;
	case MAI::LEFT_BACK_DASH:
		break;
	case MAI::RIGHT_BACK_DASH:
		break;
	case MAI::LEFT_KNOCK_DOWN:
		break;
	case MAI::RIGHT_KNOCK_DOWN:
		break;
	case MAI::LEFT_KNOCK_DOWN_BACK_MOVE:
		break;
	case MAI::RIGHT_KNOCK_DOWN_BACK_MOVE:
		break;
	case MAI::LEFT_DAMAGED:
		break;
	case MAI::RIGHT_DAMAGED:
		break;
	case MAI::STATE_END:
		break;
	default:
		break;
	}

	

}