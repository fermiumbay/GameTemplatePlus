#pragma once
#include "BaseMotion.h"
#include "Vector2.h"

// モーションを設定する
namespace Motion {

	// 二次曲線
	class Curve : public BaseMotion<double> {
	public:

		// 二次曲線
		Curve() : BaseMotion<double>() {}

		// 初期化
		void initialize(Vector2d vertex_pos);
		void initialize() { BaseMotion<double>::initialize(); }

		// 値の取得
		double get_value();

		// 二次関数の計算関数(a(t-p)^2+q)
		static double func(double a, double p, double q, double t);

		// 頂点通った
		bool passed_vertex();

		// 終了判定
		bool is_finished();

	private:

		// 終了する時間
		int finish_time;

		// 定数
		double a, p, q;

	};

	// 減衰振動
	class Wave : public BaseMotion<double> {
	public:

		// 減衰振動
		Wave() : BaseMotion<double>() {}

		// 初期化
		void initialize(double set_value, double a, double b, double c, double d);
		void initialize() { BaseMotion<double>::initialize(); }

		// 値の取得
		double get_value();

		// 終了判定
		bool is_finished();

	private:

		// 終了する時間
		int finish_time;

		// 終了しないフラグ
		bool never_finish_flg;

		// 収束する値
		double set_value;

		// 定数（ae^(-bt)sin(ct+d)）
		double a, b, c, d;

	};

}
