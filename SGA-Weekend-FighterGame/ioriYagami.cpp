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

	this->setStatus(1000, 10);


	IMAGEMANAGER->addFrameImage("skill1Effect", "resource/Dongjin/오른쪽스킬1임팩트.bmp", 12589, 1280, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("skill1Effect6", "resource/Dongjin/스킬3임팩트.bmp", 16332, 1280, 19, 1, true, RGB(255, 0, 255));

	//커맨드!!!!!!

	int comnand[3] = { key::RIGHT, key::JUMP, key::STRONG_ATTACK };
	this->addCommand(comnand, 3, "skill");
	this->addCallback("skill", [this](tagMessage msg)
	{
		this->skill();
	});

	int comnand2[3] = { key::DOWN, key::RIGHT, key::ATTACK };
	this->addCommand(comnand2, 3, "skill2");
	this->addCallback("skill2", [this](tagMessage msg)
	{
		this->skill2();
	});

	int comnand3[4] = { key::DOWN, key::RIGHT, key::JUMP, key::STRONG_KICK };
	this->addCommand(comnand3, 4, "skill3");
	this->addCallback("skill3", [this](tagMessage msg)
	{
		this->skill3();
	});


	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((tagIoriState::Enum)msg.data);
	});

	this->addCallback("hited", [this](tagMessage msg)
	{
		this->hit(msg);
	});
	//this->addCallback("block", [this](tagMessage msg)
	//{
	//	this->block();
	//});
	this->addCallback("die", [this](tagMessage msg)
	{
		this->die(msg);
	});

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

		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
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

		break;
	case tagIoriState::LEFT_SIT:
		if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(tagIoriState::LEFT_STOP);
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
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.1f, tagIoriState::RIGHT_STOP));
		break;
	case tagIoriState::LEFT_JUMP:
		this->setAnimation("이오리_왼쪽_점프");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.1f, tagIoriState::LEFT_STOP));
		break;
	case tagIoriState::ATTAK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_약손");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 170, _pos.y - 80), vector2D(50, 55), _enemy, 0.1f);
			WORLD->addObject(hitbox);
		}

		else if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_약손");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 170, _pos.y - 80), vector2D(50, 55), _enemy, 0.1f);
			WORLD->addObject(hitbox);
		}
		break;
	case tagIoriState::KICK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_약발");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 150, _pos.y - 20), vector2D(50, 95), _enemy, 0.3f);
			WORLD->addObject(hitbox);
		}

		else if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_약발");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 150, _pos.y - 20), vector2D(50, 95), _enemy, 0.3f);
			WORLD->addObject(hitbox);
		}
		break;
	case tagIoriState::STRONG_ATTACK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_강손");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 175, _pos.y + 5), vector2D(50, 95), _enemy, 0.3f);
			WORLD->addObject(hitbox);
		}

		else if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_강손");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 175, _pos.y + 5), vector2D(50, 95), _enemy, 0.3f);
			WORLD->addObject(hitbox);
		}
		break;
	case tagIoriState::STRONG_KICK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_강발");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 175, _pos.y - 65), vector2D(50, 50), _enemy, 0.3f);
			WORLD->addObject(hitbox);
		}

		else if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_강발");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 175, _pos.y - 65), vector2D(50, 50), _enemy, 0.3f);
			WORLD->addObject(hitbox);
		}
		break;
	case tagIoriState::SIT_ATTAK:

		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_앉은_약손");
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 175, _pos.y + 10), vector2D(50, 65), _enemy, 0.3f);
			WORLD->addObject(hitbox);
			if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_SIT));
				
			}
			if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
			}
		}

		else if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_앉은_약손");
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 175, _pos.y + 10), vector2D(50, 65), _enemy, 0.3f);
			WORLD->addObject(hitbox);
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
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 185, _pos.y + 175), vector2D(50, 40), _enemy, 0.3f);
			WORLD->addObject(hitbox);
			if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_SIT));
			}
			if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
			}
		}

		else if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_앉은_약발"); attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 185, _pos.y + 175), vector2D(50, 40), _enemy, 0.3f);
			WORLD->addObject(hitbox);
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
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 150, _pos.y -160), vector2D(50, 80), _enemy, 0.3f);
			WORLD->addObject(hitbox);
			if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_SIT));
			}
			if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
			}
		}

		else if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_앉은_강손");
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 150, _pos.y - 160), vector2D(50, 80), _enemy, 0.3f);
			WORLD->addObject(hitbox);
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
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 200, _pos.y + 40), vector2D(50, 130), _enemy, 0.3f);
			WORLD->addObject(hitbox);
			if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_SIT));
			}
			if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
			}
		}

		else if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_앉은_강발");
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 200, _pos.y + 40), vector2D(50, 130), _enemy, 0.3f);
			WORLD->addObject(hitbox);
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
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 160, _pos.y + 20), vector2D(50, 50), _enemy, 0.3f);
			WORLD->addObject(hitbox);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		}

		else if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_점프_약손");
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 160, _pos.y + 20), vector2D(50, 50), _enemy, 0.3f);
			WORLD->addObject(hitbox);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
		}
		break;
	case tagIoriState::JUMP_KICK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_점프_약발");
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 225, _pos.y + 20), vector2D(50, 50), _enemy, 0.3f);
			WORLD->addObject(hitbox);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		}

		else if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_점프_약발");
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 225, _pos.y + 20), vector2D(50, 50), _enemy, 0.4f);
			WORLD->addObject(hitbox);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
		}
		break;
	case tagIoriState::JUMP_STRONG_ATTAK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_점프_강손");
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 150, _pos.y + 20), vector2D(50, 50), _enemy, 0.4f);
			WORLD->addObject(hitbox);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		}

		else if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_점프_강손");
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 150, _pos.y ), vector2D(50, 50), _enemy, 0.4f);
			WORLD->addObject(hitbox);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
		}
		break;
	case tagIoriState::JUMP_STRONG_KICK:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_점프_강발");
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 180, _pos.y - 60), vector2D(50, 80), _enemy, 0.4f);
			WORLD->addObject(hitbox);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		}

		else if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_점프_강발");
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 180, _pos.y - 60), vector2D(50, 80), _enemy, 0.4f);
			WORLD->addObject(hitbox);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
		}
		break;
	case tagIoriState::SKILL1:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_스킬");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, tagIoriState::RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 350, _pos.y), vector2D(300, 1028), _enemy, 0.8f);
			WORLD->addObject(hitbox);
		}
		else if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_스킬");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, tagIoriState::LEFT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 350, _pos.y), vector2D(300, 1028), _enemy, 0.8f);
			WORLD->addObject(hitbox);
		}
		break;
	case tagIoriState::SKILL2:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_스킬2");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, tagIoriState::RIGHT_STOP));
		}
		else if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_왼쪽_스킬2");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, tagIoriState::LEFT_STOP));
		}
		break;
	case tagIoriState::SKILL3:
		if (_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_스킬3");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, tagIoriState::RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 450, _pos.y), vector2D(500, 1028), _enemy, 0.8f);
			WORLD->addObject(hitbox);
		}
		else if (!_isEnemyDirection)
		{
			this->setAnimation("이오리_오른쪽_스킬3");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, tagIoriState::LEFT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 450, _pos.y), vector2D(500, 1028), _enemy, 0.8f);
			WORLD->addObject(hitbox);
		}
		break;
	case tagIoriState::RIGHT_HIT:
		this->setAnimation("이오리_오른쪽_맞음");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		break;

	case tagIoriState::LEFT_HIT:
		this->setAnimation("이오리_왼쪽_맞음");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
		break;

	case tagIoriState::RIGHT_DIE:
		this->setAnimation("이오리_오른쪽_죽음");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		break;

	case tagIoriState::LEFT_DIE:
		this->setAnimation("이오리_왼쪽_죽음");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::LEFT_STOP));
		break;
	}


	_state = state;
}

void ioriYagami::skill()
{
	this->changeState(tagIoriState::SKILL1);
	effectFire* effect = new effectFire;
	effect->init("skill1Effect", vector2D(_pos.x + 10, _pos.y - 1000));
	WORLD->addObject(effect);
	_effect = effect;
}

void ioriYagami::skill2()
{
	this->changeState(tagIoriState::SKILL2);
}

void ioriYagami::skill3()
{
	this->changeState(tagIoriState::SKILL3);

	effectFire* effect = new effectFire;
	effect->init("skill1Effect6", vector2D(_pos.x + 10, _pos.y - 1000));
	WORLD->addObject(effect);
	_effect = effect;


}

void ioriYagami::hit(tagMessage msg)
{
	tagMessage message = msg;
	if (message.data == DIRECTION::LEFT)
	{
		this->changeState(tagIoriState::RIGHT_HIT);
	}
	else if (message.data == DIRECTION::RIGHT)
	{
		this->changeState(tagIoriState::LEFT_HIT);
	}


}

void ioriYagami::die(tagMessage msg)
{
	tagMessage message = msg;
	if (message.data == DIRECTION::LEFT)
	{
		this->changeState(tagIoriState::RIGHT_DIE);
	}
	else if (message.data == DIRECTION::RIGHT)
	{
		this->changeState(tagIoriState::LEFT_DIE);
	}
}


