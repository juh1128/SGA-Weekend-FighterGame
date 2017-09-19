#include "stdafx.h"
#include "playScene.h"
#include "selectScene.h"
#include "progressBar.h"
#include "character.h"

HRESULT	playScene::init()
{
	sceneBase::init();

	//리소스 로드
	// - 인터페이스
	IMAGEMANAGER->addImage("HP바_백", "resource/yuhoon/ui/hpBarBack.bmp", 53, 5, true);
	IMAGEMANAGER->addImage("HP바_프론트", "resource/yuhoon/ui/hpBarFront.bmp", 53, 5, true);
	IMAGEMANAGER->addImage("KO", "resource/yuhoon/KO.bmp", 507, 219, true);

	//초기 오브젝트 생성
	_background = IMAGEMANAGER->addFrameImage("맵", "resource/yuhoon/background2.bmp", 914, 3072, 1, 8, true);
	_backgroundAnimation = new animation;
	_backgroundAnimation->init(_background->getWidth(), _background->getHeight(), _background->getFrameWidth(), _background->getFrameHeight());
	_backgroundAnimation->setDefPlayFrame(false, true);
	_backgroundAnimation->setFPS(25);
	_backgroundAnimation->start();

	//카메라 설정
	_cameraTarget = new gameObject;
	_cameraTarget->init("카메라 타겟");
	_cameraTarget->_pos = vector2D(WINSIZEX / 2, WINSIZEY / 2);
	CAMERAMANAGER->setMapSize(1800, 768);
	CAMERAMANAGER->connectTarget(_cameraTarget);

	//UI
	for (int i = 0; i < 2; ++i)
	{
		_progressBar[i] = new progressBar();
		_progressBar[i]->init("HP바_백", "HP바_프론트", 500, 45);
	}
	_progressBar[0]->_pos = vector2D(300, 30);
	_progressBar[1]->_pos = vector2D(980, 30);

	//플레이어 0, 플레이어 1 셋팅
	characterSetup();

	_state = playSceneState::PLAY;

	//게임오버 메시지 콜백
	this->addCallback("gameover", [this](tagMessage msg) {
		this->gameOver();
	});


	return S_OK;
}

void playScene::release()
{
	_cameraTarget->release();
	SAFE_DELETE(_cameraTarget);
	sceneBase::release();

	//배경 해제
	_background->release();
	SAFE_DELETE(_background);
	_backgroundAnimation->release();
	SAFE_DELETE(_backgroundAnimation);

	_progressBar[0]->release();
	_progressBar[1]->release();
	SAFE_DELETE(_progressBar[0]);
	SAFE_DELETE(_progressBar[1]);

	_player[0]->release();
	_player[1]->release();
	SAFE_DELETE(_player[0]);
	SAFE_DELETE(_player[1]);

	IMAGEMANAGER->resetImage();
}

//씬 재시작 시 설정해야되는 것이 있다면 여기에 쓴다.
void playScene::resume()		
{

}



void playScene::update()		
{
	sceneBase::update();

	//배경 프레임
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


	//카메라 타겟 위치 셋업
	gameObject* left = _player[1];
	gameObject* right = _player[0];
	if (_player[0]->_pos.x <= _player[1]->_pos.x)
	{
		left = _player[0];
		right = _player[1];
	}
	float distance = right->getCollisionRect().right - left->getCollisionRect().left;
	vector2D averagePos = (_player[0]->_pos + _player[1]->_pos) / 2;
	vector2D dir = averagePos - _cameraTarget->_pos;
	if (dir.getLength() <= 5.0f)
	{
		_cameraTarget->_pos = averagePos;
	}
	else
	{
		_cameraTarget->_pos = _cameraTarget->_pos + dir.normalize()*5.0f;
	}


	if (_state == playSceneState::END)
	{
		_gameResetTimer -= TIMEMANAGER->getElapsedTime();
		if (_gameResetTimer <= 0)
		{
			SCENEMANAGER->changeScene(new selectScene);
		}
	}

}
void playScene::render()		
{
	RECT rc = CAMERAMANAGER->getRenderRect();
	_background->scaleAniRender(getMemDC(), -rc.left, -rc.top, _backgroundAnimation, 1800, 768);

	sceneBase::render();

	_progressBar[0]->render();
	_progressBar[1]->render();

	if (_state == playSceneState::END)
	{
		vector2D renderPos = vector2D(WINSIZEX / 2 - 253, WINSIZEY / 2 - 110);
		IMAGEMANAGER->findImage("KO")->render(getMemDC(), renderPos.x, renderPos.y);
	}
}

void playScene::gameOver()
{
	_state = playSceneState::END;
	_gameResetTimer = 5.0f;
}