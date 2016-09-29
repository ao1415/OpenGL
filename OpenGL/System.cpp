#include "System.hpp"


namespace opc {

	System::System() : System(0, nullptr) {

	}
	System::System(int argc, char *argv[]) {
		glutInit(&argc, argv);
		init();
	}

	void System::create() {

		SystemState::makeWindow = true;

		glutInitDisplayMode(displayMode);

		glutInitWindowSize((int)Window::size.width, (int)Window::size.height);

		//ここでウインドウを作成している
		glutCreateWindow(Window::title.c_str());

		glClearColor(GLclampf(Window::clearColor.r / 255.0), GLclampf(Window::clearColor.g / 255.0), GLclampf(Window::clearColor.b / 255.0), GLclampf(Window::clearColor.a / 255.0));

		if (displayFunction)
		{
			using DisplayFuncPointer = void(*)();
			DisplayFuncPointer* dp = displayFunction.target<DisplayFuncPointer>();
			if (dp != nullptr)
			{
				Display display(displayFunction);

				glutDisplayFunc(Display::display);;
			}
		}

		if (timerFunction)
		{
			using TimerFuncPointer = void(*)(int);
			TimerFuncPointer* tp = timerFunction.target<TimerFuncPointer>();
			if (tp != nullptr)
			{
				AcyncTimer acyncTimer(timerFunction);

				glutTimerFunc(AcyncTimer::time, AcyncTimer::timer, AcyncTimer::value);
			}
		}

		if (SystemState::getStandardPoint(SystemState::StandardPoint::Mode_2D))
		{
			//一度決めたら変更できない模様
			gluOrtho2D(GLdouble(Window::ortho2DPoint[0].x), GLdouble(Window::ortho2DPoint[1].x), GLdouble(Window::ortho2DPoint[1].y), GLdouble(Window::ortho2DPoint[0].y));
		}
		else if (SystemState::getStandardPoint(SystemState::StandardPoint::Mode_3D))
		{
			glFrustum(GLdouble(Window::ortho3DPoint[0].x), GLdouble(Window::ortho3DPoint[1].x),
				GLdouble(Window::ortho3DPoint[1].y), GLdouble(Window::ortho3DPoint[0].y),
				GLdouble(Window::ortho3DPoint[0].z), GLdouble(Window::ortho3DPoint[1].z));
		}

		glutMainLoop();//メインループ

	}

	void System::setDisplayMode(const unsigned int mode) {
		displayMode = mode;
	}

	void System::setDisplayFunc(std::function<void()> func) {
		displayFunction = func;
	}

	void System::setTimerFunc(unsigned int time, std::function<void(int)> func, int value) {
		timerFunction = func; AcyncTimer::time = time; AcyncTimer::value = value;
	}

}

