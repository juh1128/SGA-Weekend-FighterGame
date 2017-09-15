#include "stdafx.h"
#include "tagMessage.h"
#include "trigger.h"



HRESULT trigger::init(tagMessage msg, RECT rc, int targetPriorityNum)
{
	gameObject::init("trigger");

	//변수 기본 값을 초기화
	_targetPriorityNum = targetPriorityNum;
	_targetName = "NONE";
	_msg = msg;
	_count = 1;
	_delayTime = 0.0f;
	_lifeTime = 1.0f;
	_isMultipleTarget = false;

	int width = rc.right - rc.left;
	int height = rc.bottom - rc.top;
	this->setSize(width, height);

	_pos.x = rc.left + width / 2;
	_pos.y = rc.top + height / 2;

	return S_OK;
}

void trigger::setTriggerInfo(int triggerCount, float triggerLifeTime, bool isMultipleTarget, float delayTime, string targetName)
{
	_count = triggerCount;
	_lifeTime = triggerLifeTime;
	_delayTime = delayTime;
	_targetName = targetName;
	_isMultipleTarget = isMultipleTarget;
}

void trigger::release()		   
{
	gameObject::release();
}

void trigger::update()		   
{
	gameObject::update();

	//딜레이 타임이 있을 경우
	if (_delayTime >= 0.0f)
	{
		_delayTime -= TIMEMANAGER->getElapsedTime();
	}
	//딜레이 타임 없을 경우. 
	//트리거 관련 처리를 진행한다.
	else
	{
		//1. 라이프타임 체크
		if (_lifeTime != -1.0f)		//라이프타임이 -1이면 무한대
		{
			_lifeTime -= TIMEMANAGER->getElapsedTime();
			if (_lifeTime <= 0.0f)
			{
				this->setDestroy();
				return;
			}
		}

		//2. 충돌 체크
		RECT rc = getRect();
		auto triggerProcess = [&](string targetName, int priorityNum)
		{
			vector<gameObject*> objectList = WORLD->findObjects(targetName, priorityNum);

			//충돌 체크
			int size = objectList.size();
			RECT temp;
			for (int i = 0; i < size; ++i)
			{
				if (IntersectRect(&temp, &objectList.at(i)->getCollisionRect(), &rc))
				{
					objectList.at(i)->sendMessage(_msg.text, _msg.delayTime, _msg.data, _msg.data2, _msg.targetList);

					if (_count != -1 && !_isMultipleTarget)		//카운트가 -1이면 무한대
					{
						_count--;
						if (_count <= 0)
						{
							this->setDestroy();
							break;
						}
					}
				}
			}

			//다중타겟이 설정되어 있으면, 모든 대상과 충돌체크를 한 뒤 카운트를 1개만 감소시킨다.
			if (_count != -1 && _isMultipleTarget)
			{
				_count--;
				if (_count <= 0)
				{
					this->setDestroy();
				}
			}
		};

		//타겟의 우선순위 정보를 알 경우
		if (_targetPriorityNum >= 0)
		{
			triggerProcess(_targetName, _targetPriorityNum);			
		}
		//타겟의 우선순위 정보를 모를 경우 (전체 리스트를 돌아야 함)
		else
		{
			for (int i = 0; i < MAX_LAYER; ++i)
			{
				triggerProcess(_targetName, i);
			}
		}
	}
}

void trigger::render()		   
{
	if (_isDebugMode)
	{
		HBRUSH triggerBrush, oldBrush;

		triggerBrush = CreateSolidBrush(RGB(255, 0, 0));
		oldBrush = (HBRUSH)SelectObject(getMemDC(), triggerBrush);

		RECT rc = this->getRect();
		Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);

		SelectObject(getMemDC(), oldBrush);
		DeleteObject(triggerBrush);
	}
}