#pragma once

#include "GL/glut.h"
#include "Point.hpp"
#include "Size.hpp"
#include "Property.hpp"

#include <functional>

namespace opc {

	class System;

	class Mouse {
	public:
		Mouse();

		Property_Get(bool, mouseL_Click) const {
			return (pressed && pressedButton == GLUT_LEFT_BUTTON);
		}
		Property_Get(bool, mouseR_Click) const {
			return (pressed && pressedButton == GLUT_RIGHT_BUTTON);
		}

		Property_Get(Point, ClickPos) const {
			return clickPos;
		}
		Property_Get(Point, MotionPos) const {
			return motionPos;
		}
		Property_Get(Point, PreviousPos) const {
			return previousPos;
		}

	private:

		/// <summary>キーが押されているか</summary>
		static bool pressed;
		/// <summary>押されているキー</summary>
		static int pressedButton;

		/// <summary>カーソルが動いたか</summary>
		static bool moved;

		/// <summary>クリックした座標</summary>
		static Point clickPos;
		/// <summary>ドラッグした座標</summary>
		static Point motionPos;
		/// <summary>直前の座標</summary>
		static Point previousPos;

		static std::function<void(int, int, int, int)> mouseFunc;
		static std::function<void()> motionFunc;

		friend System;

		Mouse(std::function<void(int, int, int, int)> _mouse, std::function<void()> _motion);

		static void setMouse(std::function<void(int, int, int, int)> _mouse);
		static void setMotion(std::function<void()> _motion);

		static void mouse(int btn, int state, int x, int y);
		static void motion(int x, int y);


	};

}
