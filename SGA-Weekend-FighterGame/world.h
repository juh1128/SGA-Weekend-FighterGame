#pragma once


#define MAX_LAYER 5

//씬 내에서 오브젝트들을 총괄하는 클래스다.
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

	//오브젝트를 추가한다. (2번째 인자는 렌더링 우선순위)
	void addObject(gameObject* obj, int renderPriority = 1);
	//name이 일치하는 오브젝트를 찾아서 반환한다.
	gameObject* findObject(string name);
	//name이 일치하는 오브젝트를 모두 찾아서 벡터로 반환한다.
	vector<gameObject*> findObjects(string name);
	
	vector<gameObject*> findObjects(string name, int priorityNum);
};