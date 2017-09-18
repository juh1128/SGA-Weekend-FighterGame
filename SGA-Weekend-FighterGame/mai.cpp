#include "stdafx.h"
#include "mai.h"
#include "playGround.h"


//=====================================
//���׳�Ʈ// changeState ����� ���ÿ� ����
//=====================================
HRESULT mai::init(vector2D pos)
{
	//�̹����� �ִϸ��̼� �¾�
	_playGround->setupSunghoon();

	if (pos.x == 200) //������ ���ʿ�����(���������ٶ�)
	{
		character::init("mai", pos, "maiRightIdle");
		_state = RIGHT_IDLE;
	}
	else//������ �����ʿ�����(������ �ٶ�)
	{
		character::init("mai", pos, "maiLeftIdle");
		_state = LEFT_IDLE;
	}

	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((MAI::state)msg.data);
	});

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

//ĳ������ ���¿����� �ൿ��
void mai::stateUpdate(state) 
{

	switch (_state)
	{
	case MAI::LEFT_IDLE:
	{
		
	}
		break;
	case MAI::RIGHT_IDLE:
	{
		
	}
		break;
	case MAI::LEFT_MOVE:
	{
		
		_pos.x -= MOVESPEED;
	}
		break;
	case MAI::RIGHT_MOVE:
	{
		_pos.x += MOVESPEED;
	}
		break;
	case MAI::LEFT_JUMP:
	{
	
		jump(25);
	}
		break;
	case MAI::RIGHT_JUMP:
	{
		
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
void mai::changeState(state) 
{

	switch (_state)
	{
	case MAI::LEFT_IDLE:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			this->setAnimation("maiLeftMove");
			_state = LEFT_MOVE;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			this->setAnimation("maiLeftBackMove");
			_state = LEFT_BACK_MOVE;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			this->setAnimation("maiLeftJump");
			_state = LEFT_JUMP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			this->setAnimation("maiLeftSit");
			_state = LEFT_SIT;
		}
		
	}
		break;
	case MAI::RIGHT_IDLE:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			this->setAnimation("amiRightBackMove");
			_state = RIGHT_BACK_MOVE;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			this->setAnimation("maiRightMove");
			_state = RIGHT_MOVE;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			this->setAnimation("maiRightJump");
			_state = RIGHT_JUMP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			this->setAnimation("maiRightSit");
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