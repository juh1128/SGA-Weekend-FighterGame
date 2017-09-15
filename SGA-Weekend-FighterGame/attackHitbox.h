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

	//대미지, 생성 위치, 히트박스 크기, 히트박스의 타겟, 히트박스 자동소멸 시간, 히트 후 터질 이펙트
	HRESULT init(int damage, vector2D pos, vector2D size, gameObject* target , float lifeTime = 0.3f, string hitedEffectKey = "NONE" );
	void release();
	void update();
	void render();
};