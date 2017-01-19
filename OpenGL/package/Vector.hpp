#pragma once

#include <iostream>

namespace opc {

	/// <summary>
	/// 3D�̐������W
	/// </summary>
	struct Point3D {

		/// <summary>
		///	�R���X�g���N�^
		///	</summary>
		Point3D();
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="_x">x���W</param>
		/// <param name="_y">y���W</param>
		/// <param name="_z">z���W</param>
		Point3D(const int _x, const int _y, const int _z);

		/// <summary>
		///	x���W
		///	</summary>
		int x = 0;
		/// <summary>
		///	y���W
		///	</summary>
		int y = 0;
		/// <summary>
		///	z���W
		///	</summary>
		int z = 0;

		/// <summary>+���Z�q</summary>
		/// <param name="p">���Z����<see cref="Point3D"></param>
		/// <returns>���Z���ꂽ<see cref="Point3D"></returns>
		const Point3D operator+(const Point3D& p) const;
		/// <summary>-���Z�q</summary>
		/// <param name="p">���Z����<see cref="Point3D"></param>
		/// <returns>���Z���ꂽ<see cref="Point3D"></returns>
		const Point3D operator-(const Point3D& p) const;

		/// <summary>*���Z�q</summary>
		/// <param name="p">��Z����W��</param>
		/// <returns>��Z���ꂽ<see cref="Point3D"></returns>
		const Point3D operator*(const int v) const;
		/// <summary>/���Z�q</summary>
		/// <param name="p">���Z����W��</param>
		/// <returns>���Z���ꂽ<see cref="Point3D"></returns>
		const Point3D operator/(const int v) const;

		/// <summary>+=���Z�q</summary>
		/// <param name="p">���Z����<see cref="Point3D"></param>
		void operator+=(const Point3D& p);
		/// <summary>-=���Z�q</summary>
		/// <param name="p">���Z����<see cref="Point3D"></param>
		void operator-=(const Point3D& p);

		/// <summary>*=���Z�q</summary>
		/// <param name="p">��Z����W��</param>
		void operator*=(const int v);
		/// <summary>/=���Z�q</summary>
		/// <param name="p">���Z����W��</param>
		void operator/=(const int v);

	};


	/// <summary><see cref="Color"/>�o�̓X�g���[����<see cref="Point3D"/>��n��</summary>
	/// <param name="os">�o�̓X�g���[��</param>
	/// <param name="v">�o��<see cref="Point3D"/></param>
	/// <returns>�n������̃X�g���[��</returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Point3D& v) {
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(',') << v.z << CharType(')');
	}


	/// <summary>
	/// 3D�̎������W
	/// </summary>
	struct Vec3 {

		/// <summary>
		///	�R���X�g���N�^
		///	</summary>
		Vec3();
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="_x">x���W</param>
		/// <param name="_y">y���W</param>
		/// <param name="_z">z���W</param>
		Vec3(const double _x, const double _y, const double _z);

		/// <summary>
		///	x���W
		///	</summary>
		double x = 0;
		/// <summary>
		///	y���W
		///	</summary>
		double y = 0;
		/// <summary>
		///	z���W
		///	</summary>
		double z = 0;

		/// <summary>+���Z�q</summary>
		/// <param name="p">���Z����<see cref="Vec3"></param>
		/// <returns>���Z���ꂽ<see cref="Vec3"></returns>
		const Vec3 operator+(const Vec3& p) const;
		/// <summary>-���Z�q</summary>
		/// <param name="p">���Z����<see cref="Vec3"></param>
		/// <returns>���Z���ꂽ<see cref="Vec3"></returns>
		const Vec3 operator-(const Vec3& p) const;

		/// <summary>*���Z�q</summary>
		/// <param name="p">��Z����W��</param>
		/// <returns>��Z���ꂽ<see cref="Vec3"></returns>
		const Vec3 operator*(const double v) const;
		/// <summary>/���Z�q</summary>
		/// <param name="p">���Z����W��</param>
		/// <returns>���Z���ꂽ<see cref="Vec3"></returns>
		const Vec3 operator/(const double v) const;

		/// <summary>+=���Z�q</summary>
		/// <param name="p">���Z����<see cref="Vec3"></param>
		void operator+=(const Vec3& p);
		/// <summary>-=���Z�q</summary>
		/// <param name="p">���Z����<see cref="Vec3"></param>
		void operator-=(const Vec3& p);

		/// <summary>*=���Z�q</summary>
		/// <param name="p">��Z����W��</param>
		void operator*=(const double v);
		/// <summary>/=���Z�q</summary>
		/// <param name="p">���Z����W��</param>
		void operator/=(const double v);

		/// <summary>�R�s�[���Z�q</summary>
		/// <param name="p">�R�s�[����<see cref="Point3D"></param>
		void operator=(const Point3D& p);

		/// <summary>�����ɐ؂�̂Ă��l��Ԃ�</summary>
		/// <return><see cref="Point3D"></return>
		const Point3D integer() const;

	};

	/// <summary><see cref="Color"/>�o�̓X�g���[����<see cref="Vec3"/>��n��</summary>
	/// <param name="os">�o�̓X�g���[��</param>
	/// <param name="v">�o��<see cref="Vec3"/></param>
	/// <returns>�n������̃X�g���[��</returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Vec3& v) {
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(',') << v.z << CharType(')');
	}

	/// <summary>+���Z�q</summary>
	/// <param name="v1"><see cref="Point3D"/></param>
	/// <param name="v2"><see cref="Vec3"/></param>
	/// <returns>���Z�������<see cref="Vec3"/></returns>
	const Vec3 operator+(const Point3D& v1, const Vec3& v2);
	/// <summary>+���Z�q</summary>
	/// <param name="v1"><see cref="Vec3"/></param>
	/// <param name="v2"><see cref="Point3D"/></param>
	/// <returns>���Z�������<see cref="Vec3"/></returns>
	const Vec3 operator+(const Vec3& v1, const Point3D& v2);

}
