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

	//Ÿ���� ���� ��� nullTarget�� Ÿ������ �ν��Ѵ�.
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
		//������ Ÿ���� ������, �ϴ� Ÿ���� �����صд�.
		else
		{
			_reservedTargetTimer = delayTime;
			_reservedTarget = target;
		}
	}
}

void cameraManager::updateCamera()
{
	//����� Ÿ���� ���� ���, Ÿ�̸� üũ
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
		//Ÿ���� ���� �ȿ� �ִ���, �ۿ� �ִ��� Ȯ���Ѵ�.
		RECT rangeRC = RectMakeCenter((int)_pos.x, (int)_pos.y, (int)_range.x, (int)_range.y);
		RECT targetRC = _target->getRect();

		//Ÿ���� ���� ������ �����̶� ���������� ���
		if (!(rangeRC.left <= targetRC.left && rangeRC.right >= targetRC.right &&
			rangeRC.top <= targetRC.top && rangeRC.bottom >= targetRC.bottom))
		{
			//ī�޶����� �����̶�� �Ѵ�.
			_isMove = true;
		}
		_isMove = true;

		//ī�޶� Ÿ���� ī�޶��� �߽ɿ� �� ������ �̵��Ѵ�.
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

	//���� ī�޶��� ���� ������ �� ������ �Ѿ�ٸ� ��ġ ����
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

	//ī�޶� ��鸲
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
	//ī�޶� ��ġ�� �߽����� ȭ�� ũ�⸸ŭ Rect�� ���� ��ȯ.
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