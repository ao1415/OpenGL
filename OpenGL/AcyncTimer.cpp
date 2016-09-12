#include "AcyncTimer.hpp"

namespace opc {

	AcyncTimer::AcyncTimer() {}
	AcyncTimer::AcyncTimer(std::function<void(int)> _func) {
		func = _func;
	}

	void AcyncTimer::timer(int v) {

		func(value);

		glutTimerFunc(time, AcyncTimer::timer, value);
	}


}
