#ifndef __SCENE_H__
#define __SCENE_H__

#include "snpch.h"
namespace grav{

class System;

struct Scene {
	Scene();

	void load();
	bool update();
	void addEntity();

	template<typename systemType>
	systemType registerSystem();

	template<typename systemType>
	systemType getSystem();

protected:
	std::map<char*, System> _systems;

};


template<typename systemType>
inline systemType Scene::registerSystem()
{
	systemType system = _systems.find(systemType::SystemName);
	if (system == _systems.end()) {
		_systems[systemType::SystemName] = systemName();
		system = _systems[systemType::SystemName];
	}
	return system;
}

template<typename systemType>
inline systemType Scene::getSystem()
{
	systemType system = _systems.find(systemType::SystemName);
	if (system == _systems.end()) {
		throw Error("System does not exist in this scene");
	}

	return system;
}

}

#endif // !__SCENE_H__