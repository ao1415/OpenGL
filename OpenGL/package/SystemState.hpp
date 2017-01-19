#pragma once

#include "Exception.hpp"

namespace opc {

	class System;
	class Window;

	/// <summary>
	/// �E�C���h�E�X�e�[�^�X�̐ݒ�
	/// </summary>
	class SystemState {
	public:

		/// <summary>
		/// �`�惂�[�h
		/// </summary>
		enum class StandardPoint : unsigned char {
			Mode_2D = 0x01,
			Mode_3D = 0x02,
		};

		/// <summary>�E�C���h�E���쐬���ꂽ����Ԃ�</summary>
		/// <returns>�쐬����Ă�����true, �쐬����Ă��Ȃ�������false</returns>
		inline static const bool getMakeWindow() { return makeWindow; }

		/// <summary>�`�惂�[�h��Ԃ�</summary>
		/// <returns>�`�惂�[�h</returns>
		inline static const unsigned char getStandardPoint() { return standardPoint; }
		/// <summary>�`�惂�[�h��Ԃ�</summary>
		///	<param name="s">�`�惂�[�h</param>
		/// <returns>�w�肳�ꂽ���[�h�Ȃ��true, ����ȊO��false</returns>
		inline static const bool getStandardPoint(const StandardPoint& s) {
			return (standardPoint & (char)s) > 0;
		}

		friend System;
		friend Window;

	private:

		/// <summary>
		///	�E�C���h�E���쐬���ꂽ���̃t���O
		///	</summary>
		static bool makeWindow;

		/// <summary>
		///	���W�̐ݒ�̃t���O
		///	</summary>
		static unsigned char standardPoint;

		/// <summary>�`�惂�[�h�̐ݒ�</summary>
		///	<param name="s">�`�惂�[�h</param>
		inline static void setStandardPoint(const StandardPoint& s) { standardPoint = (char)s; }

	};

}
