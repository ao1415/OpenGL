#include "HSV.hpp"
#include <algorithm>

namespace opc {

	HSV::HSV() {
		h = s = v = 0;
	}
	HSV::HSV(const double _h, const double _s, const double _v) {

		const auto round = [](const double x) {
			if (x >= 0)
				return fmod(x, 360.0);
			return 360 - fmod(-x, 360.0);
		};

		h = round(_h);
		s = std::max(0.0, std::min(1.0, _s));
		v = std::max(0.0, std::min(1.0, _v));
	}
	HSV::HSV(const Color c) {

		const double r = c.r / 255.0;
		const double g = c.g / 255.0;
		const double b = c.b / 255.0;

		const double maximum = std::max(r, std::max(g, b));
		const double minimum = std::min(r, std::min(g, b));

		v = maximum;

		if (maximum == minimum)
		{
			h = s = 0;
		}
		else
		{
			const double d = maximum - minimum;
			if (maximum == r)
				h = (g - b) / d;
			else if (maximum == g)
				h = (b - r) / d + 2;
			else if (maximum == b)
				h = (r - g) / d + 4;
			h *= 60;
			s = d / maximum;
		}
	}

	const Color HSV::toRGB() const {

		double r, g, b;

		if (s == 0)
		{
			r = g = b = v;
		}
		else
		{
			const double _h = h / 60;
			int i = (int)round(_h);
			const double f = _h - i;
			const double p = v*(1 - s);
			double q;

			if (i % 2 == 0)
				q = v*(1 - (1 - f)*s);
			else
				q = v*(1 - f*s);

			switch (i)
			{
			case 0: r = v; g = q; b = p; break;
			case 1: r = q; g = v; b = p; break;
			case 2: r = p; g = v; b = q; break;
			case 3: r = p; g = q; b = v; break;
			case 4: r = q; g = p; b = v; break;
			case 5: r = v; g = p; b = q; break;
			}

		}

		return Color((int)(r * 255), (int)(g * 255), (int)(b * 255));
	}

}
