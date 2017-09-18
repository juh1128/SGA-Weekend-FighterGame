#include "stdafx.h"
#include "cameraManager.h"
#include "gameObject.h"

HRESULT cameraManager::init()
{
	_pos.x = WINSIZEX / 2;
	_pos.y = WINSIZEY / 2;
	_mapSize.x = WINSIZEX;
	_mapSize.y = WINSIZEY;

	_range.x = WINSIZEX / 2;
	_range.y = WINSIZEY / 2;

	//_speed = 0.0f;
	//_addSpeed = 0.3f;
	//_maxSpeed = 10.0f;

	_shakeTimer = 0.0f;
	_isShake = false;
	_shakeStrenth = 0;

	//타겟이 없을 경우 nullTarget을 타겟으로 인식한다.
	_nullTarget = new gameObject;
	_nullTarget->init("NullObject");
	_nullTarget->_pos = vector2D(WINSIZEX / 2, WINSIZEY / 2);
	this->connectTarget(_nullTarget);

	_reservedTarget = NULL;
	_reservedTargetTimer = 0.0f;

	return S_OK;
}

void cameraManager::connectTarget(gameObject* target, float delayTime)
{
	if (target)
	{
		if (delayTime == 0.0f)
		{
			_target = target;
			_pos = target->_pos;
			//_speed = 0;

			moveCamera();
		}
		//딜레이 타임이 있으면, 일단 타겟을 예약해둔다.
		else
		{
			_reservedTargetTimer = delayTime;
			_reservedTarget = target;
		}
	}
}

void cameraManager::updateCamera()
{
	//예약된 타겟이 있을 경우, 타이머 체크
	if (_reservedTarget)
	{
		_reservedTargetTimer -= TIMEMANAGER->getElapsedTime();
		if (_reservedTargetTimer <= 0.0f)
		{
			connectTarget(_reservedTarget);
			_reservedTarget = NULL;
			_reservedTargetTimer = 0.0f;
		}
	}

	if (_target->isLive())
	{
		//타겟이 범위 안에 있는지, 밖에 있는지 확인한다.
		RECT rangeRC = RectMakeCenter((int)_pos.x, (int)_pos.y, (int)_range.x, (int)_range.y);
		RECT targetRC = _target->getRect();

		//타겟이 범위 밖으로 조금이라도 삐져나왔을 경우
		if (!(rangeRC.left <= targetRC.left && rangeRC.right >= targetRC.right &&
			rangeRC.top <= targetRC.top && rangeRC.bottom >= targetRC.bottom))
		{
			//카메라한테 움직이라고 한다.
			_isMove = true;
		}
		_isMove = true;

		//카메라가 타겟이 카메라의 중심에 올 때까지 이동한다.
		if (_isMove)
			moveCamera();
	}
	else
	{
		_nullTarget->_pos = _pos;
		connectNullTarget();
	}

	setupRenderRC();
}

void cameraManager::moveCamera()
{
	vector2D targetCenterPos = _target->_pos;

	_pos = targetCenterPos;
	_isMove = false;

	//만약 카메라의 렌더 영역이 맵 밖으로 넘어갔다면 위치 보정
	RECT renderRect = RectMakeCenter((int)_pos.x, (int)_pos.y, WINSIZEX, WINSIZEY);
	if (renderRect.left < 0)
	{
		_pos.x -= renderRect.left;
	}
	if (renderRect.top < 0)
	{
		_pos.y -= renderRect.top;
	}
	if (renderRect.right > _mapSize.x)
	{
		_pos.x -= renderRect.right - _mapSize.x;
	}
	if (renderRect.bottom > _mapSize.y)
	{
		_pos.y -= renderRect.bottom - _mapSize.y;
	}

	//카메라 흔들림
	if (_isShake)
	{
		if (TIMEMANAGER->getWorldTime() - _shakeTimer > 0.1f)
		{
			_shakeStrenth -= 4.0f;
			_shakeTimer = TIMEMANAGER->getWorldTime();

			if (_shakeStrenth <= 0)
			{
				_isShake = false;
				_shakeStrenth = 0;
			}
		}
	}
}

RECT cameraManager::getRenderRect()
{
	return _renderRC;
}

void cameraManager::shakeCamera(float strenth)
{
	if (!_isShake)
	{
		_shakeTimer = TIMEMANAGER->getWorldTime();
		_isShake = true;
		_shakeStrenth = strenth;
	}
}

void cameraManager::release()
{
	_target = NULL;
	_nullTarget->release();
	SAFE_DELETE(_nullTarget);
}



void cameraManager::setupRenderRC()
{
	//카메라 위치를 중심으로 화면 크기만큼 Rect를 만들어서 반환.
	vector2D renderPos = _pos;
	if (_isShake)
	{
		static int dir = 1;
		renderPos.y += _shakeStrenth * dir;
		dir *= -1;

	}
	_renderRC = RectMakeCenter((int)renderPos.x, (int)renderPos.y, WINSIZEX, WINSIZEY);
}

RECT cameraManager::getRelativeRect(RECT rc)
{
	MoveRect(&rc, -_renderRC.left, -_renderRC.top);
	return std::move(rc);
}
POINT cameraManager::getRelativePoint(POINT pt)
{
	pt.x -= _renderRC.left;
	pt.y -= _renderRC.top;
	return std::move(pt);
}
vector2D cameraManager::getRelativeVector2D(vector2D v)
{
	v.x -= _renderRC.left;
	v.y -= _renderRC.top;
	return std::move(v);
}