#include "stdafx.h"
#include "selectScene.h"
#include "playScene.h"

HRESULT	selectScene::init()
{
	sceneBase::init();

	//필요한 이미지 로드
	IMAGEMANAGER->addImage("백", "resource/yuhoon/mask.bmp", 100, 100, true);
	IMAGEMANAGER->addImage("타이틀", "resource/yuhoon/title.bmp", 881, 186, true);
	IMAGEMANAGER->addFrameImage("플레이어넘버", "resource/yuhoon/playerNumber.bmp", 150, 45, 2, 1, true);

	_playerNumber[0] = IMAGEMANAGER->findImage("플레이어넘버");
	_playerNumber[1] = IMAGEMANAGER->findImage("플레이어넘버");

	//오른쪽 보는 애니메이션
	// - 이오리 0~8   (357, 267,  521, 526)
	IMAGEMANAGER->addFrameImage("이오리", "resource/Dongjin/오른쪽강손.bmp", 3568, 400, 9, 1, true);
	// - 테리 8~15 (74,360, 270, 651)
	IMAGEMANAGER->addFrameImage("테리", "resource/geunhwa/terryIdle.bmp", 2288, 800, 8, 2, true);
	// - 네코 오른쪽 0, 17 (2프레임) (298, 541, 383, 659)
	IMAGEMANAGER->addFrameImage("네코", "resource/soonwoo/neko/neko1_right.bmp", 4352, 1790, 17, 7, true);
	//왼쪽 보는 애니메이션
	// - 마이 0->7 (1010, 437, 1207, 687)
	IMAGEMANAGER->addFrameImage("마이", "resource/sunghoon/maiStrongKick.bmp", 3624, 802, 8, 2, true);
	// - 솔배드가이 9->5 (759, 267, 962, 463)
	IMAGEMANAGER->addFrameImage("솔배드가이", "resource/taesung/solBadGuy/jump_attack.bmp", 406, 162, 5, 2, true);
	// - 나나야 23->12 (670, 409, 759, 659)
	IMAGEMANAGER->addFrameImage("나나야", "resource/youngjae/nanaya/Nanaya_WalkForward.bmp", 3072, 512, 12, 2, true);

	//초기 애니메이션 설정
	_selectedAnimation[characterName::iori] = new animation();
	_selectedAnimation[characterName::iori]->init(3568, 400, 3568 / 9, 400);
	_selectedAnimation[characterName::iori]->setPlayFrame(0, 8, false, false);

	_selectedAnimation[characterName::terry] = new animation();
	_selectedAnimation[characterName::terry]->init(2288, 800, 2288 / 8, 800/2);
	_selectedAnimation[characterName::terry]->setPlayFrame(8, 15, false, false);

	_selectedAnimation[characterName::neco] = new animation();
	_selectedAnimation[characterName::neco]->init(4352, 1790, 4352 / 17, 1790 / 7);
	int arrAnim[] = { 0, 17 };
	_selectedAnimation[characterName::neco]->setPlayFrame(arrAnim, 2, false, false);


	_selectedAnimation[characterName::mai] = new animation();
	_selectedAnimation[characterName::mai]->init(3624, 802, 3624 / 8, 802 / 2);
	_selectedAnimation[characterName::mai]->setPlayFrame(0, 7, false, false);

	_selectedAnimation[characterName::sol] = new animation();
	_selectedAnimation[characterName::sol]->init(406, 162, 406 / 5, 162 / 2);
	_selectedAnimation[characterName::sol]->setPlayFrame(9, 5, false, false);

	_selectedAnimation[characterName::nanaya] = new animation();
	_selectedAnimation[characterName::nanaya]->init(3072, 512, 3072 / 12, 512 / 2);
	_selectedAnimation[characterName::nanaya]->setPlayFrame(23, 12, false, false);

	//애니메이션 속도 설정
	for (int i = 0; i < characterName::END; ++i)
	{
		_selectedAnimation[i]->setFPS(15);
	}


	//충돌 렉트 설정
	_characterRC[characterName::iori] = { 358, 288, 493, 526 };
	_characterRC[characterName::terry] = { 76, 370, 238, 639 };
	_characterRC[characterName::neco] = { 325, 552, 386, 640 };
	_characterRC[characterName::sol] = { 819, 315, 1020, 505 };
	_characterRC[characterName::nanaya] = { 788, 532, 870, 736 };
	_characterRC[characterName::mai] = { 1053, 471, 1185, 675 };


	//초기 오브젝트 생성
	_back = IMAGEMANAGER->findImage("백");
	_title = IMAGEMANAGER->findImage("타이틀");

	_selectNum = 0;
	_state = selectSceneState::SELECT;
	_selectedCharacter[0] = -1;
	_selectedCharacter[1] = -1;


	//카메라 설정
	CAMERAMANAGER->setMapSize(WINSIZEX, WINSIZEY);
	CAMERAMANAGER->connectNullTarget();

	return S_OK;
}

void selectScene::release()
{
	sceneBase::release();

	//로드된 이미지 해제
	IMAGEMANAGER->resetImage();

	//애니메이션 해제
	for (int i = 0; i < characterName::END; ++i)
	{
		_selectedAnimation[i]->release();
		SAFE_DELETE(_selectedAnimation[i]);
	}
}

//씬 재시작 시 설정해야되는 것이 있다면 여기에 쓴다.
void selectScene::resume()
{

}



void selectScene::update()
{
	sceneBase::update();

	switch (_state)
	{
		case selectSceneState::SELECT:
		{
			//마우스 커서랑 이미지 충돌렉트랑 충돌 시
			static int currentPlay = -1;
			for (int i = 0; i < characterName::END; ++i)
			{
				if (PtInRect(&_characterRC[i], _ptMouse))
				{
					if (!_selectedAnimation[i]->isPlay() && i != currentPlay)
					{
						_selectedAnimation[i]->start();
						currentPlay = i;
					}
				}
				else
				{
					_selectedAnimation[i]->stop();
					if (currentPlay == i)
					{
						currentPlay = -1;
					}
				}

				_selectedAnimation[i]->frameUpdate();
			}

			//선택 처리
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				if (currentPlay != -1)
				{
					_selectedCharacter[_selectNum] = currentPlay;
					_selectNum++;

					//선택 완료 2초 후 게임시작
					if (_selectNum >= 2)
					{
						_state = selectSceneState::GO_NEXT;
					}
				}
			}
		}
		break;

		case selectSceneState::GO_NEXT:
		{
			static float nextTimer = 2.0f;
			nextTimer -= TIMEMANAGER->getElapsedTime();
			if (nextTimer <= 0)
			{
				SCENEMANAGER->changeScene(new playScene(_selectedCharacter[0], _selectedCharacter[1]));
			}
		}
		break;
	}


}
void selectScene::render()
{
	sceneBase::render();

	_back->scaleRender(getMemDC(), 0, 0, WINSIZEX, WINSIZEY);
	_title->render(getMemDC(), 200, 84);

	//캐릭터 렌더링
	IMAGEMANAGER->findImage("이오리")->scaleAniRender(getMemDC(), 357, 267, _selectedAnimation[characterName::iori], 230, 259);
	IMAGEMANAGER->findImage("테리")->scaleAniRender(getMemDC(), 74, 360, _selectedAnimation[characterName::terry], 270 - 74, 651 - 360);
	IMAGEMANAGER->findImage("네코")->scaleAniRender(getMemDC(), 100, 201, _selectedAnimation[characterName::neco], 500, 500);
	
	IMAGEMANAGER->findImage("솔배드가이")->scaleAniRender(getMemDC(), 759, 267, _selectedAnimation[characterName::sol], 304, 294);
	IMAGEMANAGER->findImage("나나야")->scaleAniRender(getMemDC(), 570, 309, _selectedAnimation[characterName::nanaya], 500, 500);
	IMAGEMANAGER->findImage("마이")->scaleAniRender(getMemDC(), 950, 437, _selectedAnimation[characterName::mai], 250, 250);

	//1p,2p 렌더링
	for (int i = 0; i < 2; ++i)
	{
		if (_selectedCharacter[i] != -1)
		{
			int width = _characterRC[_selectedCharacter[i]].right - _characterRC[_selectedCharacter[i]].left;
			_playerNumber[i]->frameRender(getMemDC(), _characterRC[_selectedCharacter[i]].right - width/2, 
				_characterRC[_selectedCharacter[i]].top - 30, i, 0);
		}
	}
}