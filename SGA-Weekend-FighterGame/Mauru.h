#pragma once
#include "character.h"

namespace MauruState
{
	enum Enum
	{
		RIGHT_IDLE, LEFT_IDLE,
		RIGHT_MOVE, LEFT_MOVE,
		RIGHT_DASH, LEFT_DASH,
		RIGHT_DASHSTOP, LEFT_DASHSTOP,
		RIGHT_SIT, LEFT_SIT,
		RIGHT_JUMP,LEFT_JUMP,
		RIGHT_PUNCH_W , LEFT_PUNCH_W ,
		RIGHT_PUNCH_S , LEFT_PUNCH_S , 
		RIGHT_KICK_W , LEFT_KICK_W , 
		RIGHT_KICK_S , LEFT_KICK_S 
		
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

	//void Dash(); 
	void skill1();
	void skill2();
	void skill3(); 

};

