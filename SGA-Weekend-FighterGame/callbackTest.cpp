#include "stdafx.h"
#include "tagMessage.h"
#include "callbackTest.h"



HRESULT callbackTest::init()
{
	gameObject::init("테스트");

	hp = 10000;

	this->addCallback("addHp", [this](tagMessage msg) 
	{
		this->callbackFunc(msg);
	});


	return S_OK;
}
void callbackTest::release()	 
{
	gameObject::release();
}
void callbackTest::update()		 
{
	gameObject::update();
}
void callbackTest::render()		 
{
	gameObject::render();
}

void callbackTest::callbackFunc(tagMessage msg)
{
	hp += msg.data;
	cout << "콜백함수 발동! 현재 HP: " << hp << endl;
}
