#pragma once

#include <string>

class Vector2;
class Vector2d;

// 2�����x�N�g��
class Vector2 {
public:

	// ���W�l
	int x, y;

	// 2�����x�N�g��
	Vector2(int xi = 0, int yi = 0) : x(xi), y(yi) {}

	// �����x�N�g���iVector2d�j�ɕϊ�
	Vector2d to_double() const;

	// ���W�l�̕�������擾
	std::string get_str() const;

	Vector2 operator+() const {
		return *this;
	}

	Vector2 operator-() const {
		return Vector2(-x, -y);
	}

	Vector2& operator+=(const Vector2& v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2& operator-=(const Vector2& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vector2& operator+=(int a) {
		x += a;
		y += a;
		return *this;
	}

	Vector2& operator-=(int a) {
		x -= a;
		y -= a;
		return *this;
	}

	friend bool operator==(const Vector2& v1, const Vector2& v2) {
		return v1.x == v2.x && v1.y == v2.y;
	}

	friend bool operator!=(const Vector2& v1, const Vector2& v2) {
		return !(v1 == v2);
	}

	friend bool operator<(const Vector2& v1, const Vector2& v2) {
		return v1.x < v2.x && v1.y < v2.y;
	}

	friend bool operator<=(const Vector2& v1, const Vector2& v2) {
		return v1.x <= v2.x && v1.y <= v2.y;
	}

	friend bool operator>(const Vector2& v1, const Vector2& v2) {
		return v1.x > v2.x && v1.y > v2.y;
	}

	friend bool operator>=(const Vector2& v1, const Vector2& v2) {
		return v1.x >= v2.x && v1.y >= v2.y;
	}

	friend Vector2 operator+(const Vector2& v1, const Vector2& v2) {
		return Vector2(v1.x + v2.x, v1.y + v2.y);
	}

	friend Vector2 operator+(int x, const Vector2& v) {
		return Vector2(x + v.x, x + v.y);
	}

	friend Vector2 operator+(const Vector2& v, int y) {
		return Vector2(v.x + y, v.y + y);
	}

	friend Vector2 operator-(const Vector2& v1, const Vector2& v2) {
		return Vector2(v1.x - v2.x, v1.y - v2.y);
	}

	friend Vector2 operator-(int x, const Vector2& v) {
		return Vector2(x - v.x, x - v.y);
	}

	friend Vector2 operator-(const Vector2& v, int y) {
		return Vector2(v.x - y, v.y - y);
	}

	friend Vector2 operator*(int a, const Vector2& v) {
		return Vector2(a * v.x, a * v.y);
	}

	friend Vector2 operator/(const Vector2& v, int a) {
		return Vector2(v.x / a, v.y / a);
	}

	Vector2& operator++() {
		x += 1;
		y += 1;
		return *this;
	}

	Vector2& operator--() {
		x -= 1;
		y -= 1;
		return *this;
	}

	Vector2 operator++(int) {
		Vector2 v = *this;
		this->x += 1;
		this->y += 1;
		return v;
	}

	Vector2 operator--(int) {
		Vector2 v = *this;
		this->x -= 1;
		this->y -= 1;
		return v;
	}

};

// 2�����x�N�g���i�����j
class Vector2d {
public:

	// ���W�l
	double x, y;

	// 2�����x�N�g���i�����j
	Vector2d(double xi = 0, double yi = 0) : x(xi), y(yi) {}

	// �����x�N�g���iVector2�j�ɕϊ�
	Vector2 to_int() const;

	// ���W�l�̕�������擾
	std::string get_str() const;

	Vector2d operator+() const { return *this; }
	Vector2d operator-() const { return Vector2d(-x, -y); }

	Vector2d& operator+=(const Vector2d& v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2d& operator-=(const Vector2d& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vector2d& operator+=(double a) {
		x += a;
		y += a;
		return *this;
	}

	Vector2d& operator-=(double a) {
		x -= a;
		y -= a;
		return *this;
	}

	friend bool operator==(const Vector2d& v1, const Vector2d& v2) {
		return v1.x == v2.x && v1.y == v2.y;
	}

	friend bool operator!=(const Vector2d& v1, const Vector2d& v2) {
		return !(v1 == v2);
	}

	friend Vector2d operator+(const Vector2d& v1, const Vector2d& v2) {
		return Vector2d(v1.x + v2.x, v1.y + v2.y);
	}

	friend Vector2d operator+(double x, const Vector2d& v) {
		return Vector2d(x + v.x, x + v.y);
	}

	friend Vector2d operator+(const Vector2d& v, double y) {
		return Vector2d(v.x + y, v.y + y);
	}

	friend Vector2d operator-(const Vector2d& v1, const Vector2d& v2) {
		return Vector2d(v1.x - v2.x, v1.y - v2.y);
	}

	friend Vector2d operator-(double x, const Vector2d& v) {
		return Vector2d(x - v.x, x - v.y);
	}

	friend Vector2d operator-(const Vector2d& v, double y) {
		return Vector2d(v.x - y, v.y - y);
	}

	friend Vector2d operator*(double a, const Vector2d& v) {
		return Vector2d(a * v.x, a * v.y);
	}

	friend Vector2d operator/(const Vector2d& v, double a) {
		return Vector2d(v.x / a, v.y / a);
	}

	Vector2d& operator++() {
		x += 1.0;
		y += 1.0;
		return *this;
	}

	Vector2d& operator--() {
		x -= 1.0;
		y -= 1.0;
		return *this;
	}

	Vector2d operator++(int) {
		Vector2d v = *this;
		this->x += 1.0;
		this->y += 1.0;
		return v;
	}

	Vector2d operator--(int) {
		Vector2d v = *this;
		this->x -= 1.0;
		this->y -= 1.0;
		return v;
	}

};
