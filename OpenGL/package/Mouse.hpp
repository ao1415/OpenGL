#pragma once

#include "GL/glut.h"
#include "Point.hpp"
#include "Size.hpp"
#include "Property.hpp"

#include <functional>

namespace opc {

	class System;

	/// <summary>
	/// �}�E�X���͂��Ǘ�����N���X
	/// </summary>
	class Mouse {
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Mouse();

		/// <summary>�E�N���b�N���ꂽ����Ԃ�</summary>
		/// <returns>�E�N���b�N����Ă�����true, ����ȊO��false</returns>
		Property_Get(bool, mouseL_Click) const {
			return (pressed && pressedButton == GLUT_LEFT_BUTTON);
		}
		/// <summary>���N���b�N���ꂽ����Ԃ�</summary>
		/// <returns>���N���b�N����Ă�����true, ����ȊO��false</returns>
		Property_Get(bool, mouseR_Click) const {
			return (pressed && pressedButton == GLUT_RIGHT_BUTTON);
		}
		/// <summary>���N���b�N���ꂽ����Ԃ�</summary>
		/// <returns>���N���b�N����Ă�����true, ����ȊO��false</returns>
		Property_Get(bool, mouseM_Click) const {
			return (pressed && pressedButton == GLUT_MIDDLE_BUTTON);
		}

		/// <summary>�N���b�N���ꂽ�ꏊ��Ԃ�</summary>
		/// <returns>�N���b�N���ꂽ�ꏊ</returns>
		Property_Get(Point, ClickPos) const {
			return clickPos;
		}
		/// <summary>�h���b�O���ꂽ�ꏊ��Ԃ�</summary>
		/// <returns>�h���b�O���ꂽ�ꏊ</returns>
		Property_Get(Point, MotionPos) const {
			return motionPos;
		}
		/// <summary>���O�ɃN���b�N���ꂽ�ꏊ��Ԃ�</summary>
		/// <returns>���O�ɃN���b�N���ꂽ�ꏊ</returns>
		Property_Get(Point, PreviousPos) const {
			return previousPos;
		}

	private:

		/// <summary>
		///	�L�[��������Ă��邩
		///	</summary>
		static bool pressed;
		/// <summary>
		///	������Ă���L�[
		///	</summary>
		static int pressedButton;

		/// <summary>
		///	�J�[�\������������
		///	</summary>
		static bool moved;

		/// <summary>
		///	�N���b�N�������W
		///	</summary>
		static Point clickPos;
		/// <summary>
		///	�h���b�O�������W
		///	</summary>
		static Point motionPos;
		/// <summary>
		///	���O�̍��W
		///	</summary>
		static Point previousPos;

		/// <summary>
		/// �}�E�X���͂̎��s�֐�
		/// </summary>
		static std::function<void(int, int, int, int)> mouseFunc;
		/// <summary>
		/// �}�E�X����̎��s�֐�
		/// </summary>
		static std::function<void()> motionFunc;

		friend System;

		/// <summary>�R���X�g���N�^</summary>
		/// <param name="_mouse">���͎��s�֐�</param>
		/// <param name="_motion">������s�֐�</param>
		Mouse(std::function<void(int, int, int, int)> _mouse, std::function<void()> _motion);

		/// <summary>�}�E�X���͂̎��s�֐���ݒ肷��</summary>
		/// <param name="_mouse">���͎��s�֐�</param>
		static void setMouse(std::function<void(int, int, int, int)> _mouse);
		/// <summary>�}�E�X����̎��s�֐���ݒ肷��</summary>
		/// <param name="_motion">������s�֐�</param>
		static void setMotion(std::function<void()> _motion);

		/// <summary>���͎��s����֐�</summary>
		/// <param name="btn">�{�^������</param>
		/// <param name="state">�{�^���̏��</param>
		/// <param name="x">x���W</param>
		/// <param name="y">y���W</param>
		static void mouse(int btn, int state, int x, int y);
		/// <summary>������s����֐�</summary>
		/// <param name="x">x���W</param>
		/// <param name="y">y���W</param>
		static void motion(int x, int y);

	};

}
