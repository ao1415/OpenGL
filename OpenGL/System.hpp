#pragma once

#include "Window.hpp"

namespace opc {

	/// <summary>
	///	<para>OpenGL���p�b�P�[�W�����N���X</para>
	///	<para>�e�평���ݒ���s������ɁAwindowCreate�����s���Ă�������</para>
	///	</summary>
	class System {
	public:

		/// <summary>�e��ݒ�̏�����</summary>
		System();
		/// <summary>�e��ݒ�̏�����</summary>
		/// <param name="argc">argv�̗v�f��</param>
		/// <param name="argv">������̔z��</param>
		System(int argc, char *argv[]);

		/// <summary>
		///	<para>�E�C���h�E�̍쐬�E�ݒ肳�ꂽ�v���O�����̎��s���s��</para>
		///	<para>���s��͊e��ݒ�̕ύX�͍s���܂���</para>
		///	</summary>
		void create();

		/// <summary>�f�B�X�v���C���[�h�̐ݒ�</summary>
		/// <param name="mode">�f�B�X�v���C���[�h�̃t���O</param>
		void setDisplayMode(const unsigned int mode);

		/// <summary>�`��֐���ݒ肷��</summary>
		/// <param name="func">�`�悷��֐��|�C���^</param>
		void setDisplayFunc(std::function<void()> func);

		/// <summary>
		///	<para>time�ɐݒ肳�ꂽ���Ԗ��ɁA�ݒ肳�ꂽ�֐������s����</para>
		///	<para>�����F�֐�����glutTimerFunc�����s���Ȃ��ł�������</para>
		///	</summary>
		/// <param name="time">���s����Ԋu(ms)</param>
		/// <param name="func">���s����֐�</param>
		/// <param name="value">���s����֐��̈���</param>
		void setTimerFunc(unsigned int time, std::function<void(int)> func, int value);

	private:

		unsigned int displayMode;

		std::function<void()> displayFunction;
		std::function<void(int)> timerFunction;


		/// <summary>�����ݒ�</summary>
		void init() {
			Window::size = Size(640, 480);
			Window::title = "OpenGL";
			Window::clearColor = Palette::Black;

			displayMode = GLUT_RGBA | GLUT_DOUBLE;

			//Window::ortho2DPoint[0] = IntPoint(0, 0);
			//Window::ortho2DPoint[1] = IntPoint(640, 480);

			AcyncTimer::time = 16;
			AcyncTimer::value = 0;

		}

	};

}
