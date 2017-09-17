#include "stdafx.h"
#include "playGround.h"

void playGround::setupDongjin()
{
	
	IMAGEMANAGER->addFrameImage("ioriYagamiStop", "resource/Dongjin/오른쪽멈춤.bmp", 0, 0, 2770, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiStop2", "resource/Dongjin/왼쪽멈춤.bmp", 0, 0, 2770, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiMove", "resource/Dongjin/오른쪽이동.bmp", 0, 0, 2578, 400, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiMove2", "resource/Dongjin/왼쪽이동.bmp", 0, 0, 2578, 400, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiBackMove", "resource/Dongjin/오른쪽뒷이동.bmp", 0, 0, 2124, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiBackMove2", "resource/Dongjin/왼쪽뒷이동.bmp", 0, 0, 2124, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiJump", "resource/Dongjin/오른쪽점프.bmp", 0, 0, 2310, 400, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSit", "resource/Dongjin/오른쪽앉기.bmp", 0, 0, 1876, 400, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackA", "resource/Dongjin/오른쪽약손.bmp", 0, 0, 1175, 400, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackB", "resource/Dongjin/오른쪽약발.bmp", 0, 0, 2478, 400, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackC", "resource/Dongjin/오른쪽강손.bmp", 0, 0, 3568, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackD", "resource/Dongjin/오른쪽강발.bmp", 0, 0, 3634, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiBackJump", "resource/Dongjin/오른쪽백점프.bmp", 0, 0, 1130, 400, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiBackJump2", "resource/Dongjin/왼쪽백점프.bmp", 0, 0, 1130, 400, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiJumpAttackC", "resource/Dongjin/왼쪽점프강손.bmp", 0, 0, 1378, 400, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill", "resource/Dongjin/오른쪽스킬1.bmp", 0, 0, 4872, 400, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill2", "resource/Dongjin/왼쪽스킬1.bmp", 0, 0, 4872, 400, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect", "resource/Dongjin/오른쪽스킬1임팩트.bmp", 0, 0, 12589, 1280, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect2", "resource/Dongjin/왼쪽스킬1임팩트.bmp", 0, 0, 12589, 1280, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill3", "resource/Dongjin/오른쪽스킬2.bmp", 0, 0, 2153, 400, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill4", "resource/Dongjin/왼쪽스킬2.bmp", 0, 0, 2153, 400, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect3", "resource/Dongjin/왼쪽스킬2임팩트.bmp", 0, 0, 1283, 206, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect4", "resource/Dongjin/오른쪽스킬2임팩트.bmp", 0, 0, 1283, 206, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill5", "resource/Dongjin/오른쪽스킬3.bmp", 0, 0, 6400, 400, 17, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill6", "resource/Dongjin/왼쪽스킬3.bmp", 0, 0, 6400, 400, 17, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect5", "resource/Dongjin/오른쪽스킬3임팩트.bmp", 0, 0, 1283, 206, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect6", "resource/Dongjin/왼쪽스킬3임팩트.bmp", 0, 0, 1283, 206, 6, 1, true, RGB(255, 0, 255));

	//예시
	//KEYANIMANAGER->addCoordinateFrameAnimation("테스트_이동_오른쪽", "테스트_이동", 0, 9, 15, false, true);
	//KEYANIMANAGER->setCollisionRect("테스트_이동_오른쪽", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_멈춤", "ioriYagamiStop", 0, 8, 10, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_멈춤", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_멈춤", "ioriYagamiStop2", 0, 8, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_멈춤", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_이동", "ioriYagamiSkill", 18, 0, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_이동", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_이동", "ioriYagamiMove2", 0, 8, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_이동", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_뒤_이동", "ioriYagamiBackMove", 0, 8, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_뒤_이동", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_뒤_이동", "ioriYagamiBackMove2", 0, 8, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_뒤_이동", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_앉음", "ioriYagamiSit", 0, 6, 10, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_앉음", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_점프", "ioriYagamiJump", 0, 6, 10, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_점프", RectMakeCenter(150, 200, 200, 400));

	//KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_대쉬", "ioriYagami", 60, 69, 10, false, true);
	//KEYANIMANAGER->setCollisionRect("이오리_오른쪽_대쉬", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_약손", "ioriYagamiAttackA", 0, 2, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_약손", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_약발", "ioriYagamiAttackB", 0, 6, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_약발", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_강손", "ioriYagamiAttackC", 8, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_강손", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_강발", "ioriYagamiAttackD", 8, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_강발", RectMakeCenter(150, 200, 200, 400));
}