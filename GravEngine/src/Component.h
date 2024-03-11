#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "snpch.h"

namespace grav {

struct Entity;

struct Component {
	Component(Entity& entity) : _owner(entity) {};
	~Component() {};

	Entity& _owner;
};

}

#endif // !__COMPONENT_H__
