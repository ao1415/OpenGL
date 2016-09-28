#pragma once

#include <iostream>

namespace opc {

	struct IntVector {

		IntVector();
		IntVector(const int _x, const int _y, const int _z);

		int x = 0;
		int y = 0;
		int z = 0;

		const IntVector operator+(const IntVector& p) const;
		const IntVector operator-(const IntVector& p) const;

		const IntVector operator*(const int v) const;
		const IntVector operator/(const int v) const;

		void operator+=(const IntVector& p);
		void operator-=(const IntVector& p);

		void operator*=(const int v);
		void operator/=(const int v);

	};

	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const IntVector& v) {
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(',') << v.z << CharType(')');
	}


	struct RealVector {

		RealVector();
		RealVector(const double _x, const double _y, const double _z);

		double x = 0;
		double y = 0;
		double z = 0;

		const RealVector operator+(const RealVector& p) const;
		const RealVector operator-(const RealVector& p) const;

		const RealVector operator*(const double v) const;
		const RealVector operator/(const double v) const;

		void operator+=(const RealVector& p);
		void operator-=(const RealVector& p);

		void operator*=(const double v);
		void operator/=(const double v);

		void operator=(const IntVector& p);

		const IntVector integer() const;

	};

	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const RealVector& v) {
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(',') << v.z << CharType(')');
	}

	const RealVector operator+(const IntVector& v1, const RealVector& v2);
	const RealVector operator+(const RealVector& v1, const IntVector& v2);

}
