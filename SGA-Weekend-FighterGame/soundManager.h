#pragma once
#include "singletonBase.h"

#include <unordered_map>
#include <string>

//fmod.hpp 추가
#include "inc/fmod.hpp"

//lib 링크
#pragma comment (lib, "lib/fmodex_vc.lib")

//여유분의 채널 갯수 설정(버퍼)
#define EXTRA_SOUND_CHANNEL 5
#define SOUNDBUFFER 10

//총 사운드 갯수
#define TOTAL_SOUND_CHANNEL SOUNDBUFFER + EXTRA_SOUND_CHANNEL

using namespace FMOD;

class soundManager : public singletonBase <soundManager>
{
private:
	typedef unordered_map<string, Sound**> arrSounds;
	typedef unordered_map<string, Sound**>::iterator arrSoundsIter;
	typedef unordered_map<string, Channel**> arrChannels;
	typedef unordered_map<string, Channel**>::iterator arrChannelIter;

private:
	System* _system;
	Sound** _sound;

	Channel** _channel;

	arrSounds _mTotalSounds;

public:
	HRESULT init(void);
	void release(void);

	//사운드 추가
	void addSound(string keyName, string soundName, bool background = false, bool loop = false);


	//재생
	void play(string keyName, float volume);
	void setVolume(string keyName, float volume);
	float getVolume(string keyName);

	//종료
	void stop(string keyName);

	//정지
	void pause(string keyName);

	//다시 재생
	void resume(string keyName);

	//멈춰있니?
	bool isPauseSound(string keyName);

	//재생중이니?
	bool isPlaySound(string keyName);

	//Fmod 시스템을 갱신
	void update(void);

	Channel* findChannel(string keyName);
	unsigned int getPosition(string keyName);
	unsigned int getLength(string keyName);
	void setPosition(string keyName, unsigned int time);

	bool isEndMusic(string keyName);

	soundManager();
	~soundManager();
};

