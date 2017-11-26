#include "Motion.h"
using namespace Motion;

#define _USE_MATH_DEFINES
#include <math.h>

void Curve::initialize(Vector2d vertex_pos) {
	BaseMotion<double>::initialize();

	p = vertex_pos.x;
	q = vertex_pos.y;
	if (p == 0) {
		a = 0.0;
		finish_time = 0;
	}
	else {
		a = -q / (p*p);
		finish_time = static_cast<int>(2.0 * p);
	}
}

double Curve::get_value() {
	return func(a, p, q, time);
}

double Curve::func(double a, double p, double q, double t) {
	return a * (t - p) * (t - p) + q;
}

bool Curve::is_finished() {
	return time >= finish_time;
}

bool Curve::passed_vertex() {
	return time >= p;
}

void Wave::initialize(double set_value, double a, double b, double c, double d) {
	BaseMotion<double>::initialize();

	this->set_value = set_value;
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	if (a == 0 || (c == 0 && d == 0)) {
		finish_time = 0;
		never_finish_flg = false;
	}
	else if (b == 0) {
		never_finish_flg = true;
	}
	else if (c == 0) {
		finish_time = static_cast<int>(log(fabs(a * sin(d))) / b);
		never_finish_flg = false;
	}
	else {
		int n = static_cast<int>(1.0 / M_PI * (c / b * log(fabs(a)) + d) + 1.0);
		finish_time = static_cast<int>((-d + M_PI * n) / c);
		never_finish_flg = false;
	}
}

double Wave::get_value() {
	if (is_finished()) {
		return set_value;
	}
	else {
		return set_value + a * exp(-b * time) * sin(c * time + d);
	}
}

bool Wave::is_finished() {
	return !never_finish_flg && time > finish_time;
}
