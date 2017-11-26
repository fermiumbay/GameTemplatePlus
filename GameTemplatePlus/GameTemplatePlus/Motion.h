#pragma once
#include "BaseMotion.h"
#include "Vector2.h"

// ���[�V������ݒ肷��
namespace Motion {

	// �񎟋Ȑ�
	class Curve : public BaseMotion<double> {
	public:

		// �񎟋Ȑ�
		Curve() : BaseMotion<double>() {}

		// ������
		void initialize(Vector2d vertex_pos);
		void initialize() { BaseMotion<double>::initialize(); }

		// �l�̎擾
		double get_value();

		// �񎟊֐��̌v�Z�֐�(a(t-p)^2+q)
		static double func(double a, double p, double q, double t);

		// ���_�ʂ���
		bool passed_vertex();

		// �I������
		bool is_finished();

	private:

		// �I�����鎞��
		int finish_time;

		// �萔
		double a, p, q;

	};

	// �����U��
	class Wave : public BaseMotion<double> {
	public:

		// �����U��
		Wave() : BaseMotion<double>() {}

		// ������
		void initialize(double set_value, double a, double b, double c, double d);
		void initialize() { BaseMotion<double>::initialize(); }

		// �l�̎擾
		double get_value();

		// �I������
		bool is_finished();

	private:

		// �I�����鎞��
		int finish_time;

		// �I�����Ȃ��t���O
		bool never_finish_flg;

		// ��������l
		double set_value;

		// �萔�iae^(-bt)sin(ct+d)�j
		double a, b, c, d;

	};

}
