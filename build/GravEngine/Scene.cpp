#include "Scene.h"
#include "System.h"

namespace grav {
Scene::Scene()
{
}

void Scene::load()
{
	while (update());
}

//todo: add exit condition
bool Scene::update()
{
	for (auto& system : _systems)
	{
		system.second->update();
	}
	return false;
}

void Scene::addEntity()
{
}
}
