#pragma once

#include <iostream>

namespace opc {

	/// <summary>‘å‚«‚³‚ðˆµ‚¤ƒNƒ‰ƒX</summary>
	struct Size {
		Size();
		Size(const int w, const int h);

		int width = 0;
		int height = 0;
	};

	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Size& v) {
		return os << CharType('(') << v.width << CharType(',') << v.height << CharType(')');
	}

}
