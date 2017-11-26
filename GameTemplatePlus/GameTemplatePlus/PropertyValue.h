#pragma once

// �v���p�e�B�t���ϐ��̐錾�}�N���܂Ƃ�

// type�^�ϐ�name��getter��setter��t���Đ錾����
#define val_property(type, name, get_access, set_access) \
	private:\
		type _##name = (type)0;\
	_self_val_get(type, name, get_access)\
	_self_val_set(type, name, set_access)\
	public:\
		__declspec(property(get = get_##name, put = set_##name)) type name;

// bool�^�ϐ�name_flg���A�֐�name()��true�ɂȂ�Aget����Ǝ�����false�ɖ߂�֐���t���Đ錾����
#define flg_property(name, get_access, set_access) \
	private:\
		bool name##_flg = false;\
	_self_flg_get(type, name, get_access)\
	_self_flg_set(type, name, set_access)\
	public:

// type�^�ϐ�name��public��getter��protected��setter��t���Đ錾����
#define self_val(type, name) val_property(type, name, public, protected)

// bool�^�ϐ�name_flg���A�֐�name()��true�ɂȂ�Aget����Ǝ�����false�ɖ߂�֐���t���Đ錾����
#define self_flg(name) flg_property(name, public, protected)

// val_property getter�w��
#define val_property_get(type, name, set_access, get_func) \
	private:\
		type _##name = (type)0;\
	_self_val_set(type, name, set_access)\
	public:\
		__declspec(property(get = get_func, put = set_##name)) type name;

// val_property setter�w��
#define val_property_set(type, name, get_access, set_func) \
	private:\
		type _##name = (type)0;\
	_self_val_get(type, name, get_access)\
	public:\
		__declspec(property(get = get_##name, put = set_func)) type name;

// val_property getter/setter�w��
#define val_property_get_set(type, name, get_func, set_func) \
	private:\
		type _##name = (type)0;\
	public:\
		__declspec(property(get = get_func, put = set_func)) type name;

// val_property getter/setter�w��
#define val_property_set_get(type, name, set_func, get_func) val_property_get_set(type, name, get_func, set_func)

// flg_property getter�Ȃ�
#define flg_property_get(name, set_access) \
	private:\
		bool name##_flg = false;\
	_self_flg_set(type, name, set_access)\
	public:

// flg_property setter�Ȃ�
#define flg_property_set(name, get_access) \
	private:\
		bool name##_flg = false;\
	_self_flg_get(type, name, get_access)\
	public:

// flg_property getter/setter�Ȃ�
#define flg_property_get_set(name) \
	private:\
		bool name##_flg = false;\
	public:

// flg_property getter/setter�Ȃ�
#define flg_property_set_get(name) flg_property_get_set(name)

// self_val getter�w��
#define self_val_get(type, name, get_func) val_property_get(type, name, protected, get_func)

// self_val setter�w��
#define self_val_set(type, name, set_func) val_property_set(type, name, public, set_func)

// self_val getter/setter�w��
#define self_val_get_set(type, name, get_func, set_func) val_property_get_set(type, name, get_func, set_func)

// self_val getter/setter�w��
#define self_val_set_get(type, name, set_func, get_func) self_val_get_set(type, name, get_func, set_func)

// self_flg getter�Ȃ�
#define self_flg_get(name) flg_property_get(name, protected)

// self_flg setter�Ȃ�
#define self_flg_set(name) flg_property_set(name, public)

// self_flg getter/setter�Ȃ�
#define self_flg_get_set(name) flg_property_get_set(name)

// self_flg getter/setter�Ȃ�
#define self_flg_set_get(name) self_flg_get_set(name)

// self_val�pgetter�֐�
#define _self_val_get(type, name, access)	access##:\
		type get_##name() const {\
			return _##name;\
		}

// self_val�psetter�֐�
#define _self_val_set(type, name, access)	access##:\
		void set_##name(type name) {\
			_##name = name;\
		}

// self_flg�pgetter�֐�
#define _self_flg_get(type, name, access)		access##:\
		bool get_##name##_flg() {\
			bool ret = name##_flg;\
			name##_flg = false;\
			return ret;\
		}

// self_flg�psetter�֐�
#define _self_flg_set(type, name, access)		access##:\
		void name() {\
			name##_flg = true;\
		}
