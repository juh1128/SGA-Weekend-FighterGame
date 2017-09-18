#include "stdafx.h"
#include "playScene.h"
#include "selectScene.h"

#include "testCharacter.h"
#include "ioriYagami.h"
#include "mai.h"
#include "Nanaya.h"
#include "neko.h"
#include "solBadGuy.h"
#include "terry.h"
#include "athena.h"
#include "Mauru.h"
#include "kim.h"


character* getCharacter(int id, vector2D pos)
{
	character* newCharacter;
	switch (id)
	{
		case characterName::iori:
			newCharacter = new ioriYagami;
			((ioriYagami*)newCharacter)->init(pos);
		break;
		case characterName::mai:
			newCharacter = new mai;
			((mai*)newCharacter)->init(pos);
		break;
		case characterName::nanaya:
			newCharacter = new Nanaya;
			((Nanaya*)newCharacter)->init(pos);
		break;
		case characterName::terry:
			newCharacter = new terry;
			((terry*)newCharacter)->init(pos);
		break;
		case characterName::neco:
			newCharacter = new neko;
			((neko*)newCharacter)->init(pos);
		break;
		case characterName::sol:
			newCharacter = new testCharacter;
			((testCharacter*)newCharacter)->init(pos);
		break;
		case characterName::athena:
			newCharacter = new athena;
			((athena*)newCharacter)->init(pos);
		break;
		case characterName::mauru:
			newCharacter = new Mauru;
			((Mauru*)newCharacter)->init(pos);
		break;
		case characterName::kim:
			newCharacter = new kim;
			((kim*)newCharacter)->init(pos);
		break;
		default:
			newCharacter = new testCharacter;
			((testCharacter*)newCharacter)->init(pos);
		break;
	}
	return newCharacter;
}

void playScene::characterSetup()
{
	//캐릭터 생성
	_player[0] = getCharacter(_selectedCharacter[0], vector2D(200, 200));
	WORLD->addObject(_player[0], 1);
	_player[1] = getCharacter(_selectedCharacter[1], vector2D(WINSIZEX - 200, 200));
	WORLD->addObject(_player[1], 1);

	//========================================================================//

	//적 셋팅
	_player[0]->setupEnemy(_player[1]);
	_player[1]->setupEnemy(_player[0]);

	//1p 단축키 설정
	_player[0]->setupKey(key::LEFT, VK_LEFT);
	_player[0]->setupKey(key::RIGHT, VK_RIGHT);
	_player[0]->setupKey(key::JUMP, VK_UP);
	_player[0]->setupKey(key::DOWN, VK_DOWN);
	_player[0]->setupKey(key::ATTACK, 'A');
	_player[0]->setupKey(key::KICK, 'S');
	_player[0]->setupKey(key::STRONG_ATTACK, 'Q');
	_player[0]->setupKey(key::STRONG_KICK, 'W');

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