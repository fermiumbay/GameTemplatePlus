#include "GameDriver.h"
#include "DxLib.h"

void GameDriver::wait_for_load(int handle) {
	while (!already_loaded(handle)) {
		ProcessMessage();
		Sleep(1);
	}
}

void GameDriver::wait_for_loads(std::vector<int> &handle) {
	int load_num = 0;
	bool* handle_loaded_flg = new bool[(int)handle.size()];
	for (int i = 0; i < (int)handle.size(); i++) {
		handle_loaded_flg[i] = false;
	}
	while (load_num < (int)handle.size()) {
		for (int i = 0; i < (int)handle.size(); i++) {
			if (handle_loaded_flg[i]) {
				continue;
			}
			if (already_loaded(handle[i])) {
				load_num++;
				handle_loaded_flg[i] = true;
			}
		}
		ProcessMessage();
		Sleep(1);
	}
	delete[] handle_loaded_flg;
}

bool GameDriver::already_loaded(int handle) {
	return CheckHandleASyncLoad(handle) != TRUE;
}

bool GameDriver::initialize(Vector2 window_size, std::string window_text, int window_mode, int window_color_bit_num) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);	// メモリリーク検出

	//初期処理（エラー発生すると終了）
	if (SetWindowIconID(101) != 0) { return false; }	// アイコン画像の埋め込み
	if (SetOutApplicationLogValidFlag(false) != 0) { return false; }	// ログ出力を禁止する
	if (SetGraphMode(window_size.x, window_size.y, window_color_bit_num) != 0) { return false; }	// 解像度の設定
	if (SetMainWindowText(window_text.c_str())) { return false; }	// タイトルバーの初期テキストを決定
	if (ChangeWindowMode(window_mode) != 0) { return false; }	// ウィンドウモードに設定
	if (DxLib_Init() != 0) { return false; }	//DXライブラリ初期化処理
	if (SetDrawScreen(DX_SCREEN_BACK) != 0) { return false; }	//描画先を裏画面に設定
	if (SetChangeScreenModeGraphicsSystemResetFlag(false)) { return false; }	// スクリーンモード変更による画像関係の設定初期化を禁止
	if (SetUseASyncLoadFlag(true) != 0) { return false; }	// 非同期読み込みON

	return true;
}

bool GameDriver::update() {
	if (ScreenFlip() != 0) { return false; }	//裏画面を表画面に反映
	if (ProcessMessage() != 0) { return false; }	//Windowsとの同期
	if (ClearDrawScreen() != 0) { return false; }	//画面を消去

	return true;
}

bool GameDriver::finalize() {
	DxLib_End();

	return true;
}

void GameDriver::change_window_mode(bool mode) {
	ChangeWindowMode(mode);
}

void GameDriver::draw_string(int handle, Vector2d pos, Vector2d add_pos, std::string text, Color color, Color edge_color) {
	DrawStringToHandle(
		static_cast<int>(pos.x + add_pos.x),
		static_cast<int>(pos.y + add_pos.y),
		text.c_str(),
		GetColor(color.r, color.g, color.b),
		handle,
		GetColor(edge_color.r, edge_color.g, edge_color.b)
	);
}

void GameDriver::delete_font_to_handle(int handle) {
	DeleteFontToHandle(handle);
}

void GameDriver::delete_graph(int handle) {
	DeleteGraph(handle);
}

int GameDriver::get_fonttype(int id) {
	switch (id) {
	case 0: return DX_FONTTYPE_NORMAL;	break;
	case 1:	return DX_FONTTYPE_EDGE;	break;
	case 2:	return DX_FONTTYPE_ANTIALIASING;	break;
	case 3:	return DX_FONTTYPE_ANTIALIASING_EDGE;	break;
	case 4:	return DX_FONTTYPE_ANTIALIASING_4X4;	break;
	case 5:	return DX_FONTTYPE_ANTIALIASING_EDGE_4X4;	break;
	case 6:	return DX_FONTTYPE_ANTIALIASING_8X8;	break;
	case 7:	return DX_FONTTYPE_ANTIALIASING_EDGE_8X8;	break;
	}
	return -1;
}

int GameDriver::create_new_font(std::string font_name, int size, int thick, int fontType) {
	int handle = CreateFontToHandle(font_name.c_str(), size, thick, fontType);
	return handle;
}

int GameDriver::load_graph(std::string path) {
	int handle = LoadGraph(path.c_str());
	return handle;
}

std::vector<int> GameDriver::load_div_graph(std::string path, Vector2 one_size, Vector2 div_num) {
	std::vector<int> ret;
	int *handle = new int[div_num.x * div_num.y];
	LoadDivGraph(path.c_str(), div_num.x * div_num.y, div_num.x, div_num.y, one_size.x, one_size.y, handle);
	for (int i = 0; i < div_num.x * div_num.y; i++) {
		ret.push_back(handle[i]);
	}
	delete[] handle;
	return ret;
}

int GameDriver::make_screen(Vector2 size) {
	int handle = MakeScreen(size.x, size.y, TRUE);
	return handle;
}

bool GameDriver::get_draw_screen_graph(int handle, Vector2 first, Vector2 last) {
	return GetDrawScreenGraph((int)first.x, (int)first.y, (int)(last.x + 1), (int)(last.y + 1), handle) == 0;
}

void GameDriver::set_draw_screen(int handle) {
	SetDrawScreen(handle);
}

void GameDriver::set_draw_screen_to_back() {
	SetDrawScreen(DX_SCREEN_BACK);
}

void GameDriver::clear_draw_screen() {
	ClearDrawScreen();
}

Color GameDriver::get_draw_bright() {
	int r, g, b;
	GetDrawBright(&r, &g, &b);
	return Color(r, g, b);
}

void GameDriver::set_draw_bright(Color c) {
	SetDrawBright(c.r, c.g, c.b);
}

void GameDriver::set_draw_mode(int mode) {
	switch (mode) {
	case 0: SetDrawMode(DX_DRAWMODE_BILINEAR);	break;	// バイリニア描画
	case 1: SetDrawMode(DX_DRAWMODE_NEAREST);	break;	// ネアレストネイバー描画
	}
}

void GameDriver::set_draw_blend_mode(int mode, int fade) {
	switch (mode) {
	case 0:	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, fade);	break;	// ブレンドなし
	case 1:	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fade);	break;	// アルファブレンド
	case 2:	SetDrawBlendMode(DX_BLENDMODE_ADD, fade); break;	// 加算ブレンド
	}
}

void GameDriver::draw_graph(int handle, Vector2d pos, bool trans) {
	DrawGraph((int)pos.x, (int)pos.y, handle, trans);
}

void GameDriver::draw_rota_graph(int handle, Vector2d pos, Vector2d center_pos, Vector2d zoom, double angle, bool trans, bool turn_flg) {
	DrawRotaGraph3((int)pos.x, (int)pos.y, (int)center_pos.x, (int)center_pos.y, 0.01 * zoom.x, 0.01 * zoom.y, -angle, handle, trans, turn_flg);
}

Vector2 GameDriver::get_graph_size(int handle) {
	int width, height;
	GetGraphSize(handle, &width, &height);
	return Vector2(width, height);
}

bool GameDriver::check_hit_key(int key_id) {
	return CheckHitKey(key_id) != 0;
}

bool GameDriver::get_mouse_input(int key_id) {
	return (GetMouseInput() & key_id) != 0;
}

bool GameDriver::get_joypad_input_state(int key_id) {
	return (GetJoypadInputState(DX_INPUT_PAD1) & key_id) != 0;
}

int GameDriver::load_sound(std::string path) {
	int handle = LoadSoundMem(path.c_str());
	return handle;
}

void GameDriver::play_sound(int handle, bool loop_flg, bool top_pos_flg) {
	PlaySoundMem(handle, loop_flg ? DX_PLAYTYPE_LOOP : DX_PLAYTYPE_BACK, top_pos_flg ? 1 : 0);
}

void GameDriver::stop_sound(int handle) {
	StopSoundMem(handle);
}

void GameDriver::delete_sound(int handle) {
	DeleteSoundMem(handle);
}

int GameDriver::get_sound_current_time(int handle) {
	return GetSoundCurrentTime(handle);
}

void GameDriver::set_sound_current_time(int handle, int time) {
	SetSoundCurrentTime(time, handle);
}

void GameDriver::set_sound_loop_pos(int handle, int loop_pos) {
	SetLoopPosSoundMem(loop_pos, handle);
}

bool GameDriver::is_playing_sound(int handle) {
	return CheckSoundMem(handle) == 1;
}

void GameDriver::set_sound_pan(int handle, int pan) {
	SetPanSoundMem(pan, handle);
}

void GameDriver::set_sound_volume(int handle, int volume) {
	ChangeVolumeSoundMem(volume, handle);
}

void GameDriver::set_sound_speed(int handle, int speed) {
	ResetFrequencySoundMem(handle);	// これしないとサンプリング周波数が得られない
	int frequency = GetFrequencySoundMem(handle);
	SetFrequencySoundMem(frequency * speed / 100, handle);
}

void GameDriver::set_sound_frequency(int handle, int frequency) {
	SetFrequencySoundMem(frequency, handle);
}

void GameDriver::draw_pixel(Vector2 pos, Color color) {
	DrawPixel(pos.x, pos.y, GetColor(color.r, color.g, color.b));
}

Color GameDriver::get_pixel(Vector2 pos) {
	int color = GetPixel(pos.x, pos.y);
	int r, g, b;
	GetColor2(color, &r, &g, &b);
	return Color(r, g, b);
}

void GameDriver::draw_line(Vector2 first, Vector2 last, Color color) {
	DrawLine(first.x, first.y, last.x + 1, last.y + 1, GetColor(color.r, color.g, color.b));
}

void GameDriver::draw_rectangle(Vector2 first, Vector2 last, Color color, bool fill_flg) {
	DrawBox(first.x, first.y, last.x + 1, last.y + 1, GetColor(color.r, color.g, color.b), fill_flg);
}

void GameDriver::draw_triangle(Vector2 p1, Vector2 p2, Vector2 p3, Color color, bool fill_flg) {
	DrawTriangle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, GetColor(color.r, color.g, color.b), fill_flg);
}

void GameDriver::draw_ellipse(Vector2 center, int radius_x, int radius_y, Color color, bool fill_flg) {
	DrawOval(center.x, center.y, radius_x, radius_y, GetColor(color.r, color.g, color.b), fill_flg);
}

Vector2 GameDriver::get_mouse_pos() {
	int x, y;
	GetMousePoint(&x, &y);
	return Vector2(x, y);
}
