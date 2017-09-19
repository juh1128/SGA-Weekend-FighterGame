#include "stdafx.h"
#include "Nanaya.h"
#include "attackHitbox.h"

HRESULT Nanaya::init(vector2D pos)
{
	//이미지 로드
	IMAGEMANAGER->addFrameImage("Nanaya_Select", "resource/youngjae/Nanaya/Nanaya_Select", 2304, 512, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Nanaya_Stand", "resource/youngjae/Nanaya/Nanaya_Stand", 4096, 512, 16, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Nanaya_WalkForward", "resource/youngjae/Nanaya/Nanaya_WalkForward", 3072, 512, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Nanaya_WalkBackward", "resouce/youngjae/Nanaya/Nanaya_WalkBackward", 4352, 512, 17, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Nanaya_SitAndUp", "resource/youngjae/Nanaya/Nanaya_SitAndUp", 2560, 512, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Nanaya_StandWeakAttack", "resource/youngjae/Nanaya/Nanaya_StandWeakAttack", 1280, 512, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("NNanaya_StandStrongAttack", "resource/youngjae/Nanaya/Nanaya_StandStrongAttack", 4864, 512, 19, 2, true, RGB(255, 0, 255));

	//키애니매니저 설정

	//서있을 시
	KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_Stand", "Nanaya_Stand", 0, 15, 8, true, true);
	KEYANIMANAGER->setCollisionRect("Nanaya_Left_Stand", RectMake(670, 409, 759, 659));

	KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_Stand", "Nanaya_Stand", 31, 16, 8, true, true);
	KEYANIMANAGER->setCollisionRect("Nanaya_Right_Stand", RectMake(670, 409, 759, 659));

	//앞으로 걸을 때
	KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_WalkForward", "Nanaya_WalkForward", 0, 11, 8, false, true);
	KEYANIMANAGER->setCollisionRect("Nanaya_Left_WalkForward", RectMake(670, 409, 759, 659));

	KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_WalkForward", "Nanaya_WalkForward", 23, 12, 8, false, true);
	KEYANIMANAGER->setCollisionRect("Nanaya_Right_WalkForward", RectMake(670, 409, 759, 659));

	//뒤로 걸을 때
	KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_WalkBackward", "Nanaya_WalkBackward", 0, 16, 8, false, true);
	KEYANIMANAGER->setCollisionRect("Nanaya_Left_WalkBackward", RectMake(670, 409, 759, 659));

	KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_WalkBackward", "Nanaya_WalkBackward", 33, 17, 8, false, true);
	KEYANIMANAGER->setCollisionRect("Nanaya_Right_WalkBackWard", RectMake(670, 409, 759, 659));

	//앉았을 때
	KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_Sit", "Nanaya_SitAndUp", 0, 4, 8, false, true);
	KEYANIMANAGER->setCollisionRect("Nanaya_Left_Sit", RectMake(670, 409, 759, 329));

	KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_Sit", "Nanaya_SitAndUp", 15, 19, 8, false, true);
	KEYANIMANAGER->setCollisionRect("Nanaya_Right_Sit", RectMake(670, 409, 759, 329));

	//일어날 때
	KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_SitUp", "Nanaya_SitAndUp", 5, 9, 8, false, true);
	KEYANIMANAGER->setCollisionRect("Nanaya_Left_SitUp", RectMake(670, 409, 759, 659));

	KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_SitUp", "Nanaya_SitAndUp", 10, 14, 8, false, true);
	KEYANIMANAGER->setCollisionRect("Nanaya_Right_SitUp", RectMake(670, 409, 759, 659));

	character::init("Nanaya", pos, "Nanaya_Stand");
	this->changeState(NanayaState::RIGHT_STAND);

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
		case NanayaState::RIGHT_STAND:
		{
			this->setAnimation("Nanaya_Right_Stand");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, NanayaState::RIGHT_STAND));
		}
		case NanayaState::LEFT_STAND:
		{
			this->setAnimation("Nanaya_Left_Stand");
			this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, NanayaState::LEFT_STAND));
		}
		break;
	}
}

void Nanaya::changeState(NanayaState::Enum state)
{

}