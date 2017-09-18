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
	vector2D		_scale;			//확대 비율
	bool			_isScaled;
	vector2D		_size;			//게임 오브젝트의 크기 (이미지 크기 * _scale)

	bool			_isLive;		//게임 오브젝트가 살아있는지 여부.
	bool			_isActive;		//게임 오브젝트 활성화 여부.
	float			_destroyDelayTime;

	//메시지 처리 관련
	vector<tagMessage> _reservedMessage;
	vector<tagMessage> _messageList;
	unordered_map<string, std::function<void(tagMessage)>> _callbackList;

protected:
	//LEFT_TOP: 좌상단을 기준으로 그린다. CENTER: pos을 중앙으로 그린다. BOTTOM: pos을 하단으로 그린다.
	Pivot::Enum		_pivot;	
	image*			_image;			//게임 오브젝트 이미지
	animation*		_animation;		//게임 오브젝트의 애니메이션 정보
	float			_alpha;			//게임 오브젝트 알파값 (0.0f ~ 1.0f)

public:
	string			_name;
	vector2D		_pos;

	//이미지 키값, 위치값
	virtual HRESULT init(string objectName, string imageKey = "", vector2D pos = vector2D(0,0), Pivot::Enum pivot = Pivot::CENTER);

	virtual void release(void);

	//게임 오브젝트의 메시지 처리, 딜레이 타임 후 삭제와 관련된 처리를 함.
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

	//setSize 사용 시 scale은 1.0f으로 되돌아감.
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

	//메시지를 전달한다.
	void sendMessage(string text, float delayTime = 0.0f, int data = 0, float data2 = 0.0f, vector<gameObject*> targetList = vector<gameObject*>());
	//콜백 함수 저장
	void addCallback(string msgName, std::function<void(tagMessage)> callbackFunc)
	{
		_callbackList.insert(make_pair(msgName, callbackFunc));
	}

	//애니메이션 셋팅
	void setAnimation(string animationKeyName);


private:
	void addBaseCallback();
};