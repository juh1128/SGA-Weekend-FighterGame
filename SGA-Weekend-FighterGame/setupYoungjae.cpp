#include "stdafx.h"
#include "playGround.h"

void playGround::setupYoungjae()
{
	//�̹��� ���ҽ� �ε�
	IMAGEMANAGER->addFrameImage("Nanaya_Stand", "resource/youngjae/Nanaya/Nanaya_Stand.bmp", 4096, 512, 16, 2, true);

	//�ִϸ��̼� �ε�
	KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Stand", "Nanaya_Stand", 0, 15, 8, true, true);
}