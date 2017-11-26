#include "GraphicCell.h"
#include "GameDriver.h"

using namespace std;

stack<int> GraphicCell::handle_stack;

GraphicCell* GraphicCell::create(bool wait_flg, Vector2 size) {
	GraphicCell *ret = new GraphicCell;
	ret->create_by_image_flg = false;
	ret->handle = GameDriver::make_screen(size);
	if (wait_flg) {
		GameDriver::wait_for_load(ret->handle);
		ret->size = GameDriver::get_graph_size(ret->handle);
	}
	return ret;
}

GraphicCell* GraphicCell::create(bool wait_flg, std::string path) {
	GraphicCell *ret = new GraphicCell;
	ret->create_by_image_flg = true;
	ret->handle = GameDriver::load_graph(path);
	if (wait_flg) {
		GameDriver::wait_for_load(ret->handle);
		ret->size = GameDriver::get_graph_size(ret->handle);
	}
	return ret;
}

vector<GraphicCell*> GraphicCell::create(bool wait_flg, std::string path, Vector2 one_size, Vector2 pattern_num) {
	vector<GraphicCell*> ret;
	vector<int> handles = GameDriver::load_div_graph(path, one_size, pattern_num);
	if (wait_flg) {
		GameDriver::wait_for_loads(handles);
	}
	for (int i = 0; i < pattern_num.x * pattern_num.y; i++) {
		GraphicCell *tmp = new GraphicCell;
		tmp->create_by_image_flg = true;
		tmp->handle = handles[i];
		if (wait_flg) {
			tmp->size = GameDriver::get_graph_size(tmp->handle);
		}
		ret.push_back(tmp);
	}
	return ret;
}

GraphicCell* GraphicCell::create(Vector2 size) {
	return create(true, size);
}

GraphicCell* GraphicCell::create(std::string path) {
	return create(true, path);
}

vector<GraphicCell*> GraphicCell::create(std::string path, Vector2 one_size, Vector2 pattern_num) {
	return create(true, path, one_size, pattern_num);
}

GraphicCellHandle GraphicCell::create_handle(Vector2 size) {
	GraphicCellHandle ret;
	ret.cell = create(false, size);
	return ret;
}

GraphicCellHandle GraphicCell::create_handle(std::string path) {
	GraphicCellHandle ret;
	ret.cell = create(false, path);
	return ret;
}

GraphicDivCellHandle GraphicCell::create_handle(std::string path, Vector2 one_size, Vector2 pattern_num) {
	GraphicDivCellHandle ret;
	ret.cells = create(false, path, one_size, pattern_num);
	return ret;
}

bool GraphicCell::already_loaded(GraphicCellHandle cell_handle) {
	return GameDriver::already_loaded(cell_handle.cell->handle);
}

bool GraphicCell::already_loaded(GraphicDivCellHandle cells_handle) {
	bool ret = true;
	for (auto p : cells_handle.cells) {
		if (!GameDriver::already_loaded(p->handle)) {
			ret = false;
			break;
		}
	}
	return ret;
}

GraphicCell* GraphicCell::create_by_handle(GraphicCellHandle cell_handle) {
	cell_handle.cell->size = GameDriver::get_graph_size(cell_handle.cell->handle);
	return cell_handle.cell;
}

std::vector<GraphicCell*> GraphicCell::create_by_handle(GraphicDivCellHandle cells_handle) {
	for (auto p : cells_handle.cells) {
		p->size = GameDriver::get_graph_size(p->handle);
	}
	return cells_handle.cells;
}

void GraphicCell::copy_display(Vector2 first, Vector2 last) {
	reset();
	GameDriver::get_draw_screen_graph(handle, first, last);
}

void GraphicCell::copy_display(Vector2 first, Vector2 last, int handle) {
	handle_stack.push(handle);
	set_draw_screen_by_handle_stack();
	copy_display(first, last);
	handle_stack.pop();
	set_draw_screen_by_handle_stack();
}

void GraphicCell::repaint(std::function<void()> func) {
	handle_stack.push(handle);
	set_draw_screen_by_handle_stack();
	GameDriver::set_draw_bright(Color::white());
	func();
	handle_stack.pop();
	set_draw_screen_by_handle_stack();
}

void GraphicCell::reset() {
	handle_stack.push(handle);
	set_draw_screen_by_handle_stack();
	GameDriver::clear_draw_screen();
	handle_stack.pop();
	set_draw_screen_by_handle_stack();
}

void GraphicCell::clear(GraphicCell* &cell) {
	if (cell != nullptr) {
		if (cell->create_by_image_flg) {
			GameDriver::delete_graph(cell->handle);
		}
		delete cell;
		cell = nullptr;
	}
}

void GraphicCell::clear(std::vector<GraphicCell*> &cells) {
	for (auto p : cells) {
		clear(p);
	}
	cells.clear();
}

void GraphicCell::set_draw_screen_by_handle_stack() {
	if (handle_stack.size() > 0) {
		GameDriver::set_draw_screen(handle_stack.top());
	}
	else {
		GameDriver::set_draw_screen_to_back();
	}
}

int GraphicCellHandle::get_handle() const {
	return cell->handle;
}

vector<int> GraphicDivCellHandle::get_handle() const {
	vector<int> ret;
	for (auto p : cells) {
		ret.push_back(p->handle);
	}
	return ret;
}
