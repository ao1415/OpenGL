#include "Vector.hpp"

namespace opc {

	Point3D::Point3D() : Point3D(0, 0, 0) {}
	Point3D::Point3D(const int _x, const int _y, const int _z) {
		x = _x; y = _y; z = _z;
	}

	const Point3D Point3D::operator+(const Point3D& p) const {
		return Point3D(x + p.x, y + p.y, z + p.z);
	}
	const Point3D Point3D::operator-(const Point3D& p) const {
		return Point3D(x - p.x, y - p.y, z - p.z);
	}

	const Point3D Point3D::operator*(const int v) const {
		return Point3D(x * v, y * v, z * v);
	}
	const Point3D Point3D::operator/(const int v) const {
		return Point3D(x / v, y / v, z / v);
	}

	void Point3D::operator+=(const Point3D& p) {
		(*this) = (*this) + p;
	}
	void Point3D::operator-=(const Point3D& p) {
		(*this) = (*this) - p;
	}

	void Point3D::operator*=(const int v) {
		(*this) = (*this) * v;

	}
	void Point3D::operator/=(const int v) {
		(*this) = (*this) / v;
	}


	Vec3::Vec3() : Vec3(0, 0, 0) {}
	Vec3::Vec3(const double _x, const double _y, const double _z) {
		x = _x; y = _y; z = _z;
	}

	const Vec3 Vec3::operator+(const Vec3& p) const {
		return Vec3(x + p.x, y + p.y, z + p.z);
	}
	const Vec3 Vec3::operator-(const Vec3& p) const {
		return Vec3(x - p.x, y - p.y, z - p.z);
	}

	const Vec3 Vec3::operator*(const double v) const {
		return Vec3(x * v, y * v, z * v);
	}
	const Vec3 Vec3::operator/(const double v) const {
		return Vec3(x / v, y / v, z / v);
	}

	void Vec3::operator+=(const Vec3& p) {
		(*this) = (*this) + p;
	}
	void Vec3::operator-=(const Vec3& p) {
		(*this) = (*this) - p;
	}

	void Vec3::operator*=(const double v) {
		(*this) = (*this) * v;

	}
	void Vec3::operator/=(const double v) {
		(*this) = (*this) / v;
	}

	void Vec3::operator=(const Point3D& v) {
		x = v.x; y = v.y; z = v.z;
	}

	const Point3D Vec3::integer() const {
		return Point3D((int)x, (int)y, (int)z);
	}

	const Vec3 operator+(const Point3D& v1, const Vec3& v2) {
		return Vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	}
	const Vec3 operator+(const Vec3& v1, const Point3D& v2) {
		return Vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	}

}
