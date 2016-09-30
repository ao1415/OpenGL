#pragma once

#include "Window.hpp"

namespace opc {

	/// <summary>ディスプレイの設定コマンド</summary>
	enum class DisplayMode : unsigned int {
		/// <summary>RGBAモード</summary>
		RGBA = GLUT_RGBA,
		/// <summary>RGBモード</summary>
		RGB = GLUT_RGB,
		/// <summary>カラーインデックスモード</summary>
		Index = GLUT_INDEX,
		/// <summary>シングルバッファモード</summary>
		Single = GLUT_SINGLE,
		/// <summary>ダブルバッファモード</summary>
		Double = GLUT_DOUBLE,
		/// <summary>アキュムレーションバッファ</summary>
		Accum = GLUT_ACCUM,
		/// <summary>カラーバッファにアルファ成分を加える</summary>
		Alpha = GLUT_ALPHA,
		/// <summary>ディプス(Z)バッファを加える</summary>
		Depth = GLUT_DEPTH,
		/// <summary>マルチサンプリングのサポート</summary>
		Stencil = GLUT_STENCIL,
		/// <summary></summary>
		MultiSample = GLUT_MULTISAMPLE,
		/// <summary>ステレオ・ウインドウビットマスク</summary>
		Stereo = GLUT_STEREO
	};

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
		/// <summary>ディスプレイモードの設定</summary>
		/// <param name="...rest">DisplayMode</param>
		template<typename... Rest>
		void setDisplayMode(const Rest&... rest) {
			displayMode = getDisplayMode(rest...);
		}

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
			
			Window::setSize(Size(640, 480));
			Window::setTitle("OpenGL");
			Window::setClearColor(Palette::Black);
			setDisplayMode(DisplayMode::RGBA, DisplayMode::Double);

			AcyncTimer::time = 16;
			AcyncTimer::value = 0;

		}

		template<typename First,typename... Rest>
		const unsigned int getDisplayMode(const First& first, const Rest&... rest) {
			return (unsigned int)first | getDisplayMode(rest...);
		}
		inline const unsigned int getDisplayMode() {
			return 0;
		}

	};

}
