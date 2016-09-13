#include "Display.hpp"

namespace opc {

	std::function<void()> Display::func;

	Display::Display() {}
	Display::Display(std::function<void()> _func) {
		func = _func;
	}

	void Display::display() {
		glClear(GL_COLOR_BUFFER_BIT);

		func();

		glutSwapBuffers();
	}

}
