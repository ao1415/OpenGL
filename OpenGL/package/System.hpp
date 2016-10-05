#pragma once

#include "Window.hpp"
#include "Grid.hpp"
#include "Matrix.hpp"
#include "Bitmap.hpp"

namespace opc {

	/// <summary>�f�B�X�v���C�̐ݒ�R�}���h</summary>
	enum class DisplayMode : unsigned int {
		/// <summary>RGBA���[�h</summary>
		RGBA = GLUT_RGBA,
		/// <summary>RGB���[�h</summary>
		RGB = GLUT_RGB,
		/// <summary>�J���[�C���f�b�N�X���[�h</summary>
		Index = GLUT_INDEX,
		/// <summary>�V���O���o�b�t�@���[�h</summary>
		Single = GLUT_SINGLE,
		/// <summary>�_�u���o�b�t�@���[�h</summary>
		Double = GLUT_DOUBLE,
		/// <summary>�A�L�������[�V�����o�b�t�@</summary>
		Accum = GLUT_ACCUM,
		/// <summary>�J���[�o�b�t�@�ɃA���t�@������������</summary>
		Alpha = GLUT_ALPHA,
		/// <summary>�f�B�v�X(Z)�o�b�t�@��������</summary>
		Depth = GLUT_DEPTH,
		/// <summary>�}���`�T���v�����O�̃T�|�[�g</summary>
		Stencil = GLUT_STENCIL,
		/// <summary></summary>
		MultiSample = GLUT_MULTISAMPLE,
		/// <summary>�X�e���I�E�E�C���h�E�r�b�g�}�X�N</summary>
		Stereo = GLUT_STEREO
	};

	/// <summary>�N���A�o�b�t�@�̐ݒ�R�}���h</summary>
	enum class ClearMode : unsigned int {
		/// <summary>�F</summary>
		Color = GL_COLOR_BUFFER_BIT,
		/// <summary>�[�x</summary>
		Depth = GL_DEPTH_BUFFER_BIT,
		Accum = GL_ACCUM_BUFFER_BIT,
		Stencil = GL_STENCIL_BUFFER_BIT
	};

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
		///	<para>�E�C���h�E�̍쐬</para>
		///	<para>���s��͊e��ݒ�̕ύX�͍s���܂���</para>
		///	</summary>
		void create();

		/// <summary>�ݒ肳�ꂽ�v���O���������s���܂�</summary>
		void update();

		/// <summary>�f�B�X�v���C���[�h�̐ݒ�</summary>
		/// <param name="mode">�f�B�X�v���C���[�h�̃t���O</param>
		void setDisplayMode(const unsigned int mode);
		/// <summary>�f�B�X�v���C���[�h�̐ݒ�</summary>
		/// <param name="...rest">DisplayMode</param>
		template<typename... Rest>
		void setDisplayMode(const Rest&... rest) {
			if (SystemState::getMakeWindow())
				throw SettingErrer("�f�B�X�v���C���[�h��ύX�ł��܂���ł���");
			displayMode = orFlag(rest...);
		}

		/// <summary>�o�b�t�@�N���A�̐ݒ�</summary>
		/// <param name="mode">�o�b�t�@�N���A�̃t���O</param>
		void setClearMode(const unsigned int mode);
		/// <summary>�o�b�t�@�N���A�̐ݒ�</summary>
		/// <param name="...rest">ClearMode</param>
		template<typename... Rest>
		void setClearMode(const Rest&... rest) {
			if (SystemState::getMakeWindow())
				throw SettingErrer("�N���A���[�h��ύX�ł��܂���ł���");
			clearMode = orFlag(rest...);
		}

		/// <summary>
		/// <para>�ݒ��L���ɂ��܂�</para>
		///	<para>�ڍ�:https://www.opengl.org/sdk/docs/man2/xhtml/glEnable.xml</para>
		/// </summary>
		/// <param name="mode">cap</param>
		void enable(const unsigned int mode);
		/// <summary>
		/// <para>�ݒ�𖳌��ɂ��܂�</para>
		///	<para>�ڍ�:https://www.opengl.org/sdk/docs/man2/xhtml/glEnable.xml</para>
		/// </summary>
		/// <param name="mode">cap</param>
		void disable(const unsigned int mode);

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
		unsigned int clearMode;

		std::vector<unsigned int> enableConfig;
		std::vector<unsigned int> disableConfig;

		std::function<void()> displayFunction;
		std::function<void(int)> timerFunction;


		/// <summary>�����ݒ�</summary>
		void init() {

			Window::setSize(IntSize(640, 480));
			Window::setTitle("OpenGL");
			Window::setClearColor(Palette::Black);
			setDisplayMode(DisplayMode::RGBA, DisplayMode::Double);

			AcyncTimer::time = 16;
			AcyncTimer::value = 0;

		}

		template<typename First, typename... Rest>
		const unsigned int orFlag(const First& first, const Rest&... rest) {
			return (unsigned int)first | orFlag(rest...);
		}
		inline const unsigned int orFlag() {
			return 0;
		}

	};

}
