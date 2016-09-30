#include "Draw.hpp"

namespace opc {

	Pixel::Pixel() : Pixel(RealPoint(0, 0)) {

	}
	Pixel::Pixel(const int x, const int y)
		: Pixel(RealPoint(x, y)) {

	}
	Pixel::Pixel(const double x, const double y)
		: Pixel(RealPoint(x, y)) {

	}
	Pixel::Pixel(const IntPoint& p) : Pixel(p.x, p.y) {

	}
	Pixel::Pixel(const RealPoint& p) {
		point = p;
	}

	void Pixel::draw(const double size, const Color& color) const {
		glColor4ub(color.r, color.g, color.b, color.a);
		glPointSize((GLfloat)size);
		glBegin(GL_POINTS);
		glVertex2d(point.x, point.y);
		glEnd();
	}

	Line::Line() : Line(RealPoint(0, 0), RealPoint(0, 0)) {

	}
	Line::Line(const int x1, const int y1, const int x2, const int y2)
		: Line({ RealPoint(x1,y1),RealPoint(x2,y2) }) {

	}
	Line::Line(const double x1, const double y1, const double x2, const double y2)
		: Line({ RealPoint(x1,y1),RealPoint(x2,y2) }) {

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

	void Line::draw(const double size, const Color& color) const {
		glColor4ub(color.r, color.g, color.b, color.a);
		glLineWidth((float)size);
		glBegin(GL_LINES);
		glVertex2d(points[0].x, points[0].y);
		glVertex2d(points[1].x, points[1].y);
		glEnd();
	}

	Triangle::Triangle() : Triangle(RealPoint(0, 0), RealPoint(0, 0), RealPoint(0, 0)) {

	}
	Triangle::Triangle(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3)
		: Triangle(RealPoint(x1, y1), RealPoint(x2, y2), RealPoint(x3, y3)) {

	}
	Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3)
		: Triangle(RealPoint(x1, y1), RealPoint(x2, y2), RealPoint(x3, y3)) {

	}
	Triangle::Triangle(const IntPoint& p1, const IntPoint& p2, const IntPoint& p3) {
		points[0] = p1; points[1] = p2; points[2] = p3;
	}
	Triangle::Triangle(const std::array<IntPoint, 3>& ps) {
		points[0] = ps[0]; points[1] = ps[1]; points[2] = ps[2];
	}
	Triangle::Triangle(const RealPoint& p1, const RealPoint& p2, const RealPoint& p3) {
		points[0] = p1; points[1] = p2; points[2] = p3;
	}
	Triangle::Triangle(const std::array<RealPoint, 3>& ps) {
		points = ps;
	}

	void Triangle::draw(const double size, const Color& color) const {
		glColor4ub(color.r, color.g, color.b, color.a);
		glBegin(GL_TRIANGLES);
		glVertex2d(points[0].x, points[0].y);
		glVertex2d(points[1].x, points[1].y);
		glVertex2d(points[2].x, points[2].y);
		glEnd();
	}

	Quad::Quad() : Quad(RealPoint(0, 0), RealPoint(0, 0), RealPoint(0, 0), RealPoint(0, 0)) {

	}
	Quad::Quad(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3, const int x4, const int y4)
		: Quad(RealPoint(x1, y1), RealPoint(x2, y2), RealPoint(x3, y3), RealPoint(x4, y4)) {

	}
	Quad::Quad(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3, const double x4, const double y4)
		: Quad(RealPoint(x1, y1), RealPoint(x2, y2), RealPoint(x3, y3), RealPoint(x4, y4)) {

	}
	Quad::Quad(const IntPoint& p1, const IntPoint& p2, const IntPoint& p3, const IntPoint& p4) {
		points[0] = p1; points[1] = p2; points[2] = p3; points[3] = p4;
	}
	Quad::Quad(const std::array<IntPoint, 4>& ps) {
		points[0] = ps[0]; points[1] = ps[1]; points[2] = ps[2]; points[3] = ps[3];
	}
	Quad::Quad(const RealPoint& p1, const RealPoint& p2, const RealPoint& p3, const RealPoint& p4) {
		points[0] = p1; points[1] = p2; points[2] = p3; points[3] = p4;
	}
	Quad::Quad(const std::array<RealPoint, 4>& ps) {
		points = ps;
	}

	void Quad::draw(const double size, const Color& color) const {
		glColor4ub(color.r, color.g, color.b, color.a);
		glBegin(GL_QUADS);
		glVertex2d(points[0].x, points[0].y);
		glVertex2d(points[1].x, points[1].y);
		glVertex2d(points[2].x, points[2].y);
		glVertex2d(points[3].x, points[3].y);
		glEnd();
	}

	Rect::Rect() : Rect(RealPoint(0, 0), Size(0, 0)) {

	}
	Rect::Rect(const int x, const int y, const int width, const int height)
		: Rect(RealPoint(x, y), Size(width, height)) {

	}
	Rect::Rect(const double x, const double y, const double width, const double height)
		: Rect(RealPoint(x, y), Size(width, height)) {

	}
	Rect::Rect(const IntPoint& pos, const Size& size) {
		points[0] = pos;
		points[1] = pos + RealPoint(size.width, 0);
		points[2] = pos + RealPoint(size.width, size.height);
		points[3] = pos + RealPoint(0, size.height);
	}
	Rect::Rect(const RealPoint& pos, const Size& size) {
		points[0] = pos;
		points[1] = pos + RealPoint(size.width, 0);
		points[2] = pos + RealPoint(size.width, size.height);
		points[3] = pos + RealPoint(0, size.height);
	}

}
