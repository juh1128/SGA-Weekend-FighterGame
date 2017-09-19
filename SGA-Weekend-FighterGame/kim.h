#pragma once
#include "character.h"


namespace kimState
{
	enum Enum
	{
		NONE,
		IDLE,
		WALK_FRONT,
		WALK_BACK,
		JUMP,
		JUMP_FRONT,
		JUMP_BACK,
		JUMP_DASH_FRONT,
		JUMP_DASH_BACK,
		SIT,
		GUARD,
		SIT_GUARD,
		DASH_START,
		DASH,
		DASH_STOP,
		BACK_DASH,
		A,
		B,
		C,
		D,
		HIT
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

	void leftDouble(void);
	void rightDouble(void);
	void hit(void);
};
