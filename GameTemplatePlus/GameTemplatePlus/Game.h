#pragma once
#include "SceneManager.h"

class Game : public BaseObject {
public:
	Game();
	~Game();

	// �Q�[�����s
	void run();

private:

	// �V�[���}�l�[�W���[
	SceneManager *sceneManager;

};
