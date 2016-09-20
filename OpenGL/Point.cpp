#include "Point.hpp"

namespace opc {

	IntPoint::IntPoint() {

	}
	IntPoint::IntPoint(const int _x, const int _y) : x(_x), y(_y) {

	}

	const IntPoint IntPoint::operator+(const IntPoint& p) const {
		return IntPoint(x + p.x, y + p.y);
	}
	const IntPoint IntPoint::operator-(const IntPoint& p) const {
		return IntPoint(x - p.x, y - p.y);
	}

	const IntPoint IntPoint::operator*(const int v) const {
		return IntPoint(x * v, y * v);
	}
	const IntPoint IntPoint::operator/(const int v) const {
		return IntPoint(x / v, y / v);
	}

	void IntPoint::operator+=(const IntPoint& p) {
		(*this) = (*this) + p;
	}
	void IntPoint::operator-=(const IntPoint& p) {
		(*this) = (*this) - p;
	}

	void IntPoint::operator*=(const int v) {
		(*this) = (*this) * v;
	}
	void IntPoint::operator/=(const int v) {
		(*this) = (*this) / v;
	}
}

namespace opc {

	RealPoint::RealPoint() {

	}
	RealPoint::RealPoint(const double _x, const double _y) : x(_x), y(_y) {

	}

	const RealPoint RealPoint::operator+(const RealPoint& p) const {
		return RealPoint(x + p.x, y + p.y);
	}
	const RealPoint RealPoint::operator-(const RealPoint& p) const {
		return RealPoint(x - p.x, y - p.y);
	}

	const RealPoint RealPoint::operator*(const int v) const {
		return RealPoint(x * v, y * v);
	}
	const RealPoint RealPoint::operator/(const int v) const {
		return RealPoint(x / v, y / v);
	}

	void RealPoint::operator+=(const RealPoint& p) {
		(*this) = (*this) + p;
	}
	void RealPoint::operator-=(const RealPoint& p) {
		(*this) = (*this) - p;
	}

	void RealPoint::operator*=(const int v) {
		(*this) = (*this) * v;
	}
	void RealPoint::operator/=(const int v) {
		(*this) = (*this) / v;
	}

	void RealPoint::operator=(const IntPoint& p) {
		x = p.x; y = p.y;
	}

	const IntPoint RealPoint::integer() const {
		return IntPoint((int)x, (int)y);
	}

	const RealPoint operator+(const IntPoint& p1, const RealPoint& p2) {
		return RealPoint(p1.x + p2.x, p1.y + p2.y);
	}
	const RealPoint operator+(const RealPoint& p1, const IntPoint& p2) {
		return RealPoint(p1.x + p2.x, p1.y + p2.y);
	}

}
