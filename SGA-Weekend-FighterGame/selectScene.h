#pragma once
#include "sceneBase.h"

namespace characterName
{
	enum Enum
	{
		 iori, terry, neco, mai, athena, sol, nanaya, mauru, END
	};
}

namespace selectSceneState
{
	enum Enum
	{
		SELECT, GO_NEXT
	};
}

class selectScene : public sceneBase
{
private:
	selectSceneState::Enum _state;

	image* _back;
	image* _title;

	image* _playerNumber[2];

	animation*	_selectedAnimation[characterName::END];
	RECT		_characterRC[characterName::END];

	int _selectNum;
	int _selectedCharacter[2];

public:
	selectScene() {}
	virtual ~selectScene() {}

	virtual HRESULT	init();
	virtual void	release();

	virtual void	resume();
	virtual void	update();
	virtual void	render();
};