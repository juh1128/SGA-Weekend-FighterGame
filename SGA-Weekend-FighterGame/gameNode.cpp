#include "stdafx.h"
#include "gameNode.h"

image* gameNode::_backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);

gameNode::gameNode()
{
}


gameNode::~gameNode()
{
	
}

HRESULT gameNode::init(void)
{
	_hdc = GetDC(_hWnd);
	_managerInit = false;
		
	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if (_managerInit)
	{
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		SOUNDMANAGER->init();
		TIMEMANAGER->init();
		CAMERAMANAGER->init();
		EFFECTMANAGER->init();
		KEYANIMANAGER->init();
		TXTDATA->init();
	}

	return S_OK;
}

//메모리 해제
void gameNode::release(void)
{
	if (_managerInit)
	{
		KEYMANAGER->releaseSingleton();
		IMAGEMANAGER->releaseSingleton();
		SOUNDMANAGER->releaseSingleton();
		TIMEMANAGER->releaseSingleton();
		CAMERAMANAGER->releaseSingleton();
		EFFECTMANAGER->releaseSingleton();
		KEYANIMANAGER->releaseSingleton();
		TXTDATA->releaseSingleton();
	}
	ReleaseDC(_hWnd, _hdc);
}

//업데이트
void gameNode::update(void)
{

}

//그리기
void gameNode::render(void)
{

}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
		case WM_MOUSEMOVE:
			_ptMouse.x = static_cast<float>LOWORD(lParam);
			_ptMouse.y = static_cast<float>HIWORD(lParam);
		break;

		case WM_KEYDOWN:
			switch (wParam)
			{
				case VK_ESCAPE:
					PostMessage(hWnd, WM_DESTROY, 0, 0);
				break;
			}
		break;

		case WM_DESTROY:
			PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
