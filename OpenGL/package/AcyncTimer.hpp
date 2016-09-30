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

		AcyncTimer();
		AcyncTimer(std::function<void(int)> _func);

		static void timer(int v);

		static std::function<void(int)> func;

		static unsigned int time;
		static int value;

	};

}
