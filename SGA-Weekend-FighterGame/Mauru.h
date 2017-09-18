#pragma once
#include "character.h"

namespace MauruState
{
	enum Enum
	{
		RIGHT_IDLE, LEFT_IDLE,
		RIGHT_MOVE, LEFT_MOVE,
		RIGHT_SIT, LEFT_SIT,
		RIGHT_JUMP, LEFT_JUMP,
		RIGHT_LANDING, LEFT_LANDING 
	};
}

class Mauru :public character 
{
private :
	MauruState::Enum _state;

public:
	Mauru() {} 
	virtual ~Mauru() {} 

	HRESULT init(vector2D pos);
	void release();
	void update(); 
	void render(); 

	void stateUpdate(MauruState::Enum state);
	void changeState(MauruState::Enum State);

	void skill1();
	void skill2();
	void skill3(); 

};

