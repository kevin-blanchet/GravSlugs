#pragma once
#include "Vector2.h"

class Object;

//Collision Infos holder 
struct Manifold
{
    Object *A;
    Object *B;

    float penetration;
    Vector2 normal;
};