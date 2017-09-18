#include "stdafx.h"
#include "Mauru.h"

//Mauru::Mauru(){}
//Mauru::~Mauru(){}

HRESULT Mauru::init(vector2D pos)
{
	character::init("Mauru", pos, "Mauru_idle_Right");
	this->changeState(MauruState::RIGHT_IDLE);

	this->setScale(3.0f, 3.0f);

	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((MauruState::Enum)msg.data);
	});

	this->setStatus(300, 10);
	
	return S_OK; 
}

void Mauru::release()
{
	character::release(); 

}
void Mauru::update()
{
	character::update();

	stateUpdate(_state);
}
void Mauru::render()
{
	character::render();
}

void Mauru::changeState(MauruState::Enum state)
{
	switch (state)
	{

	case MauruState::RIGHT_IDLE:
	{
		this->setAnimation("Mauru_idle_Right");
	}
	break;

	case MauruState::LEFT_IDLE:
	{
		this->setAnimation("Mauru_idle_Left");
	}
	break; 

	case MauruState::RIGHT_MOVE:
	{
		this->setAnimation("Mauru_move_Right");
	}
	break; 

	case MauruState::LEFT_MOVE:
	{
		this->setAnimation("Mauru_move_Left");
	}
	break; 

	}
	_state = state; 
	
}

void Mauru::stateUpdate(MauruState::Enum state)
{
	switch (state)
	{
		case MauruState::RIGHT_MOVE:
		{
			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{
				_pos.x += 10;
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
			{
				changeState(MauruState::LEFT_MOVE);
			}
		}
		break;
		
		case MauruState::LEFT_MOVE:
		{
			if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
			{
				_pos.x -= 10;
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
			{
				changeState(MauruState::RIGHT_MOVE);
			}

		}
		break;

			

	}
}

