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
	/// 2次元描画
	/// </summary>
	namespace Draw2D {

		/// <summary>
		/// 点を描画するクラス
		/// </summary>
		class Pixel {
		public:

			/// <summary>
			/// コンストラクタ
			/// </summary>
			Pixel();
			/// <summary>コンストラクタ</summary>
			/// <param name="x">x座標</param>
			/// <param name="y">y座標</param>
			Pixel(const int x, const int y);
			/// <summary>コンストラクタ</summary>
			/// <param name="x">x座標</param>
			/// <param name="y">y座標</param>
			Pixel(const double x, const double y);
			/// <summary>コンストラクタ</summary>
			/// <param name="p">座標</param>
			Pixel(const Point& p);
			/// <summary>コンストラクタ</summary>
			/// <param name="p">座標</param>
			Pixel(const Vec2& p);

			/// <summary>
			/// 描画関数
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="color">色</param>
			void draw(const Color& color) const { draw(1, color); }
			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			/// <param name="color">色</param>
			void draw(const double size, const Color& color) const;

		protected:

			/// <summary>
			/// 描画座標
			/// </summary>
			Vec2 point;

		};

		/// <summary>
		/// 線を描画するクラス
		/// </summary>
		class Line {
		public:

			/// <summary>
			/// コンストラクタ
			/// </summary>
			Line();
			/// <summary>コンストラクタ</summary>
			/// <param name="x1">始点のx座標</param>
			/// <param name="y1">始点のy座標</param>
			/// <param name="x2">終点のx座標</param>
			/// <param name="y2">終点のy座標</param>
			Line(const int x1, const int y1, const int x2, const int y2);
			/// <summary>コンストラクタ</summary>
			/// <param name="x1">始点のx座標</param>
			/// <param name="y1">始点のy座標</param>
			/// <param name="x2">終点のx座標</param>
			/// <param name="y2">終点のy座標</param>
			Line(const double x1, const double y1, const double x2, const double y2);
			/// <summary>コンストラクタ</summary>
			/// <param name="p1">始点の座標</param>
			/// <param name="p2">終点の座標</param>
			Line(const Point& p1, const Point& p2);
			/// <summary>コンストラクタ</summary>
			/// <param name="ps">座標配列</param>
			Line(const std::array<Point, 2>& ps);
			/// <summary>コンストラクタ</summary>
			/// <param name="p1">始点の座標</param>
			/// <param name="p2">終点の座標</param>
			Line(const Vec2& p1, const Vec2& p2);
			/// <summary>コンストラクタ</summary>
			/// <param name="ps">座標配列</param>
			Line(const std::array<Vec2, 2>& ps);

			/// <summary>
			/// 描画関数
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="color">色</param>
			void draw(const Color& color) const { draw(1, color); }
			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			/// <param name="color">色</param>
			void draw(const double size, const Color& color) const;

		protected:

			/// <summary>
			/// 描画座標
			/// </summary>
			std::array<Vec2, 2> points;

		};

		/// <summary>
		/// 三角形を描画するクラス
		/// </summary>
		class Triangle {
		public:

			/// <summary>
			///	コンストラクタ
			///	</summary>
			Triangle();
			/// <summary>コンストラクタ</summary>
			/// <param name="x1">1点目のx座標</param>
			/// <param name="y1">1点目のy座標</param>
			/// <param name="x2">2点目のx座標</param>
			/// <param name="y2">2点目のy座標</param>
			/// <param name="x3">3点目のx座標</param>
			/// <param name="y3">3点目のy座標</param>
			Triangle(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3);
			/// <summary>コンストラクタ</summary>
			/// <param name="x1">1点目のx座標</param>
			/// <param name="y1">1点目のy座標</param>
			/// <param name="x2">2点目のx座標</param>
			/// <param name="y2">2点目のy座標</param>
			/// <param name="x3">3点目のx座標</param>
			/// <param name="y3">3点目のy座標</param>
			Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3);
			/// <summary>コンストラクタ</summary>
			/// <param name="p1">1点目の座標</param>
			/// <param name="p2">2点目の座標</param>
			/// <param name="p3">3点目の座標</param>
			Triangle(const Point& p1, const Point& p2, const Point& p3);
			/// <summary>コンストラクタ</summary>
			/// <param name="ps">座標の配列</param>
			Triangle(const std::array<Point, 3>& ps);
			/// <summary>コンストラクタ</summary>
			/// <param name="p1">1点目の座標</param>
			/// <param name="p2">2点目の座標</param>
			/// <param name="p3">3点目の座標</param>
			Triangle(const Vec2& p1, const Vec2& p2, const Vec2& p3);
			/// <summary>コンストラクタ</summary>
			/// <param name="ps">座標の配列</param>
			Triangle(const std::array<Vec2, 3>& ps);

			/// <summary>
			/// 描画関数
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="color">色</param>
			void draw(const Color& color) const { draw(1, color); }

		protected:

			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			/// <param name="color">色</param>
			void draw(const double size, const Color& color) const;

			/// <summary>
			/// 描画座標
			/// </summary>
			std::array<Vec2, 3> points;

		};

		/// <summary>
		///	四角形を描画するクラス
		///	</summary>
		class Quad {
		public:

			/// <summary>
			/// コンストラクタ
			/// </summary>
			Quad();
			/// <summary>コンストラクタ</summary>
			/// <param name="x1">1点目のx座標</param>
			/// <param name="y1">1点目のy座標</param>
			/// <param name="x2">2点目のx座標</param>
			/// <param name="y2">2点目のy座標</param>
			/// <param name="x3">3点目のx座標</param>
			/// <param name="y3">3点目のy座標</param>
			/// <param name="x4">4点目のx座標</param>
			/// <param name="y4">4点目のy座標</param>
			Quad(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3, const int x4, const int y4);
			/// <summary>コンストラクタ</summary>
			/// <param name="x1">1点目のx座標</param>
			/// <param name="y1">1点目のy座標</param>
			/// <param name="x2">2点目のx座標</param>
			/// <param name="y2">2点目のy座標</param>
			/// <param name="x3">3点目のx座標</param>
			/// <param name="y3">3点目のy座標</param>
			/// <param name="x4">4点目のx座標</param>
			/// <param name="y4">4点目のy座標</param>
			Quad(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3, const double x4, const double y4);
			/// <summary>コンストラクタ</summary>
			/// <param name="p1">1点目の座標</param>
			/// <param name="p2">2点目の座標</param>
			/// <param name="p3">3点目の座標</param>
			/// <param name="p4">4点目の座標</param>
			Quad(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
			/// <summary>コンストラクタ</summary>
			/// <param name="p1">座標の配列</param>
			Quad(const std::array<Point, 4>& ps);
			/// <summary>コンストラクタ</summary>
			/// <param name="p1">1点目の座標</param>
			/// <param name="p2">2点目の座標</param>
			/// <param name="p3">3点目の座標</param>
			/// <param name="p4">4点目の座標</param>
			Quad(const Vec2& p1, const Vec2& p2, const Vec2& p3, const Vec2& p4);
			/// <summary>コンストラクタ</summary>
			/// <param name="p1">座標の配列</param>
			Quad(const std::array<Vec2, 4>& ps);

			/// <summary>
			/// 描画関数
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="color">色</param>
			void draw(const Color& color) const { draw(1, color); }

		protected:

			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			/// <param name="color">色</param>
			void draw(const double size, const Color& color) const;

			/// <summary>
			/// 描画座標
			/// </summary>
			std::array<Vec2, 4> points;

		};

		/// <summary>
		///	長方形を描画するクラス
		///	</summary>
		class Rect : public Quad {
		public:

			/// <summary>
			///	コンストラクタ
			///	</summary>
			Rect();
			/// <summary>コンストラクタ</summary>
			/// <param name="x">x座標</param>
			/// <param name="y">y座標</param>
			/// <param name="width">幅</param>
			/// <param name="height">高さ</param>
			Rect(const int x, const int y, const int width, const int height);
			/// <summary>コンストラクタ</summary>
			/// <param name="x">x座標</param>
			/// <param name="y">y座標</param>
			/// <param name="width">幅</param>
			/// <param name="height">高さ</param>
			Rect(const double x, const double y, const double width, const double height);
			/// <summary>コンストラクタ</summary>
			/// <param name="pos">座標</param>
			/// <param name="size">大きさ</param>
			Rect(const Point& pos, const RealSize& size);
			/// <summary>コンストラクタ</summary>
			/// <param name="pos">座標</param>
			/// <param name="size">大きさ</param>
			Rect(const Vec2& pos, const RealSize& size);

		};
	}

	/// <summary>
	/// 3次元描写
	/// </summary>
	namespace Draw3D {

		/// <summary>
		///	点を描画するクラス
		///	</summary>
		class Pixel {
		public:

			/// <summary>
			/// コンストラクタ
			/// </summary>
			Pixel();
			/// <summary>コンストラクタ</summary>
			/// <param name="x">x座標</param>
			/// <param name="y">y座標</param>
			/// <param name="z">z座標</param>
			Pixel(const int x, const int y, const int z);
			/// <summary>コンストラクタ</summary>
			/// <param name="x">x座標</param>
			/// <param name="y">y座標</param>
			/// <param name="z">z座標</param>
			Pixel(const double x, const double y, const double z);
			/// <summary>コンストラクタ</summary>
			/// <param name="v">座標</param>
			Pixel(const Point3D& v);
			/// <summary>コンストラクタ</summary>
			/// <param name="v">座標</param>
			Pixel(const Vec3& v);

			/// <summary>
			/// 描画関数
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="color">色</param>
			void draw(const Color& color) const { draw(1, color); }
			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			/// <param name="color">色</param>
			void draw(const double size, const Color& color) const;

		protected:

			/// <summary>
			/// 描画座標
			/// </summary>
			Vec3 vec;

		};

		/// <summary>
		///	線を描画するクラス
		///	</summary>
		class Line {
		public:

			/// <summary>
			/// コンストラクタ
			/// </summary>
			Line();
			/// <summary>コンストラクタ</summary>
			/// <param name="x1">始点のx座標</param>
			/// <param name="y1">始点のy座標</param>
			/// <param name="z1">始点のz座標</param>
			/// <param name="x2">終点のx座標</param>
			/// <param name="y2">終点のy座標</param>
			/// <param name="z2">終点のz座標</param>
			Line(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2);
			/// <summary>コンストラクタ</summary>
			/// <param name="x1">始点のx座標</param>
			/// <param name="y1">始点のy座標</param>
			/// <param name="z1">始点のz座標</param>
			/// <param name="x2">終点のx座標</param>
			/// <param name="y2">終点のy座標</param>
			/// <param name="z2">終点のz座標</param>
			Line(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2);
			/// <summary>コンストラクタ</summary>
			/// <param name="v1">始点の座標</param>
			/// <param name="v2">始点の座標</param>
			Line(const Point3D& v1, const Point3D& v2);
			/// <summary>コンストラクタ</summary>
			/// <param name="vs">座標の配列</param>
			Line(const std::array<Point3D, 2>& vs);
			/// <summary>コンストラクタ</summary>
			/// <param name="v1">始点の座標</param>
			/// <param name="v2">始点の座標</param>
			Line(const Vec3& v1, const Vec3& v2);
			/// <summary>コンストラクタ</summary>
			/// <param name="vs">座標の配列</param>
			Line(const std::array<Vec3, 2>& vs);

			/// <summary>
			/// 描画関数
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="color">色</param>
			void draw(const Color& color) const { draw(1, color); }
			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			/// <param name="color">色</param>
			void draw(const double size, const Color& color) const;

		protected:

			/// <summary>
			/// 描画座標
			/// </summary>
			std::array<Vec3, 2> vectors;

		};

		/// <summary>
		///	三角形を描画するクラス
		///	</summary>
		class Triangle {
		public:

			/// <summary>
			/// コンストラクタ
			/// </summary>
			Triangle();
			/// <summary>コンストラクタ</summary>
			/// <param name="x1">1番目のx座標</param>
			/// <param name="y1">1番目のy座標</param>
			/// <param name="z1">1番目のz座標</param>
			/// <param name="x2">2番目のx座標</param>
			/// <param name="y2">2番目のy座標</param>
			/// <param name="z2">2番目のz座標</param>
			/// <param name="x3">3番目のx座標</param>
			/// <param name="y3">3番目のy座標</param>
			/// <param name="z3">3番目のz座標</param>
			Triangle(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2, const int x3, const int y3, const int z3);
			/// <summary>コンストラクタ</summary>
			/// <param name="x1">1番目のx座標</param>
			/// <param name="y1">1番目のy座標</param>
			/// <param name="z1">1番目のz座標</param>
			/// <param name="x2">2番目のx座標</param>
			/// <param name="y2">2番目のy座標</param>
			/// <param name="z2">2番目のz座標</param>
			/// <param name="x3">3番目のx座標</param>
			/// <param name="y3">3番目のy座標</param>
			/// <param name="z3">3番目のz座標</param>
			Triangle(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3);
			/// <summary>コンストラクタ</summary>
			/// <param name="v1">1番目の座標</param>
			/// <param name="v2">2番目の座標</param>
			/// <param name="v3">3番目の座標</param>
			Triangle(const Point3D& v1, const Point3D& v2, const Point3D& v3);
			/// <summary>コンストラクタ</summary>
			/// <param name="vs">座標の配列</param>
			Triangle(const std::array<Point3D, 3>& vs);
			/// <summary>コンストラクタ</summary>
			/// <param name="v1">1番目の座標</param>
			/// <param name="v2">2番目の座標</param>
			/// <param name="v3">3番目の座標</param>
			Triangle(const Vec3& v1, const Vec3& v2, const Vec3& v3);
			/// <summary>コンストラクタ</summary>
			/// <param name="vs">座標の配列</param>
			Triangle(const std::array<Vec3, 3>& vs);

			/// <summary>
			/// 描画関数
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="color">色</param>
			void draw(const Color& color) const { draw(1, color); }

		protected:

			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			/// <param name="color">色</param>
			void draw(const double size, const Color& color) const;

			/// <summary>
			/// 描画座標
			/// </summary>
			std::array<Vec3, 3> vectors;

		};

		/// <summary>
		///	四角形を描画するクラス
		///	</summary>
		class Quad {
		public:

			/// <summary>
			/// コンストラクタ
			/// </summary>
			Quad();
			/// <summary>コンストラクタ</summary>
			/// <param name="x1">1番目のx座標</param>
			/// <param name="y1">1番目のy座標</param>
			/// <param name="z1">1番目のz座標</param>
			/// <param name="x2">2番目のx座標</param>
			/// <param name="y2">2番目のy座標</param>
			/// <param name="z2">2番目のz座標</param>
			/// <param name="x3">3番目のx座標</param>
			/// <param name="y3">3番目のy座標</param>
			/// <param name="z3">3番目のz座標</param>
			/// <param name="x4">4番目のx座標</param>
			/// <param name="y4">4番目のy座標</param>
			/// <param name="z4">4番目のz座標</param>
			Quad(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2, const int x3, const int y3, const int z3, const int x4, const int y4, const int z4);
			/// <summary>コンストラクタ</summary>
			/// <param name="x1">1番目のx座標</param>
			/// <param name="y1">1番目のy座標</param>
			/// <param name="z1">1番目のz座標</param>
			/// <param name="x2">2番目のx座標</param>
			/// <param name="y2">2番目のy座標</param>
			/// <param name="z2">2番目のz座標</param>
			/// <param name="x3">3番目のx座標</param>
			/// <param name="y3">3番目のy座標</param>
			/// <param name="z3">3番目のz座標</param>
			/// <param name="x4">4番目のx座標</param>
			/// <param name="y4">4番目のy座標</param>
			/// <param name="z4">4番目のz座標</param>
			Quad(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3, const double x4, const double y4, const double z4);
			/// <summary>コンストラクタ</summary>
			/// <param name="v1">1番目の座標</param>
			/// <param name="v2">2番目の座標</param>
			/// <param name="v3">3目の座標</param>
			/// <param name="v4">4番目の座標</param>
			Quad(const Point3D& v1, const Point3D& v2, const Point3D& v3, const Point3D& v4);
			/// <summary>コンストラクタ</summary>
			/// <param name="vs">座標の配列</param>
			Quad(const std::array<Point3D, 4>& vs);
			/// <summary>コンストラクタ</summary>
			/// <param name="v1">1番目の座標</param>
			/// <param name="v2">2番目の座標</param>
			/// <param name="v3">3目の座標</param>
			/// <param name="v4">4番目の座標</param>
			Quad(const Vec3& v1, const Vec3& v2, const Vec3& v3, const Vec3& v4);
			/// <summary>コンストラクタ</summary>
			/// <param name="vs">座標の配列</param>
			Quad(const std::array<Vec3, 4>& vs);

			/// <summary>
			/// 描画関数
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="color">色</param>
			void draw(const Color& color) const { draw(1, color); }

		protected:

			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			/// <param name="color">色</param>
			void draw(const double size, const Color& color) const;

			/// <summary>
			/// 描画座標
			/// </summary>
			std::array<Vec3, 4> vectors;

		};

		/// <summary>
		///	長方形を描画するクラス
		///	</summary>
		class Rect : public Quad {
		public:

			/// <summary>
			/// コンストラクタ
			/// </summary>
			Rect();
			/// <summary>コンストラクタ</summary>
			/// <param name="x">x座標</param>
			/// <param name="y">y座標</param>
			/// <param name="z">z座標</param>
			/// <param name="sx">幅</param>
			/// <param name="sy">高さ</param>
			/// <param name="sz">奥行</param>
			Rect(const int x, const int y, const int z, const int sx, const int sy, const int sz);
			/// <summary>コンストラクタ</summary>
			/// <param name="x">x座標</param>
			/// <param name="y">y座標</param>
			/// <param name="z">z座標</param>
			/// <param name="sx">幅</param>
			/// <param name="sy">高さ</param>
			/// <param name="sz">奥行</param>
			Rect(const double x, const double y, const double z, const double sx, const double sy, const double sz);
			/// <summary>コンストラクタ</summary>
			/// <param name="v1">座標</param>
			/// <param name="v2">大きさ</param>
			Rect(const Point3D& v1, const Point3D& v2);
			/// <summary>コンストラクタ</summary>
			/// <param name="v1">座標</param>
			/// <param name="v2">大きさ</param>
			Rect(const Vec3& v1, const Vec3& v2);

		};

		class Box {
		public:

			/// <summary>
			/// コンストラクタ
			/// </summary>
			Box();
			/// <summary>コンストラクタ</summary>
			/// <param name="x">x座標</param>
			/// <param name="y">y座標</param>
			/// <param name="z">z座標</param>
			/// <param name="sx">横幅</param>
			/// <param name="sy">縦幅</param>
			/// <param name="sz">奥行</param>
			Box(const int x, const int y, const int z, const int sx, const int sy, const int sz);
			/// <summary>コンストラクタ</summary>
			/// <param name="x">x座標</param>
			/// <param name="y">y座標</param>
			/// <param name="z">z座標</param>
			/// <param name="sx">横幅</param>
			/// <param name="sy">縦幅</param>
			/// <param name="sz">奥行</param>
			Box(const double x, const double y, const double z, const double sx, const double sy, const double sz);
			/// <summary>コンストラクタ</summary>
			/// <param name="v">座標</param>
			/// <param name="s">大きさ</param>
			Box(const Point3D& v, const Point3D& s);
			/// <summary>コンストラクタ</summary>
			/// <param name="v">座標</param>
			/// <param name="s">大きさ</param>
			Box(const Vec3& v, const Vec3& s);

			/// <summary>
			/// 描画関数
			/// </summary>
			void draw() const { draw(1, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="color">色</param>
			void draw(const Color& color) const { draw(1, color); }

		protected:

			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			void draw(const double size) const { draw(size, Palette::White); }
			/// <summary>描画関数</summary>
			/// <param name="size">大きさ</param>
			/// <param name="color">色</param>
			void draw(const double size, const Color& color) const;

			/// <summary>
			/// 描画座標
			/// </summary>
			Vec3 pos;
			Vec3 size;

		};

	}

}
