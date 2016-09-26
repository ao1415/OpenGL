#include "Window.hpp"

namespace opc {

	Size Window::size;
	std::string Window::title;
	Color Window::clearColor;
	RealPoint Window::ortho2DPoint[2];

	void Window::setSize(const int width, const int height) {
		size = Size(width, height);
	}
	void Window::setSize(const Size& _size) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("�傫����ύX�ł��܂���ł���");
		size = _size;
	}

	void Window::setTitle(const std::string& name) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("�^�C�g����ύX�ł��܂���ł���");
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
			throw SettingErrer("��ʂ̃N���A�J���[��ύX�ł��܂���ł���");
		clearColor = _color;
	}

	void Window::setOrtho2D(const double left, const double right, const double bottom, const double top) {
		setOrtho2D(RealPoint(left, top), RealPoint(right, bottom));
	}
	void Window::setOrtho2D(const RealPoint& left_top, const RealPoint& right_bottom) {
		if (SystemState::getMakeWindow())
			throw SettingErrer("��ʂ̍��W�l��ύX�ł��܂���ł���");
		ortho2DPoint[0] = left_top; ortho2DPoint[1] = right_bottom;
	}

}
