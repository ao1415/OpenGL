#pragma once

#include <iostream>

namespace opc {

	/// <summary>
	/// 整数の座標を扱うクラス
	/// </summary>
	struct Point {

		/// <summary>
		///	コンストラクタ
		///	</summary>
		Point();
		/// <summary>コンストラクタ</summary>
		/// <param name="_x">x座標</param>
		/// <param name="_y">y座標</param>
		Point(const int _x, const int _y);

		/// <summary>
		///	x座標
		///	</summary>
		int x = 0;
		/// <summary>
		///	y座標
		///	</summary>
		int y = 0;

		/// <summary>+演算子</summary>
		/// <param name="p">加算する<see cref="Point"></param>
		/// <returns>加算された<see cref="Point"></returns>
		const Point operator+(const Point& p) const;
		/// <summary>-演算子</summary>
		/// <param name="p">減算する<see cref="Point"></param>
		/// <returns>減算された<see cref="Point"></returns>
		const Point operator-(const Point& p) const;

		/// <summary>*演算子</summary>
		/// <param name="p">乗算する係数</param>
		/// <returns>乗算された<see cref="Point"></returns>
		const Point operator*(const int v) const;
		/// <summary>/演算子</summary>
		/// <param name="p">除算する係数</param>
		/// <returns>除算された<see cref="Point"></returns>
		const Point operator/(const int v) const;

		/// <summary>+=演算子</summary>
		/// <param name="p">加算する<see cref="Point"></param>
		void operator+=(const Point& p);
		/// <summary>-=演算子</summary>
		/// <param name="p">減算する<see cref="Point"></param>
		void operator-=(const Point& p);

		/// <summary>*=演算子</summary>
		/// <param name="p">乗算する係数</param>
		void operator*=(const int v);
		/// <summary>/=演算子</summary>
		/// <param name="p">除算する係数</param>
		void operator/=(const int v);

	};

	/// <summary><see cref="Color"/>出力ストリームに<see cref="Point"/>を渡す</summary>
	/// <param name="os">出力ストリーム</param>
	/// <param name="v">出力<see cref="Point"/></param>
	/// <returns>渡した後のストリーム</returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Point& v) {
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(')');
	}

	/// <summary>
	/// 実数の座標を扱うクラス
	/// </summary>
	struct Vec2 {

		/// <summary>
		///	コンストラクタ
		///	</summary>
		Vec2();
		/// <summary>コンストラクタ</summary>
		/// <param name="_x">x座標</param>
		/// <param name="_y">y座標</param>
		Vec2(const double _x, const double _y);

		/// <summary>
		///	x座標
		///	</summary>
		double x = 0;
		/// <summary>
		///	y座標
		///	</summary>
		double y = 0;

		/// <summary>+演算子</summary>
		/// <param name="p">加算する<see cref="Vec2"></param>
		/// <returns>加算された<see cref="Vec2"></returns>
		const Vec2 operator+(const Vec2& p) const;
		/// <summary>-演算子</summary>
		/// <param name="p">減算する<see cref="Vec2"></param>
		/// <returns>減算された<see cref="Vec2"></returns>
		const Vec2 operator-(const Vec2& p) const;

		/// <summary>*演算子</summary>
		/// <param name="p">乗算する係数</param>
		/// <returns>乗算された<see cref="Vec2"></returns>
		const Vec2 operator*(const int v) const;
		/// <summary>/演算子</summary>
		/// <param name="p">除算する係数</param>
		/// <returns>除算された<see cref="Vec2"></returns>
		const Vec2 operator/(const int v) const;

		/// <summary>+=演算子</summary>
		/// <param name="p">加算する<see cref="Vec2"></param>
		void operator+=(const Vec2& p);
		/// <summary>-=演算子</summary>
		/// <param name="p">減算する<see cref="Vec2"></param>
		void operator-=(const Vec2& p);

		/// <summary>*=演算子</summary>
		/// <param name="p">乗算する係数</param>
		void operator*=(const int v);
		/// <summary>/=演算子</summary>
		/// <param name="p">除算する係数</param>
		void operator/=(const int v);

		/// <summary>コピー演算子</summary>
		/// <param name="p">コピーする<see cref="Point"></param>
		void operator=(const Point& p);

		/// <summary>整数に切り捨てた値を返す</summary>
		/// <return><see cref="Point"></return>
		const Point integer() const;

	};

	/// <summary><see cref="Color"/>出力ストリームに<see cref="Vec2"/>を渡す</summary>
	/// <param name="os">出力ストリーム</param>
	/// <param name="v">出力<see cref="Vec2"/></param>
	/// <returns>渡した後のストリーム</returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Vec2& v) {
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(')');
	}

	/// <summary>+演算子</summary>
	/// <param name="v1"><see cref="Point"/></param>
	/// <param name="v2"><see cref="Vec2"/></param>
	/// <returns>加算した後の<see cref="Vec2"/></returns>
	const Vec2 operator+(const Point& p1, const Vec2& p2);
	/// <summary>+演算子</summary>
	/// <param name="v1"><see cref="Vec2"/></param>
	/// <param name="v2"><see cref="Point"/></param>
	/// <returns>加算した後の<see cref="Vec2"/></returns>
	const Vec2 operator+(const Vec2& p1, const Point& p2);

}
