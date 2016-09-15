#pragma once

#include <GL/glut.h>
#include <array>
#include <vector>
#include "Point.hpp"
#include "Palette.hpp"

namespace opc {
	/*
	class Pixel;
	class Line;
	class Triangle;
	class Rectangle;
	class Polygon;

	class DrawCore {
	public:

		void draw();

	private:

		friend Pixel;
		friend Line;
		friend Triangle;
		friend Rectangle;
		friend Polygon;

		static std::vector<std::array<RealPoint, 1>> pixel;
		static std::vector<std::array<RealPoint, 2>> line;
		static std::vector<std::array<RealPoint, 3>> triangle;
		static std::vector<std::array<RealPoint, 4>> rectangle;
		static std::vector<std::vector<RealPoint>> polygon;

	};
	*/

	/// <summary>点を描画するクラス</summary>
	class Pixel {
	public:

		Pixel();
		Pixel(const int x, const int y);
		Pixel(const double x, const double y);
		Pixel(const IntPoint& p);
		Pixel(const RealPoint& p);

		void draw() const;
		void draw(const double size) const;
		void draw(const Color& color) const;
		void draw(const double size, const Color& color) const;

	private:

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

		void draw() const;
		void draw(const double size) const;
		void draw(const Color& color) const;
		void draw(const double size, const Color& color) const;

	private:

		std::array<RealPoint, 2> points;

	};

	class Triangle {
	public:

		Triangle();
		Triangle(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3);
		Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3);
		Triangle(const IntPoint& p1, const IntPoint& p2, const IntPoint& p3);
		Triangle(const std::array<IntPoint, 3>& ps);
		Triangle(const RealPoint& p1, const RealPoint& p2, const RealPoint& p3);
		Triangle(const std::array<RealPoint, 3>& ps);

		void draw() const;
		void draw(const double size) const;
		void draw(const Color& color) const;
		void draw(const double size, const Color& color) const;

	private:

		std::array<RealPoint, 3> points;

	};

}
