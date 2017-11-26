#pragma once
#include "PropertyValue.h"

#include <string>

class Color;
class ColorHSV;

// 色
class Color {
public:

	// 各輝度の限界値
	static const int max_value = 255;

	// 色
	Color(int r = 0, int g = 0, int b = 0);

	// HSV色に変換
	ColorHSV to_hsv() const;

	// RGB値の文字列を取得
	std::string get_str() const;

	// 赤の輝度
	val_property_set(int, r, public, set_r);

	// 緑の輝度
	val_property_set(int, g, public, set_g);

	// 青の輝度
	val_property_set(int, b, public, set_b);

	// 赤の輝度をセット
	void set_r(int r);

	// 緑の輝度をセット
	void set_g(int g);

	// 青の輝度をセット
	void set_b(int b);

	// 色を持ってない
	bool has_not_color() const;

	// 赤
	static const Color red() { return Color(max_value, 0, 0); }

	// 緑
	static const Color green() { return Color(0, max_value, 0); }

	// 青
	static const Color blue() { return Color(0, 0, max_value); }

	// 黄色
	static const Color yellow() { return Color(max_value, max_value, 0); }

	// 明るい紫
	static const Color purple() { return Color(max_value, 0, max_value); }

	// 水色
	static const Color cyan() { return Color(0, max_value, max_value); }

	// 白
	static const Color white() { return Color(max_value, max_value, max_value); }

	// 灰色
	static const Color gray() { return Color((max_value + 1) / 2, (max_value + 1) / 2, (max_value + 1) / 2); }

	// 黒
	static const Color black() { return Color(0, 0, 0); }

	// 色なし（引数省略など）
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

	// 色なしフラグ
	bool none_flg;

	// 正しい色の範囲に修正
	inline void regular_color();

};

// 色（HSV）
class ColorHSV {
public:

	// 各HSVの限界値
	static const int max_h = 239;
	static const int max_s = 240;
	static const int max_v = 240;

	// 色（HSV）
	ColorHSV(int h = 0, int s = 0, int v = 0);

	// RGB色に変換
	Color to_rgb() const;

	// HSV値の文字列を取得
	std::string get_str() const;

	// H値
	val_property_set(int, h, public, set_h);

	// S値
	val_property_set(int, s, public, set_s);

	// V値
	val_property_set(int, v, public, set_v);

	// H値をセット
	void set_h(int h);

	// S値をセット
	void set_s(int s);

	// V値をセット
	void set_v(int v);

	// 色を持ってない
	bool has_not_color() const;

	// 色なし（引数省略など）
	static const ColorHSV none();

	friend bool operator==(const ColorHSV& v1, const ColorHSV& v2) {
		return v1.h == v2.h && v1.s == v2.s && v1.v == v2.v;
	}

	friend bool operator!=(const ColorHSV& v1, const ColorHSV& v2) {
		return !(v1 == v2);
	}

private:

	// 色なしフラグ
	bool none_flg;

};
