#pragma once
#include "Vector2.h"
#include <vector>
#include <map>
#include <functional>

// �L�[���͊֐��̊O���錾
namespace GameDriver {
	bool check_hit_key(int key_id);
	bool get_mouse_input(int key_id);
	bool get_joypad_input_state(int key_id);
	Vector2 get_mouse_pos();
}

// �L�[�̎��
enum KeyType {
	Down,	// ��
	Left,	// ��
	Right,	// ��
	Up,	// ��
	OK,	// ����L�[
	Cancel,	// �L�����Z���L�[
	Shift,	// �V�t�g�L�[
	Ctrl,	// �R���g���[���L�[
};

// �g�p�ł���L�[��
namespace KeyName {

	// �Q�[���p�b�h
	enum DxLibPadKeyName {

		// �p�b�h���͒�`
		DX_PAD_INPUT_DOWN = (0x00000001),	// ���`�F�b�N�}�X�N
		DX_PAD_INPUT_LEFT = (0x00000002),	// ���`�F�b�N�}�X�N
		DX_PAD_INPUT_RIGHT = (0x00000004),	// ���`�F�b�N�}�X�N
		DX_PAD_INPUT_UP = (0x00000008),	// ���`�F�b�N�}�X�N
		DX_PAD_INPUT_A = (0x00000010),	// �`�{�^���`�F�b�N�}�X�N
		DX_PAD_INPUT_B = (0x00000020),	// �a�{�^���`�F�b�N�}�X�N
		DX_PAD_INPUT_C = (0x00000040),	// �b�{�^���`�F�b�N�}�X�N
		DX_PAD_INPUT_X = (0x00000080),	// �w�{�^���`�F�b�N�}�X�N
		DX_PAD_INPUT_Y = (0x00000100),	// �x�{�^���`�F�b�N�}�X�N
		DX_PAD_INPUT_Z = (0x00000200),	// �y�{�^���`�F�b�N�}�X�N
		DX_PAD_INPUT_L = (0x00000400),	// �k�{�^���`�F�b�N�}�X�N
		DX_PAD_INPUT_R = (0x00000800),	// �q�{�^���`�F�b�N�}�X�N
		DX_PAD_INPUT_START = (0x00001000),	// �r�s�`�q�s�{�^���`�F�b�N�}�X�N
		DX_PAD_INPUT_M = (0x00002000),	// �l�{�^���`�F�b�N�}�X�N
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

	// �}�E�X
	enum DxLibMouseKeyName {

		// �}�E�X���͒�`
		DX_MOUSE_INPUT_LEFT = (0x0001),			// �}�E�X���{�^��
		DX_MOUSE_INPUT_RIGHT = (0x0002),			// �}�E�X�E�{�^��
		DX_MOUSE_INPUT_MIDDLE = (0x0004),			// �}�E�X�����{�^��
		DX_MOUSE_INPUT_1 = (0x0001),			// �}�E�X�P�{�^��
		DX_MOUSE_INPUT_2 = (0x0002),			// �}�E�X�Q�{�^��
		DX_MOUSE_INPUT_3 = (0x0004),			// �}�E�X�R�{�^��
		DX_MOUSE_INPUT_4 = (0x0008),			// �}�E�X�S�{�^��
		DX_MOUSE_INPUT_5 = (0x0010),			// �}�E�X�T�{�^��
		DX_MOUSE_INPUT_6 = (0x0020),			// �}�E�X�U�{�^��
		DX_MOUSE_INPUT_7 = (0x0040),			// �}�E�X�V�{�^��
		DX_MOUSE_INPUT_8 = (0x0080),			// �}�E�X�W�{�^��

	};

	// �L�[�{�[�h
	enum DxLibKeyBoardKeyName {

		// �L�[��`
		DX_KEY_INPUT_BACK = (0x0E),				// BackSpace�L�[	D_DIK_BACK
		DX_KEY_INPUT_TAB = (0x0F),				// Tab�L�[			D_DIK_TAB
		DX_KEY_INPUT_RETURN = (0x1C),				// Enter�L�[		D_DIK_RETURN

		DX_KEY_INPUT_LSHIFT = (0x2A),				// ��Shift�L�[		D_DIK_LSHIFT
		DX_KEY_INPUT_RSHIFT = (0x36),				// �EShift�L�[		D_DIK_RSHIFT
		DX_KEY_INPUT_LCONTROL = (0x1D),				// ��Ctrl�L�[		D_DIK_LCONTROL
		DX_KEY_INPUT_RCONTROL = (0x9D),				// �ECtrl�L�[		D_DIK_RCONTROL
		DX_KEY_INPUT_ESCAPE = (0x01),				// Esc�L�[			D_DIK_ESCAPE
		DX_KEY_INPUT_SPACE = (0x39),				// �X�y�[�X�L�[		D_DIK_SPACE
		DX_KEY_INPUT_PGUP = (0xC9),				// PageUp�L�[		D_DIK_PGUP
		DX_KEY_INPUT_PGDN = (0xD1),				// PageDown�L�[		D_DIK_PGDN
		DX_KEY_INPUT_END = (0xCF),				// End�L�[			D_DIK_END
		DX_KEY_INPUT_HOME = (0xC7),				// Home�L�[			D_DIK_HOME
		DX_KEY_INPUT_LEFT = (0xCB),				// ���L�[			D_DIK_LEFT
		DX_KEY_INPUT_UP = (0xC8),				// ��L�[			D_DIK_UP
		DX_KEY_INPUT_RIGHT = (0xCD),				// �E�L�[			D_DIK_RIGHT
		DX_KEY_INPUT_DOWN = (0xD0),				// ���L�[			D_DIK_DOWN
		DX_KEY_INPUT_INSERT = (0xD2),				// Insert�L�[		D_DIK_INSERT
		DX_KEY_INPUT_DELETE = (0xD3),				// Delete�L�[		D_DIK_DELETE

		DX_KEY_INPUT_MINUS = (0x0C),				// �|�L�[			D_DIK_MINUS
		DX_KEY_INPUT_YEN = (0x7D),				// ���L�[			D_DIK_YEN
		DX_KEY_INPUT_PREVTRACK = (0x90),				// �O�L�[			D_DIK_PREVTRACK
		DX_KEY_INPUT_PERIOD = (0x34),				// �D�L�[			D_DIK_PERIOD
		DX_KEY_INPUT_SLASH = (0x35),				// �^�L�[			D_DIK_SLASH
		DX_KEY_INPUT_LALT = (0x38),				// ��Alt�L�[		D_DIK_LALT
		DX_KEY_INPUT_RALT = (0xB8),				// �EAlt�L�[		D_DIK_RALT
		DX_KEY_INPUT_SCROLL = (0x46),				// ScrollLock�L�[	D_DIK_SCROLL
		DX_KEY_INPUT_SEMICOLON = (0x27),				// �G�L�[			D_DIK_SEMICOLON
		DX_KEY_INPUT_COLON = (0x92),				// �F�L�[			D_DIK_COLON
		DX_KEY_INPUT_LBRACKET = (0x1A),				// �m�L�[			D_DIK_LBRACKET
		DX_KEY_INPUT_RBRACKET = (0x1B),				// �n�L�[			D_DIK_RBRACKET
		DX_KEY_INPUT_AT = (0x91),				// ���L�[			D_DIK_AT
		DX_KEY_INPUT_BACKSLASH = (0x2B),				// �_�L�[			D_DIK_BACKSLASH
		DX_KEY_INPUT_COMMA = (0x33),				// �C�L�[			D_DIK_COMMA
		DX_KEY_INPUT_KANJI = (0x94),				// �����L�[			D_DIK_KANJI
		DX_KEY_INPUT_CONVERT = (0x79),				// �ϊ��L�[			D_DIK_CONVERT
		DX_KEY_INPUT_NOCONVERT = (0x7B),				// ���ϊ��L�[		D_DIK_NOCONVERT
		DX_KEY_INPUT_KANA = (0x70),				// �J�i�L�[			D_DIK_KANA
		DX_KEY_INPUT_APPS = (0xDD),				// �A�v���P�[�V�������j���[�L�[		D_DIK_APPS
		DX_KEY_INPUT_CAPSLOCK = (0x3A),				// CaspLock�L�[		D_DIK_CAPSLOCK
		DX_KEY_INPUT_SYSRQ = (0xB7),				// PrintScreen�L�[	D_DIK_SYSRQ
		DX_KEY_INPUT_PAUSE = (0xC5),				// PauseBreak�L�[	D_DIK_PAUSE
		DX_KEY_INPUT_LWIN = (0xDB),				// ��Win�L�[		D_DIK_LWIN
		DX_KEY_INPUT_RWIN = (0xDC),				// �EWin�L�[		D_DIK_RWIN

		DX_KEY_INPUT_NUMLOCK = (0x45),				// �e���L�[NumLock�L�[		D_DIK_NUMLOCK
		DX_KEY_INPUT_NUMPAD0 = (0x52),				// �e���L�[�O				D_DIK_NUMPAD0
		DX_KEY_INPUT_NUMPAD1 = (0x4F),				// �e���L�[�P				D_DIK_NUMPAD1
		DX_KEY_INPUT_NUMPAD2 = (0x50),				// �e���L�[�Q				D_DIK_NUMPAD2
		DX_KEY_INPUT_NUMPAD3 = (0x51),				// �e���L�[�R				D_DIK_NUMPAD3
		DX_KEY_INPUT_NUMPAD4 = (0x4B),				// �e���L�[�S				D_DIK_NUMPAD4
		DX_KEY_INPUT_NUMPAD5 = (0x4C),				// �e���L�[�T				D_DIK_NUMPAD5
		DX_KEY_INPUT_NUMPAD6 = (0x4D),				// �e���L�[�U				D_DIK_NUMPAD6
		DX_KEY_INPUT_NUMPAD7 = (0x47),				// �e���L�[�V				D_DIK_NUMPAD7
		DX_KEY_INPUT_NUMPAD8 = (0x48),				// �e���L�[�W				D_DIK_NUMPAD8
		DX_KEY_INPUT_NUMPAD9 = (0x49),				// �e���L�[�X				D_DIK_NUMPAD9
		DX_KEY_INPUT_MULTIPLY = (0x37),				// �e���L�[���L�[			D_DIK_MULTIPLY
		DX_KEY_INPUT_ADD = (0x4E),				// �e���L�[�{�L�[			D_DIK_ADD
		DX_KEY_INPUT_SUBTRACT = (0x4A),				// �e���L�[�|�L�[			D_DIK_SUBTRACT
		DX_KEY_INPUT_DECIMAL = (0x53),				// �e���L�[�D�L�[			D_DIK_DECIMAL
		DX_KEY_INPUT_DIVIDE = (0xB5),				// �e���L�[�^�L�[			D_DIK_DIVIDE
		DX_KEY_INPUT_NUMPADENTER = (0x9C),				// �e���L�[�̃G���^�[�L�[	D_DIK_NUMPADENTER

		DX_KEY_INPUT_F1 = (0x3B),				// �e�P�L�[			D_DIK_F1
		DX_KEY_INPUT_F2 = (0x3C),				// �e�Q�L�[			D_DIK_F2
		DX_KEY_INPUT_F3 = (0x3D),				// �e�R�L�[			D_DIK_F3
		DX_KEY_INPUT_F4 = (0x3E),				// �e�S�L�[			D_DIK_F4
		DX_KEY_INPUT_F5 = (0x3F),				// �e�T�L�[			D_DIK_F5
		DX_KEY_INPUT_F6 = (0x40),				// �e�U�L�[			D_DIK_F6
		DX_KEY_INPUT_F7 = (0x41),				// �e�V�L�[			D_DIK_F7
		DX_KEY_INPUT_F8 = (0x42),				// �e�W�L�[			D_DIK_F8
		DX_KEY_INPUT_F9 = (0x43),				// �e�X�L�[			D_DIK_F9
		DX_KEY_INPUT_F10 = (0x44),				// �e�P�O�L�[		D_DIK_F10
		DX_KEY_INPUT_F11 = (0x57),				// �e�P�P�L�[		D_DIK_F11
		DX_KEY_INPUT_F12 = (0x58),				// �e�P�Q�L�[		D_DIK_F12

		DX_KEY_INPUT_A = (0x1E),				// �`�L�[			D_DIK_A
		DX_KEY_INPUT_B = (0x30),				// �a�L�[			D_DIK_B
		DX_KEY_INPUT_C = (0x2E),				// �b�L�[			D_DIK_C
		DX_KEY_INPUT_D = (0x20),				// �c�L�[			D_DIK_D
		DX_KEY_INPUT_E = (0x12),				// �d�L�[			D_DIK_E
		DX_KEY_INPUT_F = (0x21),				// �e�L�[			D_DIK_F
		DX_KEY_INPUT_G = (0x22),				// �f�L�[			D_DIK_G
		DX_KEY_INPUT_H = (0x23),				// �g�L�[			D_DIK_H
		DX_KEY_INPUT_I = (0x17),				// �h�L�[			D_DIK_I
		DX_KEY_INPUT_J = (0x24),				// �i�L�[			D_DIK_J
		DX_KEY_INPUT_K = (0x25),				// �j�L�[			D_DIK_K
		DX_KEY_INPUT_L = (0x26),				// �k�L�[			D_DIK_L
		DX_KEY_INPUT_M = (0x32),				// �l�L�[			D_DIK_M
		DX_KEY_INPUT_N = (0x31),				// �m�L�[			D_DIK_N
		DX_KEY_INPUT_O = (0x18),				// �n�L�[			D_DIK_O
		DX_KEY_INPUT_P = (0x19),				// �o�L�[			D_DIK_P
		DX_KEY_INPUT_Q = (0x10),				// �p�L�[			D_DIK_Q
		DX_KEY_INPUT_R = (0x13),				// �q�L�[			D_DIK_R
		DX_KEY_INPUT_S = (0x1F),				// �r�L�[			D_DIK_S
		DX_KEY_INPUT_T = (0x14),				// �s�L�[			D_DIK_T
		DX_KEY_INPUT_U = (0x16),				// �t�L�[			D_DIK_U
		DX_KEY_INPUT_V = (0x2F),				// �u�L�[			D_DIK_V
		DX_KEY_INPUT_W = (0x11),				// �v�L�[			D_DIK_W
		DX_KEY_INPUT_X = (0x2D),				// �w�L�[			D_DIK_X
		DX_KEY_INPUT_Y = (0x15),				// �x�L�[			D_DIK_Y
		DX_KEY_INPUT_Z = (0x2C),				// �y�L�[			D_DIK_Z

		DX_KEY_INPUT_0 = (0x0B),				// �O�L�[			D_DIK_0
		DX_KEY_INPUT_1 = (0x02),				// �P�L�[			D_DIK_1
		DX_KEY_INPUT_2 = (0x03),				// �Q�L�[			D_DIK_2
		DX_KEY_INPUT_3 = (0x04),				// �R�L�[			D_DIK_3
		DX_KEY_INPUT_4 = (0x05),				// �S�L�[			D_DIK_4
		DX_KEY_INPUT_5 = (0x06),				// �T�L�[			D_DIK_5
		DX_KEY_INPUT_6 = (0x07),				// �U�L�[			D_DIK_6
		DX_KEY_INPUT_7 = (0x08),				// �V�L�[			D_DIK_7
		DX_KEY_INPUT_8 = (0x09),				// �W�L�[			D_DIK_8
		DX_KEY_INPUT_9 = (0x0A),				// �X�L�[			D_DIK_9

	};

}

// �L�[���͊Ǘ�
class KeyInput {
public:

	// ������
	virtual void initialize();

	// �X�V
	virtual void update();

	// �������u�Ԃł���
	bool pressed_now(KeyType type) { return get_press_time(type) == 1; }

	// �����Ă����Ԃł���
	bool pressed(KeyType type) { return get_press_time(type) >= 1; }

	// �������u�Ԃł���
	bool released_now(KeyType type) { return get_release_time(type) == 1; }

	// �����Ă����Ԃł���
	bool released(KeyType type) { return get_release_time(type) >= 1; }

	// �������Ԏ擾�i�������u�Ԃ�1�A�����ĂȂ����0�j
	int get_press_time(KeyType type);

	// ������Ԏ擾�i�������u�Ԃ�1�A�����ĂȂ����0�j
	int get_release_time(KeyType type);

	// �L�[��������擾
	std::function<bool()> get_key_cond(KeyType type);

	// �L�[��������ݒ�
	void set_key_cond(KeyType type, std::function<bool()> cond);

private:

	// �L�[
	struct Key {

		Key();
		Key(std::function<bool()> cond);

		// ��������
		int press_time;

		// �������
		int release_time;

		// �������
		std::function<bool()> cond;

	};

	// �ێ����Ă���L�[
	std::map<KeyType, Key> key;

};
