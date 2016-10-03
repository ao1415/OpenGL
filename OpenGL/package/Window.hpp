#pragma once

#include <string>

#include "Display.hpp"
#include "AcyncTimer.hpp"
#include "Palette.hpp"
#include "Point.hpp"
#include "Vector.hpp"
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
		static void setSize(const IntSize& _size);

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

		/// <summary>�E�C���h�E�̍��W��ݒ肷��(2D���W)</summary>
		/// <param name="left">���[�̍��W�l</param>
		/// <param name="right">�E�[�̍��W�l</param>
		/// <param name="bottom">���[�̍��W�l</param>
		/// <param name="top">��[�̍��W�l</param>
		static void setOrtho2D(const double left, const double right, const double bottom, const double top);
		/// <summary>�E�C���h�E�̍��W��ݒ肷��(2D���W)</summary>
		/// <param name="left_top">����̍��W�l</param>
		/// <param name="right_bottom">�E���̍��W�l</param>
		static void setOrtho2D(const RealPoint& left_top, const RealPoint& right_bottom);

		/// <summary>�E�C���h�E�̍��W��ݒ肷��(3D���W)</summary>
		/// <param name="left">���[�̍��W�l</param>
		/// <param name="right">�E�[�̍��W�l</param>
		/// <param name="bottom">���[�̍��W�l</param>
		/// <param name="top">��[�̍��W�l</param>
		/// <param name="zNear">��O�̍��W�l</param>
		/// <param name="zFar">���̍��W�l</param>
		static void setOrtho3D(const double left, const double right, const double bottom, const double top, const double zNear, const double zFar);
		/// <summary>�E�C���h�E�̍��W��ݒ肷��(3D���W)</summary>
		/// <param name="left_top">��O����̍��W�l</param>
		/// <param name="right_bottom">���E���̍��W�l</param>
		static void setOrtho3D(const RealVector& left_top_near, const RealVector& right_bottom_far);

		friend System;

	private:

		static IntSize size;
		static std::string title;
		static Color clearColor;

		/// <summary>
		/// <para>0:����̍��W</para>
		/// <para>1:�E���̍��W</para>
		/// </summary>
		static RealPoint ortho2DPoint[2];

		/// <summary>
		/// <para>0:��O����̂̍��W</para>
		/// <para>1:���E���̍��W</para>
		/// </summary>
		static RealVector ortho3DPoint[2];

	};


}
