#include "stdafx.h"
#include "playGround.h"
#include "selectScene.h"

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
	//setupGuenhwa();
	//setupDongjin();
	//setupHyunjin();
	//setupSiyeong();
	//setupSoonyu();
	//setupYuhoon();
	//setupHyeongjoon();
	//setupSunghoon();
	//setupTaesung();
	//setupYongje();
	//setupYoonsam();
	//setupHalim();
	//setupYoungjae();

	//�ʱ� ���� �� ����
	SCENEMANAGER->pushScene(new selectScene);

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
