#include "stdafx.h"
#include "selectScene.h"
#include "playScene.h"

HRESULT	selectScene::init()
{
	sceneBase::init();

	//�ʿ��� �̹��� �ε�
	IMAGEMANAGER->addImage("��", "resource/yuhoon/mask.bmp", 100, 100, true);
	IMAGEMANAGER->addImage("Ÿ��Ʋ", "resource/yuhoon/title.bmp", 881, 186, true);
	IMAGEMANAGER->addFrameImage("�÷��̾�ѹ�", "resource/yuhoon/playerNumber.bmp", 150, 45, 2, 1, true);

	_playerNumber[0] = IMAGEMANAGER->findImage("�÷��̾�ѹ�");
	_playerNumber[1] = IMAGEMANAGER->findImage("�÷��̾�ѹ�");

	//������ ���� �ִϸ��̼�
	// - �̿��� 0~8   (357, 267,  521, 526)
	IMAGEMANAGER->addFrameImage("�̿���", "resource/Dongjin/�����ʰ���.bmp", 3568, 400, 9, 1, true);
	// - �׸� 8~15 (74,360, 270, 651)
	IMAGEMANAGER->addFrameImage("�׸�", "resource/geunhwa/terryIdle.bmp", 2288, 800, 8, 2, true);
	// - ���� ������ 0, 17 (2������) (298, 541, 383, 659)
	IMAGEMANAGER->addFrameImage("����", "resource/soonwoo/neko/neko1_right.bmp", 4352, 1790, 17, 7, true);
	// - ����� ������ 0~4
	IMAGEMANAGER->addFrameImage("�����", "resource/yoonsam/Mauru/Mauru_sit_.bmp", 550, 580, 5, 4, true);
	// - �� ������  1~8
	IMAGEMANAGER->addFrameImage("��", "resource/hyeongjoon/whip/whip_attack/whip_stongFoot.bmp", 1237, 228, 11, 2, true);

	//���� ���� �ִϸ��̼�
	// - ���� 0->7 (1010, 437, 1207, 687)
	IMAGEMANAGER->addFrameImage("����", "resource/sunghoon/maiStrongKick.bmp", 3624, 802, 8, 2, true);
	// - �ֹ�尡�� 9->5 (759, 267, 962, 463)
	IMAGEMANAGER->addFrameImage("�ֹ�尡��", "resource/taesung/solBadGuy/jump_attack.bmp", 406, 162, 5, 2, true);
	// - ������ 23->12 (670, 409, 759, 659)
	IMAGEMANAGER->addFrameImage("������", "resource/youngjae/Nanaya/Nanaya_Select.bmp", 2304, 512, 9, 2, true);
	// - ���׳� 41 -> 46
	IMAGEMANAGER->addFrameImage("���׳�", "resource/siyeong/���ʰȱ�,�ɱ�.bmp", 1440, 1260, 8, 6, true);
	// - �谩 667,323  0->3
	IMAGEMANAGER->addFrameImage("��", "resource/yongje/�ɱ�(683,796,3,2).bmp", 683, 796, 3, 2, true);


	//�ʱ� �ִϸ��̼� ����
	_selectedAnimation[characterName::whip] = new animation();
	_selectedAnimation[characterName::whip]->init(1237, 228, 1237 / 11, 228 / 2);
	_selectedAnimation[characterName::whip]->setPlayFrame(1, 8, false, false);

	_selectedAnimation[characterName::kim] = new animation();
	_selectedAnimation[characterName::kim]->init(683, 796, 683 / 3, 796 / 2);
	_selectedAnimation[characterName::kim]->setPlayFrame(0, 3, false, false);

	_selectedAnimation[characterName::mauru] = new animation();
	_selectedAnimation[characterName::mauru]->init(550, 580, 550 / 5, 580 /4);
	_selectedAnimation[characterName::mauru]->setPlayFrame(0, 4, false, false);

	_selectedAnimation[characterName::iori] = new animation();
	_selectedAnimation[characterName::iori]->init(3568, 400, 3568 / 9, 400);
	_selectedAnimation[characterName::iori]->setPlayFrame(8, 0, false, false);

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
	_selectedAnimation[characterName::nanaya]->init(2304, 512, 2304 / 9, 512 / 2);
	_selectedAnimation[characterName::nanaya]->setPlayFrame(17, 9, false, false);

	_selectedAnimation[characterName::athena] = new animation();
	_selectedAnimation[characterName::athena]->init(1440, 1260, 1440 / 8, 1260 / 6);
	_selectedAnimation[characterName::athena]->setPlayFrame(41, 46, false, false);

	//�ִϸ��̼� �ӵ� ����
	for (int i = 0; i < characterName::END; ++i)
	{
		_selectedAnimation[i]->setFPS(15);
	}


	//�浹 ��Ʈ ����
	_characterRC[characterName::whip] = { 42, 261, 200, 483 };
	_characterRC[characterName::kim] = { 667, 323, 830, 568 };
	_characterRC[characterName::mauru] = { 210, 314, 380, 500 };
	_characterRC[characterName::iori] = { 358, 288, 493, 526 };
	_characterRC[characterName::terry] = { 76, 370, 238, 639 };
	_characterRC[characterName::neco] = { 325, 552, 386, 640 };
	_characterRC[characterName::sol] = { 819, 315, 1020, 505 };
	_characterRC[characterName::nanaya] = { 788, 532, 870, 736 };
	_characterRC[characterName::mai] = { 1053, 471, 1185, 675 };
	_characterRC[characterName::athena] = { 880, 439, 963, 618 };


	//�ʱ� ������Ʈ ����
	_back = IMAGEMANAGER->findImage("��");
	_title = IMAGEMANAGER->findImage("Ÿ��Ʋ");

	_selectNum = 0;
	_state = selectSceneState::SELECT;
	_selectedCharacter[0] = -1;
	_selectedCharacter[1] = -1;


	//ī�޶� ����
	CAMERAMANAGER->setMapSize(WINSIZEX, WINSIZEY);
	CAMERAMANAGER->connectNullTarget();

	return S_OK;
}

void selectScene::release()
{
	sceneBase::release();

	//�ε�� �̹��� ����
	IMAGEMANAGER->resetImage();

	//�ִϸ��̼� ����
	for (int i = 0; i < characterName::END; ++i)
	{
		_selectedAnimation[i]->release();
		SAFE_DELETE(_selectedAnimation[i]);
	}
}

//�� ����� �� �����ؾߵǴ� ���� �ִٸ� ���⿡ ����.
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
			//���콺 Ŀ���� �̹��� �浹��Ʈ�� �浹 ��
			static int currentPlay = -1;

			if (currentPlay == -1)
			{
				for (int i = 0; i < characterName::END; ++i)
				{
					if (PtInRect(&_characterRC[i], _ptMouse))
					{
						if (!_selectedAnimation[i]->isPlay())
						{
							_selectedAnimation[i]->start();
							currentPlay = i;
						}
						break;
					}
				}
			}
			else
			{
				_selectedAnimation[currentPlay]->frameUpdate();
				if (!PtInRect(&_characterRC[currentPlay], _ptMouse))
				{
					_selectedAnimation[currentPlay]->stop();
					currentPlay = -1;					
				}
			}

			//���� ó��
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				if (currentPlay != -1)
				{
					_selectedCharacter[_selectNum] = currentPlay;
					_selectNum++;

					//���� �Ϸ� 2�� �� ���ӽ���
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

	//ĳ���� ������
	IMAGEMANAGER->findImage("��")->scaleAniRender(getMemDC(), 42, 261, _selectedAnimation[characterName::whip], 200-42+20, 483-261);
	IMAGEMANAGER->findImage("�����")->scaleAniRender(getMemDC(), 210, 274, _selectedAnimation[characterName::mauru], 180, 250);
	IMAGEMANAGER->findImage("�̿���")->scaleAniRender(getMemDC(), 357, 267, _selectedAnimation[characterName::iori], 230, 259);
	IMAGEMANAGER->findImage("�׸�")->scaleAniRender(getMemDC(), 74, 360, _selectedAnimation[characterName::terry], 270 - 74, 651 - 360);
	IMAGEMANAGER->findImage("����")->scaleAniRender(getMemDC(), 100, 201, _selectedAnimation[characterName::neco], 500, 500);
	
	IMAGEMANAGER->findImage("��")->scaleAniRender(getMemDC(), 667, 323, _selectedAnimation[characterName::kim], 830-667, 568-323);
	IMAGEMANAGER->findImage("�ֹ�尡��")->scaleAniRender(getMemDC(), 759, 267, _selectedAnimation[characterName::sol], 304, 294);
	IMAGEMANAGER->findImage("���׳�")->scaleAniRender(getMemDC(), 795, 351, _selectedAnimation[characterName::athena], 990 - 795, 648 - 351);
	IMAGEMANAGER->findImage("������")->scaleAniRender(getMemDC(), 570, 309, _selectedAnimation[characterName::nanaya], 500, 500);
	IMAGEMANAGER->findImage("����")->scaleAniRender(getMemDC(), 950, 437, _selectedAnimation[characterName::mai], 250, 250);
	

	//1p,2p ������
	for (int i = 0; i < 2; ++i)
	{
		if (_selectedCharacter[i] != -1)
		{
			int width = _characterRC[_selectedCharacter[i]].right - _characterRC[_selectedCharacter[i]].left;
			_playerNumber[i]->frameRender(getMemDC(), _characterRC[_selectedCharacter[i]].right - width/2, 
				_characterRC[_selectedCharacter[i]].top - 30, i, 0);
		}
	}


	if (_isDebugMode)
	{
		for (int i = 0; i < characterName::END; ++i)
		{
			HPEN bluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
			HPEN oldPen;
			HBRUSH oldBrush;
			HDC memDC = getMemDC();

			oldPen = (HPEN)SelectObject(memDC, bluePen);
			oldBrush = (HBRUSH)SelectObject(memDC, GetStockObject(NULL_BRUSH));

			Rectangle(getMemDC(), _characterRC[i].left, _characterRC[i].top, _characterRC[i].right, _characterRC[i].bottom);

			SelectObject(memDC, oldBrush);
			SelectObject(memDC, oldPen);

			DeleteObject(bluePen);
			
		}
	}
}