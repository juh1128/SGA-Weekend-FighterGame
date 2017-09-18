#pragma once
#include "character.h"
#include "effectFire.h"

#define NEKOSPEED				5.0		//기본 이동속도
#define NEKOSITSPEED			2.0		//앉아서 이동속도 
#define NEKOJUMPPOWER			25		//점프빠워
#define NEKOGRAVITY				0.8		//그라비티
#define NEKODASHSPEED			12.0	//대쉬 속도
#define NEKOBACKDASHSPEED		15.0	//백대쉬 속도
//s
namespace tagNekoState
{
	enum ENUM
	{
		RIGHT_STOP, LEFT_STOP,					//기본상태
		RIGHT_MOVE, LEFT_MOVE,					//이동상태
		RIGHT_JUMP, LEFT_JUMP,					//점프
		RIGHT_BACK_JUMP, LEFT_BACK_JUMP,		//백점프
		RIGHT_SIT, LEFT_SIT,					//앉기
		RIGHT_CHANGE_SIT, LEFT_CHANGE_SIT,		//앉는 모션
		RIGHT_CHANGE_UP, LEFT_CHAGNE_UP,		//일어서는 모션
		RIGHT_SIT_MOVE, LEFT_SIT_MOVE,			//앉아서 이동
		RIGHT_ATTACK, LEFT_ATTACK,				//약공	
		RIGHT_SIT_ATTACK, LEFT_SIT_ATTACK,		//앉아서 약공
		RIGHT_DEFENSE, LEFT_DEFENSE,			//막기
		RIGHT_SIT_DEFENSE, LEFT_SIT_DEFENSE,	//앉아 막기
		RIGHT_KICK, LEFT_KICK,					//발차기
		RIGHT_SIT_KICK, LEFT_SIT_KICK,			//앉아 발차기
		RIGHT_FIRE, LEFT_FIRE,					//불뿜기
		RIGHT_STAY_FIRE, LEFT_STAY_FIRE,		//불뿜고 있기
		RIGHT_FLY, LEFT_FLY,					//날기
		RIGHT_FALL, LEFT_FALL,					//떨어지는 상태
		RIGHT_DASH, LEFT_DASH,					//대쉬 상태
		RIGHT_BACK_DASH, LEFT_BACK_DASH,		//백대쉬 상태
		RIGHT_HIT, LEFT_HIT,					//쳐맞는 상태 
		RIGHT_DING, LEFT_DING,					//뒤져가는 상태					
		RIGHT_DIE, LEFT_DIE						//뒤지는 상태
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

	vector2D _centerPos;				//캐릭터 가운데 좌표

	float _bottom;						//발 좌표

	key::Enum   _saveLastKey;			//마지막에 누른 stayKeyDown 키 저장 변수 

	effectFire* _effect;


public:
	neko() {}
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


	//커맨드 함수들 
	void nekoFire();
	void nekoRightFly();
	void nekoLeftFly();

	void hit(tagMessage msg);
	void die(tagMessage msg);
	void block();
};

