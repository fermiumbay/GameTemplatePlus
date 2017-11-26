#include "Game.h"

#include "GameDriver.h"
#include "BaseObject.h"

Game::Game() {
}

Game::~Game() {
}

void Game::run() {

	// �Q�[���{�̂̏���������
	if (!GameDriver::initialize(
		InfoData::get_window_size(),
		InfoData::get_game_title(),
		InfoData::get_window_mode(),
		InfoData::get_window_color_bit_num())) {
		return;
	}

	// �����̏�����
	BaseObject::default_rand();

	// ���L�f�[�^�̏�����
	BaseObject::share_data.initialize();

	// �L�[���͂̏�����
	BaseObject::key_input.initialize();

	// �V�[���}�l�[�W���[�̏�����
	sceneManager = new SceneManager;

	// �Q�[���{�̂̃��[�v����
	while (!sceneManager->get_end_game_flg()) {

		// �Q�[���{�̂̍X�V
		if (!GameDriver::update()) {
			break;
		}

		// �L�[���͏��̍X�V
		BaseObject::key_input.update();

		// �e�V�[���̍X�V
		sceneManager->update();

		// �e�V�[���̕`��
		sceneManager->draw();

		// �o�^�T�E���h�̑S�Đ�
		Sound::play_all_sound();

	}

	//���L�f�[�^�̏I������
	BaseObject::share_data.finalize();

	// �V�[���}�l�[�W���[�̔j��
	delete sceneManager;

	// �Q�[���{�̂̏I������
	if (!GameDriver::finalize()) {
		return;
	}
}
