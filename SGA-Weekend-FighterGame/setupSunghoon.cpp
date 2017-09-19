#include "stdafx.h"
#include "playGround.h"

void playGround::setupSunghoon()
{
	IMAGEMANAGER->addFrameImage("maiBackDash", "resource/sunghoon/maiBackDash.bmp", 1716, 914, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiBackMove", "resource/sunghoon/maiBackMove.bmp", 2058, 800, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiSitDefence", "resource/sunghoon/maiSitDefence.bmp", 396, 500, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiFrontDash", "resource/sunghoon/maiFrontDash.bmp", 2286, 606, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiIdle", "resource/sunghoon/maiIdle.bmp", 3431, 800, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiJump", "resource/sunghoon/maiJump.bmp", 4802, 1028, 14, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiSit", "resource/sunghoon/maiSit.bmp", 228, 456, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiDefence", "resource/sunghoon/maiDefence.bmp", 1460, 704, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiDamaged", "resource/sunghoon/maiDamaged.bmp", 286, 686, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiKick", "resource/sunghoon/maiKick.bmp", 2676, 838, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiKnockDown", "resource/sunghoon/maiKnockDown.bmp", 1664, 725, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiKnockDownBackMove", "resource/sunghoon/maiKnockDownBackMove.bmp", 5046, 846, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiPunch", "resource/sunghoon/maiPunch.bmp", 1860, 704, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiSitDefence", "resource/sunghoon/maiSitDefence.bmp", 396, 500, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiSitKick", "resource/sunghoon/maiSitKick.bmp", 1047, 474, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiSitPunch", "resource/sunghoon/maiSitPunch.bmp", 3924, 504, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiSitStrongKick", "resource/sunghoon/maiSitStrongKick.bmp", 4466, 486, 11, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiSitStrongPunch", "resource/sunghoon/maiSitStrongPunch.bmp", 1017, 532, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiStrongKick", "resource/sunghoon/maiStrongKick.bmp", 3624, 802, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiStrongPunch", "resource/sunghoon/maiStrongPunch.bmp", 3728, 890, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiDead", "resource/sunghoon/maiDead.bmp", 5170, 796, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("maiWin", "resource/sunghoon/maiWin.bmp", 5170, 932, 10, 2, true, RGB(255, 0, 255));

	//Left -> 왼쪽을보는 Right -> 오른쪽을 보는
	//정지상태
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftIdle", "maiIdle", 12,23, 6, false, true);
	KEYANIMANAGER->setCollisionRect("maiLeftIdle", RectMake(80, 0, 200, 400));
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightIdle", "maiIdle", 0, 11, 6, false,true);
	KEYANIMANAGER->setCollisionRect("maiRightIdle", RectMake(0, 0, 200, 400));

	//이동
	//KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftMove")

	//뒤로가기
	int arrLeftBackMove[] = { 0,1,2,3,4,5 };
	int arrRightBackMove[] = { 6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("maiLeftBackMove", "maiBackMove", arrRightBackMove, 6, 6, true);
	KEYANIMANAGER->setCollisionRect("maiLeftBackMove", RectMake(80, 0, 200, 400));
	KEYANIMANAGER->addArrayFrameAnimation("maiRightBackMove", "maiBackMove", arrLeftBackMove, 6, 6, true);
	KEYANIMANAGER->setCollisionRect("maiRightBackMove", RectMake(0, 0, 200, 400));

	//뒤로대쉬
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftBackDash", "maiBackDash", 0, 5, 16, false, false);
	KEYANIMANAGER->setCollisionRect("maiLeftBackDash", RectMake(30, 0, 250, 457));
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightBackDash", "maiBackDash", 6, 11, 16, false, false);
	KEYANIMANAGER->setCollisionRect("maiRightBackDash", RectMake(0, 0, 250, 457));

	//앉아서막기
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftSitDefence", "maiSitDefence", 0, 1, 2, false, false);
	KEYANIMANAGER->setCollisionRect("maiLeftSitDefence", RectMake(50, 0, 130, 250));
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightSitDefence", "maiSitDefence", 2, 3, 2, false, false);
	KEYANIMANAGER->setCollisionRect("maiRightSitDefence", RectMake(20, 0, 130, 250));

	//앞대쉬
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftFrontDash", "maiFrontDash", 0, 5, 9, false, true);
	KEYANIMANAGER->setCollisionRect("maiLeftFrontDash", RectMake(0, 0, 381, 303));
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightFrontDash", "maiFrontDash", 6, 11, 9, false, true);
	KEYANIMANAGER->setCollisionRect("maiRightFrontDash", RectMake(0, 0, 381, 303));

	//점프
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftJump", "maiJump", 0, 13, 8, false, false);
	KEYANIMANAGER->setCollisionRect("maiLeftJump", RectMake(0, 0, 343, 514));
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightJump", "maiJump", 14, 27, 8, false, false);
	KEYANIMANAGER->setCollisionRect("maiRightJump", RectMake(0, 0, 343, 514));

	//앉기
	int sitArr[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("maiLeftSit", "maiSit", sitArr, 1, 1, true);
	KEYANIMANAGER->setCollisionRect("maiLeftSit", RectMake(20, 0, 200, 228));
	int sitRightArr[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("maiRightSit", "maiSit", sitRightArr, 1, 1, true);
	KEYANIMANAGER->setCollisionRect("maiRightSit", RectMake(0, 0, 200, 228));

	//막기
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftDefence", "maiDefence", 0, 4, 5, false, false);
	KEYANIMANAGER->setCollisionRect("maiLeftDefence", RectMake(30, 0, 232, 352));
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightDefence", "maiDefence", 5, 9, 5, false, false);
	KEYANIMANAGER->setCollisionRect("maiRightDefence", RectMake(0, 0, 232, 352));

	//데미지받는모션
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftDamaged", "maiDamaged", 0, 1, 1, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightDamaged", "maiDamaged", 1, 2, 1, false, false);

	//약발
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftKick", "maiKick", 0, 5, 6, false, false);
	KEYANIMANAGER->setCollisionRect("maiLeftKick", RectMake(200, 0, 190, 419));
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightKick", "maiKick", 6, 11, 6, false, false);
	KEYANIMANAGER->setCollisionRect("maiRightKick", RectMake(50, 0, 190, 419));

	//넘어짐
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftKnockDown", "maiKnockDown", 0, 3, 4, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightKnockDown", "maiKnockDown", 4, 7, 4, false, false);

	//뒤로일어나기
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftKnockDownBackMove", "maiKnockDownBackMove", 0, 7, 8, false, false);
	KEYANIMANAGER->setCollisionRect("maiLeftKnockDownBackMove", RectMake(60, 0, 510, 426));
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightKnockDownBackMove", "maiKnockDownBackMove", 8, 15, 8, false, false);
	KEYANIMANAGER->setCollisionRect("maiRightKnockDownBackMove", RectMake(60, 0, 510, 426));

	//약공
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftPunch", "maiPunch", 0, 3, 4, false, false);
	KEYANIMANAGER->setCollisionRect("maiLeftPunch", RectMake(200, 0, 245, 352));//465
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightPunch", "maiPunch", 4, 7, 4, false, false);
	KEYANIMANAGER->setCollisionRect("maiRightPunch", RectMake(20, 0, 225, 352));

	//앉아서방어
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftSitDefence", "maiSitDefence", 0, 1, 2, false, false);
	KEYANIMANAGER->setCollisionRect("maiLeftSitDefence", RectMake(10, 0, 188, 250));
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightSitDefence", "maiSitDefence", 2, 3, 2, false, false);
	KEYANIMANAGER->setCollisionRect("maiRightSitDefence", RectMake(0, 0, 188, 250));

	//앉아서약발
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftSitKick", "maiSitKick", 0, 2, 5, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightSitKick", "maiSitKick", 3, 5, 5, false, false);

	//앉아서약공
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftSitPunch", "maiSitPunch", 0, 8, 12, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightSitPunch", "maiSitPunch", 9, 17, 12, false, false);

	//앉아서강발
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftSitStrongKick", "maiSitStrongKick", 0, 10, 12, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightSitStrongKick", "maiSitStrongKick", 11, 21, 12, false, false);

	//앉아서강공
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftSitStrongPunch", "maiSitStrongPunch", 0, 2, 7, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightSitStrongPunch", "maiSitStrongPunch", 3, 5, 7, false, false);

	//강공
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftStrongPunch", "maiStrongPunch", 0, 7, 8, false, false);
	KEYANIMANAGER->setCollisionRect("maiLeftStrongPunch", RectMake(200, 0, 226, 445));
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightStrongPunch", "maiStrongPunch", 8, 15, 8, false, false);
	KEYANIMANAGER->setCollisionRect("maiRightStrongPunch", RectMake(30, 0, 236, 445));

	//강발
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftStrongKick", "maiStrongKick", 0, 7, 8, true, false);
	KEYANIMANAGER->setCollisionRect("maiLeftStrongKick", RectMake(200, 0, 180, 401));//436
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightStrongKick", "maiStrongKick", 8, 15, 8, true, false);
	KEYANIMANAGER->setCollisionRect("maiRightStrongKick", RectMake(70, 0, 180, 401));

	//패배
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftDead", "maiDead", 0, 9, 9, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightDead", "maiDead", 10, 19, 9, false, false);

	//승리
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftWin", "maiWin", 0, 9, 9, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightWin", "maiWin", 10, 19, 9, false, false);






}