#pragma once
#include "gameObject.h"
#include <unordered_map>
#include <deque>

class gameObject;
class statePattern;

class stateBase
{
protected:
	//상태 객체가 조정 할 대상
	gameObject*	_target;
	//상태 객체들을 총괄 관리하는 객체
	statePattern*	_statePattern;
	//상태 객체에서 처리하고자하는 메시지
	tagMessage		_message;

public:
	stateBase() {}
	virtual ~stateBase() {}

	//상태 객체 초기화
	virtual void init(gameObject* target, statePattern* statePattern);
	//상태 객체 해제
	virtual void release();

	//이 상태에 처음 들어올 때 1번 실행된다.
	virtual void enter();
	//상태에 들어오고나서 지속적으로 호출된다.
	virtual void update();
	virtual void render();
	//상태에서 나가기 전에 1번 실행된다.
	virtual void exit();

	//메시지 전달
	void sendMessage(tagMessage msg) { _message = msg; }
};

//상태 객체들을 관리하는 매니저 클래스.
//상태 객체 패턴을 사용하고 싶은 객체는 stateManager를 추가해주면 된다.
class statePattern : public gameNode
{
public:
	typedef pair<string, stateBase*>			state;
	typedef unordered_map<string, stateBase*>	totalState;
	typedef deque<string>						stateHistory;

private:
	state			_nowState;
	string			_defaultState;
	totalState		_totalState;
	stateHistory	_history;

	//stateManager를 가지고 있는 부모 객체
	gameObject*		_parent;

public:
	statePattern() {}
	virtual ~statePattern() {}

	HRESULT init(gameObject* parent);
	void release();
	void update();
	void render();

	//기본 상태를 설정한다. (default 상태는 삭제 할 수 없다.)
	//모든 상태를 추가 한 후 꼭~~! 기본 상태를 설정해주어야 함.
	void setDefaultState(string name);
	//새로운 상태를 등록한다.
	void addState(string name, stateBase* state);
	//상태를 삭제한다.
	void deleteState(string name);
	//상태를 바꾼다. (만약 바꾸려는 상태가 없으면, default 상태로 돌아간다.)
	void changeState(string name, tagMessage msg = tagMessage("NULL"));
	void changeToDefaultState();
	//이전 상태로 되돌아간다. (최대 3번까지 가능하다.)
	void backToPreviousState();
	//현재 상태의 이름을 반환한다.
	string getNowStateName();

	//기본 상태를 반환한다.
	stateBase* getDefaultState();

};