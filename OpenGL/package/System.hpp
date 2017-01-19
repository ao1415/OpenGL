#pragma once

#include "Window.hpp"
#include "Grid.hpp"
#include "Bitmap.hpp"
#include "Mouse.hpp"

namespace opc {

	/// <summary>
	///	ディスプレイの設定コマンド
	///	</summary>
	enum class DisplayMode : unsigned int {
		/// <summary>
		/// RGBAモード
		/// </summary>
		RGBA = GLUT_RGBA,
		/// <summary>
		/// RGBモード
		/// </summary>
		RGB = GLUT_RGB,
		/// <summary>
		/// カラーインデックスモード
		/// </summary>
		Index = GLUT_INDEX,
		/// <summary>
		/// シングルバッファモード
		/// </summary>
		Single = GLUT_SINGLE,
		/// <summary>
		/// ダブルバッファモード
		/// </summary>
		Double = GLUT_DOUBLE,
		/// <summary>
		/// アキュムレーションバッファ
		/// </summary>
		Accum = GLUT_ACCUM,
		/// <summary>
		/// カラーバッファにアルファ成分を加える
		/// </summary>
		Alpha = GLUT_ALPHA,
		/// <summary>
		/// ディプス(Z)バッファを加える
		/// </summary>
		Depth = GLUT_DEPTH,
		/// <summary>
		/// マルチサンプリングのサポート
		/// </summary>
		Stencil = GLUT_STENCIL,
		/// <summary>
		/// </summary>
		MultiSample = GLUT_MULTISAMPLE,
		/// <summary>
		/// ステレオ・ウインドウビットマスク
		/// </summary>
		Stereo = GLUT_STEREO
	};

	/// <summary>
	///	クリアバッファの設定コマンド
	///	</summary>
	enum class ClearMode : unsigned int {
		/// <summary>
		/// 色
		/// </summary>
		Color = GL_COLOR_BUFFER_BIT,
		/// <summary>
		/// 深度
		/// </summary>
		Depth = GL_DEPTH_BUFFER_BIT,
		/// <summary>
		/// </summary>
		Accum = GL_ACCUM_BUFFER_BIT,
		/// <summary>
		/// </summary>
		Stencil = GL_STENCIL_BUFFER_BIT
	};

	/// <summary>
	///	<para>OpenGLをパッケージしたクラス</para>
	///	<para>各種初期設定を行った後に、windowCreateを実行してください</para>
	///	</summary>
	class System {
	public:

		/// <summary>
		///	コンストラクタ
		///	</summary>
		System();
		/// <summary>コンストラクタ</summary>
		/// <param name="argc">argvの要素数</param>
		/// <param name="argv">文字列の配列</param>
		System(int argc, char *argv[]);

		/// <summary>
		///	<para>ウインドウの作成</para>
		///	<para>実行後は各種設定の変更は行えません</para>
		///	</summary>
		void create();

		/// <summary>
		///	設定されたプログラムを実行します
		///	</summary>
		void update();

		/// <summary>ディスプレイモードの設定</summary>
		/// <param name="mode">ディスプレイモードのフラグ</param>
		void setDisplayMode(const unsigned int mode);
		/// <summary>ディスプレイモードの設定</summary>
		/// <param name="...rest">DisplayMode</param>
		template<typename... Rest>
		void setDisplayMode(const Rest&... rest) {
			if (SystemState::getMakeWindow())
				throw SettingErrer("ディスプレイモードを変更できませんでした");
			displayMode = orFlag(rest...);
		}

		/// <summary>バッファクリアの設定</summary>
		/// <param name="mode">バッファクリアのフラグ</param>
		void setClearMode(const unsigned int mode);
		/// <summary>バッファクリアの設定</summary>
		/// <param name="...rest">ClearMode</param>
		template<typename... Rest>
		void setClearMode(const Rest&... rest) {
			if (SystemState::getMakeWindow())
				throw SettingErrer("クリアモードを変更できませんでした");
			clearMode = orFlag(rest...);
		}

		/// <summary>
		/// <para>設定を有効にします</para>
		///	<para>詳細:https://www.opengl.org/sdk/docs/man2/xhtml/glEnable.xml</para>
		/// </summary>
		/// <param name="mode">cap</param>
		void enable(const unsigned int mode);
		/// <summary>
		/// <para>設定を無効にします</para>
		///	<para>詳細:https://www.opengl.org/sdk/docs/man2/xhtml/glEnable.xml</para>
		/// </summary>
		/// <param name="mode">cap</param>
		void disable(const unsigned int mode);

		/// <summary>描画関数を設定する</summary>
		/// <param name="func">関数ポインタ</param>
		void setDisplayFunc(std::function<void()> func);

		/// <summary>
		///	<para>timeに設定された時間毎に、設定された関数を実行する</para>
		///	<para>制限：関数内でglutTimerFuncを実行しないでください</para>
		///	</summary>
		/// <param name="time">実行する間隔(ms)</param>
		/// <param name="func">実行する関数</param>
		/// <param name="value">実行する関数の引数</param>
		void setTimerFunc(unsigned int time, std::function<void(int)> func, int value);

		/// <summary>マウスクリックの関数を登録する</summary>
		/// <param name="func">関数ポインタ</param>
		void setMouseFunc(std::function<void(int, int, int, int)> func);

		/// <summary>マウス動作の関数を登録する</summary>
		/// <param name="func">関数ポインタ</param>
		void setMouseMotionFunc(std::function<void()> func);

	private:

		/// <summary>
		/// ディスプレイ設定
		/// </summary>
		unsigned int displayMode;
		/// <summary>
		/// バッファクリア設定
		/// </summary>
		unsigned int clearMode;

		/// <summary>
		/// 有効にするモードの配列
		/// </summary>
		std::vector<unsigned int> enableConfig;
		/// <summary>
		/// 無効にするモードの配列
		/// </summary>
		std::vector<unsigned int> disableConfig;

		/// <summary>
		/// 描画関数
		/// </summary>
		std::function<void()> displayFunction = nullptr;
		/// <summary>
		/// タイマー関数
		/// </summary>
		std::function<void(int)> timerFunction = nullptr;

		/// <summary>
		/// マウス入力関数
		/// </summary>
		std::function<void(int, int, int, int)> mouseFunction = nullptr;
		/// <summary>
		/// マウス動作関数
		/// </summary>
		std::function<void()> motionFunction = nullptr;


		/// <summary>
		///	初期設定
		///	</summary>
		void init() {

			Window::setSize(IntSize(640, 480));
			Window::setTitle("OpenGL");
			Window::setClearColor(Palette::Black);
			setDisplayMode(DisplayMode::RGBA, DisplayMode::Double);

			AcyncTimer::time = 16;
			AcyncTimer::value = 0;

		}


		/// <summary>フラグの加算関数</summary>
		/// <param name="...rest">加算したいフラグ</param>
		/// <returns>加算されたフラグ</returns>
		template<typename First, typename... Rest>
		const unsigned int orFlag(const First& first, const Rest&... rest) {
			return (unsigned int)first | orFlag(rest...);
		}
		/// <summary>フラグの加算関数(終端用)</summary>
		/// <returns>0</returns>
		inline const unsigned int orFlag() {
			return 0;
		}

	};

}
