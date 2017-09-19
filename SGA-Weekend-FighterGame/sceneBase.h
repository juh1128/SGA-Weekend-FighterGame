#pragma once
#include "gameNode.h"

class sceneBase : public gameNode
{
private:
	world*			_world;

	//�޽��� ó�� ����
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

	//�޽����� �����Ѵ�.
	void sendMessage(string text, float delayTime = 0.0f, int data = 0, float data2 = 0.0f, POINT ptData = POINT(), vector<gameObject*> targetList = vector<gameObject*>());
	//�ݹ� �Լ� ����
	void addCallback(string msgName, std::function<void(tagMessage)> callbackFunc)
	{
		_callbackList.insert(make_pair(msgName, callbackFunc));
	}
};