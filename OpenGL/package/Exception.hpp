#pragma once

#include <exception>

namespace opc {

	/// <summary>�ݒ��ύX�ł��Ȃ��ۂɔ��������O</summary>
	/// <seealso cref="std::exception" />
	struct SettingErrer : public std::exception {
		
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="message">���b�Z�[�W</param>
		SettingErrer(const char* message) : exception(message) {}

	};

}
