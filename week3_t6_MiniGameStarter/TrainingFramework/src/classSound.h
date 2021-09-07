#pragma once
#include"SoundBuffer.h"
#include"SoundDevice.h"
#include"SoundSource.h"
#include<iostream>
class classSound
{
private:
	SoundDevice* m_soundDevice = SoundDevice::get();
	SoundSource m_soundSource;
	uint32_t m_song;
	std::string m_path = "";
public:
	classSound(std::string path);
	void PlaySound();
	void Play();
};

