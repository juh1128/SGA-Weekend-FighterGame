#pragma once
#include "character.h"

namespace solBadGuyState
{
	enum Enum
	{
		//일반 움직임
		RIGHT_STOP, LEFT_STOP,
		RIGHT_MOVE, LEFT_MOVE,
		RIGHT_BACKMOVE, LEFT_BACKMOVE,
		RIGHT_RUN, LEFT_RUN,
		RIGHT_SIT, LEFT_SIT,
		RIGHT_JUMP, LEFT_JUMP,
		RIGHT_MOVEJUMP, LEFT_MOVEJUMP,
		//일반 공격
		RIGHT_WEAKHAND, LEFT_WEAKHAND,
		RIGHT_WEAKFOOT, LEFT_WEAKFOOT,
		RIGHT_STRONGHAND, LEFT_STRONGHAND,
		RIGHT_STRONGFOOT, LEFT_STRONGFOOT,
		RIGHT_SITWEAKHAND, LEFT_SITWEAKHAND,
		RIGHT_SITWEAKFOOT, LEFT_SITWEAKFOOT,
		RIGHT_SITSTRONGHAND, LEFT_SITSTRONGHAND,
		RIGHT_SITSTRONGFOOT, LEFT_SITSTRONGFOOT,
		RIGHT_JUMPHAND, LEFT_JUMPFOOT,
		//스킬, 필살기
		RIGHT_SKILL1, LEFT_SKILL1,
		RIGHT_SKILL2, LEFT_SKILL2,
		RIGHT_SKILL2_1, LEFT_SKILL2_1,
		RIGHT_SPECIALSKILL, LEFT_SPECIALSKILL,
		//막기, 맞기, 다이
		RIGHT_BLOCK, LEFT_BLOCK,
		RIGHT_HITED, LEFT_HITED,
		RIGHT_DIE, LEFT_DIE
	};
}

class playGround;

class solBadGuy : public character
{
private:
	solBadGuyState::Enum _state;

public:
	solBadGuy() {}
	virtual ~solBadGuy() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	void stateUpdate(solBadGuyState::Enum state);
	void changeState(solBadGuyState::Enum state);

	void setupResource();

	void skill1();

	void skill2();

	void skill3();


	void hited();

	void block();

	void die();

};