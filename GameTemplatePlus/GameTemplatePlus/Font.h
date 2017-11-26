#pragma once
#include "Vector2.h"
#include "Color.h"
#include <string>

// �t�H���g�^�C�v
enum FontType {
	normal,	// �ʏ�
	antialiasing,	// �A���`�G�C���A�X�i�W���j
	antialiasing_4x4,	// �A���`�G�C���A�X�i4x4�T���v�����O�j
	antialiasing_8x8,	// �A���`�G�C���A�X�i8x8�T���v�����O�j
};

class Font;

// �t�H���g�n���h��
class FontHandle {
public:
	int get_handle() const;
private:
	Font* font;
	friend class Font;
};

// �t�H���g�N���X
class Font {
public:

	// �t�H���g���W
	Vector2d pos;

	// �����F
	self_val(Color, color);

	// �G�b�W�F
	self_val(Color, edge_color);

	// �e�L�X�g�\��
	void print(std::string text, Vector2d add_pos = Vector2d(), Color color = Color::none(), Color edge_color = Color::none()) const;

	// �t�H���g�쐬
	static Font* create(std::string font_name, Vector2d pos = Vector2d(), int size = 16, int thick = 1, bool edge_flg = false, FontType font_type = FontType::antialiasing);

	// �t�H���g�n���h���쐬
	static FontHandle create_handle(std::string font_name, Vector2d pos = Vector2d(), int size = 16, int thick = 1, bool edge_flg = false, FontType font_type = FontType::antialiasing);

	// �t�H���g�n���h���ǂݍ��݊�����
	static bool already_loaded(FontHandle font_handle);

	// �n���h������t�H���g�쐬
	static Font* create_by_handle(FontHandle font_handle);

	// �t�H���g�폜
	static void clear(Font* &font);

	// �t�H���g�n���h��
	self_val(int, handle);

private:

	Font() {}
	Font(const Font&) {}
	~Font() {}
	Font& operator=(const Font&) {}

	// �t�H���g�쐬�i���[�h���ɃE�F�C�g���邩���w��j
	static Font* create(bool wait_flg, std::string font_name, Vector2d pos = Vector2d(), int size = 16, int thick = 1, bool edge_flg = false, FontType font_type = FontType::antialiasing);

};
