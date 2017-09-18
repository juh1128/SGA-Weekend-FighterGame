#pragma once
#include "character.h"


namespace kimState
{
	enum Enum
	{
		//RIGHT_MOVE, LEFT_MOVE,
		//RIGHT_ATTACK, LEFT_ATTACK,
		//RIGHT_JUMP, LEFT_JUMP,
		//RIGHT_JUMPATTACK, LEFT_JUMPATTACK,
		//RIGHT_RUN, LEFT_RUN,

		//-----------------------------

		//IDLE_LEFT, IDLE_RIGHT,
		//WALK_LEFT, WALK_RIGHT,
		//JUMP_LEFT, JUMP_RIGHT,
		//JUMP_FRONT_LEFT, JUMP_FRONT_RIGHT

		NONE,
		IDLE,
		WALK_FRONT,
		WALK_BACK,
		JUMP,
		JUMP_FRONT,
		JUMP_BACK,
		SIT,
		GUARD,
		SIT_GUARD,
		DASH
	};
}
namespace LEVER
{
	enum ENUM
	{
		LEFTDOWN = 1, DOWN, RIGHTDOWN,
		LEFT, IDLE, RIGHT,
		LEFTUP, UP, RIGHTUP
	};
}

class kim : public character
{
private:
	kimState::Enum _state;
	LEVER::ENUM _lever, _pastLever;
	bool _isLeft;
	bool _isEnemyLeft;

public:
	kim() {}
	virtual ~kim() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	void stateUpdate(kimState::Enum state);
	void changeState(kimState::Enum state);
	void enemyPositionUpdate(void);
	void leverPositionUpdate(void);
};
