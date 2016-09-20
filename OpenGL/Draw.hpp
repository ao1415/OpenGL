#pragma once

#include <GL/glut.h>
#include <array>
#include <vector>
#include "Point.hpp"
#include "Size.hpp"
#include "Palette.hpp"

namespace opc {

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
	
	class Rect : public Quad {
	public:

		Rect();
		Rect(const int x, const int y, const int width, const int height);
		Rect(const double x, const double y, const double width, const double height);
		Rect(const IntPoint& pos, const Size& size);
		Rect(const RealPoint& pos, const Size& size);

	};

}
