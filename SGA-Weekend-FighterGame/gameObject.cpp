#include "stdafx.h"



HRESULT gameObject::init(string objectName, string imageKey, vector2D pos, Pivot::Enum pivot)
{
	_name = objectName;

	_animation = new animation;
	//�̹����� ���� ���
	if (imageKey != "")
	{
		_image = IMAGEMANAGER->findImage(imageKey);
		_size.x = _image->getFrameWidth();
		_size.y = _image->getFrameHeight();
	
		_animation->init(_image->getWidth(), _image->getHeight(), _image->getFrameWidth(), _image->getFrameHeight());
	}
	//�̹����� ���� ���
	else
	{
		_image = NULL;
		_size.x = 1;
		_size.y = 1;
		_animation->init(1, 1, 1, 1);
	}

	_pos = pos;
	_pivot = pivot;

	_scale = vector2D(1.0f, 1.0f);
	_isScaled = false;

	_alpha = 1.0f;

	_isLive = true;
	_isActive = true;
	_destroyDelayTime = 0;

	addBaseCallback();

	return S_OK;
}

RECT gameObject::getRect()
{
	RECT rc;

	float scaledX = _size.x * _scale.x;
	float scaledY = _size.y * _scale.y;

	//������ �Ǻ��� ���� ��Ʈ�� �����.
	switch (_pivot)
	{
		case Pivot::LEFT_TOP:
		{
			rc = RectMake(_pos.x, _pos.y, scaledX, scaledY);
		}
		break;

		case Pivot::CENTER:
		{
			rc = RectMakeCenter(_pos.x, _pos.y, scaledX, scaledY);
		}
		break;

		case Pivot::BOTTOM:
		{
			rc.left = _pos.x - scaledX / 2;
			rc.right = _pos.x + scaledX / 2;
			rc.top = _pos.y - scaledY;
			rc.bottom = _pos.y;
		}
		break;
	}

	return rc;
}

void gameObject::release(void)
{
	_reservedMessage.clear();
	_messageList.clear();

	_animation->release();
	SAFE_DELETE(_animation);
}

void gameObject::update(void)
{
	//���ӿ�����Ʈ ���� ������ Ÿ���� Ȱ��ȭ ���� ���
	if (_destroyDelayTime > 0.0f)
	{
		_destroyDelayTime -= TIMEMANAGER->getElapsedTime();
		if (_destroyDelayTime <= 0.0f)
		{
			_isLive = false;
		}
	}

	//�޽��� ���� ����Ʈ ������Ʈ
	float elapsedTime = TIMEMANAGER->getElapsedTime();
	for (int i = 0; i < _reservedMessage.size(); ++i)
	{
		_reservedMessage[i].delayTime -= elapsedTime;
		//������ Ÿ���� �� ������ �޽��� ����Ʈ�� �ű��.
		if (_reservedMessage[i].delayTime <= 0.0f)
		{
			_reservedMessage[i].delayTime = 0.0f;
			_messageList.emplace_back(_reservedMessage[i]);
			_reservedMessage.erase(_reservedMessage.begin() + i);
			--i;
		}
	}

	//�޽��� ó���ϱ�
	for (int i = _messageList.size() - 1; i >= 0; --i)
	{
		auto iter = _callbackList.find(_messageList[i].text);
		if (iter != _callbackList.end())
		{
			iter->second(_messageList[i]);
		}
		_messageList.pop_back();
	}
}

void gameObject::render(void)
{
	image* renderImage = (_animation->getImage()) ? _animation->getImage() : _image;
	if (renderImage)
	{
		//���� ������Ʈ�� ���� RECT
		RECT renderRC = getRect();	

		if (_alpha < 0) _alpha = 0.0f;
		if (_alpha > 1.0f) _alpha = 1.0f;

		//����ó�� X
		if (_alpha == 1.0f)
		{
			// Ȯ��,��� X
			if (!_isScaled)
			{
				renderImage->aniRender(getMemDC(), renderRC.left, renderRC.top, _animation);
			}
			// Ȯ��,��� O
			else
			{
				renderImage->scaleAniRender(getMemDC(), renderRC.left, renderRC.top,
					_animation, renderRC.right-renderRC.left, renderRC.bottom-renderRC.top);
			}
		}
		//����ó�� O
		else
		{
			// Ȯ��,��� X
			if (!_isScaled)
			{
				renderImage->alphaAniRender(getMemDC(), renderRC.left, renderRC.top, _animation, _alpha);
			}
			// Ȯ��,��� O
			else
			{
				renderImage->alphaScaleAniRender(getMemDC(), renderRC.left, renderRC.top,
					_animation, renderRC.right - renderRC.left, renderRC.bottom - renderRC.top, _alpha);
			}
		}
	}
}

bool gameObject::isActiveObject()
{
	//������Ʈ�� �׾��ٸ� ������ false
	if (!_isLive)
		return false;

	//������Ʈ�� ��������� active�� false�� ���
	if (!_isActive)
		return false;

	return true;
}

void gameObject::setDestroy(float delayTime)
{
	if (delayTime <= 0.0f)
	{
		_isLive = false;
	}
	else
	{
		_destroyDelayTime = delayTime;
	}
}

//�޽��� ó�� ����
void gameObject::sendMessage(string text, float delayTime, int data, float data2, vector<gameObject*> targetList)
{
	//������Ÿ���� ������ �ٷ� �޽��� ���Ϳ� �ִ´�.
	if (delayTime == 0.0f)
	{
		_messageList.emplace_back(text, 0.0f, data, data2, targetList);
	}
	//������Ÿ���� ������ �޽��� ���� ����Ʈ�� �ִ´�.
	else
	{
		_reservedMessage.emplace_back(text, delayTime, data, data2, targetList);
	}
}

void gameObject::addBaseCallback()
{
	this->addCallback("changeAlpha", [this](tagMessage msg)
	{
		this->setAlpha(msg.data2);
	});
}


void gameObject::setAnimation(string animationKeyName)
{
	auto anim = KEYANIMANAGER->findAnimation(animationKeyName);
	*_animation = *anim;
	_animation->start();

	_size.x = _animation->getFrameWidth();
	_size.y = _animation->getFrameHeight();
}