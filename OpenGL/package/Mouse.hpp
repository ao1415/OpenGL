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

		/// <summary>�L�[��������Ă��邩</summary>
		static bool pressed;
		/// <summary>������Ă���L�[</summary>
		static int pressedButton;

		/// <summary>�J�[�\������������</summary>
		static bool moved;

		/// <summary>�N���b�N�������W</summary>
		static IntPoint clickPos;
		/// <summary>�h���b�O�������W</summary>
		static IntPoint motionPos;
		/// <summary>���O�̍��W</summary>
		static IntPoint previousPos;

		static void mouse(int btn, int state, int x, int y);
		static void motion(int x, int y);

	};

}
