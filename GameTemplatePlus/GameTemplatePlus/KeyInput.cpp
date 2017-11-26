#include "KeyInput.h"
#include "GameDriver.h"

void KeyInput::initialize() {
	key.clear();

	// ↓
	key[Down] = Key([] {
		bool ret =
			GameDriver::check_hit_key(KeyName::DX_KEY_INPUT_DOWN) ||
			GameDriver::get_joypad_input_state(KeyName::DX_PAD_INPUT_DOWN);
		return ret;
	});

	// ←
	key[Left] = Key([] {
		bool ret =
			GameDriver::check_hit_key(KeyName::DX_KEY_INPUT_LEFT) ||
			GameDriver::get_joypad_input_state(KeyName::DX_PAD_INPUT_LEFT);
		return ret;
	});

	// →
	key[Right] = Key([] {
		bool ret =
			GameDriver::check_hit_key(KeyName::DX_KEY_INPUT_RIGHT) ||
			GameDriver::get_joypad_input_state(KeyName::DX_PAD_INPUT_RIGHT);
		return ret;
	});

	// ↑
	key[Up] = Key([] {
		bool ret =
			GameDriver::check_hit_key(KeyName::DX_KEY_INPUT_UP) ||
			GameDriver::get_joypad_input_state(KeyName::DX_PAD_INPUT_UP);
		return ret;
	});

	// 決定キー
	key[OK] = Key([] {
		bool ret =
			GameDriver::check_hit_key(KeyName::DX_KEY_INPUT_Z) ||
			GameDriver::check_hit_key(KeyName::DX_KEY_INPUT_RETURN) ||
			GameDriver::get_joypad_input_state(KeyName::DX_PAD_INPUT_1);
		return ret;
	});

	// キャンセルキー
	key[Cancel] = Key([] {
		bool ret =
			GameDriver::check_hit_key(KeyName::DX_KEY_INPUT_X) ||
			GameDriver::check_hit_key(KeyName::DX_KEY_INPUT_ESCAPE) ||
			GameDriver::get_joypad_input_state(KeyName::DX_PAD_INPUT_2) ||
			GameDriver::get_joypad_input_state(KeyName::DX_PAD_INPUT_5);
		return ret;
	});

	// シフトキー
	key[Shift] = Key([] {
		bool ret =
			GameDriver::check_hit_key(KeyName::DX_KEY_INPUT_LSHIFT) ||
			GameDriver::check_hit_key(KeyName::DX_KEY_INPUT_RSHIFT) ||
			GameDriver::get_joypad_input_state(KeyName::DX_PAD_INPUT_3);
		return ret;
	});

	// コントロールキー
	key[Ctrl] = Key([] {
		bool ret =
			GameDriver::check_hit_key(KeyName::DX_KEY_INPUT_LCONTROL) ||
			GameDriver::check_hit_key(KeyName::DX_KEY_INPUT_RCONTROL) ||
			GameDriver::get_joypad_input_state(KeyName::DX_PAD_INPUT_4);
		return ret;
	});

}

void KeyInput::update() {
	for (auto &p : key) {
		if (p.second.cond()) {
			p.second.press_time++;
			p.second.release_time = 0;
		}
		else {
			p.second.release_time++;
			p.second.press_time = 0;
		}
	}
}

int KeyInput::get_press_time(KeyType type) {
	return key[type].press_time;
}

int KeyInput::get_release_time(KeyType type) {
	return key[type].release_time;
}

KeyInput::Key::Key() {
	press_time = 0;
	release_time = 0;
}

KeyInput::Key::Key(std::function<bool()> cond) {
	press_time = 0;
	release_time = 0;
	this->cond = cond;
}

std::function<bool()> KeyInput::get_key_cond(KeyType type) {
	return key[type].cond;
}

void KeyInput::set_key_cond(KeyType type, std::function<bool()> cond) {
	key[type].cond = cond;
}
