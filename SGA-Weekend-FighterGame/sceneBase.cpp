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
	//�޽��� ���� ����Ʈ ������Ʈ
	float elapsedTime = TIMEMANAGER->getElapsedTime();
	for (int i = 0; i < _reservedMessage.size(); ++i)
	{
		_reservedMessage[i].delayTime -= elapsedTime;
		//������ Ÿ���� �� ������ �޽��� ����Ʈ�� �ű��.
		if (_reservedMessage[i].delayTime <= 0.0f)
		{
			_reservedMessage[i].delayTime = 0.0f;
			_messageList.emplace_back(_reservedMessage[i]);
			_reservedMessage.erase(_reservedMessage.begin() + i);
			--i;
		}
	}

	//�޽��� ó���ϱ�
	for (int i = _messageList.size() - 1; i >= 0; --i)
	{
		auto iter = _callbackList.find(_messageList[i].text);
		if (iter != _callbackList.end())
		{
			iter->second(_messageList[i]);
		}
		_messageList.erase(_messageList.begin() + i);
	}

	//���� ������Ʈ
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


//�޽��� ó�� ����
void sceneBase::sendMessage(string text, float delayTime, int data, float data2, POINT ptData, vector<gameObject*> targetList)
{
	//������Ÿ���� ������ �ٷ� �޽��� ���Ϳ� �ִ´�.
	if (delayTime == 0.0f)
	{
		_messageList.emplace_back(text, 0.0f, data, data2, ptData, targetList);
	}
	//������Ÿ���� ������ �޽��� ���� ����Ʈ�� �ִ´�.
	else
	{
		_reservedMessage.emplace_back(text, delayTime, data, data2, ptData, targetList);
	}
}