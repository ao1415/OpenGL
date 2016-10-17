#include "OpenGL.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

//*

Bitmap bmp;

int mButton;
IntPoint mousePos;
bool mouseClick;
RealPoint angle;
RealPoint camera;

IntSize textureSize;
Grid<pair<int, Color>> bitmap;

void display(void)
{
	View::Perspective(30, 1, 1, 15000);

	View::LookAt(RealVector(0, 0, 1000), RealVector(0, 0, 0), RealVector(0, -1, 0));

	glTranslated(camera.x, camera.y, 0);
	glRotated(angle.x, -1, 0, 0);
	glRotated(angle.y, 0, -1, 0);

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

void timer(int value) {

	glutPostRedisplay();
}

void mouseFunc(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		mButton = button;
		mousePos.x = x;
		mousePos.y = y;
		mouseClick = true;
	}
	else
	{
		mouseClick = false;
	}

}

void mouseMotion(int x, int y)
{
	if (mouseClick == false) return;

	int xdir, ydir;

	xdir = x - mousePos.x;
	ydir = y - mousePos.y;

	switch (mButton)
	{
	case GLUT_LEFT_BUTTON:
		angle.x += (double)ydir * 0.5;
		angle.y += (double)xdir * 0.5;
		break;
	case GLUT_RIGHT_BUTTON:
		camera.x -= xdir / 40.0;
		camera.y += ydir / 40.0;
		break;
	}

	mousePos.x = x;
	mousePos.y = y;

	//glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	//*
	System system;

	system.setDisplayMode(DisplayMode::RGBA, DisplayMode::Double);
	system.setClearMode(ClearMode::Color, ClearMode::Depth);

	system.enable(GL_DEPTH_TEST);

	system.setDisplayFunc(display);
	system.setTimerFunc(10, timer, 0);

	Window::setSize(960, 960);


	int w, h;

	map<int, Grid<Color>> images;

	ifstream ifs("test.txt");
	if (!ifs)
	{
		cerr << "ファイルが開けません" << endl;
		return 0;
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


	system.create();

	//bmp = Bitmap("sample.bmp");

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	//makeTexture("sample.txt");

	glutMouseFunc(mouseFunc);
	glutMotionFunc(mouseMotion);

	system.update();

	return 0;
}
/*/

//*/
