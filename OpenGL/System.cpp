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
		glutCreateWindow(Window::title.c_str());//ここでウインドウを作成している
		glClearColor(GLclampf(Window::clearColor.r / 255.0), GLclampf(Window::clearColor.g / 255.0), GLclampf(Window::clearColor.b / 255.0), GLclampf(Window::clearColor.a / 255.0));

		gluOrtho2D(GLdouble(ortho2DPoint[0].x), GLdouble(ortho2DPoint[1].x), GLdouble(ortho2DPoint[1].y), GLdouble(ortho2DPoint[0].y));//一度決めたら変更できない模様

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

		glutMainLoop();//メインループ

	}

	void System::setOrtho2D(const double left, const double right, const double bottom, const double top) {
		setOrtho2D(RealPoint(left, top), RealPoint(right, bottom));
	}
	void System::setOrtho2D(const RealPoint& left_top, const RealPoint& right_bottom) {
		ortho2DPoint[0] = left_top; ortho2DPoint[1] = right_bottom;
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

