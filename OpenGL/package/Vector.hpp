#pragma once

#include <iostream>

namespace opc {

	/// <summary>
	/// 3Dの整数座標
	/// </summary>
	struct Point3D {

		/// <summary>
		///	コンストラクタ
		///	</summary>
		Point3D();
		/// <summary>コンストラクタ</summary>
		/// <param name="_x">x座標</param>
		/// <param name="_y">y座標</param>
		/// <param name="_z">z座標</param>
		Point3D(const int _x, const int _y, const int _z);

		/// <summary>
		///	x座標
		///	</summary>
		int x = 0;
		/// <summary>
		///	y座標
		///	</summary>
		int y = 0;
		/// <summary>
		///	z座標
		///	</summary>
		int z = 0;

		/// <summary>+演算子</summary>
		/// <param name="p">加算する<see cref="Point3D"></param>
		/// <returns>加算された<see cref="Point3D"></returns>
		const Point3D operator+(const Point3D& p) const;
		/// <summary>-演算子</summary>
		/// <param name="p">減算する<see cref="Point3D"></param>
		/// <returns>減算された<see cref="Point3D"></returns>
		const Point3D operator-(const Point3D& p) const;

		/// <summary>*演算子</summary>
		/// <param name="p">乗算する係数</param>
		/// <returns>乗算された<see cref="Point3D"></returns>
		const Point3D operator*(const int v) const;
		/// <summary>/演算子</summary>
		/// <param name="p">除算する係数</param>
		/// <returns>除算された<see cref="Point3D"></returns>
		const Point3D operator/(const int v) const;

		/// <summary>+=演算子</summary>
		/// <param name="p">加算する<see cref="Point3D"></param>
		void operator+=(const Point3D& p);
		/// <summary>-=演算子</summary>
		/// <param name="p">減算する<see cref="Point3D"></param>
		void operator-=(const Point3D& p);

		/// <summary>*=演算子</summary>
		/// <param name="p">乗算する係数</param>
		void operator*=(const int v);
		/// <summary>/=演算子</summary>
		/// <param name="p">除算する係数</param>
		void operator/=(const int v);

	};


	/// <summary><see cref="Color"/>出力ストリームに<see cref="Point3D"/>を渡す</summary>
	/// <param name="os">出力ストリーム</param>
	/// <param name="v">出力<see cref="Point3D"/></param>
	/// <returns>渡した後のストリーム</returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Point3D& v) {
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(',') << v.z << CharType(')');
	}


	/// <summary>
	/// 3Dの実数座標
	/// </summary>
	struct Vec3 {

		/// <summary>
		///	コンストラクタ
		///	</summary>
		Vec3();
		/// <summary>コンストラクタ</summary>
		/// <param name="_x">x座標</param>
		/// <param name="_y">y座標</param>
		/// <param name="_z">z座標</param>
		Vec3(const double _x, const double _y, const double _z);

		/// <summary>
		///	x座標
		///	</summary>
		double x = 0;
		/// <summary>
		///	y座標
		///	</summary>
		double y = 0;
		/// <summary>
		///	z座標
		///	</summary>
		double z = 0;

		/// <summary>+演算子</summary>
		/// <param name="p">加算する<see cref="Vec3"></param>
		/// <returns>加算された<see cref="Vec3"></returns>
		const Vec3 operator+(const Vec3& p) const;
		/// <summary>-演算子</summary>
		/// <param name="p">減算する<see cref="Vec3"></param>
		/// <returns>減算された<see cref="Vec3"></returns>
		const Vec3 operator-(const Vec3& p) const;

		/// <summary>*演算子</summary>
		/// <param name="p">乗算する係数</param>
		/// <returns>乗算された<see cref="Vec3"></returns>
		const Vec3 operator*(const double v) const;
		/// <summary>/演算子</summary>
		/// <param name="p">除算する係数</param>
		/// <returns>除算された<see cref="Vec3"></returns>
		const Vec3 operator/(const double v) const;

		/// <summary>+=演算子</summary>
		/// <param name="p">加算する<see cref="Vec3"></param>
		void operator+=(const Vec3& p);
		/// <summary>-=演算子</summary>
		/// <param name="p">減算する<see cref="Vec3"></param>
		void operator-=(const Vec3& p);

		/// <summary>*=演算子</summary>
		/// <param name="p">乗算する係数</param>
		void operator*=(const double v);
		/// <summary>/=演算子</summary>
		/// <param name="p">除算する係数</param>
		void operator/=(const double v);

		/// <summary>コピー演算子</summary>
		/// <param name="p">コピーする<see cref="Point3D"></param>
		void operator=(const Point3D& p);

		/// <summary>整数に切り捨てた値を返す</summary>
		/// <return><see cref="Point3D"></return>
		const Point3D integer() const;

	};

	/// <summary><see cref="Color"/>出力ストリームに<see cref="Vec3"/>を渡す</summary>
	/// <param name="os">出力ストリーム</param>
	/// <param name="v">出力<see cref="Vec3"/></param>
	/// <returns>渡した後のストリーム</returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Vec3& v) {
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(',') << v.z << CharType(')');
	}

	/// <summary>+演算子</summary>
	/// <param name="v1"><see cref="Point3D"/></param>
	/// <param name="v2"><see cref="Vec3"/></param>
	/// <returns>加算した後の<see cref="Vec3"/></returns>
	const Vec3 operator+(const Point3D& v1, const Vec3& v2);
	/// <summary>+演算子</summary>
	/// <param name="v1"><see cref="Vec3"/></param>
	/// <param name="v2"><see cref="Point3D"/></param>
	/// <returns>加算した後の<see cref="Vec3"/></returns>
	const Vec3 operator+(const Vec3& v1, const Point3D& v2);

}
