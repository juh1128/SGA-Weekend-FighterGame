#include "stdafx.h"
#include "keyAniManager.h"
#include "image.h"
#include "animation.h"
#include "gameObject.h"

keyAniManager::keyAniManager()
{
}


keyAniManager::~keyAniManager()
{

}

HRESULT keyAniManager::init()
{

	return S_OK;
}

void keyAniManager::release()
{
	deleteAll();
}

void keyAniManager::update()
{
	iterAnimations iter = _mTotalAnimation.begin();

	for (iter; iter != _mTotalAnimation.end(); ++iter)
	{
		if (!iter->second->isPlay()) continue;

		iter->second->frameUpdate();
	}

}

void keyAniManager::render()
{

}


//디폴트 애니메이션
void keyAniManager::addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop);
	ani->setFPS(fps);

	ani->setImage(img);
	RECT rc = RectMake(0, 0, img->getFrameWidth(), img->getFrameHeight());
	ani->setCollisionRect(rc);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));


}

void keyAniManager::addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop, (CALLBACK_FUNCTION)cbFunction);
	ani->setFPS(fps);

	ani->setImage(img);
	RECT rc = RectMake(0, 0, img->getFrameWidth(), img->getFrameHeight());
	ani->setCollisionRect(rc);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));
}

void keyAniManager::addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction, void* obj)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop, (CALLBACK_FUNCTION_PARAMETER)cbFunction, obj);
	ani->setFPS(fps);

	ani->setImage(img);
	RECT rc = RectMake(0, 0, img->getFrameWidth(), img->getFrameHeight());
	ani->setCollisionRect(rc);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));
}

//배열 애니메이션
void keyAniManager::addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(arr, arrLen, loop);
	ani->setFPS(fps);

	ani->setImage(img);
	RECT rc = RectMake(0, 0, img->getFrameWidth(), img->getFrameHeight());
	ani->setCollisionRect(rc);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));
}

void keyAniManager::addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(arr, arrLen, loop, CALLBACK_FUNCTION(cbFunction));
	ani->setFPS(fps);

	ani->setImage(img);
	RECT rc = RectMake(0, 0, img->getFrameWidth(), img->getFrameHeight());
	ani->setCollisionRect(rc);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));
}

void keyAniManager::addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction, void* obj)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(arr, arrLen, loop, CALLBACK_FUNCTION_PARAMETER(cbFunction), obj);
	ani->setFPS(fps);

	ani->setImage(img);
	RECT rc = RectMake(0, 0, img->getFrameWidth(), img->getFrameHeight());
	ani->setCollisionRect(rc);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));
}


//구간 애니메이션
void keyAniManager::addCoordinateFrameAnimation(string animationKeyName, char* imageKeyName, int start, int end, int fps, bool reverse, bool loop)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop);
	ani->setFPS(fps);

	ani->setImage(img);
	RECT rc = RectMake(0, 0, img->getFrameWidth(), img->getFrameHeight());
	ani->setCollisionRect(rc);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));
}

void keyAniManager::addCoordinateFrameAnimation(string animationKeyName, char* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop, (CALLBACK_FUNCTION)cbFunction);
	ani->setFPS(fps);

	ani->setImage(img);
	RECT rc = RectMake(0, 0, img->getFrameWidth(), img->getFrameHeight());
	ani->setCollisionRect(rc);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));
}

void keyAniManager::addCoordinateFrameAnimation(string animationKeyName, char* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction, void* obj)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop, (CALLBACK_FUNCTION_PARAMETER)cbFunction, obj);
	ani->setFPS(fps);

	ani->setImage(img);
	RECT rc = RectMake(0, 0, img->getFrameWidth(), img->getFrameHeight());
	ani->setCollisionRect(rc);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));
}


void keyAniManager::start(string animationKeyName)
{
	iterAnimations iter = _mTotalAnimation.find(animationKeyName);
	iter->second->start();
}

void keyAniManager::stop(string animationKeyName)
{
	iterAnimations iter = _mTotalAnimation.find(animationKeyName);
	iter->second->stop();
}

void keyAniManager::pause(string animationKeyName)
{
	iterAnimations iter = _mTotalAnimation.find(animationKeyName);
	iter->second->pause();
}

void keyAniManager::resume(string animationKeyName)
{
	iterAnimations iter = _mTotalAnimation.find(animationKeyName);
	iter->second->resume();
}


animation* keyAniManager::findAnimation(string animationKeyName)
{
	iterAnimations iter = _mTotalAnimation.find(animationKeyName);

	if (iter != _mTotalAnimation.end())
	{
		return iter->second;
	}


	char buf[200];
	wsprintf(buf, "[ 에러 ] %s 애니메이션을 찾지 못했습니다.", animationKeyName.c_str());
	MessageBox(_hWnd, buf, TEXT("오류"), MB_OK);

	return NULL;
}


void keyAniManager::deleteAll()
{
	for (iterAnimations iter = _mTotalAnimation.begin(); iter != _mTotalAnimation.end();)
	{
		if (iter->second != NULL)
		{
			iter->second->release();
			SAFE_DELETE(iter->second);
			iter = _mTotalAnimation.erase(iter);
		}
		else ++iter;

	}

	_mTotalAnimation.clear();
}


void keyAniManager::setCollisionRect(string animationKeyName, RECT collisionRect)
{
	auto anim = findAnimation(animationKeyName);
	if (anim)
	{
		anim->setCollisionRect(collisionRect);
	}
}