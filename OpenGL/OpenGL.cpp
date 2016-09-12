#include "System.hpp"

namespace opc {

	std::function<void(int)> AcyncTimer::func;
	unsigned int AcyncTimer::time;
	int AcyncTimer::value;

}
