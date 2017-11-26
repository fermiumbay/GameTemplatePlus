#include "BaseScene.h"

BaseScene::BaseScene() {
}

BaseScene::~BaseScene() {
}

void BaseScene::change_scene(SceneInfo::Scene scene) {
	add_scene(scene);
	clear();
}

void BaseScene::add_scene(SceneInfo::Scene scene) {
	change_scene();
	new_scene = scene;
}

void BaseScene::update() {
	BaseObject::update();
}

void BaseScene::draw() {
	BaseObject::draw();
}
