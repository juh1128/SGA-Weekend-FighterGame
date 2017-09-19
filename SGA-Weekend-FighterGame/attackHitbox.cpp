#include "stdafx.h"
#include "attackHitbox.h"





HRESULT attackHitbox::init(int damage, vector2D pos, vector2D size, gameObject* target, float lifeTime, string hitedEffectKey)
{
	gameObject::init("히트박스");

	_pos = pos;
	this->setSize(size.x, size.y);
	_damage = damage;
	_target = target;
	_hitedEffectKey = hitedEffectKey;
	_lifeTime = lifeTime;

	return S_OK;
}
void attackHitbox::release()	 
{
	gameObject::release();
}
void attackHitbox::update()		 
{
	gameObject::update();

	_lifeTime -= TIMEMANAGER->getElapsedTime();
	if (_lifeTime <= 0)
	{
		this->setDestroy();
		return;
	}

	if (_target->isActiveObject())
	{
		RECT temp;
		if (IntersectRect(&temp, &_target->getCollisionRect(), &getRect()))
		{
			POINT hitedPos = { (temp.right + temp.left) / 2, (temp.top + temp.bottom) / 2 };

			_target->sendMessage("attacked", 0.0f, _damage, 0, hitedPos);

			if (_hitedEffectKey != "NONE")
			{				
				EFFECTMANAGER->play(_hitedEffectKey, hitedPos.x, hitedPos.y);
			}
			this->setDestroy();
		}
	}
}
void attackHitbox::render()		 
{
	if (_isDebugMode)
	{
		//카메라 렌더링 영역
		RECT cameraRC = CAMERAMANAGER->getRenderRect();

		HPEN redPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HPEN oldPen;
		HBRUSH oldBrush;
		HDC memDC = getMemDC();

		oldPen = (HPEN)SelectObject(memDC, redPen);
		oldBrush = (HBRUSH)SelectObject(memDC, GetStockObject(NULL_BRUSH));

		RECT rc = this->getRect();
		MoveRect(&rc, -cameraRC.left, -cameraRC.top);
		Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);

		SelectObject(memDC, oldBrush);
		SelectObject(memDC, oldPen);

		DeleteObject(redPen);
	}
}