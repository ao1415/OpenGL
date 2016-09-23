#include "Color.hpp"

namespace opc{
	
	Color::Color() {}
	Color::Color(const int _r, const int _g, const int _b) : Color(_r, _g, _b, 255) {}
	Color::Color(const int _r, const int _g, const int _b, const int _a) {
		r = _r & 0x000000ff;
		g = _g & 0x000000ff;
		b = _b & 0x000000ff;
		a = _a & 0x000000ff;
	}
	Color::Color(unsigned int code) : Color(code, 255) {}
	Color::Color(unsigned int code, const int alpha) {
		//0xrrggbb

		b = (0x000000ff & code) >> 0;
		g = (0x0000ff00 & code) >> 8;
		r = (0x00ff0000 & code) >> 16;
		a = alpha & 0x000000ff;
	}
	Color::Color(const Color& _c, const int _a) {
		r = _c.r;
		g = _c.g;
		b = _c.b;
		a = _a & 0x000000ff;
	}

}
