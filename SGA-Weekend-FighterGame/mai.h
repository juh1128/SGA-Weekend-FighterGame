#pragma once
#include "character.h"

namespace MAI
{
	enum state	//상태
	{
		LEFT_IDLE,RIGHT_IDLE,									//정지
		LEFT_MOVE,RIGHT_MOVE,									//앞으로이동
		LEFT_JUMP,RIGHT_JUMP,									//점프
		LEFT_BACK_MOVE,RIGHT_BACK_MOVE,							//뒤로이동
		LEFT_SIT,RIGHT_SIT,										//앉기
		LEFT_PUNCH,RIGHT_PUNCH,									//약공
		LEFT_STRONG_PUNCH,RIGHT_STRONG_PUNCH,					//강공
		LEFT_KICK,RIGHT_KICK,									//약발
		LEFT_STRONG_KICK,RIGHT_STRONG_KICK,						//강발
		LEFT_SIT_PUNCH,RIGHT_SIT_PUNCH,							//앉아서약공
		LEFT_SIT_KICK,RIGHT_SIT_KICK,							//앉아서약발
		LEFT_SIT_STRONG_PUNCH,RIGHT_SIT_STRONG_PUNCH,			//앉아서강공
		LEFT_SIT_STRONG_KICK,RIGHT_SIT_STRONG_KICK,				//앉아서강발
		LEFT_DEFENCE,RIGHT_DEFENCE,								//방어
		LEFT_SIT_DEFENCE,RIGHT_SIT_DEFENCE,						//앉아서방어
		LEFT_DASH,RIGHT_DASH,									//대쉬
		LEFT_BACK_DASH,RIGHT_BACK_DASH,							//뒤로대쉬
		LEFT_KNOCK_DOWN,RIGHT_KNOCK_DOWN,						//쓰러짐
		LEFT_KNOCK_DOWN_BACK_MOVE,RIGHT_KNOCK_DOWN_BACK_MOVE,	//쓰러진상태에서뒤로이동
		LEFT_DAMAGED,RIGHT_DAMAGED,								//피해입음
		STATE_END												//매무리

	};
}

using namespace MAI;
using namespace key;

#define MOVESPEED 5

class playGround;

class mai : public character
{
private:
	//상태이넘
	state _state;
	//키 이넘
	Enum _enum;
	//전방선언플레이그라운드
	playGround* _playGround;


public:
	mai() {}
	virtual ~mai() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	void stateUpdate(state);
	void changeState(state);
};

