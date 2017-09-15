#pragma once
#include "singletonBase.h"

class gameObject;

class cameraManager : public singletonBase<cameraManager>
{
private:
	gameObject* _target;
	gameObject* _reservedTarget;
	float		_reservedTargetTimer;

	//대상이 범위를 벗어나면 카메라가 쫒아간다.
	vector2D	_pos;
	vector2D	_mapSize;
	POINT		_range;

	//float		_speed;
	//float		_addSpeed;
	//float		_maxSpeed;

	bool		_isMove;

	gameObject* _nullTarget;

	float		_shakeTimer;
	bool		_isShake;
	float		_shakeStrenth;

public:
	HRESULT init();
	void release();

	void connectTarget(gameObject* target, float delayTime = 0.0f);
	void connectNullTarget()
	{
		connectTarget(_nullTarget);
	}

	void setMapSize(int width, int height)
	{
		_mapSize.x = (float)width; _mapSize.y = (float)height;
	}
	vector2D getMapSize() { return _mapSize; }

	void updateCamera();

	void shakeCamera(float strenth);
	RECT getRenderRect();
	vector2D getPos() { return _pos; }

	cameraManager() {}
	~cameraManager() {}

private:
	void moveCamera();

};

