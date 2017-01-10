#include "AcyncTimer.hpp"

namespace opc {

	std::function<void(int)> AcyncTimer::func;
	unsigned int AcyncTimer::time;
	int AcyncTimer::value;

	AcyncTimer::AcyncTimer() {}
	AcyncTimer::AcyncTimer(std::function<void(int)> _func) {
		func = _func;
	}

	void AcyncTimer::timer(int v) {

		if (func)
			func(value);

		glutTimerFunc(time, AcyncTimer::timer, value);
	}

}
