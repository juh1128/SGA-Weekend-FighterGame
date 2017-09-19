#pragma once
#include "character.h"
#include "effectFire.h"


namespace tagIoriState
{
	enum Enum
	{
		RIGHT_STOP, LEFT_STOP,
		RIGHT_MOVE, LEFT_MOVE,
		RIGHT_RUN, LEFT_RUN,
		RIGHT_BACK_MOVE, LEFT_BACK_MOVE,
		RIGHT_SIT, LEFT_SIT,
		RIGHT_JUMP, LEFT_JUMP,
		ATTAK, KICK,
		STRONG_ATTACK, STRONG_KICK,
		SIT_ATTAK, SIT_KICK,
		SIT_STRONG_ATTAK, SIT_STRONG_KIKC,
		JUMP_ATTAK, JUMP_KICK,
		JUMP_STRONG_ATTAK, JUMP_STRONG_KICK,
		SKILL1, SKILL2,
		SKILL3,
		RIGHT_HIT, LEFT_HIT,
		RIGHT_DIE, LEFT_DIE
	};
}


class playGround;


class ioriYagami : public character
{
private:
	tagIoriState::Enum _state;


	float _jumpPower;
	float _gravity;

	float _startX;
	float _startY;

	bool _isEnemyDirection;

	playGround* _playGround;
	effectFire* _effect;

	bool _isJumping;

public:
	ioriYagami() {}
	virtual ~ioriYagami() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	void skill();
	void skill2();
	void skill3();
	void stateUpdate(tagIoriState::Enum _state);
	void changeState(tagIoriState::Enum _state);

	void hit(tagMessage msg);
	void die(tagMessage msg);

};

