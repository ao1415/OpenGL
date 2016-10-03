#pragma once

#include <GL/glut.h>
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

	namespace Paint {

		void Color(const opc::Color& c, const bool alpha = true);
		void Color(const byte r, const byte g, const byte b);
		void Color(const byte r, const byte g, const byte b, const byte a);
		void Color(const float r, const float g, const float b);
		void Color(const float r, const float g, const float b, const float a);
		void Color(const double r, const double g, const double b);
		void Color(const double r, const double g, const double b, const double a);
	}

}
