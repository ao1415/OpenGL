#include "OpenGL.hpp"

//*

Bitmap bmp;

IntPoint mousePos;
bool mouseClick;
RealPoint angle;

void display(void)
{
	View::Perspective(30, 1, 1, 500);

	View::LookAt(RealVector(0, 0, 80), RealVector(0, 0, 0), RealVector(0, -1, 0));

	glRotated(angle.x, -1, 0, 0);
	glRotated(angle.y, 0, -1, 0);

	glEnable(GL_TEXTURE_2D);//テクスチャ有効
	glBindTexture(GL_TEXTURE_2D, bmp.Texture);
	glEnable(GL_ALPHA_TEST);//アルファテスト開始

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f); glVertex3d((double)(-(int)bmp.Width / 32), (double)((int)bmp.Height / 32), 0);//左下
	glTexCoord2f(0.0f, 1.0f); glVertex3d((double)(-(int)bmp.Width / 32), (double)(-(int)bmp.Height / 32), 0);//左上
	glTexCoord2f(1.0f, 1.0f); glVertex3d((double)((int)bmp.Width / 32), (double)(-(int)bmp.Height / 32), 0);//右上
	glTexCoord2f(1.0f, 0.0f); glVertex3d((double)((int)bmp.Width / 32), (double)((int)bmp.Height / 32), 0);//右下
	glEnd();

	glDisable(GL_ALPHA_TEST);//アルファテスト終了
	glDisable(GL_TEXTURE_2D);//テクスチャ無効

}

void timer(int value) {

	glutPostRedisplay();
}

void mouseFunc(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
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
	if (mouseClick== false) return;

	int xdir, ydir;

	xdir = x - mousePos.x;
	ydir = y - mousePos.y;

	angle.x += (double)ydir * 0.5;
	angle.y += (double)xdir * 0.5;

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

	Window::setSize(640, 640);

	system.create();

	bmp = Bitmap("sample.bmp");

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	glutMouseFunc(mouseFunc);
	glutMotionFunc(mouseMotion);

	system.update();

	return 0;
}
/*/

//*/
