#pragma once

#include "Exception.hpp"

namespace opc {

	class System;
	class Window;

	/// <summary>
	/// ウインドウステータスの設定
	/// </summary>
	class SystemState {
	public:

		/// <summary>
		/// 描画モード
		/// </summary>
		enum class StandardPoint : unsigned char {
			Mode_2D = 0x01,
			Mode_3D = 0x02,
		};

		/// <summary>ウインドウが作成されたかを返す</summary>
		/// <returns>作成されていたらtrue, 作成されていなかったらfalse</returns>
		inline static const bool getMakeWindow() { return makeWindow; }

		/// <summary>描画モードを返す</summary>
		/// <returns>描画モード</returns>
		inline static const unsigned char getStandardPoint() { return standardPoint; }
		/// <summary>描画モードを返す</summary>
		///	<param name="s">描画モード</param>
		/// <returns>指定されたモードならばtrue, それ以外はfalse</returns>
		inline static const bool getStandardPoint(const StandardPoint& s) {
			return (standardPoint & (char)s) > 0;
		}

		friend System;
		friend Window;

	private:

		/// <summary>
		///	ウインドウが作成されたかのフラグ
		///	</summary>
		static bool makeWindow;

		/// <summary>
		///	座標の設定のフラグ
		///	</summary>
		static unsigned char standardPoint;

		/// <summary>描画モードの設定</summary>
		///	<param name="s">描画モード</param>
		inline static void setStandardPoint(const StandardPoint& s) { standardPoint = (char)s; }

	};

}
