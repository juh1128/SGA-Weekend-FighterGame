#include "stdafx.h"
#include "statePattern.h"
#include "gameObject.h"

//===============================================
// ## ���� ��ü ���� ##
//===============================================

HRESULT statePattern::init(gameObject* parent)
{
	_parent = parent;

	return S_OK;
}

void statePattern::release()
{
	auto mIter = _totalState.begin();
	for (; mIter != _totalState.end(); ++mIter)
	{
		mIter->second->release();
		SAFE_DELETE(mIter->second);
	}
	_totalState.clear();
	_history.clear();
}

void statePattern::update()
{
	_nowState.second->update();
}
void statePattern::render()
{
	_nowState.second->render();
}

void statePattern::setDefaultState(string name)
{
	_defaultState = name;
	_nowState = make_pair(name, this->getDefaultState());
	_nowState.second->enter();

	_history.push_back(name);
}

void statePattern::addState(string name, stateBase* state)
{
	_totalState.insert(make_pair(name, state));
	state->init(_parent, this);
}

void statePattern::deleteState(string name)
{
	auto find = _totalState.find(name);
	if (find != _totalState.end())
	{
		find->second->release();
		SAFE_DELETE(find->second);
		_totalState.erase(find);
	}
}

void statePattern::changeState(string name, tagMessage msg)
{
	auto find = _totalState.find(name);
	//�ٲٷ��� ���¸� ã������, ��ü�Ѵ�.
	_nowState.second->exit();
	if (find != _totalState.end())
	{
		_nowState = *find;
	}
	//�ٲٷ��� ���°� ���� ��� ����Ʈ ���·� �����Ѵ�.
	else
	{
		_nowState = make_pair(_defaultState, getDefaultState());	
	}
	_nowState.second->sendMessage(msg);
	_nowState.second->enter();

	_history.push_back(name);
	//����� 5�� �̻�Ǹ� �տ����� �����Ѵ�.
	if (_history.size() > 5)
	{
		_history.pop_front();
	}
}

void statePattern::changeToDefaultState()
{
	_nowState.second->exit();
	_nowState = make_pair(_defaultState, getDefaultState());
	_nowState.second->enter();

	_history.push_back(_defaultState);
	//����� 5�� �̻�Ǹ� �տ����� �����Ѵ�.
	if (_history.size() > 5)
	{
		_history.pop_front();
	}
}

void statePattern::backToPreviousState()
{
	string previousStateName = *(_history.end() - 1);
	_history.pop_back();

	changeState(previousStateName);
}

string statePattern::getNowStateName()
{
	return _nowState.first;
}

stateBase* statePattern::getDefaultState()
{
	auto find = _totalState.find(_defaultState);
	if (find != _totalState.end())
	{
		return find->second;
	}
	return NULL;
}

//===============================================
// ## ���� ��ü �������̽� ##
//===============================================
void stateBase::init(gameObject* target, statePattern* statePattern)
{
	_target = target;
	_statePattern = statePattern;
}

void stateBase::release()
{

}

void stateBase::enter()		   
{
}

void stateBase::update()	   
{

}
void stateBase::render()
{

}

void stateBase::exit()		   
{

}