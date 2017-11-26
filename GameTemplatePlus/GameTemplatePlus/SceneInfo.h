#pragma once

class BaseScene;

// シーン情報データ
namespace SceneInfo {

	// シーン名の登録
	enum Scene {
		Scene_Main,	// メイン画面
	};

	// 初期シーン取得
	Scene get_default_scene();

	// シーンオブジェクト生成・取得
	BaseScene* get_new_scene(Scene scene);

}
