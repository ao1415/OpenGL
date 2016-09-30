#pragma once

#include <iostream>

namespace opc {

	typedef unsigned char byte;

	/// <summary>F‚ğˆµ‚¤ƒNƒ‰ƒX</summary>
	struct Color {

		Color();
		Color(const int _r, const int _g, const int _b);
		Color(const int _r, const int _g, const int _b, const int _a);
		Color(unsigned int code);
		Color(unsigned int code, const int alpha);
		Color(const Color& _c, const int _a);

		byte r = 0;
		byte g = 0;
		byte b = 0;
		byte a = 0;
	};

	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Color& v) {
		return os << CharType('(') << (int)v.r << CharType(',') << (int)v.g << CharType(',') << (int)v.b << CharType(',') << (int)v.a << CharType(')');
	}

}
