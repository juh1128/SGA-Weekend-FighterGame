#include "stdafx.h"
#include "solBadGuy.h"
#include "attackHitbox.h"


HRESULT solBadGuy::init(vector2D pos)
{
	//리소스 로드
	IMAGEMANAGER->addFrameImage("테스트_이동", "resource/yuhoon/testCharacter/move.bmp", 625, 168,
		10, 2, true);
	IMAGEMANAGER->addFrameImage("테스트_달리기", "resource/yuhoon/testCharacter/run.bmp", 624, 126,
		8, 2, true);
	IMAGEMANAGER->addFrameImage("테스트_발차기", "resource/yuhoon/testCharacter/kick.bmp", 377, 164,
		5, 2, true);
	IMAGEMANAGER->addFrameImage("테스트_점프", "resource/yuhoon/testCharacter/jump.bmp", 207, 83,
		3, 2, true);
	IMAGEMANAGER->addFrameImage("테스트_점프공격", "resource/yuhoon/testCharacter/jump_attack.bmp", 406, 162,
		5, 2, true);
	IMAGEMANAGER->addFrameImage("테스트_공격", "resource/yuhoon/testCharacter/attack.bmp", 399, 178,
		5, 2, true);

	//애니메이션 로드
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_이동_오른쪽", "테스트_이동", 0, 9, 15, false, true);
	KEYANIMANAGER->setCollisionRect("테스트_이동_오른쪽", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_이동_왼쪽", "테스트_이동", 10, 19, 15, false, true);
	KEYANIMANAGER->setCollisionRect("테스트_이동_왼쪽", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_달리기_오른쪽", "테스트_달리기", 0, 7, 15, false, true);
	KEYANIMANAGER->setCollisionRect("테스트_달리기_오른쪽", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_달리기_왼쪽", "테스트_달리기", 8, 15, 15, false, true);
	KEYANIMANAGER->setCollisionRect("테스트_달리기_왼쪽", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_발차기_오른쪽", "테스트_발차기", 0, 4, 15, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_발차기_오른쪽", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_발차기_왼쪽", "테스트_발차기", 5, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_발차기_왼쪽", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_점프_오른쪽", "테스트_점프", 3, 5, 15, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_점프_오른쪽", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_점프_왼쪽", "테스트_점프", 0, 2, 15, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_점프_왼쪽", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_점프공격_오른쪽", "테스트_점프공격", 0, 4, 15, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_점프공격_오른쪽", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_점프공격_왼쪽", "테스트_점프공격", 5, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_점프공격_왼쪽", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_공격_오른쪽", "테스트_공격", 0, 4, 12, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_공격_오른쪽", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_공격_왼쪽", "테스트_공격", 5, 9, 12, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_공격_왼쪽", RectMake(19, 9, 30, 65));


	//테스트 애니메이션은 setupYuhoon에서 만든다. (게임 시작 시 최초 1번만 만들어놓고 씀)
	character::init("테스트 캐릭터", pos, "테스트_이동_오른쪽");
	this->changeState(solBadGuyState::RIGHT_MOVE);

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
