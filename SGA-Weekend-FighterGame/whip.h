#pragma once
#include "character.h"

namespace tagWhip
{
	enum Enum
	{
		//�Ϲ� ������
		RIGHT_STOP, LEFT_STOP,
		RIGHT_MOVE, LEFT_MOVE,
		RIGHT_BACKMOVE, LEFT_BACKMOVE,
		RIGHT_RUN, LEFT_RUN,
		RIGHT_SIT, LEFT_SIT,
		RIGHT_JUMP, LEFT_JUMP,
		RIGHT_MOVEJUMP, LEFT_MOVEJUMP,
		//�Ϲ� ����
		RIGHT_WEAKHAND, LEFT_WEAKHAND,
		RIGHT_WEAKFOOT, LEFT_WEAKFOOT,
		RIGHT_STRONGHAND, LEFT_STRONGHAND,
		RIGHT_STRONGFOOT, LEFT_STRONGFOOT,
		RIGHT_SITWEAKHAND, LEFT_SITWEAKHAND,
		RIGHT_SITWEAKFOOT, LEFT_SITWEAKFOOT,
		RIGHT_SITSTRONGHAND, LEFT_SITSTRONGHAND,
		RIGHT_SITSTRONGFOOT, LEFT_SITSTRONGFOOT,
		RIGHT_JUMPHAND, LEFT_JUMPFOOT,
		//��ų, �ʻ��
		RIGHT_SKILL1, LEFT_SKILL1,
		RIGHT_SKILL2, LEFT_SKILL2,
		RIGHT_SKILL2_1, LEFT_SKILL2_1,
		RIGHT_SPECIALSKILL, LEFT_SPECIALSKILL,
		//����, �±�, ����
		RIGHT_BLOCK, LEFT_BLOCK,
		RIGHT_HITED, LEFT_HITED,
		RIGHT_DIE, LEFT_DIE

	};
}

class playGround;

class whip : public character
{
private:
	tagWhip::Enum _state;

	bool _isEnemyDirection;  //������ �����ʿ� ������ true


public:
	whip() {}
	virtual ~whip() {}

	HRESULT init(vector2D pos);
	void release();
	void update();
	void render();

	void stateUpdate(tagWhip::Enum _state);
	void changeState(tagWhip::Enum _state);

	void setupResource();

	void skill1();
	void skill2();
	void skill3();

	void lSkill1();
	void lSkill2();
	void lSkill3();

	void enemyDirectiion();

	void hit(tagMessage msg);
	void block();
	void die(tagMessage msg);
};
