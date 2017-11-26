#include "Vector2.h"
using namespace std;

Vector2d Vector2::to_double() const {
	return Vector2d(static_cast<double>(x), static_cast<double>(y));
}

Vector2 Vector2d::to_int() const {
	return Vector2(static_cast<int>(x), static_cast<int>(y));
}

string Vector2::get_str() const {
	return "(" + to_string(x) + ", " + to_string(y) + ")";
}

string Vector2d::get_str() const {
	return "(" + to_string(x) + ", " + to_string(y) + ")";
}
