#pragma once

#include <iostream>

namespace opc {

	/// <summary>
	/// 整数の大きさ
	/// </summary>
	struct IntSize {

		/// <summary>
		/// コンストラクタ
		/// </summary>
		IntSize();
		/// <summary>コンストラクタ</summary>
		/// <param name="w">横幅</param>
		/// <param name="h">縦幅</param>
		IntSize(const int w, const int h);

		/// <summary>
		/// 横幅
		/// </summary>
		int width = 0;
		/// <summary>
		/// 縦幅
		/// </summary>
		int height = 0;
	};

	/// <summary>
	/// 実数の大きさ
	/// </summary>
	struct RealSize {

		/// <summary>
		/// コンストラクタ
		/// </summary>
		RealSize();
		/// <summary>コンストラクタ</summary>
		/// <param name="w">横幅</param>
		/// <param name="h">縦幅</param>
		RealSize(const double w, const double h);

		/// <summary>
		/// 横幅
		/// </summary>
		double width = 0;
		/// <summary>
		/// 縦幅
		/// </summary>
		double height = 0;
	};

	/// <summary><see cref="Color"/>出力ストリームに<see cref="IntSize"/>を渡す</summary>
	/// <param name="os">出力ストリーム</param>
	/// <param name="v">出力<see cref="IntSize"/></param>
	/// <returns>渡した後のストリーム</returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const IntSize& v) {
		return os << CharType('(') << v.width << CharType(',') << v.height << CharType(')');
	}

	/// <summary><see cref="Color"/>出力ストリームに<see cref="RealSize"/>を渡す</summary>
	/// <param name="os">出力ストリーム</param>
	/// <param name="v">出力<see cref="RealSize"/></param>
	/// <returns>渡した後のストリーム</returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const RealSize& v) {
		return os << CharType('(') << v.width << CharType(',') << v.height << CharType(')');
	}

}
