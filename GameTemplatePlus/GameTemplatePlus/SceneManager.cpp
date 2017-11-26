#include "SceneManager.h"

using namespace std;

SceneManager::SceneManager() {
	new_scene(SceneInfo::get_default_scene());
}

SceneManager::~SceneManager() {
	all_clear(scenes);
}

void SceneManager::new_scene(SceneInfo::Scene scene) {
	scenes.push_back(SceneInfo::get_new_scene(scene));
}

// 新規追加シーン
static vector<SceneInfo::Scene> new_scene_list;

void SceneManager::update() {
	BaseObject::update();

	// 新規シーンを追加
	for (auto p : new_scene_list) {
		new_scene(p);
	}
	new_scene_list.clear();

	// 進行中のシーンを全更新
	all_update(scenes);

	// 終了フラグ、シーン追加フラグの検知してシーン追加リストに追加
	for (auto p : scenes) {
		if (p->get_end_game_flg()) {
			end_game();
		}
		if (p->get_change_scene_flg()) {
			new_scene_list.push_back(p->get_new_scene());
		}
	}

	// 終了シーンを検知してシーン削除
	all_refresh(scenes);
}

void SceneManager::draw() {
	BaseObject::draw();

	// 進行中のシーンを全描画
	all_draw(scenes);

}
