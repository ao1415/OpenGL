#include "OpenGL.hpp"

int x = -320;

void display(void)
{

	Pixel(IntPoint(0, 0)).draw(4, Palette::Blue);
	Pixel(IntPoint(160, 120)).draw(8, Palette::White);

	Line(IntPoint(-160, 120), IntPoint(160, -120)).draw(8, Palette::Red);

	Triangle(IntPoint(0, 0), IntPoint(0, 80), IntPoint(80, 80)).draw(Palette::Green);
	Quad(IntPoint(0, 0), IntPoint(0, -80), IntPoint(-80, -80), IntPoint(-80, 0)).draw(Palette::Yellow);

	Rect(IntPoint(-40, -40), Size(80, 60)).draw(Palette::Gray);
	Rect(IntPoint(-40, -20), Size(80, 60)).draw(Color(Palette::White, 127));

}

void timer(int value) {

	x += 2;

	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	System system;

	system.setOrtho2D(RealPoint(0, 0), RealPoint(640, 480));
	system.setOrtho2D(RealPoint(-320, -240), RealPoint(320, 240));

	system.setDisplayFunc(display);
	system.setTimerFunc(16, timer, 0);

	system.create();

	return 0;
}
