#ifndef __SCENE_H__
#define __SCENE_H__

#include "snpch.h"

namespace grav{

struct System;
struct Entity;

struct Scene {
	Scene();

	void load();
	bool update();
	void addEntity();

	template<typename systemType>
	systemType& registerSystem();

	template<typename systemType>
	systemType& getSystem();

	template<typename entityType>
	entityType& registerEntity();

protected:
	std::map<char*, System*> _systems;
	std::vector<Entity*> _entities;
};


template<typename systemType>
inline systemType& Scene::registerSystem()
{
	systemType* system = _systems.find(systemType::SystemName);
	if (system == _systems.end()) {
		system = new systemType(*this);
		_systems[systemType::SystemName] = system;
	}
	return *system;
}

template<typename systemType>
inline systemType& Scene::getSystem()
{
	systemType* system = _systems.find(systemType::SystemName);
	if (system == _systems.end()) {
		// throw Error("System does not exist in this scene");
	}

	return *system;
}

template<typename entityType>
inline entityType& Scene::registerEntity()
{
	entityType* entity = new entityType(*this);
	_entities.push_back(entity);
	return *entity;
}

}

#endif // !__SCENE_H__