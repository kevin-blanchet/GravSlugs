#ifndef __CLOCK_H__
#define __CLOCK_H__

#include "GravEngineConfig.h"

namespace grav {

class Clock
{

public:
	Clock() {};
	virtual ~Clock() {};

	/* Get the time in seconds since last reset or creation of the clock if never reset */
	virtual float getDelta() = 0;
	/* Get the time in micro-seconds since last reset or creation of the clock if never reset */
	virtual Int64 uGetDelta() = 0;

	/* Reset the clock. Returns the time in seconds since last reset or creation of the clock if never reset */
	virtual float resetDelta() = 0;
	/* Reset the clock. Returns the time in micros-seconds since last reset or creation of the clock if never reset */
	virtual Int64 uResetDelta() = 0;

};

}

#endif //!__CLOCK_H__