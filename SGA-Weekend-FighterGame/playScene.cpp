#include "stdafx.h"
#include "playScene.h"
#include "progressBar.h"

HRESULT	playScene::init()
{
	sceneBase::init();

	//���ҽ� �ε�
	// - �������̽�
	IMAGEMANAGER->addImage("HP��_��", "resource/yuhoon/ui/hpBarBack.bmp", 53, 5, true);
	IMAGEMANAGER->addImage("HP��_����Ʈ", "resource/yuhoon/ui/hpBarFront.bmp", 53, 5, true);

	//�ʱ� ������Ʈ ����
	_background = IMAGEMANAGER->addFrameImage("��", "resource/yuhoon/background2.bmp", 914, 3072, 1, 8, true);
	_backgroundAnimation = new animation;
	_backgroundAnimation->init(_background->getWidth(), _background->getHeight(), _background->getFrameWidth(), _background->getFrameHeight());
	_backgroundAnimation->setDefPlayFrame(false, true);
	_backgroundAnimation->setFPS(25);
	_backgroundAnimation->start();

	//ī�޶� ����
	_cameraTarget = new gameObject;
	_cameraTarget->init("ī�޶� Ÿ��");
	_cameraTarget->_pos = vector2D(WINSIZEX / 2, WINSIZEY / 2);
	CAMERAMANAGER->setMapSize(1800, 768);
	CAMERAMANAGER->connectTarget(_cameraTarget);

	//UI
	for (int i = 0; i < 2; ++i)
	{
		_progressBar[i] = new progressBar();
		_progressBar[i]->init("HP��_��", "HP��_����Ʈ", 500, 45);
	}
	_progressBar[0]->_pos = vector2D(300, 30);
	_progressBar[1]->_pos = vector2D(980, 30);

	//�÷��̾� 0, �÷��̾� 1 ����
	characterSetup();


	return S_OK;
}

void playScene::release()
{
	SAFE_DELETE(_cameraTarget);
	sceneBase::release();

	IMAGEMANAGER->resetImage();
}

//�� ����� �� �����ؾߵǴ� ���� �ִٸ� ���⿡ ����.
void playScene::resume()		
{

}



void playScene::update()		
{
	sceneBase::update();


	//��� ������
	_backgroundAnimation->frameUpdate();

}
void playScene::render()		
{
	_background->scaleAniRender(getMemDC(), 0, 0, _backgroundAnimation, 1800, 768);

	sceneBase::render();
}