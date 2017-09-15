#pragma once
#include "gameObject.h"

//progressBarŬ����: hp������, ����ġ�� ��� �پ��ϰ� ����� �� �ִ� UI Ŭ����
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

	//current: ���� ��ô�� max: �ִ� ��ô��
	void update(float current, float max);

	//isAbsolute�� true�� ��� ȭ�� �� ���� ��ǥ��� �׸���.
	void render(bool isAbsolute = true);

	//�ش� ������Ʈ�� ��ġ�� �������� �����Ѵ�. 
	//������Ʈ�� �����̸� �������� ��ġ�� �ڵ����� ���ŵȴ�.
	void connectObject(gameObject* obj, vector2D offset = vector2D(0,0));

	//�������� ��ġ�� �����Ѵ�. �̰� ����ϸ� connectObject�� �ڵ����� Ǯ���� ��ġ�� �����ȴ�.
	void setPosition(vector2D pos);

	progressBar();
	virtual ~progressBar();
};
