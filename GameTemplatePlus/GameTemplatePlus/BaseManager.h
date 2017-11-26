#pragma once
#include <vector>
#include <map>
#include "PropertyValue.h"

// 要素を管理し、要素として管理される基底クラス
class BaseManager {
public:

	BaseManager() {
		clear_flg = false;
	}

	virtual ~BaseManager() {}

	// 要素の削除
	self_flg(clear);

protected:

	// 全要素の関数呼び出し(vector)
	template<class Class, class ReturnType, class... Args>
	static void all_func(std::vector<Class*> &e, ReturnType(Class::*func)(Args...), const Args&... args) {
		for (auto it = e.begin(); it != e.end(); it++) {
			((*it)->*func)(args...);
		}
	}

	// 全要素を走査し、削除済みであれば実際に配列から削除する(vector)
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

	// 全要素の削除(vector)
	template<class Class>
	static void all_clear(std::vector<Class*> &e) {
		for (auto it = e.begin(); it != e.end(); it++) {
			delete *it;
		}
		e.clear();
	}

	// 全要素の関数呼び出し(map_first)
	template<class ClassA, class ClassB, class ReturnType, class... Args>
	static void all_func_first(std::map<ClassA*, ClassB> &e, ReturnType(ClassA::*func)(Args...), const Args&... args) {
		for (auto it = e.begin(); it != e.end(); it++) {
			((*it).first->*func)(args...);
		}
	}

	// 全要素を走査し、削除済みであれば実際に配列から削除する(map_first)
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

	// 全要素の削除(map_first)
	template<class ClassA, class ClassB>
	static void all_clear_first(std::map<ClassA*, ClassB> &e) {
		for (auto it = e.begin(); it != e.end(); it++) {
			delete (*it).first;
		}
		e.clear();
	}

	// 全要素の関数呼び出し(map_second)
	template<class ClassA, class ClassB, class ReturnType, class... Args>
	static void all_func_second(std::map<ClassA, ClassB*> &e, ReturnType(ClassB::*func)(Args...), const Args&... args) {
		for (auto it = e.begin(); it != e.end(); it++) {
			((*it).second->*func)(args...);
		}
	}

	// 全要素を走査し、削除済みであれば実際に配列から削除する(map_second)
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

	// 全要素の削除(map_second)
	template<class ClassA, class ClassB>
	static void all_clear_second(std::map<ClassA, ClassB*> &e) {
		for (auto it = e.begin(); it != e.end(); it++) {
			delete (*it).second;
		}
		e.clear();
	}

};
