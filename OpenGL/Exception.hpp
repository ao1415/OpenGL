#pragma once

#include <exception>

namespace opc {

	/// <summary>İ’è‚ğ•ÏX‚Å‚«‚È‚¢Û‚É”­¶‚·‚é—áŠO</summary>
	/// <seealso cref="std::exception" />
	struct SettingErrer : public std::exception {
		
		SettingErrer(const char* message) : exception(message) {}

	};

}
