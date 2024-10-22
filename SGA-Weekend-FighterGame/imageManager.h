#pragma once
#include "singletonBase.h"
#include "image.h"
#include <map>

class imageManager : public singletonBase<imageManager>
{
private:
	typedef map<string, image*> mapImageList;
	typedef map<string, image*>::iterator mapImageIter;

private:
	mapImageList _mImageList;

public:
	HRESULT init(void);
	void release(void);

	image* addImage(string strKey, int width, int height);

	image* addImage(string strKey, const char* fileName, int width, int height, bool trans = false, COLORREF transColor = RGB(255,0,255));
	image* addImage(string strKey, const char* fileName, float x, float y, int width, int height, bool trans = false, COLORREF transColor = RGB(255, 0, 255));

	image* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans = false, COLORREF transColor = RGB(255, 0, 255));
	image* addFrameImage(string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool trans = false, COLORREF transColor = RGB(255, 0, 255));

	//이미지 찾는 함수
	image* findImage(string strKey);

	BOOL deleteImage(string strKey);

	BOOL deleteAll(void);
	void resetImage();	//백버퍼만 빼고 다 날림

	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	void frameRender(string strKey, HDC hdc, int destX, int destY);


	imageManager();
	~imageManager();
};

