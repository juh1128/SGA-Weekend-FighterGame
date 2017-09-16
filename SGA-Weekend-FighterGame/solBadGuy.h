#pragma once#pragma once
#include "stdafx.h"
#include "character.h"


namespace solBadGuyState
{
	enum Enum
	{
		RIGHT_MOVE, LEFT_MOVE,
		RIGHT_ATTACK, LEFT_ATTACK,
		RIGHT_JUMP, LEFT_JUMP,
		RIGHT_JUMPATTACK, LEFT_JUMPATTACK,
		RIGHT_RUN, LEFT_RUN
	};
}

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
};