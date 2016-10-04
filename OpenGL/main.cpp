#include "OpenGL.hpp"

double theta = 0;

void display(void)
{

	View::Perspective(30, 1, 1, 500);

	View::LookAt(RealVector(0, 0, 80), RealVector(0, 0, 0), RealVector(0, 1, 0));

	glRotated(theta, 0, 1, 0);
	theta += 1;
	const int size = 20;

	Draw3D::Rect(RealVector(-size / 2, -size / 2, size / 2), RealVector(size, size, 0)).draw(Palette::White);
	Draw3D::Rect(RealVector(-size / 2, -size / 2, -size / 2), RealVector(size, size, 0)).draw(Palette::White);
	Draw3D::Rect(RealVector(-size / 2, -size / 2, size / 2), RealVector(0, size, -size)).draw(Palette::Gray);
	Draw3D::Rect(RealVector(size / 2, -size / 2, size / 2), RealVector(0, size, -size)).draw(Palette::Gray);

	Draw3D::Pixel(RealVector(0, 10, size)).draw(8, Palette::Red);

}

void timer(int value) {

	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	System system;

	system.setDisplayMode(DisplayMode::RGBA, DisplayMode::Double);
	system.setClearMode(ClearMode::Color, ClearMode::Depth);

	system.enable(GL_DEPTH_TEST);

	system.setDisplayFunc(display);
	system.setTimerFunc(10, timer, 0);

	Window::setSize(640, 640);

	system.create();

	return 0;
}
