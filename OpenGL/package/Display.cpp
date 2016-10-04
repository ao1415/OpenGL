#include "Display.hpp"

namespace opc {

	std::function<void()> Display::func;
	unsigned int Display::clearMode;

	Display::Display() {}
	Display::Display(std::function<void()> _func) {
		func = _func;
	}

	void Display::display() {
		glClear(clearMode);

		func();

		glutSwapBuffers();
	}

}
