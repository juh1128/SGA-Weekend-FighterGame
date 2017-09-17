#pragma once
#include "character.h"

#define NEKOSPEED		5.0		//기본 이동속도
#define NEKOSITSPEED	2.0		//앉아서 이동속도 
#define NEKOJUMPPOWER	25		//점프빠워
#define NEKOGRAVITY		0.8		//그라비티

namespace tagNekoState
{
	enum ENUM
	{
		RIGHT_STOP, LEFT_STOP,				//기본상태
		RIGHT_MOVE, LEFT_MOVE,				//이동상태
		RIGHT_JUMP, LEFT_JUMP,				//점프
		RIGHT_SIT, LEFT_SIT,				//앉기
		RIGHT_CHANGE_SIT, LEFT_CHANGE_SIT,	//앉는 모션
		RIGHT_CHANGE_UP , LEFT_CHAGNE_UP,	//일어서는 모션
		RIGHT_SIT_MOVE , LEFT_SIT_MOVE		//앉아서 이동
	};
}

using namespace tagNekoState;
using namespace key;

class neko : public character
{
private:
	tagNekoState::ENUM	_state;			//상태처리 enum 변수 

	bool _isEnemyRight;					//적 위치에 따른 제어변수

	float _jumpPower;					//점프력
	float _gravity;						//중력 
	float _savePosY;					//좌표 저장 변수
	bool  _isJump;						//점프 상태인지 제어 변수

	key::Enum   _saveLastKey;			//마지막에 누른 stayKeyDown 키 저장 변수 


public:
	neko()  {}
	virtual ~neko() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	void stateUpdate(tagNekoState::ENUM state);
	void changeState(tagNekoState::ENUM state);

	void enemyPos();

	void jumping();
	void setJump()
	{
		if (_isJump) return;
		_isJump = true;
		_savePosY = this->_pos.y;
		_gravity = NEKOGRAVITY;
		_jumpPower = NEKOJUMPPOWER;
	}
};

