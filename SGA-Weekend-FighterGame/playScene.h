#pragma once
#include "sceneBase.h"

class gameObject;
class animation;
class callbackTest;

class character;

class playScene : public sceneBase
{
private:
	image*				_background;
	animation*			_backgroundAnimation;

	character*			_player[2];

	gameObject*			_cameraTarget;

	callbackTest*		_cbTest;

public:
	playScene() {}
	virtual ~playScene() {}

	virtual HRESULT	init();
	virtual void	release();

	virtual void	resume();
	virtual void	update();
	virtual void	render();

	void characterSetup();
};