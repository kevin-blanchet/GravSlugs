#ifndef __CLOCK_SFML_H__
#define __CLOCK_SFML_H__

#include "Clock.h"

#include "snpch.h"

namespace sf {
	class Clock;
}

namespace grav {

class Clock_SFML: public Clock
{
public:
	Clock_SFML() : Clock(), p_clock(std::make_unique<sf::Clock>()) {};

	float getDelta();
	Int64 uGetDelta();

	float resetDelta();
	Int64 uResetDelta();
private:
	std::unique_ptr<sf::Clock> p_clock;
};

}
#endif //!__CLOCK_SFML_H__