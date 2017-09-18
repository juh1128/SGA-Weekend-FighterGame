#pragma once
#include "gameNode.h"
#include <functional>

namespace Pivot
{
	enum Enum
	{
		LEFT_TOP, CENTER, BOTTOM
	};
}


class gameObject : public gameNode
{
private:
	vector2D		_scale;			//Ȯ�� ����
	bool			_isScaled;
	vector2D		_size;			//���� ������Ʈ�� ũ�� (�̹��� ũ�� * _scale)

	bool			_isLive;		//���� ������Ʈ�� ����ִ��� ����.
	bool			_isActive;		//���� ������Ʈ Ȱ��ȭ ����.
	float			_destroyDelayTime;

	//�޽��� ó�� ����
	vector<tagMessage> _reservedMessage;
	vector<tagMessage> _messageList;
	unordered_map<string, std::function<void(tagMessage)>> _callbackList;

protected:
	//LEFT_TOP: �»���� �������� �׸���. CENTER: pos�� �߾����� �׸���. BOTTOM: pos�� �ϴ����� �׸���.
	Pivot::Enum		_pivot;	
	image*			_image;			//���� ������Ʈ �̹���
	animation*		_animation;		//���� ������Ʈ�� �ִϸ��̼� ����
	float			_alpha;			//���� ������Ʈ ���İ� (0.0f ~ 1.0f)

public:
	string			_name;
	vector2D		_pos;

	//�̹��� Ű��, ��ġ��
	virtual HRESULT init(string objectName, string imageKey = "", vector2D pos = vector2D(0,0), Pivot::Enum pivot = Pivot::CENTER);

	virtual void release(void);

	//���� ������Ʈ�� �޽��� ó��, ������ Ÿ�� �� ������ ���õ� ó���� ��.
	virtual void update(void);	
	virtual void render(void);

	void setScale(float ratioX, float ratioY)
	{
		_scale.x = ratioX;
		_scale.y = ratioY;
		_isScaled = true;
		if (ratioX == 1.0f && ratioY == 1.0f)
			_isScaled = false;
	}
	vector2D getScale() { return _scale; }

	void setAlpha(float set) { _alpha = set; }
	float getAlpha() { return _alpha; }

	//setSize ��� �� scale�� 1.0f���� �ǵ��ư�.
	void setSize(int width, int height)
	{
		_scale.x = 1.0f;
		_scale.y = 1.0f;
		_size.x = width;
		_size.y = height;
		_isScaled = true;
	}
	vector2D getOriginSize()
	{
		return _size;
	}
	vector2D getSize() 
	{
		float scaledX = _size.x * _scale.x;
		float scaledY = _size.y * _scale.y;
		return vector2D(scaledX, scaledY); 
	}

	gameObject() {}
	virtual ~gameObject() {}

	RECT getRect();
	virtual RECT getCollisionRect() { return getRect(); }

	bool isActiveObject();
	bool isLive() { return _isLive; }
	void setDestroy(float delayTime = 0.0f);
	void setActive(bool set) { _isActive = set; }

	//�޽����� �����Ѵ�.
	void sendMessage(string text, float delayTime = 0.0f, int data = 0, float data2 = 0.0f, vector<gameObject*> targetList = vector<gameObject*>());
	//�ݹ� �Լ� ����
	void addCallback(string msgName, std::function<void(tagMessage)> callbackFunc)
	{
		_callbackList.insert(make_pair(msgName, callbackFunc));
	}

	//�ִϸ��̼� ����
	void setAnimation(string animationKeyName);


private:
	void addBaseCallback();
};