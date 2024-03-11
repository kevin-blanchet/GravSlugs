#ifndef __SYSTEM_H__
#define __SYSTEM_H__

namespace grav {

struct System {

	virtual ~System() {};

	virtual void update();

};

}

#endif //!__SYSTEM_H__