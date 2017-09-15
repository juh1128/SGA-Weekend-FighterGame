#pragma once

class gameObject;

//모든 게임오브젝트는 대기벡터와 메시지벡터를 가진다.
//게임오브젝트끼리는 메시지를 주고 받을 수 있다.
//메시지큐는 매 프레임마다 자동으로 클리어된다.
//health 클래스같이 게임 오브젝트 안에서 쓰이는 클래스들은
//parent->popMessage 함수를 통해서 메시지 처리를 할 수 있다.
struct tagMessage
{
	bool isActive;
	string text;
	int data;
	float data2;
	vector<gameObject*> targetList;

	float delayTime;

	tagMessage();
	tagMessage(string text, float delay = 0.0f, int data = 0, float data2 = 0.0f, vector<gameObject*> targetList = vector<gameObject*>());
};

//NULL메시지 정의
#define NULL_MESSAGE tagMessage("NULL")