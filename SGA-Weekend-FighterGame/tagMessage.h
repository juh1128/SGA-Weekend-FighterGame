#pragma once

class gameObject;

//��� ���ӿ�����Ʈ�� ��⺤�Ϳ� �޽������͸� ������.
//���ӿ�����Ʈ������ �޽����� �ְ� ���� �� �ִ�.
//�޽���ť�� �� �����Ӹ��� �ڵ����� Ŭ����ȴ�.
//health Ŭ�������� ���� ������Ʈ �ȿ��� ���̴� Ŭ��������
//parent->popMessage �Լ��� ���ؼ� �޽��� ó���� �� �� �ִ�.
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

//NULL�޽��� ����
#define NULL_MESSAGE tagMessage("NULL")