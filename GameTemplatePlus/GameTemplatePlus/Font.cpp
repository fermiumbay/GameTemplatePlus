#include "Font.h"
using namespace std;

#include "GameDriver.h"

Font* Font::create(bool wait_flg, string font_name, Vector2d pos, int size, int thick, bool edge_flg, FontType type) {
	Font* ret = new Font;
	int fonttype;

	switch (type) {
	case FontType::normal:
		if (!edge_flg) {
			fonttype = GameDriver::get_fonttype(0);
		}
		else {
			fonttype = GameDriver::get_fonttype(1);
		}
		break;
	case FontType::antialiasing:
		if (!edge_flg) {
			fonttype = GameDriver::get_fonttype(2);
		}
		else {
			fonttype = GameDriver::get_fonttype(3);
		}
		break;
	case FontType::antialiasing_4x4:
		if (!edge_flg) {
			fonttype = GameDriver::get_fonttype(4);
		}
		else {
			fonttype = GameDriver::get_fonttype(5);
		}
		break;
	case FontType::antialiasing_8x8:
		if (!edge_flg) {
			fonttype = GameDriver::get_fonttype(6);
		}
		else {
			fonttype = GameDriver::get_fonttype(7);
		}
		break;
	}
	ret->handle = GameDriver::create_new_font(font_name, size, thick, fonttype);
	ret->pos = pos;
	ret->color = Color::white();
	ret->edge_color = Color::black();
	if (wait_flg) {
		GameDriver::wait_for_load(ret->handle);
	}
	return ret;
}

Font* Font::create(string font_name, Vector2d pos, int size, int thick, bool edge_flg, FontType type) {
	return create(true, font_name, pos, size, thick, edge_flg, type);
}

FontHandle Font::create_handle(string font_name, Vector2d pos, int size, int thick, bool edge_flg, FontType type) {
	FontHandle ret;
	ret.font = create(false, font_name, pos, size, thick, edge_flg, type);
	return ret;
}

bool Font::already_loaded(FontHandle font_handle) {
	return GameDriver::already_loaded(font_handle.font->handle);
}

Font* Font::create_by_handle(FontHandle font_handle) {
	return font_handle.font;
}

void Font::clear(Font* &font) {
	if (font != nullptr) {
		GameDriver::delete_font_to_handle(font->handle);
		delete font;
		font = nullptr;
	}
}

void Font::print(string text, Vector2d add_pos, Color color, Color edge_color) const {
	if (color.has_not_color()) {
		color = this->color;
	}
	if (edge_color.has_not_color()) {
		edge_color = this->edge_color;
	}
	GameDriver::draw_string(handle, pos, add_pos, text, color, edge_color);
}

int FontHandle::get_handle() const {
	return font->handle;
}
