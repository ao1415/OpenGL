#pragma once

#include <iostream>

namespace opc {

	/// <summary>整数の座標を扱うクラス</summary>
	struct IntPoint {
		IntPoint();
		IntPoint(const int _x, const int _y);

		int x = 0;
		int y = 0;

		const IntPoint operator+(const IntPoint& p) const;
		const IntPoint operator-(const IntPoint& p) const;

		const IntPoint operator*(const int v) const;
		const IntPoint operator/(const int v) const;

		void operator+=(const IntPoint& p);
		void operator-=(const IntPoint& p);

		void operator*=(const int v);
		void operator/=(const int v);

	};

	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const IntPoint& v) {
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(')');
	}

	/// <summary>実数の座標を扱うクラス</summary>
	struct RealPoint {
		RealPoint();
		RealPoint(const double _x, const double _y);

		double x = 0;
		double y = 0;

		const RealPoint operator+(const RealPoint& p) const;
		const RealPoint operator-(const RealPoint& p) const;

		const RealPoint operator*(const int v) const;
		const RealPoint operator/(const int v) const;

		void operator+=(const RealPoint& p);
		void operator-=(const RealPoint& p);

		void operator*=(const int v);
		void operator/=(const int v);

		void operator=(const IntPoint& p);

		const IntPoint integer() const;

	};

	template <class CharType>
	inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const RealPoint& v) {
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(')');
	}

	const RealPoint operator+(const IntPoint& p1, const RealPoint& p2);
	const RealPoint operator+(const RealPoint& p1, const IntPoint& p2);

}
