#pragma once

class Object;

struct Manifold
{
    Object* A;
    Object* B;

    float penetration;
    sf::Vector2f normal;
};