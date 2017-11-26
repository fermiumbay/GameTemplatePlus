#pragma once
#include <string>
#include "Vector2.h"

// �Œ���f�[�^�i�Q�[�����ɕω����Ȃ����j
namespace InfoData {

	// �Q�[���^�C�g��
	std::string get_game_title();

	// �E�B���h�E�T�C�Y
	Vector2 get_window_size();

	// �E�B���h�E�̃J���[�r�b�g��
	int get_window_color_bit_num();

	// �����E�B���h�E���[�h�t���O
	bool get_window_mode();

};
