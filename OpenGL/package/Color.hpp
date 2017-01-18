#pragma once

#include <GL/glut.h>
#include <iostream>

namespace opc {

	typedef unsigned char byte;

	/// <summary>
	/// �F�������N���X
	/// </summary>
	struct Color {

		/// <summary>
		///	�R���X�g���N�^
		///	</summary>
		Color();
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="_r">��</param>
		/// <param name="_g">��</param>
		/// <param name="_b">��</param>
		Color(const int _r, const int _g, const int _b);
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="_r">��</param>
		/// <param name="_g">��</param>
		/// <param name="_b">��</param>
		/// <param name="_a">�����x</param>
		Color(const int _r, const int _g, const int _b, const int _a);
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="code">�J���[�R�[�h(0xRRGGBB)</param>
		Color(unsigned int code);
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="code">�J���[�R�[�h(0xRRGGBB)</param>
		/// <param name="alpha">�����x</param>
		Color(unsigned int code, const int alpha);
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="_c"><see cref="Color"/>�N���X</param>
		/// <param name="_a">�����x</param>
		Color(const Color& _c, const int _a);

		/// <summary>
		/// ��
		/// </summary>
		byte r = 0;
		/// <summary>
		/// ��
		/// </summary>
		byte g = 0;
		/// <summary>
		/// ��
		/// </summary>
		byte b = 0;
		/// <summary>
		/// �����x
		/// </summary>
		byte a = 0;
	};

	/// <summary><see cref="Color"/>�̏o�̓X�g���[���p�I�[�o�[���[�h</summary>
	/// <param name="os">�o�̓X�g���[��</param>
	/// <param name="v">�o��<see cref="Color"/></param>
	/// <returns></returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Color& v) {
		return os << CharType('(') << (int)v.r << CharType(',') << (int)v.g << CharType(',') << (int)v.b << CharType(',') << (int)v.a << CharType(')');
	}

	/// <summary>
	/// OpenGL�̐F��ݒ肷��֐�
	/// </summary>
	namespace Paint {
		///	<summary></summary>
		///	<param name="c">�F</param>
		///	<param name="alpha">alpha�l���g�p���邩 true:�g�p����, false:�g�p���Ȃ�</param>
		void Color(const opc::Color& c, const bool alpha = true);
		///	<summary></summary>
		///	<param name="r">��</param>
		///	<param name="g">��</param>
		///	<param name="b">��</param>
		void Color(const byte r, const byte g, const byte b);
		///	<summary></summary>
		///	<param name="r">��</param>
		///	<param name="g">��</param>
		///	<param name="b">��</param>
		///	<param name="a">�����x</param>
		void Color(const byte r, const byte g, const byte b, const byte a);
		///	<summary></summary>
		///	<param name="r">��</param>
		///	<param name="g">��</param>
		///	<param name="b">��</param>
		void Color(const float r, const float g, const float b);
		///	<summary></summary>
		///	<param name="r">��</param>
		///	<param name="g">��</param>
		///	<param name="b">��</param>
		///	<param name="a">�����x</param>
		void Color(const float r, const float g, const float b, const float a);
		///	<summary></summary>
		///	<param name="r">��</param>
		///	<param name="g">��</param>
		///	<param name="b">��</param>
		void Color(const double r, const double g, const double b);
		///	<summary></summary>
		///	<param name="r">��</param>
		///	<param name="g">��</param>
		///	<param name="b">��</param>
		///	<param name="a">�����x</param>
		void Color(const double r, const double g, const double b, const double a);
	}

}
