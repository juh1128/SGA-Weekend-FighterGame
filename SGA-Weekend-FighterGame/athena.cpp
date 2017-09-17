#include "stdafx.h"
#include "athena.h"
#include "attackHitbox.h"


HRESULT athena::init(vector2D pos)
{
	character::init("athena", pos, "athenaRightStop");
	
	_state = athenaState::RIGHT_STOP;
	
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((athenaState::Enum)msg.data);
	});

	return S_OK;
}
void athena::release()
{
	character::release();
}
void athena::update()
{
	character::update();
	stateUpdate(_state);

}
void athena::render()
{
	character::render();
}

void athena::changeState(athenaState::Enum state)
{
	switch (state)
	{
	case athenaState::RIGHT_STOP:				//오른쪽 대기
		this->setAnimation("athenaRightStop");
		break;
	
	case athenaState::LEFT_STOP:				//왼쪽 대기
		this->setAnimation("athenaLeftStop");
	
	case athenaState::RIGHT_MOVE:				//오른쪽 이동
		this->setAnimation("athenaRightMove");
		break;

	case athenaState::RIGHT_BACK_STEP:			//오른쪽방향으로 뒤로 이동
		this->setAnimation("athenaRightBackStep");
	break;
	
	case athenaState::LEFT_MOVE:				//왼쪽 이동
		this->setAnimation("athenaLeftMove");
		break;
	
	case athenaState::RIGHT_JUMP:				//오른쪽 점프
		this->setAnimation("athenaRightJump");
		break;
	
	case athenaState::LEFT_JUMP:				//왼쪽 점프
		this->setAnimation("athenaLeftJump");
		break;
	
	case athenaState::RIGHT_DASH:				//오른쪽 대쉬
		this->setAnimation("athenRightDash");
		break;
	
	case athenaState::LEFT_DASH:				//왼쪽 대쉬
		this->setAnimation("athenaLeftDash");
		break;
	
	case athenaState::RIGHT_FOOT_ATTACK:
		break;
	
	case athenaState::LEFT_FOOT_ATTACK:
	
	case athenaState::RIGHT_HAND_ATTACK:
		break;
	
	case athenaState::RIGHT_FOOT_COUNT:
		break;
	
	case athenaState::RIGHT_HAND_COUNT:
		break;
	}
	
	_state = state;
}


void athena::stateUpdate(athenaState::Enum state)
{

	switch (state)
	{
	case athenaState::RIGHT_STOP:
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))				//오른쪽을보고 오른쪽키를 한번눌렀을때 (오른쪽이동으로 상태변경)
		{
			changeState(athenaState::RIGHT_MOVE);
		}
	
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))				//오른쪽을 보고 왼쪽키를 한번눌렀을때 (뒤로 백스텝)
		{
			changeState(athenaState::RIGHT_BACK_STEP);
		}
	
		break;
	
	case athenaState::RIGHT_MOVE:
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))				//오른쪽을 보고 오른쪽키를 꾹눌렀을때 (오른쪽 이동)
		{
			_pos.x += 10;
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))				//오른쪽 키를 뗐을때 (오른쪽 대기 상태변경)
		{
			changeState(athenaState::RIGHT_STOP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))				//오른쪽 이동시에 왼쪽키를 한번만 눌렀을때 (왼쪽이동 상태변경)
		{
			changeState(athenaState::LEFT_MOVE);
		}
		break;
	
	case athenaState::LEFT_MOVE: case athenaState::RIGHT_BACK_STEP:
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))				//왼쪽키를 꾹 누르고 있을때 (왼쪽으로 이동)
		{
			_pos.x -= 10;
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))				//왼쪽으로 이동중일때 오른쪽키를 한번만 눌렀을때 (오른쪽이동 상태변경)
		{
			changeState(athenaState::RIGHT_MOVE);
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))				//왼쪽키를 뗏을때 상태 (오른쪽 대기 상태변경)
		{
			changeState(athenaState::RIGHT_STOP);
		}
		break;
	
	
	case athenaState::RIGHT_JUMP:
		break;
	
	case athenaState::RIGHT_DASH:
		break;
	
	case athenaState::RIGHT_FOOT_ATTACK:
		break;
	
	case athenaState::RIGHT_HAND_ATTACK:
		break;
	
	case athenaState::RIGHT_FOOT_COUNT:
		break;
	
	case athenaState::RIGHT_HAND_COUNT:
		break;
	}
}
