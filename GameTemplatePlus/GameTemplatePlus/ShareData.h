#pragma once
#include <string>

// セーブする共有データ
struct SaveData {
};

// セーブしない共有データ
struct UnSaveData {
};

// 共有データ
class ShareData {
public:

	// セーブに含めるデータ
	SaveData save_data;

	// セーブに含めないデータ
	UnSaveData unsave_data;

	// データの初期化（成功したらtrue）
	bool initialize();

	// データの終了処理（成功したらtrue）
	bool finalize();

	// データのセーブ（成功したらtrue）
	bool save(std::string path);

	// データのロード（成功したらtrue）
	bool load(std::string path);

};
