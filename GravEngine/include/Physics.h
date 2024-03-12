#pragma once

#include <iostream>
#include <cmath>

#include "Manifold.h"
#include "Object.h"

void ResolveCollision(Manifold* m);

bool Circle_Collision(Manifold* m);
bool Rectangle_Collision(Manifold m*);
bool RectangleCircle_Collision(Manifold m*);
