#include "stdafx.h"
#include "playGround.h"

void playGround::setupYuhoon()
{
	//�̹��� ���ҽ� �ε�
	IMAGEMANAGER->addFrameImage("��", "resource/yuhoon/background2.bmp", 914, 3072, 1, 8, true);
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_�̵�", "resource/yuhoon/testCharacter/move.bmp", 625, 168,
		10, 2, true);
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_�޸���", "resource/yuhoon/testCharacter/run.bmp", 624, 126,
		8, 2, true);
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_������", "resource/yuhoon/testCharacter/kick.bmp", 377, 164,
		5, 2, true);
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_����", "resource/yuhoon/testCharacter/jump.bmp", 207, 83,
		3, 2, true);
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_��������", "resource/yuhoon/testCharacter/jump_attack.bmp", 406, 162,
		5, 2, true);
	IMAGEMANAGER->addFrameImage("�׽�Ʈ_����", "resource/yuhoon/testCharacter/attack.bmp", 399, 178,
		5, 2, true);

	//�������̽�
	IMAGEMANAGER->addImage("HP��_��", "resource/yuhoon/ui/hpBarBack.bmp", 53, 5, true);
	IMAGEMANAGER->addImage("HP��_����Ʈ", "resource/yuhoon/ui/hpBarFront.bmp", 53, 5, true);


	//�ִϸ��̼� �ε�
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�̵�_������", "�׽�Ʈ_�̵�", 0, 9, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�̵�_������", RectMake(19,9,30,65));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�̵�_����", "�׽�Ʈ_�̵�", 10, 19, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�̵�_����", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�޸���_������", "�׽�Ʈ_�޸���", 0, 7, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�޸���_������", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�޸���_����", "�׽�Ʈ_�޸���", 8, 15, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�޸���_����", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_������_������", "�׽�Ʈ_������", 0, 4, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_������_������", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_������_����", "�׽�Ʈ_������", 5, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_������_����", RectMake(19, 9, 30, 65));
	
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_����_������", "�׽�Ʈ_����", 3, 5, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_����_������", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_����_����", "�׽�Ʈ_����", 0, 2, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_����_����", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_��������_������", "�׽�Ʈ_��������", 0, 4, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_��������_������", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_��������_����", "�׽�Ʈ_��������", 5, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_��������_����", RectMake(19, 9, 30, 65));
	
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_����_������", "�׽�Ʈ_����", 0, 4, 12, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_����_������", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_����_����", "�׽�Ʈ_����", 5, 9, 12, false, false);
	KEYANIMANAGER->setCollisionRect("�׽�Ʈ_����_����", RectMake(19, 9, 30, 65));
	

}