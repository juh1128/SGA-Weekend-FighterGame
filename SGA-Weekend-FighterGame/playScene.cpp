#include "stdafx.h"
#include "playScene.h"
#include "gameObject.h"
#include "animation.h"

#include "callbackTest.h"

HRESULT	playScene::init()
{
	sceneBase::init();

	//초기 오브젝트 생성
	_background = new image;
	_background = IMAGEMANAGER->findImage("맵");
	_backgroundAnimation = new animation;
	_backgroundAnimation->init(_background->getWidth(), _background->getHeight(), _background->getFrameWidth(), _background->getFrameHeight());
	_backgroundAnimation->setDefPlayFrame(false, true);
	_backgroundAnimation->setFPS(25);
	_backgroundAnimation->start();

	_cbTest = new callbackTest;
	_cbTest->init();
	WORLD->addObject(_cbTest);

	//카메라 설정
	_cameraTarget = new gameObject;
	_cameraTarget->init("카메라 타겟");
	_cameraTarget->_pos = vector2D(WINSIZEX / 2, WINSIZEY / 2);
	CAMERAMANAGER->setMapSize(1800, 768);
	CAMERAMANAGER->connectTarget(_cameraTarget);

	//플레이어 0, 플레이어 1 셋팅
	characterSetup();


	return S_OK;
}

void playScene::release()
{
	SAFE_DELETE(_cameraTarget);
	sceneBase::release();
}

//씬 재시작 시 설정해야되는 것이 있다면 여기에 쓴다.
void playScene::resume()		
{

}



void playScene::update()		
{
	sceneBase::update();


	if (KEYMANAGER->isOnceKeyDown('T'))
	{
		_cbTest->sendMessage("addHp", 0.0f, -45);
	}

	//배경 프레임
	_backgroundAnimation->frameUpdate();

}
void playScene::render()		
{
	_background->scaleAniRender(getMemDC(), 0, 0, _backgroundAnimation, 1800, 768);

	sceneBase::render();
}