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
		Property_Get(bool, mouseR_Click) const {
			return (pressed && pressedButton == GLUT_RIGHT_BUTTON);
		}

		Property_Get(IntPoint, ClickPos) const {
			return clickPos;
		}
		Property_Get(IntPoint, MotionPos) const {
			return motionPos;
		}
		Property_Get(IntPoint, PreviousPos) const {
			return previousPos;
		}

		friend System;

	private:

		/// <summary>キーが押されているか</summary>
		static bool pressed;
		/// <summary>押されているキー</summary>
		static int pressedButton;

		/// <summary>カーソルが動いたか</summary>
		static bool moved;

		/// <summary>クリックした座標</summary>
		static IntPoint clickPos;
		/// <summary>ドラッグした座標</summary>
		static IntPoint motionPos;
		/// <summary>直前の座標</summary>
		static IntPoint previousPos;

		static void mouse(int btn, int state, int x, int y);
		static void motion(int x, int y);

	};

}
