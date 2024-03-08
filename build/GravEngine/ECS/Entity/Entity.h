/**
* @file
* @todo: make MAX_ENTITY_COUNT configurable
*/
#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "snpch.h"

// Type alias
using Entity = std::uint32_t;

// Define a maximum number of entity for optimisation purposes
const Entity MAX_ENTITY_COUNT = 5000;

#endif // !__ENTITY_H__
