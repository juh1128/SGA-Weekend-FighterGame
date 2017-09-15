#include "stdafx.h"
#include "character.h"


HRESULT character::init(string characterName, vector2D pos, string animationKeyName)
{
	gameObject::init(characterName, "", pos);
	this->setAnimation(animationKeyName);
	this->setSize(_animation->getFrameWidth(), _animation->getFrameHeight());

	return S_OK;
}
void character::release()
{
	gameObject::release();
}
void character::update()
{
	gameObject::update();

	this->_animation->frameUpdate();
}
void character::render()
{
	gameObject::render();

	//디버그 모드일 경우 히트박스 렉트를 그려준다.
	if (_isDebugMode)
	{
		HPEN redPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HPEN oldPen;
		HBRUSH oldBrush;
		HDC memDC = getMemDC();

		oldPen = (HPEN)SelectObject(memDC, redPen);
		oldBrush = (HBRUSH)SelectObject(memDC, GetStockObject(NULL_BRUSH));

		RECT rc = getCollisionRect();
		Rectangle(memDC, rc.left, rc.top, rc.right, rc.bottom);

		SelectObject(memDC, oldBrush);
		SelectObject(memDC, oldPen);

		DeleteObject(redPen);
	}
}

RECT character::getCollisionRect()
{
	RECT collisionRC = _animation->getCollisionRect();
	int width = collisionRC.right - collisionRC.left;
	int height = collisionRC.bottom - collisionRC.top;
	MoveRect(&collisionRC, (int)(_pos.x + width*0.5f), (int)(_pos.y + height*0.5f));
	return collisionRC;
}

