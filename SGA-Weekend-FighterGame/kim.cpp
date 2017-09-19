#include "stdafx.h"
#include "kim.h"
#include "attackHitbox.h"


HRESULT kim::init(vector2D pos)
{
	IMAGEMANAGER->addFrameImage("kimIdle", "resource/yongje/서있는거(2053,796,11,2).bmp", 2053, 796, 11, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimWalk", "resource/yongje/앞뒤이동(1365,1593,6,4).bmp", 1365, 1593, 6, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimJump", "resource/yongje/점프(1593,1024,7,2).bmp", 1593, 1024, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimFrontJump", "resource/yongje/앞 대점프(3072,1024,9,2).bmp", 3072, 1024, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimSit", "resource/yongje/앉기(683,796,3,2).bmp", 683, 796, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimDash", "resource/yongje/대쉬(3186,683,8,2).bmp", 3186, 683, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimBackDash", "resource/yongje/백대쉬(569,796,2,2).bmp", 569, 796, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimA", "resource/yongje/원A(2418,796,4,2).bmp", 2418, 796, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimB", "resource/yongje/원B(4480,796,9,2).bmp", 4480, 796, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimC", "resource/yongje/원C(7040,811,11,2).bmp", 7040, 811, 11, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimD", "resource/yongje/원D(9600,996,18,2).bmp", 9600, 996, 18, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimHit", "resource/yongje/상단피격(711,796,2,2).bmp", 711, 796, 2, 2, true, RGB(255, 0, 255));



	KEYANIMANAGER->addCoordinateFrameAnimation("kimIdleLeft", "kimIdle", 0, 11, 22, false, true);
	KEYANIMANAGER->setCollisionRect("kimIdleLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimIdle")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimIdle")->getFrameHeight() / 2,
		110, 370));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimIdleRight", "kimIdle", 21, 11, 22, false, true);
	KEYANIMANAGER->setCollisionRect("kimIdleRight", RectMakeCenter(IMAGEMANAGER->findImage("kimIdle")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimIdle")->getFrameHeight() / 2,
		110, 370));

	KEYANIMANAGER->addCoordinateFrameAnimation("kimWalkFrontLeft", "kimWalk", 0, 6, 12, false, true);
	KEYANIMANAGER->setCollisionRect("kimWalkFrontLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimWalk")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimWalk")->getFrameHeight() / 2,
		110, 370));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimWalkBackLeft", "kimWalk", 6, 12, 12, false, true);
	KEYANIMANAGER->setCollisionRect("kimWalkBackLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimWalk")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimWalk")->getFrameHeight() / 2,
		110, 370));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimWalkFrontRight", "kimWalk", 17, 12, 12, false, true);
	KEYANIMANAGER->setCollisionRect("kimWalkFrontRight", RectMakeCenter(IMAGEMANAGER->findImage("kimWalk")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimWalk")->getFrameHeight() / 2,
		110, 370));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimWalkBackRight", "kimWalk", 23, 18, 12, false, true);
	KEYANIMANAGER->setCollisionRect("kimWalkBackRight", RectMakeCenter(IMAGEMANAGER->findImage("kimWalk")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimWalk")->getFrameHeight() / 2,
		110, 370));

	KEYANIMANAGER->addCoordinateFrameAnimation("kimSitLeft", "kimSit", 0, 3, 60, false, false);
	KEYANIMANAGER->setCollisionRect("kimSitLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimSit")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimSit")->getFrameHeight() / 2 + 80,
		110, 200));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimSitRight", "kimSit", 5, 3, 60, false, false);
	KEYANIMANAGER->setCollisionRect("kimSitRight", RectMakeCenter(IMAGEMANAGER->findImage("kimSit")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimSit")->getFrameHeight() / 2 + 80,
		110, 200));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimStandUpLeft", "kimSit", 1, 0, 60, false, false);
	KEYANIMANAGER->setCollisionRect("kimStandUpLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimSit")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimSit")->getFrameHeight() / 2 + 80,
		110, 200));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimStandUpRight", "kimSit", 4, 6, 60, false, false);
	KEYANIMANAGER->setCollisionRect("kimStandUpRight", RectMakeCenter(IMAGEMANAGER->findImage("kimSit")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimSit")->getFrameHeight() / 2 + 80,
		110, 200));

	KEYANIMANAGER->addCoordinateFrameAnimation("kimJumpLeft", "kimJump", 0, 7, 10, false, false);
	KEYANIMANAGER->setCollisionRect("kimJumpLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimJump")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimJump")->getFrameHeight() / 2,
		110, 300));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimJumpRight", "kimJump", 13, 7, 10, false, false);
	KEYANIMANAGER->setCollisionRect("kimJumpRight", RectMakeCenter(IMAGEMANAGER->findImage("kimJump")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimJump")->getFrameHeight() / 2,
		110, 300));

	KEYANIMANAGER->addCoordinateFrameAnimation("kimFrontJumpLeft", "kimFrontJump", 0, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("kimFrontJumpLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimFrontJump")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimFrontJump")->getFrameHeight() / 2,
		110, 250));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimFrontJumpRight", "kimFrontJump", 17, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("kimFrontJumpRight", RectMakeCenter(IMAGEMANAGER->findImage("kimFrontJump")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimFrontJump")->getFrameHeight() / 2,
		110, 250));

	KEYANIMANAGER->addCoordinateFrameAnimation("kimDashStartLeft", "kimDash", 0, 1, 30, false, false);
	KEYANIMANAGER->setCollisionRect("kimDashStartLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimDash")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimDash")->getFrameHeight() / 2 + 30,
		110, 280));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimDashLeft", "kimDash", 1, 7, 15, false, true);
	KEYANIMANAGER->setCollisionRect("kimDashLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimDash")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimDash")->getFrameHeight() / 2 + 30,
		110, 280));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimDashStopLeft", "kimDash", 7, 8, 30, false, false);
	KEYANIMANAGER->setCollisionRect("kimDashStopLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimDash")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimDash")->getFrameHeight() / 2 + 30,
		110, 280));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimDashStartRight", "kimDash", 15, 16, 30, false, false);
	KEYANIMANAGER->setCollisionRect("kimDashStartRight", RectMakeCenter(IMAGEMANAGER->findImage("kimDash")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimDash")->getFrameHeight() / 2 + 30,
		110, 280));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimDashRight", "kimDash", 14, 9, 15, false, true);
	KEYANIMANAGER->setCollisionRect("kimDashRight", RectMakeCenter(IMAGEMANAGER->findImage("kimDash")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimDash")->getFrameHeight() / 2 + 30,
		110, 280));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimDashStopRight", "kimDash", 8, 9, 30, false, false);
	KEYANIMANAGER->setCollisionRect("kimDashStopRight", RectMakeCenter(IMAGEMANAGER->findImage("kimDash")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimDash")->getFrameHeight() / 2 + 30,
		110, 280));

	int arr01[5] = { 0,1,1,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("kimBackDashLeft", "kimBackDash", arr01, sizeof(arr01) / sizeof(arr01[0]), 15, false);
	KEYANIMANAGER->setCollisionRect("kimBackDashLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimBackDash")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimBackDash")->getFrameHeight() / 2,
		110, 350));
	int arr02[5] = { 3,2,2,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("kimBackDashRight", "kimBackDash", arr02, sizeof(arr02) / sizeof(arr02[0]), 15, false);
	KEYANIMANAGER->setCollisionRect("kimBackDashRight", RectMakeCenter(IMAGEMANAGER->findImage("kimBackDash")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimBackDash")->getFrameHeight() / 2,
		110, 350));

	KEYANIMANAGER->addCoordinateFrameAnimation("kimALeft", "kimA", 0, 4, 30, false, false);
	KEYANIMANAGER->setCollisionRect("kimALeft", RectMakeCenter(IMAGEMANAGER->findImage("kimA")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimA")->getFrameHeight() / 2,
		110, 370));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimARight", "kimA", 7, 4, 30, false, false);
	KEYANIMANAGER->setCollisionRect("kimARight", RectMakeCenter(IMAGEMANAGER->findImage("kimA")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimA")->getFrameHeight() / 2,
		110, 370));

	int arr03[10] = { 0,1,2,3,4,4,5,6,7,8 };
	KEYANIMANAGER->addArrayFrameAnimation("kimBLeft", "kimB", arr03, sizeof(arr03) / sizeof(arr03[0]), 30, false);
	KEYANIMANAGER->setCollisionRect("kimBLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimB")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimB")->getFrameHeight() / 2,
		110, 370));
	int arr04[10] = { 17,16,15,14,13,13,12,11,10,9 };
	KEYANIMANAGER->addArrayFrameAnimation("kimBRight", "kimB", arr04, sizeof(arr04) / sizeof(arr04[0]), 30, false);
	KEYANIMANAGER->setCollisionRect("kimBRight", RectMakeCenter(IMAGEMANAGER->findImage("kimB")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimB")->getFrameHeight() / 2,
		110, 370));

	int arr05[12] = { 0,1,2,3,4,5,6,6,7,8,9,10 };
	KEYANIMANAGER->addArrayFrameAnimation("kimCLeft", "kimC", arr05, sizeof(arr05) / sizeof(arr05[0]), 30, false);
	KEYANIMANAGER->setCollisionRect("kimCLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimC")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimC")->getFrameHeight() / 2,
		110, 370));
	int arr06[12] = { 21,20,19,18,17,16,15,15,14,13,12,11 };
	KEYANIMANAGER->addArrayFrameAnimation("kimCRight", "kimC", arr06, sizeof(arr06) / sizeof(arr06[0]), 30, false);
	KEYANIMANAGER->setCollisionRect("kimCRight", RectMakeCenter(IMAGEMANAGER->findImage("kimC")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimC")->getFrameHeight() / 2,
		110, 370));

	KEYANIMANAGER->addCoordinateFrameAnimation("kimDLeft", "kimD", 0, 18, 30, false, false);
	KEYANIMANAGER->setCollisionRect("kimDLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimD")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimD")->getFrameHeight() / 2,
		110, 370));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimDRight", "kimD", 35, 18, 30, false, false);
	KEYANIMANAGER->setCollisionRect("kimDRight", RectMakeCenter(IMAGEMANAGER->findImage("kimD")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimD")->getFrameHeight() / 2,
		110, 370));

	int arr07[5] = { 0,1,1,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("kimHitLeft", "kimHit", arr07, sizeof(arr07) / sizeof(arr07[0]), 10, false);
	KEYANIMANAGER->setCollisionRect("kimHitLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimHit")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimHit")->getFrameHeight() / 2,
		110, 370));
	int arr08[5] = { 3,2,2,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("kimHitRight", "kimHit", arr08, sizeof(arr08) / sizeof(arr08[0]), 10, false);
	KEYANIMANAGER->setCollisionRect("kimHitRight", RectMakeCenter(IMAGEMANAGER->findImage("kimHit")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimHit")->getFrameHeight() / 2,
		110, 370));
	//------------------------------------------------------

	character::init("kim", pos, "kimIdleRight");

	_lever = _pastLever = LEVER::IDLE;
	_isLeft = false;
	_isEnemyLeft = true;

	this->changeState(kimState::IDLE);

	//this->setScale(1.0f, 1.0f);

	//콜백 함수 등록
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((kimState::Enum)msg.data);
	});
	this->addCallback("hited", [this](tagMessage msg)
	{
		this->hit();
	});

	//커맨드 등록
	int leftDouble[2] = { key::LEFT, key::LEFT };
	this->addCommand(leftDouble, 2, "leftDouble");
	int rightDouble[2] = { key::RIGHT, key::RIGHT };
	this->addCommand(rightDouble, 2, "rightDouble");

	//커맨드 메시지에 따른 콜백함수 등록
	this->addCallback("leftDouble", [this](tagMessage msg)
	{
		this->leftDouble();
	});
	this->addCallback("rightDouble", [this](tagMessage msg)
	{
		this->rightDouble();
	});

	//캐릭터 초기 능력치 설정
	this->setStatus(1000, 100);

	return S_OK;
}
void kim::release()
{
	character::release();
}
void kim::update()
{
	character::update();

	enemyPositionUpdate();
	leverPositionUpdate();
	stateUpdate(_state);
}
void kim::render()
{
	character::render();
}


void kim::enemyPositionUpdate(void)
{
	if (this->_pos.x < _enemy->_pos.x) _isEnemyLeft = false;
	else if (_enemy->_pos.x < this->_pos.x) _isEnemyLeft = true;
}
void kim::leverPositionUpdate(void)
{
	_pastLever = _lever;

	if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			_lever = LEVER::LEFTDOWN;
			return;
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::JUMP]))
		{
			_lever = LEVER::LEFTUP;
			return;
		}
		_lever = LEVER::LEFT;
		return;
	}
	if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			_lever = LEVER::RIGHTDOWN;
			return;
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::JUMP]))
		{
			_lever = LEVER::RIGHTUP;
			return;
		}
		_lever = LEVER::RIGHT;
		return;
	}
	if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
	{
		_lever = LEVER::DOWN;
		return;
	}
	if (KEYMANAGER->isStayKeyDown(keyList[key::JUMP]))
	{
		_lever = LEVER::UP;
		return;
	}
	_lever = LEVER::IDLE;
	return;
}
void kim::changeState(kimState::Enum state)
{
	attackHitbox* hitbox;
	int plusRight;
	_isLeft ? plusRight = -1 : plusRight = 1;

	switch (state)
	{
	case kimState::IDLE:
		if (_isLeft) this->setAnimation("kimIdleLeft");
		else this->setAnimation("kimIdleRight");
		break;
	case kimState::WALK_FRONT:
		if (_isLeft) this->setAnimation("kimWalkFrontLeft");
		else this->setAnimation("kimWalkFrontRight");
		break;
	case kimState::WALK_BACK:
		if (_isLeft) this->setAnimation("kimWalkBackLeft");
		else this->setAnimation("kimWalkBackRight");
		break;
	case kimState::JUMP:
		if (_isLeft) this->setAnimation("kimJumpLeft");
		else this->setAnimation("kimJumpRight");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
		jump(35);
		break;
	case kimState::JUMP_FRONT:
		if (_isLeft) this->setAnimation("kimFrontJumpLeft");
		else this->setAnimation("kimFrontJumpRight");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
		jump(35);
		break;
	case kimState::JUMP_BACK:
		if (_isLeft) this->setAnimation("kimJumpLeft");
		else this->setAnimation("kimJumpRight");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
		jump(35);
		break;
	case kimState::JUMP_DASH_FRONT:
		if (_isLeft) this->setAnimation("kimFrontJumpLeft");
		else this->setAnimation("kimFrontJumpRight");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
		jump(35);
		break;
	case kimState::JUMP_DASH_BACK:
		if (_isLeft) this->setAnimation("kimJumpLeft");
		else this->setAnimation("kimJumpRight");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
		jump(35);
		break;
	case kimState::SIT:
		if (_isLeft) this->setAnimation("kimSitLeft");
		else this->setAnimation("kimSitRight");
		break;
	case kimState::GUARD:
		break;
	case kimState::SIT_GUARD:
		break;
	case kimState::DASH_START:
		if (_isLeft) this->setAnimation("kimDashStartLeft");
		else this->setAnimation("kimDashStartRight");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::DASH));
		break;
	case kimState::DASH:
		if (_isLeft) this->setAnimation("kimDashLeft");
		else this->setAnimation("kimDashRight");
		break;
	case kimState::DASH_STOP:
		if (_isLeft) this->setAnimation("kimDashStopLeft");
		else this->setAnimation("kimDashStopRight");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
		break;
	case kimState::BACK_DASH:
		if (_isLeft) this->setAnimation("kimBackDashLeft");
		else this->setAnimation("kimBackDashRight");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
		jump(15);
		break;
	case kimState::A:
		_isLeft = _isEnemyLeft;
		if (_isLeft) this->setAnimation("kimALeft");
		else this->setAnimation("kimARight");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));

		_isLeft ? plusRight = -1 : plusRight = 1;
		hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + plusRight * 200, _pos.y - 50), vector2D(200, 50), _enemy, 0.1f);
		WORLD->addObject(hitbox);
		break;
	case kimState::B:
		_isLeft = _isEnemyLeft;
		if (_isLeft) this->setAnimation("kimBLeft");
		else this->setAnimation("kimBRight");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));

		_isLeft ? plusRight = -1 : plusRight = 1;
		hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + plusRight * 150, _pos.y - 130), vector2D(200, 50), _enemy, 0.1f);
		WORLD->addObject(hitbox);
		break;
	case kimState::C:
		_isLeft = _isEnemyLeft;
		if (_isLeft) this->setAnimation("kimCLeft");
		else this->setAnimation("kimCRight");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));

		_isLeft ? plusRight = -1 : plusRight = 1;
		hitbox = new attackHitbox;
		hitbox->init(70, vector2D(_pos.x + plusRight * 180, _pos.y - 110), vector2D(200, 50), _enemy, 0.3f);
		WORLD->addObject(hitbox);
		break;
	case kimState::D:
		_isLeft = _isEnemyLeft;
		if (_isLeft) this->setAnimation("kimDLeft");
		else this->setAnimation("kimDRight");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));

		_isLeft ? plusRight = -1 : plusRight = 1;
		hitbox = new attackHitbox;
		hitbox->init(100, vector2D(_pos.x + plusRight * 200, _pos.y - 70), vector2D(150, 300), _enemy, 0.5f);
		WORLD->addObject(hitbox);
		break;
	case kimState::HIT:
		if (_isLeft) this->setAnimation("kimHitLeft");
		else this->setAnimation("kimHitRight");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
		break;
	}

	_state = state;
}
void kim::stateUpdate(kimState::Enum state)
{
	switch (state)
	{
	case kimState::IDLE:
		switch (_lever)
		{
		case LEVER::LEFTDOWN:
		case LEVER::DOWN:
		case LEVER::RIGHTDOWN:
			changeState(kimState::SIT);
			break;
		case LEVER::LEFT:
			if (_isLeft) changeState(kimState::WALK_FRONT);
			else changeState(kimState::WALK_BACK);
			break;
		case LEVER::IDLE:
			if (_isEnemyLeft != _isLeft)
			{
				_isLeft = _isEnemyLeft;
				changeState(kimState::IDLE);
			}
			break;
		case LEVER::RIGHT:
			if (_isLeft) changeState(kimState::WALK_BACK);
			else changeState(kimState::WALK_FRONT);
			break;
		case LEVER::LEFTUP:
			if (_isLeft) changeState(kimState::JUMP_FRONT);
			else changeState(kimState::JUMP_BACK);
			break;
		case LEVER::UP:
			changeState(kimState::JUMP);
			break;
		case LEVER::RIGHTUP:
			if (_isLeft) changeState(kimState::JUMP_BACK);
			else changeState(kimState::JUMP_FRONT);
			break;
		}
		break;
	case kimState::WALK_FRONT:
		switch (_lever)
		{
		case LEVER::LEFTDOWN:
		case LEVER::DOWN:
		case LEVER::RIGHTDOWN:
			changeState(kimState::SIT);
			break;
		case LEVER::LEFT:
			_pos.x -= 8;
			if (_isLeft != _isEnemyLeft) _isLeft = _isEnemyLeft;
			if (!_isLeft) changeState(kimState::WALK_BACK);
			break;
		case LEVER::IDLE:
			changeState(kimState::IDLE);
			break;
		case LEVER::RIGHT:
			_pos.x += 8;
			if (_isLeft != _isEnemyLeft) _isLeft = _isEnemyLeft;
			if (_isLeft) changeState(kimState::WALK_BACK);
			break;
		case LEVER::LEFTUP:
			if (_isLeft) changeState(kimState::JUMP_FRONT);
			else changeState(kimState::JUMP_BACK);
			break;
		case LEVER::UP:
			changeState(kimState::JUMP);
			break;
		case LEVER::RIGHTUP:
			if (_isLeft) changeState(kimState::JUMP_BACK);
			else changeState(kimState::JUMP_FRONT);
			break;
		}
		break;
	case kimState::WALK_BACK:
		switch (_lever)
		{
		case LEVER::LEFTDOWN:
		case LEVER::DOWN:
		case LEVER::RIGHTDOWN:
			changeState(kimState::SIT);
			break;
		case LEVER::LEFT:
			_pos.x -= 8;
			if (_isLeft != _isEnemyLeft) _isLeft = _isEnemyLeft;
			if (_isLeft) changeState(kimState::WALK_FRONT);
			break;
		case LEVER::IDLE:
			changeState(kimState::IDLE);
			break;
		case LEVER::RIGHT:
			_pos.x += 8;
			if (_isLeft != _isEnemyLeft) _isLeft = _isEnemyLeft;
			if (!_isLeft) changeState(kimState::WALK_FRONT);
			break;
		case LEVER::LEFTUP:
			if (_isLeft) changeState(kimState::JUMP_FRONT);
			else changeState(kimState::JUMP_BACK);
			break;
		case LEVER::UP:
			changeState(kimState::JUMP);
			break;
		case LEVER::RIGHTUP:
			if (_isLeft) changeState(kimState::JUMP_BACK);
			else changeState(kimState::JUMP_FRONT);
			break;
		}
		break;
	case kimState::JUMP:
		break;
	case kimState::JUMP_FRONT:
		if (_isLeft) _pos.x -= 8;
		else _pos.x += 8;
		break;
	case kimState::JUMP_BACK:
		if (_isLeft) _pos.x += 8;
		else _pos.x -= 8;
		break;
	case kimState::JUMP_DASH_FRONT:
		if (_isLeft) _pos.x -= 18;
		else _pos.x += 18;
		break;
	case kimState::JUMP_DASH_BACK:
		if (_isLeft) _pos.x += 18;
		else _pos.x -= 18;
		break;
	case kimState::SIT:
		switch (_lever)
		{
		case LEVER::LEFTDOWN:
		case LEVER::DOWN:
		case LEVER::RIGHTDOWN:
			if (_isEnemyLeft != _isLeft)
			{
				_isLeft = _isEnemyLeft;
				changeState(kimState::SIT);
			}
			break;
		case LEVER::IDLE:
			_state = kimState::NONE;
			if (_isLeft) this->setAnimation("kimStandUpLeft");
			else this->setAnimation("kimStandUpRight");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
			break;
		case LEVER::LEFT:
		case LEVER::RIGHT:
		case LEVER::LEFTUP:
		case LEVER::UP:
		case LEVER::RIGHTUP:
			changeState(kimState::IDLE);
			break;
		}
		break;
	case kimState::GUARD:
		if (_lever == LEVER::IDLE) changeState(kimState::IDLE);
		break;
	case kimState::SIT_GUARD:
		if (_lever == LEVER::IDLE) changeState(kimState::IDLE);
		break;
	case kimState::DASH_START:
		if (_isLeft)
		{
			_pos.x -= 18;
		}
		else
		{
			_pos.x += 18;
		}
		break;
	case kimState::DASH:
		switch (_lever)
		{
		case LEVER::IDLE:
		case LEVER::DOWN:
		case LEVER::UP:
			changeState(kimState::DASH_STOP);
			break;
		case LEVER::LEFTUP:
			if (_isLeft) changeState(kimState::JUMP_DASH_FRONT);
			else changeState(kimState::DASH_STOP);
			break;
		case LEVER::RIGHTUP:
			if (_isLeft) changeState(kimState::DASH_STOP);
			else changeState(kimState::JUMP_DASH_FRONT);
			break;
		case LEVER::LEFT: case LEVER::LEFTDOWN:
			if (_isLeft)
			{
				_pos.x -= 18;
			}
			else
			{
				changeState(kimState::DASH_STOP);
			}
			break;
		case LEVER::RIGHT: case LEVER::RIGHTDOWN:
			if (_isLeft)
			{
				changeState(kimState::DASH_STOP);
			}
			else
			{
				_pos.x += 18;
			}
			break;
		}
		break;
	case kimState::DASH_STOP:
		break;
	case kimState::BACK_DASH:
		if (_isLeft) _pos.x += 25;
		else _pos.x -= 25;
		break;
	case kimState::A:
		break;
	case kimState::B:
		break;
	case kimState::C:
		break;
	case kimState::D:
		if (_isLeft) _pos.x -= 4;
		else _pos.x += 4;
		break;
	case kimState::HIT:
		break;
	}

	if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
	{
		switch (_state)
		{
		case kimState::IDLE:
		case kimState::WALK_FRONT:
		case kimState::WALK_BACK:
		case kimState::DASH:
		case kimState::SIT:
		case kimState::GUARD:
		case kimState::SIT_GUARD:
			changeState(kimState::A);
			break;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
	{
		switch (_state)
		{
		case kimState::IDLE:
		case kimState::WALK_FRONT:
		case kimState::WALK_BACK:
		case kimState::DASH:
		case kimState::SIT:
		case kimState::GUARD:
		case kimState::SIT_GUARD:
			changeState(kimState::B);
			break;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
	{
		switch (_state)
		{
		case kimState::IDLE:
		case kimState::WALK_FRONT:
		case kimState::WALK_BACK:
		case kimState::DASH:
		case kimState::SIT:
		case kimState::GUARD:
		case kimState::SIT_GUARD:
			changeState(kimState::C);
			break;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
	{
		switch (_state)
		{
		case kimState::IDLE:
		case kimState::WALK_FRONT:
		case kimState::WALK_BACK:
		case kimState::DASH:
		case kimState::SIT:
		case kimState::GUARD:
		case kimState::SIT_GUARD:
			changeState(kimState::D);
			break;
		}
	}
}

void kim::leftDouble(void)
{
	switch (_state)
	{
	case kimState::IDLE:
	case kimState::WALK_FRONT:
	case kimState::WALK_BACK:
		if (_isLeft) changeState(kimState::DASH_START);
		else changeState(kimState::BACK_DASH);
		break;
	}
}
void kim::rightDouble(void)
{
	switch (_state)
	{
	case kimState::IDLE:
	case kimState::WALK_FRONT:
	case kimState::WALK_BACK:
		if (_isLeft) changeState(kimState::BACK_DASH);
		else changeState(kimState::DASH_START);
		break;
	}
}
void kim::hit(void)
{
	if (_state != kimState::HIT) this->changeState(kimState::HIT);
}
