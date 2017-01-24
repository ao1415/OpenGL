#pragma once

#include "GL/glut.h"
#include "Point.hpp"
#include "Size.hpp"
#include "Property.hpp"

#include <functional>

namespace opc {

	class System;

	/// <summary>
	/// マウス入力を管理するクラス
	/// </summary>
	class Mouse {
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		Mouse();

		/// <summary>右クリックされたかを返す</summary>
		/// <returns>右クリックされていたらtrue, それ以外はfalse</returns>
		Property_Get(bool, mouseL_Click) const {
			return (pressed && pressedButton == GLUT_LEFT_BUTTON);
		}
		/// <summary>左クリックされたかを返す</summary>
		/// <returns>左クリックされていたらtrue, それ以外はfalse</returns>
		Property_Get(bool, mouseR_Click) const {
			return (pressed && pressedButton == GLUT_RIGHT_BUTTON);
		}
		/// <summary>中クリックされたかを返す</summary>
		/// <returns>中クリックされていたらtrue, それ以外はfalse</returns>
		Property_Get(bool, mouseM_Click) const {
			return (pressed && pressedButton == GLUT_MIDDLE_BUTTON);
		}

		/// <summary>クリックされた場所を返す</summary>
		/// <returns>クリックされた場所</returns>
		Property_Get(Point, ClickPos) const {
			return clickPos;
		}
		/// <summary>ドラッグされた場所を返す</summary>
		/// <returns>ドラッグされた場所</returns>
		Property_Get(Point, MotionPos) const {
			return motionPos;
		}
		/// <summary>直前にクリックされた場所を返す</summary>
		/// <returns>直前にクリックされた場所</returns>
		Property_Get(Point, PreviousPos) const {
			return previousPos;
		}

	private:

		/// <summary>
		///	キーが押されているか
		///	</summary>
		static bool pressed;
		/// <summary>
		///	押されているキー
		///	</summary>
		static int pressedButton;

		/// <summary>
		///	カーソルが動いたか
		///	</summary>
		static bool moved;

		/// <summary>
		///	クリックした座標
		///	</summary>
		static Point clickPos;
		/// <summary>
		///	ドラッグした座標
		///	</summary>
		static Point motionPos;
		/// <summary>
		///	直前の座標
		///	</summary>
		static Point previousPos;

		/// <summary>
		/// マウス入力の実行関数
		/// </summary>
		static std::function<void(int, int, int, int)> mouseFunc;
		/// <summary>
		/// マウス動作の実行関数
		/// </summary>
		static std::function<void()> motionFunc;

		friend System;

		/// <summary>コンストラクタ</summary>
		/// <param name="_mouse">入力実行関数</param>
		/// <param name="_motion">動作実行関数</param>
		Mouse(std::function<void(int, int, int, int)> _mouse, std::function<void()> _motion);

		/// <summary>マウス入力の実行関数を設定する</summary>
		/// <param name="_mouse">入力実行関数</param>
		static void setMouse(std::function<void(int, int, int, int)> _mouse);
		/// <summary>マウス動作の実行関数を設定する</summary>
		/// <param name="_motion">動作実行関数</param>
		static void setMotion(std::function<void()> _motion);

		/// <summary>入力実行制御関数</summary>
		/// <param name="btn">ボタン入力</param>
		/// <param name="state">ボタンの状態</param>
		/// <param name="x">x座標</param>
		/// <param name="y">y座標</param>
		static void mouse(int btn, int state, int x, int y);
		/// <summary>動作実行制御関数</summary>
		/// <param name="x">x座標</param>
		/// <param name="y">y座標</param>
		static void motion(int x, int y);

	};

}
