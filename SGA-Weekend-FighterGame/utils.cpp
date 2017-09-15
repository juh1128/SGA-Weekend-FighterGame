#include "stdafx.h"
#include "utils.h"

namespace OMICRON_UTIL
{
	//�Ÿ� �������� �Լ�
	float getDistance(float startX, float startY, float endX, float endY)
	{
		float x = endX - startX;
		float y = endY - startY;

		return sqrtf(x * x + y * y);
	}

	//���� �˾ƿ��� �Լ�
	float getAngle(float x1, float y1, float x2, float y2)
	{
		float x = x2 - x1;
		float y = y2 - y1;

		float distance = sqrtf((x * x) + (y * y));

		float angle = acos(x / distance);
		
		if (y2 > y1)
		{
			angle = PI2 - angle;
			if (angle >= PI2) angle -= PI2;
		}

		return angle;
	}

	int pixelRayCast(HDC memDC, vector2D startPos, vector2D direction, 
		COLORREF checkColor, bool isExcept, int precision)
	{
		vector2D checkPos = startPos;

		int distance = 0;
		int checkR = GetRValue(checkColor);
		int checkG = GetGValue(checkColor);
		int checkB = GetBValue(checkColor);

		while (distance < 1000)
		{
			COLORREF color = GetPixel(memDC, checkPos.x, checkPos.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if (isExcept)
			{
				if (!(r == checkR && g == checkG && b == checkB))
				{
					return distance;
				}
			}
			else
			{
				if (r == checkR && g == checkG && b == checkB)
				{
					return distance;
				}
			}

			checkPos = checkPos + (direction*precision);
			distance += precision;
		}

		//�ִ� �˻�Ÿ��� 1000�ε�, ��������� ������� �ʾ����� 0�� ��ȯ (false)
		return 0;
	}

	void modifyRect(RECT* rc, int left, int top, int right, int bottom)
	{
		rc->left = left;
		rc->top = top;
		rc->right = right;
		rc->bottom = bottom;
	}

	bool ptInCircle(vector2D pt, vector2D circlePos, int cr)
	{
		vector2D distance = pt - circlePos;
		float len = distance.getLength();

		if (len <= cr)
		{
			return true;
		}
		return false;
	}

	//�簢���� �� �浹üũ �Լ�
	bool isCollisionRectToEllipse(RECT rc, int rad, vector2D ellipseCenter)
	{
		//���� �簢���� ������ �Ǵ� �����࿡ ��ġ�� ���
		if (rc.left <= ellipseCenter.x && ellipseCenter.x <= rc.right ||
			rc.top <= ellipseCenter.y && ellipseCenter.y <= rc.bottom)
		{
			//�簢���� ���� ��������ŭ Ȯ���Ų �� 
			//Ȯ��� �簢�� �ȿ� ���� �߽����� �� �ִ��� Ȯ��.
			modifyRect(&rc,
				rc.left - rad, //left
				rc.top - rad, //top
				rc.right + rad, //right
				rc.bottom + rad //bottom
			);

			POINT pos = ellipseCenter.toPoint();
			if (PtInRect(&rc, pos))
			{
				return true;
			}
		}
		//���� �簢���� �밢���� ��ġ�� ���
		else
		{
			//�簢���� �������� ���� ���� ���� ������ �浹
			if (ptInCircle(vector2D((float)rc.left, (float)rc.top), ellipseCenter, rad)) return true;
			if (ptInCircle(vector2D((float)rc.left, (float)rc.bottom), ellipseCenter, rad)) return true;
			if (ptInCircle(vector2D((float)rc.right, (float)rc.top), ellipseCenter, rad)) return true;
			if (ptInCircle(vector2D((float)rc.right, (float)rc.bottom), ellipseCenter, rad)) return true;
		}
		return false;
	}

}