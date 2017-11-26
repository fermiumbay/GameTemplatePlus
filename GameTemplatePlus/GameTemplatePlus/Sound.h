#pragma once
#include "PropertyValue.h"
#include <string>
#include <map>

class Sound;

// サウンドハンドル
class SoundHandle {
public:
	int get_handle() const;
private:
	Sound* sound;
	friend class Sound;
};

// サウンドクラス
class Sound {
public:

	// ループの可否を設定
	void set_loop_flg(bool loop_flg);

	// ループ位置を設定［ms］
	void set_loop_pos(int loop_pos);

	// 再生（単位[ms]）（引数省略で現在の再生位置から再開）
	virtual void play(int play_pos = -1);

	// 停止（再生位置を維持する場合はstay_flgをtrue）
	void stop(bool stay_flg = false);

	// 再生中であるか調べる
	bool is_playing();

	// 再生位置を取得
	int get_play_pos();

	// パン設定（-10000～10000）
	void set_pan(int pan = 0);

	// 音量設定（0～255）
	void set_volume(int volume);

	// 音量
	val_property_set(int, volume, public, set_volume);

	// 速さ設定[％]（100KHzを超える速さ（サンプリング周波数44100Hzだと226％まで）にはできない）
	void set_speed(int speed = 100);

	// 再生周波数設定[Hz]
	void set_frequency(int frequency = -1);

	// BGM作成
	static Sound* create_bgm(std::string path, int loop_pos = 0) {
		return create(path, true, loop_pos, false);
	}

	// SE作成
	static Sound* create_se(std::string path) {
		return create(path, false, 0, true);
	}

	// BGMハンドル作成
	static SoundHandle create_bgm_handle(std::string path, int loop_pos = 0) {
		return create_handle(path, true, loop_pos, false);
	}

	// SEハンドル作成
	static SoundHandle create_se_handle(std::string path) {
		return create_handle(path, false, 0, true);
	}

	// サウンドハンドル読み込み完了か
	static bool already_loaded(SoundHandle sound_handle);

	// ハンドルからサウンド作成
	static Sound* create_by_handle(SoundHandle sound_handle);

	// 音楽削除
	static void clear(Sound* sound);

	// ハンドル
	self_val(int, handle);

	// ループ位置
	self_val_set(int, loop_pos, set_loop_pos);

	// ループフラグ
	self_val_set(bool, loop_flg, set_loop_flg);

	// 効果音フラグ
	self_val(bool, se_flg);

	// 登録されているサウンドをすべて再生（実際には本関数によりサウンドが再生される）
	static void play_all_sound();

protected:

	// 音楽作成
	static Sound* create(std::string path = "", bool loop_flg = false, int loop_pos = 0, bool se_flg = false);

	// サウンドハンドル作成
	static SoundHandle create_handle(std::string path = "", bool loop_flg = false, int loop_pos = 0, bool se_flg = false);

private:

	Sound() {}
	~Sound() {}
	Sound(const Sound&) {}
	Sound& operator=(const Sound&) {}

	// 再生するサウンドポインタと再生位置の組
	static std::map<Sound*, int> play_sound_pos;

	// 実際の再生（登録されていたサウンドとして再生する）
	void play_virtual(int play_pos);

	// 音楽作成（ロード中にウェイトするかを指定）
	static Sound* create(bool wait_flg, std::string path = "", bool loop_flg = false, int loop_pos = 0, bool se_flg = false);

};
