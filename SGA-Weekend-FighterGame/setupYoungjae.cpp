#include "stdafx.h"
#include "playGround.h"

void playGround::setupYoungjae()
{
	//�̹��� ���ҽ� �ε�
	IMAGEMANAGER->addFrameImage("��", "resource/background2.bmp", 1828, 6144, 1, 8, true);
	IMAGEMANAGER->addFrameImage("������_Idle", "resource/youngjae/Nanaya/Idle.bmp", 1280, 122, 16, 1, true);

	//�ִϸ��̼� �ε�
	KEYANIMANAGER->addCoordinateFrameAnimation("������_������_Idle", "������_Idle", 0, 15, 8, true, true);
}