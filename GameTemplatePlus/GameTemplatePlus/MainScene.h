#pragma once
#include "BaseScene.h"

class MainScene : public BaseScene {
public:
	MainScene();
	~MainScene();

	// 更新
	void update() override;

	// 描画
	void draw() override;

private:

	// フォント
	Font* font;

};
