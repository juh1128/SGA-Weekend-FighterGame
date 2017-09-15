#include "stdafx.h"
#include "tagMessage.h"
#include "trigger.h"



HRESULT trigger::init(tagMessage msg, RECT rc, int targetPriorityNum)
{
	gameObject::init("trigger");

	//���� �⺻ ���� �ʱ�ȭ
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

	//������ Ÿ���� ���� ���
	if (_delayTime >= 0.0f)
	{
		_delayTime -= TIMEMANAGER->getElapsedTime();
	}
	//������ Ÿ�� ���� ���. 
	//Ʈ���� ���� ó���� �����Ѵ�.
	else
	{
		//1. ������Ÿ�� üũ
		if (_lifeTime != -1.0f)		//������Ÿ���� -1�̸� ���Ѵ�
		{
			_lifeTime -= TIMEMANAGER->getElapsedTime();
			if (_lifeTime <= 0.0f)
			{
				this->setDestroy();
				return;
			}
		}

		//2. �浹 üũ
		RECT rc = getRect();
		auto triggerProcess = [&](string targetName, int priorityNum)
		{
			vector<gameObject*> objectList = WORLD->findObjects(targetName, priorityNum);

			//�浹 üũ
			int size = objectList.size();
			RECT temp;
			for (int i = 0; i < size; ++i)
			{
				if (IntersectRect(&temp, &objectList.at(i)->getCollisionRect(), &rc))
				{
					objectList.at(i)->sendMessage(_msg.text, _msg.delayTime, _msg.data, _msg.data2, _msg.targetList);

					if (_count != -1 && !_isMultipleTarget)		//ī��Ʈ�� -1�̸� ���Ѵ�
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

			//����Ÿ���� �����Ǿ� ������, ��� ���� �浹üũ�� �� �� ī��Ʈ�� 1���� ���ҽ�Ų��.
			if (_count != -1 && _isMultipleTarget)
			{
				_count--;
				if (_count <= 0)
				{
					this->setDestroy();
				}
			}
		};

		//Ÿ���� �켱���� ������ �� ���
		if (_targetPriorityNum >= 0)
		{
			triggerProcess(_targetName, _targetPriorityNum);			
		}
		//Ÿ���� �켱���� ������ �� ��� (��ü ����Ʈ�� ���ƾ� ��)
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