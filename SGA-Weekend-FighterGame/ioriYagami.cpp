#include "stdafx.h"
#include "ioriYagami.h"
#include "attackHitbox.h"
#include "playGround.h"

HRESULT ioriYagami::init(vector2D pos)
{

	_playGround->setupDongjin();

	character::init("�̿���", pos, "�̿���_������_����");
	this->changeState(tagIoriState::RIGHT_STOP);

	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((tagIoriState::Enum)msg.data);
	});
	//this->setGravity(true);
	



	return S_OK;
}
void ioriYagami::release()
{
	character::release();
}
void ioriYagami::update()
{
	character::update();

	stateUpdate(_state);

}
void ioriYagami::render()
{
	character::render();
}

void ioriYagami::stateUpdate(tagIoriState::Enum state)
{
	switch (_state)
	{
	case tagIoriState::RIGHT_STOP:
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			changeState(tagIoriState::RIGHT_MOVE);
		}

		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			changeState(tagIoriState::RIGHT_BACK_MOVE);
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(tagIoriState::RIGHT_SIT);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::ATTACK]))
		{
			changeState(tagIoriState::ATTAK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::KICK]))
		{
			changeState(tagIoriState::KICK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_ATTACK]))
		{
			changeState(tagIoriState::STRONG_ATTACK);
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::STRONG_KICK]))
		{
			changeState(tagIoriState::STRONG_KICK);
		}
	
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))
		{
			changeState(tagIoriState::RIGHT_JUMP);
		}

		break;
		//case tagIoriState::LEFT_STOP:
		//	break;
	case tagIoriState::RIGHT_MOVE:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			_pos.x += 5;
		}
		if (!KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))
		{
			changeState(tagIoriState::RIGHT_STOP);
		}
	}
	break;
	case tagIoriState::LEFT_MOVE:
	{

	}
	break;
	case tagIoriState::RIGHT_RUN:
		//if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT, key::RIGHT]))
		//{
		//	_pos.x += 8;
		//}
		//
		//if (!KEYMANAGER->isStayKeyDown(keyList[key::RIGHT, key::RIGHT]))
		//{
		//	changeState(tagIoriState::RIGHT_STOP);
		//}
		break;
	case tagIoriState::LEFT_RUN:
		break;
	case tagIoriState::RIGHT_BACK_MOVE:
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			_pos.x -= 5;
		}
		if (!KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))
		{
			changeState(tagIoriState::RIGHT_STOP);
		}
	}
	break;
	case tagIoriState::LEFT_BACK_MOVE:
		break;
	case tagIoriState::RIGHT_SIT:

		if (!KEYMANAGER->isStayKeyDown(keyList[key::DOWN]))
		{
			changeState(tagIoriState::RIGHT_STOP);
		}
		break;
	case tagIoriState::LEFT_SIT:
		break;
	case tagIoriState::RIGHT_JUMP:
		if (KEYMANAGER->isStayKeyDown(keyList[key::JUMP]))
		{
			jump(25);
		}
		break;
	case tagIoriState::LEFT_JUMP:
		break;
	case tagIoriState::ATTAK:

		break;
	case tagIoriState::KICK:

		break;
	case tagIoriState::STRONG_ATTACK:
		break;
	case tagIoriState::STRONG_KICK:
		break;

	}

}

void ioriYagami::changeState(tagIoriState::Enum state)
{
	switch (state)
	{
	case tagIoriState::RIGHT_STOP:
		this->setAnimation("�̿���_������_����");
		break;
		//case tagIoriState::LEFT_STOP:
		//	break;
	case tagIoriState::RIGHT_MOVE:
	{
		this->setAnimation("�̿���_������_�̵�");
		//this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_MOVE));
	}
	break;
	case tagIoriState::LEFT_MOVE:
		break;
	case tagIoriState::RIGHT_RUN:
		this->setAnimation("�̿���_������_�뽬");
		break;
	case tagIoriState::LEFT_RUN:
		break;
	case tagIoriState::RIGHT_BACK_MOVE:
		this->setAnimation("�̿���_������_��_�̵�");
		break;
	case tagIoriState::LEFT_BACK_MOVE:
		break;
	case tagIoriState::RIGHT_SIT:
		this->setAnimation("�̿���_������_����");
		break;
	case tagIoriState::LEFT_SIT:
		break;
	case tagIoriState::RIGHT_JUMP:
		this->setAnimation("�̿���_������_����");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.1f, tagIoriState::RIGHT_STOP));
		break;
	case tagIoriState::LEFT_JUMP:
		break;
	case tagIoriState::ATTAK:
		this->setAnimation("�̿���_������_���");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		//this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, testCharacterState::RIGHT_MOVE));
		break;
	case tagIoriState::KICK:
		this->setAnimation("�̿���_������_���");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		break;
	case tagIoriState::STRONG_ATTACK:
		this->setAnimation("�̿���_������_����");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		break;
	case tagIoriState::STRONG_KICK:
		this->setAnimation("�̿���_������_����");
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, tagIoriState::RIGHT_STOP));
		break;
	}
	_state = state;
}

