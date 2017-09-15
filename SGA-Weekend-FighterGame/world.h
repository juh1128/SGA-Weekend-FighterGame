#pragma once


#define MAX_LAYER 5

//�� ������ ������Ʈ���� �Ѱ��ϴ� Ŭ������.
class world
{
private:
	vector<gameObject*> _objectList[MAX_LAYER];

public:
	world() {}
	~world() {}

	void init();
	void update();
	void render();
	void release();

	//������Ʈ�� �߰��Ѵ�. (2��° ���ڴ� ������ �켱����)
	void addObject(gameObject* obj, int renderPriority = 1);
	//name�� ��ġ�ϴ� ������Ʈ�� ã�Ƽ� ��ȯ�Ѵ�.
	gameObject* findObject(string name);
	//name�� ��ġ�ϴ� ������Ʈ�� ��� ã�Ƽ� ���ͷ� ��ȯ�Ѵ�.
	vector<gameObject*> findObjects(string name);
	
	vector<gameObject*> findObjects(string name, int priorityNum);
};