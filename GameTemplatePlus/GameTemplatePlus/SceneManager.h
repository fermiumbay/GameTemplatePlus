#pragma once
#include "BaseObject.h"
#include "SceneInfo.h"
#include "BaseScene.h"

class SceneManager : public BaseObject {
public:

	SceneManager();
	~SceneManager();

	// 更新
	void update() override;

	// 描画
	void draw() override;

	// ゲーム終了
	self_flg(end_game);

private:

	// シーンオブジェクト
	std::vector<BaseScene*> scenes;

	// 新規シーンを読み込む
	void new_scene(SceneInfo::Scene scene);

};
