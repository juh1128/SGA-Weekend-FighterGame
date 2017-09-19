#include "stdafx.h"
#include "athenaeffect.h"

HRESULT athenaeffect::init(string imageKey, vector2D pos)
{
	gameObject::init("", imageKey, pos);

	_image = IMAGEMANAGER->findImage(imageKey);

	_frameX = _count = 0;

	_fire = pos;
	_isFrame = true;

	return S_OK;
}
void athenaeffect::release()
{
	gameObject::release();
}

void athenaeffect::update()
{
	gameObject::update();

	_count++;
	if (_count % 10 == 0)
	{
		
		if (_isFrame)
		{
			_frameX++;
		}
		if (_frameX == 5)_isFrame = false;
		//if (_frameX >= _image->getMaxFrameX())this->setDestroy();
	}

	if (_frameX >= _image->getMaxFrameX())this->setDestroy();

}
void athenaeffect::render()
{
	//gameObject::render();
	vector2D pt = CAMERAMANAGER->getRelativeVector2D(_fire);
	_image->alphaScaleFrameRender(getMemDC(), pt.x, pt.y, _frameX, 0, 300,500,0);
}