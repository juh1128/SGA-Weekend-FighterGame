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

	//Left -> 왼쪽을보는 Right -> 오른쪽을 보는
	//정지상태
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftIdle", "maiIdle", 12,23, 6, false, true);

	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightIdle", "maiIdle", 0, 11, 6, false,true);

	//뒤로가기
	int arrLeftBackMove[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("maiLeftBackMove", "maiBackMove", arrLeftBackMove, 6, 3, true);
	int arrRightBackMove[] = { 6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("maiRightBackMove", "maiBackMove", arrRightBackMove, 6, 3, true);

	//뒤로대쉬
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftBackDash", "maiBackDash", 0, 5, 3, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightBackDash", "maiBackDash", 6, 11, 3, false, false);

	//앉아서막기
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftSitDefence", "maiSitDefence", 0, 1, 2, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightSitDefence", "maiSitDefence", 2, 3, 2, false, false);

	//앞대쉬
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftFrontDash", "maiFrontDash", 0, 5, 6, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightFrontDash", "maiFrontDash", 6, 11, 6, false, false);

	//점프
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftJump", "maiJump", 0, 13, 6, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightJump", "maiJump", 14, 17, 6, false, false);

	//앉기
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftSit", "maiSit", 0, 0, 1, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightSit", "maiSit", 1, 1, 1, false, true);

	//막기
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftDefence", "maiDefence", 0, 4, 5, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightDefence", "maiDefence", 5, 9, 5, false, false);

	//데미지받는모션
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftDamaged", "maiDamaged", 0, 0, 1, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightDamaged", "maiDamaged", 1, 1, 1, false, false);

	//약발
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftKick", "maiKick", 0, 5, 6, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightKick", "maiKick", 6, 11, 6, false, false);

	//넘어짐
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftKnockDown", "maiKnockDown", 0, 3, 4, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightKnockDown", "maiKnockDown", 4, 7, 4, false, false);

	//뒤로일어나기
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftKnockDownBackMove", "maiKnockDownBackMove", 0, 7, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightKnockDownBackMove", "maiKnockDownBackMove", 8, 15, 8, false, false);

	//약공
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftPunch", "maiPunch", 0, 3, 4, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightPunch", "maiPunch", 4, 7, 4, false, false);

	//앉아서방어
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftSitDefence", "maiSitDefence", 0, 1, 2, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightSitDefence", "maiSitDefence", 2, 3, 2, false, false);

	//앉아서약발
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftSitKcik", "maiSitKick", 0, 2, 3, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightSitKick", "maiSitKick", 3, 5, 3, false, false);

	//앉아서약공
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftSitPunch", "maiSitPunch", 0, 8, 9, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRIghtSitPunch", "maiSitPunch", 9, 17, 9, false, false);

	//앉아서강발
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftSitStrongKick", "maiSitStrongKick", 0, 10, 9, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightSitStrongKick", "maiSitStrongKick", 11, 21, 9, false, false);

	//앉아서강공
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftSitStrongPunch", "maiSitStrongPunch", 0, 2, 3, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightSitStrongPunch", "maiSitStrongPunch", 3, 5, 3, false, false);

	//강공
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftStrongPunch", "maiStrongPunch", 0, 7, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightStrongPunch", "maiStrongPunch", 8, 15, 8, false, false);

	//강발
	KEYANIMANAGER->addCoordinateFrameAnimation("maiLeftStrongKick", "maiStrongKick", 0, 7, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("maiRightStrongKick", "maiStrongKick", 8, 15, 8, false, false);






}