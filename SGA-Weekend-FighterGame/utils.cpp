#include "stdafx.h"
#include "utils.h"

namespace OMICRON_UTIL
{
	//거리 가져오는 함수
	float getDistance(float startX, float startY, float endX, float endY)
	{
		float x = endX - startX;
		float y = endY - startY;

		return sqrtf(x * x + y * y);
	}

	//각도 알아오는 함수
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

		//최대 검사거리는 1000인데, 여기까지도 검출되지 않았으면 0을 반환 (false)
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

	//사각형과 원 충돌체크 함수
	bool isCollisionRectToEllipse(RECT rc, int rad, vector2D ellipseCenter)
	{
		//원이 사각형의 가로축 또는 세로축에 위치할 경우
		if (rc.left <= ellipseCenter.x && ellipseCenter.x <= rc.right ||
			rc.top <= ellipseCenter.y && ellipseCenter.y <= rc.bottom)
		{
			//사각형을 원의 반지름만큼 확장시킨 뒤 
			//확장된 사각형 안에 원의 중심점이 들어가 있는지 확인.
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
		//원이 사각형의 대각선에 위치할 경우
		else
		{
			//사각형의 꼭지점이 원의 범위 내에 있으면 충돌
			if (ptInCircle(vector2D((float)rc.left, (float)rc.top), ellipseCenter, rad)) return true;
			if (ptInCircle(vector2D((float)rc.left, (float)rc.bottom), ellipseCenter, rad)) return true;
			if (ptInCircle(vector2D((float)rc.right, (float)rc.top), ellipseCenter, rad)) return true;
			if (ptInCircle(vector2D((float)rc.right, (float)rc.bottom), ellipseCenter, rad)) return true;
		}
		return false;
	}

}