#include "stdafx.h"
#include "solbadGuy.h"
#include "attackHitbox.h"

using namespace tagSolBadGuy;

HRESULT solBadGuy::init(vector2D pos)
{
	setupResource();

	//테스트 애니메이션은 setupYuhoon에서 만든다. (게임 시작 시 최초 1번만 만들어놓고 씀)
	//character::init("위프", pos, "whip_attack_right");
	//this->changeState(tagWhip::RIGHT_STOP);

	this->setScale(4.0f, 4.0f);


	_state = tagSolBadGuy::RIGHT_STOP;

	//콜백 함수 등록
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((tagSolBadGuy::Enum)msg.data);
	});

	//커맨드 등록
	int command[4] = { key::LEFT, key::DOWN, key::RIGHT, key::ATTACK };
	this->addCommand(command, 4, "skill1");
	int command2[4] = { key::LEFT, key::DOWN, key::RIGHT, key::KICK };
	this->addCommand(command2, 4, "skill2");
	int command3[5] = { key::LEFT, key::DOWN, key::RIGHT, key::DOWN, key::ATTACK };
	this->addCommand(command3, 5, "skill3");

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
void solBadGuy::changeState(tagSolBadGuy::Enum state)
{
	//상태 변경 시 처리해줄 것들이 있으면 여기서


	///일반 움직임
	//	RIGHT_STOP, LEFT_STOP,
	//	RIGHT_MOVE, LEFT_MOVE,
	//	//RIGHT_BACK_MOVE, LEFT_BACK_MOVE,
	//	RIGHT_RUN, LEFT_RUN,
	//	RIGHT_SIT, LEFT_SIT,
	//	RIGHT_JUMP, LEFT_JUMP,
	//	RIGHT_MOVEJUMP, LEFT_MOVEJUMP,
	///일반 공격
	//	//RIGHT_WEAKHAND, LEFT_WEAKHAND,
	//	//RIGHT_WEAKFOOT, LEFT_WEAKFOOT,
	//	//RIGHT_STRONGHAND, LEFT_STRONGHAND,
	//	//RIGHT_STRONGFOOT, LEFT_STRONGFOOT,
	//	//RIGHT_SITWEAKHAND, LEFT_SITWEAKHAND,
	//	//RIGHT_SITWEAKFOOT, LEFT_SITWEAKFOOT,
	//	//RIGHT_SITSTRONGHAND, LEFT_SITSTRONGHAND,
	//	//RIGHT_SITSTRONGFOOT, LEFT_SITSTRONGFOOT,
	//	//RIGHT_JUMPHAND, LEFT_JUMPFOOT,
	///스킬, 필살기
	//	RIGHT_SKILL1, LEFT_SKILL1,
	//	RIGHT_SKILL2, LEFT_SKILL2,
	//	RIGHT_SPECIALSKILL, LEFT_SPECIALSKILL,

	switch (state)
	{
		///기본 동작
	case RIGHT_STOP:
	{			this->setAnimation("solBadGuy_stop_right");		}
	break;
	//이동
	case RIGHT_MOVE:
	{			this->setAnimation("solBadGuy_move_right");		}
	break;

	//앉기
	case RIGHT_SIT:
	{			this->setAnimation("solBadGuy_sit_right");		}
	break;
	//점프
	case RIGHT_JUMP:
	{
		this->setAnimation("solBadGuy_jump_right");
		jump(32);
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
	}
	break;
	//달리기
	case RIGHT_RUN:
	{			this->setAnimation("solBadGuy_run_right");		}
	break;

	//무브점프
	case RIGHT_MOVEJUMP:
	{			this->setAnimation("solBadGuy_moveJump_right");		}
	break;

	//일반공격
	case RIGHT_WEAKHAND:
	{
		this->setAnimation("solBadGuy_attack_right");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 350, _pos.y), vector2D(450, _pos.y), _enemy, 1.0f);
		WORLD->addObject(hitbox);
	}
	break;
	case RIGHT_WEAKFOOT:
	{
		this->setAnimation("solBadGuy_kick_right");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 150, _pos.y), vector2D(150, 100), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;
	case RIGHT_STRONGHAND:
	{
		this->setAnimation("solBadGuy_strongAttack_right");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 350, _pos.y), vector2D(450, _pos.y), _enemy, 1.0f);
		WORLD->addObject(hitbox);
	}
	break;

	case RIGHT_STRONGFOOT:
	{
		this->setAnimation("solBadGuy_strongKick_right");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 200, _pos.y - 100), vector2D(100, 100), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;
	case RIGHT_SITWEAKHAND:
	{
		this->setAnimation("solBadGuy_sitAttack_right");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));

		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x, _pos.y), vector2D(100, 100), _enemy, 0.5f);
		WORLD->addObject(hitbox);

	}
	break;
	case RIGHT_SITWEAKFOOT:
	{
		this->setAnimation("solBadGuy_sitKick_right");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x, _pos.y), vector2D(100, 100), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;
	case RIGHT_SITSTRONGHAND:
	{
		this->setAnimation("solBadGuy_sitStrongAttack_right");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x, _pos.y), vector2D(100, 100), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;
	case RIGHT_SITSTRONGFOOT:
	{
		this->setAnimation("solBadGuy_sitStrongKick_right");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x, _pos.y), vector2D(100, 100), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;
	case RIGHT_SKILL1:
	{
		this->setAnimation("위프_스킬1_오른쪽");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x + 350, _pos.y), vector2D(450, _pos.y), _enemy, 1.0f);
		WORLD->addObject(hitbox);
	}
	break;
	case RIGHT_SKILL2:
	{
		this->setAnimation("위프_스킬2_오른쪽");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SKILL2_1));
	}
	break;
	case RIGHT_SKILL2_1:
	{
		_pos.x += 500;
		_pos.y -= 200;
		this->setAnimation("위프_스킬2_오른쪽2");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x, _pos.y + 350), vector2D(200, 150), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;
	case RIGHT_SPECIALSKILL:
	{
		this->setAnimation("위프_필살기_오른쪽");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		attackHitbox* hitbox = new attackHitbox;
		hitbox->init(30, vector2D(_pos.x, _pos.y + 100), vector2D(100, 200), _enemy, 0.5f);
		WORLD->addObject(hitbox);
	}
	break;
	}

	_state = state;
}

void solBadGuy::stateUpdate(tagSolBadGuy::Enum state)
{

	switch (state)
	{
	case RIGHT_STOP:
	{

		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			this->changeState(RIGHT_MOVE);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			this->changeState(LEFT_MOVE);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(RIGHT_SIT);

		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			this->changeState(RIGHT_JUMP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			this->changeState(RIGHT_WEAKHAND);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			this->changeState(RIGHT_WEAKFOOT);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			this->changeState(RIGHT_STRONGHAND);
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			this->changeState(RIGHT_STRONGFOOT);
		}
	}
	break;
	case RIGHT_SIT:
	{
		//if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]) )
		//{
		//	this->changeState(RIGHT_STOP);
		//}
		//

		if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(RIGHT_STOP);
		}


		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			this->changeState(RIGHT_SITWEAKHAND);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			this->changeState(RIGHT_SITWEAKFOOT);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			this->changeState(RIGHT_SITSTRONGHAND);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			this->changeState(RIGHT_SITSTRONGFOOT);
		}

	}
	case RIGHT_MOVE:
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]) || KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
		{
			this->changeState(RIGHT_STOP);
		}

		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			_pos.x += 10;
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			this->changeState(LEFT_MOVE);
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			this->changeState(RIGHT_JUMP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			this->changeState(RIGHT_WEAKHAND);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			this->changeState(RIGHT_WEAKFOOT);

		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			this->changeState(RIGHT_STRONGHAND);
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			this->changeState(RIGHT_STRONGFOOT);
		}
	}
	break;
	case LEFT_MOVE:
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]) || KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
		{
			changeState(RIGHT_STOP);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			_pos.x -= 10;
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			this->changeState(RIGHT_MOVE);
		}
	}
	case RIGHT_RUN:
	{

	}
	break;
	case RIGHT_JUMP:
	{

	}
	break;
	case RIGHT_MOVEJUMP:
	{

	}
	break;
	}


}

void solBadGuy::skill1()
{
	this->changeState(RIGHT_SKILL1);
}
void solBadGuy::skill2()
{
	this->changeState(RIGHT_SKILL2);
}
void solBadGuy::skill3()
{
	this->changeState(RIGHT_SPECIALSKILL);
}


void solBadGuy::setupResource()
{



}