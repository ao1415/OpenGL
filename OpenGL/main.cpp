#include "OpenGL.hpp"

const double vertex[] = {
	-1.4 , 1.9 , -3 , 0 , 0.1 , -3 , 1.5 , 1.9 , -3 ,
	0.1 , 1.9 , -2 , 1.5 , 0.1 , -2 , 3 , 1.9 , -2
};
//-1.4, 1.9, -3, 0, 0.1, -3, 1.5, 1.9, -3,

void display(void)
{

	Draw3D::Rect(RealVector(-1, 1, -5), RealVector(2, 2, 0)).draw();
	Draw3D::Rect(RealVector(-1, 1, -3), RealVector(0, 2, -2)).draw(Palette::Gray);
	Draw3D::Rect(RealVector(1, 1, -3), RealVector(0, 2, -2)).draw(Palette::Gray);
	Draw3D::Rect(RealVector(-1, 1, -3), RealVector(2, 2, 0)).draw();

}

void timer(int value) {

	glRotatef(1, 0, 1, 0);

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

	//system.setDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);

	system.setDisplayMode(DisplayMode::RGBA, DisplayMode::Double, DisplayMode::Alpha, DisplayMode::Depth);

	system.setDisplayFunc(display);
	system.setTimerFunc(10, timer, 0);

	Window::setOrtho3D(RealVector(-4, -2, 1), RealVector(4, 2, 6));

	glMatrixMode(GL_PROJECTION);
	//glMatrixMode(GL_MODELVIEW);
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
