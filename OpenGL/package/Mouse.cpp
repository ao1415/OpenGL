#include "Mouse.hpp"

namespace opc {

	bool Mouse::pressed;
	int Mouse::pressedButton;

	bool Mouse::moved;

	IntPoint Mouse::clickPos;
	IntPoint Mouse::motionPos;
	IntPoint Mouse::previousPos;

	std::function<void(int, int, int, int)> Mouse::mouseFunc;
	std::function<void()> Mouse::motionFunc;

	Mouse::Mouse() {}
	Mouse::Mouse(std::function<void(int, int, int, int)> _mouse, std::function<void()> _motion) {
		mouseFunc = _mouse;
		motionFunc = _motion;
	}

	void Mouse::setMouse(std::function<void(int, int, int, int)> _mouse) {
		mouseFunc = _mouse;
	}
	void Mouse::setMotion(std::function<void()> _motion) {
		motionFunc = _motion;
	}

	void Mouse::mouse(int btn, int state, int x, int y) {
		if (state == GLUT_DOWN)
		{
			pressedButton = btn;
			clickPos = IntPoint(x, y);
			motionPos = clickPos;
			previousPos = clickPos;
			pressed = true;
		}
		else
			pressed = false;

		if (mouseFunc)
			mouseFunc(btn, state, x, y);

	}

	void Mouse::motion(int x, int y) {
		previousPos = motionPos;
		motionPos = IntPoint(x, y);
		//std::cout << motionPos - previousPos << std::endl;

		if (motionFunc)
			motionFunc();
	}

}
