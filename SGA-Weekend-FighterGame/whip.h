#pragma once
#include "character.h"

namespace tagWhip
{
	enum Enum
	{
		//일반 움직임
		RIGHT_STOP, LEFT_STOP,
		RIGHT_MOVE, LEFT_MOVE,
		//RIGHT_BACK_MOVE, LEFT_BACK_MOVE,
		RIGHT_RUN, LEFT_RUN,
		RIGHT_SIT, LEFT_SIT,
		RIGHT_JUMP, LEFT_JUMP,
		RIGHT_MOVEJUMP, LEFT_MOVEJUMP,
		//일반 공격
		//RIGHT_WEAKHAND, LEFT_WEAKHAND,
		//RIGHT_WEAKFOOT, LEFT_WEAKFOOT,
		//RIGHT_STRONGHAND, LEFT_STRONGHAND,
		//RIGHT_STRONGFOOT, LEFT_STRONGFOOT,
		//RIGHT_SITWEAKHAND, LEFT_SITWEAKHAND,
		//RIGHT_SITWEAKFOOT, LEFT_SITWEAKFOOT,
		//RIGHT_SITSTRONGHAND, LEFT_SITSTRONGHAND,
		//RIGHT_SITSTRONGFOOT, LEFT_SITSTRONGFOOT,
		//RIGHT_JUMPHAND, LEFT_JUMPFOOT,
		//스킬, 필살기
		//RIGHT_SKILL1, LEFT_SKILL1,
		//RIGHT_SKILL2, LEFT_SKILL2,
		//RIGHT_SPECIALSKILL, LEFT_SPECIALSKILL,

	};
}

class playGround;

class whip : public character
{
private:
	tagWhip::Enum _state;

public:
	whip() {}
	virtual ~whip() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	void stateUpdate(tagWhip::Enum _state);
	void changeState(tagWhip::Enum _state);

	void setupResource();
};
