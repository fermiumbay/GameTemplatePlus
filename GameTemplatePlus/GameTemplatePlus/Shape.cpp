#include "Shape.h"
#include "GameDriver.h"

Point::Point(Vector2d p, Color color) : BaseShape(color) {
	this->p = p;
}

void Point::draw() {
	GameDriver::draw_pixel(p.to_int(), color);
}

Color Point::get_color(Vector2 p) {
	return GameDriver::get_pixel(p);
}


Line::Line(Vector2d first, Vector2d last, Color color) : BaseShape(color) {
	this->first = first;
	this->last = last;
}

void Line::draw() {
	GameDriver::draw_line(first.to_int(), last.to_int(), color);
}

Rectangle::Rectangle(Vector2d first, Vector2d last, Color color, bool fill_flg) : BaseShape(color) {
	this->first = first;
	this->last = last;
	this->fill_flg = fill_flg;
}

void Rectangle::draw() {
	GameDriver::draw_rectangle(first.to_int(), last.to_int(), color, fill_flg);
}

Triangle::Triangle(Vector2d p1, Vector2d p2, Vector2d p3, Color color, bool fill_flg) : BaseShape(color) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->fill_flg = fill_flg;
}

void Triangle::draw() {
	GameDriver::draw_triangle(p1.to_int(), p2.to_int(), p3.to_int(), color, fill_flg);
}

Ellipse::Ellipse(Vector2d first, Vector2d last, Color color, bool fill_flg) : BaseShape(color) {
	this->first = first;
	this->last = last;
	this->fill_flg = fill_flg;
}

Ellipse::Ellipse(Vector2d center, double radius_x, double radius_y, Color color, bool fill_flg) : BaseShape(color) {
	this->first = center - Vector2d(radius_x, radius_y);
	this->last = center + Vector2d(radius_x, radius_y);
	this->fill_flg = fill_flg;
}

Vector2d Ellipse::get_center_pos() {
	return (first + last) / 2.0;
}

double Ellipse::get_radius_x() {
	return (last.x - first.x) / 2.0;
}

double Ellipse::get_radius_y() {
	return (last.y - first.y) / 2.0;
}

void Ellipse::draw() {
	GameDriver::draw_ellipse(get_center_pos().to_int(), (int)(get_radius_x() + 0.5), (int)(get_radius_y() + 0.5), color, fill_flg);
}

void Circle::set_center_pos(Vector2d center_pos) {
	Vector2d c = center_pos;
	Vector2d r = Vector2d(radius, radius);
	first = c - r;
	last = c + r;
}

void Circle::set_radius(double radius) {
	Vector2d c = center_pos;
	Vector2d r = Vector2d(radius, radius);
	first = c - r;
	last = c + r;
}
