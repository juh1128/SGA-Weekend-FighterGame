#include "stdafx.h"
#include "mai.h"
#include "playGround.h"


HRESULT mai::init(vector2D pos)
{
	//�̹����� �ִϸ��̼� �¾�
	_playGround->setupSunghoon();

	if (pos.x == 200) //������ ���ʿ�����(���������ٶ�)
	{
		character::init("mai", pos, "maiRightIdle");
		_posEnum = RIGHT_SEE;
		_state = RIGHT_STOP;
	}
	else//������ �����ʿ�����(������ �ٶ�)
	{
		character::init("mai", pos, "maiLeftIdle");
		_posEnum = LEFT_SEE;
		_state = LEFT_STOP;
	}

	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((MAI::state)msg.data);
	});

	//�������� ���� Ű����
	_lastKey = END;

	return S_OK;
}

void mai::release()	
{
	character::release();
}
void mai::update()	
{
	character::update();

	//�׻� ������� �ٶ󺸵��� �ض�
	if (_pos.x < _enemy->_pos.x)
	{
		_posEnum = RIGHT_SEE;
	}
	else
	{
		_posEnum = LEFT_SEE;
	}

	stateUpdate(_state);
	changeState(_state);

}
void mai::render()	
{
	character::render();
	//TCHAR str[128];
	//sprintf(str, TEXT("status:%d"), _pos.x);
	//TextOut(getMemDC(), 0, 100, str, strlen(str));

}

//ĳ������ ���¿����� �ൿ��
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
	
		//jump(5);
	}
		break;
	case MAI::RIGHT_JUMP:
	{
		//jump(5);
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
	case MAI::LEFT_JUMP_LEFT_MOVE:
	{
		if (_pos.y >= GROUND_LINE)
		{
			_pos.y = GROUND_LINE;
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
		_gravity += GRAVITYACCEL;
		_pos.y -= JUMPPOWER - _gravity;
		_pos.x -= MOVESPEED;
	}
		break;
	case MAI::RIGHT_JUMP_LFET_MOVE:
	{
		if (_pos.y >= GROUND_LINE)
		{
			_pos.y = GROUND_LINE;
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
		_gravity += GRAVITYACCEL;
		_pos.y -= JUMPPOWER - _gravity;
		_pos.x -= MOVESPEED;
	}
		break;
	case MAI::LEFT_JUMP_RIGHT_MOVE:
	{
		if (_pos.y >= GROUND_LINE)
		{
			_pos.y = GROUND_LINE;
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
		_gravity += GRAVITYACCEL;
		_pos.y -= JUMPPOWER - _gravity;
		_pos.x += MOVESPEED;
	}
		break;
	case MAI::RIGHT_JUMP_RIGHT_MOVE:
	{
		if (_pos.y >= GROUND_LINE)
		{
			_pos.y = GROUND_LINE;
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
		_gravity += GRAVITYACCEL;
		_pos.y -= JUMPPOWER - _gravity;
		_pos.x += MOVESPEED;
	}
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
	case MAI::LEFT_STOP:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{

			//������ ������ ����
			if (_lastKey == LEFT)
			{
				setAnimation("maiLeftFrontDash");
				_state = LEFT_DASH;
				_lastKey = END;
			}
			else
			{
				//�������� �̵�
				setAnimation("maiLeftBackMove");
				_state = LEFT_MOVE;
			}
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			//���������� ���� ��ư�̶�� �뽬�� �ߵ�
			if (_lastKey == RIGHT)
			{
				//�̹� �ѹ� �뽬�� �߱⶧���� �ߺ��Ǵ°��� �����ϱ����� �ʱ�ȭ
				_lastKey = END;
				setAnimation("maiLeftBackDash");
				_state = LEFT_BACK_DASH;
			}
			else
			{
				//������(�ڷ�) �̵�
				setAnimation("maiLeftBackMove");
				_state = LEFT_BACK_MOVE;
			}
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			//����
			setAnimation("maiLeftJump");
			_state = LEFT_JUMP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			//�ɱ�
			setAnimation("maiLeftSit");
			_state = LEFT_SIT;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			//���
			setAnimation("maiLeftPunch");
			_state = LEFT_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			//���
			setAnimation("maiLeftKick");
			_state = LEFT_KICK;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			//����
			setAnimation("maiLeftStrongPunch");
			_state = LEFT_STRONG_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			//����
			setAnimation("maiLeftStrongKick");
			_state = LEFT_STRONG_KICK;
		}

		//��밡 ���ʿ� ���� �ʴٸ�
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
				//����(�ڷ�) �̵�
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
			}
			else
			{
				//���������� �̵�
				setAnimation("maiRightBackMove");
				_state = RIGHT_MOVE;
			}
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			//����
			setAnimation("maiRightJump");
			_state = RIGHT_JUMP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			//�ɱ�
			setAnimation("maiRightSit");
			_state = RIGHT_SIT;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			//���
			setAnimation("maiRightPunch");
			_state = RIGHT_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			//���
			setAnimation("maiRightKick");
			_state = RIGHT_KICK;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			//����
			setAnimation("maiRightStrongPunch");
			_state = RIGHT_STRONG_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			//����
			setAnimation("maiRightStrongKick");
			_state = RIGHT_STRONG_KICK;
		}

		//��밡 �����ʿ� ���� �ʴٸ� �ٶ󺸴� ������ �ٲ����
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
			//�������� �̵�Ű�� ��
			_lastKey = LEFT;
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
		else if(KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			//�̵��߿� �ɴ�Ű�� ����
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
			//Ű������ ���������� ������ �ִ� Ű�� ���������� ���� ��ư
			_lastKey = RIGHT;
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
		else if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			//�������� �̵�
			this->setAnimation("maiLeftBackMove");
			_state = LEFT_MOVE;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			//�̵��߿� �ɴ�Ű�� ����
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
			//���������� �̵�
			this->setAnimation("maiRightBackMove");
			_state = RIGHT_MOVE;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			//����
			this->setAnimation("maiRightJump");
			_state = RIGHT_JUMP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			//�ɱ�
			this->setAnimation("maiRightSit");
			_state = RIGHT_SIT;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			//���
			setAnimation("maiRightPunch");
			_state = RIGHT_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			//���
			setAnimation("maiRightKick");
			_state = RIGHT_KICK;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			//����
			setAnimation("maiRightStrongPunch");
			_state = RIGHT_STRONG_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			//����
			setAnimation("maiRightStrongKick");
			_state = RIGHT_STRONG_KICK;
		}

		//��밡 �����ʿ� ���� �ʴٸ� �ٶ󺸴� ������ �ٲ����
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
			//�ɴ�Ű�� ���ٸ�
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			//�������¿��� ����Ű�� ������ ŷ���Ŀ����� ��ž���·� �ٲ��
			setAnimation("maiLeftIdle");
			_state = LEFT_STOP;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			//�ɾƼ� ���
			setAnimation("maiLeftSitPunch");
			_state = LEFT_SIT_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			//�ɾƼ� ���
			setAnimation("maiLeftSitKick");
			_state = LEFT_SIT_KICK;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			//�ɾƼ� ����
			setAnimation("maiLeftSitStrongPunch");
			_state = LEFT_SIT_STRONG_PUNCH;
		}
		else if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			//�ɾƼ� ����
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
			//�ɴ�Ű�� �´ٸ�
			setAnimation("maiRightIdle");
			_state = RIGHT_STOP;
		}
	}
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
	default:
		break;
	}

	

}