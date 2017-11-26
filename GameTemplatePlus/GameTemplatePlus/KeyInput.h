#pragma once
#include "Vector2.h"
#include <vector>
#include <map>
#include <functional>

// キー入力関数の外部宣言
namespace GameDriver {
	bool check_hit_key(int key_id);
	bool get_mouse_input(int key_id);
	bool get_joypad_input_state(int key_id);
	Vector2 get_mouse_pos();
}

// キーの種類
enum KeyType {
	Down,	// ↓
	Left,	// ←
	Right,	// →
	Up,	// ↑
	OK,	// 決定キー
	Cancel,	// キャンセルキー
	Shift,	// シフトキー
	Ctrl,	// コントロールキー
};

// 使用できるキー名
namespace KeyName {

	// ゲームパッド
	enum DxLibPadKeyName {

		// パッド入力定義
		DX_PAD_INPUT_DOWN = (0x00000001),	// ↓チェックマスク
		DX_PAD_INPUT_LEFT = (0x00000002),	// ←チェックマスク
		DX_PAD_INPUT_RIGHT = (0x00000004),	// →チェックマスク
		DX_PAD_INPUT_UP = (0x00000008),	// ↑チェックマスク
		DX_PAD_INPUT_A = (0x00000010),	// Ａボタンチェックマスク
		DX_PAD_INPUT_B = (0x00000020),	// Ｂボタンチェックマスク
		DX_PAD_INPUT_C = (0x00000040),	// Ｃボタンチェックマスク
		DX_PAD_INPUT_X = (0x00000080),	// Ｘボタンチェックマスク
		DX_PAD_INPUT_Y = (0x00000100),	// Ｙボタンチェックマスク
		DX_PAD_INPUT_Z = (0x00000200),	// Ｚボタンチェックマスク
		DX_PAD_INPUT_L = (0x00000400),	// Ｌボタンチェックマスク
		DX_PAD_INPUT_R = (0x00000800),	// Ｒボタンチェックマスク
		DX_PAD_INPUT_START = (0x00001000),	// ＳＴＡＲＴボタンチェックマスク
		DX_PAD_INPUT_M = (0x00002000),	// Ｍボタンチェックマスク
		DX_PAD_INPUT_D = (0x00004000),
		DX_PAD_INPUT_F = (0x00008000),
		DX_PAD_INPUT_G = (0x00010000),
		DX_PAD_INPUT_H = (0x00020000),
		DX_PAD_INPUT_I = (0x00040000),
		DX_PAD_INPUT_J = (0x00080000),
		DX_PAD_INPUT_K = (0x00100000),
		DX_PAD_INPUT_LL = (0x00200000),
		DX_PAD_INPUT_N = (0x00400000),
		DX_PAD_INPUT_O = (0x00800000),
		DX_PAD_INPUT_P = (0x01000000),
		DX_PAD_INPUT_RR = (0x02000000),
		DX_PAD_INPUT_S = (0x04000000),
		DX_PAD_INPUT_T = (0x08000000),
		DX_PAD_INPUT_U = (0x10000000),
		DX_PAD_INPUT_V = (0x20000000),
		DX_PAD_INPUT_W = (0x40000000),
		DX_PAD_INPUT_XX = (0x80000000),

		DX_PAD_INPUT_1 = (0x00000010),
		DX_PAD_INPUT_2 = (0x00000020),
		DX_PAD_INPUT_3 = (0x00000040),
		DX_PAD_INPUT_4 = (0x00000080),
		DX_PAD_INPUT_5 = (0x00000100),
		DX_PAD_INPUT_6 = (0x00000200),
		DX_PAD_INPUT_7 = (0x00000400),
		DX_PAD_INPUT_8 = (0x00000800),
		DX_PAD_INPUT_9 = (0x00001000),
		DX_PAD_INPUT_10 = (0x00002000),
		DX_PAD_INPUT_11 = (0x00004000),
		DX_PAD_INPUT_12 = (0x00008000),
		DX_PAD_INPUT_13 = (0x00010000),
		DX_PAD_INPUT_14 = (0x00020000),
		DX_PAD_INPUT_15 = (0x00040000),
		DX_PAD_INPUT_16 = (0x00080000),
		DX_PAD_INPUT_17 = (0x00100000),
		DX_PAD_INPUT_18 = (0x00200000),
		DX_PAD_INPUT_19 = (0x00400000),
		DX_PAD_INPUT_20 = (0x00800000),
		DX_PAD_INPUT_21 = (0x01000000),
		DX_PAD_INPUT_22 = (0x02000000),
		DX_PAD_INPUT_23 = (0x04000000),
		DX_PAD_INPUT_24 = (0x08000000),
		DX_PAD_INPUT_25 = (0x10000000),
		DX_PAD_INPUT_26 = (0x20000000),
		DX_PAD_INPUT_27 = (0x40000000),
		DX_PAD_INPUT_28 = (0x80000000),

	};

	// マウス
	enum DxLibMouseKeyName {

		// マウス入力定義
		DX_MOUSE_INPUT_LEFT = (0x0001),			// マウス左ボタン
		DX_MOUSE_INPUT_RIGHT = (0x0002),			// マウス右ボタン
		DX_MOUSE_INPUT_MIDDLE = (0x0004),			// マウス中央ボタン
		DX_MOUSE_INPUT_1 = (0x0001),			// マウス１ボタン
		DX_MOUSE_INPUT_2 = (0x0002),			// マウス２ボタン
		DX_MOUSE_INPUT_3 = (0x0004),			// マウス３ボタン
		DX_MOUSE_INPUT_4 = (0x0008),			// マウス４ボタン
		DX_MOUSE_INPUT_5 = (0x0010),			// マウス５ボタン
		DX_MOUSE_INPUT_6 = (0x0020),			// マウス６ボタン
		DX_MOUSE_INPUT_7 = (0x0040),			// マウス７ボタン
		DX_MOUSE_INPUT_8 = (0x0080),			// マウス８ボタン

	};

	// キーボード
	enum DxLibKeyBoardKeyName {

		// キー定義
		DX_KEY_INPUT_BACK = (0x0E),				// BackSpaceキー	D_DIK_BACK
		DX_KEY_INPUT_TAB = (0x0F),				// Tabキー			D_DIK_TAB
		DX_KEY_INPUT_RETURN = (0x1C),				// Enterキー		D_DIK_RETURN

		DX_KEY_INPUT_LSHIFT = (0x2A),				// 左Shiftキー		D_DIK_LSHIFT
		DX_KEY_INPUT_RSHIFT = (0x36),				// 右Shiftキー		D_DIK_RSHIFT
		DX_KEY_INPUT_LCONTROL = (0x1D),				// 左Ctrlキー		D_DIK_LCONTROL
		DX_KEY_INPUT_RCONTROL = (0x9D),				// 右Ctrlキー		D_DIK_RCONTROL
		DX_KEY_INPUT_ESCAPE = (0x01),				// Escキー			D_DIK_ESCAPE
		DX_KEY_INPUT_SPACE = (0x39),				// スペースキー		D_DIK_SPACE
		DX_KEY_INPUT_PGUP = (0xC9),				// PageUpキー		D_DIK_PGUP
		DX_KEY_INPUT_PGDN = (0xD1),				// PageDownキー		D_DIK_PGDN
		DX_KEY_INPUT_END = (0xCF),				// Endキー			D_DIK_END
		DX_KEY_INPUT_HOME = (0xC7),				// Homeキー			D_DIK_HOME
		DX_KEY_INPUT_LEFT = (0xCB),				// 左キー			D_DIK_LEFT
		DX_KEY_INPUT_UP = (0xC8),				// 上キー			D_DIK_UP
		DX_KEY_INPUT_RIGHT = (0xCD),				// 右キー			D_DIK_RIGHT
		DX_KEY_INPUT_DOWN = (0xD0),				// 下キー			D_DIK_DOWN
		DX_KEY_INPUT_INSERT = (0xD2),				// Insertキー		D_DIK_INSERT
		DX_KEY_INPUT_DELETE = (0xD3),				// Deleteキー		D_DIK_DELETE

		DX_KEY_INPUT_MINUS = (0x0C),				// －キー			D_DIK_MINUS
		DX_KEY_INPUT_YEN = (0x7D),				// ￥キー			D_DIK_YEN
		DX_KEY_INPUT_PREVTRACK = (0x90),				// ＾キー			D_DIK_PREVTRACK
		DX_KEY_INPUT_PERIOD = (0x34),				// ．キー			D_DIK_PERIOD
		DX_KEY_INPUT_SLASH = (0x35),				// ／キー			D_DIK_SLASH
		DX_KEY_INPUT_LALT = (0x38),				// 左Altキー		D_DIK_LALT
		DX_KEY_INPUT_RALT = (0xB8),				// 右Altキー		D_DIK_RALT
		DX_KEY_INPUT_SCROLL = (0x46),				// ScrollLockキー	D_DIK_SCROLL
		DX_KEY_INPUT_SEMICOLON = (0x27),				// ；キー			D_DIK_SEMICOLON
		DX_KEY_INPUT_COLON = (0x92),				// ：キー			D_DIK_COLON
		DX_KEY_INPUT_LBRACKET = (0x1A),				// ［キー			D_DIK_LBRACKET
		DX_KEY_INPUT_RBRACKET = (0x1B),				// ］キー			D_DIK_RBRACKET
		DX_KEY_INPUT_AT = (0x91),				// ＠キー			D_DIK_AT
		DX_KEY_INPUT_BACKSLASH = (0x2B),				// ＼キー			D_DIK_BACKSLASH
		DX_KEY_INPUT_COMMA = (0x33),				// ，キー			D_DIK_COMMA
		DX_KEY_INPUT_KANJI = (0x94),				// 漢字キー			D_DIK_KANJI
		DX_KEY_INPUT_CONVERT = (0x79),				// 変換キー			D_DIK_CONVERT
		DX_KEY_INPUT_NOCONVERT = (0x7B),				// 無変換キー		D_DIK_NOCONVERT
		DX_KEY_INPUT_KANA = (0x70),				// カナキー			D_DIK_KANA
		DX_KEY_INPUT_APPS = (0xDD),				// アプリケーションメニューキー		D_DIK_APPS
		DX_KEY_INPUT_CAPSLOCK = (0x3A),				// CaspLockキー		D_DIK_CAPSLOCK
		DX_KEY_INPUT_SYSRQ = (0xB7),				// PrintScreenキー	D_DIK_SYSRQ
		DX_KEY_INPUT_PAUSE = (0xC5),				// PauseBreakキー	D_DIK_PAUSE
		DX_KEY_INPUT_LWIN = (0xDB),				// 左Winキー		D_DIK_LWIN
		DX_KEY_INPUT_RWIN = (0xDC),				// 右Winキー		D_DIK_RWIN

		DX_KEY_INPUT_NUMLOCK = (0x45),				// テンキーNumLockキー		D_DIK_NUMLOCK
		DX_KEY_INPUT_NUMPAD0 = (0x52),				// テンキー０				D_DIK_NUMPAD0
		DX_KEY_INPUT_NUMPAD1 = (0x4F),				// テンキー１				D_DIK_NUMPAD1
		DX_KEY_INPUT_NUMPAD2 = (0x50),				// テンキー２				D_DIK_NUMPAD2
		DX_KEY_INPUT_NUMPAD3 = (0x51),				// テンキー３				D_DIK_NUMPAD3
		DX_KEY_INPUT_NUMPAD4 = (0x4B),				// テンキー４				D_DIK_NUMPAD4
		DX_KEY_INPUT_NUMPAD5 = (0x4C),				// テンキー５				D_DIK_NUMPAD5
		DX_KEY_INPUT_NUMPAD6 = (0x4D),				// テンキー６				D_DIK_NUMPAD6
		DX_KEY_INPUT_NUMPAD7 = (0x47),				// テンキー７				D_DIK_NUMPAD7
		DX_KEY_INPUT_NUMPAD8 = (0x48),				// テンキー８				D_DIK_NUMPAD8
		DX_KEY_INPUT_NUMPAD9 = (0x49),				// テンキー９				D_DIK_NUMPAD9
		DX_KEY_INPUT_MULTIPLY = (0x37),				// テンキー＊キー			D_DIK_MULTIPLY
		DX_KEY_INPUT_ADD = (0x4E),				// テンキー＋キー			D_DIK_ADD
		DX_KEY_INPUT_SUBTRACT = (0x4A),				// テンキー－キー			D_DIK_SUBTRACT
		DX_KEY_INPUT_DECIMAL = (0x53),				// テンキー．キー			D_DIK_DECIMAL
		DX_KEY_INPUT_DIVIDE = (0xB5),				// テンキー／キー			D_DIK_DIVIDE
		DX_KEY_INPUT_NUMPADENTER = (0x9C),				// テンキーのエンターキー	D_DIK_NUMPADENTER

		DX_KEY_INPUT_F1 = (0x3B),				// Ｆ１キー			D_DIK_F1
		DX_KEY_INPUT_F2 = (0x3C),				// Ｆ２キー			D_DIK_F2
		DX_KEY_INPUT_F3 = (0x3D),				// Ｆ３キー			D_DIK_F3
		DX_KEY_INPUT_F4 = (0x3E),				// Ｆ４キー			D_DIK_F4
		DX_KEY_INPUT_F5 = (0x3F),				// Ｆ５キー			D_DIK_F5
		DX_KEY_INPUT_F6 = (0x40),				// Ｆ６キー			D_DIK_F6
		DX_KEY_INPUT_F7 = (0x41),				// Ｆ７キー			D_DIK_F7
		DX_KEY_INPUT_F8 = (0x42),				// Ｆ８キー			D_DIK_F8
		DX_KEY_INPUT_F9 = (0x43),				// Ｆ９キー			D_DIK_F9
		DX_KEY_INPUT_F10 = (0x44),				// Ｆ１０キー		D_DIK_F10
		DX_KEY_INPUT_F11 = (0x57),				// Ｆ１１キー		D_DIK_F11
		DX_KEY_INPUT_F12 = (0x58),				// Ｆ１２キー		D_DIK_F12

		DX_KEY_INPUT_A = (0x1E),				// Ａキー			D_DIK_A
		DX_KEY_INPUT_B = (0x30),				// Ｂキー			D_DIK_B
		DX_KEY_INPUT_C = (0x2E),				// Ｃキー			D_DIK_C
		DX_KEY_INPUT_D = (0x20),				// Ｄキー			D_DIK_D
		DX_KEY_INPUT_E = (0x12),				// Ｅキー			D_DIK_E
		DX_KEY_INPUT_F = (0x21),				// Ｆキー			D_DIK_F
		DX_KEY_INPUT_G = (0x22),				// Ｇキー			D_DIK_G
		DX_KEY_INPUT_H = (0x23),				// Ｈキー			D_DIK_H
		DX_KEY_INPUT_I = (0x17),				// Ｉキー			D_DIK_I
		DX_KEY_INPUT_J = (0x24),				// Ｊキー			D_DIK_J
		DX_KEY_INPUT_K = (0x25),				// Ｋキー			D_DIK_K
		DX_KEY_INPUT_L = (0x26),				// Ｌキー			D_DIK_L
		DX_KEY_INPUT_M = (0x32),				// Ｍキー			D_DIK_M
		DX_KEY_INPUT_N = (0x31),				// Ｎキー			D_DIK_N
		DX_KEY_INPUT_O = (0x18),				// Ｏキー			D_DIK_O
		DX_KEY_INPUT_P = (0x19),				// Ｐキー			D_DIK_P
		DX_KEY_INPUT_Q = (0x10),				// Ｑキー			D_DIK_Q
		DX_KEY_INPUT_R = (0x13),				// Ｒキー			D_DIK_R
		DX_KEY_INPUT_S = (0x1F),				// Ｓキー			D_DIK_S
		DX_KEY_INPUT_T = (0x14),				// Ｔキー			D_DIK_T
		DX_KEY_INPUT_U = (0x16),				// Ｕキー			D_DIK_U
		DX_KEY_INPUT_V = (0x2F),				// Ｖキー			D_DIK_V
		DX_KEY_INPUT_W = (0x11),				// Ｗキー			D_DIK_W
		DX_KEY_INPUT_X = (0x2D),				// Ｘキー			D_DIK_X
		DX_KEY_INPUT_Y = (0x15),				// Ｙキー			D_DIK_Y
		DX_KEY_INPUT_Z = (0x2C),				// Ｚキー			D_DIK_Z

		DX_KEY_INPUT_0 = (0x0B),				// ０キー			D_DIK_0
		DX_KEY_INPUT_1 = (0x02),				// １キー			D_DIK_1
		DX_KEY_INPUT_2 = (0x03),				// ２キー			D_DIK_2
		DX_KEY_INPUT_3 = (0x04),				// ３キー			D_DIK_3
		DX_KEY_INPUT_4 = (0x05),				// ４キー			D_DIK_4
		DX_KEY_INPUT_5 = (0x06),				// ５キー			D_DIK_5
		DX_KEY_INPUT_6 = (0x07),				// ６キー			D_DIK_6
		DX_KEY_INPUT_7 = (0x08),				// ７キー			D_DIK_7
		DX_KEY_INPUT_8 = (0x09),				// ８キー			D_DIK_8
		DX_KEY_INPUT_9 = (0x0A),				// ９キー			D_DIK_9

	};

}

// キー入力管理
class KeyInput {
public:

	// 初期化
	virtual void initialize();

	// 更新
	virtual void update();

	// 押した瞬間である
	bool pressed_now(KeyType type) { return get_press_time(type) == 1; }

	// 押している状態である
	bool pressed(KeyType type) { return get_press_time(type) >= 1; }

	// 離した瞬間である
	bool released_now(KeyType type) { return get_release_time(type) == 1; }

	// 離している状態である
	bool released(KeyType type) { return get_release_time(type) >= 1; }

	// 押下時間取得（押した瞬間が1、押してなければ0）
	int get_press_time(KeyType type);

	// 解放時間取得（離した瞬間が1、離してなければ0）
	int get_release_time(KeyType type);

	// キー判定条件取得
	std::function<bool()> get_key_cond(KeyType type);

	// キー判定条件設定
	void set_key_cond(KeyType type, std::function<bool()> cond);

private:

	// キー
	struct Key {

		Key();
		Key(std::function<bool()> cond);

		// 押下時間
		int press_time;

		// 解放時間
		int release_time;

		// 判定条件
		std::function<bool()> cond;

	};

	// 保持しているキー
	std::map<KeyType, Key> key;

};
