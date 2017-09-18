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

	//this->setScale(4.0f, 4.0f);

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
		case RIGHT_STOP:
		{
			this->setAnimation("whip_stop_right");
		}
		break;
		case tagWhip::LEFT_STOP:
		{
			this->setAnimation("whip_stop_left");
		}
		case tagWhip::RIGHT_MOVE:
		{
			this->setAnimation("whip_move_right");
		}
		break;
		case tagWhip::LEFT_JUMP:
		{
			this->setAnimation("whip_move_left");
		}

		case tagWhip::RIGHT_RUN:
		{
			this->setAnimation("위프_달리기_오른쪽");
		}
		break;
		case tagWhip::RIGHT_JUMP:
		{
			this->setAnimation("위프_점프_오른쪽");
		}
		break;
		case tagWhip::RIGHT_MOVEJUMP:
		{
			this->setAnimation("위프_무브점프_오른쪽");
		}
		break;
	}

	_state = state;
}

void whip::stateUpdate(tagWhip::Enum state)
{
	switch (state)
	{
		case tagWhip::RIGHT_STOP:
		{
			if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
			{
				this->changeState(RIGHT_MOVE);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
			{
				this->changeState(LEFT_MOVE);
			}
		}
		break;
		case tagWhip::RIGHT_MOVE:
		{
			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{
				_pos.x += 10;
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
			{
				this->changeState(LEFT_MOVE);
			}
		}
		break;
		case tagWhip::LEFT_MOVE:
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
		case tagWhip::RIGHT_RUN:
		{
			
		}
		break;
		case tagWhip::RIGHT_JUMP:
		{
			
		}
		break;
		case tagWhip::RIGHT_MOVEJUMP:
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
		IMAGEMANAGER->addFrameImage("위프_정지", "resource/hyeongjoon/whip/whip_motion/whip_stop.bmp", 5427, 836,
			19, 2, true);
		IMAGEMANAGER->addFrameImage("위프_이동", "resource/hyeongjoon/whip/whip_motion/whip_move.bmp", 2753, 862,
			8, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_달리기", "resource/hyeongjoon/whip/whip_motion/whip_run.bmp", 2989, 794,
		//	8, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_앉기", "resource/hyeongjoon/whip/whip_motion/whip_sit.bmp", 2100, 600,
		//	7, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_점프", "resource/hyeongjoon/whip/whip_motion/whip_jump.bmp", 2720, 886,
		//	8, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_무브점프", "resource/hyeongjoon/whip/whip_motion/whip_moveJump.bmp", 3102, 1188,
		//	9, 2, true);
		//일반공격 
		//IMAGEMANAGER->addFrameImage("위프_약손", "resource/hyeongjoon/whip/whip_attack/whip_weakHand.bmp", 11210, 1680,
		//	9, 4, true);
		//IMAGEMANAGER->addFrameImage("위프_약발", "resource/hyeongjoon/whip/whip_attack/whip_strongFoot.bmp", 3000, 806,
		//	5, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_강손", "resource/hyeongjoon/whip/whip_attack/whip_strongFoot.bmp", 16500, 2068,
		//	11, 4, true);
		//IMAGEMANAGER->addFrameImage("위프_강발", "resource/hyeongjoon/whip/whip_attack/whip_strongFoot.bmp", 4950, 912,
		//	11, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_앉기_약손", "resource/hyeongjoon/whip/whip_attack/whip_weakHand.bmp", 10660, 874,
		//	13, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_앉기_약발", "resource/hyeongjoon/whip/whip_attack/whip_sitWeakFoot.bmp", 4900, 520,
		//	7, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_앉기_강손", "resource/hyeongjoon/whip/whip_attack/whip_sitStrongHand.bmp", 11000, 1200,
		//	19, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_앉기_강발", "resource/hyeongjoon/whip/whip_attack/whip_sitStrongFoot.bmp", 4800, 520,
		//	6, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_점프_손", "resource/hyeongjoon/whip/whip_attack/whip_jumpHand.bmp", 2280, 819,
		//	8, 2, true);
		//IMAGEMANAGER->addFrameImage("위프_점프_발", "resource/hyeongjoon/whip/whip_attack/whip_jumpFoot.bmp", 2850, 746,
		//	5, 2, true);
		//
		////스킬1,2 + 필살기
		//IMAGEMANAGER->addFrameImage("위프_스킬1", "resource/hyeongjoon/whip/whip_skill/whip_skill1.bmp", 12430, 4260,
		//	11, 6, true);
		//IMAGEMANAGER->addFrameImage("위프_스킬2", "resource/hyeongjoon/whip/whip_skill/whip_skill2.bmp", 3300, 4836,
		//	10, 4, true);
		//IMAGEMANAGER->addFrameImage("위프_필살기", "resource/hyeongjoon/whip/whip_skill/whip_specialSkill.bmp", 12120, 6128,
		//	12, 8, true);

		//예시
		//KEYANIMANAGER->addCoordinateFrameAnimation("테스트_이동_오른쪽", "테스트_이동", 0, 9, 15, false, true);
		//KEYANIMANAGER->setCollisionRect("테스트_이동_오른쪽", RectMakeCenter(20, 10, 30, 67));

		//일반움직임
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_stop_right", "위프_정지", 0, 18, 5, true, true);
		KEYANIMANAGER->setCollisionRect("whip_stop_right", RectMakeCenter(150, 200, 200, 400));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_stop_left", "위프_정지", 37, 19, 5, true, true);
		KEYANIMANAGER->setCollisionRect("whip_stop_left", RectMakeCenter(150, 200, 200, 400));

		KEYANIMANAGER->addCoordinateFrameAnimation("whip_move_right", "위프_이동", 0, 7, 5, false, true);
		KEYANIMANAGER->setCollisionRect("whip_move_right", RectMakeCenter(150, 200, 200, 400));
		KEYANIMANAGER->addCoordinateFrameAnimation("whip_move_left", "위프_이동", 15, 8, 5, false, true);
		KEYANIMANAGER->setCollisionRect("whip_move_left", RectMakeCenter(150, 200, 200, 400));
		
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_달리기_오른쪽", "위프_달리기", 0, 7, 5, false, true);
		//KEYANIMANAGER->setCollisionRect("위프_달리기_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_달리기_왼쪽", "위프_달리기", 15, 8, 5, false, true);
		//KEYANIMANAGER->setCollisionRect("위프_달리기_왼쪽", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_앉기_오른쪽", "위프_앉기", 0, 6, 5, true, true);
		//KEYANIMANAGER->setCollisionRect("위프_앉기_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_앉기_왼쪽", "위프_앉기", 13, 7, 5, true, true);
		//KEYANIMANAGER->setCollisionRect("위프_앉기_왼쪽", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_점프_오른쪽", "위프_점프", 0, 7, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_점프_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_점프_왼쪽", "위프_점프", 15, 8, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_점프_왼쪽", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_무브점프_오른쪽", "위프_무브점프", 0, 8, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_무브점프_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_무브점프_왼쪽", "위프_무브점프", 17, 9, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_무브점프_왼쪽", RectMakeCenter(150, 200, 200, 400));


		//일반공격
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_약손_오른쪽", "위프_약손", 0, 17, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_약손_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_약손_왼쪽", "위프_약손", 35, 18, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_약손_왼쪽", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_약발_오른쪽", "위프_약발", 0, 4, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_약발_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_약발_왼쪽", "위프_약발", 9, 5, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_약발_왼쪽", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_강손_오른쪽", "위프_강손", 0, 21, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_강손_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_강손_왼쪽", "위프_강손", 43, 22, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_강손_왼쪽", RectMakeCenter(150, 200, 200, 400));
		//
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_강발_오른쪽", "위프_강발", 0, 10, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_강발_오른쪽	", RectMakeCenter(150, 200, 200, 400));
		//KEYANIMANAGER->addCoordinateFrameAnimation("위프_강발_왼쪽", "위프_강발", 21, 11, 5, false, false);
		//KEYANIMANAGER->setCollisionRect("위프_강발_왼쪽", RectMakeCenter(150, 200, 200, 400));
		//
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