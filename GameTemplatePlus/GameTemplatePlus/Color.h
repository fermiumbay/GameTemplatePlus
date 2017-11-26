#pragma once
#include "PropertyValue.h"

#include <string>

class Color;
class ColorHSV;

// �F
class Color {
public:

	// �e�P�x�̌��E�l
	static const int max_value = 255;

	// �F
	Color(int r = 0, int g = 0, int b = 0);

	// HSV�F�ɕϊ�
	ColorHSV to_hsv() const;

	// RGB�l�̕�������擾
	std::string get_str() const;

	// �Ԃ̋P�x
	val_property_set(int, r, public, set_r);

	// �΂̋P�x
	val_property_set(int, g, public, set_g);

	// �̋P�x
	val_property_set(int, b, public, set_b);

	// �Ԃ̋P�x���Z�b�g
	void set_r(int r);

	// �΂̋P�x���Z�b�g
	void set_g(int g);

	// �̋P�x���Z�b�g
	void set_b(int b);

	// �F�������ĂȂ�
	bool has_not_color() const;

	// ��
	static const Color red() { return Color(max_value, 0, 0); }

	// ��
	static const Color green() { return Color(0, max_value, 0); }

	// ��
	static const Color blue() { return Color(0, 0, max_value); }

	// ���F
	static const Color yellow() { return Color(max_value, max_value, 0); }

	// ���邢��
	static const Color purple() { return Color(max_value, 0, max_value); }

	// ���F
	static const Color cyan() { return Color(0, max_value, max_value); }

	// ��
	static const Color white() { return Color(max_value, max_value, max_value); }

	// �D�F
	static const Color gray() { return Color((max_value + 1) / 2, (max_value + 1) / 2, (max_value + 1) / 2); }

	// ��
	static const Color black() { return Color(0, 0, 0); }

	// �F�Ȃ��i�����ȗ��Ȃǁj
	static const Color none();

	Color& operator+=(const Color& v) {
		r += v.r;
		g += v.g;
		b += v.b;
		regular_color();
		return *this;
	}

	Color& operator-=(const Color& v) {
		r -= v.r;
		g -= v.g;
		b -= v.b;
		regular_color();
		return *this;
	}

	Color& operator+=(int a) {
		r += a;
		g += a;
		b += a;
		regular_color();
		return *this;
	}

	Color& operator-=(int a) {
		r -= a;
		g -= a;
		b -= a;
		regular_color();
		return *this;
	}

	Color& operator*=(double a) {
		r = (int)(a * r);
		g = (int)(a * g);
		b = (int)(a * b);
		regular_color();
		return *this;
	}

	Color& operator/=(double a) {
		r = (int)(1.0 * r / a);
		g = (int)(1.0 * g / a);
		b = (int)(1.0 * b / a);
		regular_color();
		return *this;
	}

	friend bool operator==(const Color& v1, const Color& v2) {
		return v1.r == v2.r && v1.g == v2.g && v1.b == v2.b;
	}

	friend bool operator!=(const Color& v1, const Color& v2) {
		return !(v1 == v2);
	}

	friend Color operator+(const Color& v1, const Color& v2) {
		Color c = Color(v1.r + v2.r, v1.g + v2.g, v1.b + v2.b);
		c.regular_color();
		return c;
	}

	friend Color operator+(int a, const Color& v) {
		Color c = Color(a + v.r, a + v.g, a + v.b);
		c.regular_color();
		return c;
	}

	friend Color operator+(const Color& v, int a) {
		Color c = Color(v.r + a, v.g + a, v.b + a);
		c.regular_color();
		return c;
	}

	friend Color operator-(const Color& v1, const Color& v2) {
		Color c = Color(v1.r - v2.r, v1.g - v2.g, v1.b - v2.b);
		c.regular_color();
		return c;
	}

	friend Color operator-(int a, const Color& v) {
		Color c = Color(a - v.r, a - v.g, a - v.b);
		c.regular_color();
		return c;
	}

	friend Color operator-(const Color& v, int a) {
		Color c = Color(v.r - a, v.g - a, v.b - a);
		c.regular_color();
		return c;
	}

	friend Color operator*(double a, const Color& v) {
		Color c = Color((int)(a * v.r), (int)(a * v.g), (int)(a * v.b));
		c.regular_color();
		return c;
	}

	friend Color operator*(const Color& v, double a) {
		return a * v;
	}

	friend Color operator/(const Color& v, double a) {
		Color c = Color((int)(1.0 * v.r / a), (int)(1.0 * v.g / a), (int)(1.0 * v.b / a));
		c.regular_color();
		return c;
	}

	Color& operator++() {
		r += 1;
		g += 1;
		b += 1;
		regular_color();
		return *this;
	}

	Color& operator--() {
		r -= 1;
		g -= 1;
		b -= 1;
		regular_color();
		return *this;
	}

	Color operator++(int) {
		Color v = *this;
		this->r += 1;
		this->g += 1;
		this->b += 1;
		this->regular_color();
		return v;
	}

	Color operator--(int) {
		Color v = *this;
		this->r -= 1;
		this->g -= 1;
		this->b -= 1;
		this->regular_color();
		return v;
	}

private:

	// �F�Ȃ��t���O
	bool none_flg;

	// �������F�͈̔͂ɏC��
	inline void regular_color();

};

// �F�iHSV�j
class ColorHSV {
public:

	// �eHSV�̌��E�l
	static const int max_h = 239;
	static const int max_s = 240;
	static const int max_v = 240;

	// �F�iHSV�j
	ColorHSV(int h = 0, int s = 0, int v = 0);

	// RGB�F�ɕϊ�
	Color to_rgb() const;

	// HSV�l�̕�������擾
	std::string get_str() const;

	// H�l
	val_property_set(int, h, public, set_h);

	// S�l
	val_property_set(int, s, public, set_s);

	// V�l
	val_property_set(int, v, public, set_v);

	// H�l���Z�b�g
	void set_h(int h);

	// S�l���Z�b�g
	void set_s(int s);

	// V�l���Z�b�g
	void set_v(int v);

	// �F�������ĂȂ�
	bool has_not_color() const;

	// �F�Ȃ��i�����ȗ��Ȃǁj
	static const ColorHSV none();

	friend bool operator==(const ColorHSV& v1, const ColorHSV& v2) {
		return v1.h == v2.h && v1.s == v2.s && v1.v == v2.v;
	}

	friend bool operator!=(const ColorHSV& v1, const ColorHSV& v2) {
		return !(v1 == v2);
	}

private:

	// �F�Ȃ��t���O
	bool none_flg;

};
