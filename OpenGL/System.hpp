#pragma once

#include <string>

#include "Display.hpp"
#include "AcyncTimer.hpp"
#include "Point.hpp"
#include "Size.hpp"
#include "Palette.hpp"

namespace opc {

	/// <summary>
	///	<para>OpenGLをパッケージしたクラス</para>
	///	<para>各種初期設定を行った後に、windowCreateを実行してください</para>
	///	</summary>
	class System {
	public:

		/// <summary>各種設定の初期化</summary>
		System();
		/// <summary>各種設定の初期化</summary>
		/// <param name="argc">argvの要素数</param>
		/// <param name="argv">文字列の配列</param>
		System(int argc, char *argv[]);

		/// <summary>
		///	<para>ウインドウの作成・設定されたプログラムの実行を行う</para>
		///	<para>実行後は各種設定の変更は行えません</para>
		///	</summary>
		void create();

		/// <summary>ウインドウの大きさを設定する</summary>
		/// <param name="width">横幅</param>
		/// <param name="height">高さ</param>
		void setSize(const int width, const int height);
		/// <summary>ウインドウの大きさを設定する</summary>
		/// <param name="_size">大きさ</param>
		void setSize(const Size& _size);

		/// <summary>ウインドウのタイトルを設定する</summary>
		/// <param name="name">タイトル</param>
		void setTitle(const std::string& name);

		/// <summary>画面がクリアされるときの色を設定する</summary>
		/// <param name="r">赤色成分(0～255)</param>
		/// <param name="g">緑色成分(0～255)</param>
		/// <param name="b">青色成分(0～255)</param>
		void setClearColor(const int r, const int g, const int b);
		/// <summary>画面がクリアされるときの色を設定する</summary>
		/// <param name="r">赤色成分(0～255)</param>
		/// <param name="g">緑色成分(0～255)</param>
		/// <param name="b">青色成分(0～255)</param>
		/// <param name="a">透明度(0～255)</param>
		void setClearColor(const int r, const int g, const int b, const int a);
		/// <summary>画面がクリアされるときの色を設定する</summary>
		/// <param name="_color">色</param>
		void setClearColor(const Color& _color);

		/// <summary>ウインドウの座標を設定する</summary>
		/// <param name="left">左端の座標値</param>
		/// <param name="right">右端の座標値</param>
		/// <param name="bottom">下端の座標値</param>
		/// <param name="top">上端の座標値</param>
		void setOrtho2D(const double left, const double right, const double bottom, const double top);
		/// <summary>ウインドウの座標を設定する</summary>
		/// <param name="left_top">左上の座標値</param>
		/// <param name="right_bottom">右下の座標値</param>
		void setOrtho2D(const RealPoint& left_top, const RealPoint& right_bottom);

		/// <summary>ディスプレイモードの設定</summary>
		/// <param name="mode">ディスプレイモードのフラグ</param>
		void setDisplayMode(const unsigned int mode);

		/// <summary>描画関数を設定する</summary>
		/// <param name="func">描画する関数ポインタ</param>
		void setDisplayFunc(std::function<void()> func);

		/// <summary>
		///	<para>timeに設定された時間毎に、設定された関数を実行する</para>
		///	<para>制限：関数内でglutTimerFuncを実行しないでください</para>
		///	</summary>
		/// <param name="time">実行する間隔(ms)</param>
		/// <param name="func">実行する関数</param>
		/// <param name="value">実行する関数の引数</param>
		void setTimerFunc(unsigned int time, std::function<void(int)> func, int value);

	private:

		Size size;
		std::string title;
		Color clearColor;

		unsigned int displayMode;

		/// <summary>
		/// <para>0:右上の座標</para>
		/// <para>1:左下の座標</para>
		/// </summary>
		RealPoint ortho2DPoint[2];

		std::function<void()> displayFunction;
		std::function<void(int)> timerFunction;


		/// <summary>初期設定</summary>
		void init() {
			size = Size(640, 480);
			title = "OpenGL";
			clearColor = Palette::Black;

			displayMode = GLUT_RGBA | GLUT_DOUBLE;

			ortho2DPoint[0] = IntPoint(0, 0);
			ortho2DPoint[1] = IntPoint(640, 480);

			AcyncTimer::time = 16;
			AcyncTimer::value = 0;

		}

	};

}
