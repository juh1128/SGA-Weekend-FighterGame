#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{

}

HRESULT progressBar::init(string imageBack, string imageFront, int width, int height)
{
	gameObject::init("게이지");
	this->setSize(width, height);
	_progressWidth = width;

	_connectedObject = NULL;

	_progressBack = IMAGEMANAGER->findImage(imageBack);
	_progressFront = IMAGEMANAGER->findImage(imageFront);

	return S_OK;
}

void progressBar::connectObject(gameObject* obj, vector2D offset)
{
	_connectedObject = obj;
	_offset = offset;
}

void progressBar::setPosition(vector2D pos)
{
	_connectedObject = NULL;
	_pos = pos;
}

void progressBar::release()									  
{

}

void progressBar::update(float current, float max)
{
	gameObject::update();

	if (_connectedObject)
	{
		_pos = _connectedObject->_pos;
	}
	_progressWidth = current / max * getSize().x;
}

void progressBar::render(bool isAbsolute)
{
	//center 피봇
	vector2D renderPos = _pos + _offset - getSize() / 2;

	if (isAbsolute)
	{
		RECT cameraRC = CAMERAMANAGER->getRenderRect();

		//카메라 위치에 따라서 렌더링됨. (절대 좌표계)
		renderPos.x += cameraRC.left;
		renderPos.y += cameraRC.top;

		_progressBack->scaleRender(this->getMemDC(), renderPos.x, renderPos.y,
			getSize().x, getSize().y);

		_progressFront->scaleRender(this->getMemDC(), renderPos.x, renderPos.y,
			_progressWidth, getSize().y);
	}
	else
	{
		_progressBack->scaleRender(this->getMemDC(), renderPos.x, renderPos.y,
			getSize().x, getSize().y);

		_progressFront->scaleRender(this->getMemDC(), renderPos.x, renderPos.y,
			_progressWidth, getSize().y);
	}
}

