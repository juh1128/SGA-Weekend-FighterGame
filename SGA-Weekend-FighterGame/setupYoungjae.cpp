#include "stdafx.h"
#include "playGround.h"

void playGround::setupYoungjae()
{
	//�̹��� ���ҽ� �ε�
	IMAGEMANAGER->addFrameImage("Nanaya_Right_Stand", "resource/youngjae/Nanaya/R_Stand.bmp", 4096, 256, 16, 1, true);

	//�ִϸ��̼� �ε�
	KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_Stand", "Nanaya_Stand", 0, 15, 8, true, true);
}