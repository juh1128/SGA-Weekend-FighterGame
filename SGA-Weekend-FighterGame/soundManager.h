#pragma once
#include "singletonBase.h"

#include <unordered_map>
#include <string>

//fmod.hpp �߰�
#include "inc/fmod.hpp"

//lib ��ũ
#pragma comment (lib, "lib/fmodex_vc.lib")

//�������� ä�� ���� ����(����)
#define EXTRA_SOUND_CHANNEL 5
#define SOUNDBUFFER 10

//�� ���� ����
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

	//���� �߰�
	void addSound(string keyName, string soundName, bool background = false, bool loop = false);


	//���
	void play(string keyName, float volume);
	void setVolume(string keyName, float volume);
	float getVolume(string keyName);

	//����
	void stop(string keyName);

	//����
	void pause(string keyName);

	//�ٽ� ���
	void resume(string keyName);

	//�����ִ�?
	bool isPauseSound(string keyName);

	//������̴�?
	bool isPlaySound(string keyName);

	//Fmod �ý����� ����
	void update(void);

	Channel* findChannel(string keyName);
	unsigned int getPosition(string keyName);
	unsigned int getLength(string keyName);
	void setPosition(string keyName, unsigned int time);

	bool isEndMusic(string keyName);

	soundManager();
	~soundManager();
};

