#include "stdafx.h"
#include "playGround.h"

void playGround::setupYoungjae()
{
	//이미지 리소스 로드
	IMAGEMANAGER->addFrameImage("맵", "resource/background2.bmp", 1828, 6144, 1, 8, true);
	IMAGEMANAGER->addFrameImage("나나야_Idle", "resource/youngjae/Nanaya/Idle.bmp", 1280, 122, 16, 1, true);

	//애니메이션 로드
	KEYANIMANAGER->addCoordinateFrameAnimation("나나야_오른쪽_Idle", "나나야_Idle", 0, 15, 8, true, true);
}