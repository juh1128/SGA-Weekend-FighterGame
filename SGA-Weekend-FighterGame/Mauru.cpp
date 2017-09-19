#include "stdafx.h"
#include "Mauru.h"

//Mauru::Mauru(){}
//Mauru::~Mauru(){}

HRESULT Mauru::init(vector2D pos)
{
	IMAGEMANAGER->addFrameImage("Mauru_idle", "resource/yoonsam/Mauru/Mauru_idle_.bmp", 550, 780, 5, 6, true);
	IMAGEMANAGER->addFrameImage("Mauru_move", "resource/yoonsam/Mauru/Mauru_move_.bmp", 600, 780, 5, 6, true);
	IMAGEMANAGER->addFrameImage("Mauru_sit", "resource/yoonsam/Mauru/Mauru_sit_.bmp", 550, 580, 5, 4, true);
	IMAGEMANAGER->addFrameImage("Mauru_jump", "resource/yoonsam/Mauru/Mauru_jump_.bmp", 900, 240, 9, 2, true);
	IMAGEMANAGER->addFrameImage("Mauru_landing", "resource/yoonsam/Mauru/Mauru_landing_.bmp", 550, 480, 5, 4, true);
	IMAGEMANAGER->addFrameImage("Mauru_dash", "resource/yoonsam/Mauru/Mauru_dash_.bmp", 520, 460, 4, 4, true);
	IMAGEMANAGER->addFrameImage("Mauru_dash_stop", "resource/yoonsam/Mauru/Mauru_dash_stop_.bmp", 650, 230, 5, 2, true);
	IMAGEMANAGER->addFrameImage("Mauru_back_move", "resource/yoonsam/Mauru/Mauru_back_move_.bmp", 660, 560, 6, 4, true);
	IMAGEMANAGER->addFrameImage("Mauru_back_dash", "resource/yoonsam/Mauru/Mauru_back_dash_.bmp", 520, 460, 6, 4, true);
	IMAGEMANAGER->addFrameImage("Mauru_punch_w", "resource/yoonsam/Mauru/Mauru_punch_w_.bmp", 645, 260, 3, 2, true);
	IMAGEMANAGER->addFrameImage("Mauru_punch_s", "resource/yoonsam/Mauru/Mauru_punch_s_.bmp", 800, 600, 5, 4, true);
	IMAGEMANAGER->addFrameImage("Mauru_move_attack", "resource/yoonsam/Mauru/Mauru_move_attack_.bmp", 1540, 580, 7, 4, true);
	IMAGEMANAGER->addFrameImage("Mauru_kick_w", "resource/yoonsam/Mauru/Mauru_kick_w_.bmp", 680, 280, 4, 2, true);
	IMAGEMANAGER->addFrameImage("Mauru_kick_s", "resource/yoonsam/Mauru/Mauru_kick_s_.bmp", 850, 560, 5, 4, true);

	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_jump_Right", "Mauru_jump", 0, 8, 7, false, false);
	//KEYANIMANAGER->setCollisionRect("Mauru_jump_Right", RectMakeCenter(10, 10, 80, 110));
	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_jump_Left", "Mauru_jump", 9, 17, 7, false, false);
	//KEYANIMANAGER->setCollisionRect("Mauru_jump_Left", RectMakeCenter(10, 10, 80, 110));

	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_landing_Right", "Mauru_landing", 0, 9, 7, false, false);
	//KEYANIMANAGER->setCollisionRect("Mauru_landing_Right", RectMakeCenter(10, 10, 80, 110));
	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_landing_Left", "Mauru_landing", 10, 19, 7, false, false);
	//KEYANIMANAGER->setCollisionRect("Mauru_landing_Left", RectMakeCenter(10, 10, 80, 110));

	int Mauru0[] = { 1,2,3,4,5,6,7,6,5,4,3,2 };
	KEYANIMANAGER->addArrayFrameAnimation("Mauru_sit_Right", "Mauru_sit", Mauru0, 12, 7, true);
	KEYANIMANAGER->setCollisionRect("Mauru_sit_Right", RectMake(10, 10, 90, 128));

	int Mauru1[] = { 13,12,11,10,19,18,17,16,15,16,17,18,19,10,11,12,13};
	KEYANIMANAGER->addArrayFrameAnimation("Mauru_sit_Left", "Mauru_sit", Mauru1, 17, 7, true);
	KEYANIMANAGER->setCollisionRect("Mauru_sit_Right", RectMake(10, 10, 90, 128));

	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_idle_Right", "Mauru_idle", 0, 13, 6.5f, false, true);
	//KEYANIMANAGER->setCollisionRect("Mauru_idle_Right", RectMake(10, 10, 80, 110));
	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_idle_Left", "Mauru_idle", 15, 29, 6.5f, false, true);
	//KEYANIMANAGER->setCollisionRect("Mauru_idle_Left", RectMake(10, 10, 80, 110));

	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_move_Right", "Mauru_move", 0, 11, 12, false, true);

	int Mauru2[] = { 19,18,17,16,15,24,23,22,21,20,29,28 };
	KEYANIMANAGER->addArrayFrameAnimation("Mauru_move_Left", "Mauru_move", Mauru2, 12, 12, false);
	//KEYANIMANAGER->setCollisionRect("Mauru_move_Left", RectMakeCenter(10, 10, 80, 110));
	//KEYANIMANAGER->setCollisionRect("Mauru_move_Right", RectMakeCenter(10, 10, 80, 110));

	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_back_move_Right", "Mauru_back_move",0, 11, 12, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_back_move_Left", "Mauru_back_move", 12, 23, 12, false, true);
	KEYANIMANAGER->setCollisionRect("Mauru_back_move_Right", RectMake(10, 10, 90, 125));
	KEYANIMANAGER->setCollisionRect("Mauru_back_move_Left", RectMake(10, 10, 90, 125));

	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_jump_Right", "Mauru_jump",0, 8, 7, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_jump_Left", "Mauru_jump", 17, 9, 7, false, false);

	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_landing_Right", "Mauru_landing", 0, 9, 7, false, false);

	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_punch_w_Right", "Mauru_punch_w", 0, 2, 15, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_punch_w_Left", "Mauru_punch_w", 5, 3, 15, false, false);
	KEYANIMANAGER->setCollisionRect("Mauru_punch_w_Right", RectMake(55, 10,  90, 120));
	KEYANIMANAGER->setCollisionRect("Mauru_punch_w_Left", RectMake(55, 10, 90, 120));

	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_punch_s_Right", "Mauru_punch_s", 0, 9, 20, false, false);
	//KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_punch_s_Left","Mauru_punch_s",)
	KEYANIMANAGER->setCollisionRect("Mauru_punch_s_Right", RectMake(10, 10, 90, 120));

	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_kick_w_Right", "Mauru_kick_w", 0, 3, 15, false, false);
	KEYANIMANAGER->setCollisionRect("Mauru_kick_w_Right", RectMake(10, 10, 90, 125));

	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_kick_s_Right", "Mauru_kick_s", 0, 9, 20, false, false);

	KEYANIMANAGER->addCoordinateFrameAnimation("Mauru_dash_Right", "Mauru_dash", 0, 6, 7, false, true);

	int Mauru3[] = { 11,10,9,8,15,14,13 };
	KEYANIMANAGER->addArrayFrameAnimation("Mauru_dash_Left", "Mauru_dash", Mauru3, 7, 7, true);



//------------------------------------------------------------------------------------------------------------------

	character::init("Mauru", pos, "Mauru_idle_Right");
	this->changeState(MauruState::RIGHT_IDLE);

	this->setScale(3.0f, 3.0f);

	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((MauruState::Enum)msg.data);
	});


	int command[2] = { key::RIGHT, key::RIGHT };
	this->addCommand(command, 2, "dash");

	this->addCallback("dash", [this](tagMessage msg)
	{
		this->Dash();
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
		this->setAnimation("Mauru_back_move_Right");
	}
	break; 

	case MauruState::RIGHT_SIT:
	{
		this->setAnimation("Mauru_sit_Right");
	}
	break;

	case MauruState::LEFT_SIT:
	{
		this->setAnimation("Mauru_sit_LEFT");
	}
	break;

	case MauruState::RIGHT_JUMP:
	{
		this->setAnimation("Mauru_jump_Right");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0,MauruState::RIGHT_LANDING));
		jump(30);
	}
	break; 

	case MauruState::LEFT_JUMP:
	{
		this->setAnimation("Mauru_jump_Left");
	}
	break;

	case MauruState::RIGHT_LANDING:
	{
		this->setAnimation("Mauru_landing_Right");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, MauruState::RIGHT_IDLE));
	}
	break; 

	case MauruState::RIGHT_PUNCH_W :
	{
		this->setAnimation("Mauru_punch_w_Right");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, MauruState::RIGHT_IDLE));
	}
	break; 

	case MauruState::LEFT_PUNCH_W:
	{
		this->setAnimation("Mauru_punch_w_Left");
	}
	break; 

	case MauruState::RIGHT_PUNCH_S:
	{
		this->setAnimation("Mauru_punch_s_Right");
	}
	break; 

	case MauruState::RIGHT_KICK_W:
	{
		this->setAnimation("Mauru_kick_w_Right");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0, MauruState::RIGHT_IDLE));
	}
	break;

	case MauruState::RIGHT_KICK_S:
	{
		this->setAnimation("Mauru_kick_s_Right");
	}
	break; 

	case MauruState::RIGHT_DASH:
	{
		this->setAnimation("Mauru_dash_Right");
	}
	break; 

	}
	_state = state; 
	
}

void Mauru::stateUpdate(MauruState::Enum state)
{
	if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
	{
		changeState(MauruState::LEFT_MOVE);
	}

	if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
	{
		changeState(MauruState::RIGHT_MOVE);
	}

	switch (state)
	{
		case MauruState::RIGHT_IDLE:
		{
			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{
				changeState(MauruState::RIGHT_MOVE);
			}

			if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
			{
				changeState(MauruState::RIGHT_SIT);
			}

			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
			{
				changeState(MauruState::RIGHT_JUMP);
			}

			if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
			{
				changeState(MauruState::RIGHT_PUNCH_W);
			}

			if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
			{
				changeState(MauruState::RIGHT_PUNCH_S);
			}
			
			if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
			{
				changeState(MauruState::RIGHT_KICK_W);
			}

			if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
			{
				changeState(MauruState::RIGHT_KICK_S);
			}
			
		}
		break;

		case MauruState::RIGHT_MOVE:
		{
			if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
			{
				_pos.x += 5;
			}

			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
			{
				changeState(MauruState::RIGHT_JUMP);
			}

			if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))
			{
				changeState(MauruState::RIGHT_IDLE);
			}
			
			if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
			{
				changeState(MauruState::LEFT_MOVE);
			}

			if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
			{
				changeState(MauruState::RIGHT_SIT);
			}

			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
			{
				changeState(MauruState::RIGHT_JUMP);
			}

		}
		break;
		
		case MauruState::LEFT_MOVE:
		{
			if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
			{
				_pos.x -= 5;
			}
			if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))
			{
				changeState(MauruState::RIGHT_IDLE);
			}
			
			if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
			{
				changeState(MauruState::RIGHT_MOVE);
			}
			if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
			{
				changeState(MauruState::RIGHT_SIT);
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
			{
				changeState(MauruState::LEFT_JUMP);
			}

		}
		break;

		case MauruState::RIGHT_SIT: 
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))
			{
				changeState(MauruState::RIGHT_IDLE);
			}
		}
		break; 

		case MauruState::RIGHT_JUMP:
		{
			if(KEYMANAGER->isOnceKeyUp(keyList[key::JUMP]))
			{
				
			}
		}
		break;

		case MauruState::RIGHT_PUNCH_W:
		{
			
		}
		break;

		case MauruState::RIGHT_PUNCH_S:
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::ATTACK]))
			{
				changeState(MauruState::RIGHT_IDLE);
			}
		}
		break; 
		
		case MauruState::RIGHT_KICK_W:
		{

		}
		break; 

		case MauruState::RIGHT_DASH:
		{
			_pos.x += 10; 
		}
	}
}

void Mauru::Dash()
{
	cout << "달리는중 " << endl; 
}

//_enemy -> something  ;;; 