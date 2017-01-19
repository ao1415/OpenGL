#pragma once

#include "GL/glut.h"
#include <vector>
#include <string>
#include "Property.hpp"
#include "Palette.hpp"
#include "Grid.hpp"

namespace opc {

	/// <summary>
	/// Bitmap画像を扱うクラス
	/// </summary>
	class Bitmap {
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		Bitmap() = default;
		/// <summary>コンストラクタ</summary>
		/// <param name="path">画像ファイルのパス</param>
		Bitmap(const std::string& path);
		/// <summary>コンストラクタ</summary>
		/// <param name="b">コピーする<see cref="Bitmap"/></param>
		Bitmap(const Bitmap& b) = default;
		/// <summary>コンストラクタ</summary>
		/// <param name="b">移動する<see cref="Bitmap"/></param>
		Bitmap(Bitmap&& b) {
			width = b.width;
			height = b.height;
			data = std::move(b.data);
			b.width = b.height = 0;
		}

		/// <summary>コピー演算子</summary>
		/// <param name="other">コピーする<see cref="Bitmap"/></param>
		/// <returns><see cref="Bitmap"/></returns>
		Bitmap& operator=(const Bitmap& other) = default;
		/// <summary>ムーブ演算子</summary>
		/// <param name="other">移動する<see cref="Bitmap"/></param>
		/// <returns><see cref="Bitmap"/></returns>
		Bitmap& operator=(Bitmap&& other) = default;

		/// <summary>画像が読み込まれたかを返す</summary>
		/// <returns>読み込まれた場合 true, それ以外の場合は false</returns>
		operator bool() const;

		/// <summary>画像を読み込む</summary>
		/// <param name="path">画像ファイルのパス</param>
		void load(const std::string& path);

		/// <summary>OpenGLのテクスチャを得る</summary>
		/// <returns><see cref="GLuint"/></returns>
		Property_Get(GLuint, Texture) const { return texture; }
		/// <summary>画像の幅を得る</summary>
		/// <returns>幅</returns>
		Property_Get(size_t, Width) const { return width; }
		/// <summary>画像の高さを得る</summary>
		/// <returns>高さ</returns>
		Property_Get(size_t, Height) const { return height; }

		/// <summary>ピクセルにアクセスする</summary>
		/// <param name="pos">座標</param>
		/// <returns>色</returns>
		const Color& operator[](const Point& pos) const { return colorMap[pos]; }

	private:
		/// <summary>
		/// 画像の幅
		/// </summary>
		size_t width = 0;
		/// <summary>
		/// 画像の高さ
		/// </summary>
		size_t height = 0;

		/// <summary>
		/// 画像が読み込まれたかのフラグ
		/// </summary>
		bool flag = false;

		/// <summary>
		///	OpenGLのテクスチャアドレス
		/// </summary>
		GLuint texture;

		/// <summary>
		/// カラーデータ
		/// </summary>
		std::vector<unsigned char> data;
		/// <summary>
		/// カラーピクセル
		/// </summary>
		Grid<Color> colorMap;

		/// <summary>
		/// OpenGLのテクスチャを作成する
		/// </summary>
		void setTexture();

	};

}
