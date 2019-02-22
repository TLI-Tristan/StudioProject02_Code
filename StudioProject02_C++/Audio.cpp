#include "Audio.h"



Audio::Audio()
{
}


Audio::~Audio()
{
}

void Audio::SetAudio(string name)
{
	const char * c = name.c_str();
	// music for one (init)
	unsigned int res2 = soloud.init();
	unsigned int smpl = sample.load(c);
}

void Audio::PlayAudio()
{
	soloud.playBackground(sample);
}

void Audio::StopAudio()
{

}

void Audio::Announcer(string speech, int volume) {
	const char * c = speech.c_str();
	talk.setText(c);
	soloud.init(SoLoud::Soloud::CLIP_ROUNDOFF | SoLoud::Soloud::ENABLE_VISUALIZATION);
	soloud.setGlobalVolume(volume);
	soloud.play(talk);
}
