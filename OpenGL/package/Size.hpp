#pragma once

#include <iostream>

namespace opc {

	/// <summary>大きさを扱うクラス</summary>
	struct IntSize {
		IntSize();
		IntSize(const int w, const int h);

		int width = 0;
		int height = 0;
	};

	/// <summary>大きさを扱うクラス</summary>
	struct RealSize {
		RealSize();
		RealSize(const int w, const int h);
		RealSize(const double w, const double h);

		double width = 0;
		double height = 0;
	};

	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const IntSize& v) {
		return os << CharType('(') << v.width << CharType(',') << v.height << CharType(')');
	}

	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const RealSize& v) {
		return os << CharType('(') << v.width << CharType(',') << v.height << CharType(')');
	}

}
