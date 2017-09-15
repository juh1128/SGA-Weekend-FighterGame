#include "stdafx.h"
#include "sceneBase.h"


HRESULT sceneBase::init()
{
	_world = new world();
	_world->init();

	return S_OK;
}

void sceneBase::release()
{
	_world->release();
	SAFE_DELETE(_world);
}

void sceneBase::update()	   
{
	_world->update();
	
	EFFECTMANAGER->update();
	CAMERAMANAGER->updateCamera();
}
void sceneBase::render()	   
{
	_world->render();

	EFFECTMANAGER->render();
}

world* sceneBase::getWorld() { return _world; }