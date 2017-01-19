#pragma once

#include <GL/glut.h>

#include "Vector.hpp"

namespace opc {

	namespace View {

		///	<summary>����̐ݒ�</summary>
		///	<param name="fovy">y�������̎���p</param>
		///	<param name="aspect">y�������ɑ΂���x�������̎���p</param>
		///	<param name="zNear">��O</param>
		///	<param name="zFar">���s</param>
		void Perspective(const double fovy = 30, const double aspect = 1, const double zNear = 1, const double zFar = 500);

		///	<summary>���_�̐ݒ�</summary>
		///	<param name="eye">�ڂ̈ʒu</param>
		///	<param name="center">���_�̈ʒu</param>
		///	<param name="up">��̐ݒ�</param>
		void LookAt(const Vec3& eye, const Vec3& center, const Vec3& up);

		///	<summary>���s�ړ�</summary>
		///	<param name="vector">�ړ�����</param>
		void Translate(const Vec3& vector);

		///	<summary>��]</summary>
		///	<param name="vector">��]����</param>
		void Rotate(const double angle, const Vec3& vector);

	}

}
