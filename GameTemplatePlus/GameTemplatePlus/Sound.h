#pragma once
#include "PropertyValue.h"
#include <string>
#include <map>

class Sound;

// �T�E���h�n���h��
class SoundHandle {
public:
	int get_handle() const;
private:
	Sound* sound;
	friend class Sound;
};

// �T�E���h�N���X
class Sound {
public:

	// ���[�v�̉ۂ�ݒ�
	void set_loop_flg(bool loop_flg);

	// ���[�v�ʒu��ݒ�mms�n
	void set_loop_pos(int loop_pos);

	// �Đ��i�P��[ms]�j�i�����ȗ��Ō��݂̍Đ��ʒu����ĊJ�j
	virtual void play(int play_pos = -1);

	// ��~�i�Đ��ʒu���ێ�����ꍇ��stay_flg��true�j
	void stop(bool stay_flg = false);

	// �Đ����ł��邩���ׂ�
	bool is_playing();

	// �Đ��ʒu���擾
	int get_play_pos();

	// �p���ݒ�i-10000�`10000�j
	void set_pan(int pan = 0);

	// ���ʐݒ�i0�`255�j
	void set_volume(int volume);

	// ����
	val_property_set(int, volume, public, set_volume);

	// �����ݒ�[��]�i100KHz�𒴂��鑬���i�T���v�����O���g��44100Hz����226���܂Łj�ɂ͂ł��Ȃ��j
	void set_speed(int speed = 100);

	// �Đ����g���ݒ�[Hz]
	void set_frequency(int frequency = -1);

	// BGM�쐬
	static Sound* create_bgm(std::string path, int loop_pos = 0) {
		return create(path, true, loop_pos, false);
	}

	// SE�쐬
	static Sound* create_se(std::string path) {
		return create(path, false, 0, true);
	}

	// BGM�n���h���쐬
	static SoundHandle create_bgm_handle(std::string path, int loop_pos = 0) {
		return create_handle(path, true, loop_pos, false);
	}

	// SE�n���h���쐬
	static SoundHandle create_se_handle(std::string path) {
		return create_handle(path, false, 0, true);
	}

	// �T�E���h�n���h���ǂݍ��݊�����
	static bool already_loaded(SoundHandle sound_handle);

	// �n���h������T�E���h�쐬
	static Sound* create_by_handle(SoundHandle sound_handle);

	// ���y�폜
	static void clear(Sound* sound);

	// �n���h��
	self_val(int, handle);

	// ���[�v�ʒu
	self_val_set(int, loop_pos, set_loop_pos);

	// ���[�v�t���O
	self_val_set(bool, loop_flg, set_loop_flg);

	// ���ʉ��t���O
	self_val(bool, se_flg);

	// �o�^����Ă���T�E���h�����ׂčĐ��i���ۂɂ͖{�֐��ɂ��T�E���h���Đ������j
	static void play_all_sound();

protected:

	// ���y�쐬
	static Sound* create(std::string path = "", bool loop_flg = false, int loop_pos = 0, bool se_flg = false);

	// �T�E���h�n���h���쐬
	static SoundHandle create_handle(std::string path = "", bool loop_flg = false, int loop_pos = 0, bool se_flg = false);

private:

	Sound() {}
	~Sound() {}
	Sound(const Sound&) {}
	Sound& operator=(const Sound&) {}

	// �Đ�����T�E���h�|�C���^�ƍĐ��ʒu�̑g
	static std::map<Sound*, int> play_sound_pos;

	// ���ۂ̍Đ��i�o�^����Ă����T�E���h�Ƃ��čĐ�����j
	void play_virtual(int play_pos);

	// ���y�쐬�i���[�h���ɃE�F�C�g���邩���w��j
	static Sound* create(bool wait_flg, std::string path = "", bool loop_flg = false, int loop_pos = 0, bool se_flg = false);

};
