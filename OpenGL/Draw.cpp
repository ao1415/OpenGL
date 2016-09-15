#include "Draw.hpp"

namespace opc {
	/*
	std::vector<std::array<RealPoint, 1>> DrawCore::pixel;
	std::vector<std::array<RealPoint, 2>> DrawCore::line;
	std::vector<std::array<RealPoint, 3>> DrawCore::triangle;
	std::vector<std::array<RealPoint, 4>> DrawCore::rectangle;
	std::vector<std::vector<RealPoint>> DrawCore::polygon;
	*/

	Pixel::Pixel() : Pixel(RealPoint(0, 0)) {

	}
	Pixel::Pixel(const int x, const int y) : Pixel(RealPoint(x, y)) {

	}
	Pixel::Pixel(const double x, const double y) : Pixel(RealPoint(x, y)) {

	}
	Pixel::Pixel(const IntPoint& p) : Pixel(p.x, p.y) {

	}
	Pixel::Pixel(const RealPoint& p) {
		point = p;
	}

	void Pixel::draw() const {
		draw(1, Palette::White);
	}
	void Pixel::draw(const double size) const {
		draw(size, Palette::White);
	}
	void Pixel::draw(const Color& color) const {
		draw(1, Palette::White);
	}
	void Pixel::draw(const double size, const Color& color) const {
		glColor4f(color.r, color.g, color.b, color.a);
		glPointSize(size);
		glBegin(GL_POINTS);
		glVertex2d(point.x, point.y);
		glEnd();
	}

	Line::Line() : Line({ RealPoint(0,0),RealPoint(0,0) }) {

	}
	Line::Line(const int x1, const int y1, const int x2, const int y2) : Line({ RealPoint(x1,y1),RealPoint(x2,y2) }) {

	}
	Line::Line(const double x1, const double y1, const double x2, const double y2) : Line({ RealPoint(x1,y1),RealPoint(x2,y2) }) {

	}
	Line::Line(const IntPoint& p1, const IntPoint& p2) {
		points[0] = p1; points[1] = p2;
	}
	Line::Line(const std::array<IntPoint, 2>& ps) {
		points[0] = ps[0]; points[1] = ps[1];
	}
	Line::Line(const RealPoint& p1, const RealPoint& p2) {
		points[0] = p1; points[1] = p2;
	}
	Line::Line(const std::array<RealPoint, 2>& ps) {
		points = ps;
	}

	void Line::draw() const {
		draw(1, Palette::White);
	}
	void Line::draw(const double size) const {
		draw(size, Palette::White);
	}
	void Line::draw(const Color& color) const {
		draw(1, Palette::White);
	}
	void Line::draw(const double size, const Color& color) const {
		glColor4f(color.r, color.g, color.b, color.a);
		glLineWidth((float)size);
		glBegin(GL_LINES);
		glVertex2d(points[0].x, points[0].y);
		glVertex2d(points[1].x, points[1].y);
		glEnd();
	}

}
