#pragma once

#include <vector>

#include "Point.hpp"
#include "Size.hpp"
#include "Property.hpp"

namespace opc {

	//参考ライブラリ：Siv3D

	/// <summary>動的2次元配列</summary>
	template<typename Type>
	class Grid {
	private:

		using ContainerType = std::vector<Type>;
		using iterator = typename ContainerType::iterator;
		using const_iterator = typename ContainerType::const_iterator;
		using reverse_iterator = typename ContainerType::reverse_iterator;
		using const_reverse_iterator = typename ContainerType::const_reverse_iterator;

	public:

		Grid() = default;
		Grid(const size_t w, const size_t h) : data(w*h, Type()), width(w), height(h) {}
		Grid(const IntSize& size) : Grid(size.width, size.height) {}
		Grid(const size_t w, const size_t h, const Type& val) : data(w*h, val), width(w), height(h) {}
		Grid(const IntSize& size, const Type& val) : Grid(size.width, size.height, val) {}

		Grid(const Grid& g) = default;
		Grid(Grid&& g) noexcept {
			width = g.width;
			height = g.height;
			data = std::move(g.data);
			g.width = g.height = 0;
		}

		Grid& operator=(const Grid& other) = default;
		Grid& operator=(Grid&& other) = default;

		bool inBounds(size_t y, size_t x) const noexcept {
			return (0 <= y && y < height && 0 <= x && x < width);
		}

		Type& at(size_t y, size_t x) {
			if (!isBounds(y, x)) throw std::out_of_range("Grid::at");
			return data[y*width + x];
		}
		const Type& at(size_t y, size_t x) const {
			if (!isBounds(y, x)) throw std::out_of_range("Grid::at");
			return data[y*width + x];
		}
		Type& at(const IntPoint& pos) { return at(pos.y, pos.x); }
		const Type& at(const IntPoint& pos) const { return at(pos.y, pos.x); }

		Type* operator[](size_t index) { return &data[index*width]; }
		Type& operator[](const IntPoint& pos) { return data[pos.y*width + pos.x]; }

		const Type* operator[](size_t index) const { return &data[index*width]; }
		const Type& operator[](const IntPoint& pos) const { return data[pos.y*width + pos.x]; }

		Property_Get(bool, isEmpty) const noexcept { return data.empty(); }
		Property_Get(size_t, Width) const noexcept { return width; }
		Property_Get(size_t, Height) const noexcept { return height; }

		iterator begin() noexcept { return m_data.begin(); }
		iterator end() noexcept { return m_data.end(); }

		const_iterator begin() const noexcept { return m_data.cbegin(); }
		const_iterator end() const noexcept { return m_data.cend(); }

		reverse_iterator rbegin() noexcept { return m_data.rbegin(); }
		reverse_iterator rend() noexcept { return m_data.rend(); }

		const_reverse_iterator rbegin() const noexcept { return m_data.rbegin(); }
		const_reverse_iterator rend() const noexcept { return m_data.rend(); }

		const_iterator cbegin() const noexcept { return m_data.cbegin(); }
		const_iterator cend() const noexcept { return m_data.cend(); }

		const_reverse_iterator crbegin() const noexcept { return m_data.crbegin(); }
		const_reverse_iterator crend() const noexcept { return m_data.crend(); }

		void shrink_to_fit() { data.shrink_to_fit(); }

		void release() { clear(); shrink_to_fit(); }

		void reserve(size_t w, size_t h) { data.reserve(w*h); }

		void resize(size_t w, size_t h, const Type& val) {
			if (w == width && h == height) return;
			width = w;
			height = h;
			data.assign(w*h, val);
		}
		void resize(size_t w, size_t h) { resize(w, h, Type()); }
		void resize(const IntSize& size, const Type& val) { resize(size.width, size.height, val); }
		void resize(const IntSize& size) { resize(size.width, size.height, Type()); }

		void clear() noexcept {
			data.clear();
			width = height = 0;
		}

		IntSize size() const noexcept { return IntSize(static_cast<int>width, static_cast<int>height); }

		size_t num_elements() const noexcept { return data.size(); }

		void fill(const Type& val) { std::fill(data.begin(), data.end(), val); }

		void swap(Grid& other)
			noexcept(std::allocator_traits<allocator_type>::propagate_on_container_swap::value
				|| std::allocator_traits<allocator_type>::is_always_equal::value) {
			data.swap(other.data);
			std::swap(width, other.width);
			std::swap(height, other.height);
		}

	private:

		std::vector<Type> data;
		size_t width = 0;
		size_t height = 0;

	};

}
