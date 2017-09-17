#pragma once
#include "sceneBase.h"

class character;
class progressBar;

class playScene : public sceneBase
{
private:
	//���
	image*				_background;
	animation*			_backgroundAnimation;

	//UI
	progressBar*		_progressBar[2];

	//�÷��̾�
	character*			_player[2];

	//ī�޶�
	gameObject*			_cameraTarget;

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