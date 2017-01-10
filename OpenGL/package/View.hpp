#pragma once

#include <GL/glut.h>

#include "Vector.hpp"

namespace opc {

	namespace View {

		///	<summary>視野の設定</summary>
		///	<param name="fovy">y軸方向の視野角</param>
		///	<param name="aspect">y軸方向に対するx軸方向の視野角</param>
		///	<param name="zNear">手前</param>
		///	<param name="zFar">奥行</param>
		void Perspective(const double fovy = 30, const double aspect = 1, const double zNear = 1, const double zFar = 500);

		///	<summary>視点の設定</summary>
		///	<param name="eye">目の位置</param>
		///	<param name="center">視点の位置</param>
		///	<param name="up">上の設定</param>
		void LookAt(const RealVector& eye, const RealVector& center, const RealVector& up);

		///	<summary>平行移動</summary>
		///	<param name="vector">移動方向</param>
		void Translate(const RealVector& vector);

		///	<summary>回転</summary>
		///	<param name="vector">回転方向</param>
		void Rotate(const double angle, const RealVector& vector);

	}

}
