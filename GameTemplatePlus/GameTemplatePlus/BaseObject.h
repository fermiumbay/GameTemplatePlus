#pragma once

// 標準ライブラリ
#include <random>

// インクルードヘッダー
#include "BaseManager.h"
#include "Vector2.h"
#include "Color.h"
#include "Shape.h"
#include "Motion.h"
#include "InfoData.h"
#include "ShareData.h"
#include "Font.h"
#include "GraphicCell.h"
#include "Graphic.h"
#include "Sound.h"
#include "KeyInput.h"

// BaseManagerをゲーム制作に特化したものとして拡張した基底クラス
class BaseObject : public BaseManager {
public:

	BaseObject();
	virtual ~BaseObject();

	// 初期化（経過時間を0に戻す）
	virtual void initialize();

	// 更新
	virtual void update();

	// 描画
	virtual void draw();

protected:

	// オブジェクト生成開始からの経過時間（初回updateのタイミングで1になる）
	int time;

	// 輝度（白で通常描画）
	Color color;

	// キー入力情報
	static KeyInput key_input;

	// ウィンドウモード変更（true: ウィンドウモード　false: フルスクリーンモード）
	void change_window_mode(bool mode);

	// 要素の全更新
	template<class Class> static void all_update(std::vector<Class*> &e) {
		all_func(e, &Class::update);
	}

	// 要素の全描画
	template<class Class> static void all_draw(std::vector<Class*> &e) {
		all_func(e, &Class::draw);
	}

	// 読み込み中フォントハンドル登録
	static void load(Font* &font, FontHandle font_handle);

	// 読み込み中サウンドハンドル登録
	static void load(Sound* &sound, SoundHandle sound_handle);

	// 読み込み中セル画ハンドル登録
	static void load(GraphicCell* &cell, GraphicCellHandle cell_handle);

	// 読み込み中分割セル画ハンドル登録
	static void load(std::vector<GraphicCell*> &cells, GraphicDivCellHandle cells_handle);

	// 読み込み中ハンドルを消去
	static void clear_handle();

	// 全ハンドル読み込みが完了したか
	static bool all_handle_loaded();

	// 全ハンドル読み込み完了後、各初期設定を完了させる
	static void all_handle_init();

	// 乱数初期化
	static void default_rand();

	// 初期値を指定して乱数初期化
	static void set_default_rand(int value);

	// 初期値を指定して乱数初期化（set_default_randと同義）
	static void default_rand(int value);

	// 乱数取得（0～value-1）
	static int rand(int value);

	// 乱数取得（min～max）
	static int rand(int min, int max);

	// 実数乱数取得（min～max）
	static double drand(double min, double max);

	// メルセンヌツイスタの取得
	static std::mt19937 get_mt();

	// 共有データ
	static ShareData share_data;

	// ウィンドウの中心座標を取得
	static Vector2d get_window_center();

	// 度をラジアンに
	static double deg2rad(double degree);

	// ラジアンを度に
	static double rad2deg(double radian);

	// startPosからgoalPosへ向かうための角度を求める（ラジアン）
	static double adir(Vector2 startPos, Vector2 goalPos);

	// startPosからgoalPosへ向かうための角度を求める（度）
	static double adir_deg(Vector2 startPos, Vector2 goalPos);

	// 右揃え数字文字列（数値と、指定桁数、0詰めするかのフラグを指定）
	static std::string right_number(long long int number, int limit, bool zeroFlg = false);

private:

	// メルセンヌツイスタ
	static std::mt19937 mt;

	// 読み込み中フォントハンドル
	static std::vector<std::tuple<bool, Font**, FontHandle>> BaseObject::loading_font_handle;

	// 読み込み中サウンドハンドル
	static std::vector<std::tuple<bool, Sound**, SoundHandle>> BaseObject::loading_sound_handle;

	// 読み込み中セル画ハンドル
	static std::vector<std::tuple<bool, GraphicCell**, GraphicCellHandle>> BaseObject::loading_graphic_cell_handle;

	// 読み込み中分割セル画ハンドル
	static std::vector<std::tuple<bool, std::vector<GraphicCell*>*, GraphicDivCellHandle>> BaseObject::loading_graphic_div_cell_handle;
};
