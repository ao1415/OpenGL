#pragma once

#include <vector>

#include "Point.hpp"
#include "Size.hpp"
#include "Property.hpp"

namespace opc {

	//�Q�l���C�u�����FSiv3D

	/// <summary>
	///	���I2�����z��
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
		///	�R���X�g���N�^
		///	</summary>
		Grid() = default;
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="w">��</param>
		/// <param name="h">�c</param>
		Grid(const size_t w, const size_t h) : data(w*h, Type()), width(w), height(h) {}
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="size">�傫��</param>
		Grid(const IntSize& size) : Grid(size.width, size.height) {}
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="w">��</param>
		/// <param name="h">�c</param>
		/// <param name="val">�����l</param>
		Grid(const size_t w, const size_t h, const Type& val) : data(w*h, val), width(w), height(h) {}
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="size">�傫��</param>
		/// <param name="val">�����l</param>
		Grid(const IntSize& size, const Type& val) : Grid(size.width, size.height, val) {}

		/// <summary>�R���X�g���N�^</summary>
		/// <param name="g">�R�s�[����<see cref="Grid"/></param>
		Grid(const Grid& g) = default;
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="g">�ړ�����<see cref="Grid"/></param>
		Grid(Grid&& g) noexcept {
			width = g.width;
			height = g.height;
			data = std::move(g.data);
			g.width = g.height = 0;
		}

		/// <summary>�R�s�[���Z�q</summary>
		/// <param name="other">�R�s�[����<see cref="Grid"/></param>
		/// <returns><see cref="Grid"/></returns>
		Grid& operator=(const Grid& other) = default;
		/// <summary>���[�u���Z�q</summary>
		/// <param name="other">�ړ�����<see cref="Grid"/></param>
		/// <returns><see cref="Grid"/></returns>
		Grid& operator=(Grid&& other) = default;

		/// <summary>�Q�Ɣ͈͂̊m�F</summary>
		/// <param name="y">y���W</param>
		/// <param name="x">x���W</param>
		/// <returns>�����Ȃ��true, ����ȊO��false</returns>
		bool inBounds(size_t y, size_t x) const noexcept {
			return (0 <= y && y < height && 0 <= x && x < width);
		}

		/// <summary>�z��Q��</summary>
		/// <param name="y">y���W</param>
		/// <param name="x">x���W</param>
		/// <returns>�Q�ƒl</returns>
		Type& at(size_t y, size_t x) {
			if (!isBounds(y, x)) throw std::out_of_range("Grid::at");
			return data[y*width + x];
		}
		/// <summary>�z��Q��</summary>
		/// <param name="y">y���W</param>
		/// <param name="x">x���W</param>
		/// <returns>�Q�ƒl</returns>
		const Type& at(size_t y, size_t x) const {
			if (!isBounds(y, x)) throw std::out_of_range("Grid::at");
			return data[y*width + x];
		}

		/// <summary>�z��Q��</summary>
		/// <param name="pos">���W</param>
		/// <returns>�Q�ƒl</returns>
		Type& at(const IntPoint& pos) { return at(pos.y, pos.x); }
		/// <summary>�z��Q��</summary>
		/// <param name="pos">���W</param>
		/// <returns>�Q�ƒl</returns>
		const Type& at(const IntPoint& pos) const { return at(pos.y, pos.x); }

		/// <summary>�z��Q��</summary>
		/// <param name="index">�Y����</param>
		/// <returns>�Q�ƒl</returns>
		Type* operator[](size_t index) { return &data[index*width]; }
		/// <summary>�z��Q��</summary>
		/// <param name="index">�Y����</param>
		/// <returns>�Q�ƒl</returns>
		const Type* operator[](size_t index) const { return &data[index*width]; }

		/// <summary>�z��Q��</summary>
		/// <param name="pos">���W</param>
		/// <returns>�Q�ƒl</returns>
		Type& operator[](const IntPoint& pos) { return data[pos.y*width + pos.x]; }
		/// <summary>�z��Q��</summary>
		/// <param name="pos">���W</param>
		/// <returns>�Q�ƒl</returns>
		const Type& operator[](const IntPoint& pos) const { return data[pos.y*width + pos.x]; }

		/// <summary>�z�񂪋󂩂�Ԃ�</summary>
		/// <returns>��Ȃ��true, ����ȊO��false</returns>
		Property_Get(bool, isEmpty) const noexcept { return data.empty(); }
		/// <summary>������Ԃ�</summary>
		/// <returns>����</returns>
		Property_Get(size_t, Width) const noexcept { return width; }
		/// <summary>�c����Ԃ�</summary>
		/// <returns>�c��</returns>
		Property_Get(size_t, Height) const noexcept { return height; }

		/// <summary>�擪�̃C�e���[�^��Ԃ�</summary>
		/// <returns>�擪�̃C�e���[�^</returns>
		iterator begin() noexcept { return m_data.begin(); }
		/// <summary>�I�[�̃C�e���[�^��Ԃ�</summary>
		/// <returns>�I�[�̃C�e���[�^</returns>
		iterator end() noexcept { return m_data.end(); }

		/// <summary>�擪�̃C�e���[�^��Ԃ�</summary>
		/// <returns>�擪�̃C�e���[�^</returns>
		const_iterator begin() const noexcept { return m_data.cbegin(); }
		/// <summary>�I�[�̃C�e���[�^��Ԃ�</summary>
		/// <returns>�I�[�̃C�e���[�^</returns>
		const_iterator end() const noexcept { return m_data.cend(); }

		/// <summary>���]�����擪�̃C�e���[�^��Ԃ�</summary>
		/// <returns>���]�����擪�̃C�e���[�^</returns>
		reverse_iterator rbegin() noexcept { return m_data.rbegin(); }
		/// <summary>���]�����I�[�̃C�e���[�^��Ԃ�</summary>
		/// <returns>���]�����I�[�̃C�e���[�^</returns>
		reverse_iterator rend() noexcept { return m_data.rend(); }

		/// <summary>���]�����擪�̃C�e���[�^��Ԃ�</summary>
		/// <returns>���]�����擪�̃C�e���[�^</returns>
		const_reverse_iterator rbegin() const noexcept { return m_data.rbegin(); }
		/// <summary>���]�����I�[�̃C�e���[�^��Ԃ�</summary>
		/// <returns>���]�����I�[�̃C�e���[�^</returns>
		const_reverse_iterator rend() const noexcept { return m_data.rend(); }

		/// <summary>�擪�̃C�e���[�^��Ԃ�</summary>
		/// <returns>�擪�̃C�e���[�^</returns>
		const_iterator cbegin() const noexcept { return m_data.cbegin(); }
		/// <summary>�I�[�̃C�e���[�^��Ԃ�</summary>
		/// <returns>�I�[�̃C�e���[�^</returns>
		const_iterator cend() const noexcept { return m_data.cend(); }

		/// <summary>���]�����擪�̃C�e���[�^��Ԃ�</summary>
		/// <returns>���]�����擪�̃C�e���[�^</returns>
		const_reverse_iterator crbegin() const noexcept { return m_data.crbegin(); }
		/// <summary>���]�����I�[�̃C�e���[�^��Ԃ�</summary>
		/// <returns>���]�����I�[�̃C�e���[�^</returns>
		const_reverse_iterator crend() const noexcept { return m_data.crend(); }

		/// <summary>
		/// �]���Ɋm�ۂ��ꂽ�̈������
		/// </summary>
		void shrink_to_fit() { data.shrink_to_fit(); }

		/// <summary>
		/// �z��Ɗm�ۂ����̈���폜����.
		/// </summary>
		void release() { clear(); shrink_to_fit(); }

		/// <summary>�z����쐬����̈���m�ۂ���</summary>
		/// <param name="w">����</param>
		/// <param name="h">�c��</param>
		void reserve(size_t w, size_t h) { data.reserve(w*h); }

		/// <summary>�z��̑傫����ύX����</summary>
		/// <param name="w">����</param>
		/// <param name="h">�c��</param>
		/// <param name="val">�����l</param>
		void resize(size_t w, size_t h, const Type& val) {
			if (w == width && h == height) return;
			width = w;
			height = h;
			data.assign(w*h, val);
		}
		/// <summary>�z��̑傫����ύX����</summary>
		/// <param name="w">����</param>
		/// <param name="h">�c��</param>
		void resize(size_t w, size_t h) { resize(w, h, Type()); }
		/// <summary>�z��̑傫����ύX����</summary>
		/// <param name="size">�傫��</param>
		/// <param name="val">�����l</param>
		void resize(const IntSize& size, const Type& val) { resize(size.width, size.height, val); }
		/// <summary>�z��̑傫����ύX����</summary>
		/// <param name="size">�傫��</param>
		/// <param name="val">�����l</param>
		void resize(const IntSize& size) { resize(size.width, size.height, Type()); }

		/// <summary>
		/// �z����폜����
		/// </summary>
		void clear() noexcept {
			data.clear();
			width = height = 0;
		}

		/// <summary>�z��̑傫����Ԃ�</summary>
		/// <returns>�z��̑傫��</returns>
		IntSize size() const noexcept { return IntSize(static_cast<int>(width), static_cast<int>(height)); }

		/// <summary>�z��̗v�f����Ԃ�</summary>
		/// <returns>�z��̗v�f��</returns>
		size_t num_elements() const noexcept { return data.size(); }

		/// <summary>�z���l�Ŗ��߂�</summary>
		/// <param name="val">���߂�l</param>
		void fill(const Type& val) { std::fill(data.begin(), data.end(), val); }

		/// <summary>�z������ւ���</summary>
		/// <param name="other">����ւ���<see cref="Grid"/></param>
		void swap(Grid& other)
			noexcept(std::allocator_traits<allocator_type>::propagate_on_container_swap::value
				|| std::allocator_traits<allocator_type>::is_always_equal::value) {
			data.swap(other.data);
			std::swap(width, other.width);
			std::swap(height, other.height);
		}

	private:

		/// <summary>
		/// ���I1�����z��
		/// </summary>
		std::vector<Type> data;
		/// <summary>
		/// ����
		/// </summary>
		size_t width = 0;
		/// <summary>
		/// �c��
		/// </summary>
		size_t height = 0;

	};

}
