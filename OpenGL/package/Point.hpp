#pragma once

#include <iostream>

namespace opc {

	/// <summary>
	/// �����̍��W�������N���X
	/// </summary>
	struct Point {

		/// <summary>
		///	�R���X�g���N�^
		///	</summary>
		Point();
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="_x">x���W</param>
		/// <param name="_y">y���W</param>
		Point(const int _x, const int _y);

		/// <summary>
		///	x���W
		///	</summary>
		int x = 0;
		/// <summary>
		///	y���W
		///	</summary>
		int y = 0;

		/// <summary>+���Z�q</summary>
		/// <param name="p">���Z����<see cref="Point"></param>
		/// <returns>���Z���ꂽ<see cref="Point"></returns>
		const Point operator+(const Point& p) const;
		/// <summary>-���Z�q</summary>
		/// <param name="p">���Z����<see cref="Point"></param>
		/// <returns>���Z���ꂽ<see cref="Point"></returns>
		const Point operator-(const Point& p) const;

		/// <summary>*���Z�q</summary>
		/// <param name="p">��Z����W��</param>
		/// <returns>��Z���ꂽ<see cref="Point"></returns>
		const Point operator*(const int v) const;
		/// <summary>/���Z�q</summary>
		/// <param name="p">���Z����W��</param>
		/// <returns>���Z���ꂽ<see cref="Point"></returns>
		const Point operator/(const int v) const;

		/// <summary>+=���Z�q</summary>
		/// <param name="p">���Z����<see cref="Point"></param>
		void operator+=(const Point& p);
		/// <summary>-=���Z�q</summary>
		/// <param name="p">���Z����<see cref="Point"></param>
		void operator-=(const Point& p);

		/// <summary>*=���Z�q</summary>
		/// <param name="p">��Z����W��</param>
		void operator*=(const int v);
		/// <summary>/=���Z�q</summary>
		/// <param name="p">���Z����W��</param>
		void operator/=(const int v);

	};

	/// <summary><see cref="Color"/>�o�̓X�g���[����<see cref="Point"/>��n��</summary>
	/// <param name="os">�o�̓X�g���[��</param>
	/// <param name="v">�o��<see cref="Point"/></param>
	/// <returns>�n������̃X�g���[��</returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Point& v) {
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(')');
	}

	/// <summary>
	/// �����̍��W�������N���X
	/// </summary>
	struct Vec2 {

		/// <summary>
		///	�R���X�g���N�^
		///	</summary>
		Vec2();
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="_x">x���W</param>
		/// <param name="_y">y���W</param>
		Vec2(const double _x, const double _y);

		/// <summary>
		///	x���W
		///	</summary>
		double x = 0;
		/// <summary>
		///	y���W
		///	</summary>
		double y = 0;

		/// <summary>+���Z�q</summary>
		/// <param name="p">���Z����<see cref="Vec2"></param>
		/// <returns>���Z���ꂽ<see cref="Vec2"></returns>
		const Vec2 operator+(const Vec2& p) const;
		/// <summary>-���Z�q</summary>
		/// <param name="p">���Z����<see cref="Vec2"></param>
		/// <returns>���Z���ꂽ<see cref="Vec2"></returns>
		const Vec2 operator-(const Vec2& p) const;

		/// <summary>*���Z�q</summary>
		/// <param name="p">��Z����W��</param>
		/// <returns>��Z���ꂽ<see cref="Vec2"></returns>
		const Vec2 operator*(const int v) const;
		/// <summary>/���Z�q</summary>
		/// <param name="p">���Z����W��</param>
		/// <returns>���Z���ꂽ<see cref="Vec2"></returns>
		const Vec2 operator/(const int v) const;

		/// <summary>+=���Z�q</summary>
		/// <param name="p">���Z����<see cref="Vec2"></param>
		void operator+=(const Vec2& p);
		/// <summary>-=���Z�q</summary>
		/// <param name="p">���Z����<see cref="Vec2"></param>
		void operator-=(const Vec2& p);

		/// <summary>*=���Z�q</summary>
		/// <param name="p">��Z����W��</param>
		void operator*=(const int v);
		/// <summary>/=���Z�q</summary>
		/// <param name="p">���Z����W��</param>
		void operator/=(const int v);

		/// <summary>�R�s�[���Z�q</summary>
		/// <param name="p">�R�s�[����<see cref="Point"></param>
		void operator=(const Point& p);

		/// <summary>�����ɐ؂�̂Ă��l��Ԃ�</summary>
		/// <return><see cref="Point"></return>
		const Point integer() const;

	};

	/// <summary><see cref="Color"/>�o�̓X�g���[����<see cref="Vec2"/>��n��</summary>
	/// <param name="os">�o�̓X�g���[��</param>
	/// <param name="v">�o��<see cref="Vec2"/></param>
	/// <returns>�n������̃X�g���[��</returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Vec2& v) {
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(')');
	}

	/// <summary>+���Z�q</summary>
	/// <param name="v1"><see cref="Point"/></param>
	/// <param name="v2"><see cref="Vec2"/></param>
	/// <returns>���Z�������<see cref="Vec2"/></returns>
	const Vec2 operator+(const Point& p1, const Vec2& p2);
	/// <summary>+���Z�q</summary>
	/// <param name="v1"><see cref="Vec2"/></param>
	/// <param name="v2"><see cref="Point"/></param>
	/// <returns>���Z�������<see cref="Vec2"/></returns>
	const Vec2 operator+(const Vec2& p1, const Point& p2);

}
