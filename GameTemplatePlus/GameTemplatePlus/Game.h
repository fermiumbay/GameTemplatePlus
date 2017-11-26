#pragma once
#include "SceneManager.h"

class Game : public BaseObject {
public:
	Game();
	~Game();

	// ゲーム実行
	void run();

private:

	// シーンマネージャー
	SceneManager *sceneManager;

};
