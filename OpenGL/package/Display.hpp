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

		Display();
		Display(std::function<void()> _func);

		static void display();

		static std::function<void()> func;
		static unsigned int clearMode;

	};

}
