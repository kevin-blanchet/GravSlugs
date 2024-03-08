#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "snpch.h"

namespace grav {

class Entity;

struct Component {
	std::shared_ptr<Entity> owner;
};

}

#endif // !__COMPONENT_H__
