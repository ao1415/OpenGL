#include "OpenGL.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

//表示用のクラス
class DrawImage {
public:

	//ピクセル群を表示軍
	void display()
	{
		View::Perspective(30, 1, 1, 15000);

		View::LookAt(Vec3(0, 0, 1000), Vec3(0, 0, 0), Vec3(0, -1, 0));

		View::Translate(Vec3(camera.x, camera.y, distance));
		View::Rotate(angle.x, Vec3(-1, 0, 0));
		View::Rotate(angle.y, Vec3(0, -1, 0));

		for (int y = 0; y < textureSize.height; y++)
		{
			for (int x = 0; x < textureSize.width; x++)
			{
				const int D = 32;
				const int depth = bitmap[y][x].first;
				const Color color = bitmap[y][x].second;
				const Vec3 pos(-textureSize.width / 2.0 + x, -textureSize.height / 2.0 + y, depth * D);

				if (0 <= x - 1 && bitmap[y][x - 1].first < depth)
				{
					int d = -(depth - bitmap[y][x - 1].first) * D;
					Draw3D::Quad(pos + Vec3(0, 0, 0), pos + Vec3(0, 1, 0), pos + Vec3(0, 1, d), pos + Vec3(0, 0, d)).draw(color);
				}
				if (0 <= y - 1 && bitmap[y - 1][x].first < depth)
				{
					int d = -(depth - bitmap[y - 1][x].first) * D;
					Draw3D::Quad(pos + Vec3(0, 0, 0), pos + Vec3(1, 0, 0), pos + Vec3(1, 0, d), pos + Vec3(0, 0, d)).draw(color);
				}
				if (x + 1 < textureSize.width && bitmap[y][x + 1].first < depth)
				{
					int d = -(depth - bitmap[y][x + 1].first) * D;
					Draw3D::Quad(pos + Vec3(1, 0, 0), pos + Vec3(1, 1, 0), pos + Vec3(1, 1, d), pos + Vec3(1, 0, d)).draw(color);
				}
				if (y + 1 < textureSize.height && bitmap[y + 1][x].first < depth)
				{
					int d = -(depth - bitmap[y + 1][x].first) * D;
					Draw3D::Quad(pos + Vec3(0, 1, 0), pos + Vec3(1, 1, 0), pos + Vec3(1, 1, d), pos + Vec3(0, 1, d)).draw(color);
				}

				Vec3 size(1, 1, 0);
				Draw3D::Rect(pos, size).draw(color);
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
		if (mouse.mouseM_Click)
		{
			distance -= ydir / 1.0;
		}
		if (mouse.mouseR_Click)
		{
			camera.x -= xdir / 1.0;
			camera.y += ydir / 1.0;
		}
	}

	//画像ファイルを読み込む
	void load() {

		int w, h;

		ifstream ifs("読み取り画像002.txt");
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

	//視点角度
	Vec2 angle;
	//カメラ位置
	Vec2 camera;
	//距離
	double distance = 0;

	//テクスチャの大きさ
	IntSize textureSize;
	//ピクセルと奥行データ
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
