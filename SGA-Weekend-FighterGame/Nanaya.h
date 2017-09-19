#pragma once
#include "character.h"

namespace NanayaState
{
	enum Enum
	{
		LEFT_STAND, RIGHT_STAND,							//서있을 때
		LEFT_STAND_WEAKATTACK, RIGHT_STAND_WEAKATTACK,		//서있을 때 약공
		LEFT_STAND_STRONGATTACK, RIGHT_STAND_STRONGATTACK,  //서있을 때 강공
		LEFT_WALK, RIGHT_WALK,								//걸을 때
		LEFT_WALKFORWARD, RIGHT_WALKFORWARD,				//앞으로 걸을 때
		LEFT_WALKBACKWARD, RIGHT_WALKBACKWARD,				//뒤로 걸을 때
		LEFT_DASH, RIGHT_DASH,								//뛸 때
		LEFT_DASHFORWARD, RIGHT_DASHFORWARD,				//앞으로 뛸 때
		LEFT_DASHBACKWARD, RIGHT_DASHBACKWARD,				//뒤로 뛸 때
		LEFT_SIT, RIGHT_SIT,								//앉을 때
		LEFT_SIT_WEAKATTACK, RIGHT_SIT_WEAKATTACK,			//앉았을 때 약공
		LEFT_SIT_STRONGATTACK, RIGHT_SIT_STRONGATTACK,		//앉았을 때 강공
		LEFT_UP, RIGHT_UP,									//앉았다 일어날 때
		LEFT_JUMP, RIGHT_JUMP,								//제자리 점프할 때
		LEFT_JUMPFORWARD, RIGHT_JUMPFORWARD,				//앞으로 점프할 때
		LEFT_JUMPBACKWARD, RIGHT_JUMPBACKWARD,				//뒤로 점프할 때
		LEFT_JUMP_WEAKATTACK, RIGHT_JUMP_WEAKATTACK,		//점프할 때 약공
		LEFT_JUMP_STRONGATTACK, RIGHT_JUMP_STRONGATTACK	//점프할 때 강공
	};
}

class Nanaya : public character
{
private:
	NanayaState::Enum _state;

	bool _isEnemyRight;					//적 위치에 따른 제어변수

	float _jumpPower;					//점프력
	float _gravity;						//중력 
	float _savePosY;					//좌표 저장 변수
	bool  _isJump;						//점프 상태인지 제어 변수

	vector2D _centerPos;				//캐릭터 가운데 좌표

	float _bottom;						//발 좌표

	key::Enum   _saveLastKey;			//마지막에 누른 stayKeyDown 키 저장 변수 

public:
	Nanaya() {}
	virtual ~Nanaya() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	void stateUpdate(NanayaState::Enum state);
	void changeState(NanayaState::Enum state);
};

