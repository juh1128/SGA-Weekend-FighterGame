#include "stdafx.h"
#include "playGround.h"
#include "playScene.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

HRESULT playGround::init(void)
{
	gameNode::init(true);

	//각 팀원별 리소스 로딩
	setupGuenhwa();
	setupDongjin();
	setupHyunjin();
	setupSiyeong();
//	setupSoonyu();
	setupYuhoon();
	setupHyeongjoon();
	setupSunghoon();
	setupTaesung();
	setupYongjae();
	setupYoonsam();
	setupHalim();

	//초기 시작 씬 생성
	SCENEMANAGER->pushScene(new playScene);

	return S_OK;
}

void playGround::release(void)
{
	gameNode::release();
}

void playGround::update(void)
{
	gameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_isDebugMode = !_isDebugMode;
	}
	
	SCENEMANAGER->update();
}

void playGround::render(void)
{
	HDC backDC = getMemDC();
	RECT renderRC = CAMERAMANAGER->getRenderRect();

	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	SCENEMANAGER->render();

	//=================== 손 대 지 마 ===================
	this->getBackBuffer()->render(getHDC(), -renderRC.left, -renderRC.top);

}
