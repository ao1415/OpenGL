#pragma once

#include <GL/glut.h>
#include <functional>

namespace opc {

	class System;

	/// <summary>
	///	<para>�\���p�̃N���X</para>
	///	<para>�g�p�֎~</para>
	///	</summary>
	class Display {
	private:

		friend System;

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Display();
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="v">���s�֐�</param>
		Display(std::function<void()> _func);

		/// <summary>���s����֐�</summary>
		static void display();

		/// <summary>
		/// ���s�֐�
		/// </summary>
		static std::function<void()> func;
		/// <summary>
		/// ��ʍ폜�̐ݒ�
		/// </summary>
		static unsigned int clearMode;

	};

}
