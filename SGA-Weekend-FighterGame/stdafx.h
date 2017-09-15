#pragma once
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <iostream>
#include <memory.h>
#include <tchar.h>

using namespace std;

#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "vector2D.h"
#include "utils.h"

#include "imageManager.h"
#include "keyManager.h"
#include "soundManager.h"
#include "timeManager.h"
#include "cameraManager.h"
#include "effectManager.h"
#include "sceneManager.h"
#include "keyAniManager.h"
#include "txtData.h"

using namespace OMICRON_UTIL;

//�ܼ�â ����
#pragma comment(linker , "/entry:WinMainCRTStartup /subsystem:console")

//=======================================
// ## ���� ��Ŭ��� ##
//=======================================
#include "tagMessage.h"
#include "animation.h"
#include "gameObject.h"
#include "world.h"
#include "sceneBase.h"


//========================================
// ## ������ �� ## 17.07.03 ##
//========================================

#define WINNAME (LPTSTR)(TEXT("Omicron ��������"))
#define WINSTARTX 50
#define WINSTARTY 0
#define WINSIZEX 1280
#define WINSIZEY 768
#define WINSTYLE WS_CAPTION | WS_SYSMENU

//=============================================================
// ## 17.07.06 ## Singleton Define ##
//=============================================================

#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define CAMERAMANAGER cameraManager::getSingleton()
#define EFFECTMANAGER effectManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define TXTDATA txtData::getSingleton()
#define KEYANIMANAGER keyAniManager::getSingleton()

#define WORLD SCENEMANAGER->getNowScene()->getWorld()

//=============================================================
// ## 17.07.06 ## Macro ##
//=============================================================

#define SAFE_DELETE(p) {if(p) {delete(p); (p) = NULL;}}
#define SAFE_RELEASE(p) {if(p) {(p)->release(); (p)=NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p) { delete[](p); (p) = NULL;}}

//=============================================================
// ## 17.07.06 ## �������� ##
//=============================================================

extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;
extern bool _isDebugMode;