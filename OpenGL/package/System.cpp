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

		Display display(displayFunction);
		Display::clearMode = clearMode;
		glutDisplayFunc(Display::display);


		AcyncTimer acyncTimer(timerFunction);
		glutTimerFunc(AcyncTimer::time, AcyncTimer::timer, AcyncTimer::value);


		Mouse::setMouse(mouseFunction);
		glutMouseFunc(Mouse::mouse);

		Mouse::setMotion(motionFunction);
		glutMotionFunc(Mouse::motion);

		//glutMouseFunc(Mouse::mouse);
		//glutMotionFunc(Mouse::motion);

		if (SystemState::getStandardPoint(SystemState::StandardPoint::Mode_2D))
		{
			gluOrtho2D(GLdouble(Window::ortho2DPoint[0].x), GLdouble(Window::ortho2DPoint[1].x), GLdouble(Window::ortho2DPoint[1].y), GLdouble(Window::ortho2DPoint[0].y));
		}
		else if (false && SystemState::getStandardPoint(SystemState::StandardPoint::Mode_3D))
		{
			glFrustum(GLdouble(Window::ortho3DPoint[0].x), GLdouble(Window::ortho3DPoint[1].x),
				GLdouble(Window::ortho3DPoint[1].y), GLdouble(Window::ortho3DPoint[0].y),
				GLdouble(Window::ortho3DPoint[0].z), GLdouble(Window::ortho3DPoint[1].z));
		}

		for (const auto& mode : enableConfig) glEnable(mode);
		for (const auto& mode : disableConfig) glDisable(mode);

	}

	void System::update() {

		//メインループ
		glutMainLoop();

	}

	void System::setDisplayMode(const unsigned int mode) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("ディスプレイモードを変更できませんでした");
		displayMode = mode;
	}

	void System::setClearMode(const unsigned int mode) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("クリアモードを変更できませんでした");
		clearMode = mode;
	}

	void System::enable(const unsigned int mode) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("設定を有効にできませんでした");
		enableConfig.push_back(mode);
	}
	void System::disable(const unsigned int mode) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("設定を無効にできませんでした");
		disableConfig.push_back(mode);
	}

	void System::setDisplayFunc(std::function<void()> func) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("表示関数を変更できませんでした");
		displayFunction = func;
	}

	void System::setTimerFunc(unsigned int time, std::function<void(int)> func, int value) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("タイマー関数を変更できませんでした");
		timerFunction = func; AcyncTimer::time = time; AcyncTimer::value = value;
	}

	void System::setMouseFunc(std::function<void(int, int, int, int)> func) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("マウスクリック関数を変更できませんでした");
		mouseFunction = func;
	}

	void System::setMouseMotionFunc(std::function<void()> func) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("マウス動作関数を変更できませんでした");
		motionFunction = func;
	}

}

