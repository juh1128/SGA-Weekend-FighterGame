#pragma once
#include <deque>

//캐릭터 키
namespace key
{
	enum Enum
	{
		LEFT, RIGHT, JUMP, DOWN, ATTACK, STRONG_ATTACK, KICK, STRONG_KICK, END
	};
}

#define COMMAND_RESET_TIME 0.6f
#define MAX_COMMAND_NUM	5

#define GROUND_LINE 700

class character : public gameObject
{
private:
	float								_commandResetTimer;
	bool								_historyCheck;
	deque<int>							_commandHistory;
	vector<pair<vector<int>, string>>	_commandList;	//등록된 커맨드

	float			_gravitySpeed;

protected:
	key::Enum					keyList[key::END];		//단축키 리스트
	gameObject*					_enemy;					//상대편

public:
	character() {}
	virtual ~character() {}

	virtual HRESULT init(string characterName, vector2D pos, string animationKeyName);
	virtual void release();
	virtual void update();
	virtual void render();

	//커맨드 업데이트
	void updaetCommand();
	//중력 처리
	void gravity();

	//충돌 영역을 가져온다.
	RECT getCollisionRect();

	//단축키 설정
	void setupKey(key::Enum key, int setupKey)
	{
		keyList[key] = (key::Enum)setupKey;
	}
	//커맨드 설정
	void addCommand(int* arrKeyCode, int arrLen, string message);

	//적 셋팅
	void setupEnemy(gameObject* enemy)
	{
		_enemy = enemy;
	}
	
};