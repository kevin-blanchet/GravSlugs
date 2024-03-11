#ifndef __SCENE_H__
#define __SCENE_H__

#include "snpch.h"
namespace grav{

class System;
class Entity;

struct Scene {
	Scene();

	void load();
	bool update();

	template<typename EntityType>
	void addEntity();

	template<typename systemType>
	systemType registerSystem();

	template<typename systemType>
	systemType getSystem();

protected:
	std::map<char*, System> _systems;
	std::vector<Entity> _entities;
};


template<typename EntityType>
inline void Scene::addEntity()
{
	_entities.push_back(EntityType());
}

template<typename systemType>
inline systemType Scene::registerSystem()
{
	systemType system = _systems.find(systemType::SystemName);
	if (system == _systems.end()) {
		_systems[systemType::SystemName] = systemType();
		system = _systems[systemType::SystemName];
	}
	return system;
}

template<typename systemType>
inline systemType Scene::getSystem()
{
	systemType system = _systems.find(systemType::SystemName);
	if (system == _systems.end()) {
		throw std::invalid_argument("System does not exist in this scene");
	}

	return system;
}

}

#endif // !__SCENE_H__