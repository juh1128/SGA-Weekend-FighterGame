#include "stdafx.h"
#include "vector2D.h"

//=====================================
// ## 벡터2D ##
//=====================================

vector2D vector2D::normalize(bool isSqrt)
{
	vector2D result;
	float size = 1;

	(isSqrt) ? size = sqrt(x*x + y*y) : size = x*x + y*y;

	if (size != 0)
	{
		result.x = x / size;
		result.y = y / size;
	}
	else
	{
		result.x = 0;
		result.y = 0;
	}

	return result;
}

//현재 벡터를 start에서 end 쪽을 가르키는 방향벡터로 설정한다.
void vector2D::setDirVector(vector2D start, vector2D end)
{
	vector2D dir = end - start;
	(*this) = dir.normalize();
}

//현재 벡터를 지정 각도를 가르키는 방향벡터로 설정한다.
void vector2D::setDirVector(float degree)
{
	x = cos(degree*TO_RAD);
	y = -sin(degree*TO_RAD);
}

float vector2D::getDegree()
{
	int sign = 1;
	vector2D dir = *this;
	dir = dir.normalize();
	(dir.y > 0) ? sign = -1 : sign = 1;
	return sign*(acos(dir.x)*TO_DEGREE);
}

float vector2D::getLength()
{
	return sqrt(x*x + y*y);
}

void vector2D::fixedPosX(float min, float max)
{
	if (x < min) x = min;
	if (x > max) x = max;
}

void vector2D::fixedPosY(float min, float max)
{
	if (y < min) y = min;
	if (y > max) y = max;
}

vector2D vector2D::getWorldPos()
{
	RECT rc = CAMERAMANAGER->getRenderRect();
	return vector2D(x + rc.left, y + rc.top);
}

float vector2D::dotProduct(vector2D v)
{
	return x*v.x + y*v.y;
}