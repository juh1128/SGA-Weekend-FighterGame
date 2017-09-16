#pragma once
#include "stdafx.h"
#include "character.h"


namespace testCharacterState
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

class testCharacter : public character
{
private:
	testCharacterState::Enum _state;

public:
	testCharacter() {}
	virtual ~testCharacter() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	void stateUpdate(testCharacterState::Enum state);
	void changeState(testCharacterState::Enum state);


	void skill1();
	void skill2();
	void skill3();
};