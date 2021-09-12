#pragma once
#include <vector>

#include<../../vcpkg/installed/x86-windows/include/AL/alc.h>
#include <../../vcpkg/installed/x86-windows/include/AL/alext.h>
#include<../../vcpkg/installed/x86-windows/include/AL/al.h>

class SoundBuffer
{
public:
	static SoundBuffer* get();

	ALuint addSoundEffect(const char* filename);
	bool removeSoundEffect(const ALuint& buffer);

private:
	SoundBuffer();
	~SoundBuffer();

	std::vector<ALuint> p_SoundEffectBuffers;
};

