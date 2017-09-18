#include "stdafx.h"
#include "playScene.h"
#include "progressBar.h"

HRESULT	playScene::init()
{
	sceneBase::init();

	//¸®¼Ò½º ·Îµå
	// - ÀÎÅÍÆäÀÌ½º
	IMAGEMANAGER->addImage("HP¹Ù_¹é", "resource/yuhoon/ui/hpBarBack.bmp", 53, 5, true);
	IMAGEMANAGER->addImage("HP¹Ù_ÇÁ·ÐÆ®", "resource/yuhoon/ui/hpBarFront.bmp", 53, 5, true);

	//ÃÊ±â ¿ÀºêÁ§Æ® »ý¼º
	_background = IMAGEMANAGER->addFrameImage("¸Ê", "resource/yuhoon/background2.bmp", 914, 3072, 1, 8, true);
	_backgroundAnimation = new animation;
	_backgroundAnimation->init(_background->getWidth(), _background->getHeight(), _background->getFrameWidth(), _background->getFrameHeight());
	_backgroundAnimation->setDefPlayFrame(false, true);
	_backgroundAnimation->setFPS(25);
	_backgroundAnimation->start();

	//Ä«¸Þ¶ó ¼³Á¤
	_cameraTarget = new gameObject;
	_cameraTarget->init("Ä«¸Þ¶ó Å¸°Ù");
	_cameraTarget->_pos = vector2D(WINSIZEX / 2, WINSIZEY / 2);
	CAMERAMANAGER->setMapSize(1800, 768);
	CAMERAMANAGER->connectTarget(_cameraTarget);

	//UI
	for (int i = 0; i < 2; ++i)
	{
		_progressBar[i] = new progressBar();
		_progressBar[i]->init("HPï¿½ï¿½_ï¿½ï¿½", "HPï¿½ï¿½_ï¿½ï¿½ï¿½ï¿½Æ®", 500, 45);
	}
	_progressBar[0]->_pos = vector2D(300, 30);
	_progressBar[1]->_pos = vector2D(980, 30);

	//ÇÃ·¹ÀÌ¾î 0, ÇÃ·¹ÀÌ¾î 1 ¼ÂÆÃ
	characterSetup();


	return S_OK;
}

void playScene::release()
{
	SAFE_DELETE(_cameraTarget);
	sceneBase::release();

	IMAGEMANAGER->resetImage();
}

//¾À Àç½ÃÀÛ ½Ã ¼³Á¤ÇØ¾ßµÇ´Â °ÍÀÌ ÀÖ´Ù¸é ¿©±â¿¡ ¾´´Ù.
void playScene::resume()		
{

}



void playScene::update()		
{
	sceneBase::update();


	//¹è°æ ÇÁ·¹ÀÓ
	_backgroundAnimation->frameUpdate();

}
void playScene::render()		
{
	_background->scaleAniRender(getMemDC(), 0, 0, _backgroundAnimation, 1800, 768);

	sceneBase::render();
}