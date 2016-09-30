#pragma once

#include "Window.hpp"

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

		unsigned int displayMode;

		std::function<void()> displayFunction;
		std::function<void(int)> timerFunction;


		/// <summary>初期設定</summary>
		void init() {
			Window::size = Size(640, 480);
			Window::title = "OpenGL";
			Window::clearColor = Palette::Black;

			displayMode = GLUT_RGBA | GLUT_DOUBLE;

			//Window::ortho2DPoint[0] = IntPoint(0, 0);
			//Window::ortho2DPoint[1] = IntPoint(640, 480);

			AcyncTimer::time = 16;
			AcyncTimer::value = 0;

		}

	};

}
