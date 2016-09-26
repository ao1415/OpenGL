#pragma once

#include "Exception.hpp"

namespace opc {

	class System;

	class SystemState {
	public:

		inline static const bool getMakeWindow() { return makeWindow; }

		friend System;

	private:

		/// <summary>ウインドウが作成されたかのフラグ</summary>
		static bool makeWindow;

	};

}
