#include "stdafx.h"
#include "sceneManager.h"
#include "sceneBase.h"


sceneManager::sceneManager(){}
sceneManager::~sceneManager(){}

HRESULT sceneManager::init()
{
	return S_OK;
}

void sceneManager::release()
{
	for (int i = _sceneList.size() - 1; i >= 0; --i)
	{
		_sceneList[i]->release();
		delete _sceneList[i];
	}
	_messageQueue.clear();
}

void sceneManager::pushScene(sceneBase* scene)
{
	if (scene == NULL) return;
	_messageQueue.push_back( SCENE_MSG(sceneMessage::PUSH, scene));
}

void sceneManager::popScene()
{
	_messageQueue.push_back(SCENE_MSG(sceneMessage::POP, NULL));
}

void sceneManager::changeScene(sceneBase* scene)
{
	popScene();
	pushScene(scene);
}

void sceneManager::update()
{
	//�� push, pop �޼����� �ִ��� Ȯ�� �� ó��
	for (unsigned int i = 0; i < _messageQueue.size(); ++i)
	{
		if (_messageQueue[i].kind == sceneMessage::PUSH)
		{
			_sceneList.push_back(_messageQueue[i].scene);
			_messageQueue[i].scene->init();
		}
		else if (_messageQueue[i].kind == sceneMessage::POP)
		{
			_sceneList[_sceneList.size() - 1]->release();
			_sceneList.pop_back();
			if (_sceneList.size() > 0)
			{
				_sceneList[_sceneList.size() - 1]->resume();
			}
		}
	}
	_messageQueue.clear();

	//���� �ֱٿ� ������ ���� ������Ʈ�Ѵ�.
	int sceneCnt = _sceneList.size();
	if (sceneCnt > 0)
	{
		_sceneList[sceneCnt - 1]->update();
	}
}

void sceneManager::render()
{
	int sceneCnt = _sceneList.size();
	if (sceneCnt > 0)
	{
		_sceneList[sceneCnt - 1]->render();
	}
}


sceneBase* sceneManager::getNowScene()
{
	int size = _sceneList.size();
	if (size > 0)
	{
		return _sceneList[size - 1];
	}
	return nullptr;
}



sceneManager::tagSceneMessage::tagSceneMessage(sceneMessage::Enum k, sceneBase* s)
{
	kind = k;
	scene = s;
}