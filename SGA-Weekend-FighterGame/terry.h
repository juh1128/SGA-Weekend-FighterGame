#pragma once
#include "character.h"


#define TERRYSPEED		5.0		//기본 이동속도
#define TERRYJUMPPOWER	25		//점프빠워
#define TERRYGRAVITY		0.8		//그라비티


namespace tagTerryState
{
	enum Enum
	{
		RIGHT_STOP, LEFT_STOP,							//스탠딩상태
		//무브
		RIGHT_MOVE, LEFT_MOVE,							//이동 상태
		RIGHT_BACK_MOVE, LEFT_BACK_MOVE,				//뒤로 이동 상태
		RIGHT_DASH_MOVE, LEFT_DASH_MOVE,				//대쉬 이동 상태
		RIGHT_BACK_DASH, LEFT_BACK_DASH,				//백대쉬 이동 상태
		//앉기
		RIGHT_SIT, LEFT_SIT,							//앉은상태
		//점프
		RIGHT_JUMP, LEFT_JUMP,							//제자리 점프	상태
		RIGHT_MOVE_JUMP, LEFT_MOVE_JUMP,				//이동 점프		상태
		RIGHT_BACK_MOVE_JUMP, LEFT_BACK_MOVE_JUMP,		//뒤로 이동 점프 상태
		//막기
		RIGHT_DEFENCE, LEFT_DEFENCE,					//스탠딩막기 상태
		RIGHT_SIT_DEFENCE, LEFT_SIT_DEFENCE,			//앉은막기 상태
		//공격
		RIGHT_ATTACK, LEFT_ATTACK,						//약손
		RIGHT_KICK, LEFT_KICK,							//약발
		RIGHT_POWER_ATTACK, LEFT_POWER_ATTACK,			//강손
		RIGHT_POWER_KICK, LEFT_POWER_KICK				//강발
	};
}
class terry : public character
{
private :
	tagTerryState::Enum _state;

	bool _isEnemyRight;					//적 위치에 따른 제어변수

	float _jumpPower;					//점프력
	float _gravity;						//중력 
	float _savePosY;					//좌표 저장 변수
	bool  _isJump;						//점프 상태인지 제어 변수

	float _bottom;						//발 좌표

	

public:
	terry() {}
	virtual ~terry() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	//void enemyPos();
	void changeState(tagTerryState::Enum state);
	void stateUpdate(tagTerryState::Enum state);
	
};

