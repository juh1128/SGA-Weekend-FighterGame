#include "stdafx.h"
#include "playGround.h"

void playGround::setupYuhoon()
{
	//이미지 리소스 로드
	IMAGEMANAGER->addFrameImage("맵", "resource/yuhoon/background2.bmp", 914, 3072, 1, 8, true);
	IMAGEMANAGER->addFrameImage("테스트_이동", "resource/yuhoon/testCharacter/move.bmp", 625, 168,
		10, 2, true);
	IMAGEMANAGER->addFrameImage("테스트_달리기", "resource/yuhoon/testCharacter/run.bmp", 624, 126,
		8, 2, true);
	IMAGEMANAGER->addFrameImage("테스트_발차기", "resource/yuhoon/testCharacter/kick.bmp", 377, 164,
		5, 2, true);
	IMAGEMANAGER->addFrameImage("테스트_점프", "resource/yuhoon/testCharacter/jump.bmp", 207, 83,
		3, 2, true);
	IMAGEMANAGER->addFrameImage("테스트_점프공격", "resource/yuhoon/testCharacter/jump_attack.bmp", 406, 162,
		5, 2, true);
	IMAGEMANAGER->addFrameImage("테스트_공격", "resource/yuhoon/testCharacter/attack.bmp", 399, 178,
		5, 2, true);

	//인터페이스
	IMAGEMANAGER->addImage("HP바_백", "resource/yuhoon/ui/hpBarBack.bmp", 53, 5, true);
	IMAGEMANAGER->addImage("HP바_프론트", "resource/yuhoon/ui/hpBarFront.bmp", 53, 5, true);


	//애니메이션 로드
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_이동_오른쪽", "테스트_이동", 0, 9, 15, false, true);
	KEYANIMANAGER->setCollisionRect("테스트_이동_오른쪽", RectMake(19,9,30,65));
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_이동_왼쪽", "테스트_이동", 10, 19, 15, false, true);
	KEYANIMANAGER->setCollisionRect("테스트_이동_왼쪽", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_달리기_오른쪽", "테스트_달리기", 0, 7, 15, false, true);
	KEYANIMANAGER->setCollisionRect("테스트_달리기_오른쪽", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_달리기_왼쪽", "테스트_달리기", 8, 15, 15, false, true);
	KEYANIMANAGER->setCollisionRect("테스트_달리기_왼쪽", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_발차기_오른쪽", "테스트_발차기", 0, 4, 15, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_발차기_오른쪽", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_발차기_왼쪽", "테스트_발차기", 5, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_발차기_왼쪽", RectMake(19, 9, 30, 65));
	
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_점프_오른쪽", "테스트_점프", 3, 5, 15, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_점프_오른쪽", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_점프_왼쪽", "테스트_점프", 0, 2, 15, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_점프_왼쪽", RectMake(19, 9, 30, 65));

	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_점프공격_오른쪽", "테스트_점프공격", 0, 4, 15, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_점프공격_오른쪽", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_점프공격_왼쪽", "테스트_점프공격", 5, 9, 15, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_점프공격_왼쪽", RectMake(19, 9, 30, 65));
	
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_공격_오른쪽", "테스트_공격", 0, 4, 12, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_공격_오른쪽", RectMake(19, 9, 30, 65));
	KEYANIMANAGER->addCoordinateFrameAnimation("테스트_공격_왼쪽", "테스트_공격", 5, 9, 12, false, false);
	KEYANIMANAGER->setCollisionRect("테스트_공격_왼쪽", RectMake(19, 9, 30, 65));
	

}