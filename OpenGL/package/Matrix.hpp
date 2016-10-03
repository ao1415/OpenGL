#pragma once

#include <array>

#include "Point.hpp"
#include "Size.hpp"
#include "Property.hpp"

namespace opc {

	class Matrix4x4 {
	public:

		static const size_t Width = 4;
		static const size_t Height = 4;

		Matrix4x4() = default;
		Matrix4x4(const double& val) { data.fill(val); }

		Matrix4x4(const Matrix4x4& m) = default;
		Matrix4x4(Matrix4x4&& m) { data = std::move(m.data); }

		Matrix4x4& operator=(const Matrix4x4& other) = default;
		Matrix4x4& operator=(Matrix4x4&& other) = default;

		bool isBounds(size_t y, size_t x) const noexcept {
			return (0 <= y && y < Height && 0 <= x && x < Width);
		}

		double& at(size_t y, size_t x) {
			if (!isBounds(y, x)) throw std::out_of_range("Matrix4x4::at");
			return data[y*Width + x];
		}
		const double& at(size_t y, size_t x) const {
			if (!isBounds(y, x)) throw std::out_of_range("Matrix4x4::at");
			return data[y*Width + x];
		}
		double& at(const IntPoint& pos) { return at(pos.y, pos.x); }
		const double& at(const IntPoint& pos) const { return at(pos.y, pos.x); }

		double* operator[](size_t index) { return &data[index*Width]; }
		double& operator[](const IntPoint& pos) { return data[pos.y*Width + pos.x]; }

		const double* operator[](size_t index) const { return &data[index*Width]; }
		const double& operator[](const IntPoint& pos) const { return data[pos.y*Width + pos.x]; }

		void fill(const double& val) { std::fill(data.begin(), data.end(), val); }

		void swap(Matrix4x4& other) { data.swap(other.data); }

	private:

		std::array<double, Width * Height> data;

	};

}
