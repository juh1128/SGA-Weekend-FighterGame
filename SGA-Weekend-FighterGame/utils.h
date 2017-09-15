#pragma once


#define PI 3.141592654f
#define PI2 PI * 2
#define TO_RAD PI/180
#define TO_DEGREE 180/PI

#define PI4 float(PI / 4.0f)
#define PI8 float(PI / 8.0f)
#define PI16 float(PI / 16.0f)
#define PI32 float(PI / 32.0f)
#define PI64 float(PI / 64.0f)
#define PI128 float(PI / 128.0f)

#define FLOAT_EPSILON 0.001f	//실수의 가장 작은 단위 == 엡실론(그리스어)
#define FLOAT_TO_INT(f1) static_cast<int>(f1 + FLOAT_EPSILON)
#define FLOAT_EQUAL(f1, f2) (fabs(f1, f2) <= FLOAT_EPSILON)


namespace OMICRON_UTIL
{

	float getDistance(float startX, float startY, float endX, float endY);

	float getAngle(float x1, float y1, float x2, float y2);

	// 체크 할 DC, 시작 위치, 방향, 체크할 색상, 제외여부 (checkColor를 제외한 모든 색을 검사하고 싶을 경우 true), 정밀도 (수치가 낮을수록 정밀하다.) 
	// 체크 색상이 검출된 거리를 반환한다.
	int pixelRayCast(HDC memDC, vector2D startPos, vector2D direction, COLORREF checkColor, bool isExcept, int precision = 1);

	void modifyRect(RECT* rc, int left, int top, int right, int bottom);
	bool ptInCircle(vector2D pt, vector2D circlePos, int cr);
	bool isCollisionRectToEllipse(RECT rc, int rad, vector2D ellipseCenter);
}

typedef struct tagFloatRect
{
	float left;
	float top;
	float right;
	float bottom;
	tagFloatRect(float l = 0, float t = 0, float r = 1, float b = 1)
		:left(l), top(t), right(r), bottom(b) {}
}FLOAT_RECT, *LPFLOAT_RECT;
