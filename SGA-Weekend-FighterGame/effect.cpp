#include "stdafx.h"
#include "effect.h"
#include "animation.h"

effect::effect()
	: _effectImage(NULL),
	_effectAnimation(NULL),
	_isRunning(false),
	_x(0), _y(0)
{
}


effect::~effect()
{

}

HRESULT effect::init(image* effectImage, int frameW, int frameH, int fps)
{
	_isRunning = false;
	_effectImage = effectImage;

	if (!_effectImage) return E_FAIL;

	if (!_effectAnimation) _effectAnimation = new animation;
	_effectAnimation->init(_effectImage->getWidth(), _effectImage->getHeight(), frameW, frameH);
	_effectAnimation->setDefPlayFrame(false, false);
	_effectAnimation->setFPS(fps);
	_effectAnimation->stop();

	return S_OK;
}

void effect::release(void)
{
	_effectImage = NULL;
	SAFE_DELETE(_effectAnimation);
}

void effect::update(void)
{
	if (!_isRunning) return;

	_effectAnimation->frameUpdate();

	if (!_effectAnimation->isPlay()) killEffect();
}

void effect::render(void)
{
	if (!_isRunning) return;

	vector2D renderPos = CAMERAMANAGER->getRelativeVector2D(PointMake(_x,_y));

	float radW = (_effectAnimation->getFrameWidth() * _scale.x) / 2;
	float radH = (_effectAnimation->getFrameHeight() * _scale.y) / 2;

	if (_scale.x == 1.0f && _scale.y == 1.0f)
	{
		_effectImage->aniRender(getMemDC(), renderPos.x - radW, renderPos.y - radH, _effectAnimation);
	}
	else
	{
		_effectImage->scaleAniRender(getMemDC(), renderPos.x - radW, renderPos.y - radH, _effectAnimation, radW*2, radH*2);
	}
}


void effect::startEffect(int x, int y)
{
	if (!_effectImage || !_effectAnimation) return;

	_x = x - (_effectAnimation->getFrameWidth() / 2);
	_y = y - (_effectAnimation->getFrameHeight() / 2);

	_isRunning = true;
	_effectAnimation->start();

}


void effect::killEffect(void)
{
	_isRunning = false;
}
