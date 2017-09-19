#pragma once
#include "gameNode.h"

class animation;

class effect : public gameNode
{
protected:
	int _x;
	int _y;
	
	vector2D _scale;

	image* _effectImage;			//이펙트 이미지
	animation* _effectAnimation;	//이펙트 애니메이션
	BOOL _isRunning;				//이펙트 활성화 여부

public:
	virtual HRESULT init(image* effectImage, int frameW, int frameH, int fps);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void startEffect(int x, int y);

	virtual void killEffect(void);

	BOOL getIsRunning(void) { return _isRunning; }

	void setScale(float x, float y) 
	{
		_scale.x = x; _scale.y = y; 
	}



	effect();
	virtual ~effect();
};

