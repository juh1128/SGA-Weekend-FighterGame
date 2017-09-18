#include "stdafx.h"
#include "playScene.h"
#include "progressBar.h"
#include "character.h"

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


	//UI
	if(_player[0]->isLive())
		_progressBar[0]->update(_player[0]->getNowHp(), _player[0]->getMaxHp());
	else
		_progressBar[0]->update(0, 1000);

	if (_player[1]->isLive())
		_progressBar[1]->update(_player[1]->getNowHp(), _player[1]->getMaxHp());
	else
		_progressBar[1]->update(0, 1000);


	//ī�޶� Ÿ�� ��ġ �¾�
	//vector2D averagePos = (_player[0]->_pos + _player[1]->_pos) / 2;
	//_cameraTarget->_pos = averagePos;\
	
	if (KEYMANAGER->isStayKeyDown('M'))
	{
		_cameraTarget->_pos.x += 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown('N'))
	{
		_cameraTarget->_pos.x -= 5.0f;
	}

	CAMERAMANAGER->updateCamera();
}
void playScene::render()		
{
	RECT rc = CAMERAMANAGER->getRenderRect();
	_background->scaleAniRender(getMemDC(), -rc.left, -rc.top, _backgroundAnimation, 1800, 768);

	_progressBar[0]->render();
	_progressBar[1]->render();
	sceneBase::render();
}