#include "Window.hpp"

namespace opc {

	Size Window::size;
	std::string Window::title;
	Color Window::clearColor;

	void Window::setSize(const int width, const int height) {
		size = Size(width, height);
	}
	void Window::setSize(const Size& _size) {
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

}
