#pragma once

#include <GL/glut.h>
#include <iostream>

namespace opc {

	typedef unsigned char byte;

	/// <summary>
	/// 色を扱うクラス
	/// </summary>
	struct Color {

		/// <summary>
		///	コンストラクタ
		///	</summary>
		Color();
		/// <summary>コンストラクタ</summary>
		/// <param name="_r">赤</param>
		/// <param name="_g">緑</param>
		/// <param name="_b">青</param>
		Color(const int _r, const int _g, const int _b);
		/// <summary>コンストラクタ</summary>
		/// <param name="_r">赤</param>
		/// <param name="_g">緑</param>
		/// <param name="_b">青</param>
		/// <param name="_a">透明度</param>
		Color(const int _r, const int _g, const int _b, const int _a);
		/// <summary>コンストラクタ</summary>
		/// <param name="code">カラーコード(0xRRGGBB)</param>
		Color(unsigned int code);
		/// <summary>コンストラクタ</summary>
		/// <param name="code">カラーコード(0xRRGGBB)</param>
		/// <param name="alpha">透明度</param>
		Color(unsigned int code, const int alpha);
		/// <summary>コンストラクタ</summary>
		/// <param name="_c"><see cref="Color"/>クラス</param>
		/// <param name="_a">透明度</param>
		Color(const Color& _c, const int _a);

		/// <summary>
		/// 赤
		/// </summary>
		byte r = 0;
		/// <summary>
		/// 緑
		/// </summary>
		byte g = 0;
		/// <summary>
		/// 青
		/// </summary>
		byte b = 0;
		/// <summary>
		/// 透明度
		/// </summary>
		byte a = 0;
	};

	/// <summary><see cref="Color"/>の出力ストリーム用オーバーロード</summary>
	/// <param name="os">出力ストリーム</param>
	/// <param name="v">出力<see cref="Color"/></param>
	/// <returns></returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Color& v) {
		return os << CharType('(') << (int)v.r << CharType(',') << (int)v.g << CharType(',') << (int)v.b << CharType(',') << (int)v.a << CharType(')');
	}

	/// <summary>
	/// OpenGLの色を設定する関数
	/// </summary>
	namespace Paint {
		///	<summary></summary>
		///	<param name="c">色</param>
		///	<param name="alpha">alpha値を使用するか true:使用する, false:使用しない</param>
		void Color(const opc::Color& c, const bool alpha = true);
		///	<summary></summary>
		///	<param name="r">赤</param>
		///	<param name="g">緑</param>
		///	<param name="b">青</param>
		void Color(const byte r, const byte g, const byte b);
		///	<summary></summary>
		///	<param name="r">赤</param>
		///	<param name="g">緑</param>
		///	<param name="b">青</param>
		///	<param name="a">透明度</param>
		void Color(const byte r, const byte g, const byte b, const byte a);
		///	<summary></summary>
		///	<param name="r">赤</param>
		///	<param name="g">緑</param>
		///	<param name="b">青</param>
		void Color(const float r, const float g, const float b);
		///	<summary></summary>
		///	<param name="r">赤</param>
		///	<param name="g">緑</param>
		///	<param name="b">青</param>
		///	<param name="a">透明度</param>
		void Color(const float r, const float g, const float b, const float a);
		///	<summary></summary>
		///	<param name="r">赤</param>
		///	<param name="g">緑</param>
		///	<param name="b">青</param>
		void Color(const double r, const double g, const double b);
		///	<summary></summary>
		///	<param name="r">赤</param>
		///	<param name="g">緑</param>
		///	<param name="b">青</param>
		///	<param name="a">透明度</param>
		void Color(const double r, const double g, const double b, const double a);
	}

}
