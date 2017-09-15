#pragma once
#include "gameObject.h"


//���ǿ� �´� ����� Ʈ���� ������ ������ �޽����� ������.
class trigger : public gameObject
{
private:
	int					_targetPriorityNum;
	string				_targetName;
	tagMessage			_msg;

	int					_count;
	float				_delayTime;
	float				_lifeTime;
	bool				_isMultipleTarget;

public:
	trigger() {}
	virtual ~trigger() {}

	//Ʈ���Ÿ� �ߵ���Ű���� Ÿ���� Ÿ�԰� ������ ���� �޽���, Ʈ������ RECT
	HRESULT init(tagMessage msg, RECT rc, int targetPriorityNum = -1);

	//�ߵ� Ƚ��, ���ӽð�, ���� Ÿ�� ����, �������� �ð�, Ÿ���̸�
	//option: Ʈ���� �ߵ� Ƚ���� ���ӽð��� -1�� �����ϸ� ���Ѵ밡 �ȴ�.
	//Ʈ���Ŵ� �ߵ� Ƚ���� �� �ǰų�, ���ӽð��� ������ �����ȴ�.
	void setTriggerInfo(int triggerCount=1, float triggerLifeTime=1.0f, bool isMultipleTarget=false, float delayTime=0.0f, string targetName="NONE");

	void release();
	void update();
	void render();
};