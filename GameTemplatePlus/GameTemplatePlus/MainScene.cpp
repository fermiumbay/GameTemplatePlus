#include "MainScene.h"

MainScene::MainScene() {
	font = Font::create("���C���I", Vector2d(20, 20), 24);
}

MainScene::~MainScene() {
	Font::clear(font);
}

void MainScene::update() {
	BaseScene::update();

	if (key_input.pressed_now(Cancel)) {
		end_game();
	}
}

void MainScene::draw() {
	BaseScene::draw();

	font->print("�L�����Z���L�[�ŏI�����܂��B");
}
