#pragma once
#include "Vector2.h"
#include "Color.h"
#include <string>
#include <vector>

// �Q�[�����삳����{�̂Ƃ̒[��
namespace GameDriver {

	// ========================================
	// �n���h���ǂݍ��݌n
	// ========================================

	// �n���h���ǂݍ��݂���������܂ŃE�F�C�g
	void wait_for_load(int handle);

	// �����n���h���ǂݍ��݂���������܂ŃE�F�C�g
	void wait_for_loads(std::vector<int> &handle);

	// �w��n���h�����ǂݍ��݊������ǂ���
	bool already_loaded(int handle);

	// ========================================
	// �Q�[���S�̂̎d�g��
	// ========================================

	// �Q�[���{�̂̏�����
	bool initialize(Vector2 window_size, std::string window_text, int window_mode, int window_color_bit_num);

	// �Q�[���̍X�V����
	bool update();

	// �Q�[���̏I������
	bool finalize();

	// �E�B���h�E���[�h�ύX�itrue: �E�B���h�E���[�h�@false: �t���X�N���[�����[�h�j
	void change_window_mode(bool mode);

	// ========================================
	// ������`��֌W
	// ========================================

	// ������`��֐�
	void draw_string(int handle, Vector2d pos, Vector2d add_pos, std::string text, Color color, Color edge_color);

	// �n���h���w�肵���t�H���g�f�[�^�̍폜
	void delete_font_to_handle(int handle);

	// �t�H���g�^�C�v�̎擾
	int get_fonttype(int id);

	// �t�H���g�̐V�K�쐬
	int create_new_font(std::string font_name, int size, int thick, int fontType);

	// ========================================
	// �摜�`��֌W
	// ========================================

	// �摜�ǂݍ���
	int load_graph(std::string path);

	// �����摜�ǂݍ���
	std::vector<int> load_div_graph(std::string path, Vector2 one_size, Vector2 div_num);

	// �n���h���w�肵���摜�f�[�^�̍폜
	void delete_graph(int handle);

	// �X�N���[������
	int make_screen(Vector2 size);

	// �n���h���w�肵���X�N���[���ɑ΂��A�`�撆��ʂ��R�s�[�i����������true�j
	bool get_draw_screen_graph(int handle, Vector2 first, Vector2 last);

	// �w�肵���n���h���ɕ`����ύX
	void set_draw_screen(int handle);

	// ����ʂɕ`����ύX
	void set_draw_screen_to_back();

	// �`����S�N���A
	void clear_draw_screen();

	// �`��Ώۂ̋P�x�擾
	Color get_draw_bright();

	// �`��Ώۂ̋P�x�ݒ�
	void set_draw_bright(Color c);

	// �`�惂�[�h�w��
	void set_draw_mode(int mode);

	// �u�����h���[�h�ƃu�����h�l�̐ݒ�
	void set_draw_blend_mode(int mode, int fade);

	// �摜�`��
	void draw_graph(int handle, Vector2d pos, bool trans);

	// ��]�摜�`��
	void draw_rota_graph(int handle, Vector2d pos, Vector2d center_pos, Vector2d zoom, double angle, bool trans, bool turn_flg);

	// �n���h���w�肵���摜�̃T�C�Y�擾
	Vector2 get_graph_size(int handle);

	// �_�`��
	void draw_pixel(Vector2 pos, Color color);

	// �_�̐F���擾
	Color get_pixel(Vector2 pos);

	// ���`��
	void draw_line(Vector2 first, Vector2 last, Color color);

	// ��`�`��
	void draw_rectangle(Vector2 first, Vector2 last, Color color, bool fill_flg);

	// �O�p�`�`��
	void draw_triangle(Vector2 p1, Vector2 p2, Vector2 p3, Color color, bool fill_flg);

	// �ȉ~�`��
	void draw_ellipse(Vector2 center, int radius_x, int radius_y, Color color, bool fill_flg);

	// ========================================
	// �L�[���͊֌W
	// ========================================

	// key_id�Ŏw�肵���L�[�{�[�h�̃L�[��������Ă��邩����
	bool check_hit_key(int key_id);

	// key_id�Ŏw�肵���}�E�X���͂�����Ă��邩����
	bool get_mouse_input(int key_id);

	// key_id�Ŏw�肵���Q�[���p�b�h�̃L�[��������Ă��邩����
	bool get_joypad_input_state(int key_id);

	// �}�E�X�̍��W���擾
	Vector2 get_mouse_pos();

	// ========================================
	// �T�E���h�֌W
	// ========================================

	// �T�E���h�f�ރ��[�h
	int load_sound(std::string path);

	// �T�E���h�Đ��i[ms]�P�ʁj
	void play_sound(int handle, bool loop_flg, bool top_pos_flg);

	// �T�E���h��~
	void stop_sound(int handle);

	// �T�E���h�j��
	void delete_sound(int handle);

	// �T�E���h�Đ��ʒu���擾
	int get_sound_current_time(int handle);

	// �T�E���h�Đ��ʒu���w��
	void set_sound_current_time(int handle, int time);

	// �T�E���h���[�v�ʒu���w��
	void set_sound_loop_pos(int handle, int loop_pos);

	// �Y���T�E���h���Đ���
	bool is_playing_sound(int handle);

	// �T�E���h�p���w��
	void set_sound_pan(int handle, int pan);

	// �T�E���h���ʎw��
	void set_sound_volume(int handle, int volume);

	// �T�E���h�Đ��X�s�[�h�w��
	void set_sound_speed(int handle, int speed);

	// �T�E���h���g���w��
	void set_sound_frequency(int handle, int frequency);

}
