#include "Mouse.hpp"

namespace opc {

	bool Mouse::pressed;
	int Mouse::pressedButton;

	bool Mouse::moved;

	IntPoint Mouse::clickPos;
	IntPoint Mouse::motionPos;
	IntPoint Mouse::previousPos;

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
	}

	void Mouse::motion(int x, int y) {
		previousPos = motionPos;
		motionPos = IntPoint(x, y);
		std::cout << motionPos - previousPos << std::endl;
	}

}
