#pragma once
#include "BaseObject.h"
#include "SceneInfo.h"

// �V�[�����N���X
class BaseScene : public BaseObject {
public:

	// �R���X�g���N�^
	BaseScene();

	// �f�X�g���N�^
	virtual ~BaseScene();

	// �X�V
	virtual void update() override;

	// �`��
	virtual void draw() override;

	// �Q�[���I��
	self_flg(end_game);

	// �V�[���ύX
	self_flg(change_scene);

	// �ύX�V�[����
	self_val(SceneInfo::Scene, new_scene);

protected:

	// �V�[���ύX
	void change_scene(SceneInfo::Scene scene);

	// �V�[���ǉ�
	void add_scene(SceneInfo::Scene scene);

};
