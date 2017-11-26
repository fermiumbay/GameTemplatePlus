#pragma once
#include "BaseObject.h"
#include "SceneInfo.h"
#include "BaseScene.h"

class SceneManager : public BaseObject {
public:

	SceneManager();
	~SceneManager();

	// �X�V
	void update() override;

	// �`��
	void draw() override;

	// �Q�[���I��
	self_flg(end_game);

private:

	// �V�[���I�u�W�F�N�g
	std::vector<BaseScene*> scenes;

	// �V�K�V�[����ǂݍ���
	void new_scene(SceneInfo::Scene scene);

};
