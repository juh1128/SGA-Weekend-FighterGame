#include "stdafx.h"
#include "timer.h"
#include <mmsystem.h>	//timeGetTime

#pragma comment(lib, "winmm.lib")


timer::timer()
{
}


timer::~timer()
{

}

HRESULT timer::init(void)
{
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency))
	{
		_isHardware = true;
		QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);

		_timeScale = 1.0f / _periodFrequency;
	}
	else
	{
		_isHardware = false;

		_lastTime = timeGetTime();
		_timeScale = 0.001f;
	}

	_frameRate = 0;
	_FPSFrameCount = 0;
	_FPSTimeElapsed = 0;
	_worldTime = 0;

	return S_OK;
}

void timer::tick(float lockFPS)
{
	if (_isHardware)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	}
	else
	{
		_curTime = timeGetTime();
	}


	_timeElapsed = (_curTime - _lastTime) * _timeScale;

	//Frame Per Second == Frame Skipping
	if (lockFPS > 0.0f)
	{
		//1.0f / lockFPS => 1프레임 당 주어진 시간
		//만약에 1프레임 당 주어진 시간보다 더 빨리 끝났을 경우
		//curTime을 갱신하면서 그냥 계속 대기한다.
		//렉걸려서 너무 늦게 끝났을 경우에 대한 대비는 없음. (싱글 게임용이라 크게 상관은 없다.)
		while (_timeElapsed < (1.0f / lockFPS)) 
		{
			if (_isHardware) QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			else _curTime = timeGetTime();

			_timeElapsed = (_curTime - _lastTime) * _timeScale;
		}
	}

	//1프레임이 지났으므로 관련된 변수를 업데이트한다.
	_lastTime = _curTime;
	_FPSFrameCount++;
	_FPSTimeElapsed += _timeElapsed;
	_worldTime += _timeElapsed;

	if (_FPSTimeElapsed > 1.0f)
	{
		_frameRate = _FPSFrameCount;
		_FPSFrameCount = 0;
		_FPSTimeElapsed = 0.0f;
	}
}

unsigned long timer::getFrameRate(char* str) const
{
	if (str != NULL)
	{
		wsprintf(str, "FPS : %d", _frameRate);
	}

	return _frameRate;
}
