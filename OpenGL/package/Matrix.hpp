#pragma once

#include <array>

#include "Point.hpp"
#include "Size.hpp"
#include "Property.hpp"

namespace opc {

	/// <summary>4*4ÇÃçsóÒ</summary>
	class Matrix4x4 {
	public:

		static const size_t Width = 4;
		static const size_t Height = 4;

		Matrix4x4() = default;
		Matrix4x4(const double& val) { m_data.fill(val); }

		Matrix4x4(const std::initializer_list<std::initializer_list<double>>& set) {
			fill(0);

			int y = 0;
			for (const auto& row : set)
			{
				if (y >= 4) break;
				int x = 0;
				for (const auto& val : row)
				{
					if (x >= 4) break;
					m_data[y*Width + x] = val;
					x++;
				}
				y++;
			}
		}

		Matrix4x4(const Matrix4x4& m) = default;
		Matrix4x4(Matrix4x4&& m) { m_data = std::move(m.m_data); }

		Matrix4x4& operator=(const Matrix4x4& other) = default;
		Matrix4x4& operator=(Matrix4x4&& other) = default;

		bool isBounds(size_t y, size_t x) const noexcept {
			return (0 <= y && y < Height && 0 <= x && x < Width);
		}

		double& at(size_t y, size_t x) {
			if (!isBounds(y, x)) throw std::out_of_range("Matrix4x4::at");
			return m_data[y*Width + x];
		}
		const double& at(size_t y, size_t x) const {
			if (!isBounds(y, x)) throw std::out_of_range("Matrix4x4::at");
			return m_data[y*Width + x];
		}
		double& at(const IntPoint& pos) { return at(pos.y, pos.x); }
		const double& at(const IntPoint& pos) const { return at(pos.y, pos.x); }

		double* operator[](size_t index) { return &m_data[index*Width]; }
		double& operator[](const IntPoint& pos) { return m_data[pos.y*Width + pos.x]; }

		const double* operator[](size_t index) const { return &m_data[index*Width]; }
		const double& operator[](const IntPoint& pos) const { return m_data[pos.y*Width + pos.x]; }

		void fill(const double& val) { std::fill(m_data.begin(), m_data.end(), val); }

		std::array<double, Width * Height>::pointer data() {
			for (int y = 0; y < Height; y++)
			{
				for (int x = 0; x < Width; x++)
					r_data[x*Width + y] = m_data[y*Width + x];
			}
			return &r_data[0];
		}

		void swap(Matrix4x4& other) {
			m_data.swap(other.m_data);
			r_data.swap(other.r_data);
		}

	private:

		std::array<double, Width * Height> m_data;
		std::array<double, Width * Height> r_data;

	};



}
