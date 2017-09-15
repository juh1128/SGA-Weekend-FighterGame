#pragma once


class callbackTest : public gameObject
{
private:
	int hp;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	void callbackFunc(tagMessage msg);
};