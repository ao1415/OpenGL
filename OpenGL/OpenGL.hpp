#pragma once

#include <GL/glut.h> 
#include <iostream>
#include <string>
#include <functional>

using namespace std;

typedef unsigned char byte;

struct Point {
	Point() {}
	Point(const int _x, const int _y) : x(_x), y(_y) {}

	int x = 0;
	int y = 0;

	const Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
	const Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }

	const Point operator*(const int v) const { return Point(x * v, y * v); }
	const Point operator/(const int v) const { return Point(x / v, y / v); }

	void operator+=(const Point& p) { (*this) = (*this) + p; }
	void operator-=(const Point& p) { (*this) = (*this) - p; }

	void operator*=(const int v) { (*this) = (*this) * v; }
	void operator/=(const int v) { (*this) = (*this) / v; }

};

struct DPoint {
	DPoint() {}
	DPoint(const double _x, const double _y) : x(_x), y(_y) {}

	double x = 0;
	double y = 0;

	const DPoint operator+(const DPoint& p) const { return DPoint(x + p.x, y + p.y); }
	const DPoint operator-(const DPoint& p) const { return DPoint(x - p.x, y - p.y); }

	const DPoint operator*(const int v) const { return DPoint(x * v, y * v); }
	const DPoint operator/(const int v) const { return DPoint(x / v, y / v); }

	void operator+=(const DPoint& p) { (*this) = (*this) + p; }
	void operator-=(const DPoint& p) { (*this) = (*this) - p; }

	void operator*=(const int v) { (*this) = (*this) * v; }
	void operator/=(const int v) { (*this) = (*this) / v; }

	void operator=(const Point& p) { x = p.x; y = p.y; }

};

struct Size {
	Size() {}
	Size(const int w, const int h) : width(w), height(h) {}

	int width = 0;
	int height = 0;
};

struct Color {

	Color() {}
	Color(const byte _r, const byte _g, const byte _b) : Color(_r, _g, _b, 255) {}
	Color(const byte _r, const byte _g, const byte _b, const byte _a) :r(_r), g(_g), b(_b), a(_a) {}
	Color(unsigned int code) : Color(code, 255) {}
	Color(unsigned int code, const byte alpha) {
		//0xrrggbb

		b = (0x000000ff & code) >> 0;
		g = (0x0000ff00 & code) >> 8;
		r = (0x00ff0000 & code) >> 16;
		a = alpha;
	}


	byte r = 0;
	byte g = 0;
	byte b = 0;
	byte a = 0;
};

template <class CharType>
inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Point& v) {
	return os << CharType('(') << v.x << CharType(',') << v.y << CharType(')');
}
template <class CharType>
inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const DPoint& v) {
	return os << CharType('(') << v.x << CharType(',') << v.y << CharType(')');
}
template <class CharType>
inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Size& v) {
	return os << CharType('(') << v.width << CharType(',') << v.height << CharType(')');
}
template <class CharType>
inline std::basic_ostream<CharType>& operator << (std::basic_ostream<CharType>& os, const Color& v) {
	return os << CharType('(') << (int)v.r << CharType(',') << (int)v.g << CharType(',') << (int)v.b << CharType(',') << (int)v.a << CharType(')');
}

namespace Palette {
	const Color white(0xFFFFFF);
	const Color whitesmoke(0xF5F5F5);
	const Color ghostwhite(0xF8F8FF);
	const Color aliceblue(0xF0F8FF);
	const Color lavendar(0xE6E6FA);
	const Color azure(0xF0FFFF);
	const Color lightcyan(0xE0FFFF);
	const Color mintcream(0xF5FFFA);
	const Color honeydew(0xF0FFF0);
	const Color ivory(0xFFFFF0);
	const Color beige(0xF5F5DC);
	const Color lightyellow(0xFFFFE0);
	const Color lightgoldenrodyellow(0xFAFAD2);
	const Color lemonchiffon(0xFFFACD);
	const Color floralwhite(0xFFFAF0);
	const Color oldlace(0xFDF5E6);
	const Color cornsilk(0xFFF8DC);
	const Color papayawhite(0xFFEFD5);
	const Color blanchedalmond(0xFFEBCD);
	const Color bisque(0xFFE4C4);
	const Color snow(0xFFFAFA);
	const Color linen(0xFAF0E6);
	const Color antiquewhite(0xFAEBD7);
	const Color seashell(0xFFF5EE);
	const Color lavenderblush(0xFFF0F5);
	const Color mistyrose(0xFFE4E1);
	const Color gainsboro(0xDCDCDC);
	const Color lightgray(0xD3D3D3);
	const Color lightsteelblue(0xB0C4DE);
	const Color lightblue(0xADD8E6);
	const Color lightskyblue(0x87CEFA);
	const Color powderblue(0xB0E0E6);
	const Color paleturquoise(0xAFEEEE);
	const Color skyblue(0x87CEEB);
	const Color mediumaquamarine(0x66CDAA);
	const Color aquamarine(0x7FFFD4);
	const Color palegreen(0x98FB98);
	const Color lightgreen(0x90EE90);
	const Color khaki(0xF0E68C);
	const Color palegoldenrod(0xEEE8AA);
	const Color moccasin(0xFFE4B5);
	const Color navajowhite(0xFFDEAD);
	const Color peachpuff(0xFFDAB9);
	const Color wheat(0xF5DEB3);
	const Color pink(0xFFC0CB);
	const Color lightpink(0xFFB6C1);
	const Color thistle(0xD8BFD8);
	const Color plum(0xDDA0DD);
	const Color silver(0xC0C0C0);
	const Color darkgray(0xA9A9A9);
	const Color lightslategray(0x778899);
	const Color slategray(0x708090);
	const Color slateblue(0x6A5ACD);
	const Color steelblue(0x4682B4);
	const Color mediumslateblue(0x7B68EE);
	const Color royalblue(0x4169E1);
	const Color blue(0x0000FF);
	const Color dodgerblue(0x1E90FF);
	const Color cornflowerblue(0x6495ED);
	const Color deepskyblue(0x00BFFF);
	const Color cyan(0x00FFFF);
	const Color aqua(0x00FFFF);
	const Color turquoise(0x40E0D0);
	const Color mediumturquoise(0x48D1CC);
	const Color darkturquoise(0x00CED1);
	const Color lightseagreen(0x20B2AA);
	const Color mediumspringgreen(0x00FA9A);
	const Color springgreen(0x00FF7F);
	const Color lime(0x00FF00);
	const Color limegreen(0x32CD32);
	const Color yellowgreen(0x9ACD32);
	const Color lawngreen(0x7CFC00);
	const Color chartreuse(0x7FFF00);
	const Color greenyellow(0xADFF2F);
	const Color yellow(0xFFFF00);
	const Color gold(0xFFD700);
	const Color orange(0xFFA500);
	const Color darkorange(0xFF8C00);
	const Color goldenrod(0xDAA520);
	const Color burlywood(0xDEB887);
	const Color tan(0xD2B48C);
	const Color sandybrown(0xF4A460);
	const Color darksalmon(0xE9967A);
	const Color lightcoral(0xF08080);
	const Color salmon(0xFA8072);
	const Color lightsalmon(0xFFA07A);
	const Color coral(0xFF7F50);
	const Color tomato(0xFF6347);
	const Color orangered(0xFF4500);
	const Color red(0xFF0000);
	const Color deeppink(0xFF1493);
	const Color hotpink(0xFF69B4);
	const Color palevioletred(0xDB7093);
	const Color violet(0xEE82EE);
	const Color orchid(0xDA70D6);
	const Color magenta(0xFF00FF);
	const Color fuchsia(0xFF00FF);
	const Color mediumorchid(0xBA55D3);
	const Color darkorchid(0x9932CC);
	const Color darkviolet(0x9400D3);
	const Color blueviolet(0x8A2BE2);
	const Color mediumpurple(0x9370DB);
	const Color gray(0x808080);
	const Color mediumblue(0x0000CD);
	const Color darkcyan(0x008B8B);
	const Color cadetblue(0x5F9EA0);
	const Color darkseagreen(0x8FBC8F);
	const Color mediumseagreen(0x3CB371);
	const Color teal(0x008080);
	const Color forestgreen(0x228B22);
	const Color seagreen(0x2E8B57);
	const Color darkkhaki(0xBDB76B);
	const Color peru(0xCD853F);
	const Color crimson(0xDC143C);
	const Color indianred(0xCD5C5C);
	const Color rosybrown(0xBC8F8F);
	const Color mediumvioletred(0xC71585);
	const Color dimgray(0x696969);
	const Color black(0x000000);
	const Color midnightblue(0x191970);
	const Color darkslateblue(0x483D8B);
	const Color darkblue(0x00008B);
	const Color navy(0x000080);
	const Color darkslategray(0x2F4F4F);
	const Color green(0x008000);
	const Color darkgreen(0x006400);
	const Color darkolivegreen(0x556B2F);
	const Color olivedrab(0x6B8E23);
	const Color olive(0x808000);
	const Color darkgoldenrod(0xB8860B);
	const Color chocolate(0xD2691E);
	const Color sienna(0xA0522D);
	const Color saddlebrown(0x8B4513);
	const Color firebrick(0xB22222);
	const Color brown(0xA52A2A);
	const Color maroon(0x800000);
	const Color darkred(0x8B0000);
	const Color darkmagenta(0x8B008B);
	const Color purple(0x800080);
	const Color indigo(0x4B0082);
}

class System;

/// <summary>
///	<para>タイマー用のクラス</para>
///	<para>使用禁止</para>
///	</summary>
class AcyncTimer {
public:

	friend System;

private:

	AcyncTimer() {}
	AcyncTimer(function<void(int)> _func) {
		func = _func;
	}

	static void timer(int v) {

		func(value);

		glutTimerFunc(time, AcyncTimer::timer, value);
	}

	static function<void(int)> func;

	static unsigned int time;
	static int value;

};

/// <summary>
///	<para>OpenGLをパッケージしたクラス</para>
///	<para>各種初期設定を行った後に、windowCreateを実行してください</para>
///	</summary>
class System {
public:

	/// <summary>各種設定の初期化</summary>
	System() : System(0, nullptr) {}
	/// <summary>各種設定の初期化</summary>
	/// <param name="argc">argvの要素数</param>
	/// <param name="argv">文字列の配列</param>
	System(int argc, char *argv[]) {
		glutInit(&argc, argv);
		init();
	}

	/// <summary>
	///	<para>ウインドウの作成・設定されたプログラムの実行を行う</para>
	///	<para>実行後は各種設定の変更は行えません</para>
	///	</summary>
	void create() {
		glutInitDisplayMode(displayMode);

		glutInitWindowSize(size.width, size.height);
		glutCreateWindow(title.c_str());//ここでウインドウを作成している
		glClearColor(GLclampf(clearColor.r / 255.0), GLclampf(clearColor.g / 255.0), GLclampf(clearColor.b / 255.0), GLclampf(clearColor.a / 255.0));

		gluOrtho2D(GLdouble(ortho2DPoint[0].x), GLdouble(ortho2DPoint[1].x), GLdouble(ortho2DPoint[1].y), GLdouble(ortho2DPoint[0].y));//一度決めたら変更できない模様

		if (displayFunction)
		{
			using DisplayFuncPointer = void(*)();
			DisplayFuncPointer* dp = displayFunction.target<DisplayFuncPointer>();
			if (dp != nullptr)
				glutDisplayFunc(*dp);
		}

		if (timerFunction)
		{
			using TimerFuncPointer = void(*)(int);
			TimerFuncPointer* tp = timerFunction.target<TimerFuncPointer>();
			if (tp != nullptr)
			{
				AcyncTimer acyncTimer(timerFunction);

				glutTimerFunc(AcyncTimer::time, AcyncTimer::timer, AcyncTimer::value);
			}
		}

		glutMainLoop();//メインループ

	}

	/// <summary>ウインドウの大きさを設定する</summary>
	/// <param name="width">横幅</param>
	/// <param name="height">高さ</param>
	void setSize(const int width, const int height) { size = Size(width, height); }
	/// <summary>ウインドウの大きさを設定する</summary>
	/// <param name="_size">大きさ</param>
	void setSize(const Size& _size) { size = _size; }

	/// <summary>ウインドウのタイトルを設定する</summary>
	/// <param name="name">タイトル</param>
	void setTitle(const string& name) { title = name; }

	/// <summary>画面がクリアされるときの色を設定する</summary>
	/// <param name="r">赤色成分(0～255)</param>
	/// <param name="g">緑色成分(0～255)</param>
	/// <param name="b">青色成分(0～255)</param>
	void setClearColor(const byte r, const byte g, const byte b) { setClearColor(Color(r, g, b)); }
	/// <summary>画面がクリアされるときの色を設定する</summary>
	/// <param name="r">赤色成分(0～255)</param>
	/// <param name="g">緑色成分(0～255)</param>
	/// <param name="b">青色成分(0～255)</param>
	/// <param name="a">透明度(0～255)</param>
	void setClearColor(const byte r, const byte g, const byte b, const byte a) { setClearColor(Color(r, g, b, a)); }
	/// <summary>画面がクリアされるときの色を設定する</summary>
	/// <param name="_color">色</param>
	void setClearColor(const Color& _color) { clearColor = _color; }

	/// <summary>ウインドウの座標を設定する</summary>
	/// <param name="left">左端の座標値</param>
	/// <param name="right">右端の座標値</param>
	/// <param name="bottom">下端の座標値</param>
	/// <param name="top">上端の座標値</param>
	void setOrtho2D(const double left, const double right, const double bottom, const double top) { setOrtho2D(DPoint(left, top), DPoint(right, bottom)); }
	/// <summary>ウインドウの座標を設定する</summary>
	/// <param name="left_top">左上の座標値</param>
	/// <param name="right_bottom">右下の座標値</param>
	void setOrtho2D(const DPoint& left_top, const DPoint& right_bottom) { ortho2DPoint[0] = left_top; ortho2DPoint[1] = right_bottom; }

	/// <summary>ディスプレイモードの設定</summary>
	/// <param name="mode">ディスプレイモードのフラグ</param>
	void setDisplayMode(const unsigned int mode) { displayMode = mode; }

	/// <summary>描画関数を設定する</summary>
	/// <param name="func">描画する関数ポインタ</param>
	void setDisplayFunc(function<void()> func) { displayFunction = func; }

	/// <summary>
	///	<para>timeに設定された時間毎に、設定された関数を実行する</para>
	///	<para>制限：関数内でglutTimerFuncを実行しないでください</para>
	///	</summary>
	/// <param name="time">実行する間隔(ms)</param>
	/// <param name="func">実行する関数</param>
	/// <param name="value">実行する関数の引数</param>
	void setTimerFunc(unsigned int time, function<void(int)> func, int value) { timerFunction = func; AcyncTimer::time = time; AcyncTimer::value = value; }

private:

	Size size;
	string title;
	Color clearColor;

	unsigned int displayMode;

	/// <summary>
	/// <para>0:右上の座標</para>
	/// <para>1:左下の座標</para>
	/// </summary>
	DPoint ortho2DPoint[2];

	function<void()> displayFunction;
	function<void(int)> timerFunction;


	void init() {
		size = Size(640, 480);
		title = "OpenGL";
		clearColor = Palette::black;

		displayMode = GLUT_RGBA | GLUT_DOUBLE;

		ortho2DPoint[0] = Point(0, 0);
		ortho2DPoint[1] = Point(640, 480);

		AcyncTimer::time = 16;
		AcyncTimer::value = 0;

	}

};
