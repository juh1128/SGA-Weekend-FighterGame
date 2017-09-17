#include "stdafx.h"
#include "playScene.h"
#include "testCharacter.h"



void playScene::characterSetup()
{
	//캐릭터 생성
	_player[0] = new testCharacter;
	_player[1] = new testCharacter;
	//적 셋팅
	_player[0]->setupEnemy(_player[1]);
	_player[1]->setupEnemy(_player[0]);

	//========================================================================//

	//1p 캐릭터 초기화
	((testCharacter*)_player[0])->init(vector2D(200, 200));
	WORLD->addObject(_player[0], 1);

	//1p 단축키 설정
	_player[0]->setupKey(key::LEFT, VK_LEFT);
	_player[0]->setupKey(key::RIGHT, VK_RIGHT);
	_player[0]->setupKey(key::JUMP, VK_UP);
	_player[0]->setupKey(key::DOWN, VK_DOWN);
	_player[0]->setupKey(key::ATTACK, 'A');
	_player[0]->setupKey(key::KICK, 'S');
	_player[0]->setupKey(key::STRONG_ATTACK, 'Q');
	_player[0]->setupKey(key::STRONG_KICK, 'W');

	//========================================================================//

	//2p 캐릭터 초기화
	((testCharacter*)_player[1])->init(vector2D(WINSIZEX-200, 200));
	WORLD->addObject(_player[1], 1);

	//2p 단축키 설정
	_player[1]->setupKey(key::LEFT, VK_NUMPAD4);
	_player[1]->setupKey(key::RIGHT, VK_NUMPAD6);
	_player[1]->setupKey(key::JUMP, VK_NUMPAD8);
	_player[1]->setupKey(key::DOWN, VK_NUMPAD5);
	_player[1]->setupKey(key::ATTACK, 'K');
	_player[1]->setupKey(key::KICK, 'L');
	_player[1]->setupKey(key::STRONG_ATTACK, 'I');
	_player[1]->setupKey(key::STRONG_KICK, 'O');

	//========================================================================//
}