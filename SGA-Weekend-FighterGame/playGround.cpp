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

	//초기 시작 씬 생성
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

	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	SCENEMANAGER->render();

	//=================== 손 대 지 마 ===================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
