#pragma once

// ������^����N���X����
namespace Motion {

	// ���[�V�����N���X�̊��
	template <class ValueType>
	class BaseMotion {
	public:

		BaseMotion() : time(0) {}

		virtual ~BaseMotion() {}

		// ������
		virtual void initialize() {
			time = 0;
		}

		// �X�V
		virtual void update() {
			time++;
		}

		// �l�̎擾
		virtual ValueType get_value() = 0;

		// �I������
		virtual bool is_finished() = 0;

	protected:

		// �o�ߎ���
		int time;

	private:

		BaseMotion(const BaseMotion&) {}
		BaseMotion& operator=(const BaseMotion&) {}

	};

}
