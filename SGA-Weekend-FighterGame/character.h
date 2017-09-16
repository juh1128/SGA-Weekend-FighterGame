#pragma once
#include <deque>

//ĳ���� Ű
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
	vector<pair<vector<int>, string>>	_commandList;	//��ϵ� Ŀ�ǵ�

	float			_gravitySpeed;

protected:
	key::Enum					keyList[key::END];		//����Ű ����Ʈ
	gameObject*					_enemy;					//�����

public:
	character() {}
	virtual ~character() {}

	virtual HRESULT init(string characterName, vector2D pos, string animationKeyName);
	virtual void release();
	virtual void update();
	virtual void render();

	//Ŀ�ǵ� ������Ʈ
	void updaetCommand();
	//�߷� ó��
	void gravity();

	//�浹 ������ �����´�.
	RECT getCollisionRect();

	//����Ű ����
	void setupKey(key::Enum key, int setupKey)
	{
		keyList[key] = (key::Enum)setupKey;
	}
	//Ŀ�ǵ� ����
	void addCommand(int* arrKeyCode, int arrLen, string message);

	//�� ����
	void setupEnemy(gameObject* enemy)
	{
		_enemy = enemy;
	}
	
};