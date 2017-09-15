#pragma once
#include "gameObject.h"


//조건에 맞는 대상이 트리거 영역에 들어오면 메시지를 보낸다.
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

	//트리거를 발동시키려는 타겟의 타입과 보내고 싶은 메시지, 트리거의 RECT
	HRESULT init(tagMessage msg, RECT rc, int targetPriorityNum = -1);

	//발동 횟수, 지속시간, 다중 타겟 여부, 지연생성 시간, 타겟이름
	//option: 트리거 발동 횟수나 지속시간을 -1로 설정하면 무한대가 된다.
	//트리거는 발동 횟수가 다 되거나, 지속시간이 끝나면 삭제된다.
	void setTriggerInfo(int triggerCount=1, float triggerLifeTime=1.0f, bool isMultipleTarget=false, float delayTime=0.0f, string targetName="NONE");

	void release();
	void update();
	void render();
};