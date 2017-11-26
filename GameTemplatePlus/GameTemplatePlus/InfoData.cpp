#include "InfoData.h"

using namespace std;

string InfoData::get_game_title() {
	return "新規プロジェクト";
}

Vector2 InfoData::get_window_size() {
	return Vector2(640, 480);
}

int InfoData::get_window_color_bit_num() {
	return 32;
}

bool InfoData::get_window_mode() {
	return true;
}
