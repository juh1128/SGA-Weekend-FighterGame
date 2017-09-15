#include "stdafx.h"
#include "world.h"

void world::init()
{

}

void world::update()
{
	for (int i = 0; i < MAX_LAYER; ++i)
	{
		for (unsigned int j = 0; j < _objectList[i].size(); ++j)
		{	
			gameObject* object = _objectList[i][j];
			if (object->isLive())
			{
				if (object->isActiveObject())
				{
					object->update();
				}			
			}
			else
			{
				object->release();
				delete object;
				object->setDestroy();
				_objectList[i].erase(_objectList[i].begin() + j);
				--j;
			}
		}
	}

}

void world::render()
{
	//화면 안에 있는 오브젝트만 렌더링 함.
	RECT renderRect = CAMERAMANAGER->getRenderRect();

	for (int i = 0; i < MAX_LAYER; ++i)
	{
		unsigned int size = _objectList[i].size();
		for (unsigned int j = 0; j<size; ++j)
		{
			gameObject* object = _objectList[i][j];
			if (object->isActiveObject())
			{
				if (PtInRect(&renderRect, object->_pos.toPoint()))
					object->render();
			}
		}
	}
}

void world::addObject(gameObject* obj, int renderPriority)
{
	_objectList[renderPriority].push_back(obj);
}

gameObject* world::findObject(string name)
{
	for (int i = 0; i < MAX_LAYER; ++i)
	{
		for (unsigned int j = 0; j < _objectList[i].size(); ++j)
		{
			if (_objectList[i][j]->isLive())
			{
				if (_objectList[i][j]->_name == name)
				{
					return _objectList[i][j];
				}
			}
		}
	}
	return nullptr;
}

vector<gameObject*> world::findObjects(string name)
{
	vector<gameObject*> result;
	for (int i = 0; i < MAX_LAYER; ++i)
	{
		unsigned int size = _objectList[i].size();
		for (unsigned int j = 0; j < size; ++j)
		{
			if (_objectList[i][j]->isLive())
			{
				if (_objectList[i][j]->_name == name)
				{
					result.push_back(_objectList[i][j]);
				}
			}
		}
	}
	return std::move(result);
}

vector<gameObject*> world::findObjects(string name, int priorityNum)
{
	if (name == "NONE")
	{
		return std::move(_objectList[priorityNum]);
	}

	vector<gameObject*> result;
	unsigned int size = _objectList[priorityNum].size();
	for (unsigned int i = 0; i < size; ++i)
	{
		if (_objectList[priorityNum][i]->isLive())
		{
			if (_objectList[priorityNum][i]->_name == name)
			{
				result.push_back(_objectList[priorityNum][i]);
			}
		}
	}
	return std::move(result);
}

void world::release()
{
	for (int i = 0; i < MAX_LAYER; ++i)
	{
		for (int j = (int)_objectList[i].size() - 1; j >= 0; --j)
		{
			_objectList[i][j]->release();
			SAFE_DELETE(_objectList[i][j]);
			_objectList[i].pop_back();
		}
	}

}