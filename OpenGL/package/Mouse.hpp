#pragma once

#include "GL/glut.h"
#include "Point.hpp"
#include "Size.hpp"
#include "Property.hpp"

#include <functional>

namespace opc {

	/// <summary>マウスのボタン</summary>
	enum class MouseButton : unsigned int {
		/// <summary>左クリック</summary>
		Left = GLUT_LEFT_BUTTON,
		/// <summary>中央クリック</summary>
		Middle = GLUT_MIDDLE_BUTTON,
		/// <summary>右クリック</summary>
		Right = GLUT_RIGHT_BUTTON
	};

	/// <summary>ボタンの状態</summary>
	enum class ButtonState : unsigned int {
		/// <summary>押されている</summary>
		Down = GLUT_DOWN,
		/// <summary>離されている</summary>
		Up = GLUT_UP
	};

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

		Property_Get(IntPoint, ClickPos) const {
			return clickPos;
		}
		Property_Get(IntPoint, MotionPos) const {
			return motionPos;
		}
		Property_Get(IntPoint, PreviousPos) const {
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
		static IntPoint clickPos;
		/// <summary>ドラッグした座標</summary>
		static IntPoint motionPos;
		/// <summary>直前の座標</summary>
		static IntPoint previousPos;

		static std::function<void()> mouseFunc;
		static std::function<void()> motionFunc;

		friend System;

		Mouse(std::function<void()> _mouse, std::function<void()> _motion);

		static void setMouse(std::function<void()> _mouse);
		static void setMotion(std::function<void()> _motion);

		static void mouse(int btn, int state, int x, int y);
		static void motion(int x, int y);


	};

}
