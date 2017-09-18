#pragma once
#include "character.h"

namespace MAI
{
	enum state	//����
	{
		LEFT_IDLE,RIGHT_IDLE,									//����
		LEFT_MOVE,RIGHT_MOVE,									//�������̵�
		LEFT_JUMP,RIGHT_JUMP,									//����
		LEFT_BACK_MOVE,RIGHT_BACK_MOVE,							//�ڷ��̵�
		LEFT_SIT,RIGHT_SIT,										//�ɱ�
		LEFT_PUNCH,RIGHT_PUNCH,									//���
		LEFT_STRONG_PUNCH,RIGHT_STRONG_PUNCH,					//����
		LEFT_KICK,RIGHT_KICK,									//���
		LEFT_STRONG_KICK,RIGHT_STRONG_KICK,						//����
		LEFT_SIT_PUNCH,RIGHT_SIT_PUNCH,							//�ɾƼ����
		LEFT_SIT_KICK,RIGHT_SIT_KICK,							//�ɾƼ����
		LEFT_SIT_STRONG_PUNCH,RIGHT_SIT_STRONG_PUNCH,			//�ɾƼ�����
		LEFT_SIT_STRONG_KICK,RIGHT_SIT_STRONG_KICK,				//�ɾƼ�����
		LEFT_DEFENCE,RIGHT_DEFENCE,								//���
		LEFT_SIT_DEFENCE,RIGHT_SIT_DEFENCE,						//�ɾƼ����
		LEFT_DASH,RIGHT_DASH,									//�뽬
		LEFT_BACK_DASH,RIGHT_BACK_DASH,							//�ڷδ뽬
		LEFT_KNOCK_DOWN,RIGHT_KNOCK_DOWN,						//������
		LEFT_KNOCK_DOWN_BACK_MOVE,RIGHT_KNOCK_DOWN_BACK_MOVE,	//���������¿����ڷ��̵�
		LEFT_DAMAGED,RIGHT_DAMAGED,								//��������
		STATE_END												//�Ź���

	};
}

using namespace MAI;
using namespace key;

#define MOVESPEED 5

class playGround;

class mai : public character
{
private:
	//�����̳�
	state _state;
	//Ű �̳�
	Enum _enum;
	//���漱���÷��̱׶���
	playGround* _playGround;


public:
	mai() {}
	virtual ~mai() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	void stateUpdate(state);
	void changeState(state);
};

