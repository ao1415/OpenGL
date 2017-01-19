#pragma once

#include <vector>

#include "Point.hpp"
#include "Size.hpp"
#include "Property.hpp"

namespace opc {

	//参考ライブラリ：Siv3D

	/// <summary>
	///	動的2次元配列
	///	</summary>
	template<typename Type>
	class Grid {
	private:

		using ContainerType = std::vector<Type>;
		using value_type = typename ContainerType::value_type;
		using allocator_type = typename ContainerType::allocator_type;
		using iterator = typename ContainerType::iterator;
		using const_iterator = typename ContainerType::const_iterator;
		using reverse_iterator = typename ContainerType::reverse_iterator;
		using const_reverse_iterator = typename ContainerType::const_reverse_iterator;

	public:

		/// <summary>
		///	コンストラクタ
		///	</summary>
		Grid() = default;
		/// <summary>コンストラクタ</summary>
		/// <param name="w">横</param>
		/// <param name="h">縦</param>
		Grid(const size_t w, const size_t h) : data(w*h, Type()), width(w), height(h) {}
		/// <summary>コンストラクタ</summary>
		/// <param name="size">大きさ</param>
		Grid(const IntSize& size) : Grid(size.width, size.height) {}
		/// <summary>コンストラクタ</summary>
		/// <param name="w">横</param>
		/// <param name="h">縦</param>
		/// <param name="val">初期値</param>
		Grid(const size_t w, const size_t h, const Type& val) : data(w*h, val), width(w), height(h) {}
		/// <summary>コンストラクタ</summary>
		/// <param name="size">大きさ</param>
		/// <param name="val">初期値</param>
		Grid(const IntSize& size, const Type& val) : Grid(size.width, size.height, val) {}

		/// <summary>コンストラクタ</summary>
		/// <param name="g">コピーする<see cref="Grid"/></param>
		Grid(const Grid& g) = default;
		/// <summary>コンストラクタ</summary>
		/// <param name="g">移動する<see cref="Grid"/></param>
		Grid(Grid&& g) noexcept {
			width = g.width;
			height = g.height;
			data = std::move(g.data);
			g.width = g.height = 0;
		}

		/// <summary>コピー演算子</summary>
		/// <param name="other">コピーする<see cref="Grid"/></param>
		/// <returns><see cref="Grid"/></returns>
		Grid& operator=(const Grid& other) = default;
		/// <summary>ムーブ演算子</summary>
		/// <param name="other">移動する<see cref="Grid"/></param>
		/// <returns><see cref="Grid"/></returns>
		Grid& operator=(Grid&& other) = default;

		/// <summary>参照範囲の確認</summary>
		/// <param name="y">y座標</param>
		/// <param name="x">x座標</param>
		/// <returns>内部ならばtrue, それ以外はfalse</returns>
		bool inBounds(size_t y, size_t x) const noexcept {
			return (0 <= y && y < height && 0 <= x && x < width);
		}

		/// <summary>配列参照</summary>
		/// <param name="y">y座標</param>
		/// <param name="x">x座標</param>
		/// <returns>参照値</returns>
		Type& at(size_t y, size_t x) {
			if (!isBounds(y, x)) throw std::out_of_range("Grid::at");
			return data[y*width + x];
		}
		/// <summary>配列参照</summary>
		/// <param name="y">y座標</param>
		/// <param name="x">x座標</param>
		/// <returns>参照値</returns>
		const Type& at(size_t y, size_t x) const {
			if (!isBounds(y, x)) throw std::out_of_range("Grid::at");
			return data[y*width + x];
		}

		/// <summary>配列参照</summary>
		/// <param name="pos">座標</param>
		/// <returns>参照値</returns>
		Type& at(const IntPoint& pos) { return at(pos.y, pos.x); }
		/// <summary>配列参照</summary>
		/// <param name="pos">座標</param>
		/// <returns>参照値</returns>
		const Type& at(const IntPoint& pos) const { return at(pos.y, pos.x); }

		/// <summary>配列参照</summary>
		/// <param name="index">添え字</param>
		/// <returns>参照値</returns>
		Type* operator[](size_t index) { return &data[index*width]; }
		/// <summary>配列参照</summary>
		/// <param name="index">添え字</param>
		/// <returns>参照値</returns>
		const Type* operator[](size_t index) const { return &data[index*width]; }

		/// <summary>配列参照</summary>
		/// <param name="pos">座標</param>
		/// <returns>参照値</returns>
		Type& operator[](const IntPoint& pos) { return data[pos.y*width + pos.x]; }
		/// <summary>配列参照</summary>
		/// <param name="pos">座標</param>
		/// <returns>参照値</returns>
		const Type& operator[](const IntPoint& pos) const { return data[pos.y*width + pos.x]; }

		/// <summary>配列が空かを返す</summary>
		/// <returns>空ならばtrue, それ以外はfalse</returns>
		Property_Get(bool, isEmpty) const noexcept { return data.empty(); }
		/// <summary>横幅を返す</summary>
		/// <returns>横幅</returns>
		Property_Get(size_t, Width) const noexcept { return width; }
		/// <summary>縦幅を返す</summary>
		/// <returns>縦幅</returns>
		Property_Get(size_t, Height) const noexcept { return height; }

		/// <summary>先頭のイテレータを返す</summary>
		/// <returns>先頭のイテレータ</returns>
		iterator begin() noexcept { return m_data.begin(); }
		/// <summary>終端のイテレータを返す</summary>
		/// <returns>終端のイテレータ</returns>
		iterator end() noexcept { return m_data.end(); }

		/// <summary>先頭のイテレータを返す</summary>
		/// <returns>先頭のイテレータ</returns>
		const_iterator begin() const noexcept { return m_data.cbegin(); }
		/// <summary>終端のイテレータを返す</summary>
		/// <returns>終端のイテレータ</returns>
		const_iterator end() const noexcept { return m_data.cend(); }

		/// <summary>反転した先頭のイテレータを返す</summary>
		/// <returns>反転した先頭のイテレータ</returns>
		reverse_iterator rbegin() noexcept { return m_data.rbegin(); }
		/// <summary>反転した終端のイテレータを返す</summary>
		/// <returns>反転した終端のイテレータ</returns>
		reverse_iterator rend() noexcept { return m_data.rend(); }

		/// <summary>反転した先頭のイテレータを返す</summary>
		/// <returns>反転した先頭のイテレータ</returns>
		const_reverse_iterator rbegin() const noexcept { return m_data.rbegin(); }
		/// <summary>反転した終端のイテレータを返す</summary>
		/// <returns>反転した終端のイテレータ</returns>
		const_reverse_iterator rend() const noexcept { return m_data.rend(); }

		/// <summary>先頭のイテレータを返す</summary>
		/// <returns>先頭のイテレータ</returns>
		const_iterator cbegin() const noexcept { return m_data.cbegin(); }
		/// <summary>終端のイテレータを返す</summary>
		/// <returns>終端のイテレータ</returns>
		const_iterator cend() const noexcept { return m_data.cend(); }

		/// <summary>反転した先頭のイテレータを返す</summary>
		/// <returns>反転した先頭のイテレータ</returns>
		const_reverse_iterator crbegin() const noexcept { return m_data.crbegin(); }
		/// <summary>反転した終端のイテレータを返す</summary>
		/// <returns>反転した終端のイテレータ</returns>
		const_reverse_iterator crend() const noexcept { return m_data.crend(); }

		/// <summary>
		/// 余分に確保された領域を消す
		/// </summary>
		void shrink_to_fit() { data.shrink_to_fit(); }

		/// <summary>
		/// 配列と確保した領域を削除する.
		/// </summary>
		void release() { clear(); shrink_to_fit(); }

		/// <summary>配列を作成する領域を確保する</summary>
		/// <param name="w">横幅</param>
		/// <param name="h">縦幅</param>
		void reserve(size_t w, size_t h) { data.reserve(w*h); }

		/// <summary>配列の大きさを変更する</summary>
		/// <param name="w">横幅</param>
		/// <param name="h">縦幅</param>
		/// <param name="val">初期値</param>
		void resize(size_t w, size_t h, const Type& val) {
			if (w == width && h == height) return;
			width = w;
			height = h;
			data.assign(w*h, val);
		}
		/// <summary>配列の大きさを変更する</summary>
		/// <param name="w">横幅</param>
		/// <param name="h">縦幅</param>
		void resize(size_t w, size_t h) { resize(w, h, Type()); }
		/// <summary>配列の大きさを変更する</summary>
		/// <param name="size">大きさ</param>
		/// <param name="val">初期値</param>
		void resize(const IntSize& size, const Type& val) { resize(size.width, size.height, val); }
		/// <summary>配列の大きさを変更する</summary>
		/// <param name="size">大きさ</param>
		/// <param name="val">初期値</param>
		void resize(const IntSize& size) { resize(size.width, size.height, Type()); }

		/// <summary>
		/// 配列を削除する
		/// </summary>
		void clear() noexcept {
			data.clear();
			width = height = 0;
		}

		/// <summary>配列の大きさを返す</summary>
		/// <returns>配列の大きさ</returns>
		IntSize size() const noexcept { return IntSize(static_cast<int>(width), static_cast<int>(height)); }

		/// <summary>配列の要素数を返す</summary>
		/// <returns>配列の要素数</returns>
		size_t num_elements() const noexcept { return data.size(); }

		/// <summary>配列を値で埋める</summary>
		/// <param name="val">埋める値</param>
		void fill(const Type& val) { std::fill(data.begin(), data.end(), val); }

		/// <summary>配列を入れ替える</summary>
		/// <param name="other">入れ替える<see cref="Grid"/></param>
		void swap(Grid& other)
			noexcept(std::allocator_traits<allocator_type>::propagate_on_container_swap::value
				|| std::allocator_traits<allocator_type>::is_always_equal::value) {
			data.swap(other.data);
			std::swap(width, other.width);
			std::swap(height, other.height);
		}

	private:

		/// <summary>
		/// 動的1次元配列
		/// </summary>
		std::vector<Type> data;
		/// <summary>
		/// 横幅
		/// </summary>
		size_t width = 0;
		/// <summary>
		/// 縦幅
		/// </summary>
		size_t height = 0;

	};

}
