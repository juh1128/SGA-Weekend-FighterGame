#include "stdafx.h"
#include "playGround.h"

void playGround::setupDongjin()
{
	
	IMAGEMANAGER->addFrameImage("ioriYagamiStop", "resource/Dongjin/�����ʸ���.bmp", 0, 0, 2770, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiStop2", "resource/Dongjin/���ʸ���.bmp", 0, 0, 2770, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiMove", "resource/Dongjin/�������̵�.bmp", 0, 0, 2578, 400, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiMove2", "resource/Dongjin/�����̵�.bmp", 0, 0, 2578, 400, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiBackMove", "resource/Dongjin/�����ʵ��̵�.bmp", 0, 0, 2124, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiBackMove2", "resource/Dongjin/���ʵ��̵�.bmp", 0, 0, 2124, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiJump", "resource/Dongjin/����������.bmp", 0, 0, 2310, 400, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSit", "resource/Dongjin/�����ʾɱ�.bmp", 0, 0, 1876, 400, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackA", "resource/Dongjin/�����ʾ��.bmp", 0, 0, 1175, 400, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackB", "resource/Dongjin/�����ʾ��.bmp", 0, 0, 2478, 400, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackC", "resource/Dongjin/�����ʰ���.bmp", 0, 0, 3568, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackD", "resource/Dongjin/�����ʰ���.bmp", 0, 0, 3634, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiBackJump", "resource/Dongjin/�����ʹ�����.bmp", 0, 0, 1130, 400, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiBackJump2", "resource/Dongjin/���ʹ�����.bmp", 0, 0, 1130, 400, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiJumpAttackC", "resource/Dongjin/������������.bmp", 0, 0, 1378, 400, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill", "resource/Dongjin/�����ʽ�ų1.bmp", 0, 0, 4872, 400, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill2", "resource/Dongjin/���ʽ�ų1.bmp", 0, 0, 4872, 400, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect", "resource/Dongjin/�����ʽ�ų1����Ʈ.bmp", 0, 0, 12589, 1280, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect2", "resource/Dongjin/���ʽ�ų1����Ʈ.bmp", 0, 0, 12589, 1280, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill3", "resource/Dongjin/�����ʽ�ų2.bmp", 0, 0, 2153, 400, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill4", "resource/Dongjin/���ʽ�ų2.bmp", 0, 0, 2153, 400, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect3", "resource/Dongjin/���ʽ�ų2����Ʈ.bmp", 0, 0, 1283, 206, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect4", "resource/Dongjin/�����ʽ�ų2����Ʈ.bmp", 0, 0, 1283, 206, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill5", "resource/Dongjin/�����ʽ�ų3.bmp", 0, 0, 6400, 400, 17, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill6", "resource/Dongjin/���ʽ�ų3.bmp", 0, 0, 6400, 400, 17, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect5", "resource/Dongjin/�����ʽ�ų3����Ʈ.bmp", 0, 0, 1283, 206, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect6", "resource/Dongjin/���ʽ�ų3����Ʈ.bmp", 0, 0, 1283, 206, 6, 1, true, RGB(255, 0, 255));

	//����
	//KEYANIMANAGER->addCoordinateFrameAnimation("�׽�Ʈ_�̵�_������", "�׽�Ʈ_�̵�", 0, 9, 15, false, true);
	//KEYANIMANAGER->setCollisionRect("�׽�Ʈ_�̵�_������", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_����", "ioriYagamiStop", 0, 8, 10, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_������_����", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_����_����", "ioriYagamiStop2", 0, 8, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_����_����", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_�̵�", "ioriYagamiSkill", 18, 0, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_������_�̵�", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_����_�̵�", "ioriYagamiMove2", 0, 8, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_����_�̵�", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_��_�̵�", "ioriYagamiBackMove", 0, 8, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_������_��_�̵�", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_����_��_�̵�", "ioriYagamiBackMove2", 0, 8, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_����_��_�̵�", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_����", "ioriYagamiSit", 0, 6, 10, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_������_����", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_����", "ioriYagamiJump", 0, 6, 10, false, false);
	KEYANIMANAGER->setCollisionRect("�̿���_������_����", RectMakeCenter(150, 200, 200, 400));

	//KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_�뽬", "ioriYagami", 60, 69, 10, false, true);
	//KEYANIMANAGER->setCollisionRect("�̿���_������_�뽬", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_���", "ioriYagamiAttackA", 0, 2, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_������_���", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_���", "ioriYagamiAttackB", 0, 6, 15, false, true);
	KEYANIMANAGER->setCollisionRect("�̿���_������_���", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_����", "ioriYagamiAttackC", 8, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�̿���_������_����", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("�̿���_������_����", "ioriYagamiAttackD", 8, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("�̿���_������_����", RectMakeCenter(150, 200, 200, 400));
}