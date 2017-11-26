#pragma once
#include <string>
#include "Vector2.h"

// 固定情報データ（ゲーム中に変化しない情報）
namespace InfoData {

	// ゲームタイトル
	std::string get_game_title();

	// ウィンドウサイズ
	Vector2 get_window_size();

	// ウィンドウのカラービット数
	int get_window_color_bit_num();

	// 初期ウィンドウモードフラグ
	bool get_window_mode();

};
