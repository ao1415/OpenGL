#pragma once

#include <GL/glut.h>
#include <array>
#include <vector>
#include "Point.hpp"
#include "Vector.hpp"
#include "Size.hpp"
#include "Palette.hpp"

namespace opc {

	namespace Draw2D {
		/// <summary>点を描画するクラス</summary>
		class Pixel {
		public:

			Pixel();
			Pixel(const int x, const int y);
			Pixel(const double x, const double y);
			Pixel(const IntPoint& p);
			Pixel(const RealPoint& p);

			void draw() const { draw(1, Palette::White); }
			void draw(const double size) const { draw(size, Palette::White); }
			void draw(const Color& color) const { draw(1, color); }
			void draw(const double size, const Color& color) const;

		protected:

			RealPoint point;

		};

		/// <summary>線を描画するクラス</summary>
		class Line {
		public:

			Line();
			Line(const int x1, const int y1, const int x2, const int y2);
			Line(const double x1, const double y1, const double x2, const double y2);
			Line(const IntPoint& p1, const IntPoint& p2);
			Line(const std::array<IntPoint, 2>& ps);
			Line(const RealPoint& p1, const RealPoint& p2);
			Line(const std::array<RealPoint, 2>& ps);

			void draw() const { draw(1, Palette::White); }
			void draw(const double size) const { draw(size, Palette::White); }
			void draw(const Color& color) const { draw(1, color); }
			void draw(const double size, const Color& color) const;

		protected:

			std::array<RealPoint, 2> points;

		};

		/// <summary>三角形を描画するクラス</summary>
		class Triangle {
		public:

			Triangle();
			Triangle(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3);
			Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3);
			Triangle(const IntPoint& p1, const IntPoint& p2, const IntPoint& p3);
			Triangle(const std::array<IntPoint, 3>& ps);
			Triangle(const RealPoint& p1, const RealPoint& p2, const RealPoint& p3);
			Triangle(const std::array<RealPoint, 3>& ps);

			void draw() const { draw(1, Palette::White); }
			void draw(const Color& color) const { draw(1, color); }

		protected:

			void draw(const double size) const { draw(size, Palette::White); }
			void draw(const double size, const Color& color) const;

			std::array<RealPoint, 3> points;

		};

		/// <summary>四角形を描画するクラス</summary>
		class Quad {
		public:

			Quad();
			Quad(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3, const int x4, const int y4);
			Quad(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3, const double x4, const double y4);
			Quad(const IntPoint& p1, const IntPoint& p2, const IntPoint& p3, const IntPoint& p4);
			Quad(const std::array<IntPoint, 4>& ps);
			Quad(const RealPoint& p1, const RealPoint& p2, const RealPoint& p3, const RealPoint& p4);
			Quad(const std::array<RealPoint, 4>& ps);

			void draw() const { draw(1, Palette::White); }
			void draw(const Color& color) const { draw(1, color); }

		protected:

			void draw(const double size) const { draw(size, Palette::White); }
			void draw(const double size, const Color& color) const;

			std::array<RealPoint, 4> points;

		};

		/// <summary>長方形を描画するクラス</summary>
		class Rect : public Quad {
		public:

			Rect();
			Rect(const int x, const int y, const int width, const int height);
			Rect(const double x, const double y, const double width, const double height);
			Rect(const IntPoint& pos, const Size& size);
			Rect(const RealPoint& pos, const Size& size);

		};
	}

	namespace Draw3D {

		/// <summary>点を描画するクラス</summary>
		class Pixel {
		public:

			Pixel();
			Pixel(const int x, const int y, const int z);
			Pixel(const double x, const double y, const double z);
			Pixel(const IntVector& v);
			Pixel(const RealVector& v);

			void draw() const { draw(1, Palette::White); }
			void draw(const double size) const { draw(size, Palette::White); }
			void draw(const Color& color) const { draw(1, color); }
			void draw(const double size, const Color& color) const;

		private:

			RealVector vec;

		};

		/// <summary>線を描画するクラス</summary>
		class Line {
		public:

			Line();
			Line(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2);
			Line(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2);
			Line(const IntVector& v1, const IntVector& v2);
			Line(const std::array<IntVector, 2>& vs);
			Line(const RealVector& v1, const RealVector& v2);
			Line(const std::array<RealVector, 2>& vs);

			void draw() const { draw(1, Palette::White); }
			void draw(const double size) const { draw(size, Palette::White); }
			void draw(const Color& color) const { draw(1, color); }
			void draw(const double size, const Color& color) const;

		protected:

			std::array<RealVector, 2> vectors;

		};

		/// <summary>三角形を描画するクラス</summary>
		class Triangle {
		public:

			Triangle();
			Triangle(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2, const int x3, const int y3, const int z3);
			Triangle(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3);
			Triangle(const IntVector& v1, const IntVector& v2, const IntVector& v3);
			Triangle(const std::array<IntVector, 3>& vs);
			Triangle(const RealVector& v1, const RealVector& v2, const RealVector& v3);
			Triangle(const std::array<RealVector, 3>& vs);

			void draw() const { draw(1, Palette::White); }
			void draw(const Color& color) const { draw(1, color); }

		protected:

			void draw(const double size) const { draw(size, Palette::White); }
			void draw(const double size, const Color& color) const;

			std::array<RealVector, 3> vectors;

		};

		/// <summary>四角形を描画するクラス</summary>
		class Quad {
		public:

			Quad();
			Quad(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2, const int x3, const int y3, const int z3, const int x4, const int y4, const int z4);
			Quad(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3, const double x4, const double y4, const double z4);
			Quad(const IntVector& v1, const IntVector& v2, const IntVector& v3, const IntVector& v4);
			Quad(const std::array<IntVector, 4>& vs);
			Quad(const RealVector& v1, const RealVector& v2, const RealVector& v3, const RealVector& v4);
			Quad(const std::array<RealVector, 4>& vs);

			void draw() const { draw(1, Palette::White); }
			void draw(const Color& color) const { draw(1, color); }

		protected:

			void draw(const double size) const { draw(size, Palette::White); }
			void draw(const double size, const Color& color) const;

			std::array<RealVector, 4> vectors;

		};

		/// <summary>長方形を描画するクラス</summary>
		class Rect : public Quad {
		public:

			Rect();
			Rect(const int x, const int y, const int z, const int sx, const int sy, const int sz);
			Rect(const double x, const double y, const double z, const double sx, const double sy, const double sz);
			/// <summary>長方形を設定する</summary>
			/// <param name="v1">座標</param>
			/// <param name="v2">大きさ</param>
			Rect(const IntVector& v1, const IntVector& v2);
			/// <summary>長方形を設定する</summary>
			/// <param name="v1">座標</param>
			/// <param name="v2">大きさ</param>
			Rect(const RealVector& v1, const RealVector& v2);

		};

	}

}
