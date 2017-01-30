#pragma once

#include "Color.hpp"

namespace opc {

	/// <summary>
	/// 色を扱うクラス
	/// </summary>
	struct HSV {

		/// <summary>
		///	コンストラクタ
		///	</summary>
		HSV();
		/// <summary>コンストラクタ</summary>
		/// <param name="_h">色相</param>
		/// <param name="_s">彩度</param>
		/// <param name="_v">明度</param>
		HSV(const double _h, const double _s, const double _v);
		/// <summary>コンストラクタ</summary>
		/// <param name="_c"><see cref="Color"/>クラス</param>
		HSV(const Color c);

		///	<summary>
		/// RGBに変換する
		/// </summary>
		const Color toRGB() const;

		/// <summary>
		/// 色相
		/// </summary>
		double h;
		/// <summary>
		/// 彩度
		/// </summary>
		double s;
		/// <summary>
		/// 明度
		/// </summary>
		double v;

	};

	/// <summary><see cref="Color"/>出力ストリームに<see cref="Color"/>を渡す</summary>
	/// <param name="os">出力ストリーム</param>
	/// <param name="v">出力<see cref="Color"/></param>
	/// <returns>渡した後のストリーム</returns>
	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const HSV& v) {
		return os << CharType('(') << v.h << CharType(',') << v.s << CharType(',') << v.v << CharType(')');
	}

}
