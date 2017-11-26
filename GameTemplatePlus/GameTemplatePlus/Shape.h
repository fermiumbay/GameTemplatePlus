#pragma once
#include "Vector2.h"
#include "Color.h"

// 図形基底クラス
class BaseShape {
public:

	// 色
	val_property(Color, color, public, public);

	// 描画
	virtual void draw() = 0;

protected:

	BaseShape(Color color) {
		this->color = color;
	}

	virtual ~BaseShape() {}

};

// 点
class Point : public BaseShape {
public:

	// 点生成
	Point(Vector2d p, Color color = Color::white());

	// 座標
	Vector2d p;

	// 描画
	void draw();

	// 指定座標の点の色を取得
	static Color get_color(Vector2 p);

};

// 線分
class Line : public BaseShape {
public:

	// 線分生成
	Line(Vector2d first, Vector2d last, Color color = Color::white());

	// 始点座標
	Vector2d first;

	// 終点座標
	Vector2d last;

	// 描画
	void draw();

};

// 長方形
class Rectangle : public BaseShape {
public:

	// 四角形生成
	Rectangle(Vector2d first, Vector2d last, Color color = Color::white(), bool fill_flg = true);

	// 始点座標
	Vector2d first;

	// 終点座標
	Vector2d last;

	// 塗りつぶしフラグ
	bool fill_flg;

	// 描画
	void draw();

};

// 三角形
class Triangle : public BaseShape {
public:

	// 三角形生成
	Triangle(Vector2d p1, Vector2d p2, Vector2d p3, Color color = Color::white(), bool fill_flg = true);

	// 各頂点座標
	Vector2d p1, p2, p3;

	// 塗りつぶしフラグ
	bool fill_flg;

	// 描画
	void draw();

};

// 楕円
class Ellipse : public BaseShape {
public:

	// 端座標から楕円生成
	Ellipse(Vector2d first, Vector2d last, Color color = Color::white(), bool fill_flg = true);

	// 中心座標と半径から楕円生成
	Ellipse(Vector2d center, double radius_x, double radius_y, Color color = Color::white(), bool fill_flg = true);

	// 始点座標
	Vector2d first;

	// 終点座標
	Vector2d last;

	// 中心座標取得
	Vector2d get_center_pos();

	// 半径X取得
	double get_radius_x();

	// 半径Y取得
	double get_radius_y();

	// 塗りつぶしフラグ
	bool fill_flg;

	// 描画
	void draw();

};

// 円
class Circle : private Ellipse {
public:
	// 中心座標と半径から円取得
	Circle(Vector2d center, double radius, Color color = Color::white(), bool fill_flg = true)
		: Ellipse(center, radius, radius, color, fill_flg) {}

	// 色
	val_property_set_get(Color, color, set_color, get_color);

	// 中心座標
	val_property_set_get(Vector2d, center_pos, set_center_pos, get_center_pos);

	// 半径
	val_property_set_get(double, radius, set_radius, get_radius);

	// 塗りつぶしフラグ
	bool fill_flg;

	// 描画
	void draw() { Ellipse::draw(); }

	// 中心座標取得
	Vector2d get_center_pos() { return Ellipse::get_center_pos(); }

	// 半径取得
	double get_radius() { return Ellipse::get_radius_x(); }

	// 中心座標セット
	void set_center_pos(Vector2d center_pos);

	// 半径セット
	void set_radius(double radius);

	// 色取得
	Color get_color() {
		return Ellipse::get_color();
	}

	// 色セット
	void set_color(Color color) {
		Ellipse::set_color(color);
	}

};
