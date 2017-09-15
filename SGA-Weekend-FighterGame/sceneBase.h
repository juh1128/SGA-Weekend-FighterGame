#pragma once
#include "gameNode.h"



class sceneBase : public gameNode
{
private:
	world*			_world;

public:

	virtual HRESULT init();
	virtual void release();

	virtual void resume() = 0;

	virtual void update();
	virtual void render();

	world* getWorld();
};