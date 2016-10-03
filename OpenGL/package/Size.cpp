#include "Size.hpp"

namespace opc {

	IntSize::IntSize() {

	}
	IntSize::IntSize(const int w, const int h) : width(w), height(h) {

	}

	RealSize::RealSize() {

	}
	RealSize::RealSize(const int w, const int h) : width(w), height(h) {

	}
	RealSize::RealSize(const double w, const double h) : width(w), height(h) {

	}

}
