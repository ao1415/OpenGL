#pragma once

#include <iostream>

namespace opc {

	/// <summary>
	/// �����̑傫��
	/// </summary>
	struct IntSize {

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		IntSize();
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="w">����</param>
		/// <param name="h">�c��</param>
		IntSize(const int w, const int h);

		/// <summary>
		/// ����
		/// </summary>
		int width = 0;
		/// <summary>
		/// �c��
		/// </summary>
		int height = 0;
	};

	/// <summary>
	/// �����̑傫��
	/// </summary>
	struct RealSize {

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		RealSize();
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="w">����</param>
		/// <param name="h">�c��</param>
		RealSize(const double w, const double h);

		/// <summary>
		/// ����
		/// </summary>
		double width = 0;
		/// <summary>
		/// �c��
		/// </summary>
		double height = 0;
	};

	/// <summary><see cref="Color"/>�o�̓X�g���[����<see cref="IntSize"/>��n��</summary>
	/// <param name="os">�o�̓X�g���[��</param>
	/// <param name="v">�o��<see cref="IntSize"/></param>
	/// <returns>�n������̃X�g���[��</returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const IntSize& v) {
		return os << CharType('(') << v.width << CharType(',') << v.height << CharType(')');
	}

	/// <summary><see cref="Color"/>�o�̓X�g���[����<see cref="RealSize"/>��n��</summary>
	/// <param name="os">�o�̓X�g���[��</param>
	/// <param name="v">�o��<see cref="RealSize"/></param>
	/// <returns>�n������̃X�g���[��</returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const RealSize& v) {
		return os << CharType('(') << v.width << CharType(',') << v.height << CharType(')');
	}

}
