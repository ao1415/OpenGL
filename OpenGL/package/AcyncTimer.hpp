#pragma once

#include <GL/glut.h>
#include <functional>

namespace opc {

	class System;

	/// <summary>
	///	<para>�^�C�}�[�p�̃N���X</para>
	///	<para>�g�p�֎~</para>
	///	</summary>
	class AcyncTimer {
	private:

		friend System;

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		AcyncTimer();
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="v">���s�֐�</param>
		AcyncTimer(std::function<void(int)> _func);

		/// <summary>���s����֐�</summary>
		/// <param name="v">����</param>
		static void timer(int v);

		/// <summary>
		/// ���s�֐�
		/// </summary>
		static std::function<void(int)> func;

		/// <summary>
		/// ���s�Ԋu
		/// </summary>
		static unsigned int time;
		/// <summary>
		/// ���s������
		/// </summary>
		static int value;

	};

}
