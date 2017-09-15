#pragma once
#include "gameObject.h"

//progressBar클래스: hp게이지, 경험치바 등등 다양하게 사용할 수 있는 UI 클래스
class progressBar : public gameObject
{
private:
	float _progressWidth;

	gameObject* _connectedObject;
	vector2D _offset;

	image* _progressBack;
	image* _progressFront;

public:
	HRESULT init(string imageBack, string imageFront, int width, int height);
	void release();

	//current: 현재 진척도 max: 최대 진척도
	void update(float current, float max);

	//isAbsolute가 true일 경우 화면 상 절대 좌표계로 그린다.
	void render(bool isAbsolute = true);

	//해당 오브젝트의 위치로 게이지를 연결한다. 
	//오브젝트가 움직이면 게이지의 위치도 자동으로 갱신된다.
	void connectObject(gameObject* obj, vector2D offset = vector2D(0,0));

	//게이지의 위치를 셋팅한다. 이걸 사용하면 connectObject는 자동으로 풀리고 위치가 고정된다.
	void setPosition(vector2D pos);

	progressBar();
	virtual ~progressBar();
};
