#include "stdafx.h"
#include "playGround.h"

void playGround::setupSiyeong()
{
	//ÃÊ±âÈ­
	IMAGEMANAGER->addFrameImage("athena", "resource/siyeong/´ë±â,¾É±â.bmp", 100, WINSIZEY / 2 - 50, 2880, 2520, 8, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("athena2", "resource/siyeong/¿ÞÂÊ°È±â,¾É±â.bmp", 100, WINSIZEY / 2 - 50, 2880, 2520, 8, 6, true, RGB(255, 0, 255));
	//
	////¾Ö´Ï¸ÞÀÌ¼Ç
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

	//int rightJump[] = { 31,32,33,34,35,36,37,38,39 };
	//KEYANIMANAGER->addArrayFrameAnimation("athenaLeftJump", "athena", rightJump, 9, 15, true);
	//
	//int rightSit[] = { 40,41,42,43,44 };
	//KEYANIMANAGER->addArrayFrameAnimation("athenaLeftSit", "athena", rightSit, 5, 10, true);
	//
	//int rightDash[] = { 47,48,49,50,51 };
	//KEYANIMANAGER->addArrayFrameAnimation("athenaLeftDash", "athena", rightDash, 7, 15, true);
	//
	//int rightBackDash[] = { 52,53 };
	//KEYANIMANAGER->addArrayFrameAnimation("athenaLeftBackDash", "athena", rightBackDash, 2, 10, true);
	//
	//int rightHandAttack[] = { 55,56,57,58,59 };
	//KEYANIMANAGER->addArrayFrameAnimation("athenaLeftHandAttack", "athena", rightHandAttack, 5, 10, true);
	//
	//int rightFootAttack[] = { 60,61 };
	//KEYANIMANAGER->addArrayFrameAnimation("athenaLeftFootAttack", "athena", rightFootAttack, 2, 10, true);
	//
	//int rightHandCount[] = { 63,64,65,66,67 };
	//KEYANIMANAGER->addArrayFrameAnimation("athenaLeftFootAttack", "athena", rightHandCount, 5, 10, true);
	//
	//int rightFootCount[] = { 71,72,73,74,75,76,77 };
	//KEYANIMANAGER->addArrayFrameAnimation("athenaLeftFootCount", "athena", rightFootCount, 7, 15, true);

}