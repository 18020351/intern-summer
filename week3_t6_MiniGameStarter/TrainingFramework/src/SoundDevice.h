#pragma once
#include<../../vcpkg/installed/x86-windows/include/AL/al.h>
#include "../../vcpkg/installed/x86-windows/include/AL/alc.h"
class SoundDevice
{
public:
	static SoundDevice* get();

private:
	SoundDevice();
	~SoundDevice();

	ALCdevice* p_ALCDevice;
	ALCcontext* p_ALCContext;

};

