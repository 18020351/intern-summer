#include "classSound.h"
#include <thread>

classSound::classSound(std::string path) {
	m_path = path;
	m_song = SoundBuffer::get()->addSoundEffect(m_path.c_str());
}
void classSound::PlaySound() {
	//m_soundSource.Play(m_song);
	auto thread = std::thread(&classSound::Play, this);
	thread.detach();
}
void classSound::Play() {
	m_soundSource.Play(m_song);
}