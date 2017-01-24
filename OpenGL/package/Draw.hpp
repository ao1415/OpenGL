#pragma once

#include <GL/glut.h>
#include <array>
#include <vector>
#include "Point.hpp"
#include "Vector.hpp"
#include "Size.hpp"
#include "Palette.hpp"

namespace opc {

	/// <summary>
	/// 2�����`��
	/// </summary>
	namespace Draw2D {

		/// <summary>
		/// �_��`�悷��N���X
		/// </summary>
		class Pixel {
		public:

			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			Pixel();
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x">x���W</param>
			/// <param name="y">y���W</param>
			Pixel(const int x, const int y);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x">x���W</param>
			/// <param name="y">y���W</param>
			Pixel(const double x, const double y);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="p">���W</param>
			Pixel(const Point& p);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="p">���W</param>
			Pixel(const Vec2& p);

			/// <summary>
			/// �`��֐�
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="color">�F</param>
			void draw(const Color& color) const { draw(1, color); }
			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			/// <param name="color">�F</param>
			void draw(const double size, const Color& color) const;

		protected:

			/// <summary>
			/// �`����W
			/// </summary>
			Vec2 point;

		};

		/// <summary>
		/// ����`�悷��N���X
		/// </summary>
		class Line {
		public:

			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			Line();
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x1">�n�_��x���W</param>
			/// <param name="y1">�n�_��y���W</param>
			/// <param name="x2">�I�_��x���W</param>
			/// <param name="y2">�I�_��y���W</param>
			Line(const int x1, const int y1, const int x2, const int y2);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x1">�n�_��x���W</param>
			/// <param name="y1">�n�_��y���W</param>
			/// <param name="x2">�I�_��x���W</param>
			/// <param name="y2">�I�_��y���W</param>
			Line(const double x1, const double y1, const double x2, const double y2);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="p1">�n�_�̍��W</param>
			/// <param name="p2">�I�_�̍��W</param>
			Line(const Point& p1, const Point& p2);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="ps">���W�z��</param>
			Line(const std::array<Point, 2>& ps);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="p1">�n�_�̍��W</param>
			/// <param name="p2">�I�_�̍��W</param>
			Line(const Vec2& p1, const Vec2& p2);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="ps">���W�z��</param>
			Line(const std::array<Vec2, 2>& ps);

			/// <summary>
			/// �`��֐�
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="color">�F</param>
			void draw(const Color& color) const { draw(1, color); }
			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			/// <param name="color">�F</param>
			void draw(const double size, const Color& color) const;

		protected:

			/// <summary>
			/// �`����W
			/// </summary>
			std::array<Vec2, 2> points;

		};

		/// <summary>
		/// �O�p�`��`�悷��N���X
		/// </summary>
		class Triangle {
		public:

			/// <summary>
			///	�R���X�g���N�^
			///	</summary>
			Triangle();
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x1">1�_�ڂ�x���W</param>
			/// <param name="y1">1�_�ڂ�y���W</param>
			/// <param name="x2">2�_�ڂ�x���W</param>
			/// <param name="y2">2�_�ڂ�y���W</param>
			/// <param name="x3">3�_�ڂ�x���W</param>
			/// <param name="y3">3�_�ڂ�y���W</param>
			Triangle(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x1">1�_�ڂ�x���W</param>
			/// <param name="y1">1�_�ڂ�y���W</param>
			/// <param name="x2">2�_�ڂ�x���W</param>
			/// <param name="y2">2�_�ڂ�y���W</param>
			/// <param name="x3">3�_�ڂ�x���W</param>
			/// <param name="y3">3�_�ڂ�y���W</param>
			Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="p1">1�_�ڂ̍��W</param>
			/// <param name="p2">2�_�ڂ̍��W</param>
			/// <param name="p3">3�_�ڂ̍��W</param>
			Triangle(const Point& p1, const Point& p2, const Point& p3);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="ps">���W�̔z��</param>
			Triangle(const std::array<Point, 3>& ps);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="p1">1�_�ڂ̍��W</param>
			/// <param name="p2">2�_�ڂ̍��W</param>
			/// <param name="p3">3�_�ڂ̍��W</param>
			Triangle(const Vec2& p1, const Vec2& p2, const Vec2& p3);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="ps">���W�̔z��</param>
			Triangle(const std::array<Vec2, 3>& ps);

			/// <summary>
			/// �`��֐�
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="color">�F</param>
			void draw(const Color& color) const { draw(1, color); }

		protected:

			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			/// <param name="color">�F</param>
			void draw(const double size, const Color& color) const;

			/// <summary>
			/// �`����W
			/// </summary>
			std::array<Vec2, 3> points;

		};

		/// <summary>
		///	�l�p�`��`�悷��N���X
		///	</summary>
		class Quad {
		public:

			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			Quad();
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x1">1�_�ڂ�x���W</param>
			/// <param name="y1">1�_�ڂ�y���W</param>
			/// <param name="x2">2�_�ڂ�x���W</param>
			/// <param name="y2">2�_�ڂ�y���W</param>
			/// <param name="x3">3�_�ڂ�x���W</param>
			/// <param name="y3">3�_�ڂ�y���W</param>
			/// <param name="x4">4�_�ڂ�x���W</param>
			/// <param name="y4">4�_�ڂ�y���W</param>
			Quad(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3, const int x4, const int y4);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x1">1�_�ڂ�x���W</param>
			/// <param name="y1">1�_�ڂ�y���W</param>
			/// <param name="x2">2�_�ڂ�x���W</param>
			/// <param name="y2">2�_�ڂ�y���W</param>
			/// <param name="x3">3�_�ڂ�x���W</param>
			/// <param name="y3">3�_�ڂ�y���W</param>
			/// <param name="x4">4�_�ڂ�x���W</param>
			/// <param name="y4">4�_�ڂ�y���W</param>
			Quad(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3, const double x4, const double y4);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="p1">1�_�ڂ̍��W</param>
			/// <param name="p2">2�_�ڂ̍��W</param>
			/// <param name="p3">3�_�ڂ̍��W</param>
			/// <param name="p4">4�_�ڂ̍��W</param>
			Quad(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="p1">���W�̔z��</param>
			Quad(const std::array<Point, 4>& ps);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="p1">1�_�ڂ̍��W</param>
			/// <param name="p2">2�_�ڂ̍��W</param>
			/// <param name="p3">3�_�ڂ̍��W</param>
			/// <param name="p4">4�_�ڂ̍��W</param>
			Quad(const Vec2& p1, const Vec2& p2, const Vec2& p3, const Vec2& p4);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="p1">���W�̔z��</param>
			Quad(const std::array<Vec2, 4>& ps);

			/// <summary>
			/// �`��֐�
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="color">�F</param>
			void draw(const Color& color) const { draw(1, color); }

		protected:

			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			/// <param name="color">�F</param>
			void draw(const double size, const Color& color) const;

			/// <summary>
			/// �`����W
			/// </summary>
			std::array<Vec2, 4> points;

		};

		/// <summary>
		///	�����`��`�悷��N���X
		///	</summary>
		class Rect : public Quad {
		public:

			/// <summary>
			///	�R���X�g���N�^
			///	</summary>
			Rect();
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x">x���W</param>
			/// <param name="y">y���W</param>
			/// <param name="width">��</param>
			/// <param name="height">����</param>
			Rect(const int x, const int y, const int width, const int height);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x">x���W</param>
			/// <param name="y">y���W</param>
			/// <param name="width">��</param>
			/// <param name="height">����</param>
			Rect(const double x, const double y, const double width, const double height);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="pos">���W</param>
			/// <param name="size">�傫��</param>
			Rect(const Point& pos, const RealSize& size);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="pos">���W</param>
			/// <param name="size">�傫��</param>
			Rect(const Vec2& pos, const RealSize& size);

		};
	}

	/// <summary>
	/// 3�����`��
	/// </summary>
	namespace Draw3D {

		/// <summary>
		///	�_��`�悷��N���X
		///	</summary>
		class Pixel {
		public:

			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			Pixel();
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x">x���W</param>
			/// <param name="y">y���W</param>
			/// <param name="z">z���W</param>
			Pixel(const int x, const int y, const int z);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x">x���W</param>
			/// <param name="y">y���W</param>
			/// <param name="z">z���W</param>
			Pixel(const double x, const double y, const double z);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="v">���W</param>
			Pixel(const Point3D& v);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="v">���W</param>
			Pixel(const Vec3& v);

			/// <summary>
			/// �`��֐�
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="color">�F</param>
			void draw(const Color& color) const { draw(1, color); }
			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			/// <param name="color">�F</param>
			void draw(const double size, const Color& color) const;

		protected:

			/// <summary>
			/// �`����W
			/// </summary>
			Vec3 vec;

		};

		/// <summary>
		///	����`�悷��N���X
		///	</summary>
		class Line {
		public:

			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			Line();
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x1">�n�_��x���W</param>
			/// <param name="y1">�n�_��y���W</param>
			/// <param name="z1">�n�_��z���W</param>
			/// <param name="x2">�I�_��x���W</param>
			/// <param name="y2">�I�_��y���W</param>
			/// <param name="z2">�I�_��z���W</param>
			Line(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x1">�n�_��x���W</param>
			/// <param name="y1">�n�_��y���W</param>
			/// <param name="z1">�n�_��z���W</param>
			/// <param name="x2">�I�_��x���W</param>
			/// <param name="y2">�I�_��y���W</param>
			/// <param name="z2">�I�_��z���W</param>
			Line(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="v1">�n�_�̍��W</param>
			/// <param name="v2">�n�_�̍��W</param>
			Line(const Point3D& v1, const Point3D& v2);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="vs">���W�̔z��</param>
			Line(const std::array<Point3D, 2>& vs);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="v1">�n�_�̍��W</param>
			/// <param name="v2">�n�_�̍��W</param>
			Line(const Vec3& v1, const Vec3& v2);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="vs">���W�̔z��</param>
			Line(const std::array<Vec3, 2>& vs);

			/// <summary>
			/// �`��֐�
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="color">�F</param>
			void draw(const Color& color) const { draw(1, color); }
			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			/// <param name="color">�F</param>
			void draw(const double size, const Color& color) const;

		protected:

			/// <summary>
			/// �`����W
			/// </summary>
			std::array<Vec3, 2> vectors;

		};

		/// <summary>
		///	�O�p�`��`�悷��N���X
		///	</summary>
		class Triangle {
		public:

			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			Triangle();
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x1">1�Ԗڂ�x���W</param>
			/// <param name="y1">1�Ԗڂ�y���W</param>
			/// <param name="z1">1�Ԗڂ�z���W</param>
			/// <param name="x2">2�Ԗڂ�x���W</param>
			/// <param name="y2">2�Ԗڂ�y���W</param>
			/// <param name="z2">2�Ԗڂ�z���W</param>
			/// <param name="x3">3�Ԗڂ�x���W</param>
			/// <param name="y3">3�Ԗڂ�y���W</param>
			/// <param name="z3">3�Ԗڂ�z���W</param>
			Triangle(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2, const int x3, const int y3, const int z3);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x1">1�Ԗڂ�x���W</param>
			/// <param name="y1">1�Ԗڂ�y���W</param>
			/// <param name="z1">1�Ԗڂ�z���W</param>
			/// <param name="x2">2�Ԗڂ�x���W</param>
			/// <param name="y2">2�Ԗڂ�y���W</param>
			/// <param name="z2">2�Ԗڂ�z���W</param>
			/// <param name="x3">3�Ԗڂ�x���W</param>
			/// <param name="y3">3�Ԗڂ�y���W</param>
			/// <param name="z3">3�Ԗڂ�z���W</param>
			Triangle(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="v1">1�Ԗڂ̍��W</param>
			/// <param name="v2">2�Ԗڂ̍��W</param>
			/// <param name="v3">3�Ԗڂ̍��W</param>
			Triangle(const Point3D& v1, const Point3D& v2, const Point3D& v3);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="vs">���W�̔z��</param>
			Triangle(const std::array<Point3D, 3>& vs);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="v1">1�Ԗڂ̍��W</param>
			/// <param name="v2">2�Ԗڂ̍��W</param>
			/// <param name="v3">3�Ԗڂ̍��W</param>
			Triangle(const Vec3& v1, const Vec3& v2, const Vec3& v3);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="vs">���W�̔z��</param>
			Triangle(const std::array<Vec3, 3>& vs);

			/// <summary>
			/// �`��֐�
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="color">�F</param>
			void draw(const Color& color) const { draw(1, color); }

		protected:

			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			/// <param name="color">�F</param>
			void draw(const double size, const Color& color) const;

			/// <summary>
			/// �`����W
			/// </summary>
			std::array<Vec3, 3> vectors;

		};

		/// <summary>
		///	�l�p�`��`�悷��N���X
		///	</summary>
		class Quad {
		public:

			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			Quad();
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x1">1�Ԗڂ�x���W</param>
			/// <param name="y1">1�Ԗڂ�y���W</param>
			/// <param name="z1">1�Ԗڂ�z���W</param>
			/// <param name="x2">2�Ԗڂ�x���W</param>
			/// <param name="y2">2�Ԗڂ�y���W</param>
			/// <param name="z2">2�Ԗڂ�z���W</param>
			/// <param name="x3">3�Ԗڂ�x���W</param>
			/// <param name="y3">3�Ԗڂ�y���W</param>
			/// <param name="z3">3�Ԗڂ�z���W</param>
			/// <param name="x4">4�Ԗڂ�x���W</param>
			/// <param name="y4">4�Ԗڂ�y���W</param>
			/// <param name="z4">4�Ԗڂ�z���W</param>
			Quad(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2, const int x3, const int y3, const int z3, const int x4, const int y4, const int z4);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x1">1�Ԗڂ�x���W</param>
			/// <param name="y1">1�Ԗڂ�y���W</param>
			/// <param name="z1">1�Ԗڂ�z���W</param>
			/// <param name="x2">2�Ԗڂ�x���W</param>
			/// <param name="y2">2�Ԗڂ�y���W</param>
			/// <param name="z2">2�Ԗڂ�z���W</param>
			/// <param name="x3">3�Ԗڂ�x���W</param>
			/// <param name="y3">3�Ԗڂ�y���W</param>
			/// <param name="z3">3�Ԗڂ�z���W</param>
			/// <param name="x4">4�Ԗڂ�x���W</param>
			/// <param name="y4">4�Ԗڂ�y���W</param>
			/// <param name="z4">4�Ԗڂ�z���W</param>
			Quad(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3, const double x4, const double y4, const double z4);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="v1">1�Ԗڂ̍��W</param>
			/// <param name="v2">2�Ԗڂ̍��W</param>
			/// <param name="v3">3�ڂ̍��W</param>
			/// <param name="v4">4�Ԗڂ̍��W</param>
			Quad(const Point3D& v1, const Point3D& v2, const Point3D& v3, const Point3D& v4);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="vs">���W�̔z��</param>
			Quad(const std::array<Point3D, 4>& vs);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="v1">1�Ԗڂ̍��W</param>
			/// <param name="v2">2�Ԗڂ̍��W</param>
			/// <param name="v3">3�ڂ̍��W</param>
			/// <param name="v4">4�Ԗڂ̍��W</param>
			Quad(const Vec3& v1, const Vec3& v2, const Vec3& v3, const Vec3& v4);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="vs">���W�̔z��</param>
			Quad(const std::array<Vec3, 4>& vs);

			/// <summary>
			/// �`��֐�
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="color">�F</param>
			void draw(const Color& color) const { draw(1, color); }

		protected:

			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			/// <param name="color">�F</param>
			void draw(const double size, const Color& color) const;

			/// <summary>
			/// �`����W
			/// </summary>
			std::array<Vec3, 4> vectors;

		};

		/// <summary>
		///	�����`��`�悷��N���X
		///	</summary>
		class Rect : public Quad {
		public:

			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			Rect();
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x">x���W</param>
			/// <param name="y">y���W</param>
			/// <param name="z">z���W</param>
			/// <param name="sx">��</param>
			/// <param name="sy">����</param>
			/// <param name="sz">���s</param>
			Rect(const int x, const int y, const int z, const int sx, const int sy, const int sz);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x">x���W</param>
			/// <param name="y">y���W</param>
			/// <param name="z">z���W</param>
			/// <param name="sx">��</param>
			/// <param name="sy">����</param>
			/// <param name="sz">���s</param>
			Rect(const double x, const double y, const double z, const double sx, const double sy, const double sz);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="v1">���W</param>
			/// <param name="v2">�傫��</param>
			Rect(const Point3D& v1, const Point3D& v2);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="v1">���W</param>
			/// <param name="v2">�傫��</param>
			Rect(const Vec3& v1, const Vec3& v2);

		};

		class Box {
		public:

			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			Box();
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x">x���W</param>
			/// <param name="y">y���W</param>
			/// <param name="z">z���W</param>
			/// <param name="sx">����</param>
			/// <param name="sy">�c��</param>
			/// <param name="sz">���s</param>
			Box(const int x, const int y, const int z, const int sx, const int sy, const int sz);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="x">x���W</param>
			/// <param name="y">y���W</param>
			/// <param name="z">z���W</param>
			/// <param name="sx">����</param>
			/// <param name="sy">�c��</param>
			/// <param name="sz">���s</param>
			Box(const double x, const double y, const double z, const double sx, const double sy, const double sz);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="v">���W</param>
			/// <param name="s">�傫��</param>
			Box(const Point3D& v, const Point3D& s);
			/// <summary>�R���X�g���N�^</summary>
			/// <param name="v">���W</param>
			/// <param name="s">�傫��</param>
			Box(const Vec3& v, const Vec3& s);

			/// <summary>
			/// �`��֐�
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="color">�F</param>
			void draw(const Color& color) const { draw(1, color); }

		protected:

			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>�`��֐�</summary>
			/// <param name="size">�傫��</param>
			/// <param name="color">�F</param>
			void draw(const double size, const Color& color) const;

			/// <summary>
			/// �`����W
			/// </summary>
			Vec3 pos;
			Vec3 size;

		};

	}

}
