#pragma once
#include "Vector2.h"
#include "Color.h"

// �}�`���N���X
class BaseShape {
public:

	// �F
	val_property(Color, color, public, public);

	// �`��
	virtual void draw() = 0;

protected:

	BaseShape(Color color) {
		this->color = color;
	}

	virtual ~BaseShape() {}

};

// �_
class Point : public BaseShape {
public:

	// �_����
	Point(Vector2d p, Color color = Color::white());

	// ���W
	Vector2d p;

	// �`��
	void draw();

	// �w����W�̓_�̐F���擾
	static Color get_color(Vector2 p);

};

// ����
class Line : public BaseShape {
public:

	// ��������
	Line(Vector2d first, Vector2d last, Color color = Color::white());

	// �n�_���W
	Vector2d first;

	// �I�_���W
	Vector2d last;

	// �`��
	void draw();

};

// �����`
class Rectangle : public BaseShape {
public:

	// �l�p�`����
	Rectangle(Vector2d first, Vector2d last, Color color = Color::white(), bool fill_flg = true);

	// �n�_���W
	Vector2d first;

	// �I�_���W
	Vector2d last;

	// �h��Ԃ��t���O
	bool fill_flg;

	// �`��
	void draw();

};

// �O�p�`
class Triangle : public BaseShape {
public:

	// �O�p�`����
	Triangle(Vector2d p1, Vector2d p2, Vector2d p3, Color color = Color::white(), bool fill_flg = true);

	// �e���_���W
	Vector2d p1, p2, p3;

	// �h��Ԃ��t���O
	bool fill_flg;

	// �`��
	void draw();

};

// �ȉ~
class Ellipse : public BaseShape {
public:

	// �[���W����ȉ~����
	Ellipse(Vector2d first, Vector2d last, Color color = Color::white(), bool fill_flg = true);

	// ���S���W�Ɣ��a����ȉ~����
	Ellipse(Vector2d center, double radius_x, double radius_y, Color color = Color::white(), bool fill_flg = true);

	// �n�_���W
	Vector2d first;

	// �I�_���W
	Vector2d last;

	// ���S���W�擾
	Vector2d get_center_pos();

	// ���aX�擾
	double get_radius_x();

	// ���aY�擾
	double get_radius_y();

	// �h��Ԃ��t���O
	bool fill_flg;

	// �`��
	void draw();

};

// �~
class Circle : private Ellipse {
public:
	// ���S���W�Ɣ��a����~�擾
	Circle(Vector2d center, double radius, Color color = Color::white(), bool fill_flg = true)
		: Ellipse(center, radius, radius, color, fill_flg) {}

	// �F
	val_property_set_get(Color, color, set_color, get_color);

	// ���S���W
	val_property_set_get(Vector2d, center_pos, set_center_pos, get_center_pos);

	// ���a
	val_property_set_get(double, radius, set_radius, get_radius);

	// �h��Ԃ��t���O
	bool fill_flg;

	// �`��
	void draw() { Ellipse::draw(); }

	// ���S���W�擾
	Vector2d get_center_pos() { return Ellipse::get_center_pos(); }

	// ���a�擾
	double get_radius() { return Ellipse::get_radius_x(); }

	// ���S���W�Z�b�g
	void set_center_pos(Vector2d center_pos);

	// ���a�Z�b�g
	void set_radius(double radius);

	// �F�擾
	Color get_color() {
		return Ellipse::get_color();
	}

	// �F�Z�b�g
	void set_color(Color color) {
		Ellipse::set_color(color);
	}

};
