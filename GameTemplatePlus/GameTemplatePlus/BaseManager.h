#pragma once
#include <vector>
#include <map>
#include "PropertyValue.h"

// �v�f���Ǘ����A�v�f�Ƃ��ĊǗ��������N���X
class BaseManager {
public:

	BaseManager() {
		clear_flg = false;
	}

	virtual ~BaseManager() {}

	// �v�f�̍폜
	self_flg(clear);

protected:

	// �S�v�f�̊֐��Ăяo��(vector)
	template<class Class, class ReturnType, class... Args>
	static void all_func(std::vector<Class*> &e, ReturnType(Class::*func)(Args...), const Args&... args) {
		for (auto it = e.begin(); it != e.end(); it++) {
			((*it)->*func)(args...);
		}
	}

	// �S�v�f�𑖍����A�폜�ς݂ł���Ύ��ۂɔz�񂩂�폜����(vector)
	template<class Class>
	static void all_refresh(std::vector<Class*> &e) {
		for (auto it = e.begin(); it != e.end(); ) {
			if ((*it)->get_clear_flg()) {
				delete *it;
				it = e.erase(it);
			}
			else {
				it++;
			}
		}
	}

	// �S�v�f�̍폜(vector)
	template<class Class>
	static void all_clear(std::vector<Class*> &e) {
		for (auto it = e.begin(); it != e.end(); it++) {
			delete *it;
		}
		e.clear();
	}

	// �S�v�f�̊֐��Ăяo��(map_first)
	template<class ClassA, class ClassB, class ReturnType, class... Args>
	static void all_func_first(std::map<ClassA*, ClassB> &e, ReturnType(ClassA::*func)(Args...), const Args&... args) {
		for (auto it = e.begin(); it != e.end(); it++) {
			((*it).first->*func)(args...);
		}
	}

	// �S�v�f�𑖍����A�폜�ς݂ł���Ύ��ۂɔz�񂩂�폜����(map_first)
	template<class ClassA, class ClassB>
	static void all_refresh_first(std::map<ClassA*, ClassB> &e) {
		for (auto it = e.begin(); it != e.end(); ) {
			if ((*it).first->get_clear_flg()) {
				delete (*it).first;
				it = e.erase(it);
			}
			else {
				it++;
			}
		}
	}

	// �S�v�f�̍폜(map_first)
	template<class ClassA, class ClassB>
	static void all_clear_first(std::map<ClassA*, ClassB> &e) {
		for (auto it = e.begin(); it != e.end(); it++) {
			delete (*it).first;
		}
		e.clear();
	}

	// �S�v�f�̊֐��Ăяo��(map_second)
	template<class ClassA, class ClassB, class ReturnType, class... Args>
	static void all_func_second(std::map<ClassA, ClassB*> &e, ReturnType(ClassB::*func)(Args...), const Args&... args) {
		for (auto it = e.begin(); it != e.end(); it++) {
			((*it).second->*func)(args...);
		}
	}

	// �S�v�f�𑖍����A�폜�ς݂ł���Ύ��ۂɔz�񂩂�폜����(map_second)
	template<class ClassA, class ClassB>
	static void all_refresh_second(std::map<ClassA, ClassB*> &e) {
		for (auto it = e.begin(); it != e.end(); ) {
			if ((*it).second->get_clear_flg()) {
				delete (*it).second;
				it = e.erase(it);
			}
			else {
				it++;
			}
		}
	}

	// �S�v�f�̍폜(map_second)
	template<class ClassA, class ClassB>
	static void all_clear_second(std::map<ClassA, ClassB*> &e) {
		for (auto it = e.begin(); it != e.end(); it++) {
			delete (*it).second;
		}
		e.clear();
	}

};
