#pragma once


class attackHitbox : public gameObject
{
private:
	gameObject* _target;
	int			_damage;
	string		_hitedEffectKey;
	float		_lifeTime;

public:
	attackHitbox() {}
	virtual ~attackHitbox() {}

	//�����, ���� ��ġ, ��Ʈ�ڽ� ũ��, ��Ʈ�ڽ��� Ÿ��, ��Ʈ�ڽ� �ڵ��Ҹ� �ð�, ��Ʈ �� ���� ����Ʈ
	HRESULT init(int damage, vector2D pos, vector2D size, gameObject* target , float lifeTime = 0.3f, string hitedEffectKey = "NONE" );
	void release();
	void update();
	void render();
};