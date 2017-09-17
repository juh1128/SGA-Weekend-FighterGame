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

	//�� ������ ���ҽ� �ε�
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

	//�ʱ� ���� �� ����
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

	//=================== �� �� �� �� ===================
	this->getBackBuffer()->render(getHDC(), -renderRC.left, -renderRC.top);

}
