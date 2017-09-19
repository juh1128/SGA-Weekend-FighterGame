#pragma once
#include "gameNode.h"

class sceneBase : public gameNode
{
private:
	world*			_world;

	//메시지 처리 관련
	vector<tagMessage> _reservedMessage;
	vector<tagMessage> _messageList;
	unordered_map<string, std::function<void(tagMessage)>> _callbackList;

public:

	virtual HRESULT init();
	virtual void release();

	virtual void resume() = 0;

	virtual void update();
	virtual void render();

	world* getWorld();

	//메시지를 전달한다.
	void sendMessage(string text, float delayTime = 0.0f, int data = 0, float data2 = 0.0f, POINT ptData = POINT(), vector<gameObject*> targetList = vector<gameObject*>());
	//콜백 함수 저장
	void addCallback(string msgName, std::function<void(tagMessage)> callbackFunc)
	{
		_callbackList.insert(make_pair(msgName, callbackFunc));
	}
};