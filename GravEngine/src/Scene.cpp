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
	//If Entity Contains ObjectComponent add it to _objects

}

void Scene::HandleCollision()
{
	for (size_t i = 0; i < _objects.size(); ++i)
	{
		for (size_t j = 0; j < _objects.size(); ++i)
		{
			Manifold* collisionInfos;

			collisionInfos->A = &_objects[i];
			collisionInfos->B = &_objects[j];
			if (CheckCollisions(m))
			{
				ResolveCollision(m);
			}

			delete(collisionInfos);
			collisionInfos = nullptr;
		}
	}
}
