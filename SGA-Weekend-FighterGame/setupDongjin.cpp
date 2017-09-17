
#include "stdafx.h"
#include "playGround.h"

void playGround::setupDongjin()
{

	IMAGEMANAGER->addFrameImage("ioriYagami", "resource/Dongjin/�����ü.bmp", 0, 0, 3600, 4000, 10, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagami2", "resource/Dongjin/�����ü2.bmp", 0, 0, 3330, 1600, 10, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiStop", "resource/Dongjin/�����ʸ���.bmp", 0, 0, 2770, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiStop2", "resource/Dongjin/���ʸ���.bmp", 0, 0, 2770, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiBackMove", "resource/Dongjin/�����ʵ��̵�.bmp", 0, 0, 2124, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiJump", "resource/Dongjin/����������.bmp", 0, 0, 2310, 400, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSit", "resource/Dongjin/�����ʾɱ�.bmp", 0, 0, 1876, 400, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackA", "resource/Dongjin/�����ʾ��.bmp", 0, 0, 1175, 400, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackB", "resource/Dongjin/�����ʾ��.bmp", 0, 0, 2478, 400, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackC", "resource/Dongjin/�����ʰ���.bmp", 0, 0, 3568, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackD", "resource/Dongjin/�����ʰ���.bmp", 0, 0, 3634, 400, 9, 1, true, RGB(255, 0, 255));

	//����
	//KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�̵�_������", "�׽�Ʈ_�̵�", 0, 9, 15, false, true);
	//KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�̵�_������", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_����", "ioriYagamiStop", 0, 8, 10, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_������_����", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_����_����", "ioriYagamiStop2", 0, 8, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_����_����", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_�̵�", "ioriYagamiBackMove", 0, 8, 10, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_������_�̵�", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_����_�̵�", "ioriYagami2", 30, 39, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_����_�̵�", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_��_�̵�", "ioriYagamiBackMove", 0, 8, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_������_��_�̵�", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_����_��_�̵�", "ioriYagami", 50, 58, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_����_��_�̵�", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_����", "ioriYagamiSit", 0, 6, 10, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_������_����", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_�뽬", "ioriYagami", 60, 69, 10, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_������_�뽬", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_���", "ioriYagamiAttackA", 0, 2, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_������_���", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_���", "ioriYagamiAttackB", 0, 6, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_������_���", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_����", "ioriYagamiAttackC", 8, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�̿���_������_����", RectMakeCenter(50, 10, 50, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_����", "ioriYagamiAttackD", 8, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�̿���_������_����", RectMakeCenter(50, 10, 50, 67));
}