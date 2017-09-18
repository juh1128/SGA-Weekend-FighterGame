#pragma once
#include "character.h"
#include "effectFire.h"

#define NEKOSPEED				5.0		//�⺻ �̵��ӵ�
#define NEKOSITSPEED			2.0		//�ɾƼ� �̵��ӵ� 
#define NEKOJUMPPOWER			25		//��������
#define NEKOGRAVITY				0.8		//�׶��Ƽ
#define NEKODASHSPEED			12.0	//�뽬 �ӵ�
#define NEKOBACKDASHSPEED		15.0	//��뽬 �ӵ�
//s
namespace tagNekoState
{
	enum ENUM
	{
		RIGHT_STOP, LEFT_STOP,					//�⺻����
		RIGHT_MOVE, LEFT_MOVE,					//�̵�����
		RIGHT_JUMP, LEFT_JUMP,					//����
		RIGHT_BACK_JUMP, LEFT_BACK_JUMP,		//������
		RIGHT_SIT, LEFT_SIT,					//�ɱ�
		RIGHT_CHANGE_SIT, LEFT_CHANGE_SIT,		//�ɴ� ���
		RIGHT_CHANGE_UP, LEFT_CHAGNE_UP,		//�Ͼ�� ���
		RIGHT_SIT_MOVE, LEFT_SIT_MOVE,			//�ɾƼ� �̵�
		RIGHT_ATTACK, LEFT_ATTACK,				//���	
		RIGHT_SIT_ATTACK, LEFT_SIT_ATTACK,		//�ɾƼ� ���
		RIGHT_DEFENSE, LEFT_DEFENSE,			//����
		RIGHT_SIT_DEFENSE, LEFT_SIT_DEFENSE,	//�ɾ� ����
		RIGHT_KICK, LEFT_KICK,					//������
		RIGHT_SIT_KICK, LEFT_SIT_KICK,			//�ɾ� ������
		RIGHT_FIRE, LEFT_FIRE,					//�һձ�
		RIGHT_STAY_FIRE, LEFT_STAY_FIRE,		//�һհ� �ֱ�
		RIGHT_FLY, LEFT_FLY,					//����
		RIGHT_FALL, LEFT_FALL,					//�������� ����
		RIGHT_DASH, LEFT_DASH,					//�뽬 ����
		RIGHT_BACK_DASH, LEFT_BACK_DASH,		//��뽬 ����
		RIGHT_HIT, LEFT_HIT,					//�ĸ´� ���� 
		RIGHT_DING, LEFT_DING,					//�������� ����					
		RIGHT_DIE, LEFT_DIE						//������ ����
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

	vector2D _centerPos;				//ĳ���� ��� ��ǥ

	float _bottom;						//�� ��ǥ

	key::Enum   _saveLastKey;			//�������� ���� stayKeyDown Ű ���� ���� 

	effectFire* _effect;


public:
	neko() {}
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


	//Ŀ�ǵ� �Լ��� 
	void nekoFire();
	void nekoRightFly();
	void nekoLeftFly();

	void hit(tagMessage msg);
	void die(tagMessage msg);
	void block();
};

