#include "OpenGL.hpp"

int x = -320;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(255, 255, 255);
	glPointSize(1);
	glBegin(GL_POINTS);

	for (int i = -240; i < 240; i++)
		glVertex2i(x, i);

	glEnd();

	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2i(0, 0);
	glVertex2f(0.5, 0.5);
	glEnd();

	glutSwapBuffers();
	glFlush();
}

void timer(int value) {

	x += 2;

	glutPostRedisplay();
	//glutTimerFunc(16, timer, 0);
}

int main(int argc, char *argv[])
{
	System system;

	system.setOrtho2D(DPoint(0, 0), DPoint(640, 480));
	system.setOrtho2D(DPoint(-320, -240), DPoint(320, 240));

	system.setDisplayFunc(display);
	system.setTimerFunc(16, timer, 0);

	system.create();

	return 0;
}
