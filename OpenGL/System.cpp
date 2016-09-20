#include "System.hpp"


namespace opc {

	System::System() : System(0, nullptr) {

	}
	System::System(int argc, char *argv[]) {
		glutInit(&argc, argv);
		init();
	}

	void System::create() {
		glutInitDisplayMode(displayMode);

		glutInitWindowSize((int)size.width, (int)size.height);
		glutCreateWindow(title.c_str());//ここでウインドウを作成している
		glClearColor(GLclampf(clearColor.r / 255.0), GLclampf(clearColor.g / 255.0), GLclampf(clearColor.b / 255.0), GLclampf(clearColor.a / 255.0));

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

	void System::setSize(const int width, const int height) {
		size = Size(width, height);
	}
	void System::setSize(const Size& _size) {
		size = _size;
	}

	void System::setTitle(const std::string& name) {
		title = name;
	}

	void System::setClearColor(const byte r, const byte g, const byte b) {
		setClearColor(Color(r, g, b));
	}
	void System::setClearColor(const byte r, const byte g, const byte b, const byte a) {
		setClearColor(Color(r, g, b, a));
	}
	void System::setClearColor(const Color& _color) {
		clearColor = _color;
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

