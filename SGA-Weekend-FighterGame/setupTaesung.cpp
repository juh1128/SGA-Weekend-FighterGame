#include "stdafx.h"
#include "playGround.h"


//�̹���, �ִϸ��̼� 
void playGround::setupTaesung()
{
	//�̹��� ���ҽ� �ε�
	IMAGEMANAGER->addFrameImage("��", "resource/background2.bmp", 1828, 6144, 1, 8, true);

	IMAGEMANAGER->addFrameImage("�׽�Ʈ_�̵�", "resource/yuhoon/testCharacter/move.bmp", 621, 172, 9, 2, true);

	IMAGEMANAGER->addFrameImage("�׽�Ʈ_�޸���", "resource/yuhoon/testCharacter/run.bmp", 624, 126, 8, 2, true);
	
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_������", "resource/yuhoon/testCharacter/kick.bmp", 377, 164, 5, 2, true);
	
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_����", "resource/yuhoon/testCharacter/jump.bmp", 207, 83,3, 2, true);
	
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_��������", "resource/yuhoon/testCharacter/jump_attack.bmp", 406, 162, 5, 2, true);
	
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_����", "resource/yuhoon/testCharacter/attack.bmp", 435, 156, 5, 2, true);

	
	//�ִϸ��̼� �ε�
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�̵�_������", "�׽�Ʈ_�̵�", 0, 9, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�̵�_������", RectMakeCenter(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�̵�_����", "�׽�Ʈ_�̵�", 10, 19, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�̵�_����", RectMakeCenter(20, 10, 30, 67));
	
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�޸���_������", "�׽�Ʈ_�޸���", 0, 7, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�޸���_������", RectMakeCenter(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�޸���_����", "�׽�Ʈ_�޸���", 8, 15, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�޸���_����", RectMakeCenter(20, 10, 30, 67));
	
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_������_������", "�׽�Ʈ_������", 0, 4, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_������_������", RectMakeCenter(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_������_����", "�׽�Ʈ_������", 5, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_������_����", RectMakeCenter(20, 10, 30, 67));
	
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_����_������", "�׽�Ʈ_����", 3, 5, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_����_������", RectMakeCenter(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_����_����", "�׽�Ʈ_����", 0, 2, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_����_����", RectMakeCenter(20, 10, 30, 67));
	
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_��������_������", "�׽�Ʈ_��������", 0, 4, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_��������_������", RectMakeCenter(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_��������_����", "�׽�Ʈ_��������", 5, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_��������_����", RectMakeCenter(20, 10, 30, 67));
	
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_����_������", "�׽�Ʈ_����", 0, 4, 12, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_����_������", RectMakeCenter(20, 10, 30, 67));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_����_����", "�׽�Ʈ_����", 5, 9, 12, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_����_����", RectMakeCenter(20, 10, 30, 67));

}