#pragma once
#include "character.h"

namespace NanayaState
{
	enum Enum
	{
		RIGHT_MOVE, LEFT_MOVE,
		RIGHT_ATTACK, LEFT_ATTACK,
		RIGHT_JUMP, LEFT_JUMP,
		RIGHT_JUMPATTACK, LEFT_JUMPATTACK,
		RIGHT_RUN, LEFT_RUN,
		RIGHT_STAND, LEFT_STAND,
		RIGHT_SIT, LEFT_SIT
	};
}

class Nanaya : public character
{
private:
	NanayaState::Enum _state;

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

