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
	IMAGEMANAGER->addFrameImage("kimC", "resource/yongje/원C(7040,811,11,2).bmp", 7040, 811, 11, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimD", "resource/yongje/원D(9600,996,18,2).bmp", 9600, 996, 18, 2, true, RGB(255, 0, 255));



	KEYANIMANAGER->addCoordinateFrameAnimation("kimIdleLeft", "kimIdle", 0, 10, 22, false, true);
	//KEYANIMANAGER->setCollisionRect("kimIdleLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimIdle")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimIdle")->getFrameHeight() / 2,
	//	110, 370));
	KEYANIMANAGER->setCollisionRect("kimIdleLeft", RectMakeCenter(IMAGEMANAGER->findImage("kimIdle")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimIdle")->getFrameHeight() / 2,
		110, 600));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimIdleRight", "kimIdle", 21, 11, 22, false, true);
	//KEYANIMANAGER->setCollisionRect("kimIdleRight", RectMakeCenter(IMAGEMANAGER->findImage("kimIdle")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimIdle")->getFrameHeight() / 2,
	//	110, 370));
	KEYANIMANAGER->setCollisionRect("kimIdleRight", RectMakeCenter(IMAGEMANAGER->findImage("kimIdle")->getFrameWidth() / 2, IMAGEMANAGER->findImage("kimIdle")->getFrameHeight() / 2,
		110, 600));

	KEYANIMANAGER->addCoordinateFrameAnimation("kimWalkFrontLeft", "kimWalk", 0, 5, 12, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("kimWalkBackLeft", "kimWalk", 6, 11, 12, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("kimWalkFrontRight", "kimWalk", 17, 12, 12, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("kimWalkBackRight", "kimWalk", 23, 18, 12, false, true);

	KEYANIMANAGER->addCoordinateFrameAnimation("kimSitLeft", "kimSit", 0, 2, 60, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("kimSitRight", "kimSit", 5, 3, 60, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("kimStandUpLeft", "kimSit", 1, 0, 60, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("kimStandUpRight", "kimSit", 4, 5, 60, false, false);

	KEYANIMANAGER->addCoordinateFrameAnimation("kimJumpLeft", "kimJump", 0, 6, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("kimJumpRight", "kimJump", 13, 7, 10, false, false);

	KEYANIMANAGER->addCoordinateFrameAnimation("kimDashLeft", "kimDash", 0, 7, 15, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("kimDashRight", "kimDash", 15, 8, 15, false, true);

	KEYANIMANAGER->addCoordinateFrameAnimation("kimBackDashLeft", "kimBackDash", 0, 1, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("kimBackDashRight", "kimBackDash", 3, 2, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("kimBackDashReturnLeft", "kimBackDash", 0, 0, 1, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("kimBackDashReturnRight", "kimBackDash", 2, 2, 1, false, false);
	//------------------------------------------------------

	//테스트 애니메이션은 setupYuhoon에서 만든다. (게임 시작 시 최초 1번만 만들어놓고 씀)
	//character::init("kim", pos, "테스트_공격_오른쪽");   //뭐지;; 애니메이션 키 바꾸면 이미지 크기 작살나네
	character::init("kim", pos, "kimIdleRight");

	_lever = _pastLever = LEVER::IDLE;
	_isLeft = false;
	_isEnemyLeft = true;

	this->changeState(kimState::IDLE);

	//this->setScale(3.0f, 3.0f);

	//콜백 함수 등록
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((kimState::Enum)msg.data);
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
	EllipseMakeCenter(getMemDC(), _pos.x, _pos.y, 40, 40);
	EllipseMakeCenter(getMemDC(), _pos.x, _pos.y, 10, 10);
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
		break;
	case kimState::JUMP_BACK:
		break;
	case kimState::SIT:
		if (_isLeft) this->setAnimation("kimSitLeft");
		else this->setAnimation("kimSitRight");
		break;
	case kimState::GUARD:
		break;
	case kimState::SIT_GUARD:
		break;
	case kimState::DASH:
		if (_isLeft) this->setAnimation("kimDashLeft");
		else this->setAnimation("kimDashRight");
		break;
	case kimState::BACK_DASH:
		if (_isLeft) this->setAnimation("kimBackDashLeft");
		else this->setAnimation("kimBackDashRight");
		jump(15);
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
			changeState(kimState::SIT);
			break;
		case LEVER::DOWN:
			changeState(kimState::SIT);
			break;
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
			changeState(kimState::JUMP);
			break;
		case LEVER::UP:
			changeState(kimState::JUMP);
			break;
		case LEVER::RIGHTUP:
			changeState(kimState::JUMP);
			break;
		}
		break;
	case kimState::WALK_FRONT:
		switch (_lever)
		{
		case LEVER::LEFTDOWN:
			changeState(kimState::SIT);
			break;
		case LEVER::DOWN:
			changeState(kimState::SIT);
			break;
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
			changeState(kimState::JUMP);
			break;
		case LEVER::UP:
			changeState(kimState::JUMP);
			break;
		case LEVER::RIGHTUP:
			changeState(kimState::JUMP);
			break;
		}
		break;
	case kimState::WALK_BACK:
		switch (_lever)
		{
		case LEVER::LEFTDOWN:
			changeState(kimState::SIT);
			break;
		case LEVER::DOWN:
			changeState(kimState::SIT);
			break;
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
			changeState(kimState::JUMP);
			break;
		case LEVER::UP:
			changeState(kimState::JUMP);
			break;
		case LEVER::RIGHTUP:
			changeState(kimState::JUMP);
			break;
		}
		break;
	case kimState::JUMP:
		//jump(10);
		break;
	case kimState::JUMP_FRONT:
		break;
	case kimState::JUMP_BACK:
		break;
	case kimState::SIT:
		switch (_lever)
		{
		case LEVER::LEFTDOWN:
			break;
		case LEVER::DOWN:
			break;
		case LEVER::RIGHTDOWN:
			break;
		case LEVER::LEFT:
			changeState(kimState::IDLE);
			break;
		case LEVER::IDLE:
			_state = kimState::NONE;
			if (_isLeft) this->setAnimation("kimStandUpLeft");
			else this->setAnimation("kimStandUpRight");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
			break;
		case LEVER::RIGHT:
			changeState(kimState::IDLE);
			break;
		case LEVER::LEFTUP:
			changeState(kimState::IDLE);
			break;
		case LEVER::UP:
			changeState(kimState::IDLE);
			break;
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
	case kimState::DASH:
		switch (_lever)
		{
		case LEVER::IDLE:
		case LEVER::DOWN:
		case LEVER::LEFTUP:
		case LEVER::UP:
		case LEVER::RIGHTUP:
			changeState(kimState::IDLE);
			break;
		case LEVER::LEFT: case LEVER::LEFTDOWN:
			if (_isLeft)
			{
				_pos.x -= 15;
			}
			else
			{
				changeState(kimState::IDLE);
			}
			break;
		case LEVER::RIGHT: case LEVER::RIGHTDOWN:
			if (_isLeft)
			{
				changeState(kimState::IDLE);
			}
			else
			{
				_pos.x += 15;
			}
			break;
		}
		break;
	case kimState::BACK_DASH:
		if (_lever == LEVER::IDLE) changeState(kimState::IDLE);
		if (_isLeft) _pos.x += 18;
		else _pos.x -= 18;
		break;
	}
}

void kim::leftDouble(void)
{
	switch (_state)
	{
	case kimState::IDLE:
		if (_isLeft) changeState(kimState::DASH);
		else changeState(kimState::BACK_DASH);
		break;
	case kimState::WALK_FRONT:
		if (_isLeft) changeState(kimState::DASH);
		else changeState(kimState::BACK_DASH);
		break;
	case kimState::WALK_BACK:
		if (_isLeft) changeState(kimState::DASH);
		else changeState(kimState::BACK_DASH);
		break;
	}
}
void kim::rightDouble(void)
{
	switch (_state)
	{
	case kimState::IDLE:
		if (_isLeft) changeState(kimState::BACK_DASH);
		else changeState(kimState::DASH);
		break;
	case kimState::WALK_FRONT:
		if (_isLeft) changeState(kimState::BACK_DASH);
		else changeState(kimState::DASH);
		break;
	case kimState::WALK_BACK:
		if (_isLeft) changeState(kimState::BACK_DASH);
		else changeState(kimState::DASH);
		break;
	}
}
