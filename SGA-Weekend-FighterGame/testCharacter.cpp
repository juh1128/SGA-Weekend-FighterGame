#include "stdafx.h"
#include "testCharacter.h"
#include "attackHitbox.h"


HRESULT testCharacter::init(vector2D pos)
{
	setupResource();

	//테스트 애니메이션은 setupYuhoon에서 만든다. (게임 시작 시 최초 1번만 만들어놓고 씀)
	character::init("테스트 캐릭터", pos, "테스트_공격_오른쪽");
	this->changeState(testCharacterState::RIGHT_ATTACK);

	//this->setScale(4.0f, 4.0f);
	//this->setSize(150, 300);

	//콜백 함수 등록
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((testCharacterState::Enum)msg.data);
	});


	//커맨드 등록
	int command[4] = { key::LEFT, key::JUMP, key::RIGHT, key::ATTACK };
	this->addCommand(command, 4, "skill1");
	int command2[3] = { key::RIGHT, key::RIGHT, key::ATTACK };
	this->addCommand(command2, 3, "skill2");
	int command3[4] = { key::LEFT, key::DOWN, key::RIGHT, key::ATTACK };
	this->addCommand(command3, 4, "skill3");

	//커맨드 메시지에 따른 콜백함수 등록
	this->addCallback("skill1", [this](tagMessage msg)
	{
		this->skill1();
	});
	this->addCallback("skill2", [this](tagMessage msg)
	{
		this->skill2();
	});
	this->addCallback("skill3", [this](tagMessage msg)
	{
		this->skill3();
	});

	//캐릭터 초기 능력치 설정
	this->setStatus(100, 10);


	return S_OK;
}

void testCharacter::release()	  
{
	character::release();
}

void testCharacter::update()	  
{
	character::update();

	//상태 별 업데이트 처리
	stateUpdate(_state);

}

void testCharacter::render()	  
{
	character::render();
}

void testCharacter::changeState(testCharacterState::Enum state)
{
	//상태 변경 시 처리해줄 것들이 있으면 여기서
	switch (state)
	{
		case testCharacterState::RIGHT_ATTACK:
		{
			this->setAnimation("테스트_공격_오른쪽");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, testCharacterState::RIGHT_MOVE));

			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x + 70, _pos.y), vector2D(100, 220), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;

		case testCharacterState::LEFT_ATTACK:
		{
			this->setAnimation("테스트_공격_왼쪽");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, testCharacterState::LEFT_MOVE));

			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x - 70, _pos.y), vector2D(100, 220), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;

		case testCharacterState::RIGHT_JUMP:
		break;

		case testCharacterState::LEFT_JUMP:
		break;

		case testCharacterState::RIGHT_MOVE:
		{
			this->setAnimation("테스트_이동_오른쪽");
		}
		break;

		case testCharacterState::LEFT_MOVE:
		{
			this->setAnimation("테스트_이동_왼쪽");
		}
		break;

		case testCharacterState::RIGHT_RUN:
		break;

		case testCharacterState::LEFT_RUN:
		break;

		case testCharacterState::RIGHT_JUMPATTACK:
		break;

		case testCharacterState::LEFT_JUMPATTACK:
		break;
	}
	_state = state;
}

void testCharacter::stateUpdate(testCharacterState::Enum state)
{
	switch (state)
	{
		case testCharacterState::RIGHT_ATTACK:
		{

		}
		break;

		case testCharacterState::LEFT_ATTACK:
		{

		}
		break;

		case testCharacterState::RIGHT_JUMP:
		{

		}
		break;

		case testCharacterState::LEFT_JUMP:
		{

		}
		break;

		case testCharacterState::RIGHT_MOVE:
		{
			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{
				_pos.x += 10;
			}
			if (KEYMANAGER->isStayKeyDown(keyList[key::ATTACK]))
			{
				changeState(testCharacterState::RIGHT_ATTACK);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
			{
				changeState(testCharacterState::LEFT_MOVE);
			}

			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
			{
				jump(25);
			}
		}
		break;

		case testCharacterState::LEFT_MOVE:
		{
			if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
			{
				_pos.x -= 10;
			}
			if (KEYMANAGER->isStayKeyDown(keyList[key::ATTACK]))
			{
				changeState(testCharacterState::LEFT_ATTACK);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
			{
				changeState(testCharacterState::RIGHT_MOVE);
			}
		}
		break;

		case testCharacterState::RIGHT_RUN:
		{

		}
		break;

		case testCharacterState::LEFT_RUN:
		{

		}
		break;

		case testCharacterState::RIGHT_JUMPATTACK:
		{

		}
		break;

		case testCharacterState::LEFT_JUMPATTACK:
		{

		}
		break;
	}
}


void testCharacter::skill1()
{
	cout << "스킬1 발동!" << endl;
}
void testCharacter::skill2()
{
	cout << "스킬2 발동!" << endl;
	jump(20);
}
void testCharacter::skill3()
{
	cout << "스킬3 발동!" << endl;
}





void testCharacter::setupResource()
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
}