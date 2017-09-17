#pragma once

//=====================================
// ## ����2D ##
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
	vector2D(float angle)  //��׸� ���� (���� ����)
	{
		x = 0;
		y = 0;
		this->setDirVector(angle);
	}
	~vector2D() {}

	//������ �����ε�
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

	//���� ���͸� ����ȭ��Ų ���� ��ȯ�Ѵ�.
	vector2D normalize(bool isSqrt = true);

	//���� ���͸� �� ��ġ���� end������ ����Ű�� ���⺤�ͷ� �����Ѵ�.
	void setDirVector(vector2D start, vector2D end);
	//���� ���͸� ���� ������ ����Ű�� ���⺤�ͷ� �����Ѵ�.
	void setDirVector(float degree);
	//���� ���Ͱ� ����Ű�� ������ ������ ��ȯ�Ѵ�.
	float getDegree();
	//���� ������ ���̸� ��ȯ�Ѵ�.
	float getLength();

	//���� ��ǥ�� ��ȯ�� ���͸� ��ȯ�Ѵ�.
	vector2D getWorldPos();
	POINT toPoint()
	{
		POINT pt;
		pt.x = x;
		pt.y = y;
		return pt;
	}

	//���͸� ������ ���� ��ȯ�Ѵ�.
	float dotProduct(vector2D v);

	//��ġ ����
	void fixedPosX(float min, float max);
	void fixedPosY(float min, float max);
};

