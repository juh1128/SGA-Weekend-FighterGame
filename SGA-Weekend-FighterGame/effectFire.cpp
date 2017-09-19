#include "stdafx.h"
#include "effectFire.h"

HRESULT effectFire::init( string imageKey, vector2D pos)
{
	gameObject::init("",imageKey,pos);
	
	_image = IMAGEMANAGER->findImage(imageKey);

	_frameX = _count = 0; 

	_fire = pos;

	return S_OK;
}
void effectFire::release()
{
	gameObject::release();
}

void effectFire::update()
{
	gameObject::update();

	_count++;
	if (_count % 5 == 0)
	{
		_frameX++;

		//if (_frameX >= _image->getMaxFrameX())this->setDestroy();
	}

}
void effectFire::render()
{
	//gameObject::render();

	RECT rc = CAMERAMANAGER->getRenderRect();

	_image->frameRender(getMemDC() , _fire.x - rc.left , _fire.y - rc.top,_frameX,0);
}