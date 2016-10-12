#pragma once

#include "GL/glut.h"
#include "Point.hpp"
#include "Size.hpp"
#include "Property.hpp"

namespace opc {

	class System;

	class Mouse {
	public:

		Property_Get(bool, mouseL_Click) const {
			return (pressed && pressedButton == GLUT_LEFT_BUTTON);
		}
		bool mouseR_Click() const {
			return (pressed && pressedButton == GLUT_RIGHT_BUTTON);
		}

		friend System;

	private:

		/// <summary>キーが押されているか</summary>
		static bool pressed;
		/// <summary>押されているキー</summary>
		static int pressedButton;

		/// <summary>クリックした座標</summary>
		static IntPoint clickPos;
		/// <summary>ドラッグした座標</summary>
		static IntPoint motionPos;

		static void mouse(int btn, int state, int x, int y) {

			if (state == GLUT_DOWN)
			{
				pressedButton = btn;
				clickPos = IntPoint(x, y);
				pressed = true;
			}
			else
			{
				pressed = false;
			}
		}

		static void motion(int x, int y) {

			if (pressed)
			{
				switch (pressedButton)
				{
				case GLUT_LEFT_BUTTON:
				case GLUT_RIGHT_BUTTON:
					motionPos = IntPoint(x, y);
					break;
				}
			}

		}
	};

}
