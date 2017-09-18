#include "stdafx.h"
#include "animation.h"
#include "gameObject.h"



animation::animation()
	: _frameNum(0),
	_frameWidth(0),
	_frameHeight(0),
	_loop(FALSE),
	_frameUpdateSec(0),
	_elapsedSec(0),
	_nowPlayIndex(0),
	_play(FALSE),
	_img(NULL)
{
	_collisionRect = { 0,0,0,0 };
	_endMessage.text = "NULL";
	_messageTarget = NULL;

	_maxFrameX = 0;
	_maxFrameY = 0;
}


animation::~animation()
{

}

HRESULT animation::init(int totalW, int totalH, int frameW, int frameH)
{
	_frameWidth = frameW;
	int _frameNumWidth = totalW / _frameWidth;
	_maxFrameX = _frameNumWidth;

	_frameHeight = frameH;
	int _frameNumHeight = totalH / _frameHeight;
	_maxFrameY = _frameNumHeight;

	_frameNum = _frameNumWidth * _frameNumHeight;

	for (int i = 0; i < _frameNumHeight; i++)
	{
		for (int j = 0; j < _frameNumWidth; j++)
		{
			POINT framePos;

			framePos.x = j * _frameWidth;
			framePos.y = i * _frameHeight;

			_frameList.push_back(framePos);
		}
	}

	//일단 기본은 디폴트 애니메이션 재생으로 둔다
	setDefPlayFrame();

	return S_OK;
}

void animation::release(void)
{

}


void animation::setDefPlayFrame(BOOL reverse, BOOL loop)
{
	_obj = NULL;
	_callbackFunction = NULL;
	_callbackFunctionParameter = NULL;


	_loop = loop;

	_playList.clear();

	if (reverse)
	{
		if (_loop)
		{
			// 0 1 2 3 4
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
			// 3 2 1 
			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			// 0 1 2 3 4
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
			// 3 2 1 
			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else
	{
		if (_loop)
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
		}
	}
}

void animation::setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction)
{
	_obj = NULL;
	_callbackFunction = cbFunction;
	_callbackFunctionParameter = NULL;

	_loop = loop;

	_playList.clear();

	if (reverse)
	{
		if (_loop)
		{
			// 0 1 2 3 4
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
			// 3 2 1 
			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			// 0 1 2 3 4
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
			// 3 2 1 
			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else
	{
		if (_loop)
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
		}
	}
}

void animation::setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj)
{
	_obj = obj;
	_callbackFunction = NULL;
	_callbackFunctionParameter = cbFunction;

	_loop = loop;

	_playList.clear();

	if (reverse)
	{
		if (_loop)
		{
			// 0 1 2 3 4
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
			// 3 2 1 
			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			// 0 1 2 3 4
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
			// 3 2 1 
			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else
	{
		if (_loop)
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
		}
	}
}

void animation::setPlayFrame(int* playArr, int arrLen, BOOL loop)
{
	_obj = NULL;
	_callbackFunction = NULL;
	_callbackFunctionParameter = NULL;

	_loop = loop;

	_playList.clear();

	for (int i = 0; i < arrLen; i++)
	{
		_playList.push_back(playArr[i]);
	}

}

void animation::setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION cbFunction)
{
	_obj = NULL;
	_callbackFunction = cbFunction;
	_callbackFunctionParameter = NULL;

	_loop = loop;

	_playList.clear();

	for (int i = 0; i < arrLen; i++)
	{
		_playList.push_back(playArr[i]);
	}

}

void animation::setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj)
{
	_obj = obj;
	_callbackFunction = NULL;
	_callbackFunctionParameter = cbFunction;

	_loop = loop;

	_playList.clear();

	for (int i = 0; i < arrLen; i++)
	{
		_playList.push_back(playArr[i]);
	}

}

void animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop)
{
	_obj = NULL;
	_callbackFunction = NULL;
	_callbackFunctionParameter = NULL;

	_loop = loop;

	_playList.clear();

	if (start == end)
	{
		_playList.clear();
		stop();
		return;
	}

	if (start > end)
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}

				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}

				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			if (_loop)
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
			}
		}
	}
	else
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			if (_loop)
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}
			}
		}
	}
}

void animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction)
{
	_obj = NULL;
	_callbackFunction = cbFunction;
	_callbackFunctionParameter = NULL;

	_loop = loop;

	_playList.clear();

	if (start == end)
	{
		_playList.clear();
		stop();
		return;
	}

	if (start > end)
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}

				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}

				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			if (_loop)
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
			}
		}
	}
	else
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			if (_loop)
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}
			}
		}
	}
}

void animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj)
{
	_obj = obj;
	_callbackFunction = NULL;
	_callbackFunctionParameter = cbFunction;

	_loop = loop;

	_playList.clear();

	if (start == end)
	{
		_playList.clear();
		stop();
		return;
	}

	if (start > end)
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}

				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}

				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			if (_loop)
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
			}
		}
	}
	else
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			if (_loop)
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}
			}
		}
	}
}


void animation::setFPS(int framePerSec)
{
	_frameUpdateSec = 1.0f / framePerSec;
}


void animation::frameUpdate()
{
	if (_play)
	{
		//경과된 시간을 업데이트한다.
		_elapsedSec += TIMEMANAGER->getElapsedTime();

		//경과된 시간이 프레임 업데이트 시간을 넘어서면
		if (_elapsedSec >= _frameUpdateSec)
		{
			//경과된 시간을 빼고 playIndex를 1증가시킨다. (애니메이션 프레임 증가)
			_elapsedSec -= _frameUpdateSec;
			_nowPlayIndex++;

			//애니메이션 프레임이 마지막에 닿으면 loop일 경우 0으로 돌아가고
			//아닐 경우 마지막 프레임에서 멈춘다.
			if (_nowPlayIndex == _playList.size())
			{
				if (_loop) _nowPlayIndex = 0;
				else
				{
					if (_obj == NULL)
					{
						if (_callbackFunction != NULL) _callbackFunction();
					}
					else
					{
						_callbackFunctionParameter(_obj);
					}

					_nowPlayIndex--;
					_play = FALSE;
				}

				if (_messageTarget)
				{
					_messageTarget->sendMessage(_endMessage.text, _endMessage.delayTime,
						_endMessage.data, _endMessage.data2, _endMessage.ptData, _endMessage.targetList);
				}
			}
		}
	}
}


void animation::start(void)
{
	_play = TRUE;
	_nowPlayIndex = 0;
}

void animation::stop(void)
{
	_play = FALSE;
	_nowPlayIndex = 0;
}

void animation::pause(void)
{
	_play = FALSE;

}

void animation::resume(void)
{
	_play = TRUE;

}

void animation::addFrame(void)
{
	_nowPlayIndex++;

	//애니메이션 프레임이 마지막에 닿으면 loop일 경우 0으로 돌아가고
	//아닐 경우 마지막 프레임에서 멈춘다.
	if (_nowPlayIndex == _playList.size())
	{
		if (_loop) _nowPlayIndex = 0;
		else
		{
			_nowPlayIndex--;
			_play = FALSE;
		}
	}
}

void animation::setFrame(int frame)
{
	if (frame < 0) frame = 0;
	_nowPlayIndex = frame;

	//애니메이션 프레임이 마지막에 닿으면 loop일 경우 0으로 돌아가고
	//아닐 경우 마지막 프레임에서 멈춘다.
	if (_nowPlayIndex == _playList.size())
	{
		if (_loop) _nowPlayIndex = 0;
		else
		{
			_nowPlayIndex--;
			_play = FALSE;
		}
	}
}

void animation::setImage(image* img)
{
	_img = img;
}

image* animation::getImage()
{
	return _img;
}

void animation::setEndMessage(gameObject* target, tagMessage msg)
{
	_endMessage = std::move(msg);
	_messageTarget = target;
}