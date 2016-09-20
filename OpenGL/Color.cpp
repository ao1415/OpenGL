#include "Color.hpp"

namespace opc{
	
	Color::Color() {}
	Color::Color(const byte _r, const byte _g, const byte _b) : Color(_r, _g, _b, 255) {}
	Color::Color(const byte _r, const byte _g, const byte _b, const byte _a) :r(_r), g(_g), b(_b), a(_a) {}
	Color::Color(unsigned int code) : Color(code, 255) {}
	Color::Color(unsigned int code, const byte alpha) {
		//0xrrggbb

		b = (0x000000ff & code) >> 0;
		g = (0x0000ff00 & code) >> 8;
		r = (0x00ff0000 & code) >> 16;
		a = alpha;
	}
	Color::Color(const Color& _c, const byte _a) {
		r = _c.r;
		g = _c.g;
		b = _c.b;
		a = _a;
	}

}
