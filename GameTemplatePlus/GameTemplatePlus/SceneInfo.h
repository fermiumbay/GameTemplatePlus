#pragma once

class BaseScene;

// �V�[�����f�[�^
namespace SceneInfo {

	// �V�[�����̓o�^
	enum Scene {
		Scene_Main,	// ���C�����
	};

	// �����V�[���擾
	Scene get_default_scene();

	// �V�[���I�u�W�F�N�g�����E�擾
	BaseScene* get_new_scene(Scene scene);

}
