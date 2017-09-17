#include "stdafx.h"
#include "playScene.h"
#include "progressBar.h"

HRESULT	playScene::init()
{
	sceneBase::init();

	//�ʱ� ������Ʈ ����
	_background = new image;
	_background = IMAGEMANAGER->findImage("��");
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
	//for (int i = 0; i < 2; ++i)
	//{
	//	_progressBar[i] = new progressBar();
	//	_progressBar[i]->init(
	//}

	//�÷��̾� 0, �÷��̾� 1 ����
	characterSetup();


	return S_OK;
}

void playScene::release()
{
	SAFE_DELETE(_cameraTarget);
	sceneBase::release();
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