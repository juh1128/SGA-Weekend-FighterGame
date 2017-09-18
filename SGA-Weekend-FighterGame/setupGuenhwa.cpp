#include "stdafx.h"
#include "playGround.h"

void playGround::setupGuenhwa()
{
	IMAGEMANAGER->addFrameImage("terryIdle", "resource/geunhwa/terryIdle.bmp", 2288, 800, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryMove", "resource/geunhwa/terryMove.bmp", 1716, 914, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryBackMove", "resource/geunhwa/terryBackMove.bmp", 1716, 914, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryDashMove", "resource/geunhwa/terryDashMove.bmp", 4570, 800, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryBackDash", "resource/geunhwa/terryBackDash.bmp", 286, 800, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terrySit", "resource/geunhwa/terrySit.bmp", 858, 800, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryJump", "resource/geunhwa/terryJump.bmp", 1716, 1142, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryMoveJump", "resource/geunhwa/terryMoveJump.bmp", 1430, 1142, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryBackMoveJump", "resource/geunhwa/terryBackMoveJump.bmp", 1430, 1142, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terryDefence", "resource/geunhwa/terryDefence.bmp", 1029, 800, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("terrySitDefence", "resource/geunhwa/terrySitDefence.bmp", 858, 800, 3, 2, true, RGB(255, 0, 255));
	
	
	//// Left::���ʿ� �� �ִ»��� // Right::�����ʿ� �� �ִ� ����
	
	//���ִ»��� (Idle)
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightIdle", "terryIdle", 0, 7, 8, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftIdle", "terryIdle", 8, 15, 8, false, true);
	
	//����
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightMove", "terryMove", 0, 5, 6, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftMove", "terryMove", 6, 11, 6, false, false);
	
	//�޹���
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightBackMove", "terryBackMove", 0, 5, 6, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftBackMove", "terryBackMove", 6, 11, 6, false, false);
	
	//�뽬����
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightDashMove", "terryDashMove", 0, 9, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftDashMove", "terryDashMove", 19, 10, 8, false, false);
	
	//��뽬
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightBackDash", "terryBackDash", 0, 0, 1, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftBackDash", "terryBackDash", 1, 1, 1, false, false);
	
	//�ɱ�
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightSit", "terrySit", 0, 2, 6, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftSit", "terrySit", 3, 5, 6, false, false);
	
	//���ڸ� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightJump", "terryJump", 0, 5, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLefttJump", "terryJump", 6, 11, 8, false, false);
	
	//���� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightMoveJump", "terryMoveJump", 0, 4, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLefttMoveJump", "terryMoveJump", 5, 9, 8, false, false);
	
	//�� ���� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightBackMoveJump", "terryBackMoveJump", 0, 4, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftBackMoveJump", "terryBackMoveJump", 5, 9, 8, false, false);
	
	//���ĵ� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightDefence", "terryDefence", 0, 2, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftDefence", "terryDefence", 3, 5, 8, false, false);
	
	//���� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("terryRightSitDefence", "terrySitDefence", 0, 2, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("terryLeftSitDefence", "terrySitDefence", 3, 5, 8, false, false);

}