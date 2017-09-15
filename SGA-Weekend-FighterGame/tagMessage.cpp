#include "stdafx.h"
#include "tagMessage.h"


tagMessage::tagMessage()
{
	isActive = true;
	this->data = 0;
	this->data2 = 0;
	this->delayTime = 0.0f;
}

tagMessage::tagMessage(string text, float delay, int data, float data2, vector<gameObject*> targetList)
{
	isActive = true;
	this->text = text;
	this->data = data;
	this->data2 = data2;
	this->targetList = targetList;
	this->delayTime = delay;
}