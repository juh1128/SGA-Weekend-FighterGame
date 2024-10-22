#include "stdafx.h"
#include "whip.h"
#include "attackHitbox.h"

using namespace tagWhip;

HRESULT whip::init(vector2D pos)
{
	setupResource();

	//테스트 애니메이션은 setupYuhoon에서 만든다. (게임 시작 시 최초 1번만 만들어놓고 씀)
	character::init("위프", pos, "whip_stop_right");
	//this->changeState(tagWhip::RIGHT_STOP);

	this->setScale(4.0f, 4.0f);

	_state = tagWhip::RIGHT_STOP;

	//콜백 함수 등록
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((tagWhip::Enum)msg.data);
	});

	//커맨드 등록
	int command[4] = { key::LEFT, key::DOWN, key::RIGHT, key::ATTACK };
	this->addCommand(command, 4, "skill1");
	int command2[4] = { key::LEFT, key::DOWN, key::RIGHT, key::KICK };
	this->addCommand(command2, 4, "skill2");
	int command3[5] = { key::LEFT, key::DOWN, key::RIGHT, key::DOWN, key::ATTACK };
	this->addCommand(command3, 5, "skill3");


	int command4[4] = { key::RIGHT, key::DOWN, key::LEFT, key::ATTACK };
	this->addCommand(command4, 4, "lSkill1");
	int command5[4] = { key::RIGHT, key::DOWN, key::LEFT, key::KICK };
	this->addCommand(command5, 4, "lSkill2");
	int command6[5] = { key::RIGHT, key::DOWN, key::LEFT, key::DOWN, key::ATTACK };
	this->addCommand(command6, 5, "lSkill3");


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

	this->addCallback("lSkill1", [this](tagMessage msg)
	{
		this->lSkill1();
	});
	this->addCallback("lSkill2", [this](tagMessage msg)
	{
		this->lSkill2();
	});
	this->addCallback("lSkill3", [this](tagMessage msg)
	{
		this->lSkill3();
	});



	_isEnemyDirection = true;//적이 오른쪽에 있을 때

	//캐릭터 초기 능력치 설정
	this->setStatus(1000, 50);


	//캐릭터 피격 시 콜백 등록
	this->addCallback("hited", [this](tagMessage msg)
	{
		this->hit(msg);
	});
	this->addCallback("block", [this](tagMessage msg)
	{
		this->block();
	});
	this->addCallback("die", [this](tagMessage msg)
	{
		this->die(msg);
	});


	return S_OK;
}
void whip::release()
{
	character::release();
}

void whip::update()
{
	character::update();

	//상태 별 업데이트 처리
	stateUpdate(_state);
	this->enemyDirectiion();
}
void whip::render()
{
	character::render();
}
void whip::changeState(tagWhip::Enum state)
{
	//상태 변경 시 처리해줄 것들이 있으면 여기서

	

	switch (state)
	{
		///기본 동작
		case RIGHT_STOP:
		{			this->setAnimation("whip_stop_right");		}
		break;
		//이동
		case RIGHT_MOVE:
		{			this->setAnimation("whip_move_right");		}
		break;
		//뒤로 이동
		case RIGHT_BACKMOVE:
		{
			this->setAnimation("whip_backMove_right");
		}
		break;
		//앉기
		case RIGHT_SIT:
		{			this->setAnimation("whip_sit_right");		}
		break;
		//점프
		case RIGHT_JUMP:
		{		
			this->setAnimation("whip_jump_right");
			jump(50);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));		
		}
		break;
		//달리기
		case RIGHT_RUN:
		{			this->setAnimation("whip_run_right");		}
		break;

		//무브점프
		case RIGHT_MOVEJUMP:
		{			this->setAnimation("whip_moveJump_right");		}
		break;

		//일반공격
		case RIGHT_WEAKHAND:
		{
			this->setAnimation("whip_attack_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
			
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(100, vector2D(_pos.x+350, _pos.y), vector2D(450, _pos.y), _enemy, 1.0f);
			WORLD->addObject(hitbox);
		}
		break;
		case RIGHT_WEAKFOOT:
		{
			this->setAnimation("whip_kick_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(100, vector2D(_pos.x+150, _pos.y), vector2D(150, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case RIGHT_STRONGHAND:
		{
			this->setAnimation("whip_strongAttack_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(200, vector2D(_pos.x + 350, _pos.y), vector2D(450, _pos.y), _enemy, 1.0f);
			WORLD->addObject(hitbox);
		}
		break;
	
		case RIGHT_STRONGFOOT:
		{
			this->setAnimation("whip_strongKick_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(200, vector2D(_pos.x+200, _pos.y-100), vector2D(100, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case RIGHT_SITWEAKHAND:
		{
			this->setAnimation("whip_sitAttack_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));

			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x, _pos.y), vector2D(100, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);

		}
		break;
		case RIGHT_SITWEAKFOOT:
		{
			this->setAnimation("whip_sitKick_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x, _pos.y), vector2D(100, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case RIGHT_SITSTRONGHAND:
		{
			this->setAnimation("whip_sitStrongAttack_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x, _pos.y), vector2D(100, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case RIGHT_SITSTRONGFOOT:
		{
			this->setAnimation("whip_sitStrongKick_right");
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
			hitbox->init(250, vector2D(_pos.x + 350, _pos.y), vector2D(450, _pos.y), _enemy, 1.0f);
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
			hitbox->init(250, vector2D(_pos.x, _pos.y + 350), vector2D(200, 150), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case RIGHT_SPECIALSKILL:
		{
			this->setAnimation("위프_필살기_오른쪽");


				attackHitbox* hitbox = new attackHitbox;
				hitbox->init(350, vector2D(_pos.x+300, _pos.y + 100), vector2D(300, 300), _enemy, 2.0f);
				WORLD->addObject(hitbox);
			
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
			

		}
		break;
		case RIGHT_BLOCK:
		{
			this->setAnimation("위프_막기_오른쪽");
		}
		break;
		case RIGHT_HITED:
		{
			this->setAnimation("위프_맞기_왼쪽");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		}
		break;
		case RIGHT_DIE:
		{
			this->setAnimation("위프_다이_오른쪽");
		}
		break;

		//왼쪽
		///기본 동작
		case LEFT_STOP:
		{			this->setAnimation("whip_stop_left");		}
		break;
		//이동
		case LEFT_MOVE:
		{			this->setAnimation("whip_move_left");		}
		break;
		//뒤로 이동
		case LEFT_BACKMOVE:
		{
			this->setAnimation("whip_backMove_left");
		}
		break;
		//앉기
		case LEFT_SIT:
		{			this->setAnimation("whip_sit_left");		}
		break;
		//점프
		case LEFT_JUMP:
		{
			this->setAnimation("whip_jump_left");
			jump(32);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));
		}
		break;
		//달리기
		case LEFT_RUN:
		{			this->setAnimation("whip_run_left");		}
		break;

		//무브점프
		case LEFT_MOVEJUMP:
		{			this->setAnimation("whip_moveJump_left");		}
		break;

		//일반공격
		case LEFT_WEAKHAND:
		{
			this->setAnimation("whip_attack_left");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));

			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(100, vector2D(_pos.x - 350, _pos.y), vector2D(450, _pos.y), _enemy, 1.0f);
			WORLD->addObject(hitbox);
		}
		break;
		case LEFT_WEAKFOOT:
		{
			this->setAnimation("whip_kick_left");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(100, vector2D(_pos.x - 150, _pos.y), vector2D(150, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case LEFT_STRONGHAND:
		{
			this->setAnimation("whip_strongAttack_left");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(200, vector2D(_pos.x - 350, _pos.y), vector2D(450, _pos.y), _enemy, 1.0f);
			WORLD->addObject(hitbox);
		}
		break;

		case LEFT_STRONGFOOT:
		{
			this->setAnimation("whip_strongKick_left");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(200, vector2D(_pos.x - 200, _pos.y - 100), vector2D(100, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case LEFT_SITWEAKHAND:
		{
			this->setAnimation("whip_sitAttack_left");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_SIT));

			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x, _pos.y), vector2D(100, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);

		}
		break;
		case LEFT_SITWEAKFOOT:
		{
			this->setAnimation("whip_sitKick_left");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_SIT));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x, _pos.y), vector2D(100, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case LEFT_SITSTRONGHAND:
		{
			this->setAnimation("whip_sitStrongAttack_left");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_SIT));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x, _pos.y), vector2D(100, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case LEFT_SITSTRONGFOOT:
		{
			this->setAnimation("whip_sitStrongKick_left");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_SIT));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(30, vector2D(_pos.x, _pos.y), vector2D(100, 100), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case LEFT_SKILL1:
		{
			this->setAnimation("위프_스킬1_왼쪽");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(250, vector2D(_pos.x - 350, _pos.y), vector2D(450, _pos.y), _enemy, 1.0f);
			WORLD->addObject(hitbox);
		}
		break;
		case LEFT_SKILL2:
		{
			this->setAnimation("위프_스킬2_왼쪽");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_SKILL2_1));
		}
		break;
		case LEFT_SKILL2_1:
		{
			_pos.x -= 500;
			_pos.y -= 200;
			this->setAnimation("위프_스킬2_왼쪽2");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(250, vector2D(_pos.x, _pos.y + 350), vector2D(200, 150), _enemy, 0.5f);
			WORLD->addObject(hitbox);
		}
		break;
		case LEFT_SPECIALSKILL:
		{
			this->setAnimation("위프_필살기_왼쪽");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));
			attackHitbox* hitbox = new attackHitbox;
			hitbox->init(350, vector2D(_pos.x - 300, _pos.y + 100), vector2D(300, 300), _enemy, 2.0f);
			WORLD->addObject(hitbox);
		}
		break;
		case LEFT_BLOCK:
		{
			this->setAnimation("위프_막기_왼쪽");
		}
		break;
		case LEFT_HITED:
		{
			this->setAnimation("위프_맞기_오른쪽");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));
		}
		break;
		case LEFT_DIE:
		{
			this->setAnimation("위프_다이_왼쪽");
		}
		break;
	}

	_state = state;
}



///------------------------------------------------- 상태 --------------------------------------------------
void whip::stateUpdate(tagWhip::Enum state)
{

	switch (state)
	{
		case RIGHT_STOP:
		{
			
			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{				this->changeState(RIGHT_MOVE);			}
			if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
			{				this->changeState(RIGHT_BACKMOVE);			}
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

			//적이 오른쪽에 있지 않을 때 == 내가 오른쪽에 있을 때. 
			if (!_isEnemyDirection)
			{
				this->changeState(LEFT_STOP);
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

			if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				changeState(RIGHT_STOP);
			}

			if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
			{
				changeState(RIGHT_BACKMOVE);
			}

			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{
				changeState(RIGHT_MOVE);
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
				this->changeState(RIGHT_BACKMOVE);
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

			if (_isEnemyDirection)											//상대방이 오른쪽에 있다면
			{
				if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))			//키에서 손때면
				{
					this->changeState(RIGHT_STOP);				//오른쪽 정지상태
				}
			}

			else if (!_isEnemyDirection)								//상대방이 왼쪽에 있다면
			{
				if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))		//키에서 손때면
				{
					this->changeState(LEFT_STOP);			//왼쪽 정지상태로 변환 
				}

			}
		}
		break;
		case RIGHT_BACKMOVE:
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


		///왼쪽
		case LEFT_STOP:
		{

			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{
				this->changeState(LEFT_MOVE);
			}
			if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
			{
				this->changeState(LEFT_BACKMOVE);
			}
			if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				changeState(LEFT_SIT);

			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
			{
				this->changeState(LEFT_JUMP);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
			{
				this->changeState(LEFT_WEAKHAND);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
			{
				this->changeState(LEFT_WEAKFOOT);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
			{
				this->changeState(LEFT_STRONGHAND);
			}

			if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
			{
				this->changeState(LEFT_STRONGFOOT);
			}
			if (_isEnemyDirection)
			{
				this->changeState(RIGHT_STOP);
			}





		}
		break;
		case LEFT_SIT:
		{
			//if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]) )
			//{
			//	this->changeState(LEFT_STOP);
			//}
			//
			if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
			{
				this->changeState(LEFT_SITWEAKHAND);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
			{
				this->changeState(LEFT_SITWEAKFOOT);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
			{
				this->changeState(LEFT_SITSTRONGHAND);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
			{
				this->changeState(LEFT_SITSTRONGFOOT);
			}

			if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				changeState(LEFT_STOP);
			}

			if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
			{
				changeState(LEFT_BACKMOVE);
			}

			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{
				changeState(LEFT_MOVE);
			}




		}
		case LEFT_MOVE:
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]) || KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
			{
				this->changeState(LEFT_STOP);
			}

			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{
				_pos.x += 10;
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
			{
				this->changeState(LEFT_BACKMOVE);
			}

			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
			{
				this->changeState(LEFT_JUMP);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
			{
				this->changeState(LEFT_WEAKHAND);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
			{
				this->changeState(LEFT_WEAKFOOT);

			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
			{
				this->changeState(LEFT_STRONGHAND);
			}

			if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
			{
				this->changeState(LEFT_STRONGFOOT);
			}

			if (_isEnemyDirection)											//상대방이 오른쪽에 있다면
			{
				if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))			//키에서 손때면
				{
					this->changeState(RIGHT_STOP);				//오른쪽 정지상태
				}
			}

			else if (!_isEnemyDirection)								//상대방이 왼쪽에 있다면
			{
				if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))		//키에서 손때면
				{
					this->changeState(LEFT_STOP);			//왼쪽 정지상태로 변환 
				}

			}

		}
		break;
		case LEFT_BACKMOVE:
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]) || KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
			{
				changeState(LEFT_STOP);
			}
			if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
			{
				_pos.x -= 10;
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
			{
				this->changeState(LEFT_MOVE);
			}
		}
		case LEFT_RUN:
		{

		}
		break;
		case LEFT_JUMP:
		{

		}
		break;
		case LEFT_MOVEJUMP:
		{

		}
		break;
	}


}

void whip::skill1()
{
	if (_isEnemyDirection)
	{
		this->changeState(RIGHT_SKILL1);
	}
	
}
void whip::skill2()
{
	if (_isEnemyDirection)
	{
		this->changeState(RIGHT_SKILL2);
	}
}
void whip::skill3()
{
	if (_isEnemyDirection)
	{
		this->changeState(RIGHT_SPECIALSKILL);
	}
}

void whip::lSkill1()
{
	if (!_isEnemyDirection)
	{
		this->changeState(LEFT_SKILL1);
	}

}
void whip::lSkill2()
{
	if (!_isEnemyDirection)
	{
		this->changeState(LEFT_SKILL2);
	}
}
void whip::lSkill3()
{
	if (!_isEnemyDirection)
	{
		this->changeState(LEFT_SPECIALSKILL);
	}
}








void whip::hit(tagMessage msg)
{
	tagMessage massege = msg;
	if (massege.data == DIRECTION::LEFT)
	{
		changeState(RIGHT_HITED);
	}
	else if (massege.data == DIRECTION::RIGHT)
	{
		changeState(LEFT_HITED);
	}
}

void whip::block()
{
	if (_state == RIGHT_BACKMOVE)
	{
		this->changeState(RIGHT_BLOCK);

	}
	else if (_state == LEFT_BACKMOVE)
	{
		this->changeState(LEFT_BLOCK);
	}


}
void whip::die(tagMessage msg)
{
	tagMessage message = msg;
	if (message.data == DIRECTION::RIGHT)
	{
		this->changeState(RIGHT_DIE);
	}
	else if (message.data == DIRECTION::LEFT)
	{
		this->changeState(LEFT_DIE);
	}
}

void whip::enemyDirectiion()
{
	
	//내 위치가 적의 오른쪽으로 변경되면 사용하는 조건
	if (_pos.x > _enemy->_pos.x&&_isEnemyDirection)
	{
		_isEnemyDirection = false;
	}
	else if (_pos.x < _enemy->_pos.x && !_isEnemyDirection)
	{
		_isEnemyDirection = true;
	}
}




void whip::setupResource()
{

		//리소스 로드
		//일반움직임
		IMAGEMANAGER->addFrameImage("위프_정지", "resource/hyeongjoon/whip/whip_motion/whip_stop.bmp", 5427/4, 836 / 4,
			19, 2, true);
		IMAGEMANAGER->addFrameImage("위프_이동", "resource/hyeongjoon/whip/whip_motion/whip_move.bmp", 2753 / 4, 862 / 4,
			8, 2, true);
		IMAGEMANAGER->addFrameImage("위프_달리기", "resource/hyeongjoon/whip/whip_motion/whip_run.bmp", 2989/4, 794/4,
			8, 2, true);
		IMAGEMANAGER->addFrameImage("위프_앉기", "resource/hyeongjoon/whip/whip_motion/whip_sit.bmp", 2100/4, 215,
			7, 2, true);
		IMAGEMANAGER->addFrameImage("위프_점프", "resource/hyeongjoon/whip/whip_motion/whip_jump.bmp", 680,222,
			8, 2, true);
		IMAGEMANAGER->addFrameImage("위프_무브점프", "resource/hyeongjoon/whip/whip_motion/whip_moveJump.bmp", 3102/4, 1188/4,
			9, 2, true);
		//일반공격 
		IMAGEMANAGER->addFrameImage("위프_약손", "resource/hyeongjoon/whip/whip_attack/whip_weakHand.bmp", 11210/4, 1680/4,
			9, 4, true);
		IMAGEMANAGER->addFrameImage("위프_약발", "resource/hyeongjoon/whip/whip_attack/whip_weakFoot.bmp",750, 202,
			5, 2, true);
		IMAGEMANAGER->addFrameImage("위프_강손", "resource/hyeongjoon/whip/whip_attack/whip_strongHand.bmp", 16500/4, 2068/4,
			11, 4, true);
		IMAGEMANAGER->addFrameImage("위프_강발", "resource/hyeongjoon/whip/whip_attack/whip_stongFoot.bmp", 4950/4, 912/4,
			11, 2, true);
		IMAGEMANAGER->addFrameImage("위프_앉기_약손", "resource/hyeongjoon/whip/whip_attack/whip_weakHand.bmp", 10660/4, 874/4,
			13, 2, true);
		IMAGEMANAGER->addFrameImage("위프_앉기_약발", "resource/hyeongjoon/whip/whip_attack/whip_sitWeakFoot.bmp", 4900/4, 520/4,
			7, 2, true);
		IMAGEMANAGER->addFrameImage("위프_앉기_강손", "resource/hyeongjoon/whip/whip_attack/whip_sitStrongHand.bmp", 11000/4, 1200/4,
			19, 2, true);
		IMAGEMANAGER->addFrameImage("위프_앉기_강발", "resource/hyeongjoon/whip/whip_attack/whip_sitStrongFoot.bmp", 4800/4, 520/4,
			6, 2, true);
		IMAGEMANAGER->addFrameImage("위프_점프_손", "resource/hyeongjoon/whip/whip_attack/whip_jumpHand.bmp", 2280/4, 819/4,
			8, 2, true);
		IMAGEMANAGER->addFrameImage("위프_점프_발", "resource/hyeongjoon/whip/whip_attack/whip_jumpFoot.bmp", 2850/4, 746/4,
			5, 2, true);
		
		//스킬1,2 + 필살기
		IMAGEMANAGER->addFrameImage("위프_스킬1", "resource/hyeongjoon/whip/whip_skill/whip_skill1.bmp", 12430/4, 4260/4,
			11, 6, true);
		IMAGEMANAGER->addFrameImage("위프_스킬2", "resource/hyeongjoon/whip/whip_skill/whip_skill2.bmp", 3300/4, 4836/4,
			10, 6, true);
		IMAGEMANAGER->addFrameImage("위프_필살기", "resource/hyeongjoon/whip/whip_skill/ship_specialSkill.bmp", 12120/4, 6128/4,
			12, 8, true);

		//막기, 맞기, 다이
		IMAGEMANAGER->addFrameImage("위프_막기", "resource/hyeongjoon/whip/막기.bmp", 200,100,2,1, true);
		IMAGEMANAGER->addFrameImage("위프_맞기", "resource/hyeongjoon/whip/맞기.bmp", 138,100, 2, 1, true);
		IMAGEMANAGER->addFrameImage("위프_다이", "resource/hyeongjoon/whip/다이.bmp", 256, 100, 2, 1, true);


		//예시
		//KEYANIMANAGER->addCoordinateFrameAnimation("테스트_이동_오른쪽", "테스트_이동", 0, 9, 15, false, true);
		//KEYANIMANAGER->setCollisionRect("테스트_이동_오른쪽", RectMakeCenter(20, 10, 30, 67));

		//막기, 맞기, 다이
		int rightBlock[] = { 0 };
		KEYANIMANAGER->addArrayFrameAnimation("위프_막기_오른쪽", "위프_막기", rightBlock, 1, 10, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("위프_막기_오른쪽", "위프_막기", 0, 0, 1, true, true);
		int leftBlock[] = { 1 };
		KEYANIMANAGER->addArrayFrameAnimation("위프_막기_왼쪽", "위프_막기", leftBlock, 1, 10, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("위프_막기_왼쪽", "위프_막기", 0, 0, 1, true, true);

		int rightHited[] = { 0 };
		KEYANIMANAGER->addArrayFrameAnimation("위프_맞기_오른쪽", "위프_맞기", rightHited, 1, 3, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("위프맞기_오른쪽", "위프_맞기", 0, 0, 1, true, true);
		int leftHited[] = { 1 };
		KEYANIMANAGER->addArrayFrameAnimation("위프_맞기_왼쪽", "위프_맞기", leftHited, 1, 3, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("위프_맞기_왼쪽", "위프_맞기", 0, 0, 1, true, true);

		int rightDie[] = { 0 };
		KEYANIMANAGER->addArrayFrameAnimation("위프_다이_오른쪽", "위프_다이", rightDie, 1, 10, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("위프맞기_오른쪽", "위프_다이", 0, 0, 1, true, true);
		int leftDie[] = { 1 };
		KEYANIMANAGER->addArrayFrameAnimation("위프_다이_왼쪽", "위프_다이", leftDie, 1, 10, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("위프_다이_왼쪽", "위프_다이", 0, 0, 1, true, true);

		//일반움직임
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_stop_right", "위프_정지", 0, 18, 15, true, true);
		KEYANIMANAGER->setCollisionRect("whip_stop_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_stop_left", "위프_정지", 37, 19, 15, true, true);
		KEYANIMANAGER->setCollisionRect("whip_stop_left", RectMakeCenter(35, 51, 35, 105));

		KEYANIMANAGER->addCoordinateFrameAnimation("whip_move_right", "위프_이동", 0, 7, 15, false, true);
		KEYANIMANAGER->setCollisionRect("whip_move_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_move_left", "위프_이동", 7, 0, 15, false, true);
		KEYANIMANAGER->setCollisionRect("whip_move_left", RectMakeCenter(35, 51, 35, 105));

		KEYANIMANAGER->addCoordinateFrameAnimation("whip_backMove_right", "위프_이동", 7, 0, 15, false, true);
		KEYANIMANAGER->setCollisionRect("whip_backMove_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_backMove_left", "위프_이동", 0, 7, 15, false, true);
		KEYANIMANAGER->setCollisionRect("whip_backMove_left", RectMakeCenter(35, 51, 35, 105));

		KEYANIMANAGER->addCoordinateFrameAnimation("whip_run_right", "위프_달리기", 0, 7, 15, false, true);
		KEYANIMANAGER->setCollisionRect("whip_run_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_run_left", "위프_달리기", 7, 0, 15, false, true);
		KEYANIMANAGER->setCollisionRect("whip_run_left", RectMakeCenter(35, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sit_right", "위프_앉기", 0, 6, 15, true, true);
		KEYANIMANAGER->setCollisionRect("whip_sit_right", RectMakeCenter(35, 51+15, 35, 105-30));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sit_left", "위프_앉기", 13, 7, 15, true, true);
		KEYANIMANAGER->setCollisionRect("whip_sit_left", RectMakeCenter(35, 51+15, 35, 105-30));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_jump_right", "위프_점프", 0, 7, 15, false, false);
		KEYANIMANAGER->setCollisionRect("whip_jump_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_jump_left", "위프_점프", 15, 8, 15, false, false);
		KEYANIMANAGER->setCollisionRect("whip_jump_left", RectMakeCenter(35, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_moveJump_right", "위프_무브점프", 0, 8, 15, false, false);
		KEYANIMANAGER->setCollisionRect("whip_moveJump_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_moveJump_left", "위프_무브점프", 17, 9, 15, false, false);
		KEYANIMANAGER->setCollisionRect("whip_moveJump_left", RectMakeCenter(35, 51, 35, 105));


		//일반공격
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_attack_right", "위프_약손", 0, 17, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_attack_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_attack_left", "위프_약손", 35, 18, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_attack_left", RectMakeCenter(150, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_kick_right", "위프_약발", 0, 4, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_kick_right", RectMakeCenter(75, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_kick_left", "위프_약발", 9, 5, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_kick_left", RectMakeCenter(75, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_strongAttack_right", "위프_강손", 0, 21, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_strongAttack_right", RectMakeCenter(180, 50+30, 35, 50+40));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_strongAttack_left", "위프_강손", 43, 22, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_strongAttack_left", RectMakeCenter(180, 50+30, 35, 50+40));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_strongKick_right", "위프_강발", 0, 10, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_strongKick_right", RectMakeCenter(65, 51, 35, 120));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_strongKick_left", "위프_강발", 21, 11, 20, false, false);
		KEYANIMANAGER->setCollisionRect("whip_strongKick_left", RectMakeCenter(65, 51, 35, 120));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitAttack_right", "위프_앉기_약손", 0, 12, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitAttack_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitAttack_left", "위프_앉기_약손", 25, 13, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitAttack_left", RectMakeCenter(150, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitKick_right", "위프_앉기_약발", 0, 6, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitKick_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitKick_left", "위프_앉기_약발", 13, 7, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitKick_left", RectMakeCenter(150, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitStrongAttack_right", "위프_앉기_강손", 0, 18, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitStrongAttack_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitStrongAttack_left", "위프_앉기_강손", 37, 19, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitStrongAttack_left", RectMakeCenter(150, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitStrongKick_right", "위프_앉기_강발", 0, 5, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitStrongKick_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sitStrongKick_left", "위프_앉기_강발", 11, 6, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_sitStrongKick_left", RectMakeCenter(150, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_jumpAttack_right", "위프_점프_손", 0, 7, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_jumpAttack_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_jumpAttack_left", "위프_점프_손", 15, 8, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_jumpAttack_left", RectMakeCenter(150, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_jumpKick_right", "위프_점프_발", 0, 4, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_jumpKick_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_jumpKick_left", "위프_점프_발", 9, 5, 5, false, false);
		KEYANIMANAGER->setCollisionRect("whip_jumpKick_left", RectMakeCenter(150, 51, 35, 105));
		
		////스킬 
		KEYANIMANAGER->addCoordinateFrameAnimation("위프_스킬1_오른쪽", "위프_스킬1", 0, 32, 20, false, false);
		KEYANIMANAGER->setCollisionRect("위프_스킬1_오른쪽", RectMakeCenter(160, 120, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("위프_스킬1_왼쪽", "위프_스킬1", 65, 33, 20, false, false);
		KEYANIMANAGER->setCollisionRect("위프_스킬1_왼쪽",  RectMakeCenter(160, 120, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("위프_스킬2_오른쪽", "위프_스킬2", 0, 13, 20, false, false);
		KEYANIMANAGER->setCollisionRect("위프_스킬2_오른쪽", RectMakeCenter(160, 120, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("위프_스킬2_오른쪽2", "위프_스킬2", 14, 19, 20, false, false);
		KEYANIMANAGER->setCollisionRect("위프_스킬2_오른쪽2", RectMakeCenter(160, 120, 35, 105));

		KEYANIMANAGER->addCoordinateFrameAnimation("위프_스킬2_왼쪽", "위프_스킬2", 39, 26, 20, false, false);
		KEYANIMANAGER->setCollisionRect("위프_스킬2_왼쪽", RectMakeCenter(200, 120, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("위프_스킬2_왼쪽2", "위프_스킬2", 25, 20, 20, false, false);
		KEYANIMANAGER->setCollisionRect("위프_스킬2_왼쪽2", RectMakeCenter(200, 120, 35, 105));

		
		KEYANIMANAGER->addCoordinateFrameAnimation("위프_필살기_오른쪽", "위프_필살기", 0, 48, 20, false, false);
		KEYANIMANAGER->setCollisionRect("위프_필살기_오른쪽",   RectMakeCenter(120, 140, 35, 100));
		KEYANIMANAGER->addCoordinateFrameAnimation("위프_필살기_왼쪽", "위프_필살기", 95, 49, 5, false, false);
		KEYANIMANAGER->setCollisionRect("위프_필살기_왼쪽",   RectMakeCenter(120, 140, 35, 100));
	
}