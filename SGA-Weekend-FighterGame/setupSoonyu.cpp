#include "stdafx.h"
#include "playGround.h"

#define PLUSFPS 119

void playGround::setupSoonyu()
{
	//이미지 로드 
	IMAGEMANAGER->addFrameImage("neko1_left", "resource/soonwoo/neko/neko1_left.bmp", 4352, 1790, 17, 7, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("neko1_right", "resource/soonwoo/neko/neko1_right.bmp", 4352, 1790, 17, 7, true, RGB(255, 0, 255));
	//키애니메니져 설정

	//======================STOP======================
	int rightStop[]{ 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightStop", "neko1_right", rightStop, 5, 6, true);
	KEYANIMANAGER->setCollisionRect("nekoRightStop", RectMake(118, 179,	24, 42));

	int leftStop[]{ 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftStop", "neko1_left", leftStop, 5, 6, true);
	KEYANIMANAGER->setCollisionRect("nekoLeftStop", RectMake(118, 179, 24, 42));
	//====================MOVE==========================
	int rightMove[]{ 5,6,7,8,9,10,11,12 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightMove", "neko1_right", rightMove, 8, 7, true);
	KEYANIMANAGER->setCollisionRect("nekoRightMove", RectMake(118, 179, 24, 42));
	int leftMove[]{ 5,6,7,8,9,10,11,12 };
	
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftMove", "neko1_left", leftMove, 8, 7, true);
	KEYANIMANAGER->setCollisionRect("nekoLeftMove", RectMake(118, 179, 24, 42));
	//=====================ChangeSIT===========================

	//DOWN
	int rightChangeSit[]{ 13,14,15,16 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightChangeSit", "neko1_right", rightChangeSit, 4, 20, false);
	KEYANIMANAGER->setCollisionRect("nekoRightChangeSit", RectMake(118, 179, 24, 42));
	int leftChangeSit[]{ 13,14,15,16 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftChangeSit", "neko1_left", leftChangeSit, 4, 20, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftChangeSit", RectMake(118, 179, 24, 42));
	//UP
	int rightChangeSitUp[]{ 16,15,14,13 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightChangeSitUp", "neko1_right", rightChangeSitUp, 4, 20, false);
	KEYANIMANAGER->setCollisionRect("nekoRightChangeSitUp", RectMake(118, 179, 24, 42));
	int leftChangeSitUp[]{ 16,15,14,13 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftChangeSitUp", "neko1_left", leftChangeSitUp, 4, 20, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftChangeSitUp", RectMake(118, 179, 24, 42));
	//========================SIT=============================
	int rightSit[]{ 16 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightSit", "neko1_right", rightSit, 1, 1, false);
	KEYANIMANAGER->setCollisionRect("nekoRightSit", RectMake(122, 200, 26, 22));
	int leftSit[]{ 16  };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftSit", "neko1_left", leftSit, 1, 1, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftSit", RectMake(107, 203, 26, 22));
	//=========================SIT MOVE=============================
	int rightSitMove[]{ 30,31 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightSitMove", "neko1_right", rightSitMove, 2, 2, true);
	KEYANIMANAGER->setCollisionRect("nekoRightSitMove", RectMake(122, 200, 26, 22));
	int leftSitMove[]{ 30 , 31  };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftSitMove", "neko1_left", leftSitMove, 2, 2, true);
	KEYANIMANAGER->setCollisionRect("nekoLeftSitMove", RectMake(107, 203, 26, 22));
	//=========================JUMP================================
	int	rightJump[]{ 17,18,19,20,21,22,23,24,25,26,27,28,29 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoRightJump", "neko1_right", rightJump, 13, 8, false);
	KEYANIMANAGER->setCollisionRect("nekoRightJump", RectMake(118, 179, 24, 42));
	int leftJump[]{ 17,18,19,20,21,22,23,24,25,26,27,28,29 };
	KEYANIMANAGER->addArrayFrameAnimation("nekoLeftJump", "neko1_left", leftJump, 13, 8, false);
	KEYANIMANAGER->setCollisionRect("nekoLeftJump", RectMake(118, 179, 24, 42));
}
