#pragma once

#include <iostream>
#include <string>

#include "soloud.h"
#include "soloud_wav.h"
#include "soloud_speech.h"

using namespace std;


class Audio
{
public:
	Audio();
	~Audio();

	void SetAudio(string);
	void PlayAudio();
	void StopAudio();
	void Announcer(string, int);

	SoLoud::Soloud soloud;
	SoLoud::Wav sample;
	SoLoud::Speech talk;
};
