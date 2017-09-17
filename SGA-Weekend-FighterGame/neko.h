#pragma once
#include "character.h"

#define NEKOSPEED		5.0		//�⺻ �̵��ӵ�
#define NEKOSITSPEED	2.0		//�ɾƼ� �̵��ӵ� 
#define NEKOJUMPPOWER	25		//��������
#define NEKOGRAVITY		0.8		//�׶��Ƽ

namespace tagNekoState
{
	enum ENUM
	{
		RIGHT_STOP, LEFT_STOP,				//�⺻����
		RIGHT_MOVE, LEFT_MOVE,				//�̵�����
		RIGHT_JUMP, LEFT_JUMP,				//����
		RIGHT_SIT, LEFT_SIT,				//�ɱ�
		RIGHT_CHANGE_SIT, LEFT_CHANGE_SIT,	//�ɴ� ���
		RIGHT_CHANGE_UP , LEFT_CHAGNE_UP,	//�Ͼ�� ���
		RIGHT_SIT_MOVE , LEFT_SIT_MOVE		//�ɾƼ� �̵�
	};
}

using namespace tagNekoState;
using namespace key;

class neko : public character
{
private:
	tagNekoState::ENUM	_state;			//����ó�� enum ���� 

	bool _isEnemyRight;					//�� ��ġ�� ���� �����

	float _jumpPower;					//������
	float _gravity;						//�߷� 
	float _savePosY;					//��ǥ ���� ����
	bool  _isJump;						//���� �������� ���� ����

	key::Enum   _saveLastKey;			//�������� ���� stayKeyDown Ű ���� ���� 


public:
	neko()  {}
	virtual ~neko() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	void stateUpdate(tagNekoState::ENUM state);
	void changeState(tagNekoState::ENUM state);

	void enemyPos();

	void jumping();
	void setJump()
	{
		if (_isJump) return;
		_isJump = true;
		_savePosY = this->_pos.y;
		_gravity = NEKOGRAVITY;
		_jumpPower = NEKOJUMPPOWER;
	}
};

