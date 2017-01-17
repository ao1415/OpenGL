#include "OpenGL.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

//表示用のクラス
class DrawImage {
public:

	//ピクセル軍を表示
	void display()
	{
		View::Perspective(30, 1, 1, 15000);

		View::LookAt(RealVector(0, 0, 1000), RealVector(0, 0, 0), RealVector(0, -1, 0));

		View::Translate(RealVector(camera.x, camera.y, 0));
		View::Rotate(angle.x, RealVector(-1, 0, 0));
		View::Rotate(angle.y, RealVector(0, -1, 0));

		for (int y = 0; y < textureSize.height; y++)
		{
			for (int x = 0; x < textureSize.width; x++)
			{
				//Draw3D::Pixel(-textureSize.width / 2.0 + x, -textureSize.height / 2.0 + y, 255.0 - bitmap[y][x].first)
				Draw3D::Pixel(-textureSize.width / 2.0 + x, -textureSize.height / 2.0 + y, (bitmap[y][x].first)*8.0)
					.draw(2, bitmap[y][x].second);
			}
		}

	}

	//一定間隔で描画更新
	void timer(int value) {

		glutPostRedisplay();
	}

	//マウスの動作
	void mouseMotion()
	{
		Mouse mouse;

		const auto pos = mouse.MotionPos;
		const auto prePos = mouse.PreviousPos;
		int xdir, ydir;

		xdir = pos.x - prePos.x;
		ydir = pos.y - prePos.y;

		if (mouse.mouseL_Click)
		{
			angle.x += (double)ydir * 0.5;
			angle.y += (double)xdir * 0.5;
		}
		if (mouse.mouseR_Click)
		{
			camera.x -= xdir / 40.0;
			camera.y += ydir / 40.0;
		}
	}

	//画像ファイルを読み込む
	void load() {

		int w, h;

		ifstream ifs("256.txt");
		if (!ifs)
		{
			cerr << "ファイルが開けません" << endl;
			return;
		}

		ifs >> w >> h;
		textureSize.width = w;
		textureSize.height = h;

		bitmap.resize(w, h, { 0,Color(255,255,255,0) });
		cout << "画像読み込み開始" << endl;
		for (int y = 0; y < h; y++)
		{
			for (int x = w - 1; x >= 0; x--)
			{
				int r, g, b, d;
				ifs >> r >> g >> b >> d;

				bitmap[y][x] = { d,Color(r,g,b) };
			}
		}
		cout << "画像読み込み終了" << endl;

	}

private:

	RealPoint angle;
	RealPoint camera;

	IntSize textureSize;
	Grid<pair<int, Color>> bitmap;

};

int main(int argc, char *argv[])
{
	//3D表示を行うクラスの宣言
	DrawImage drawImage;

	
	//データの読み込み
	drawImage.load();

	
	//ウインドウ作成クラスの宣言
	System system;


	//ウインドウの大きさを設定する
	Window::setSize(960, 960);


	//表示の設定(色:RGBA, 表示方法:ダブルバッファ)
	system.setDisplayMode(DisplayMode::RGBA, DisplayMode::Double);
	//バッファクリアの設定(色情報, 深さ情報を削除する)
	system.setClearMode(ClearMode::Color, ClearMode::Depth);


	//OpenGLの設定を有効にする(3D表示機能を有効にする)
	system.enable(GL_DEPTH_TEST);


	//表示画面を設定する(DrawImage::display)
	system.setDisplayFunc([&]() {drawImage.display(); });
	//タイマーを設定する(DrawImage::timer)
	system.setTimerFunc(10, [&](int v) {drawImage.timer(v); }, 0);
	//マウス動作を設定する(DrawImage::timer)
	system.setMouseMotionFunc([&]() {drawImage.mouseMotion(); });


	//ウインドを作成する
	system.create();
	//ループを開始する
	system.update();

	return 0;
}
