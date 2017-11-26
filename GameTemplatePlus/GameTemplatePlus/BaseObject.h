#pragma once

// �W�����C�u����
#include <random>

// �C���N���[�h�w�b�_�[
#include "BaseManager.h"
#include "Vector2.h"
#include "Color.h"
#include "Shape.h"
#include "Motion.h"
#include "InfoData.h"
#include "ShareData.h"
#include "Font.h"
#include "GraphicCell.h"
#include "Graphic.h"
#include "Sound.h"
#include "KeyInput.h"

// BaseManager���Q�[������ɓ����������̂Ƃ��Ċg���������N���X
class BaseObject : public BaseManager {
public:

	BaseObject();
	virtual ~BaseObject();

	// �������i�o�ߎ��Ԃ�0�ɖ߂��j
	virtual void initialize();

	// �X�V
	virtual void update();

	// �`��
	virtual void draw();

protected:

	// �I�u�W�F�N�g�����J�n����̌o�ߎ��ԁi����update�̃^�C�~���O��1�ɂȂ�j
	int time;

	// �P�x�i���Œʏ�`��j
	Color color;

	// �L�[���͏��
	static KeyInput key_input;

	// �E�B���h�E���[�h�ύX�itrue: �E�B���h�E���[�h�@false: �t���X�N���[�����[�h�j
	void change_window_mode(bool mode);

	// �v�f�̑S�X�V
	template<class Class> static void all_update(std::vector<Class*> &e) {
		all_func(e, &Class::update);
	}

	// �v�f�̑S�`��
	template<class Class> static void all_draw(std::vector<Class*> &e) {
		all_func(e, &Class::draw);
	}

	// �ǂݍ��ݒ��t�H���g�n���h���o�^
	static void load(Font* &font, FontHandle font_handle);

	// �ǂݍ��ݒ��T�E���h�n���h���o�^
	static void load(Sound* &sound, SoundHandle sound_handle);

	// �ǂݍ��ݒ��Z����n���h���o�^
	static void load(GraphicCell* &cell, GraphicCellHandle cell_handle);

	// �ǂݍ��ݒ������Z����n���h���o�^
	static void load(std::vector<GraphicCell*> &cells, GraphicDivCellHandle cells_handle);

	// �ǂݍ��ݒ��n���h��������
	static void clear_handle();

	// �S�n���h���ǂݍ��݂�����������
	static bool all_handle_loaded();

	// �S�n���h���ǂݍ��݊�����A�e�����ݒ������������
	static void all_handle_init();

	// ����������
	static void default_rand();

	// �����l���w�肵�ė���������
	static void set_default_rand(int value);

	// �����l���w�肵�ė����������iset_default_rand�Ɠ��`�j
	static void default_rand(int value);

	// �����擾�i0�`value-1�j
	static int rand(int value);

	// �����擾�imin�`max�j
	static int rand(int min, int max);

	// ���������擾�imin�`max�j
	static double drand(double min, double max);

	// �����Z���k�c�C�X�^�̎擾
	static std::mt19937 get_mt();

	// ���L�f�[�^
	static ShareData share_data;

	// �E�B���h�E�̒��S���W���擾
	static Vector2d get_window_center();

	// �x�����W�A����
	static double deg2rad(double degree);

	// ���W�A����x��
	static double rad2deg(double radian);

	// startPos����goalPos�֌��������߂̊p�x�����߂�i���W�A���j
	static double adir(Vector2 startPos, Vector2 goalPos);

	// startPos����goalPos�֌��������߂̊p�x�����߂�i�x�j
	static double adir_deg(Vector2 startPos, Vector2 goalPos);

	// �E��������������i���l�ƁA�w�茅���A0�l�߂��邩�̃t���O���w��j
	static std::string right_number(long long int number, int limit, bool zeroFlg = false);

private:

	// �����Z���k�c�C�X�^
	static std::mt19937 mt;

	// �ǂݍ��ݒ��t�H���g�n���h��
	static std::vector<std::tuple<bool, Font**, FontHandle>> BaseObject::loading_font_handle;

	// �ǂݍ��ݒ��T�E���h�n���h��
	static std::vector<std::tuple<bool, Sound**, SoundHandle>> BaseObject::loading_sound_handle;

	// �ǂݍ��ݒ��Z����n���h��
	static std::vector<std::tuple<bool, GraphicCell**, GraphicCellHandle>> BaseObject::loading_graphic_cell_handle;

	// �ǂݍ��ݒ������Z����n���h��
	static std::vector<std::tuple<bool, std::vector<GraphicCell*>*, GraphicDivCellHandle>> BaseObject::loading_graphic_div_cell_handle;
};
