#include "stdafx.h"
#include "terry.h"
#include "attackHitbox.h"


HRESULT terry::init(vector2D pos)
{
	IMAGEMANAGER->addFrameImage("terryIdle", "resource/geunhwa/terryIdle.bmp", 2288, 800, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryMove", "resource/geunhwa/terryMove.bmp", 1716, 914, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryBackMove", "resource/geunhwa/terryBackMove.bmp", 1716, 914, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryDashMove", "resource/geunhwa/terryDashMove.bmp", 4570, 800, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryBackDash", "resource/geunhwa/terryBackDash.bmp", 286, 800, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terrySit", "resource/geunhwa/terrySit.bmp", 858, 800, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryJump", "resource/geunhwa/terryJump.bmp", 1716, 1142, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryMoveJump", "resource/geunhwa/terryMoveJump.bmp", 1430, 1142, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryBackMoveJump", "resource/geunhwa/terryBackMoveJump.bmp", 1430, 1142, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryDefence", "resource/geunhwa/terryDefence.bmp", 1029, 800, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terrySitDefence", "resource/geunhwa/terrySitDefence.bmp", 858, 800, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryAttack", "resource/geunhwa/terryAttack.bmp", 686, 800, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryKick", "resource/geunhwa/terryKick.bmp", 1828, 800, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryPowerAttack", "resource/geunhwa/terryPowerAttack.bmp", 1371, 800, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryPowerKick", "resource/geunhwa/terryPowerKick.bmp", 3084, 800, 6, 2, true, RGB(255, 0, 255));


	//// Left::왼쪽에 서 있는상태 // Right::오른쪽에 서 있는 상태

	//서있는상태 (Idle)
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightIdle", "terryIdle", 0, 7, 8, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftIdle", "terryIdle", 8, 15, 8, false, true);

	//무빙
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightMove", "terryMove", 0, 5, 6, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftMove", "terryMove", 6, 11, 6, false, false);

	//뒷무빙
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightBackMove", "terryBackMove", 0, 5, 6, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftBackMove", "terryBackMove", 6, 11, 6, false, false);

	//대쉬무빙
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightDashMove", "terryDashMove", 0, 9, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftDashMove", "terryDashMove", 19, 10, 8, false, false);

	//백대쉬
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightBackDash", "terryBackDash", 0, 0, 1, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftBackDash", "terryBackDash", 1, 1, 1, false, false);

	//앉기
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightSit", "terrySit", 0, 2, 6, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftSit", "terrySit", 3, 5, 6, false, false);

	//제자리 점프
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightJump", "terryJump", 0, 5, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftJump", "terryJump", 6, 11, 8, false, false);

	//무브 점프
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightMoveJump", "terryMoveJump", 0, 4, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftMoveJump", "terryMoveJump", 5, 9, 8, false, false);

	//백 무브 점프
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightBackMoveJump", "terryBackMoveJump", 0, 4, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftBackMoveJump", "terryBackMoveJump", 5, 9, 8, false, false);

	//스탠딩 막기
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightDefence", "terryDefence", 0, 2, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftDefence", "terryDefence", 3, 5, 8, false, false);

	//앉은 막기
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightSitDefence", "terrySitDefence", 0, 2, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftSitDefence", "terrySitDefence", 3, 5, 8, false, false);

	//약손
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightAttack", "terryAttack", 0, 2, 15, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftAttack", "terryAttack", 3, 2, 15, false, false);
	//약발
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightKick", "terryKick", 0, 4, 15, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftKick", "terryKick", 7, 4, 15, false, false);
	//강손
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightPowerAttack", "terryPowerAttack", 0, 2, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftPowerAttack", "terryPowerAttack", 5, 3, 10, false, false);
	//강발
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightPowerKick", "terryPowerKick", 0, 5, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftPowerKick", "terryPowerKick", 11, 6, 10, false, false);


	character::init("테리", pos, "terryLeftIdle");
	_state = tagTerryState::LEFT_STOP;

	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((tagTerryState::Enum)msg.data);
	});
	_isEnemyRight = true;

	


	return S_OK;
}

void terry::release()
{
	character::release();

}
void terry::update()
{
	character::update();

	stateUpdate(_state);
	enemyPos();
	
	
}
void terry::render()
{
	character::render();

}

void terry::changeState(tagTerryState::Enum state)
{
	switch (state)
	{
	case tagTerryState::RIGHT_STOP:
		this->setAnimation("terryRightIdle");
		break;
	case tagTerryState::LEFT_STOP:
		this->setAnimation("terryLeftIdle");
		break;
	case tagTerryState::RIGHT_MOVE:
		this->setAnimation("terryRightMove");
		break;
	case tagTerryState::LEFT_MOVE:
		this->setAnimation("terryLeftMove");
		break;
	case tagTerryState::RIGHT_BACK_MOVE:
		this->setAnimation("terryRightBackMove");
		break; 
	case tagTerryState::LEFT_BACK_MOVE:
		this->setAnimation("terryLeftBackMove");
		break;
	case tagTerryState::RIGHT_DASH_MOVE:
		this->setAnimation("terryRightDashMove");
		break; 
	case tagTerryState::LEFT_DASH_MOVE:
		this->setAnimation("terryLeftDashMove");
			break;
	case tagTerryState::RIGHT_BACK_DASH:
		this->setAnimation("terryRightBackDash");
		break; 
	case tagTerryState::LEFT_BACK_DASH:
		this->setAnimation("terryLeftBackDash");
		break;		
	case tagTerryState::RIGHT_SIT: 
		this->setAnimation("terryRightSit");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::RIGHT_STOP));
		break;
	case tagTerryState::LEFT_SIT:
		this->setAnimation("terryLeftSit");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::LEFT_STOP));
		break;		
	case tagTerryState::RIGHT_JUMP: 
		this->setAnimation("terryRightJump");
		jump(55);
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::RIGHT_STOP));
		break;
	case tagTerryState::LEFT_JUMP:
		this->setAnimation("terryLeftJump");
		jump(55);
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::LEFT_STOP));
		break;
	case tagTerryState::RIGHT_MOVE_JUMP: 
		this->setAnimation("terryRightMoveJump");
		jump(55);
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::RIGHT_STOP));
		break;
	case tagTerryState::LEFT_MOVE_JUMP:
		this->setAnimation("terryLeftMoveJump");
		jump(55);
		
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::LEFT_STOP));
		break;
	case tagTerryState::RIGHT_BACK_MOVE_JUMP:
		this->setAnimation("terryRightBackMoveJump");
		jump(55);
		
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::LEFT_STOP));
		break;
	case tagTerryState::LEFT_BACK_MOVE_JUMP:
		this->setAnimation("terryLeftBackMoveJump");
		jump(55);
		
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::LEFT_STOP));
		break;		
	case tagTerryState::RIGHT_DEFENCE: 
		this->setAnimation("terryRightDefence");
		break;
	case tagTerryState::LEFT_DEFENCE:
		this->setAnimation("terryLeftDefence");
		break;
	case tagTerryState::RIGHT_SIT_DEFENCE: 
		this->setAnimation("terryRightSitDefence");
		break;
	case tagTerryState::LEFT_SIT_DEFENCE:
		this->setAnimation("terryLeftSitDefence");
		break;		
	case tagTerryState::RIGHT_ATTACK: 
	{
		this->setAnimation("terryRightAttack");

		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::RIGHT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x - 170, _pos.y - 120), vector2D(50, 50), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
		break;
	case tagTerryState::LEFT_ATTACK:
	{
		this->setAnimation("terryLeftAttack");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::LEFT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 170, _pos.y - 120), vector2D(50, 50), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
	break;
	case tagTerryState::RIGHT_KICK:
	{
		this->setAnimation("terryRightKick");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::RIGHT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x - 220, _pos.y - 50), vector2D(50, 80), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
		break;
	case tagTerryState::LEFT_KICK:
	{
		this->setAnimation("terryLeftKick");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::LEFT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 220, _pos.y - 50), vector2D(50, 80), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
		break;
	case tagTerryState::RIGHT_POWER_ATTACK: 
	{
		this->setAnimation("terryRightPowerAttack");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::RIGHT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x - 200, _pos.y - 80), vector2D(50, 60), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
		break;
	case tagTerryState::LEFT_POWER_ATTACK:
	{
		this->setAnimation("terryLeftPowerAttack");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::LEFT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 200, _pos.y - 80), vector2D(50, 60), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
		break;
	case tagTerryState::RIGHT_POWER_KICK: 
	{
		this->setAnimation("terryRightPowerKick");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::RIGHT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x - 200, _pos.y - 120), vector2D(50, 120), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
		break;
	case tagTerryState::LEFT_POWER_KICK:
	{
		this->setAnimation("terryLeftPowerKick");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagTerryState::LEFT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 200, _pos.y - 120), vector2D(50, 120), _enemy, 0.1f);
		WORLD->addObject(hitbox);
	}
		break;
	}
	_state = state;
}
void terry::stateUpdate(tagTerryState::Enum state)
{
	switch (state)
	{
	case tagTerryState::RIGHT_STOP:
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			changeState(tagTerryState::RIGHT_MOVE);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			changeState(tagTerryState::RIGHT_BACK_MOVE);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			changeState(tagTerryState::RIGHT_JUMP);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(tagTerryState::RIGHT_SIT);
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))
		{
			changeState(tagTerryState::RIGHT_STOP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			changeState(tagTerryState::RIGHT_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			changeState(tagTerryState::RIGHT_KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			changeState(tagTerryState::RIGHT_POWER_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			changeState(tagTerryState::RIGHT_POWER_KICK);
		}
		if (_isEnemyRight)changeState(tagTerryState::LEFT_STOP);
		break;
	case tagTerryState::LEFT_STOP:
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			this->changeState(tagTerryState::LEFT_MOVE);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			changeState(tagTerryState::LEFT_BACK_MOVE);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			changeState(tagTerryState::LEFT_JUMP);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(tagTerryState::LEFT_SIT);
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))
		{
			changeState(tagTerryState::LEFT_STOP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			changeState(tagTerryState::LEFT_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			changeState(tagTerryState::LEFT_KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			changeState(tagTerryState::LEFT_POWER_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			changeState(tagTerryState::LEFT_POWER_KICK);
		}
		if (!_isEnemyRight)changeState(tagTerryState::RIGHT_STOP);

		break;
	case tagTerryState::RIGHT_MOVE:
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			_pos.x -= 10;
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
		{
			changeState(tagTerryState::RIGHT_STOP);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(tagTerryState::RIGHT_SIT);
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))
		{
			changeState(tagTerryState::RIGHT_STOP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			changeState(tagTerryState::RIGHT_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			changeState(tagTerryState::RIGHT_KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			changeState(tagTerryState::RIGHT_POWER_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			changeState(tagTerryState::RIGHT_POWER_KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			changeState(tagTerryState::RIGHT_MOVE_JUMP);
		}
		break;
	case tagTerryState::LEFT_MOVE:
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			_pos.x += 10;
		}
		if (KEYMANAGER->isOnceKeyUp (keyList[key::RIGHT]))
		{
			changeState(tagTerryState::LEFT_STOP);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(tagTerryState::LEFT_SIT);
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))
		{
			changeState(tagTerryState::LEFT_STOP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			changeState(tagTerryState::LEFT_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			changeState(tagTerryState::LEFT_KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			changeState(tagTerryState::LEFT_POWER_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			changeState(tagTerryState::LEFT_POWER_KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			changeState(tagTerryState::LEFT_MOVE_JUMP);
		}
		break;
	case tagTerryState::RIGHT_BACK_MOVE:
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			_pos.x += 10;
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))
		{
			changeState(tagTerryState::RIGHT_STOP);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(tagTerryState::RIGHT_SIT);
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))
		{
			changeState(tagTerryState::RIGHT_STOP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			changeState(tagTerryState::RIGHT_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			changeState(tagTerryState::RIGHT_KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			changeState(tagTerryState::RIGHT_POWER_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			changeState(tagTerryState::RIGHT_POWER_KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			changeState(tagTerryState::RIGHT_BACK_MOVE_JUMP);
		}
		break;
	case tagTerryState::LEFT_BACK_MOVE:
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			_pos.x -= 10;
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
		{
			changeState(tagTerryState::LEFT_STOP);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(tagTerryState::LEFT_SIT);
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))
		{
			changeState(tagTerryState::LEFT_STOP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			changeState(tagTerryState::LEFT_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			changeState(tagTerryState::LEFT_KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			changeState(tagTerryState::LEFT_POWER_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			changeState(tagTerryState::LEFT_POWER_KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			changeState(tagTerryState::LEFT_BACK_MOVE_JUMP);
		}
		break;
	case tagTerryState::RIGHT_DASH_MOVE:
		break;
	case tagTerryState::LEFT_DASH_MOVE:
		break;
	case tagTerryState::RIGHT_BACK_DASH:
		break;
	case tagTerryState::LEFT_BACK_DASH:
		break;
	case tagTerryState::RIGHT_SIT:
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))
		{
			changeState(tagTerryState::RIGHT_STOP);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			changeState(tagTerryState::RIGHT_SIT_DEFENCE);
		}
		break;
	case tagTerryState::LEFT_SIT:
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))
		{
			changeState(tagTerryState::LEFT_STOP);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			changeState(tagTerryState::LEFT_SIT_DEFENCE);
		}
		break;
	case tagTerryState::RIGHT_JUMP:
		break;
	case tagTerryState::LEFT_JUMP:
		break;
	case tagTerryState::RIGHT_MOVE_JUMP:
		_pos.x -= 10;
		break;
	case tagTerryState::LEFT_MOVE_JUMP:
		_pos.x += 10;
		break;
	case tagTerryState::RIGHT_BACK_MOVE_JUMP:
		_pos.x += 10;
		break;
	case tagTerryState::LEFT_BACK_MOVE_JUMP:
		_pos.x -= 10;
		break;
	case tagTerryState::RIGHT_DEFENCE:
		break;
	case tagTerryState::LEFT_DEFENCE:
		break;
	case tagTerryState::RIGHT_SIT_DEFENCE:
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))
		{
			changeState(tagTerryState::RIGHT_SIT);
		}
		break;
	case tagTerryState::LEFT_SIT_DEFENCE:
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
		{
			changeState(tagTerryState::LEFT_SIT);
		}
		break;
	case tagTerryState::RIGHT_ATTACK:
		break;
	case tagTerryState::LEFT_ATTACK:
		break;
	case tagTerryState::RIGHT_KICK:
		break;
	case tagTerryState::LEFT_KICK:
		break;
	case tagTerryState::RIGHT_POWER_ATTACK:
		break;
	case tagTerryState::LEFT_POWER_ATTACK:
		break;
	case tagTerryState::RIGHT_POWER_KICK:
		break;
	case tagTerryState::LEFT_POWER_KICK:
		break;
	}
}



void terry::enemyPos()
{
	if (this->_pos.x > _enemy->_pos.x && _isEnemyRight)			//내 x좌표값이 상대보다 크다면  (오른쪽에 내가 서있다면)
	{
		_isEnemyRight = false;									//상대위치 불값 false 
	}
	else if (this->_pos.x < _enemy->_pos.x && !_isEnemyRight)	//내	 x좌표값이 상대보다 작다면  (왼쪽에 내가 서있다면)
	{
		_isEnemyRight = true;									//내 위치 불값 true
	}
}