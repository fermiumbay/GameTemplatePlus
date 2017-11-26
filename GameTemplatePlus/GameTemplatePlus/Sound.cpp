#include "Sound.h"
#include "GameDriver.h"

using namespace std;

map<Sound*, int> Sound::play_sound_pos;

void Sound::set_loop_flg(bool loop_flg) {
	this->_loop_flg = loop_flg;
	if (this->_loop_flg) {
		GameDriver::set_sound_loop_pos(this->handle, this->loop_pos);
	}
}

// ループ位置を設定［ms］
void Sound::set_loop_pos(int loop_pos) {
	this->_loop_pos = loop_pos;
	if (this->_loop_flg) {
		GameDriver::set_sound_loop_pos(this->handle, this->loop_pos);
	}
}

void Sound::play(int play_pos) {
	// この段階では再生サウンドとして登録するだけ 最後にplay_all_soundを実行して再生する
	play_sound_pos[this] = play_pos;
}

void Sound::stop(bool stay_flg) {
	GameDriver::stop_sound(handle);
	if (!stay_flg) {
		GameDriver::set_sound_current_time(handle, 0);
	}
}

bool Sound::is_playing() {
	return GameDriver::is_playing_sound(handle);
}

int Sound::get_play_pos() {
	return GameDriver::get_sound_current_time(handle);
}

void Sound::set_pan(int pan) {
	GameDriver::set_sound_pan(handle, pan);
}

void Sound::set_speed(int speed) {
	GameDriver::set_sound_speed(handle, speed);
}

void Sound::set_frequency(int frequency) {
	GameDriver::set_sound_frequency(handle, frequency);
}

void Sound::clear(Sound* sound) {
	if (sound != nullptr) {
		GameDriver::delete_sound(sound->handle);
		delete sound;
		sound = nullptr;
	}
}

Sound* Sound::create(string path, bool loop_flg, int loop_pos, bool se_flg) {
	return create(true, path, loop_flg, loop_pos, se_flg);
}

Sound* Sound::create(bool wait_flg, string path, bool loop_flg, int loop_pos, bool se_flg) {
	Sound* ret = new Sound;
	ret->handle = GameDriver::load_sound(path);
	ret->se_flg = se_flg;

	if (wait_flg) {
		GameDriver::wait_for_load(ret->handle);
		ret->loop_flg = loop_flg;
		ret->set_loop_pos(loop_pos);
		ret->volume = 255;
		GameDriver::set_sound_current_time(ret->handle, 0);
	}
	else {
		ret->_loop_flg = loop_flg;
		ret->_loop_pos = loop_pos;
		ret->_volume = 255;
	}
	return ret;
}

SoundHandle Sound::create_handle(string path, bool loop_flg, int loop_pos, bool se_flg) {
	SoundHandle ret;
	ret.sound = create(false, path, loop_flg, loop_pos, se_flg);
	return ret;
}

bool Sound::already_loaded(SoundHandle sound_handle) {
	return GameDriver::already_loaded(sound_handle.sound->handle);
}

Sound* Sound::create_by_handle(SoundHandle sound_handle) {
	if (sound_handle.sound->_loop_flg) {
		GameDriver::set_sound_loop_pos(sound_handle.sound->handle, sound_handle.sound->loop_pos);
	}
	GameDriver::set_sound_volume(sound_handle.sound->handle, sound_handle.sound->volume);
	GameDriver::set_sound_current_time(sound_handle.sound->handle, 0);
	return sound_handle.sound;
}

void Sound::set_volume(int volume) {
	this->_volume = volume;
	GameDriver::set_sound_volume(handle, volume);
}

void Sound::play_virtual(int play_pos) {
	if (play_pos != -1) {
		// 再生位置を指定して再生
		GameDriver::set_sound_current_time(handle, play_pos);
	}
	else if (se_flg) {
		play_pos = 0;
	}

	// ループしないサウンドは再生位置を0に指定した場合のみ再生位置が戻るようにする
	GameDriver::play_sound(handle, loop_flg, !loop_flg && play_pos == 0);
}

void Sound::play_all_sound() {
	for (auto p : play_sound_pos) {
		p.first->play_virtual(p.second);
	}
	play_sound_pos.clear();
}

int SoundHandle::get_handle() const {
	return sound->handle;
}
