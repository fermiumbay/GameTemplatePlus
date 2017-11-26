#include "Color.h"

Color::Color(int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->none_flg = false;
}

inline void Color::regular_color() {
	if (this->_r < 0) this->_r = 0;
	if (this->_g < 0) this->_g = 0;
	if (this->_b < 0) this->_b = 0;
	if (this->_r > max_value) this->_r = max_value;
	if (this->_g > max_value) this->_g = max_value;
	if (this->_b > max_value) this->_b = max_value;
}

void Color::set_r(int r) {
	this->_r = r;
	this->regular_color();
}

void Color::set_g(int g) {
	this->_g = g;
	this->regular_color();
}

void Color::set_b(int b) {
	this->_b = b;
	this->regular_color();
}

bool Color::has_not_color() const {
	return none_flg;
}

const Color Color::none() {
	Color ret;
	ret.none_flg = true;
	return ret;
}

ColorHSV::ColorHSV(int h, int s, int v) {
	this->h = h;
	this->s = s;
	this->v = v;
	this->none_flg = false;
}

void ColorHSV::set_h(int h) {
	this->_h = (h + (max_h + 1)) % (max_h + 1);
}

void ColorHSV::set_s(int s) {
	if (s < 0) s = 0;
	if (s > max_s) s = max_s;
	this->_s = s;
}

void ColorHSV::set_v(int v) {
	if (v < 0) v = 0;
	if (v > max_v) s = max_v;
	this->_v = v;
}

bool ColorHSV::has_not_color() const {
	return none_flg;
}

const ColorHSV ColorHSV::none() {
	ColorHSV ret;
	ret.none_flg = true;
	return ret;
}

std::string Color::get_str() const {
	return "(" + std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b) + ")";
}

std::string ColorHSV::get_str() const {
	return "(" + std::to_string(h) + ", " + std::to_string(s) + ", " + std::to_string(v) + ")";
}

ColorHSV Color::to_hsv() const {
	int h, s, v;

	const int DivH = (ColorHSV::max_h + 1) / 6;
	int max, min;

	if (r >= g && r >= b) {
		max = r;
		min = (g <= b ? g : b);
		h = (int)(1.0 * DivH * (1.0 * (g - b) / (max - min)));
	}
	else if (g >= r && g >= b) {
		max = g;
		min = (r <= b ? r : b);
		h = (int)(1.0 * DivH * (1.0 * (b - r) / (max - min))) + 2 * DivH;
	}
	else if (b >= r && b >= g) {
		max = b;
		min = (r <= g ? r : g);
		h = (int)(1.0 * DivH * (1.0 * (r - g) / (max - min))) + 4 * DivH;
	}
	else {
		h = 0;
		max = min = r;
	}
	h = (h + (ColorHSV::max_h + 1)) % (ColorHSV::max_h + 1);

	s = (int)(1.0 * ColorHSV::max_s * (max - min) / max);
	v = (int)(1.0 * ColorHSV::max_v * max / max_value);

	return ColorHSV(h, s, v);
}

Color ColorHSV::to_rgb() const {
	int r, g, b;

	const int DivH = (ColorHSV::max_h + 1) / 6;

	int max = (int)(1.0 * Color::max_value * v / max_v);
	int min = (int)(1.0 * max - (1.0 * s / max_s * max));

	if (h < DivH) {
		r = max;
		g = (int)((1.0 * h / DivH) * (max - min) + min);
		b = min;
	}
	else if (h < 2 * DivH) {
		r = (int)((1.0 * (2 * DivH - h) / DivH) * (max - min) + min);
		g = max;
		b = min;
	}
	else if (h < 3 * DivH) {
		r = min;
		g = max;
		b = (int)((1.0 * (h - 2 * DivH) / DivH) * (max - min) + min);
	}
	else if (h < 4 * DivH) {
		r = min;
		g = (int)((1.0 * (4 * DivH - h) / DivH) * (max - min) + min);
		b = max;
	}
	else if (h < 5 * DivH) {
		r = (int)((1.0 * (h - 4 * DivH) / DivH) * (max - min) + min);
		g = min;
		b = max;
	}
	else {
		r = max;
		g = min;
		b = (int)((1.0 * (6 * DivH - h) / DivH) * (max - min) + min);
	}

	return Color(r, g, b);
}
