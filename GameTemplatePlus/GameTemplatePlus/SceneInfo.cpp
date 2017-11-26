#include "SceneInfo.h"

// 登場シーンをインクルード
#include "MainScene.h"

// 初期シーン名の登録
SceneInfo::Scene SceneInfo::get_default_scene() {
	return Scene_Main;
}

BaseScene* SceneInfo::get_new_scene(Scene scene) {
	BaseScene* ret = nullptr;

	// 各シーンオブジェクトの生成
	switch (scene) {
	case Scene_Main:	ret = new MainScene();	break;
	};

	return ret;
}
