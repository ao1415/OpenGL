#pragma once

#include <GL/glut.h>
#include <functional>

namespace opc {

	class System;

	/// <summary>
	///	<para>表示用のクラス</para>
	///	<para>使用禁止</para>
	///	</summary>
	class Display {
	private:

		friend System;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		Display();
		/// <summary>コンストラクタ</summary>
		/// <param name="v">実行関数</param>
		Display(std::function<void()> _func);

		/// <summary>実行制御関数</summary>
		static void display();

		/// <summary>
		/// 実行関数
		/// </summary>
		static std::function<void()> func;
		/// <summary>
		/// 画面削除の設定
		/// </summary>
		static unsigned int clearMode;

	};

}
