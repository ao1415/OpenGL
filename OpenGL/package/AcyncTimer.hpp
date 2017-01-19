#pragma once

#include <GL/glut.h>
#include <functional>

namespace opc {

	class System;

	/// <summary>
	///	<para>タイマー用のクラス</para>
	///	<para>使用禁止</para>
	///	</summary>
	class AcyncTimer {
	private:

		friend System;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		AcyncTimer();
		/// <summary>コンストラクタ</summary>
		/// <param name="v">実行関数</param>
		AcyncTimer(std::function<void(int)> _func);

		/// <summary>実行制御関数</summary>
		/// <param name="v">引数</param>
		static void timer(int v);

		/// <summary>
		/// 実行関数
		/// </summary>
		static std::function<void(int)> func;

		/// <summary>
		/// 実行間隔
		/// </summary>
		static unsigned int time;
		/// <summary>
		/// 実行時引数
		/// </summary>
		static int value;

	};

}
