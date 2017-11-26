#pragma once
#include "PropertyValue.h"
#include "Vector2.h"
#include <string>
#include <stack>
#include <functional>
#include <vector>

class GraphicCell;

// セル画ハンドル
class GraphicCellHandle {
public:
	int get_handle() const;
private:
	GraphicCell* cell;
	friend class GraphicCell;
};

// 分割セル画ハンドル
class GraphicDivCellHandle {
public:
	std::vector<int> get_handle() const;
private:
	std::vector<GraphicCell*> cells;
	friend class GraphicCell;
};

// セル画
class GraphicCell {
public:

	// サイズを指定してスクリーン生成
	static GraphicCell* create(Vector2 size);

	// 画像ファイルをもとにセル画生成
	static GraphicCell* create(std::string path);

	// 画像ファイルをもとに、pattern_numの個数だけ分割してセル画生成
	static std::vector<GraphicCell*> create(std::string path, Vector2 one_size, Vector2 pattern_num);

	// セル画ハンドル作成（スクリーン）
	static GraphicCellHandle create_handle(Vector2 size);

	// セル画ハンドル作成（画像ファイル）
	static GraphicCellHandle create_handle(std::string path);

	// 分割セル画ハンドル作成（画像ファイル）
	static GraphicDivCellHandle create_handle(std::string path, Vector2 one_size, Vector2 pattern_num);

	// セル画ハンドル読み込み完了か
	static bool already_loaded(GraphicCellHandle cell_handle);

	// 分割セル画ハンドル読み込み完了か
	static bool already_loaded(GraphicDivCellHandle cells_handle);

	// ハンドルからセル画作成
	static GraphicCell* create_by_handle(GraphicCellHandle cell_handle);

	// ハンドルから分割セル画作成
	static std::vector<GraphicCell*> create_by_handle(GraphicDivCellHandle cells_handle);

	// 描画内容を編集
	virtual void repaint(std::function<void()> func);

	// 描画中画面をコピー
	virtual void copy_display(Vector2 first, Vector2 last);

	// handle指定した画面をコピー
	virtual void copy_display(Vector2 first, Vector2 last, int handle);

	// 描画内容を完全クリア
	void reset();

	// セル画削除
	static void clear(GraphicCell* &cell);

	// セル画一括削除
	static void clear(std::vector<GraphicCell*> &cells);

	// 画像ハンドル
	self_val(int, handle);

	// 画像ファイルをもとに作成したフラグ
	self_val(bool, create_by_image_flg);

	// 画像サイズ
	self_val(Vector2, size);

private:

	// 各レベルごとのハンドルスタック
	static std::stack<int> handle_stack;

	// ハンドルスタックのトップのハンドルを描画先に設定
	void set_draw_screen_by_handle_stack();

	GraphicCell() {}
	GraphicCell(const GraphicCell&) {}
	~GraphicCell() {}
	GraphicCell& operator=(const GraphicCell&) {}

	// サイズを指定してスクリーン生成（ロード中にウェイトするかを指定）
	static GraphicCell* create(bool wait_flg, Vector2 size);

	// 画像ファイルをもとにセル画生成（ロード中にウェイトするかを指定）
	static GraphicCell* create(bool wait_flg, std::string path);

	// 画像ファイルをもとに、pattern_numの個数だけ分割してセル画生成（ロード中にウェイトするかを指定）
	static std::vector<GraphicCell*> create(bool wait_flg, std::string path, Vector2 one_size, Vector2 pattern_num);

};
