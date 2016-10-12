#include "OpenGL.hpp"

double theta = 0;

Bitmap bmp;

void display(void)
{
	View::Perspective(30, 1, 1, 500);

	View::LookAt(RealVector(0, 0, 80), RealVector(0, 0, 0), RealVector(0, -1, 0));

	//glRotated(theta, 0, 1, 0);
	theta += 1;
	const int size = 20;

	//Draw3D::Rect(RealVector(-size / 2, -size / 2, size / 2), RealVector(size, size, 0)).draw(Palette::White);
	//Draw3D::Rect(RealVector(-size / 2, -size / 2, -size / 2), RealVector(size, size, 0)).draw(Palette::White);
	//Draw3D::Rect(RealVector(-size / 2, -size / 2, size / 2), RealVector(0, size, -size)).draw(Palette::Gray);
	//Draw3D::Rect(RealVector(size / 2, -size / 2, size / 2), RealVector(0, size, -size)).draw(Palette::Gray);

	//Draw3D::Pixel(RealVector(0, 10, size)).draw(8, Palette::Red);

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

	system.update();

	return 0;
}
