#pragma once
#include "BaseScene.h"

class MainScene : public BaseScene {
public:
	MainScene();
	~MainScene();

	// �X�V
	void update() override;

	// �`��
	void draw() override;

private:

	// �t�H���g
	Font* font;

};
