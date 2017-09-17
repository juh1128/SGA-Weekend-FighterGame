#include "stdafx.h"
#include "playGround.h"

void playGround::setupYoungjae()
{
	//이미지 리소스 로드
	IMAGEMANAGER->addFrameImage("맵", "resource/background2.bmp", 1828, 6144, 1, 8, true);
	IMAGEMANAGER->addFrameImage("Nanaya_Right_Stand", "resource/youngjae/Nanaya/R_Stand.bmp", 4096, 256, 16, 1, true);

	//애니메이션 로드
	KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_Stand", "Nanaya_Stand", 0, 15, 8, true, true);
}