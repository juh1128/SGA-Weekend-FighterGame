#pragma once
#include "singletonBase.h"
#include <vector>

class sceneBase;

namespace sceneMessage
{
	enum Enum
	{
		PUSH, POP
	};
}

class sceneManager : public singletonBase<sceneManager>
{ 
private:
	typedef struct tagSceneMessage
	{
		sceneMessage::Enum		kind;
		sceneBase*				scene;

		tagSceneMessage() {}
		tagSceneMessage(sceneMessage::Enum k, sceneBase* s);
	}SCENE_MSG;

	vector<sceneBase*>			_sceneList;
	vector<SCENE_MSG>			_messageQueue;

public:
	sceneManager();
	~sceneManager();

	HRESULT					init();
	void					release();
	void					update();
	void					render();

	//���ο� ���� �߰��Ѵ�. (���� �״´�.)
	void					pushScene(sceneBase* scene);
	//���� ���� �����Ѵ�.
	void					popScene();
	//���� ���� �����ϰ�, ���ο� ���� �߰��Ѵ�.
	void					changeScene(sceneBase* scene);
	//���� ���� �����´�.
	sceneBase*				getNowScene();

	void					gameExit() { exit(1); }
};
