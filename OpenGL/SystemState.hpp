#pragma once

#include "Exception.hpp"

namespace opc {

	class System;

	class SystemState {
	public:

		enum class StandardPoint : unsigned char {
			Mode_2D = 0x01,
			Mode_3D = 0x02,
		};

		inline static const bool getMakeWindow() { return makeWindow; }

		inline static const unsigned char getStandardPoint() { return standardPoint; }
		inline static const bool getStandardPoint(const StandardPoint& d) {
			return (standardPoint & (char)d) > 0;
		}

		friend System;

	private:

		/// <summary>�E�C���h�E���쐬���ꂽ���̃t���O</summary>
		static bool makeWindow;

		/// <summary>���W�̐ݒ�̃t���O</summary>
		static unsigned char standardPoint;
		
	};

}
