#pragma once
#include "gameObject.h"
#include <unordered_map>
#include <deque>

class gameObject;
class statePattern;

class stateBase
{
protected:
	//���� ��ü�� ���� �� ���
	gameObject*	_target;
	//���� ��ü���� �Ѱ� �����ϴ� ��ü
	statePattern*	_statePattern;
	//���� ��ü���� ó���ϰ����ϴ� �޽���
	tagMessage		_message;

public:
	stateBase() {}
	virtual ~stateBase() {}

	//���� ��ü �ʱ�ȭ
	virtual void init(gameObject* target, statePattern* statePattern);
	//���� ��ü ����
	virtual void release();

	//�� ���¿� ó�� ���� �� 1�� ����ȴ�.
	virtual void enter();
	//���¿� �������� ���������� ȣ��ȴ�.
	virtual void update();
	virtual void render();
	//���¿��� ������ ���� 1�� ����ȴ�.
	virtual void exit();

	//�޽��� ����
	void sendMessage(tagMessage msg) { _message = msg; }
};

//���� ��ü���� �����ϴ� �Ŵ��� Ŭ����.
//���� ��ü ������ ����ϰ� ���� ��ü�� stateManager�� �߰����ָ� �ȴ�.
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

	//stateManager�� ������ �ִ� �θ� ��ü
	gameObject*		_parent;

public:
	statePattern() {}
	virtual ~statePattern() {}

	HRESULT init(gameObject* parent);
	void release();
	void update();
	void render();

	//�⺻ ���¸� �����Ѵ�. (default ���´� ���� �� �� ����.)
	//��� ���¸� �߰� �� �� ��~~! �⺻ ���¸� �������־�� ��.
	void setDefaultState(string name);
	//���ο� ���¸� ����Ѵ�.
	void addState(string name, stateBase* state);
	//���¸� �����Ѵ�.
	void deleteState(string name);
	//���¸� �ٲ۴�. (���� �ٲٷ��� ���°� ������, default ���·� ���ư���.)
	void changeState(string name, tagMessage msg = tagMessage("NULL"));
	void changeToDefaultState();
	//���� ���·� �ǵ��ư���. (�ִ� 3������ �����ϴ�.)
	void backToPreviousState();
	//���� ������ �̸��� ��ȯ�Ѵ�.
	string getNowStateName();

	//�⺻ ���¸� ��ȯ�Ѵ�.
	stateBase* getDefaultState();

};