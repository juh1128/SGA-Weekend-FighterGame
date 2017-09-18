#pragma once
#include "gameObject.h"

class athenaeffect : public gameObject
{
private:

	int _count;


public:
	int _frameX;
	image* _image;
	vector2D _fire;
	bool _isFrame;

	HRESULT init(string imageKey, vector2D pos);
	void release();
	void update();
	void render();

	athenaeffect() {}
	virtual ~athenaeffect() {}
};
