#pragma once

#include <exception>

namespace opc {

	/// <summary>�ݒ��ύX�ł��Ȃ��ۂɔ��������O</summary>
	/// <seealso cref="std::exception" />
	struct SettingErrer : public std::exception {
		
		SettingErrer(const char* message) : exception(message) {}

	};

}
