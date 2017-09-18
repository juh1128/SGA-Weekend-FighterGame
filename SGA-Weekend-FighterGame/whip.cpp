#include "stdafx.h"
#include "whip.h"
#include "attackHitbox.h"

using namespace tagWhip;

HRESULT whip::init(vector2D pos)
{
	setupResource();

	//테스트 애니메이션은 setupYuhoon에서 만든다. (게임 시작 시 최초 1번만 만들어놓고 씀)
	character::init("위프", pos, "whip_attack_right");
	//this->changeState(tagWhip::RIGHT_STOP);

	this->setScale(4.0f, 4.0f);


	_state = tagWhip::RIGHT_STOP;

	//콜백 함수 등록
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((tagWhip::Enum)msg.data);
	});


	//캐릭터 초기 능력치 설정
	this->setStatus(100, 10);


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
}
void whip::render()
{
	character::render();
}
void whip::changeState(tagWhip::Enum state)
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
		{			this->setAnimation("whip_stop_right");		}
		break;
		case LEFT_STOP:
		{			this->setAnimation("whip_stop_left");		}
		break;
		//이동
		case RIGHT_MOVE:
		{			this->setAnimation("whip_move_right");		}
		break;
		case LEFT_MOVE:
		{			this->setAnimation("whip_move_left");		}
		break;
		//앉기
		case RIGHT_SIT:
		{			this->setAnimation("whip_sit_right");		}
		break;
		case LEFT_SIT:
		{			this->setAnimation("whip_sit_left");		}
		break;
		//점프
		case RIGHT_JUMP:
		{		
			this->setAnimation("whip_jump_right");
			jump(25);
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));		
		}
		break;
		case LEFT_JUMP:
		{			this->setAnimation("whip_jump_left");		}
		//달리기
		case RIGHT_RUN:
		{			this->setAnimation("whip_run_right");		}
		break;
		case LEFT_RUN:
		{			this->setAnimation("whip_run_left");		}
		break;
		//무브점프
		case RIGHT_MOVEJUMP:
		{			this->setAnimation("whip_moveJump_right");		}
		break;
		case LEFT_MOVEJUMP:
		{			this->setAnimation("whip_moveJump_left");		}
		break;
		case RIGHT_WEAKHAND:
		{
			this->setAnimation("whip_attack_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		}
		break;
		case LEFT_WEAKHAND:
		{
			this->setAnimation("whip_attack_left");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		}
		break;
		case RIGHT_WEAKFOOT:
		{
			this->setAnimation("whip_kick_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		}
		break;
		case LEFT_WEAKFOOT:
		{
			this->setAnimation("whip_kick_left");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		}
		break;
		case RIGHT_STRONGHAND:
		{
			this->setAnimation("whip_strongAttack_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		}
		break;
		case LEFT_STRONGHAND:
		{
			this->setAnimation("whip_strongAttack_left");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		}
		break;
		case RIGHT_STRONGFOOT:
		{
			this->setAnimation("whip_strongKick_right");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		}
		break;
		case LEFT_STRONGFOOT:
		{
			this->setAnimation("whip_strongFoot_left");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));
		}
		break;

	}

	_state = state;
}

void whip::stateUpdate(tagWhip::Enum state)
{

	switch (state)
	{
		case RIGHT_STOP:
		{
			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{				this->changeState(RIGHT_MOVE);			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
			{				this->changeState(LEFT_MOVE);			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
			{				this->changeState(RIGHT_SIT);			}
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
			if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]) )
			{
				this->changeState(RIGHT_STOP);
			}
		}
		case RIGHT_MOVE:	
		{
			
			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{
					_pos.x += 10;
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
			{
				this->changeState(LEFT_MOVE);
			}

			if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]) || KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
			{
				this->changeState(RIGHT_STOP);
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


void whip::setupResource()
{
		IMAGEMANAGER->addFrameImage("테스트_이동", "resource/yuhoon/testCharacter/move.bmp", 625, 168,
		10, 2, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("테스트_이동_오른쪽", "테스트_이동", 0, 9, 15, false, true);
		KEYANIMANAGER->setCollisionRect("테스트_이동_오른쪽", RectMake(19, 9, 30, 65));


		//리소스 로드
		//일반움직임
		IMAGEMANAGER->addFrameImage("위프_정지", "resource/hyeongjoon/whip/whip_motion/whip_stop.bmp", 5427/4, 836 / 4,
			19, 2, true);
		IMAGEMANAGER->addFrameImage("위프_이동", "resource/hyeongjoon/whip/whip_motion/whip_move.bmp", 2753 / 4, 862 / 4,
			8, 2, true);
		IMAGEMANAGER->addFrameImage("위프_달리기", "resource/hyeongjoon/whip/whip_motion/whip_run.bmp", 2989/4, 794/4,
			8, 2, true);
		IMAGEMANAGER->addFrameImage("위프_앉기", "resource/hyeongjoon/whip/whip_motion/whip_sit.bmp", 2100/4, 600/4,
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
		//IMAGEMANAGER->addFrameImage("위프_앉기_약손", "resource/hyeongjoon/whip/whip_attack/whip_weakHand.bmp", 10660/4, 874/4,
		//	13, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_앉기_약발", "resource/hyeongjoon/whip/whip_attack/whip_sitWeakFoot.bmp", 4900/4, 520/4,
		//	7, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_앉기_강손", "resource/hyeongjoon/whip/whip_attack/whip_sitStrongHand.bmp", 11000/4, 1200/4,
		//	19, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_앉기_강발", "resource/hyeongjoon/whip/whip_attack/whip_sitStrongFoot.bmp", 4800/4, 520/4,
		//	6, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_점프_손", "resource/hyeongjoon/whip/whip_attack/whip_jumpHand.bmp", 2280/4, 819/4,
		//	8, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_점프_발", "resource/hyeongjoon/whip/whip_attack/whip_jumpFoot.bmp", 2850/4, 746/4,
		//	5, 2, true);
		
		////스킬1,2 + 필살기
		//IMAGEMANAGER->addFrameImage("위프_스킬1", "resource/hyeongjoon/whip/whip_skill/whip_skill1.bmp", 12430/4, 4260/4,
		//	11, 6, true);
		//IMAGEMANAGER->addFrameImage("위프_스킬2", "resource/hyeongjoon/whip/whip_skill/whip_skill2.bmp", 3300/4, 4836/4,
		//	10, 4, true);
		//IMAGEMANAGER->addFrameImage("위프_필살기", "resource/hyeongjoon/whip/whip_skill/whip_specialSkill.bmp", 12120/4, 6128/4,
		//	12, 8, true);

		//예시
		//KEYANIMANAGER->addCoordinateFrameAnimation("테스트_이동_오른쪽", "테스트_이동", 0, 9, 15, false, true);
		//KEYANIMANAGER->setCollisionRect("테스트_이동_오른쪽", RectMakeCenter(20, 10, 30, 67));

		//일반움직임
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_stop_right", "위프_정지", 0, 18, 10, true, true);
		KEYANIMANAGER->setCollisionRect("whip_stop_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_stop_left", "위프_정지", 37, 19, 10, true, true);
		KEYANIMANAGER->setCollisionRect("whip_stop_left", RectMakeCenter(35, 51, 35, 105));

		KEYANIMANAGER->addCoordinateFrameAnimation("whip_move_right", "위프_이동", 0, 7, 10, false, true);
		KEYANIMANAGER->setCollisionRect("whip_move_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_move_left", "위프_이동", 15, 8, 10, false, true);
		KEYANIMANAGER->setCollisionRect("whip_move_left", RectMakeCenter(35, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_run_right", "위프_달리기", 0, 7, 10, false, true);
		KEYANIMANAGER->setCollisionRect("whip_run_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_run_left", "위프_달리기", 15, 8, 10, false, true);
		KEYANIMANAGER->setCollisionRect("whip_run_left", RectMakeCenter(35, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sit_right", "위프_앉기", 0, 6, 10, true, true);
		KEYANIMANAGER->setCollisionRect("whip_sit_right", RectMake(35,70,35,15));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_sit_left", "위프_앉기", 13, 7, 10, true, true);
		KEYANIMANAGER->setCollisionRect("whip_sit_left", RectMake(35, 70, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_jump_right", "위프_점프", 0, 7, 10, false, false);
		KEYANIMANAGER->setCollisionRect("whip_jump_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_jump_left", "위프_점프", 15, 8, 10, false, false);
		KEYANIMANAGER->setCollisionRect("whip_jump_left", RectMakeCenter(35, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_moveJump_right", "위프_무브점프", 0, 8, 10, false, false);
		KEYANIMANAGER->setCollisionRect("whip_moveJump_right", RectMakeCenter(35, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_moveJump_left", "위프_무브점프", 17, 9, 10, false, false);
		KEYANIMANAGER->setCollisionRect("whip_moveJump_left", RectMakeCenter(35, 51, 35, 105));


		//일반공격
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_attack_right", "위프_약손", 0, 17, 10, false, false);
		KEYANIMANAGER->setCollisionRect("whip_attack_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_attack_left", "위프_약손", 35, 18, 10, false, false);
		KEYANIMANAGER->setCollisionRect("whip_attack_left", RectMakeCenter(150, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_kick_right", "위프_약발", 0, 4, 10, false, false);
		KEYANIMANAGER->setCollisionRect("whip_kick_right", RectMakeCenter(150, 51, 35, 105));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_kick_left", "위프_약발", 9, 5, 10, false, false);
		KEYANIMANAGER->setCollisionRect("whip_kick_left", RectMakeCenter(150, 51, 35, 105));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_strongAttack_right", "위프_강손", 0, 21, 10, false, false);
		KEYANIMANAGER->setCollisionRect("whip_strongAttack_right", RectMakeCenter(150, 51, 35, 140));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_strongAttack_left", "위프_강손", 43, 22, 10, false, false);
		KEYANIMANAGER->setCollisionRect("whip_strongAttack_left", RectMakeCenter(150, 51, 35, 140));
		
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_strongKick_right", "위프_강발", 0, 10, 10, false, false);
		KEYANIMANAGER->setCollisionRect("whip_strongKick_right", RectMakeCenter(150, 51, 35, 120));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_strongKick_left", "위프_강발", 21, 11, 10, false, false);
		KEYANIMANAGER->setCollisionRect("whip_strongKick_left", RectMakeCenter(150, 51, 35, 120));
		
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_앉기_약손_오른쪽", "위프_앉기_약손", 0, 12, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_앉기_약손_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_앉기_약손_왼쪽", "위프_앉기_약손", 25, 13, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_앉기_약손_왼쪽", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_앉기_약발_오른쪽", "위프_앉기_약발", 0, 6, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_앉기_약발_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_앉기_약발_왼쪽", "위프_앉기_약발", 13, 7, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_앉기_약발_왼쪽", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_앉기_강손_오른쪽", "위프_앉기_강손", 0, 18, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_앉기_강손_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_앉기_강손_왼쪽", "위프_앉기_강손", 37, 19, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_앉기_강손_왼쪽", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_앉기_강발_오른쪽", "위프_앉기_강발", 0, 5, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_앉기_강발_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_앉기_강발_왼쪽", "위프_앉기_강발", 11, 6, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_앉기_강발_왼쪽", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_점프_손_오른쪽", "위프_점프_손", 0, 7, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_점프_손_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_점프_손_왼쪽", "위프_점프_손", 15, 8, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_점프_손_왼쪽", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_점프_발_오른쪽", "위프_점프_발", 0, 4, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_점프_발_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_점프_발_왼쪽", "위프_점프_발", 9, 5, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_점프_발_왼쪽", RectMakeCenter(150, 200, 200, 400));
		//
		////스킬 
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_스킬1_오른쪽", "위프_스킬1", 0, 32, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_스킬1_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_스킬1_왼쪽", "위프_스킬1", 65, 33, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_스킬1_왼쪽", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_스킬2_오른쪽", "위프_스킬2", 0, 19, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_스킬2_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_스킬2_왼쪽", "위프_스킬2", 39, 20, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_스킬2_왼쪽", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_필살기_오른쪽", "위프_필살기", 0, 48, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_필살기_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_필살기_왼쪽", "위프_필살기", 95, 49, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_필살기_왼쪽", RectMakeCenter(150, 200, 200, 400));
	
}