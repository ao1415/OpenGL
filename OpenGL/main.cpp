#include "OpenGL.hpp"

const double vertex[] = {
	3.1 , 1.9 , -3 , 4.5 , 0.1 , -3 , 6 , 1.9 , -3 ,
	0.1 , 1.9 , -2 , 1.5 , 0.1 , -2 , 3 , 1.9 , -2
};

void display(void)
{
	//glClear(GL_COLOR_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_DOUBLE, 0, vertex);

	glBegin(GL_TRIANGLES); {
		int i;
		glColor3f(0, 0, 1);
		for (i = 0; i < 3; i++) glArrayElement(i);
		glColor3f(1, 0, 0);
		for (i = 3; i < 6; i++) glArrayElement(i);
	} glEnd();

	//glFlush();
}

void timer(int value) {

	//glRotatef(1, 0, 1, 0);

	glutPostRedisplay();
}

void disp(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_DOUBLE, 0, vertex);

	glBegin(GL_TRIANGLES); {
		int i;
		glColor3f(0, 0, 1);
		for (i = 0; i < 3; i++) glArrayElement(i);
		glColor3f(1, 0, 0);
		for (i = 3; i < 6; i++) glArrayElement(i);
	} glEnd();

	glFlush();
}

int main(int argc, char *argv[])
{
	//*
	System system;

	//Window::setOrtho2D(RealPoint(0, 0), RealPoint(640, 480));
	//Window::setOrtho2D(RealPoint(-10, -10), RealPoint(10, 10));
	system.setDisplayFunc(display);
	//system.setTimerFunc(10, timer, 0);

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glFrustum(0, 4, 2, 0, 2, 10);

	Window::setOrtho3D(RealVector(0, 0, 2), RealVector(4, 2, 10));

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	system.create();

	/*/
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 50);
	glutInitWindowSize(400, 300);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutCreateWindow("Kitty on your lap");
	glutDisplayFunc(disp);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(0, 4, 2, 0, 2, 10);

	glutMainLoop();
	//*/

	return 0;
}
