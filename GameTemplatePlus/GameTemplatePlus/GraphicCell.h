#pragma once
#include "PropertyValue.h"
#include "Vector2.h"
#include <string>
#include <stack>
#include <functional>
#include <vector>

class GraphicCell;

// �Z����n���h��
class GraphicCellHandle {
public:
	int get_handle() const;
private:
	GraphicCell* cell;
	friend class GraphicCell;
};

// �����Z����n���h��
class GraphicDivCellHandle {
public:
	std::vector<int> get_handle() const;
private:
	std::vector<GraphicCell*> cells;
	friend class GraphicCell;
};

// �Z����
class GraphicCell {
public:

	// �T�C�Y���w�肵�ăX�N���[������
	static GraphicCell* create(Vector2 size);

	// �摜�t�@�C�������ƂɃZ���搶��
	static GraphicCell* create(std::string path);

	// �摜�t�@�C�������ƂɁApattern_num�̌������������ăZ���搶��
	static std::vector<GraphicCell*> create(std::string path, Vector2 one_size, Vector2 pattern_num);

	// �Z����n���h���쐬�i�X�N���[���j
	static GraphicCellHandle create_handle(Vector2 size);

	// �Z����n���h���쐬�i�摜�t�@�C���j
	static GraphicCellHandle create_handle(std::string path);

	// �����Z����n���h���쐬�i�摜�t�@�C���j
	static GraphicDivCellHandle create_handle(std::string path, Vector2 one_size, Vector2 pattern_num);

	// �Z����n���h���ǂݍ��݊�����
	static bool already_loaded(GraphicCellHandle cell_handle);

	// �����Z����n���h���ǂݍ��݊�����
	static bool already_loaded(GraphicDivCellHandle cells_handle);

	// �n���h������Z����쐬
	static GraphicCell* create_by_handle(GraphicCellHandle cell_handle);

	// �n���h�����番���Z����쐬
	static std::vector<GraphicCell*> create_by_handle(GraphicDivCellHandle cells_handle);

	// �`����e��ҏW
	virtual void repaint(std::function<void()> func);

	// �`�撆��ʂ��R�s�[
	virtual void copy_display(Vector2 first, Vector2 last);

	// handle�w�肵����ʂ��R�s�[
	virtual void copy_display(Vector2 first, Vector2 last, int handle);

	// �`����e�����S�N���A
	void reset();

	// �Z����폜
	static void clear(GraphicCell* &cell);

	// �Z����ꊇ�폜
	static void clear(std::vector<GraphicCell*> &cells);

	// �摜�n���h��
	self_val(int, handle);

	// �摜�t�@�C�������Ƃɍ쐬�����t���O
	self_val(bool, create_by_image_flg);

	// �摜�T�C�Y
	self_val(Vector2, size);

private:

	// �e���x�����Ƃ̃n���h���X�^�b�N
	static std::stack<int> handle_stack;

	// �n���h���X�^�b�N�̃g�b�v�̃n���h����`���ɐݒ�
	void set_draw_screen_by_handle_stack();

	GraphicCell() {}
	GraphicCell(const GraphicCell&) {}
	~GraphicCell() {}
	GraphicCell& operator=(const GraphicCell&) {}

	// �T�C�Y���w�肵�ăX�N���[�������i���[�h���ɃE�F�C�g���邩���w��j
	static GraphicCell* create(bool wait_flg, Vector2 size);

	// �摜�t�@�C�������ƂɃZ���搶���i���[�h���ɃE�F�C�g���邩���w��j
	static GraphicCell* create(bool wait_flg, std::string path);

	// �摜�t�@�C�������ƂɁApattern_num�̌������������ăZ���搶���i���[�h���ɃE�F�C�g���邩���w��j
	static std::vector<GraphicCell*> create(bool wait_flg, std::string path, Vector2 one_size, Vector2 pattern_num);

};
