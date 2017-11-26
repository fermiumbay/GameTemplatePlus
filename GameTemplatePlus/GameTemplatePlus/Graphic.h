#pragma once
#include "GraphicCell.h"
#include "Vector2.h"
#include "Color.h"
#include <string>

// �u�����h���[�h
enum BlendMode {
	alpha_blend = 1,	// �A���t�@�u�����h
	add_blend = 2,	// ���Z�u�����h
};

// �摜�`��N���X
class Graphic {
public:

	// �Z������g���ĒP�̉摜�쐬�i�P�̃C���X�^���X�j
	static Graphic* create(GraphicCell *cell, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// �Z������g���ĕ����摜�쐬�i�P�̃C���X�^���X�j
	static Graphic* create(std::vector<GraphicCell*> cells, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// �摜�t�@�C����ǂݍ���ŒP�̉摜�쐬�i�P�̃C���X�^���X�j
	static Graphic* create(std::string path, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// �摜�t�@�C����ǂݍ���ŕ����摜�쐬�i�P�̃C���X�^���X�j
	static Graphic* create(std::string path, Vector2 one_size, Vector2 pattern_num, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// �Z������g���ĒP�̉摜�쐬�i�����C���X�^���X�j
	static std::vector<Graphic*> create_div(std::vector<GraphicCell*> cells, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// �Z������g���ĕ����摜�쐬�i�����C���X�^���X�j
	static std::vector<Graphic*> create_div(std::vector<GraphicCell*> cells, Vector2 div_num, Vector2 pattern_num, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// �摜�t�@�C����ǂݍ���ŒP�̉摜�쐬�i�����C���X�^���X�j
	static std::vector<Graphic*> create_div(std::string path, Vector2 one_size, Vector2 div_num, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// �摜�t�@�C����ǂݍ���ŕ����摜�쐬�i�����C���X�^���X�j
	static std::vector<Graphic*> create_div(std::string path, Vector2 one_size, Vector2 div_num, Vector2 pattern_num, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// �P�̃C���X�^���X�̍폜
	static void clear(Graphic* graphic);

	// �����C���X�^���X�̈ꊇ�폜
	static void clear(std::vector<Graphic*> &graphics);

	// �`��
	void draw(int id, Vector2d add_pos) const;
	void draw() const { draw(show_id, Vector2d()); }
	void draw(int id) const { draw(id, Vector2d()); }
	void draw(Vector2d add_pos) const { draw(show_id, add_pos); }

	// �\�����W
	Vector2d pos;

	// �s�����x�i0�`256�j
	int fade;

	// ��]�p�x�i�����v���j[rad]
	double angle;

	// �����F����
	bool trans;

	// ���E���]����
	bool turn_flg;

	// �u�����h���[�h
	BlendMode blend_mode;

	// �o�C���j�A�`��t���O
	bool bilinear_flg;

	// �`��O���t�B�b�NID
	int show_id;

	// �g�嗦[��]�i���Əc�j
	val_property(Vector2d, zoom, public, public);

	// �g�嗦[��]��ݒ�
	void set_zoom(double zoom = 100.0);

	// �F��
	val_property(Color, color, public, public);

	// �F�������ɖ߂��i���j
	void set_default_color();

	// ���S���W�t���O
	self_val(bool, center_pos_flg);

private:

	// �ێ����Ă���Z����iGraphic�������Ɍ��܂�A���̌ア���邱�Ƃ͏o���Ȃ� ������ꍇ��GraphicCell�{�̂������邱�Ɓj
	std::vector<GraphicCell*> cells;

	// Graphic���g��GraphicCell���쐬�������߁AGraphic�폜���ɕێ����Ă���GraphicCell���폜����t���O
	bool self_delete_cells_flg;

	// Graphic�̊e�p�����[�^�����l���
	void set_values(Vector2d pos, int fade, Vector2d zoom, double angle, bool center_pos_flg, bool trans, BlendMode blend_mode, bool bilinear_flg);

	Graphic() {}
	Graphic(const Graphic&) {}
	~Graphic() {}
	Graphic& operator=(const Graphic&) {}

};
