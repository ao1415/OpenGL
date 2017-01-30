#pragma once

#include "Color.hpp"

namespace opc {

	/// <summary>
	/// �F�������N���X
	/// </summary>
	struct HSV {

		/// <summary>
		///	�R���X�g���N�^
		///	</summary>
		HSV();
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="_h">�F��</param>
		/// <param name="_s">�ʓx</param>
		/// <param name="_v">���x</param>
		HSV(const double _h, const double _s, const double _v);
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="_c"><see cref="Color"/>�N���X</param>
		HSV(const Color c);

		///	<summary>
		/// RGB�ɕϊ�����
		/// </summary>
		const Color toRGB() const;

		/// <summary>
		/// �F��
		/// </summary>
		double h;
		/// <summary>
		/// �ʓx
		/// </summary>
		double s;
		/// <summary>
		/// ���x
		/// </summary>
		double v;

	};

	/// <summary><see cref="Color"/>�o�̓X�g���[����<see cref="Color"/>��n��</summary>
	/// <param name="os">�o�̓X�g���[��</param>
	/// <param name="v">�o��<see cref="Color"/></param>
	/// <returns>�n������̃X�g���[��</returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const HSV& v) {
		return os << CharType('(') << v.h << CharType(',') << v.s << CharType(',') << v.v << CharType(')');
	}

}
