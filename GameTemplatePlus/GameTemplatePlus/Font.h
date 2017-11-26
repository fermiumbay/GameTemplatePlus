#pragma once
#include "Vector2.h"
#include "Color.h"
#include <string>

// フォントタイプ
enum FontType {
	normal,	// 通常
	antialiasing,	// アンチエイリアス（標準）
	antialiasing_4x4,	// アンチエイリアス（4x4サンプリング）
	antialiasing_8x8,	// アンチエイリアス（8x8サンプリング）
};

class Font;

// フォントハンドル
class FontHandle {
public:
	int get_handle() const;
private:
	Font* font;
	friend class Font;
};

// フォントクラス
class Font {
public:

	// フォント座標
	Vector2d pos;

	// 文字色
	self_val(Color, color);

	// エッジ色
	self_val(Color, edge_color);

	// テキスト表示
	void print(std::string text, Vector2d add_pos = Vector2d(), Color color = Color::none(), Color edge_color = Color::none()) const;

	// フォント作成
	static Font* create(std::string font_name, Vector2d pos = Vector2d(), int size = 16, int thick = 1, bool edge_flg = false, FontType font_type = FontType::antialiasing);

	// フォントハンドル作成
	static FontHandle create_handle(std::string font_name, Vector2d pos = Vector2d(), int size = 16, int thick = 1, bool edge_flg = false, FontType font_type = FontType::antialiasing);

	// フォントハンドル読み込み完了か
	static bool already_loaded(FontHandle font_handle);

	// ハンドルからフォント作成
	static Font* create_by_handle(FontHandle font_handle);

	// フォント削除
	static void clear(Font* &font);

	// フォントハンドル
	self_val(int, handle);

private:

	Font() {}
	Font(const Font&) {}
	~Font() {}
	Font& operator=(const Font&) {}

	// フォント作成（ロード中にウェイトするかを指定）
	static Font* create(bool wait_flg, std::string font_name, Vector2d pos = Vector2d(), int size = 16, int thick = 1, bool edge_flg = false, FontType font_type = FontType::antialiasing);

};
