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
	IMAGEMANAGER->addFrameImage("ioriYagamiJump", "resource/Dongjin/오른쪽점프.bmp", 0, 0, 1960, 350, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiJump2", "resource/Dongjin/왼쪽점프.bmp", 0, 0, 1960, 350, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSit", "resource/Dongjin/오른쪽앉기.bmp", 0, 0, 1876, 400, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSit2", "resource/Dongjin/왼쪽앉기.bmp", 0, 0, 1876, 400, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiBackJump", "resource/Dongjin/오른쪽백점프.bmp", 0, 0, 1130, 400, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiBackJump2", "resource/Dongjin/왼쪽백점프.bmp", 0, 0, 1130, 400, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiDash", "resource/Dongjin/오른쪽대쉬.bmp", 0, 0, 4235, 331, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiDash2", "resource/Dongjin/왼쪽대쉬.bmp", 0, 0, 4235, 331, 9, 1, true, RGB(255, 0, 255));

	//일반공격모션 강손 강발 약손 약발
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackA", "resource/Dongjin/오른쪽약손.bmp", 0, 0, 1175, 400, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackB", "resource/Dongjin/오른쪽약발.bmp", 0, 0, 2478, 400, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackC", "resource/Dongjin/오른쪽강손.bmp", 0, 0, 3568, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackD", "resource/Dongjin/오른쪽강발.bmp", 0, 0, 3634, 400, 9, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("ioriYagamiAttackA2", "resource/Dongjin/왼쪽약손.bmp", 0, 0, 1175, 400, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackB2", "resource/Dongjin/왼쪽약발.bmp", 0, 0, 2478, 400, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackC2", "resource/Dongjin/왼쪽강손.bmp", 0, 0, 3568, 400, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiAttackD2", "resource/Dongjin/왼쪽강발.bmp", 0, 0, 3634, 400, 9, 1, true, RGB(255, 0, 255));

	//점프공격 모션
	IMAGEMANAGER->addFrameImage("ioriYagamiJumpAttackC", "resource/Dongjin/오른쪽점프강손.bmp", 0, 0, 1378, 400, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiJumpAttackA", "resource/Dongjin/오른쪽점프약손.bmp", 0, 0, 773, 322, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiJumpAttackD", "resource/Dongjin/오른쪽점프강발.bmp", 0, 0, 2147, 400, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiJumpAttackB", "resource/Dongjin/오른쪽점프약발.bmp", 0, 0, 1000, 332, 2, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("ioriYagamiJumpAttackC2", "resource/Dongjin/왼쪽점프강손.bmp", 0, 0, 1378, 400, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiJumpAttackA2", "resource/Dongjin/왼쪽점프약손.bmp", 0, 0, 773, 322, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiJumpAttackD2", "resource/Dongjin/왼쪽점프강발.bmp", 0, 0, 2147, 400, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiJumpAttackB2", "resource/Dongjin/왼쪽점프약발.bmp", 0, 0, 1000, 332, 2, 1, true, RGB(255, 0, 255));

	//앉기공격 모션
	IMAGEMANAGER->addFrameImage("ioriYagamiSitAttackA", "resource/Dongjin/오른쪽앉은약손.bmp", 0, 0, 2021, 254, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSitAttackB", "resource/Dongjin/오른쪽앉은약발.bmp", 0, 0, 2598, 254, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSitAttackC", "resource/Dongjin/오른쪽앉기강손.bmp", 0, 0, 3675, 479, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSitAttackD", "resource/Dongjin/오른쪽앉기강발.bmp", 0, 0, 2771, 316, 6, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("ioriYagamiSitAttackA2", "resource/Dongjin/왼쪽앉은약손.bmp", 0, 0, 2021, 254, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSitAttackB2", "resource/Dongjin/왼쪽앉은약발.bmp", 0, 0, 2598, 254, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSitAttackC2", "resource/Dongjin/왼쪽앉기강손.bmp", 0, 0, 3675, 479, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSitAttackD2", "resource/Dongjin/왼쪽앉기강발.bmp", 0, 0, 2771, 316, 6, 1, true, RGB(255, 0, 255));

	//스킬 
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill", "resource/Dongjin/오른쪽스킬1.bmp", 0, 0, 4872, 400, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill2", "resource/Dongjin/왼쪽스킬1.bmp", 0, 0, 4872, 400, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill3", "resource/Dongjin/오른쪽스킬2.bmp", 0, 0, 2153, 400, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill4", "resource/Dongjin/왼쪽스킬2.bmp", 0, 0, 2153, 400, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill5", "resource/Dongjin/오른쪽스킬3.bmp", 0, 0, 6400, 400, 17, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkill6", "resource/Dongjin/왼쪽스킬3.bmp", 0, 0, 6400, 400, 17, 1, true, RGB(255, 0, 255));

	//스킬이팩트
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect", "resource/Dongjin/오른쪽스킬1임팩트.bmp", 0, 0, 12589, 1280, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect2", "resource/Dongjin/왼쪽스킬1임팩트.bmp", 0, 0, 12589, 1280, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect3", "resource/Dongjin/왼쪽스킬2임팩트.bmp", 0, 0, 1283, 206, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect4", "resource/Dongjin/오른쪽스킬2임팩트.bmp", 0, 0, 1283, 206, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect5", "resource/Dongjin/스킬3임팩트.bmp", 0, 0, 16332, 1280, 19, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiSkillEffect6", "resource/Dongjin/스킬3임팩트.bmp", 0, 0, 16332, 1280, 19, 1, true, RGB(255, 0, 255));

	//맞는모션
	IMAGEMANAGER->addFrameImage("ioriYagamiHit", "resource/Dongjin/오른쪽상단기맞음.bmp", 0, 0, 1452, 400, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ioriYagamiHit2", "resource/Dongjin/왼쪽상단기맞음.bmp", 0, 0, 1452, 400, 5, 1, true, RGB(255, 0, 255));

	//예시
	//KEYANIMANAGER->addCoordinateFrameAnimation("테스트_이동_오른쪽", "테스트_이동", 0, 9, 15, false, true);
	//KEYANIMANAGER->setCollisionRect("테스트_이동_오른쪽", RectMakeCenter(20, 10, 30, 67));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_멈춤", "ioriYagamiStop", 0, 8, 10, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_멈춤", RectMakeCenter(150, 200, 300, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_멈춤", "ioriYagamiStop2", 0, 8, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_멈춤", RectMakeCenter(150, 200, 300, 400));



	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_이동", "ioriYagamiMove", 0, 9, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_이동", RectMakeCenter(120, 200, 250, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_이동", "ioriYagamiMove2", 0, 9, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_이동", RectMakeCenter(120, 200, 250, 400));



	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_뒤_이동", "ioriYagamiBackMove", 0, 8, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_뒤_이동", RectMakeCenter(120, 200, 250, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_뒤_이동", "ioriYagamiBackMove2", 0, 8, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_뒤_이동", RectMakeCenter(120, 200, 250, 400));



	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_앉음", "ioriYagamiSit", 0, 6, 10, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_앉음", RectMakeCenter(130, 250, 280, 300));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_앉음", "ioriYagamiSit2", 0, 6, 10, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_앉음", RectMakeCenter(130, 250, 280, 300));



	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_점프", "ioriYagamiJump", 0, 6, 10, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_점프", RectMakeCenter(150, 180, 200, 350));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_점프", "ioriYagamiJump2", 0, 6, 10, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_점프", RectMakeCenter(150, 180, 200, 350));



	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_약손", "ioriYagamiAttackA", 0, 2, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_약손", RectMakeCenter(200, 200, 390, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_약발", "ioriYagamiAttackB", 0, 6, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_약발", RectMakeCenter(175, 200, 350, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_강손", "ioriYagamiAttackC", 8, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_강손", RectMakeCenter(200, 200, 400, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_강발", "ioriYagamiAttackD", 8, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_강발", RectMakeCenter(200, 200, 400, 400));



	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_약손", "ioriYagamiAttackA2", 0, 2, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_약손", RectMakeCenter(200, 200, 390, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_약발", "ioriYagamiAttackB2", 0, 6, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_약발", RectMakeCenter(175, 200, 350, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_강손", "ioriYagamiAttackC2", 8, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_강손", RectMakeCenter(200, 200, 400, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_강발", "ioriYagamiAttackD2", 8, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_강발", RectMakeCenter(200, 200, 400, 400));



	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_앉은_약손", "ioriYagamiSitAttackA", 4, 0, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_앉은_약손", RectMakeCenter(200, 125, 400, 250));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_앉은_약발", "ioriYagamiSitAttackB", 0, 5, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_앉은_약발", RectMakeCenter(225, 120, 425, 250));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_앉은_강손", "ioriYagamiSitAttackC", 8, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_앉은_강손", RectMakeCenter(170, 200, 335, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_앉은_강발", "ioriYagamiSitAttackD", 5, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_앉은_강발", RectMakeCenter(230, 150, 435, 310));



	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_앉은_약손", "ioriYagamiSitAttackA2", 4, 0, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_앉은_약손", RectMakeCenter(200, 125, 400, 250));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_앉은_약발", "ioriYagamiSitAttackB2", 0, 5, 15, false, true);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_앉은_약발", RectMakeCenter(225, 120, 425, 250));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_앉은_강손", "ioriYagamiSitAttackC2", 0, 8, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_앉은_강손", RectMakeCenter(170, 200, 335, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_앉은_강발", "ioriYagamiSitAttackD2", 5, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_앉은_강발", RectMakeCenter(230, 150, 435, 310));


	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_대쉬", "ioriYagamiDash", 0, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_대쉬", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_대쉬", "ioriYagamiDash2", 0, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_대쉬", RectMakeCenter(150, 200, 200, 400));



	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_점프_약손", "ioriYagamiJumpAttackA", 0, 1, 5, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_점프_약손", RectMakeCenter(190, 170, 400, 310));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_점프_약발", "ioriYagamiJumpAttackB", 1, 0, 10, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_점프_약발", RectMakeCenter(250, 170, 485, 310));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_점프_강손", "ioriYagamiJumpAttackC", 3, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_점프_강손", RectMakeCenter(175, 200, 350, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_점프_강발", "ioriYagamiJumpAttackD", 4, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_점프_강발", RectMakeCenter(225, 200, 400, 400));



	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_점프_약손", "ioriYagamiJumpAttackA2", 0, 2, 5, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_점프_약손", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_점프_약발", "ioriYagamiJumpAttackB2", 0, 2, 5, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_점프_약발", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_점프_강손", "ioriYagamiJumpAttackC2", 0, 3, 10, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_점프_강손", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_점프_강발", "ioriYagamiJumpAttackD2", 0, 4, 10, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_점프_강발", RectMakeCenter(150, 200, 200, 400));



	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_스킬", "ioriYagamiSkill", 17, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_스킬", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_스킬", "ioriYagamiSkill2", 0, 17, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_스킬", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_스킬2", "ioriYagamiSkill3", 7, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_스킬2", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_스킬2", "ioriYagamiSkill4", 7, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_스킬2", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_스킬3", "ioriYagamiSkill5", 16, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_스킬3", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_스킬3", "ioriYagamiSkill6", 16, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_스킬3", RectMakeCenter(150, 200, 200, 400));



	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_오른쪽_맞음", "ioriYagamiHit", 4, 0, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_오른쪽_맞음", RectMakeCenter(150, 200, 200, 400));

	KEYANIMANAGER->addCoordinateFrameAnimation("이오리_왼쪽_맞음", "ioriYagamiHit2", 0, 4, 15, false, false);
	KEYANIMANAGER->setCollisionRect("이오리_왼쪽_맞음", RectMakeCenter(150, 200, 200, 400));
}