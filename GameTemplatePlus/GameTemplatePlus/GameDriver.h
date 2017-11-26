#pragma once
#include "Vector2.h"
#include "Color.h"
#include <string>
#include <vector>

// ゲーム動作させる本体との端末
namespace GameDriver {

	// ========================================
	// ハンドル読み込み系
	// ========================================

	// ハンドル読み込みが完了するまでウェイト
	void wait_for_load(int handle);

	// 複数ハンドル読み込みが完了するまでウェイト
	void wait_for_loads(std::vector<int> &handle);

	// 指定ハンドルが読み込み完了かどうか
	bool already_loaded(int handle);

	// ========================================
	// ゲーム全体の仕組み
	// ========================================

	// ゲーム本体の初期化
	bool initialize(Vector2 window_size, std::string window_text, int window_mode, int window_color_bit_num);

	// ゲームの更新処理
	bool update();

	// ゲームの終了処理
	bool finalize();

	// ウィンドウモード変更（true: ウィンドウモード　false: フルスクリーンモード）
	void change_window_mode(bool mode);

	// ========================================
	// 文字列描画関係
	// ========================================

	// 文字列描画関数
	void draw_string(int handle, Vector2d pos, Vector2d add_pos, std::string text, Color color, Color edge_color);

	// ハンドル指定したフォントデータの削除
	void delete_font_to_handle(int handle);

	// フォントタイプの取得
	int get_fonttype(int id);

	// フォントの新規作成
	int create_new_font(std::string font_name, int size, int thick, int fontType);

	// ========================================
	// 画像描画関係
	// ========================================

	// 画像読み込み
	int load_graph(std::string path);

	// 分割画像読み込み
	std::vector<int> load_div_graph(std::string path, Vector2 one_size, Vector2 div_num);

	// ハンドル指定した画像データの削除
	void delete_graph(int handle);

	// スクリーン生成
	int make_screen(Vector2 size);

	// ハンドル指定したスクリーンに対し、描画中画面をコピー（成功したらtrue）
	bool get_draw_screen_graph(int handle, Vector2 first, Vector2 last);

	// 指定したハンドルに描画先を変更
	void set_draw_screen(int handle);

	// 裏画面に描画先を変更
	void set_draw_screen_to_back();

	// 描画先を全クリア
	void clear_draw_screen();

	// 描画対象の輝度取得
	Color get_draw_bright();

	// 描画対象の輝度設定
	void set_draw_bright(Color c);

	// 描画モード指定
	void set_draw_mode(int mode);

	// ブレンドモードとブレンド値の設定
	void set_draw_blend_mode(int mode, int fade);

	// 画像描画
	void draw_graph(int handle, Vector2d pos, bool trans);

	// 回転画像描画
	void draw_rota_graph(int handle, Vector2d pos, Vector2d center_pos, Vector2d zoom, double angle, bool trans, bool turn_flg);

	// ハンドル指定した画像のサイズ取得
	Vector2 get_graph_size(int handle);

	// 点描画
	void draw_pixel(Vector2 pos, Color color);

	// 点の色を取得
	Color get_pixel(Vector2 pos);

	// 線描画
	void draw_line(Vector2 first, Vector2 last, Color color);

	// 矩形描画
	void draw_rectangle(Vector2 first, Vector2 last, Color color, bool fill_flg);

	// 三角形描画
	void draw_triangle(Vector2 p1, Vector2 p2, Vector2 p3, Color color, bool fill_flg);

	// 楕円描画
	void draw_ellipse(Vector2 center, int radius_x, int radius_y, Color color, bool fill_flg);

	// ========================================
	// キー入力関係
	// ========================================

	// key_idで指定したキーボードのキーが押されているか判定
	bool check_hit_key(int key_id);

	// key_idで指定したマウス入力がされているか判定
	bool get_mouse_input(int key_id);

	// key_idで指定したゲームパッドのキーが押されているか判定
	bool get_joypad_input_state(int key_id);

	// マウスの座標を取得
	Vector2 get_mouse_pos();

	// ========================================
	// サウンド関係
	// ========================================

	// サウンド素材ロード
	int load_sound(std::string path);

	// サウンド再生（[ms]単位）
	void play_sound(int handle, bool loop_flg, bool top_pos_flg);

	// サウンド停止
	void stop_sound(int handle);

	// サウンド破棄
	void delete_sound(int handle);

	// サウンド再生位置を取得
	int get_sound_current_time(int handle);

	// サウンド再生位置を指定
	void set_sound_current_time(int handle, int time);

	// サウンドループ位置を指定
	void set_sound_loop_pos(int handle, int loop_pos);

	// 該当サウンドが再生中
	bool is_playing_sound(int handle);

	// サウンドパン指定
	void set_sound_pan(int handle, int pan);

	// サウンド音量指定
	void set_sound_volume(int handle, int volume);

	// サウンド再生スピード指定
	void set_sound_speed(int handle, int speed);

	// サウンド周波数指定
	void set_sound_frequency(int handle, int frequency);

}
