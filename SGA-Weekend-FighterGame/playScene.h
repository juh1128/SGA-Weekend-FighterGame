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
	int					_selectedCharacter[2];
	character*			_player[2];

	//ī�޶�
	gameObject*			_cameraTarget;

public:
	playScene(int player1, int player2) 
	{ 
		_selectedCharacter[0] = player1; 
		_selectedCharacter[1] = player2;
	}
	virtual ~playScene() {}

	virtual HRESULT	init();
	virtual void	release();

	virtual void	resume();
	virtual void	update();
	virtual void	render();

	void characterSetup();
};