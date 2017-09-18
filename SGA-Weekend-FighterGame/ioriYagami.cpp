#include "stdafx.h"
#include "ioriYagami.h"
#include "attackHitbox.h"
#include "playGround.h"

HRESULT ioriYagami::init(vector2D pos)
{

	_playGround->setupDongjin();

	character::init("이오리", pos, "이오리_오른쪽_멈춤");
	this->changeState(tagIoriState::RIGHT_STOP);

	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((tagIoriState::Enum)msg.data);
	});
	//this->setGravity(true);
	

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_앉은_약손", "ioriYagamiSitAttackA", 4, 0, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_앉은_약손", RectMakeCenter(150, 200, 200, 400));



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

	if (this->_pos.x > _enemy->_pos.x && _isEnemyRight)			//내 x좌표값이 상대보다 크다면 
	{
		_isEnemyRight = false;						//상대위치 불값 false 
	}
	else if (this->_pos.x < _enemy->_pos.x && !_isEnemyRight)	//내	 x좌표값이 상대보다 작다면 
	{
		_isEnemyRight = true;						//내 위치 불값 true
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
	
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			changeState(tagIoriState::RIGHT_JUMP);
			
		}

		break;
		//case tagIoriState::LEFT_STOP:
		//	break;
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
		break;
	case tagIoriState::LEFT_SIT:
		break;
	case tagIoriState::RIGHT_JUMP:
		if (KEYMANAGER->isStayKeyDown(keyList[key::JUMP]))
		{
			jump(25);
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

		break;
	case tagIoriState::LEFT_JUMP:
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
		//case tagIoriState::LEFT_STOP:
		//	break;
	case tagIoriState::RIGHT_MOVE:
	{
		this->setAnimation("이오리_오른쪽_이동");
		//this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_MOVE));
	}
	break;
	case tagIoriState::LEFT_MOVE:
		break;
	case tagIoriState::RIGHT_RUN:
		this->setAnimation("이오리_오른쪽_대쉬");
		break;
	case tagIoriState::LEFT_RUN:
		break;
	case tagIoriState::RIGHT_BACK_MOVE:
		this->setAnimation("이오리_오른쪽_뒤_이동");
		break;
	case tagIoriState::LEFT_BACK_MOVE:
		break;
	case tagIoriState::RIGHT_SIT:
		this->setAnimation("이오리_오른쪽_앉음");
		break;
	case tagIoriState::LEFT_SIT:
		break;
	case tagIoriState::RIGHT_JUMP:
		this->setAnimation("이오리_오른쪽_점프");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.1f, tagIoriState::RIGHT_STOP));
		break;
	case tagIoriState::LEFT_JUMP:
		break;
	case tagIoriState::ATTAK:
		this->setAnimation("이오리_오른쪽_약손");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		//this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, testCharacterState::RIGHT_MOVE));
		break;
	case tagIoriState::KICK:
		this->setAnimation("이오리_오른쪽_약발");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		break;
	case tagIoriState::STRONG_ATTACK:
		this->setAnimation("이오리_오른쪽_강손");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		break;
	case tagIoriState::STRONG_KICK:
		this->setAnimation("이오리_오른쪽_강발");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		break;
	case tagIoriState::SIT_ATTAK:
		this->setAnimation("이오리_오른쪽_앉은_약손");
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_SIT));
		}
		if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		}
		break;
	case tagIoriState::SIT_KICK:
		this->setAnimation("이오리_오른쪽_앉은_약발");
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_SIT));
		}
		if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		}
		break;
	case tagIoriState::SIT_STRONG_ATTAK:
		this->setAnimation("이오리_오른쪽_앉은_강손");
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_SIT));
		}
		if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		}
		break;
	case tagIoriState::SIT_STRONG_KIKC:
		this->setAnimation("이오리_오른쪽_앉은_강발");
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_SIT));
		}
		if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		}
		break;
	case tagIoriState::JUMP_ATTAK:
		this->setAnimation("이오리_오른쪽_점프_약손");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		break;
	case tagIoriState::JUMP_KICK:
		this->setAnimation("이오리_오른쪽_점프_약발");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		break;
	case tagIoriState::JUMP_STRONG_ATTAK:
		this->setAnimation("이오리_오른쪽_점프_강손");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		break;
	case tagIoriState::JUMP_STRONG_KICK:
		this->setAnimation("이오리_오른쪽_점프_강발");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		break;
	case tagIoriState::SKILL1:
		this->setAnimation("이오리_오른쪽_스킬");
		break;
	case tagIoriState::SKILL2:
		this->setAnimation("이오리_오른쪽_스킬");
		break;
	case tagIoriState::SKILL3:
		this->setAnimation("이오리_오른쪽_스킬");
		break;
	}
	_state = state;
}

