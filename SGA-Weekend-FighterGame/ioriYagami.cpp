#include "stdafx.h"
#include "ioriYagami.h"
#include "attackHitbox.h"
#include "playGround.h"

HRESULT ioriYagami::init(vector2D pos)
{

	_playGround->setupDongjin();

	character::init("이오리", pos, "이오리_오른쪽_멈춤");
	_state = tagIoriState::RIGHT_STOP;

	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((tagIoriState::Enum)msg.data);
	});
	//this->setGravity(true);
	

	


	return S_OK;
}
void ioriYagami::release()
{
	character::release();
}
void ioriYagami::update()
{
	character::update();

	stateUpdate(_state);

	if (_pos.x < _enemy->_pos.x && !_isEnemyDirection)
	{
		_isEnemyDirection = true;
	}
	else if (_pos.x > _enemy->_pos.x&&_isEnemyDirection)
	{
		_isEnemyDirection = false;
	}

}
void ioriYagami::render()
{
	character::render();
}

void ioriYagami::stateUpdate(tagIoriState::Enum state)
{
	switch (_state)
	{
		
	case tagIoriState::RIGHT_STOP:
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			changeState(tagIoriState::RIGHT_MOVE);
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			changeState(tagIoriState::RIGHT_BACK_MOVE);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(tagIoriState::RIGHT_SIT);

		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			changeState(tagIoriState::ATTAK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			changeState(tagIoriState::KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			changeState(tagIoriState::STRONG_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			changeState(tagIoriState::STRONG_KICK);
		}

		if (KEYMANAGER->isStayKeyDown(keyList[key::JUMP]))
		{
			changeState(tagIoriState::RIGHT_JUMP);

		}
		if (!_isEnemyDirection)
		{
			this->changeState(tagIoriState::LEFT_STOP);
		}

		break;
		
		
	case tagIoriState::LEFT_STOP:
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			changeState(tagIoriState::LEFT_BACK_MOVE);
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			changeState(tagIoriState::LEFT_MOVE);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(tagIoriState::LEFT_SIT);

		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			changeState(tagIoriState::ATTAK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			changeState(tagIoriState::KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			changeState(tagIoriState::STRONG_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			changeState(tagIoriState::STRONG_KICK);
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			changeState(tagIoriState::LEFT_JUMP);
			
		}
		if (_isEnemyDirection)
		{
			this->changeState(tagIoriState::RIGHT_STOP);
		}

		break;
		
	case tagIoriState::RIGHT_MOVE:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			_pos.x += 5;
		}
		if (!KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			changeState(tagIoriState::RIGHT_STOP);
		}

	}
	break;
	case tagIoriState::LEFT_MOVE:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			_pos.x -= 5;
		}
		if (!KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			changeState(tagIoriState::LEFT_STOP);
		}
	}
	break;
	case tagIoriState::RIGHT_RUN:
		//if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT, key::RIGHT]))
		//{
		//	_pos.x += 8;
		//}
		//
		//if (!KEYMANAGER->isStayKeyDown(keyList[key::RIGHT, key::RIGHT]))
		//{
		//	changeState(tagIoriState::RIGHT_STOP);
		//}
		break;
	case tagIoriState::LEFT_RUN:
		break;
	case tagIoriState::RIGHT_BACK_MOVE:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			_pos.x -= 5;
		}
		if (!KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			changeState(tagIoriState::RIGHT_STOP);
		}
	}
	break;
	case tagIoriState::LEFT_BACK_MOVE:
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			_pos.x += 5;
		}
		if (!KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			changeState(tagIoriState::LEFT_STOP);
		}
		break;
	case tagIoriState::RIGHT_SIT:

		if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(tagIoriState::RIGHT_STOP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			changeState(tagIoriState::SIT_ATTAK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			changeState(tagIoriState::SIT_KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			changeState(tagIoriState::SIT_STRONG_ATTAK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			changeState(tagIoriState::SIT_STRONG_KIKC);
		}
		if (!_isEnemyDirection)
		{
			this->changeState(tagIoriState::LEFT_SIT);
		}

		break;
	case tagIoriState::LEFT_SIT:
		if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(tagIoriState::RIGHT_STOP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			changeState(tagIoriState::SIT_ATTAK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			changeState(tagIoriState::SIT_KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			changeState(tagIoriState::SIT_STRONG_ATTAK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			changeState(tagIoriState::SIT_STRONG_KIKC);
		}
		if (_isEnemyDirection)
		{
			this->changeState(tagIoriState::RIGHT_SIT);
		}
		break;
	case tagIoriState::RIGHT_JUMP:
		//if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		//{
		//	//jump(25);
		//	//this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		//}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			changeState(tagIoriState::JUMP_ATTAK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			changeState(tagIoriState::JUMP_KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			changeState(tagIoriState::JUMP_STRONG_ATTAK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			changeState(tagIoriState::JUMP_STRONG_KICK);
		}
		if (!_isEnemyDirection)
		{
			this->changeState(tagIoriState::LEFT_STOP);
		}
		break;
	case tagIoriState::LEFT_JUMP:
		if (KEYMANAGER->isStayKeyDown(keyList[key::JUMP]))
		{
			//jump(25);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			changeState(tagIoriState::JUMP_ATTAK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			changeState(tagIoriState::JUMP_KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			changeState(tagIoriState::JUMP_STRONG_ATTAK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			changeState(tagIoriState::JUMP_STRONG_KICK);
		}
		if (!_isEnemyDirection)
		{
			this->changeState(tagIoriState::RIGHT_STOP);
		}
		break;
	case tagIoriState::ATTAK:

		break;
	case tagIoriState::KICK:

		break;
	case tagIoriState::STRONG_ATTACK:
		break;
	case tagIoriState::STRONG_KICK:
		break;
	
	case tagIoriState::SKILL1:
		break;
	case tagIoriState::SKILL2:
		break;
	case tagIoriState::SKILL3:
		break;
	}

}

void ioriYagami::changeState(tagIoriState::Enum state)
{
	switch (state)
	{
	case tagIoriState::RIGHT_STOP:
		this->setAnimation("이오리_오른쪽_멈춤");
		break;
		case tagIoriState::LEFT_STOP:
			this->setAnimation("이오리_왼쪽_멈춤");
			break;
	case tagIoriState::RIGHT_MOVE:
	{
		this->setAnimation("이오리_오른쪽_이동");
		//this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_MOVE));
	}
	break;
	case tagIoriState::LEFT_MOVE:
		this->setAnimation("이오리_왼쪽_이동");
		break;
	case tagIoriState::RIGHT_RUN:
		this->setAnimation("이오리_오른쪽_대쉬");
		break;
	case tagIoriState::LEFT_RUN:
		this->setAnimation("이오리_오른쪽_대쉬");
		break;
	case tagIoriState::RIGHT_BACK_MOVE:
		this->setAnimation("이오리_오른쪽_뒤_이동");
		break;
	case tagIoriState::LEFT_BACK_MOVE:
		this->setAnimation("이오리_왼쪽_뒤_이동");
		break;
	case tagIoriState::RIGHT_SIT:
		this->setAnimation("이오리_오른쪽_앉음");
		break;
	case tagIoriState::LEFT_SIT:
		this->setAnimation("이오리_왼쪽_앉음");
		break;
	case tagIoriState::RIGHT_JUMP:
		this->setAnimation("이오리_오른쪽_점프");
		jump(25);
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.1f, tagIoriState::RIGHT_STOP));
		break;
	case tagIoriState::LEFT_JUMP:
		jump(25);
		this->setAnimation("이오리_왼쪽_점프");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.1f, tagIoriState::LEFT_STOP));
		break;
	case tagIoriState::ATTAK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_약손");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 180, _pos.y - 80), vector2D(50, 65), _enemy, 0.1f);
			WORLD->addObject(hitbox);
		}
		
		if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_약손");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 180, _pos.y - 80), vector2D(50, 65), _enemy, 0.1f);
			WORLD->addObject(hitbox);
		}
		break;
	case tagIoriState::KICK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_약발");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 150, _pos.y + 30), vector2D(50, 95), _enemy, 0.3f);
			WORLD->addObject(hitbox);
		}

		if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_약발");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 150, _pos.y + 30), vector2D(50, 95), _enemy, 0.3f);
			WORLD->addObject(hitbox);
		}
		break;
	case tagIoriState::STRONG_ATTACK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_강손");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		}

		if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_강손");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
		}
		break;
	case tagIoriState::STRONG_KICK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_강발");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		}

		if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_강발");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
		}
		break;
	case tagIoriState::SIT_ATTAK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_앉은_약손");
			if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_SIT));
			}
			if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
			}
		}

		if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_앉은_약손");
			if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_SIT));
			}
			if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
			}
		}
		break;
	case tagIoriState::SIT_KICK:
		if (_isEnemyDirection)
		{
		this->setAnimation("이오리_오른쪽_앉은_약발");
		
			if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_SIT));
			}
			if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
			}
		}

		if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_앉은_약발");

			if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_SIT));
			}
			if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
			}
		}
		break;
	case tagIoriState::SIT_STRONG_ATTAK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_앉은_강손");
			if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_SIT));
			}
			if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
			}
		}

		if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_앉은_강손");
			if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_SIT));
			}
			if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
			}
		}
		break;
	case tagIoriState::SIT_STRONG_KIKC:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_앉은_강발");
			if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_SIT));
			}
			if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
			}
		}

		if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_앉은_강발");
			if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_SIT));
			}
			if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
			}
		}
		break;
	case tagIoriState::JUMP_ATTAK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_점프_약손");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		}

		if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_점프_약손");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
		}
		break;
	case tagIoriState::JUMP_KICK:
		if (_isEnemyDirection)
	{
		this->setAnimation("이오리_오른쪽_점프_약발");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
	}

		if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_점프_약발");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
		}
		break;
	case tagIoriState::JUMP_STRONG_ATTAK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_점프_강손");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		}

		if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_점프_강손");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
		}
		break;
	case tagIoriState::JUMP_STRONG_KICK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_점프_강발");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		}

		if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_점프_강발");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
		}
		break;
	case tagIoriState::SKILL1:
		this->setAnimation("이오리_오른쪽_스킬");
		break;
	case tagIoriState::SKILL2:
		this->setAnimation("이오리_오른쪽_스킬2");
		break;
	case tagIoriState::SKILL3:
		this->setAnimation("이오리_오른쪽_스킬3");
		break;
	}
	_state = state;
}

