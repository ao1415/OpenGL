#include "Color.hpp"
#include <cassert>

namespace opc {

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

	namespace Paint {

		void Color(const opc::Color& c, const bool alpha) {
			if (alpha) glColor4ub(c.r, c.g, c.b, c.a);
			else glColor3ub(c.r, c.g, c.b);
		}
		void Color(const byte r, const byte g, const byte b) {
			Color(opc::Color(r, g, b), false);
		}
		void Color(const byte r, const byte g, const byte b, const byte a) {
			Color(opc::Color(r, g, b, a));
		}

		void Color(const float r, const float g, const float b) {
			assert(0 <= r && r <= 1 && 0 <= g && g <= 1 && 0 <= b && b <= 1);
			glColor3f(r, g, b);
		}
		void Color(const float r, const float g, const float b, const float a) {
			assert(0 <= r && r <= 1 && 0 <= g && g <= 1 && 0 <= b && b <= 1 && 0 <= a && a <= 1);
			glColor4f(r, g, b, a);
		}
		void Color(const double r, const double g, const double b) {
			assert(0 <= r && r <= 1 && 0 <= g && g <= 1 && 0 <= b && b <= 1);
			glColor3d(r, g, b);
		}
		void Color(const double r, const double g, const double b, const double a) {
			assert(0 <= r && r <= 1 && 0 <= g && g <= 1 && 0 <= b && b <= 1 && 0 <= a && a <= 1);
			glColor4d(r, g, b, a);
		}

	}
}
