#include "Graphic.h"
#include "GameDriver.h"

using namespace std;

Graphic* Graphic::create(GraphicCell *cell, Vector2d pos, bool center_pos_flg, bool trans, int fade, Vector2d zoom, double angle, BlendMode blend_mode, bool bilinear_flg) {
	Graphic *ret = new Graphic;
	ret->cells.clear();
	ret->cells.push_back(cell);
	ret->self_delete_cells_flg = false;
	ret->set_values(pos, fade, zoom, angle, center_pos_flg, trans, blend_mode, bilinear_flg);
	return ret;
}

Graphic* Graphic::create(vector<GraphicCell*> cells, Vector2d pos, bool center_pos_flg, bool trans, int fade, Vector2d zoom, double angle, BlendMode blend_mode, bool bilinear_flg) {
	Graphic *ret = new Graphic;
	ret->cells.clear();
	for (auto p : cells) {
		ret->cells.push_back(p);
	}
	ret->self_delete_cells_flg = false;
	ret->set_values(pos, fade, zoom, angle, center_pos_flg, trans, blend_mode, bilinear_flg);
	return ret;
}

Graphic* Graphic::create(string path, Vector2d pos, bool center_pos_flg, bool trans, int fade, Vector2d zoom, double angle, BlendMode blend_mode, bool bilinear_flg) {
	GraphicCell* cell = GraphicCell::create(path);
	Graphic *ret = new Graphic;
	ret->cells.clear();
	ret->cells.push_back(cell);
	ret->self_delete_cells_flg = true;
	ret->set_values(pos, fade, zoom, angle, center_pos_flg, trans, blend_mode, bilinear_flg);
	return ret;
}

Graphic* Graphic::create(string path, Vector2 one_size, Vector2 pattern_num, Vector2d pos, bool center_pos_flg, bool trans, int fade, Vector2d zoom, double angle, BlendMode blend_mode, bool bilinear_flg) {
	vector<GraphicCell*> cells = GraphicCell::create(path, one_size, pattern_num);
	Graphic *ret = new Graphic;
	ret->cells.clear();
	for (auto p : cells) {
		ret->cells.push_back(p);
	}
	ret->self_delete_cells_flg = true;
	ret->set_values(pos, fade, zoom, angle, center_pos_flg, trans, blend_mode, bilinear_flg);
	return ret;
}

vector<Graphic*> Graphic::create_div(vector<GraphicCell*> cells, Vector2d pos, bool center_pos_flg, bool trans, int fade, Vector2d zoom, double angle, BlendMode blend_mode, bool bilinear_flg) {
	vector<Graphic*> ret;
	for (auto p : cells) {
		Graphic *graphic = new Graphic;
		graphic->cells.clear();
		graphic->cells.push_back(p);
		graphic->self_delete_cells_flg = false;
		graphic->set_values(pos, fade, zoom, angle, center_pos_flg, trans, blend_mode, bilinear_flg);
		ret.push_back(graphic);
	}
	return ret;
}

vector<Graphic*> Graphic::create_div(vector<GraphicCell*> cells, Vector2 div_num, Vector2 pattern_num, Vector2d pos, bool center_pos_flg, bool trans, int fade, Vector2d zoom, double angle, BlendMode blend_mode, bool bilinear_flg) {
	vector<Graphic*> ret;
	for (int j = 0; j < div_num.y; j++) {
		for (int i = 0; i < div_num.x; i++) {
			Graphic *graphic = new Graphic;
			graphic->cells.clear();
			for (int y = 0; y < pattern_num.y; y++) {
				for (int x = 0; x < pattern_num.x; x++) {
					int id = x + pattern_num.x * (i + div_num.x * (y + j * pattern_num.y));
					graphic->cells.push_back(cells[id]);
				}
			}
			graphic->self_delete_cells_flg = false;
			graphic->set_values(pos, fade, zoom, angle, center_pos_flg, trans, blend_mode, bilinear_flg);
			ret.push_back(graphic);
		}
	}
	return ret;
}

vector<Graphic*> Graphic::create_div(string path, Vector2 one_size, Vector2 div_num, Vector2d pos, bool center_pos_flg, bool trans, int fade, Vector2d zoom, double angle, BlendMode blend_mode, bool bilinear_flg) {
	vector<GraphicCell*> cells = GraphicCell::create(path, one_size, div_num);
	vector<Graphic*> ret;
	for (auto p : cells) {
		Graphic *graphic = new Graphic;
		graphic->cells.clear();
		graphic->cells.push_back(p);
		graphic->self_delete_cells_flg = true;
		graphic->set_values(pos, fade, zoom, angle, center_pos_flg, trans, blend_mode, bilinear_flg);
		ret.push_back(graphic);
	}
	return ret;
}

vector<Graphic*> Graphic::create_div(string path, Vector2 one_size, Vector2 div_num, Vector2 pattern_num, Vector2d pos, bool center_pos_flg, bool trans, int fade, Vector2d zoom, double angle, BlendMode blend_mode, bool bilinear_flg) {
	vector<GraphicCell*> cells = GraphicCell::create(path, one_size, Vector2(div_num.x * pattern_num.x, div_num.y * pattern_num.y));
	vector<Graphic*> ret;
	for (int j = 0; j < div_num.y; j++) {
		for (int i = 0; i < div_num.x; i++) {
			Graphic *graphic = new Graphic;
			graphic->cells.clear();
			for (int y = 0; y < pattern_num.y; y++) {
				for (int x = 0; x < pattern_num.x; x++) {
					int id = x + pattern_num.x * (i + div_num.x * (y + j * pattern_num.y));
					graphic->cells.push_back(cells[id]);
				}
			}
			graphic->self_delete_cells_flg = true;
			graphic->set_values(pos, fade, zoom, angle, center_pos_flg, trans, blend_mode, bilinear_flg);
			ret.push_back(graphic);
		}
	}
	return ret;
}

void Graphic::set_values(Vector2d pos, int fade, Vector2d zoom, double angle, bool center_pos_flg, bool trans, BlendMode blend_mode, bool bilinear_flg) {
	this->pos = pos;
	this->fade = fade;
	this->zoom = zoom;
	this->angle = angle;
	this->center_pos_flg = center_pos_flg;
	this->trans = trans;
	this->set_default_color();
	this->turn_flg = false;
	this->blend_mode = blend_mode;
	this->bilinear_flg = bilinear_flg;
	this->show_id = 0;
}

void Graphic::clear(Graphic* graphic) {
	if (graphic != nullptr) {
		if (graphic->self_delete_cells_flg) {
			for (auto p : graphic->cells) {
				GraphicCell::clear(p);
			}
		}
		delete graphic;
		graphic = nullptr;
	}
}

void Graphic::clear(std::vector<Graphic*> &graphics) {
	for (auto p : graphics) {
		clear(p);
	}
	graphics.clear();
}

void Graphic::draw(int id, Vector2d add_pos) const {
	Color color_tmp = GameDriver::get_draw_bright();
	GameDriver::set_draw_bright(Color((color_tmp.r * color.r) / 255, (color_tmp.g * color.g) / 255, (color_tmp.b * color.b) / 255));
	GameDriver::set_draw_mode(bilinear_flg ? 0 : 1);
	GameDriver::set_draw_blend_mode(blend_mode, fade);

	// ¶ãÀ•W‚©‚ç‚Ì’†SÀ•W
	Vector2d center_pos = cells[0]->size.to_double() / 2;

	// Ý’è‚É‰ž‚¶‚Ä•`‰æŠÖ”‚ð•Ï‚¦A•`‰æ‚·‚é
	if (zoom == Vector2d(100, 100) && angle == 0 && !turn_flg) {
		if (center_pos_flg) {
			GameDriver::draw_graph(cells[id]->handle, pos + add_pos - center_pos, trans);
		}
		else {
			GameDriver::draw_graph(cells[id]->handle, pos + add_pos, trans);
		}
	}
	else {
		Vector2d draw_pos = Vector2d(pos + add_pos);
		if (!center_pos_flg) {
			Vector2d z = Vector2d(zoom.x * center_pos.x, zoom.y * center_pos.y) / 100;
			draw_pos.x += z.y * sin(angle) + z.x * cos(angle);
			draw_pos.y += z.y * cos(angle) - z.x * sin(angle);
		}
		GameDriver::draw_rota_graph(cells[id]->handle, draw_pos, center_pos, zoom, angle, trans, turn_flg);
	}

	GameDriver::set_draw_mode(1);
	GameDriver::set_draw_blend_mode(0, 0);
	GameDriver::set_draw_bright(color_tmp);
}

void Graphic::set_zoom(double zoom) {
	this->zoom = Vector2d(zoom, zoom);
}

void Graphic::set_default_color() {
	set_color(Color::white());
}
