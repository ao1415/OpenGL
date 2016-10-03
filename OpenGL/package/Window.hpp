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

	/// <summary>ウインドウの設定を行うクラス</summary>
	class Window {
	public:

		/// <summary>ウインドウの大きさを設定する</summary>
		/// <param name="width">横幅</param>
		/// <param name="height">高さ</param>
		static void setSize(const int width, const int height);
		/// <summary>ウインドウの大きさを設定する</summary>
		/// <param name="_size">大きさ</param>
		static void setSize(const IntSize& _size);

		/// <summary>ウインドウのタイトルを設定する</summary>
		/// <param name="name">タイトル</param>
		static void setTitle(const std::string& name);

		/// <summary>画面がクリアされるときの色を設定する</summary>
		/// <param name="r">赤色成分(0～255)</param>
		/// <param name="g">緑色成分(0～255)</param>
		/// <param name="b">青色成分(0～255)</param>
		static void setClearColor(const int r, const int g, const int b);
		/// <summary>画面がクリアされるときの色を設定する</summary>
		/// <param name="r">赤色成分(0～255)</param>
		/// <param name="g">緑色成分(0～255)</param>
		/// <param name="b">青色成分(0～255)</param>
		/// <param name="a">透明度(0～255)</param>
		static void setClearColor(const int r, const int g, const int b, const int a);
		/// <summary>画面がクリアされるときの色を設定する</summary>
		/// <param name="_color">色</param>
		static void setClearColor(const Color& _color);

		/// <summary>ウインドウの座標を設定する(2D座標)</summary>
		/// <param name="left">左端の座標値</param>
		/// <param name="right">右端の座標値</param>
		/// <param name="bottom">下端の座標値</param>
		/// <param name="top">上端の座標値</param>
		static void setOrtho2D(const double left, const double right, const double bottom, const double top);
		/// <summary>ウインドウの座標を設定する(2D座標)</summary>
		/// <param name="left_top">左上の座標値</param>
		/// <param name="right_bottom">右下の座標値</param>
		static void setOrtho2D(const RealPoint& left_top, const RealPoint& right_bottom);

		/// <summary>ウインドウの座標を設定する(3D座標)</summary>
		/// <param name="left">左端の座標値</param>
		/// <param name="right">右端の座標値</param>
		/// <param name="bottom">下端の座標値</param>
		/// <param name="top">上端の座標値</param>
		/// <param name="zNear">手前の座標値</param>
		/// <param name="zFar">奥の座標値</param>
		static void setOrtho3D(const double left, const double right, const double bottom, const double top, const double zNear, const double zFar);
		/// <summary>ウインドウの座標を設定する(3D座標)</summary>
		/// <param name="left_top">手前左上の座標値</param>
		/// <param name="right_bottom">奥右下の座標値</param>
		static void setOrtho3D(const RealVector& left_top_near, const RealVector& right_bottom_far);

		friend System;

	private:

		static IntSize size;
		static std::string title;
		static Color clearColor;

		/// <summary>
		/// <para>0:左上の座標</para>
		/// <para>1:右下の座標</para>
		/// </summary>
		static RealPoint ortho2DPoint[2];

		/// <summary>
		/// <para>0:手前左上のの座標</para>
		/// <para>1:奥右下の座標</para>
		/// </summary>
		static RealVector ortho3DPoint[2];

	};


}
