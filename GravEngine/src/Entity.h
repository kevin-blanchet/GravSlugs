/**
* @file
* @todo: make MAX_ENTITY_COUNT configurable
*/
#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "snpch.h"

namespace grav {

struct Component;
struct Scene;

struct Entity {
	Entity(Scene& scene) : _owner(scene) {};
	virtual ~Entity() {};

	std::string EntityType;

	std::vector<Component> _components;

	Scene& _owner;
};

}

#endif // !__ENTITY_H__
