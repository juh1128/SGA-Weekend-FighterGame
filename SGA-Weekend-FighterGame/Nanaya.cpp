#include "stdafx.h"
#include "Nanaya.h"
#include "attackHitbox.h"

using namespace NanayaState;

HRESULT Nanaya::init(vector2D pos)
{
	character::init("������", pos, "������_������_Idle");
	this->changeState(NanayaState::RIGHT_IDLE);

	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((NanayaState::Enum)msg.data);
	});

	return S_OK;
}

void Nanaya::release()			  
{
	character::release();
}

void Nanaya::update()			  
{
	character::update();

	stateUpdate(_state);
}

void Nanaya::render()			  
{
	character::render();
}

void Nanaya::stateUpdate(NanayaState::Enum state)
{
	switch (state)
	{
		case RIGHT_IDLE:
		{
			this->setAnimation("������_������_Idle");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, NanayaState::RIGHT_IDLE));
		}
		break;
	}
}

void Nanaya::changeState(NanayaState::Enum state)
{

}