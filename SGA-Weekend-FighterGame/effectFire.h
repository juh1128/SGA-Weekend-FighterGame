#pragma once
#include "gameObject.h"

class effectFire : public gameObject
{
private:

	int _count;

	vector2D _fire;
public:
	int _frameX;
	image* _image;

	HRESULT init( string imageKey, vector2D pos);
	void release();
	void update();
	void render();

	effectFire() {}
	virtual ~effectFire() {}
};

