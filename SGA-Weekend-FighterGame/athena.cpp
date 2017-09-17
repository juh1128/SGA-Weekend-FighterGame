#include "stdafx.h"
#include "athena.h"
#include "attackHitbox.h"


HRESULT athena::init(vector2D pos)
{
	character::init("athena", pos, "athenaRightStop");
	
	_state = athenaState::RIGHT_STOP;
	
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((athenaState::Enum)msg.data);
	});

	return S_OK;
}
void athena::release()
{
	character::release();
}
void athena::update()
{
	character::update();
	stateUpdate(_state);

}
void athena::render()
{
	character::render();
}

void athena::changeState(athenaState::Enum state)
{
	switch (state)
	{
	case athenaState::RIGHT_STOP:				//������ ���
		this->setAnimation("athenaRightStop");
		break;
	
	case athenaState::LEFT_STOP:				//���� ���
		this->setAnimation("athenaLeftStop");
	
	case athenaState::RIGHT_MOVE:				//������ �̵�
		this->setAnimation("athenaRightMove");
		break;

	case athenaState::RIGHT_BACK_STEP:			//�����ʹ������� �ڷ� �̵�
		this->setAnimation("athenaRightBackStep");
	break;
	
	case athenaState::LEFT_MOVE:				//���� �̵�
		this->setAnimation("athenaLeftMove");
		break;
	
	case athenaState::RIGHT_JUMP:				//������ ����
		this->setAnimation("athenaRightJump");
		break;
	
	case athenaState::LEFT_JUMP:				//���� ����
		this->setAnimation("athenaLeftJump");
		break;
	
	case athenaState::RIGHT_DASH:				//������ �뽬
		this->setAnimation("athenRightDash");
		break;
	
	case athenaState::LEFT_DASH:				//���� �뽬
		this->setAnimation("athenaLeftDash");
		break;
	
	case athenaState::RIGHT_FOOT_ATTACK:
		break;
	
	case athenaState::LEFT_FOOT_ATTACK:
	
	case athenaState::RIGHT_HAND_ATTACK:
		break;
	
	case athenaState::RIGHT_FOOT_COUNT:
		break;
	
	case athenaState::RIGHT_HAND_COUNT:
		break;
	}
	
	_state = state;
}


void athena::stateUpdate(athenaState::Enum state)
{

	switch (state)
	{
	case athenaState::RIGHT_STOP:
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))				//������������ ������Ű�� �ѹ��������� (�������̵����� ���º���)
		{
			changeState(athenaState::RIGHT_MOVE);
		}
	
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))				//�������� ���� ����Ű�� �ѹ��������� (�ڷ� �齺��)
		{
			changeState(athenaState::RIGHT_BACK_STEP);
		}
	
		break;
	
	case athenaState::RIGHT_MOVE:
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))				//�������� ���� ������Ű�� �ڴ������� (������ �̵�)
		{
			_pos.x += 10;
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))				//������ Ű�� ������ (������ ��� ���º���)
		{
			changeState(athenaState::RIGHT_STOP);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))				//������ �̵��ÿ� ����Ű�� �ѹ��� �������� (�����̵� ���º���)
		{
			changeState(athenaState::LEFT_MOVE);
		}
		break;
	
	case athenaState::LEFT_MOVE: case athenaState::RIGHT_BACK_STEP:
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))				//����Ű�� �� ������ ������ (�������� �̵�)
		{
			_pos.x -= 10;
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))				//�������� �̵����϶� ������Ű�� �ѹ��� �������� (�������̵� ���º���)
		{
			changeState(athenaState::RIGHT_MOVE);
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))				//����Ű�� ������ ���� (������ ��� ���º���)
		{
			changeState(athenaState::RIGHT_STOP);
		}
		break;
	
	
	case athenaState::RIGHT_JUMP:
		break;
	
	case athenaState::RIGHT_DASH:
		break;
	
	case athenaState::RIGHT_FOOT_ATTACK:
		break;
	
	case athenaState::RIGHT_HAND_ATTACK:
		break;
	
	case athenaState::RIGHT_FOOT_COUNT:
		break;
	
	case athenaState::RIGHT_HAND_COUNT:
		break;
	}
}
