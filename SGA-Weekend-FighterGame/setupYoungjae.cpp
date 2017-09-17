#include "stdafx.h"
#include "playGround.h"

void playGround::setupYoungjae()
{
	//이미지 리소스 로드
	IMAGEMANAGER->addFrameImage("Nanaya_Stand", "resource/youngjae/Nanaya/Nanaya_Stand.bmp", 4096, 512, 16, 2, true);

	//애니메이션 로드
	KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Stand", "Nanaya_Stand", 0, 15, 8, true, true);
}