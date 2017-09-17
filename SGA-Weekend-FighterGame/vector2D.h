#pragma once

//=====================================
// ## 벡터2D ##
//=====================================
class vector2D
{
private:

public:
	float x;
	float y;

	vector2D() :x(0), y(0) {}
	vector2D(float _x, float _y) : x(_x), y(_y) {}
	vector2D(POINT pt) : x(pt.x), y(pt.y) {}
	vector2D(float angle)  //디그리 각도 (라디안 ㄴㄴ)
	{
		x = 0;
		y = 0;
		this->setDirVector(angle);
	}
	~vector2D() {}

	//연산자 오버로딩
	vector2D operator+ (vector2D v)
	{
		vector2D result;
		result.x = x + v.x;
		result.y = y + v.y;
		return result;
	}
	vector2D operator- (vector2D v)
	{
		vector2D result;
		result.x = x - v.x;
		result.y = y - v.y;
		return result;
	}
	vector2D operator* (float scalar)
	{
		vector2D result;
		result.x = x*scalar;
		result.y = y*scalar;
		return result;
	}
	vector2D operator/ (float scalar)
	{
		vector2D result;
		result.x = x / scalar;
		result.y = y / scalar;
		return result;
	}
	bool operator==(vector2D v)
	{
		if (x == v.x)
		{
			if (y == v.y)
			{
				return true;
			}
		}
		return false;
	}
	bool operator!=(vector2D v)
	{
		if (!(*this == v))
		{
			return true;
		}
		return false;
	}

	//현재 벡터를 정규화시킨 값을 반환한다.
	vector2D normalize(bool isSqrt = true);

	//현재 벡터를 현 위치에서 end방향을 가르키는 방향벡터로 설정한다.
	void setDirVector(vector2D start, vector2D end);
	//현재 벡터를 지정 각도를 가르키는 방향벡터로 설정한다.
	void setDirVector(float degree);
	//현재 벡터가 가르키는 방향의 각도를 반환한다.
	float getDegree();
	//현재 벡터의 길이를 반환한다.
	float getLength();

	//월드 좌표로 변환된 벡터를 반환한다.
	vector2D getWorldPos();
	POINT toPoint()
	{
		POINT pt;
		pt.x = x;
		pt.y = y;
		return pt;
	}

	//벡터를 내적한 값을 반환한다.
	float dotProduct(vector2D v);

	//위치 보정
	void fixedPosX(float min, float max);
	void fixedPosY(float min, float max);
};

