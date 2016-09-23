#pragma once

#include <string>

#include "Display.hpp"
#include "AcyncTimer.hpp"
#include "Point.hpp"
#include "Size.hpp"
#include "Palette.hpp"

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

		/// <summary>�E�C���h�E�̑傫����ݒ肷��</summary>
		/// <param name="width">����</param>
		/// <param name="height">����</param>
		void setSize(const int width, const int height);
		/// <summary>�E�C���h�E�̑傫����ݒ肷��</summary>
		/// <param name="_size">�傫��</param>
		void setSize(const Size& _size);

		/// <summary>�E�C���h�E�̃^�C�g����ݒ肷��</summary>
		/// <param name="name">�^�C�g��</param>
		void setTitle(const std::string& name);

		/// <summary>��ʂ��N���A�����Ƃ��̐F��ݒ肷��</summary>
		/// <param name="r">�ԐF����(0�`255)</param>
		/// <param name="g">�ΐF����(0�`255)</param>
		/// <param name="b">�F����(0�`255)</param>
		void setClearColor(const int r, const int g, const int b);
		/// <summary>��ʂ��N���A�����Ƃ��̐F��ݒ肷��</summary>
		/// <param name="r">�ԐF����(0�`255)</param>
		/// <param name="g">�ΐF����(0�`255)</param>
		/// <param name="b">�F����(0�`255)</param>
		/// <param name="a">�����x(0�`255)</param>
		void setClearColor(const int r, const int g, const int b, const int a);
		/// <summary>��ʂ��N���A�����Ƃ��̐F��ݒ肷��</summary>
		/// <param name="_color">�F</param>
		void setClearColor(const Color& _color);

		/// <summary>�E�C���h�E�̍��W��ݒ肷��</summary>
		/// <param name="left">���[�̍��W�l</param>
		/// <param name="right">�E�[�̍��W�l</param>
		/// <param name="bottom">���[�̍��W�l</param>
		/// <param name="top">��[�̍��W�l</param>
		void setOrtho2D(const double left, const double right, const double bottom, const double top);
		/// <summary>�E�C���h�E�̍��W��ݒ肷��</summary>
		/// <param name="left_top">����̍��W�l</param>
		/// <param name="right_bottom">�E���̍��W�l</param>
		void setOrtho2D(const RealPoint& left_top, const RealPoint& right_bottom);

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

		Size size;
		std::string title;
		Color clearColor;

		unsigned int displayMode;

		/// <summary>
		/// <para>0:�E��̍��W</para>
		/// <para>1:�����̍��W</para>
		/// </summary>
		RealPoint ortho2DPoint[2];

		std::function<void()> displayFunction;
		std::function<void(int)> timerFunction;


		/// <summary>�����ݒ�</summary>
		void init() {
			size = Size(640, 480);
			title = "OpenGL";
			clearColor = Palette::Black;

			displayMode = GLUT_RGBA | GLUT_DOUBLE;

			ortho2DPoint[0] = IntPoint(0, 0);
			ortho2DPoint[1] = IntPoint(640, 480);

			AcyncTimer::time = 16;
			AcyncTimer::value = 0;

		}

	};

}
