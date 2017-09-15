#pragma once
#include "singletonBase.h"
#include "timer.h"

class timeManager : public singletonBase<timeManager>
{
private:
	timer* _timer;

public:
	HRESULT init(void);
	void release(void);
	void update(float lock = 0.0f);
	void render(HDC hdc);

	//1프레임 지나는데 걸린 시간.
	inline float getElapsedTime(void) const { return _timer->getElapsedTime(); }
	//현재 게임 시간.
	inline float getWorldTime(void) const { return _timer->getWorldTime(); }


	timeManager();
	~timeManager();
};

