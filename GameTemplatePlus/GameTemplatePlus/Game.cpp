#include "Game.h"

#include "GameDriver.h"
#include "BaseObject.h"

Game::Game() {
}

Game::~Game() {
}

void Game::run() {

	// ゲーム本体の初期化処理
	if (!GameDriver::initialize(
		InfoData::get_window_size(),
		InfoData::get_game_title(),
		InfoData::get_window_mode(),
		InfoData::get_window_color_bit_num())) {
		return;
	}

	// 乱数の初期化
	BaseObject::default_rand();

	// 共有データの初期化
	BaseObject::share_data.initialize();

	// キー入力の初期化
	BaseObject::key_input.initialize();

	// シーンマネージャーの初期化
	sceneManager = new SceneManager;

	// ゲーム本体のループ処理
	while (!sceneManager->get_end_game_flg()) {

		// ゲーム本体の更新
		if (!GameDriver::update()) {
			break;
		}

		// キー入力情報の更新
		BaseObject::key_input.update();

		// 各シーンの更新
		sceneManager->update();

		// 各シーンの描画
		sceneManager->draw();

		// 登録サウンドの全再生
		Sound::play_all_sound();

	}

	//共有データの終了処理
	BaseObject::share_data.finalize();

	// シーンマネージャーの破棄
	delete sceneManager;

	// ゲーム本体の終了処理
	if (!GameDriver::finalize()) {
		return;
	}
}
