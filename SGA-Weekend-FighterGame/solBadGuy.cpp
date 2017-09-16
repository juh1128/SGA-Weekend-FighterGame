#include "stdafx.h"
#include "solBadGuy.h"
#include "attackHitbox.h"


HRESULT solBadGuy::init(vector2D pos)
{
	//테스트 애니메이션은 setupYuhoon에서 만든다. (게임 시작 시 최초 1번만 만들어놓고 씀)
	character::init("테스트 캐릭터", pos, "테스트_공격_오른쪽");
	this->changeState(solBadGuyState::RIGHT_ATTACK);

	this->setScale(3.0f, 3.0f);

	//콜백 함수 등록
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((solBadGuyState::Enum)msg.data);
	});


	return S_OK;
}

void solBadGuy::release()
{
	character::release();
}

void solBadGuy::update()
{
	character::update();

	//상태 별 업데이트 처리
	stateUpdate(_state);

}

void solBadGuy::render()
{
	character::render();
}

void solBadGuy::changeState(solBadGuyState::Enum state)
{
	//상태 변경 시 처리해줄 것들이 있으면 여기서
	switch (state)
	{
	case solBadGuyState::RIGHT_ATTACK:
	{
		this->setAnimation("테스트_공격_오른쪽");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, solBadGuyState::RIGHT_MOVE));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 50, _pos.y + 30), vector2D(30, 30), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;

	case solBadGuyState::LEFT_ATTACK:
		this->setAnimation("테스트_공격_왼쪽");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, solBadGuyState::LEFT_MOVE));
		break;

	case solBadGuyState::RIGHT_JUMP:
		break;

	case solBadGuyState::LEFT_JUMP:
		break;

	case solBadGuyState::RIGHT_MOVE:
	{
		this->setAnimation("테스트_이동_오른쪽");
	}
	break;

	case solBadGuyState::LEFT_MOVE:
	{
		this->setAnimation("테스트_이동_왼쪽");
	}
	break;

	case solBadGuyState::RIGHT_RUN:
		break;

	case solBadGuyState::LEFT_RUN:
		break;

	case solBadGuyState::RIGHT_JUMPATTACK:
		break;

	case solBadGuyState::LEFT_JUMPATTACK:
		break;
	}
	_state = state;
}

void solBadGuy::stateUpdate(solBadGuyState::Enum state)
{
	switch (state)
	{
	case solBadGuyState::RIGHT_ATTACK:
	{

	}
	break;

	case solBadGuyState::LEFT_ATTACK:
	{

	}
	break;

	case solBadGuyState::RIGHT_JUMP:
	{

	}
	break;

	case solBadGuyState::LEFT_JUMP:
	{

	}
	break;

	case solBadGuyState::RIGHT_MOVE:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			_pos.x += 5;
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::ATTACK]))
		{
			changeState(solBadGuyState::RIGHT_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			changeState(solBadGuyState::LEFT_MOVE);
		}
	}
	break;

	case solBadGuyState::LEFT_MOVE:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			_pos.x -= 5;
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::ATTACK]))
		{
			changeState(solBadGuyState::LEFT_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			changeState(solBadGuyState::RIGHT_MOVE);
		}
	}
	break;

	//오른쪽 대쉬
	case solBadGuyState::RIGHT_RUN:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			_pos.x += 10;
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::ATTACK]))
		{
			changeState(solBadGuyState::RIGHT_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			changeState(solBadGuyState::LEFT_MOVE);
		}
	}
	break;

	case solBadGuyState::LEFT_RUN:
	{

	}
	break;

	case solBadGuyState::RIGHT_JUMPATTACK:
	{

	}
	break;

	case solBadGuyState::LEFT_JUMPATTACK:
	{

	}
	break;
	}
}
