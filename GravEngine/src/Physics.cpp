#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Physics.h"

void ResolveCollision(Manifold* m) {

    //Impulse
    Object* A = m->A;
    Object* B = m->B;

    //Velovité relative 
    Vector2i relVelo = B->velocity - A->velocity;
    //Vélocité par rapport à la normale
    float velNormal = dotProduct(relVelo, m->normal);

    if (velNormal > 0) {
        return;
    }

    //calcul de la restitution
    float e = fminf(A->restitution, B->restitution);
    float j = (-(1 + e) * velNormal) / (A->inv_mass + B->inv_mass);

    Vector2i impulse = j * m->normal;
    A->velocity -= A->inv_mass * impulse;
    B->velocity += B->inv_mass * impulse;
}

bool Circle_Collision(Manifold* m) {
    Object* c1 = m->A;
    Object* c2 = m->B;

    Circle* c1Shape = &(c1->circleObject);
    Circle* c2Shape = &(c2->circleObject);

    float radiusLength = c1Shape->radius + c2Shape->radius;
    float squareRadius = powf(radiusLength, 2);

    if (squareRadius < powf((c1Shape->center.x - c2Shape->center.x), 2) + powf((c1Shape->center.y - c2Shape->center.y), 2)) {
        return(false);
    }

    sf::Vector2f n = c2Shape->center - c1Shape->center;
    float d = sqrtf(powf(n.x, 2) + powf(n.y, 2));

    if (d != 0) {
        m->penetration = radiusLength - d;
        m->normal = n / d;

        return(true);
    }

    else {
        m->penetration = radiusLength;
        m->normal = sf::Vector2f(1.0f, 0.f);

        return(true);
    }
}

bool Rectangle_Collision(Manifold* m) {
    Object* r1 = m->A;
    Object* r2 = m->B;

    AABB* r1Shape = &(r1->rectangleObject);
    AABB* r2Shape = &(r2->rectangleObject);

    float r1HalfX = (r1Shape->maxCoords.x - r1Shape->minCoords.x) / 2.f;
    float r2HalfX = (r2Shape->maxCoords.x - r2Shape->minCoords.x) / 2.f;

    sf::Vector2f relPos = r2->pos - r1->pos;

    float xOverleap = r1HalfX + r2HalfX - abs(relPos.x + r2HalfX - r1HalfX);

    if (xOverleap > 0) {
        float r1HalfY = (r1Shape->maxCoords.y - r1Shape->minCoords.y) / 2.f;
        float r2HalfY = (r2Shape->maxCoords.y - r2Shape->minCoords.y) / 2.f;

        float yOverleap = r1HalfY + r2HalfY - abs(relPos.y + r2HalfY - r1HalfY);

        if (yOverleap > 0) {
            if (xOverleap < yOverleap) {
                m->penetration = xOverleap;

                if (relPos.x > 0) {
                    m->normal = sf::Vector2f(1.f, 0.f);
                }

                else {
                    m->normal = sf::Vector2f(-1.f, 0.f);
                }

                return(true);
            }

            else {
                m->penetration = yOverleap;

                if (relPos.y > 0) {
                    m->normal = sf::Vector2f(0.f, 1.f);
                }

                else {
                    m->normal = sf::Vector2f(0.f, -1.f);
                }

                return(true);
            }
        }
    }

    return(false);
}

bool RectangleCircle_Collision(Manifold* m) {
    Object* r = m->A;
    Object* c = m->B;

    AABB* rShape = &(r->rectangleObject);
    circle* cShape = &(c->circleObject);

    float rad = cShape->radius;

    float xHalf = (rShape->maxCoords.x - rShape->minCoords.x) / 2.f;
    float yHalf = (rShape->maxCoords.y - rShape->minCoords.y) / 2.f;

    sf::Vector2f relPos = (c->pos + sf::Vector2f(rad, rad)) - (r->pos + sf::Vector2f(xHalf, yHalf));
    sf::Vector2f closest = relPos;

    closest.x = clamp(-xHalf, xHalf, closest.x);
    closest.y = clamp(-yHalf, yHalf, closest.y);

    bool isInside = false;

    if (closest == relPos) {
        isInside = true;

        if (abs(closest.x) > abs(closest.y)) {
            closest.x = copysignf(xHalf, closest.x);
        }

        else {
            closest.y = copysignf(yHalf, closest.y);
        }
    }

    sf::Vector2f n = relPos - closest;
    float d = powf(n.x, 2.f) + powf(n.y, 2.f);

    if (d > rad * rad && !isInside) {
        return(false);
    }

    d = sqrtf(d);

    if (isInside) {
        m->normal = -n / d;
    }

    else {
        m->normal = n / d;
    }

    m->penetration = rad - d;

    return(true);
}

