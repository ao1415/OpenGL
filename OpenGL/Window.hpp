#pragma once

#include <string>

#include "Display.hpp"
#include "AcyncTimer.hpp"
#include "Palette.hpp"
#include "Point.hpp"
#include "Size.hpp"
#include "SystemState.hpp"

namespace opc {

	/// <summary>�E�C���h�E�̐ݒ���s���N���X</summary>
	class Window {
	public:

		/// <summary>�E�C���h�E�̑傫����ݒ肷��</summary>
		/// <param name="width">����</param>
		/// <param name="height">����</param>
		static void setSize(const int width, const int height);
		/// <summary>�E�C���h�E�̑傫����ݒ肷��</summary>
		/// <param name="_size">�傫��</param>
		static void setSize(const Size& _size);

		/// <summary>�E�C���h�E�̃^�C�g����ݒ肷��</summary>
		/// <param name="name">�^�C�g��</param>
		static void setTitle(const std::string& name);

		/// <summary>��ʂ��N���A�����Ƃ��̐F��ݒ肷��</summary>
		/// <param name="r">�ԐF����(0�`255)</param>
		/// <param name="g">�ΐF����(0�`255)</param>
		/// <param name="b">�F����(0�`255)</param>
		static void setClearColor(const int r, const int g, const int b);
		/// <summary>��ʂ��N���A�����Ƃ��̐F��ݒ肷��</summary>
		/// <param name="r">�ԐF����(0�`255)</param>
		/// <param name="g">�ΐF����(0�`255)</param>
		/// <param name="b">�F����(0�`255)</param>
		/// <param name="a">�����x(0�`255)</param>
		static void setClearColor(const int r, const int g, const int b, const int a);
		/// <summary>��ʂ��N���A�����Ƃ��̐F��ݒ肷��</summary>
		/// <param name="_color">�F</param>
		static void setClearColor(const Color& _color);

		friend System;

	private:

		static Size size;
		static std::string title;
		static Color clearColor;

	};


}
