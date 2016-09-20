#pragma once

#include <iostream>

namespace opc {

	/// <summary>�傫���������N���X</summary>
	struct Size {
		Size();
		Size(const int w, const int h);
		Size(const double w, const double h);

		double width = 0;
		double height = 0;
	};

	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Size& v) {
		return os << CharType('(') << v.width << CharType(',') << v.height << CharType(')');
	}

}
