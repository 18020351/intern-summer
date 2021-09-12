#include "ClassSound.h"
#include <thread>

ClassSound::ClassSound(std::string path) {
	m_path = path;
	m_song = SoundBuffer::get()->addSoundEffect(m_path.c_str());
}
void ClassSound::PlaySound() {
	auto thread = std::thread(&ClassSound::Play, this);
	thread.detach();
}
void ClassSound::Play() {
	m_soundSource.Play(m_song);
}
void ClassSound::PlayLoopSound() {
	auto thread = std::thread(&ClassSound::PlayLoop, this);
	thread.detach();
}
void ClassSound::PlayLoop() {
	m_soundSource.PlayLoop(m_song);
}
void ClassSound::Stop() {
	m_soundSource.Stop(m_song);
}