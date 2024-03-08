#ifndef __GRAV_ENGINE_CONFIG_H__
#define __GRAV_ENGINE_CONFIG_H__

namespace grav {

// 64 bits integer types
#if defined(_MSC_VER)
	typedef signed   __int64 Int64;
	typedef unsigned __int64 Uint64;
#else
	typedef signed   long long Int64;
	typedef unsigned long long Uint64;
#endif

}

#endif //!__GRAV_ENGINE_CONFIG_H__