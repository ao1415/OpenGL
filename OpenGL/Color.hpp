#pragma once

#include <iostream>

namespace opc {

	typedef unsigned char byte;

	/// <summary>F‚ğˆµ‚¤ƒNƒ‰ƒX</summary>
	struct Color {

		Color();
		Color(const byte _r, const byte _g, const byte _b);
		Color(const byte _r, const byte _g, const byte _b, const byte _a);
		Color(unsigned int code);
		Color(unsigned int code, const byte alpha);


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
