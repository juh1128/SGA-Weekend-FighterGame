#pragma once
#include "character.h"

namespace NanayaState
{
	enum Enum
	{
		LEFT_STAND, RIGHT_STAND,							//������ ��
		LEFT_STAND_WEAKATTACK, RIGHT_STAND_WEAKATTACK,		//������ �� ���
		LEFT_STAND_STRONGATTACK, RIGHT_STAND_STRONGATTACK,  //������ �� ����
		LEFT_WALK, RIGHT_WALK,								//���� ��
		LEFT_WALKFORWARD, RIGHT_WALKFORWARD,				//������ ���� ��
		LEFT_WALKBACKWARD, RIGHT_WALKBACKWARD,				//�ڷ� ���� ��
		LEFT_DASH, RIGHT_DASH,								//�� ��
		LEFT_DASHFORWARD, RIGHT_DASHFORWARD,				//������ �� ��
		LEFT_DASHBACKWARD, RIGHT_DASHBACKWARD,				//�ڷ� �� ��
		LEFT_SIT, RIGHT_SIT,								//���� ��
		LEFT_SIT_WEAKATTACK, RIGHT_SIT_WEAKATTACK,			//�ɾ��� �� ���
		LEFT_SIT_STRONGATTACK, RIGHT_SIT_STRONGATTACK,		//�ɾ��� �� ����
		LEFT_UP, RIGHT_UP,									//�ɾҴ� �Ͼ ��
		LEFT_JUMP, RIGHT_JUMP,								//���ڸ� ������ ��
		LEFT_JUMPFORWARD, RIGHT_JUMPFORWARD,				//������ ������ ��
		LEFT_JUMPBACKWARD, RIGHT_JUMPBACKWARD,				//�ڷ� ������ ��
		LEFT_JUMP_WEAKATTACK, RIGHT_JUMP_WEAKATTACK,		//������ �� ���
		LEFT_JUMP_STRONGATTACK, RIGHT_JUMP_STRONGATTACK,	//������ �� ����
	};
}

class Nanaya : public character
{
private:
	NanayaState::Enum _state;

public:
	Nanaya() {}
	virtual ~Nanaya() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	void stateUpdate(NanayaState::Enum state);
	void changeState(NanayaState::Enum state);
};

