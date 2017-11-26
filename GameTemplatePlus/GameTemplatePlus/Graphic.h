#pragma once
#include "GraphicCell.h"
#include "Vector2.h"
#include "Color.h"
#include <string>

// ブレンドモード
enum BlendMode {
	alpha_blend = 1,	// アルファブレンド
	add_blend = 2,	// 加算ブレンド
};

// 画像描画クラス
class Graphic {
public:

	// セル画を使って単体画像作成（単体インスタンス）
	static Graphic* create(GraphicCell *cell, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// セル画を使って複数画像作成（単体インスタンス）
	static Graphic* create(std::vector<GraphicCell*> cells, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// 画像ファイルを読み込んで単体画像作成（単体インスタンス）
	static Graphic* create(std::string path, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// 画像ファイルを読み込んで複数画像作成（単体インスタンス）
	static Graphic* create(std::string path, Vector2 one_size, Vector2 pattern_num, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// セル画を使って単体画像作成（分割インスタンス）
	static std::vector<Graphic*> create_div(std::vector<GraphicCell*> cells, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// セル画を使って複数画像作成（分割インスタンス）
	static std::vector<Graphic*> create_div(std::vector<GraphicCell*> cells, Vector2 div_num, Vector2 pattern_num, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// 画像ファイルを読み込んで単体画像作成（分割インスタンス）
	static std::vector<Graphic*> create_div(std::string path, Vector2 one_size, Vector2 div_num, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// 画像ファイルを読み込んで複数画像作成（分割インスタンス）
	static std::vector<Graphic*> create_div(std::string path, Vector2 one_size, Vector2 div_num, Vector2 pattern_num, Vector2d pos = Vector2d(), bool center_pos_flg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blend_mode = alpha_blend, bool bilinear_flg = true);

	// 単体インスタンスの削除
	static void clear(Graphic* graphic);

	// 分割インスタンスの一括削除
	static void clear(std::vector<Graphic*> &graphics);

	// 描画
	void draw(int id, Vector2d add_pos) const;
	void draw() const { draw(show_id, Vector2d()); }
	void draw(int id) const { draw(id, Vector2d()); }
	void draw(Vector2d add_pos) const { draw(show_id, add_pos); }

	// 表示座標
	Vector2d pos;

	// 不透明度（0～256）
	int fade;

	// 回転角度（反時計回り）[rad]
	double angle;

	// 透明色あり
	bool trans;

	// 左右反転あり
	bool turn_flg;

	// ブレンドモード
	BlendMode blend_mode;

	// バイリニア描画フラグ
	bool bilinear_flg;

	// 描画グラフィックID
	int show_id;

	// 拡大率[％]（横と縦）
	val_property(Vector2d, zoom, public, public);

	// 拡大率[％]を設定
	void set_zoom(double zoom = 100.0);

	// 色調
	val_property(Color, color, public, public);

	// 色調を元に戻す（白）
	void set_default_color();

	// 中心座標フラグ
	self_val(bool, center_pos_flg);

private:

	// 保持しているセル画（Graphic生成時に決まり、その後いじることは出来ない いじる場合はGraphicCell本体をいじること）
	std::vector<GraphicCell*> cells;

	// Graphic自身がGraphicCellを作成したため、Graphic削除時に保持しているGraphicCellを削除するフラグ
	bool self_delete_cells_flg;

	// Graphicの各パラメータ初期値代入
	void set_values(Vector2d pos, int fade, Vector2d zoom, double angle, bool center_pos_flg, bool trans, BlendMode blend_mode, bool bilinear_flg);

	Graphic() {}
	Graphic(const Graphic&) {}
	~Graphic() {}
	Graphic& operator=(const Graphic&) {}

};
