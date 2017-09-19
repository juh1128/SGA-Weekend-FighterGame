#include "stdafx.h"
#include "playGround.h"

void playGround::setupSiyeong()
{
	//초기화
	IMAGEMANAGER->addFrameImage("athena", "resource/siyeong/대기,앉기.bmp", 100, WINSIZEY / 2 - 50, 2880, 2520, 8, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("athena2", "resource/siyeong/왼쪽걷기,앉기.bmp", 100, WINSIZEY / 2 - 50, 2880, 2520, 8, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("athenaAction", "resource/siyeong/강약손발.bmp", 100, WINSIZEY / 2 - 50, 2880, 1680, 8, 4, true, RGB(255, 0, 255));


	////애니메이션
	int leftStop[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftStop", "athena2", leftStop, 8, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftStop", RectMake(90, 40, 130, 350));
	
	int rightStop[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightStop", "athena", rightStop, 8, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaRightStop", RectMake(90, 40, 130, 350));

	int rightMove[] = { 8,9,10,11,12,13,14,15,16,17,18,19 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightMove", "athena", rightMove, 12, 15, true);
	KEYANIMANAGER->setCollisionRect("athenaRightMove", RectMake(90, 40, 130, 350));

	
	int leftMove[] = { 8,9,10,11,12,13,14,15,16,17,18,19 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaLeftMove", "athena2", leftMove, 12, 15, true);
	KEYANIMANAGER->setCollisionRect("athenaLeftMove", RectMake(90, 40, 130, 350));
	
	int rightBackStep[] = { 24,25,26,27,28,29,30,31 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightBackStep", "athena", rightBackStep, 8, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaRightBackStep", RectMake(90, 40, 130, 350));

	int rightJump[] = { 32,33,34,35,36,37,38,39,40 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightJump", "athena", rightJump, 9, 13, false);
	KEYANIMANAGER->setCollisionRect("athenaRightJump", RectMake(90, 40, 130, 350));
	
	int rightSit[] = { 42,43,44,45 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightSit", "athena", rightSit, 4, 8, true);
	KEYANIMANAGER->setCollisionRect("athenaRightSit", RectMake(90, 130, 130, 260));

	
	//int rightDash[] = { 47,48,49,50,51 };
	//KEYANIMANAGER->addArrayFrameAnimation("athenaLeftDash", "athena", rightDash, 7, 15, true);
	//
	//int rightBackDash[] = { 52,53 };
	//KEYANIMANAGER->addArrayFrameAnimation("athenaLeftBackDash", "athena", rightBackDash, 2, 10, true);
	//
	int rightHandAttack[] = { 8,9,10,11,12 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightHandAttack", "athenaAction", rightHandAttack, 5, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaRightHandAttack", RectMake(90, 40, 130, 350));
	
	int rightFootAttack[] = { 13,14 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightFootAttack", "athenaAction", rightFootAttack, 2, 5, true);
	KEYANIMANAGER->setCollisionRect("athenaRightFootAttack", RectMake(90, 40, 130, 350));

	int rightHandCount[] = { 16,17,18,19,20 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightHandCount", "athenaAction", rightHandCount, 5, 10, true);
	KEYANIMANAGER->setCollisionRect("athenaRightHandCount", RectMake(90, 40, 130, 350));
	
	int rightFootCount[] = { 24,25,26,27,28,29,30 };
	KEYANIMANAGER->addArrayFrameAnimation("athenaRightFootCount", "athenaAction", rightFootCount, 7, 15, true);
	KEYANIMANAGER->setCollisionRect("athenaRightFootCount", RectMake(90, 40, 130, 350));

}