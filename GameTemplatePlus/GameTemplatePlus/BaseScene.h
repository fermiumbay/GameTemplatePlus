#pragma once
#include "BaseObject.h"
#include "SceneInfo.h"

// シーン基底クラス
class BaseScene : public BaseObject {
public:

	// コンストラクタ
	BaseScene();

	// デストラクタ
	virtual ~BaseScene();

	// 更新
	virtual void update() override;

	// 描画
	virtual void draw() override;

	// ゲーム終了
	self_flg(end_game);

	// シーン変更
	self_flg(change_scene);

	// 変更シーン名
	self_val(SceneInfo::Scene, new_scene);

protected:

	// シーン変更
	void change_scene(SceneInfo::Scene scene);

	// シーン追加
	void add_scene(SceneInfo::Scene scene);

};
