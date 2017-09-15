#pragma once

//ĳ���� Ű
namespace key
{
	enum Enum
	{
		LEFT, RIGHT, JUMP, DOWN, ATTACK, STRONG_ATTACK, KICK, STRONG_KICK, END
	};
}

class character : public gameObject
{
protected:
	key::Enum			keyList[key::END];		//����Ű ����Ʈ
	gameObject*			_enemy;					//�����

public:
	character() {}
	virtual ~character() {}

	virtual HRESULT init(string characterName, vector2D pos, string animationKeyName);
	virtual void release();
	virtual void update();
	virtual void render();

	//�浹 ������ �����´�.
	RECT getCollisionRect();

	//����Ű ����
	void setupKey(key::Enum key, int setupKey)
	{
		keyList[key] = (key::Enum)setupKey;
	}

	//�� ����
	void setupEnemy(gameObject* enemy)
	{
		_enemy = enemy;
	}
	
};