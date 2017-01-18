#pragma once

#include <exception>

namespace opc {

	/// <summary>設定を変更できない際に発生する例外</summary>
	/// <seealso cref="std::exception" />
	struct SettingErrer : public std::exception {
		
		/// <summary>コンストラクタ</summary>
		/// <param name="message">メッセージ</param>
		SettingErrer(const char* message) : exception(message) {}

	};

}
