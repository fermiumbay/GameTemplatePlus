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

// �V�K�ǉ��V�[��
static vector<SceneInfo::Scene> new_scene_list;

void SceneManager::update() {
	BaseObject::update();

	// �V�K�V�[����ǉ�
	for (auto p : new_scene_list) {
		new_scene(p);
	}
	new_scene_list.clear();

	// �i�s���̃V�[����S�X�V
	all_update(scenes);

	// �I���t���O�A�V�[���ǉ��t���O�̌��m���ăV�[���ǉ����X�g�ɒǉ�
	for (auto p : scenes) {
		if (p->get_end_game_flg()) {
			end_game();
		}
		if (p->get_change_scene_flg()) {
			new_scene_list.push_back(p->get_new_scene());
		}
	}

	// �I���V�[�������m���ăV�[���폜
	all_refresh(scenes);
}

void SceneManager::draw() {
	BaseObject::draw();

	// �i�s���̃V�[����S�`��
	all_draw(scenes);

}
