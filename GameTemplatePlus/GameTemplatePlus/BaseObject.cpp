#include "BaseObject.h"

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

mt19937 BaseObject::mt;
vector<tuple<bool, Font**, FontHandle>> BaseObject::loading_font_handle;
vector<tuple<bool, Sound**, SoundHandle>> BaseObject::loading_sound_handle;
vector<tuple<bool, GraphicCell**, GraphicCellHandle>> BaseObject::loading_graphic_cell_handle;
vector<tuple<bool, vector<GraphicCell*>*, GraphicDivCellHandle>> BaseObject::loading_graphic_div_cell_handle;

ShareData BaseObject::share_data;
KeyInput BaseObject::key_input;

#include <vector>
#include <map>

#include "GameDriver.h"

BaseObject::BaseObject() : BaseManager() {
	initialize();
}

BaseObject::~BaseObject() {
}

void BaseObject::update() {
	time++;

	for (auto &p : loading_font_handle) {
		if (Font::already_loaded(get<2>(p))) {
			get<0>(p) = true;
		}
	}
	for (auto &p : loading_sound_handle) {
		if (Sound::already_loaded(get<2>(p))) {
			get<0>(p) = true;
		}
	}
	for (auto &p : loading_graphic_cell_handle) {
		if (GraphicCell::already_loaded(get<2>(p))) {
			get<0>(p) = true;
		}
	}
	for (auto &p : loading_graphic_div_cell_handle) {
		if (GraphicCell::already_loaded(get<2>(p))) {
			get<0>(p) = true;
		}
	}
}

void BaseObject::draw() {
	GameDriver::set_draw_bright(color);
}

void BaseObject::initialize() {
	time = 0;
	color = Color::white();
}

void BaseObject::change_window_mode(bool mode) {
	GameDriver::change_window_mode(mode);
}

void BaseObject::load(Font* &font, FontHandle font_handle) {
	tuple<bool, Font**, FontHandle> t;
	get<0>(t) = false;
	get<1>(t) = &font;
	get<2>(t) = font_handle;
	loading_font_handle.push_back(t);
}

void BaseObject::load(Sound* &sound, SoundHandle sound_handle) {
	tuple<bool, Sound**, SoundHandle> t;
	get<0>(t) = false;
	get<1>(t) = &sound;
	get<2>(t) = sound_handle;
	loading_sound_handle.push_back(t);
}

void BaseObject::load(GraphicCell* &cell, GraphicCellHandle cell_handle) {
	tuple<bool, GraphicCell**, GraphicCellHandle> t;
	get<0>(t) = false;
	get<1>(t) = &cell;
	get<2>(t) = cell_handle;
	loading_graphic_cell_handle.push_back(t);
}

void BaseObject::load(vector<GraphicCell*> &cells, GraphicDivCellHandle cells_handle) {
	tuple<bool, vector<GraphicCell*>*, GraphicDivCellHandle> t;
	get<0>(t) = false;
	get<1>(t) = &cells;
	get<2>(t) = cells_handle;
	loading_graphic_div_cell_handle.push_back(t);
}

void BaseObject::clear_handle() {
	loading_font_handle.clear();
	loading_sound_handle.clear();
	loading_graphic_cell_handle.clear();
	loading_graphic_div_cell_handle.clear();
}

bool BaseObject::all_handle_loaded() {
	for (auto p : loading_font_handle) {
		if (!get<0>(p)) {
			return false;
		}
	}
	for (auto p : loading_sound_handle) {
		if (!get<0>(p)) {
			return false;
		}
	}
	for (auto p : loading_graphic_cell_handle) {
		if (!get<0>(p)) {
			return false;
		}
	}
	for (auto p : loading_graphic_div_cell_handle) {
		if (!get<0>(p)) {
			return false;
		}
	}
	return true;
}

void BaseObject::all_handle_init() {
	for (auto p : loading_font_handle) {
		*get<1>(p) = Font::create_by_handle(get<2>(p));
	}
	for (auto p : loading_sound_handle) {
		*get<1>(p) = Sound::create_by_handle(get<2>(p));
	}
	for (auto p : loading_graphic_cell_handle) {
		*get<1>(p) = GraphicCell::create_by_handle(get<2>(p));
	}
	for (auto p : loading_graphic_div_cell_handle) {
		*get<1>(p) = GraphicCell::create_by_handle(get<2>(p));
	}
}

void BaseObject::default_rand() {
	std::random_device rd;
	mt.seed(rd());
}

void BaseObject::set_default_rand(int value) {
	mt.seed(value);
}

void BaseObject::default_rand(int value) {
	set_default_rand(value);
}

int BaseObject::rand(int value) {
	return uniform_int_distribution<int>(0, value - 1)(mt);
}

int BaseObject::rand(int min, int max) {
	return uniform_int_distribution<int>(min, max)(mt);
}

double BaseObject::drand(double min, double max) {
	return uniform_real_distribution<double>(min, max)(mt);
}

mt19937 BaseObject::get_mt() {
	return mt;
}

Vector2d BaseObject::get_window_center() {
	return InfoData::get_window_size().to_double() / 2;
}

double BaseObject::deg2rad(double degree) {
	return degree * M_PI / 180.0;
}

double BaseObject::rad2deg(double radian) {
	return radian * 180.0 / M_PI;
}

double BaseObject::adir(Vector2 startPos, Vector2 goalPos) {
	return atan2(
		static_cast<double>(startPos.y - goalPos.y),
		static_cast<double>(goalPos.x - startPos.x)
	);
}

double BaseObject::adir_deg(Vector2 startPos, Vector2 goalPos) {
	return rad2deg(adir(startPos, goalPos));
}

string BaseObject::right_number(long long int number, int limit, bool zeroFlg) {
	string ret = "";
	string numstr = to_string(number);
	for (int i = 0; i < limit - (int)numstr.size(); i++) {
		ret += (zeroFlg ? "0" : " ");
	}
	return ret + numstr;
}
