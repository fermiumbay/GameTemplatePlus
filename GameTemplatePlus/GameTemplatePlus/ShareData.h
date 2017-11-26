#pragma once
#include <string>

// �Z�[�u���鋤�L�f�[�^
struct SaveData {
};

// �Z�[�u���Ȃ����L�f�[�^
struct UnSaveData {
};

// ���L�f�[�^
class ShareData {
public:

	// �Z�[�u�Ɋ܂߂�f�[�^
	SaveData save_data;

	// �Z�[�u�Ɋ܂߂Ȃ��f�[�^
	UnSaveData unsave_data;

	// �f�[�^�̏������i����������true�j
	bool initialize();

	// �f�[�^�̏I�������i����������true�j
	bool finalize();

	// �f�[�^�̃Z�[�u�i����������true�j
	bool save(std::string path);

	// �f�[�^�̃��[�h�i����������true�j
	bool load(std::string path);

};
