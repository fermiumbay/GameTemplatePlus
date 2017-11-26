#include "SceneInfo.h"

// �o��V�[�����C���N���[�h
#include "MainScene.h"

// �����V�[�����̓o�^
SceneInfo::Scene SceneInfo::get_default_scene() {
	return Scene_Main;
}

BaseScene* SceneInfo::get_new_scene(Scene scene) {
	BaseScene* ret = nullptr;

	// �e�V�[���I�u�W�F�N�g�̐���
	switch (scene) {
	case Scene_Main:	ret = new MainScene();	break;
	};

	return ret;
}
