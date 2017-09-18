#pragma once
#include "character.h"

namespace MAI
{
	enum state	//상태
	{
		LEFT_STOP,RIGHT_STOP,									//정지
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
		LEFT_KNOCK_DOWN_FRONT_MOVE,RIGHT_KNOCK_DOWN_FRONT_MOVE,
		LEFT_DAMAGED,RIGHT_DAMAGED,								//피해입음
		LEFT_JUMP_LEFT_MOVE,RIGHT_JUMP_LFET_MOVE,				//점프상태에서 왼쪽으로 이동
		LEFT_JUMP_RIGHT_MOVE,RIGHT_JUMP_RIGHT_MOVE,				//점프상태에서 오른쪽으로 이동
		LEFT_DEAD,RIGHT_DEAD,									//죽음
		LEFT_WIN,RIGHT_WIN,										//승리
		STATE_END												//매무리

	};

	enum POS
	{
		LEFT_SEE,RIGHT_SEE,POS_END
	};
}

using namespace MAI;
using namespace key;

#define MOVESPEED 5			//이동속도
#define LASTKEY_TIME 0.2f	//키를가지고있는 시간
#define JUMPPOWER 5			//점프파워
#define GRAVITYACCEL 0.3f	//중력가속도

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

	//현재 자신의 상태를 알수있는 이넘
	POS _posEnum;

	bool _isCharPos; //false == 왼쪽바라봄 true == 오른쪽바라봄

	Enum _lastKey;

	float _lastKeyTime; //키를 가지고있는 시간
	float _gravity; //중력


public:
	mai() {}
	virtual ~mai() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	void skill1();
	void skill2();
	void skill3();

	void stateUpdate(state);
	void changeState(state);
};

