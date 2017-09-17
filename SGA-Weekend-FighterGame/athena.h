#pragma once
#include "stdafx.h"
#include "character.h"

namespace athenaState
{
	enum Enum
	{
		RIGHT_STOP,
		RIGHT_MOVE,
		RIGHT_HAND_ATTACK,
		RIGHT_FOOT_ATTACK,
		RIGHT_HAND_COUNT,
		RIGHT_FOOT_COUNT,
		RIGHT_JUMP,
		RIGHT_DASH,
		RIGHT_BACK_STEP,
		LEFT_STOP,
		LEFT_MOVE,
		LEFT_HAND_ATTACK,
		LEFT_FOOT_ATTACK,
		LEFT_HAND_COUNT,
		LEFT_FOOT_COUNT,
		LEFT_JUMP,
		LEFT_DASH

	};
}

class athena : public character
{
private:
	athenaState::Enum _state;

public:
	athena() {}
	virtual ~athena() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	void stateUpdate(athenaState::Enum state);
	void changeState(athenaState::Enum state);


};

