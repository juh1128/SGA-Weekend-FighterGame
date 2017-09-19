#include "stdafx.h"
#include "playGround.h"

void playGround::setupYoungjae()
{
	////이미지 로드

	////선택
	//IMAGEMANAGER->addFrameImage("Nanaya_Select", "resource/youngjae/Nanaya/Nanaya_Select.bmp", 2304, 512, 9, 2, true, RGB(255, 0, 255));

	////서있을 때 이미지들
	//IMAGEMANAGER->addFrameImage("Nanaya_Stand", "resource/youngjae/Nanaya/Nanaya_Stand.bmp", 4096, 512, 16, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Nanaya_StandWeakAttack", "resource/youngjae/Nanaya/Nanaya_StandWeakAttack.bmp", 1280, 512, 5, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Nanaya_StandStrongAttack", "resource/youngjae/Nanaya/Nanaya_StandStrongAttack.bmp", 4864, 512, 19, 2, true, RGB(255, 0, 255));

	////걸을 때 이미지들
	//IMAGEMANAGER->addFrameImage("Nanaya_WalkForward", "resource/youngjae/Nanaya/Nanaya_WalkForward.bmp", 3072, 512, 12, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Nanaya_WalkBackward", "resource/youngjae/Nanaya/Nanaya_WalkBackward.bmp", 4352, 512, 17, 2, true, RGB(255, 0, 255));

	////뛸 때 이미지들
	//IMAGEMANAGER->addFrameImage("Nanaya_DashForward", "resource/youngjae/Nanaya/Nanaya_DashForward.bmp", 2560, 512, 10, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Nanaya_DashBackward", "resource/youngjae/Nanaya/Nanaya_DashBackward.bmp", 7680, 512, 30, 2, true, RGB(255, 0, 255));

	////앉을 때 이미지들
	//IMAGEMANAGER->addFrameImage("Nanaya_SitAndUp", "resource/youngjae/Nanaya/Nanaya_SitAndUp.bmp", 2560, 512, 10, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Nanaya_SitWeakAttack", "resource/youngjae/Nanaya/Nanaya_SitWeakAttack.bmp", 1536, 512, 6, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Nanaya_SitStrongAttack", "resource/youngjae/Nanaya/Nanaya_SitStrongAttack.bmp", 2816, 512, 11, 2, true, RGB(255, 0, 255));

	////점프할 때 이미지들
	//IMAGEMANAGER->addFrameImage("Nanaya_Jump", "resource/youngjae/Nanaya/Nanaya_Jump.bmp", 6400, 512, 25, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Nanaya_JumpForward", "resource/youngjae/Nanaya/Nanaya_JumpForward.bmp", 5376, 512, 21, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Nanaya_JumpBackward", "resource/youngjae/Nanaya/Nanaya_JumpBackward.bmp", 7424, 512, 29, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Nanaya_JumpWeakAttack", "resource/youngjae/Nananya/Nanaya_JumpWeakAttack.bmp", 3328, 512, 13, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Nanaya_JumpStrongAttack", "resource/youngjae/Nanaya/Nanaya_JumpStrongAttack.bmp", 2304, 512, 9, 2, true, RGB(255, 0, 255));

	////키애니매니저 설정	

	////서있을 시 - 왼쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_Stand", "Nanaya_Stand", 0, 15, 8, true, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_Stand", RectMake(670, 409, 759, 659));

	////서있을 시 - 오른쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_Stand", "Nanaya_Stand", 31, 16, 8, true, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Right_Stand", RectMake(670, 409, 759, 659));

	////서있을 시 - 왼쪽 약공격
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_StandWeakAttack", "Nanaya_StandWeakAttack", 0, 4, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_StandWeakAttack", RectMake(670, 409, 759, 659));

	////서있을 시 - 왼쪽 강공격
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_StandStrongAttack", "Nanaya_StandStrongAttack", 0, 18, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_StandStrongAttack", RectMake(670, 409, 759, 659));

	////서있을 시 - 오른쪽 약공격
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_StandWeakAttack", "Nanaya_StandWeakAttack", 9, 5, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Right_StandWeakAttack", RectMake(670, 409, 759, 659));

	////서있을 시 - 오른쪽 강공격
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_StandStrongAttack", "Nanaya_StandStrongAttack", 37, 19, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Right_StandStrongAttack", RectMake(670, 409, 759, 659));

	////앞으로 걸을 때 - 왼쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_WalkForward", "Nanaya_WalkForward", 0, 11, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_WalkForward", RectMake(670, 409, 759, 659));

	////앞으로 걸을 때 - 오른쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_WalkForward", "Nanaya_WalkForward", 23, 12, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Right_WalkForward", RectMake(670, 409, 759, 659));

	////뒤로 걸을 때 - 왼쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_WalkBackward", "Nanaya_WalkBackward", 0, 16, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_WalkBackward", RectMake(670, 409, 759, 659));

	////뒤로 걸을 때 - 오른쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_WalkBackward", "Nanaya_WalkBackward", 33, 17, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Right_WalkBackWard", RectMake(670, 409, 759, 659));

	////앞으로 뛸 때 - 왼쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_DashForward", "Nanaya_DashForward", 0, 9, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_DashForward", RectMake(670, 409, 759, 659));

	////앞으로 뛸 때 - 오른쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_DashForward", "Nanaya_DashForward", 17, 10, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Right_DashForward", RectMake(670, 409, 759, 659));

	////뒤로 뛸 때 - 왼쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_DashBackward", "Nanaya_DashBackward", 0, 29, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_DashBackward", RectMake(670, 409, 759, 659));

	////뒤로 뛸 때 - 오른쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_DashBackward", "Nanaya_DashBackward", 59, 30, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Right_DashBackward", RectMake(670, 409, 759, 659));

	////앉았을 때 - 왼쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_Sit", "Nanaya_SitAndUp", 0, 4, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_Sit", RectMake(670, 409, 759, 329));

	////앉았을 때 - 오른쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_Sit", "Nanaya_SitAndUp", 15, 19, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Right_Sit", RectMake(670, 409, 759, 329));

	////앉았을 때 - 왼쪽 약공격
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_SitWeakAttack", "Nanaya_SitWeakAttack", 0, 5, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_SitWeakAttack", RectMake(670, 409, 759, 329));

	////앉았을 때 - 오른쪽 약공격
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_SitWeakAttack", "Nanaya_SitWeakAttack", 11, 6, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Right_SitWeakAttack", RectMake(670, 409, 759, 329));

	////앉았을 때 - 왼쪽 강공격
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_SitStrongAttack", "Nanaya_SitWeakAttack", 0, 10, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_SitStrongAttack", RectMake(670, 409, 759, 329));

	////앉았을 때 - 오른쪽 강공격
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_SitStrongAttack", "Nanaya_SitWeakAttack", 21, 11, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Right_SitStrongAttack", RectMake(670, 409, 759, 329));

	////일어날 때 - 왼쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_SitUp", "Nanaya_SitAndUp", 5, 9, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_SitUp", RectMake(670, 409, 759, 659));

	////일어날 때 - 오른쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_SitUp", "Nanaya_SitAndUp", 10, 14, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Right_SitUp", RectMake(670, 409, 759, 659));

	////앞으로 점프할 때 - 왼쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_JumpForward", "Nanaya_JumpForward", 0, 20, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_JumpForward", RectMake(670, 409, 759, 659));

	////앞으로 점프할 때 - 오른쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_JumpForward", "Nanaya_JumpForward", 41, 21, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Right_JumpForward", RectMake(670, 409, 759, 659));

	////제자리 점프할 때 - 왼쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_Jump", "Nanaya_Jump", 0, 24, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_Jump", RectMake(670, 409, 759, 659));

	////제자리 점프할 때 - 오른쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_Jump", "Nanaya_Jump", 49, 25, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Right_Jump", RectMake(670, 409, 759, 659));

	////뒤로 점프할 때 - 왼쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_JumpBackward", "Nanaya_JumpBackward", 0, 28, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_JumpBackward", RectMake(670, 409, 759, 659));

	////뒤로 점프할 때 - 오른쪽
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Right_JumpBackward", "Nanaya_JumpBackward", 57, 29, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Right_JumpBackward", RectMake(670, 409, 759, 659));

	////점프할 때 - 왼쪽약공격
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_JumpWeakAttack", "Nanaya_JumpWeakAttack", 0, 12, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_JumpWeakAttack", RectMake(670, 409, 759, 659));

	////점프할 때 - 오른쪽약공격
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_JumpWeakAttack", "Nanaya_JumpWeakAttack", 25, 13, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_JumpWeakAttack", RectMake(670, 409, 759, 659));

	////점프할 때 - 왼쪽강공격
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_JumpStrongAttack", "Nanaya_JumpStrongAttack", 0, 8, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_JumpStrongAttack", RectMake(670, 409, 759, 659));

	////점프할 때 - 오른쪽강공격
	//KEYANIMANAGER->addCoordinateFrameAnimation("Nanaya_Left_JumpStrongAttack", "Nanaya_JumpStrongAttack", 17, 9, 8, false, true);
	//KEYANIMANAGER->setCollisionRect("Nanaya_Left_JumpStrongAttack", RectMake(670, 409, 759, 659));
}