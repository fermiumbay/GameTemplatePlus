#pragma once

// 動きを与えるクラスたち
namespace Motion {

	// モーションクラスの基底
	template <class ValueType>
	class BaseMotion {
	public:

		BaseMotion() : time(0) {}

		virtual ~BaseMotion() {}

		// 初期化
		virtual void initialize() {
			time = 0;
		}

		// 更新
		virtual void update() {
			time++;
		}

		// 値の取得
		virtual ValueType get_value() = 0;

		// 終了判定
		virtual bool is_finished() = 0;

	protected:

		// 経過時間
		int time;

	private:

		BaseMotion(const BaseMotion&) {}
		BaseMotion& operator=(const BaseMotion&) {}

	};

}
