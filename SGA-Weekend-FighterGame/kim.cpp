#include "stdafx.h"
#include "kim.h"
#include "attackHitbox.h"


HRESULT kim::init(vector2D pos)
{
	IMAGEMANAGER->addFrameImage("kimIdle", "resource/yongjae/서있는거(2053,796,11,2).bmp", 2053, 796, 11, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimWalk", "resource/yongjae/앞뒤이동(1365,1593,6,4).bmp", 1365, 1593, 6, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimJump", "resource/yongjae/점프(1593,1024,7,2).bmp", 1593, 1024, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimFrontJump", "resource/yongjae/앞 대점프(3072,1024,9,2).bmp", 3072, 1024, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("kimSit", "resource/yongjae/앉기(683,796,3,2).bmp", 683, 796, 3, 2, true, RGB(255, 0, 255));



	KEYANIMANAGER->addCoordinateFrameAnimation("kimIdleLeft", "kimIdle", 0, 10, 22, false, true);
	KEYANIMANAGER->setCollisionRect("kimIdleLeft", RectMakeCenter(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimIdleRight", "kimIdle", 21, 11, 22, false, true);
	KEYANIMANAGER->setCollisionRect("kimIdleRight", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("kimWalkFrontLeft", "kimWalk", 0, 5, 12, false, true);
	KEYANIMANAGER->setCollisionRect("kimWalkFrontLeft", RectMakeCenter(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimWalkBackLeft", "kimWalk", 6, 11, 12, false, true);
	KEYANIMANAGER->setCollisionRect("kimWalkBackLeft", RectMakeCenter(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimWalkFrontRight", "kimWalk", 17, 12, 12, false, true);
	KEYANIMANAGER->setCollisionRect("kimWalkFrontRight", RectMakeCenter(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimWalkBackRight", "kimWalk", 23, 18, 12, false, true);
	KEYANIMANAGER->setCollisionRect("kimWalkBackRight", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("kimSitLeft", "kimSit", 0, 2, 60, false, false);
	KEYANIMANAGER->setCollisionRect("kimSitLeft", RectMakeCenter(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimSitRight", "kimSit", 5, 3, 60, false, false);
	KEYANIMANAGER->setCollisionRect("kimSitRight", RectMakeCenter(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimStandUpLeft", "kimSit", 1, 0, 60, false, false);
	KEYANIMANAGER->setCollisionRect("kimStandUpLeft", RectMakeCenter(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimStandUpRight", "kimSit", 4, 5, 60, false, false);
	KEYANIMANAGER->setCollisionRect("kimStandUpRight", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("kimJumpLeft", "kimJump", 0, 6, 10, false, false);
	KEYANIMANAGER->setCollisionRect("kimJumpLeft", RectMakeCenter(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("kimJumpRight", "kimJump", 13, 7, 10, false, false);
	KEYANIMANAGER->setCollisionRect("kimJumpRight", RectMakeCenter(20, 10, 30, 67));
	//------------------------------------------------------

	//테스트 애니메이션은 setupYuhoon에서 만든다. (게임 시작 시 최초 1번만 만들어놓고 씀)
	//character::init("kim", pos, "테스트_공격_오른쪽");   //뭐지;; 애니메이션 키 바꾸면 이미지 크기 작살나네
	character::init("kim", pos, "kimIdleRight");
	this->changeState(kimState::IDLE);

	//this->setScale(3.0f, 3.0f);

	//콜백 함수 등록
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((kimState::Enum)msg.data);
	});

	_lever = _pastLever = LEVER::IDLE;
	enemyPositionUpdate();
	_isLeft = _isEnemyLeft;

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
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
			break;
		case LEVER::UP:
			changeState(kimState::JUMP);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
			break;
		case LEVER::RIGHTUP:
			changeState(kimState::JUMP);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
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
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
			break;
		case LEVER::UP:
			changeState(kimState::JUMP);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
			break;
		case LEVER::RIGHTUP:
			changeState(kimState::JUMP);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
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
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
			break;
		case LEVER::UP:
			changeState(kimState::JUMP);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
			break;
		case LEVER::RIGHTUP:
			changeState(kimState::JUMP);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, kimState::IDLE));
			break;
		}
		break;
	case kimState::JUMP:
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
		break;
	case kimState::SIT_GUARD:
		break;
	case kimState::DASH:
		break;
	}
}
