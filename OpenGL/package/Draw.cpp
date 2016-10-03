#include "Draw.hpp"

namespace opc {

	namespace Draw2D {

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
			Paint::Color(color);
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
			Paint::Color(color);
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
			Paint::Color(color);
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
			Paint::Color(color);
			glBegin(GL_QUADS);
			glVertex2d(points[0].x, points[0].y);
			glVertex2d(points[1].x, points[1].y);
			glVertex2d(points[2].x, points[2].y);
			glVertex2d(points[3].x, points[3].y);
			glEnd();
		}

		Rect::Rect() : Rect(RealPoint(0, 0), RealSize(0, 0)) {

		}
		Rect::Rect(const int x, const int y, const int width, const int height)
			: Rect(RealPoint(x, y), RealSize(width, height)) {

		}
		Rect::Rect(const double x, const double y, const double width, const double height)
			: Rect(RealPoint(x, y), RealSize(width, height)) {

		}
		Rect::Rect(const IntPoint& pos, const RealSize& size) {
			points[0] = pos;
			points[1] = pos + RealPoint(size.width, 0);
			points[2] = pos + RealPoint(size.width, size.height);
			points[3] = pos + RealPoint(0, size.height);
		}
		Rect::Rect(const RealPoint& pos, const RealSize& size) {
			points[0] = pos;
			points[1] = pos + RealPoint(size.width, 0);
			points[2] = pos + RealPoint(size.width, size.height);
			points[3] = pos + RealPoint(0, size.height);
		}
	}

	namespace Draw3D {

		Pixel::Pixel() : Pixel(RealVector(0, 0, 0)) {

		}
		Pixel::Pixel(const int x, const int y, const int z)
			: Pixel(RealVector(x, y, z)) {

		}
		Pixel::Pixel(const double x, const double y, const double z)
			: Pixel(RealVector(x, y, z)) {

		}
		Pixel::Pixel(const IntVector& v) : Pixel(v.x, v.y, v.z) {

		}
		Pixel::Pixel(const RealVector& v) {
			vec = v;
		}

		void Pixel::draw(const double size, const Color& color) const {
			Paint::Color(color);
			glPointSize((GLfloat)size);
			glBegin(GL_POINTS);
			glVertex3d(vec.x, vec.y, vec.z);
			glEnd();
		}

		Line::Line() : Line(RealVector(0, 0, 0), RealVector(0, 0, 0)) {

		}
		Line::Line(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2)
			: Line(RealVector(x1, y1, z1), RealVector(x2, y2, z2)) {

		}
		Line::Line(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2)
			: Line(RealVector(x1, y1, z1), RealVector(x2, y2, z2)) {

		}
		Line::Line(const IntVector& v1, const IntVector& v2) {
			vectors[0] = v1; vectors[1] = v2;
		}
		Line::Line(const std::array<IntVector, 2>& vs) {
			vectors[0] = vs[0]; vectors[1] = vs[1];
		}
		Line::Line(const RealVector& v1, const RealVector& v2) {
			vectors[0] = v1; vectors[1] = v2;
		}
		Line::Line(const std::array<RealVector, 2>& vs) {
			vectors = vs;
		}

		void Line::draw(const double size, const Color& color) const {
			Paint::Color(color);
			glLineWidth((float)size);
			glBegin(GL_LINES);
			glVertex3d(vectors[0].x, vectors[0].y, vectors[0].z);
			glVertex3d(vectors[1].x, vectors[1].y, vectors[1].z);
			glEnd();
		}

		Triangle::Triangle() : Triangle(RealVector(0, 0, 0), RealVector(0, 0, 0), RealVector(0, 0, 0)) {

		}
		Triangle::Triangle(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2, const int x3, const int y3, const int z3)
			: Triangle(RealVector(x1, y1, z1), RealVector(x2, y2, z2), RealVector(x3, y3, z3)) {

		}
		Triangle::Triangle(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3)
			: Triangle(RealVector(x1, y1, z1), RealVector(x2, y2, z2), RealVector(x3, y3, z3)) {

		}
		Triangle::Triangle(const IntVector& v1, const IntVector& v2, const IntVector& v3) {
			vectors[0] = v1; vectors[1] = v2; vectors[2] = v3;
		}
		Triangle::Triangle(const std::array<IntVector, 3>& vs) {
			vectors[0] = vs[0]; vectors[1] = vs[1]; vectors[2] = vs[2];
		}
		Triangle::Triangle(const RealVector& v1, const RealVector& v2, const RealVector& v3) {
			vectors[0] = v1; vectors[1] = v2; vectors[2] = v3;
		}
		Triangle::Triangle(const std::array<RealVector, 3>& vs) {
			vectors = vs;
		}

		void Triangle::draw(const double size, const Color& color) const {
			Paint::Color(color);
			glBegin(GL_TRIANGLES);
			glVertex3d(vectors[0].x, vectors[0].y, vectors[0].z);
			glVertex3d(vectors[1].x, vectors[1].y, vectors[1].z);
			glVertex3d(vectors[2].x, vectors[2].y, vectors[2].z);
			glEnd();
		}

		Quad::Quad() : Quad(RealVector(0, 0, 0), RealVector(0, 0, 0), RealVector(0, 0, 0), RealVector(0, 0, 0)) {

		}
		Quad::Quad(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2, const int x3, const int y3, const int z3, const int x4, const int y4, const int z4)
			: Quad(RealVector(x1, y1, z1), RealVector(x2, y2, z2), RealVector(x3, y3, z3), RealVector(x4, y4, z4)) {

		}
		Quad::Quad(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3, const double x4, const double y4, const double z4)
			: Quad(RealVector(x1, y1, z1), RealVector(x2, y2, z2), RealVector(x3, y3, z3), RealVector(x4, y4, z4)) {

		}
		Quad::Quad(const IntVector& v1, const IntVector& v2, const IntVector& v3, const IntVector& v4) {
			vectors[0] = v1; vectors[1] = v2; vectors[2] = v3; vectors[3] = v4;
		}
		Quad::Quad(const std::array<IntVector, 4>& vs) {
			vectors[0] = vs[0]; vectors[1] = vs[1]; vectors[2] = vs[2]; vectors[3] = vs[3];
		}
		Quad::Quad(const RealVector& v1, const RealVector& v2, const RealVector& v3, const RealVector& v4) {
			vectors[0] = v1; vectors[1] = v2; vectors[2] = v3; vectors[3] = v4;
		}
		Quad::Quad(const std::array<RealVector, 4>& vs) {
			vectors = vs;
		}

		void Quad::draw(const double size, const Color& color) const {
			Paint::Color(color);
			glBegin(GL_QUADS);
			glVertex3d(vectors[0].x, vectors[0].y, vectors[0].z);
			glVertex3d(vectors[1].x, vectors[1].y, vectors[1].z);
			glVertex3d(vectors[2].x, vectors[2].y, vectors[2].z);
			glVertex3d(vectors[3].x, vectors[3].y, vectors[3].z);
			glEnd();
		}

		Rect::Rect() : Rect(RealVector(0, 0, 0), RealVector(0, 0, 0)) {

		}
		Rect::Rect(const int x, const int y, const int z, const int sx, const int sy, const int sz)
			: Rect(RealVector(x, y, z), RealVector(sx, sy, sz)) {

		}
		Rect::Rect(const double x, const double y, const double z, const double sx, const double sy, const double sz)
			: Rect(RealVector(x, y, z), RealVector(sx, sy, sz)) {

		}
		Rect::Rect(const IntVector& pos, const IntVector& size) {
			vectors[0] = pos;
			vectors[1] = pos + RealVector(size.x, 0, size.z);
			vectors[2] = pos + RealVector(size.x, size.y, size.z);
			vectors[3] = pos + RealVector(0, size.y, 0);
		}
		Rect::Rect(const RealVector& pos, const RealVector& size) {
			vectors[0] = pos;
			vectors[1] = pos + RealVector(size.x, 0, size.z);
			vectors[2] = pos + RealVector(size.x, size.y, size.z);
			vectors[3] = pos + RealVector(0, size.y, 0);
		}

	}

}
