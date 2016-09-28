#include "Vector.hpp"

namespace opc {

	IntVector::IntVector() : IntVector(0, 0, 0) {}
	IntVector::IntVector(const int _x, const int _y, const int _z) {
		x = _x; y = _y; z = _z;
	}

	const IntVector IntVector::operator+(const IntVector& p) const {
		return IntVector(x + p.x, y + p.y, z + p.z);
	}
	const IntVector IntVector::operator-(const IntVector& p) const {
		return IntVector(x - p.x, y - p.y, z - p.z);
	}

	const IntVector IntVector::operator*(const int v) const {
		return IntVector(x * v, y * v, z * v);
	}
	const IntVector IntVector::operator/(const int v) const {
		return IntVector(x / v, y / v, z / v);
	}

	void IntVector::operator+=(const IntVector& p) {
		(*this) = (*this) + p;
	}
	void IntVector::operator-=(const IntVector& p) {
		(*this) = (*this) - p;
	}

	void IntVector::operator*=(const int v) {
		(*this) = (*this) * v;

	}
	void IntVector::operator/=(const int v) {
		(*this) = (*this) / v;
	}


	RealVector::RealVector() : RealVector(0, 0, 0) {}
	RealVector::RealVector(const double _x, const double _y, const double _z) {
		x = _x; y = _y; z = _z;
	}

	const RealVector RealVector::operator+(const RealVector& p) const {
		return RealVector(x + p.x, y + p.y, z + p.z);
	}
	const RealVector RealVector::operator-(const RealVector& p) const {
		return RealVector(x - p.x, y - p.y, z - p.z);
	}

	const RealVector RealVector::operator*(const double v) const {
		return RealVector(x * v, y * v, z * v);
	}
	const RealVector RealVector::operator/(const double v) const {
		return RealVector(x / v, y / v, z / v);
	}

	void RealVector::operator+=(const RealVector& p) {
		(*this) = (*this) + p;
	}
	void RealVector::operator-=(const RealVector& p) {
		(*this) = (*this) - p;
	}

	void RealVector::operator*=(const double v) {
		(*this) = (*this) * v;

	}
	void RealVector::operator/=(const double v) {
		(*this) = (*this) / v;
	}

	void RealVector::operator=(const IntVector& v) {
		x = v.x; y = v.y; z = v.z;
	}

	const IntVector RealVector::integer() const {
		return IntVector((int)x, (int)y, (int)z);
	}

	const RealVector operator+(const IntVector& v1, const RealVector& v2) {
		return RealVector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	}
	const RealVector operator+(const RealVector& v1, const IntVector& v2) {
		return RealVector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	}

}
