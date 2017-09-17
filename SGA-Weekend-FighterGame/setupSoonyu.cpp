#include "stdafx.h"
#include "playGround.h"

#define PLUSFPS 119

void playGround::setupSoonyu()
{
	//이미지 로드 
	IMAGEMANAGER->addFrameImage("neko1_left", "resource/soonwoo/neko1_left.bmp", 4352, 1790, 17, 7, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("neko1_right", "resource/soonwoo/neko1_right.bmp", 4352, 1790, 17, 7, true, RGB(255, 0, 255));
	//키애니메니져 설정

	//======================STOP======================
	int rightStop[]{ 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightStop", "neko1_right", rightStop, 5, 6, true);

	int leftStop[5];
	for (int i = 0; i < 5; i++)
	{
		leftStop[i] = rightStop[i] + PLUSFPS;
	}
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftStop", "neko1_left", leftStop, 5, 6, true);

	//====================MOVE==========================
	int rightMove[]{ 5,6,7,8,9,10,11,12 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightMove", "neko1_right", rightMove, 8, 7, true);

	int leftMove[8];
	for (int i = 0; i < 8; i++)
	{
		leftMove[i] = rightMove[i] + PLUSFPS;
	}
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftMove", "neko1_left", leftMove, 8, 7, true);

	//=====================ChangeSIT===========================

	//DOWN
	int rightChangeSit[]{ 13,14,15,16 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightChangeSit", "neko1_right", rightChangeSit, 4, 20, false);

	int leftChangeSit[4];
	for (int i = 0; i < 4; i++)
	{
		leftChangeSit[i] = rightChangeSit[i] + PLUSFPS;
	}
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftChangeSit", "neko1_left", leftChangeSit, 4, 20, false);

	//UP
	int rightChangeSitUp[]{ 16,15,14,13 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightChangeSitUp", "neko1_right", rightChangeSitUp, 4, 20, false);

	int leftChangeSitUp[4];
	for (int i = 0; i < 4; i++)
	{
		leftChangeSitUp[i] = rightChangeSitUp[i] + PLUSFPS;
	}
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftChangeSitUp", "neko1_left", leftChangeSitUp, 4, 20, false);

	//========================SIT=============================
	int rightSit[]{ 16 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightSit", "neko1_right", rightSit, 1, 1, false);

	int leftSit[]{ 16 + PLUSFPS };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftSit", "neko1_left", leftSit, 1, 1, false);

	//=========================SIT MOVE=============================
	int rightSitMove[]{ 30,31 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightSitMove", "neko1_right", rightSitMove, 2, 2, true);

	int leftSitMove[]{ 30 + PLUSFPS , 31 + PLUSFPS };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftSitMove", "neko1_left", leftSitMove, 2, 2, true);

	//=========================JUMP================================
	int	rightJump[]{ 17,18,19,20,21,22,23,24,25,26,27,28,29 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightJump", "neko1_right", rightJump, 13, 8, false);

	int leftJump[13];
	for (int i = 0; i < 13; i++)
	{
		leftJump[i] = rightJump[i] + PLUSFPS;
	}
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftJump", "neko1_left", leftJump, 13, 8, false);
}
