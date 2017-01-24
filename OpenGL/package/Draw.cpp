#include "Draw.hpp"

namespace opc {

	namespace Draw2D {

		Pixel::Pixel() : Pixel(Vec2(0, 0)) {

		}
		Pixel::Pixel(const int x, const int y)
			: Pixel(Vec2(x, y)) {

		}
		Pixel::Pixel(const double x, const double y)
			: Pixel(Vec2(x, y)) {

		}
		Pixel::Pixel(const Point& p) : Pixel(p.x, p.y) {

		}
		Pixel::Pixel(const Vec2& p) {
			point = p;
		}

		void Pixel::draw(const double size, const Color& color) const {
			Paint::Color(color);
			glPointSize((GLfloat)size);
			glBegin(GL_POINTS);
			glVertex2d(point.x, point.y);
			glEnd();
		}

		Line::Line() : Line(Vec2(0, 0), Vec2(0, 0)) {

		}
		Line::Line(const int x1, const int y1, const int x2, const int y2)
			: Line({ Vec2(x1,y1),Vec2(x2,y2) }) {

		}
		Line::Line(const double x1, const double y1, const double x2, const double y2)
			: Line({ Vec2(x1,y1),Vec2(x2,y2) }) {

		}
		Line::Line(const Point& p1, const Point& p2) {
			points[0] = p1; points[1] = p2;
		}
		Line::Line(const std::array<Point, 2>& ps) {
			points[0] = ps[0]; points[1] = ps[1];
		}
		Line::Line(const Vec2& p1, const Vec2& p2) {
			points[0] = p1; points[1] = p2;
		}
		Line::Line(const std::array<Vec2, 2>& ps) {
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

		Triangle::Triangle() : Triangle(Vec2(0, 0), Vec2(0, 0), Vec2(0, 0)) {

		}
		Triangle::Triangle(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3)
			: Triangle(Vec2(x1, y1), Vec2(x2, y2), Vec2(x3, y3)) {

		}
		Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3)
			: Triangle(Vec2(x1, y1), Vec2(x2, y2), Vec2(x3, y3)) {

		}
		Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) {
			points[0] = p1; points[1] = p2; points[2] = p3;
		}
		Triangle::Triangle(const std::array<Point, 3>& ps) {
			points[0] = ps[0]; points[1] = ps[1]; points[2] = ps[2];
		}
		Triangle::Triangle(const Vec2& p1, const Vec2& p2, const Vec2& p3) {
			points[0] = p1; points[1] = p2; points[2] = p3;
		}
		Triangle::Triangle(const std::array<Vec2, 3>& ps) {
			points = ps;
		}

		void Triangle::draw(const double, const Color& color) const {
			Paint::Color(color);
			glBegin(GL_TRIANGLES);
			glVertex2d(points[0].x, points[0].y);
			glVertex2d(points[1].x, points[1].y);
			glVertex2d(points[2].x, points[2].y);
			glEnd();
		}

		Quad::Quad() : Quad(Vec2(0, 0), Vec2(0, 0), Vec2(0, 0), Vec2(0, 0)) {

		}
		Quad::Quad(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3, const int x4, const int y4)
			: Quad(Vec2(x1, y1), Vec2(x2, y2), Vec2(x3, y3), Vec2(x4, y4)) {

		}
		Quad::Quad(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3, const double x4, const double y4)
			: Quad(Vec2(x1, y1), Vec2(x2, y2), Vec2(x3, y3), Vec2(x4, y4)) {

		}
		Quad::Quad(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
			points[0] = p1; points[1] = p2; points[2] = p3; points[3] = p4;
		}
		Quad::Quad(const std::array<Point, 4>& ps) {
			points[0] = ps[0]; points[1] = ps[1]; points[2] = ps[2]; points[3] = ps[3];
		}
		Quad::Quad(const Vec2& p1, const Vec2& p2, const Vec2& p3, const Vec2& p4) {
			points[0] = p1; points[1] = p2; points[2] = p3; points[3] = p4;
		}
		Quad::Quad(const std::array<Vec2, 4>& ps) {
			points = ps;
		}

		void Quad::draw(const double, const Color& color) const {
			Paint::Color(color);
			glBegin(GL_QUADS);
			glVertex2d(points[0].x, points[0].y);
			glVertex2d(points[1].x, points[1].y);
			glVertex2d(points[2].x, points[2].y);
			glVertex2d(points[3].x, points[3].y);
			glEnd();
		}

		Rect::Rect() : Rect(Vec2(0, 0), RealSize(0, 0)) {

		}
		Rect::Rect(const int x, const int y, const int width, const int height)
			: Rect(Vec2(x, y), RealSize(width, height)) {

		}
		Rect::Rect(const double x, const double y, const double width, const double height)
			: Rect(Vec2(x, y), RealSize(width, height)) {

		}
		Rect::Rect(const Point& pos, const RealSize& size) {
			points[0] = pos;
			points[1] = pos + Vec2(size.width, 0);
			points[2] = pos + Vec2(size.width, size.height);
			points[3] = pos + Vec2(0, size.height);
		}
		Rect::Rect(const Vec2& pos, const RealSize& size) {
			points[0] = pos;
			points[1] = pos + Vec2(size.width, 0);
			points[2] = pos + Vec2(size.width, size.height);
			points[3] = pos + Vec2(0, size.height);
		}
	}

	namespace Draw3D {

		Pixel::Pixel() : Pixel(Vec3(0, 0, 0)) {

		}
		Pixel::Pixel(const int x, const int y, const int z)
			: Pixel(Vec3(x, y, z)) {

		}
		Pixel::Pixel(const double x, const double y, const double z)
			: Pixel(Vec3(x, y, z)) {

		}
		Pixel::Pixel(const Point3D& v) : Pixel(v.x, v.y, v.z) {

		}
		Pixel::Pixel(const Vec3& v) {
			vec = v;
		}

		void Pixel::draw(const double size, const Color& color) const {
			Paint::Color(color);
			glPointSize((GLfloat)size);
			glBegin(GL_POINTS);
			glVertex3d(vec.x, vec.y, vec.z);
			glEnd();
		}

		Line::Line() : Line(Vec3(0, 0, 0), Vec3(0, 0, 0)) {

		}
		Line::Line(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2)
			: Line(Vec3(x1, y1, z1), Vec3(x2, y2, z2)) {

		}
		Line::Line(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2)
			: Line(Vec3(x1, y1, z1), Vec3(x2, y2, z2)) {

		}
		Line::Line(const Point3D& v1, const Point3D& v2) {
			vectors[0] = v1; vectors[1] = v2;
		}
		Line::Line(const std::array<Point3D, 2>& vs) {
			vectors[0] = vs[0]; vectors[1] = vs[1];
		}
		Line::Line(const Vec3& v1, const Vec3& v2) {
			vectors[0] = v1; vectors[1] = v2;
		}
		Line::Line(const std::array<Vec3, 2>& vs) {
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

		Triangle::Triangle() : Triangle(Vec3(0, 0, 0), Vec3(0, 0, 0), Vec3(0, 0, 0)) {

		}
		Triangle::Triangle(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2, const int x3, const int y3, const int z3)
			: Triangle(Vec3(x1, y1, z1), Vec3(x2, y2, z2), Vec3(x3, y3, z3)) {

		}
		Triangle::Triangle(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3)
			: Triangle(Vec3(x1, y1, z1), Vec3(x2, y2, z2), Vec3(x3, y3, z3)) {

		}
		Triangle::Triangle(const Point3D& v1, const Point3D& v2, const Point3D& v3) {
			vectors[0] = v1; vectors[1] = v2; vectors[2] = v3;
		}
		Triangle::Triangle(const std::array<Point3D, 3>& vs) {
			vectors[0] = vs[0]; vectors[1] = vs[1]; vectors[2] = vs[2];
		}
		Triangle::Triangle(const Vec3& v1, const Vec3& v2, const Vec3& v3) {
			vectors[0] = v1; vectors[1] = v2; vectors[2] = v3;
		}
		Triangle::Triangle(const std::array<Vec3, 3>& vs) {
			vectors = vs;
		}

		void Triangle::draw(const double, const Color& color) const {
			Paint::Color(color);
			glBegin(GL_TRIANGLES);
			glVertex3d(vectors[0].x, vectors[0].y, vectors[0].z);
			glVertex3d(vectors[1].x, vectors[1].y, vectors[1].z);
			glVertex3d(vectors[2].x, vectors[2].y, vectors[2].z);
			glEnd();
		}

		Quad::Quad() : Quad(Vec3(0, 0, 0), Vec3(0, 0, 0), Vec3(0, 0, 0), Vec3(0, 0, 0)) {

		}
		Quad::Quad(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2, const int x3, const int y3, const int z3, const int x4, const int y4, const int z4)
			: Quad(Vec3(x1, y1, z1), Vec3(x2, y2, z2), Vec3(x3, y3, z3), Vec3(x4, y4, z4)) {

		}
		Quad::Quad(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3, const double x4, const double y4, const double z4)
			: Quad(Vec3(x1, y1, z1), Vec3(x2, y2, z2), Vec3(x3, y3, z3), Vec3(x4, y4, z4)) {

		}
		Quad::Quad(const Point3D& v1, const Point3D& v2, const Point3D& v3, const Point3D& v4) {
			vectors[0] = v1; vectors[1] = v2; vectors[2] = v3; vectors[3] = v4;
		}
		Quad::Quad(const std::array<Point3D, 4>& vs) {
			vectors[0] = vs[0]; vectors[1] = vs[1]; vectors[2] = vs[2]; vectors[3] = vs[3];
		}
		Quad::Quad(const Vec3& v1, const Vec3& v2, const Vec3& v3, const Vec3& v4) {
			vectors[0] = v1; vectors[1] = v2; vectors[2] = v3; vectors[3] = v4;
		}
		Quad::Quad(const std::array<Vec3, 4>& vs) {
			vectors = vs;
		}

		void Quad::draw(const double, const Color& color) const {
			Paint::Color(color);
			glBegin(GL_QUADS);
			glVertex3d(vectors[0].x, vectors[0].y, vectors[0].z);
			glVertex3d(vectors[1].x, vectors[1].y, vectors[1].z);
			glVertex3d(vectors[2].x, vectors[2].y, vectors[2].z);
			glVertex3d(vectors[3].x, vectors[3].y, vectors[3].z);
			glEnd();
		}

		Rect::Rect() : Rect(Vec3(0, 0, 0), Vec3(0, 0, 0)) {

		}
		Rect::Rect(const int x, const int y, const int z, const int sx, const int sy, const int sz)
			: Rect(Vec3(x, y, z), Vec3(sx, sy, sz)) {

		}
		Rect::Rect(const double x, const double y, const double z, const double sx, const double sy, const double sz)
			: Rect(Vec3(x, y, z), Vec3(sx, sy, sz)) {

		}
		Rect::Rect(const Point3D& pos, const Point3D& size) {
			vectors[0] = pos;
			vectors[1] = pos + Vec3(size.x, 0, size.z);
			vectors[2] = pos + Vec3(size.x, size.y, size.z);
			vectors[3] = pos + Vec3(0, size.y, 0);
		}
		Rect::Rect(const Vec3& pos, const Vec3& size) {
			vectors[0] = pos;
			vectors[1] = pos + Vec3(size.x, 0, size.z);
			vectors[2] = pos + Vec3(size.x, size.y, size.z);
			vectors[3] = pos + Vec3(0, size.y, 0);
		}

		Box::Box() : Box(Vec3(0, 0, 0), Vec3(1, 1, 1)) {

		}
		Box::Box(const int x, const int y, const int z, const int sx, const int sy, const int sz)
			: Box(Vec3(x, y, z), Vec3(sx, sy, sz)) {

		}
		Box::Box(const double x, const double y, const double z, const double sx, const double sy, const double sz)
			: Box(Vec3(x, y, z), Vec3(sx, sy, sz)) {

		}
		Box::Box(const Point3D& v, const Point3D& s) {
			pos = v;
			size = s;
		}
		Box::Box(const Vec3& v, const Vec3& s) {
			pos = v;
			size = s;
		}

		void Box::draw(const double, const Color& color) const {
			Paint::Color(color);
			glBegin(GL_QUADS);
			glVertex3d(pos.x, pos.y, pos.z);
			glVertex3d(pos.x + size.x, pos.y, pos.z);
			glVertex3d(pos.x + size.x, pos.y + size.y, pos.z);
			glVertex3d(pos.x, pos.y + size.y, pos.z);

			glVertex3d(pos.x, pos.y, pos.z);
			glVertex3d(pos.x, pos.y, pos.z + size.z);
			glVertex3d(pos.x + size.x, pos.y, pos.z + size.z);
			glVertex3d(pos.x + size.x, pos.y, pos.z);

			glVertex3d(pos.x, pos.y, pos.z);
			glVertex3d(pos.x, pos.y + size.y, pos.z);
			glVertex3d(pos.x, pos.y + size.y, pos.z + size.z);
			glVertex3d(pos.x, pos.y, pos.z + size.z);

			glVertex3d(pos.x + size.x, pos.y + size.y, pos.z + size.z);
			glVertex3d(pos.x + size.x, pos.y, pos.z + size.z);
			glVertex3d(pos.x + size.x, pos.y, pos.z);
			glVertex3d(pos.x + size.x, pos.y + size.y, pos.z);

			glVertex3d(pos.x + size.x, pos.y + size.y, pos.z + size.z);
			glVertex3d(pos.x + size.x, pos.y + size.y, pos.z);
			glVertex3d(pos.x, pos.y + size.y, pos.z);
			glVertex3d(pos.x, pos.y + size.y, pos.z + size.z);

			glVertex3d(pos.x + size.x, pos.y + size.y, pos.z + size.z);
			glVertex3d(pos.x, pos.y + size.y, pos.z + size.z);
			glVertex3d(pos.x, pos.y, pos.z + size.z);
			glVertex3d(pos.x + size.x, pos.y, pos.z + size.z);
			glEnd();
		}

	}

}
