#include "Window.hpp"

namespace opc {

	IntSize Window::size;
	std::string Window::title;
	Color Window::clearColor;
	Vec2 Window::ortho2DPoint[2];
	Vec3 Window::ortho3DPoint[2];

	void Window::setSize(const int width, const int height) {
		setSize(IntSize(width, height));
	}
	void Window::setSize(const IntSize& _size) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("大きさを変更できませんでした");
		size = _size;
	}

	void Window::setTitle(const std::string& name) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("タイトルを変更できませんでした");
		title = name;
	}

	void Window::setClearColor(const int r, const int g, const int b) {
		setClearColor(Color(r, g, b));
	}
	void Window::setClearColor(const int r, const int g, const int b, const int a) {
		setClearColor(Color(r, g, b, a));
	}
	void Window::setClearColor(const Color& _color) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("画面のクリアカラーを変更できませんでした");
		clearColor = _color;
	}

	void Window::setOrtho2D(const double left, const double right, const double bottom, const double top) {
		setOrtho2D(Vec2(left, top), Vec2(right, bottom));
	}
	void Window::setOrtho2D(const Vec2& left_top, const Vec2& right_bottom) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("画面の座標値を変更できませんでした");

		SystemState::setStandardPoint(SystemState::StandardPoint::Mode_2D);
		ortho2DPoint[0] = left_top; ortho2DPoint[1] = right_bottom;
	}

	void Window::setOrtho3D(const double left, const double right, const double bottom, const double top, const double zNear, const double zFar) {
		setOrtho3D(Vec3(left, top, zNear), Vec3(right, bottom, zFar));
	}
	void Window::setOrtho3D(const Vec3& left_top_near, const Vec3& right_bottom_far) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("画面の座標値を変更できませんでした");

		SystemState::setStandardPoint(SystemState::StandardPoint::Mode_3D);
		ortho3DPoint[0] = left_top_near; ortho3DPoint[1] = right_bottom_far;
	}

}
