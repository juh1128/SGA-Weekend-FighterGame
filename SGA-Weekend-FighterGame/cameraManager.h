#pragma once
#include "singletonBase.h"

class gameObject;

class cameraManager : public singletonBase<cameraManager>
{
private:
	gameObject* _target;
	gameObject* _reservedTarget;
	float		_reservedTargetTimer;

	//����� ������ ����� ī�޶� �i�ư���.
	vector2D	_pos;
	vector2D	_mapSize;
	POINT		_range;

	bool		_isMove;

	gameObject* _nullTarget;

	float		_shakeTimer;
	bool		_isShake;
	float		_shakeStrenth;

	RECT		_renderRC;

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

	void setupRenderRC();

	RECT getRelativeRect(RECT rc);
	POINT getRelativePoint(POINT pt);
	vector2D getRelativeVector2D(vector2D v);

	cameraManager() {}
	~cameraManager() {}

private:
	void moveCamera();

};

