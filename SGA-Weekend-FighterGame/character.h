#pragma once

//캐릭터 키
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
	key::Enum			keyList[key::END];		//단축키 리스트
	gameObject*			_enemy;					//상대편

public:
	character() {}
	virtual ~character() {}

	virtual HRESULT init(string characterName, vector2D pos, string animationKeyName);
	virtual void release();
	virtual void update();
	virtual void render();

	//충돌 영역을 가져온다.
	RECT getCollisionRect();

	//단축키 설정
	void setupKey(key::Enum key, int setupKey)
	{
		keyList[key] = (key::Enum)setupKey;
	}

	//적 셋팅
	void setupEnemy(gameObject* enemy)
	{
		_enemy = enemy;
	}
	
};