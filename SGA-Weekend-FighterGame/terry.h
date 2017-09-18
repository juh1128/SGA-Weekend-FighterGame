#pragma once
#include "character.h"


#define TERRYSPEED		5.0		//�⺻ �̵��ӵ�
#define TERRYJUMPPOWER	25		//��������
#define TERRYGRAVITY		0.8		//�׶��Ƽ


namespace tagTerryState
{
	enum Enum
	{
		RIGHT_STOP, LEFT_STOP,							//���ĵ�����
		//����
		RIGHT_MOVE, LEFT_MOVE,							//�̵� ����
		RIGHT_BACK_MOVE, LEFT_BACK_MOVE,				//�ڷ� �̵� ����
		RIGHT_DASH_MOVE, LEFT_DASH_MOVE,				//�뽬 �̵� ����
		RIGHT_BACK_DASH, LEFT_BACK_DASH,				//��뽬 �̵� ����
		//�ɱ�
		RIGHT_SIT, LEFT_SIT,							//��������
		//����
		RIGHT_JUMP, LEFT_JUMP,							//���ڸ� ����	����
		RIGHT_MOVE_JUMP, LEFT_MOVE_JUMP,				//�̵� ����		����
		RIGHT_BACK_MOVE_JUMP, LEFT_BACK_MOVE_JUMP,		//�ڷ� �̵� ���� ����
		//����
		RIGHT_DEFENCE, LEFT_DEFENCE,					//���ĵ����� ����
		RIGHT_SIT_DEFENCE, LEFT_SIT_DEFENCE,			//�������� ����
		//����
		RIGHT_ATTACK, LEFT_ATTACK,						//���
		RIGHT_KICK, LEFT_KICK,							//���
		RIGHT_POWER_ATTACK, LEFT_POWER_ATTACK,			//����
		RIGHT_POWER_KICK, LEFT_POWER_KICK				//����
	};
}
class terry : public character
{
private :
	tagTerryState::Enum _state;

	bool _isEnemyRight;					//�� ��ġ�� ���� �����

	float _jumpPower;					//������
	float _gravity;						//�߷� 
	float _savePosY;					//��ǥ ���� ����
	bool  _isJump;						//���� �������� ���� ����

	float _bottom;						//�� ��ǥ

	

public:
	terry() {}
	virtual ~terry() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	//void enemyPos();
	void changeState(tagTerryState::Enum state);
	void stateUpdate(tagTerryState::Enum state);
	
};

