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

	//새로운 씬을 추가한다. (위에 쌓는다.)
	void					pushScene(sceneBase* scene);
	//현재 씬을 삭제한다.
	void					popScene();
	//현재 씬을 삭제하고, 새로운 씬을 추가한다.
	void					changeScene(sceneBase* scene);
	//현재 씬을 가져온다.
	sceneBase*					getNowScene();
};
