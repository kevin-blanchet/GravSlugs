#ifndef __SYSTEM_H__
#define __SYSTEM_H__

namespace grav {

struct Scene;

struct System {
	System(Scene& scene) : _owner(scene) {};
	virtual ~System() {};

	virtual void update() = 0;

	Scene& _owner;
};

}

#endif //!__SYSTEM_H__