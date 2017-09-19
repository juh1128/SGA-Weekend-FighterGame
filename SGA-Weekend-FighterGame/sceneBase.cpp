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
	//메시지 예약 리스트 업데이트
	float elapsedTime = TIMEMANAGER->getElapsedTime();
	for (int i = 0; i < _reservedMessage.size(); ++i)
	{
		_reservedMessage[i].delayTime -= elapsedTime;
		//딜레이 타임이 다 됬으면 메시지 리스트로 옮긴다.
		if (_reservedMessage[i].delayTime <= 0.0f)
		{
			_reservedMessage[i].delayTime = 0.0f;
			_messageList.emplace_back(_reservedMessage[i]);
			_reservedMessage.erase(_reservedMessage.begin() + i);
			--i;
		}
	}

	//메시지 처리하기
	for (int i = _messageList.size() - 1; i >= 0; --i)
	{
		auto iter = _callbackList.find(_messageList[i].text);
		if (iter != _callbackList.end())
		{
			iter->second(_messageList[i]);
		}
		_messageList.erase(_messageList.begin() + i);
	}

	//월드 업데이트
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


//메시지 처리 관련
void sceneBase::sendMessage(string text, float delayTime, int data, float data2, POINT ptData, vector<gameObject*> targetList)
{
	//딜레이타임이 없으면 바로 메시지 벡터에 넣는다.
	if (delayTime == 0.0f)
	{
		_messageList.emplace_back(text, 0.0f, data, data2, ptData, targetList);
	}
	//딜레이타임이 있으면 메시지 예약 리스트에 넣는다.
	else
	{
		_reservedMessage.emplace_back(text, delayTime, data, data2, ptData, targetList);
	}
}