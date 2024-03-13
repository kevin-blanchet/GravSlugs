#include "Clock.h"
#include "Clock_SFML.h"

#include <SFML/System/Clock.hpp>

using namespace grav;

float Clock_SFML::getDelta()
{
	return p_clock.get()->getElapsedTime().asSeconds();
}

Int64 Clock_SFML::uGetDelta()
{
	return p_clock.get()->getElapsedTime().asMicroseconds();
}

float Clock_SFML::resetDelta()
{
	return p_clock.get()->restart().asSeconds();
}

Int64 Clock_SFML::uResetDelta()
{
	return p_clock.get()->restart().asMicroseconds();
}