#include "stdafx.h"
#include "iorieffect.h"

HRESULT iorieffect::init(string imageKey, vector2D pos)
{
	gameObject::init("", imageKey, pos);

	_image = IMAGEMANAGER->findImage(imageKey);

	_frameX = _count = 0;

	_fire = pos;

	return S_OK;
}
void iorieffect::release()
{
	gameObject::release();
}

void iorieffect::update()
{
	gameObject::update();

	_count++;
	if (_count % 5 == 0)
	{
		_frameX++;

		//if (_frameX >= _image->getMaxFrameX())this->setDestroy();
	}

}
void iorieffect::render()
{
	//gameObject::render();

	_image->frameRender(getMemDC(), _fire.x, _fire.y, _frameX, 0);
}