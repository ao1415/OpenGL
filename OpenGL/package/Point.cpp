#include "Point.hpp"

namespace opc {

	Point::Point() {

	}
	Point::Point(const int _x, const int _y) : x(_x), y(_y) {

	}

	const Point Point::operator+(const Point& p) const {
		return Point(x + p.x, y + p.y);
	}
	const Point Point::operator-(const Point& p) const {
		return Point(x - p.x, y - p.y);
	}

	const Point Point::operator*(const int v) const {
		return Point(x * v, y * v);
	}
	const Point Point::operator/(const int v) const {
		return Point(x / v, y / v);
	}

	void Point::operator+=(const Point& p) {
		(*this) = (*this) + p;
	}
	void Point::operator-=(const Point& p) {
		(*this) = (*this) - p;
	}

	void Point::operator*=(const int v) {
		(*this) = (*this) * v;
	}
	void Point::operator/=(const int v) {
		(*this) = (*this) / v;
	}

	Vec2::Vec2() {

	}
	Vec2::Vec2(const double _x, const double _y) : x(_x), y(_y) {

	}

	const Vec2 Vec2::operator+(const Vec2& p) const {
		return Vec2(x + p.x, y + p.y);
	}
	const Vec2 Vec2::operator-(const Vec2& p) const {
		return Vec2(x - p.x, y - p.y);
	}

	const Vec2 Vec2::operator*(const int v) const {
		return Vec2(x * v, y * v);
	}
	const Vec2 Vec2::operator/(const int v) const {
		return Vec2(x / v, y / v);
	}

	void Vec2::operator+=(const Vec2& p) {
		(*this) = (*this) + p;
	}
	void Vec2::operator-=(const Vec2& p) {
		(*this) = (*this) - p;
	}

	void Vec2::operator*=(const int v) {
		(*this) = (*this) * v;
	}
	void Vec2::operator/=(const int v) {
		(*this) = (*this) / v;
	}

	void Vec2::operator=(const Point& p) {
		x = p.x; y = p.y;
	}

	const Point Vec2::integer() const {
		return Point((int)x, (int)y);
	}

	const Vec2 operator+(const Point& p1, const Vec2& p2) {
		return Vec2(p1.x + p2.x, p1.y + p2.y);
	}
	const Vec2 operator+(const Vec2& p1, const Point& p2) {
		return Vec2(p1.x + p2.x, p1.y + p2.y);
	}

}
