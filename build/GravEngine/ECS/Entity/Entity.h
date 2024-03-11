/**
* @file
* @todo: make MAX_ENTITY_COUNT configurable
*/
#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "../../ComponentTypesList.h"

#include "snpch.h"

namespace grav {

class Component;

template <typename... ComponentTypes>
struct Entity {
	using EntityComponentsTypes = ComponentTypeList<ComponentTypes...>;

	Entity(ComponentTypeList<ComponentTypes...>) {}
	virtual ~Entity() {};

	std::vector<Component*> _components;
};

}

#endif // !__ENTITY_H__
