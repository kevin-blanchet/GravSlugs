#include "Physics.h"

#include <iostream>
#include <cmath>
#include<algorithm>
#include <SFML/Graphics.hpp>


void ResolveCollision(Manifold* m) 
{

    //Impulse
    Object* A = m->A;
    Object* B = m->B;

    //Velovit� relative 
    Vector2 relVelo = B->velocity - A->velocity;
    //V�locit� par rapport � la normale
    float velNormal = dotProduct(relVelo, m->normal);

    if (velNormal > 0) {
        return;
    }

    //calcul de la restitution
    float e = fminf(A->restitution, B->restitution);
    float j = (-(1 + e) * velNormal) / (A->inv_mass + B->inv_mass);

    Vector2 impulse = j * m->normal;
    A->velocity -= A->inv_mass * impulse;
    B->velocity += B->inv_mass * impulse;
}

bool CheckCollisions(Manifold* m)
{
    Object* obj1 = m->A;
    Object* obj2 = m->B;

    if (obj1->shape && obj2->shape) 
    {
        // Check collision based on the types of shapes
        ShapeType shapeType1 = obj1->shape->GetType();
        ShapeType shapeType2 = obj2->shape->GetType();

        if (shapeType1 == CIRCLE && shapeType2 == CIRCLE) 
        {
            return Circle_Collision(m);
        }
        else if (shapeType1 == RECTANGLE && shapeType2 == RECTANGLE) 
        {
            return Rectangle_Collision(m);
        }
        else if (shapeType1 == CIRCLE && shapeType2 == RECTANGLE) 
        {
            // Reverse the order for circle-rectangle collision
            m->A = obj2;
            m->B = obj1;
            return RectangleCircle_Collision(m);
        }
        else if (shapeType1 == RECTANGLE && shapeType2 == CIRCLE) 
        {

            return RectangleCircle_Collision(m);
        }
    }

    if()
    return false;
}

bool Circle_Collision(Manifold* m) {

    //Get Infos from manifold
    Object* c1 = m->A;
    Object* c2 = m->B;

    Circle* c1Shape = &(c1->circleObject);
    Circle* c2Shape = &(c2->circleObject);

    float radiusLength = c1Shape->radius + c2Shape->radius;
    float squareRadius = powf(radiusLength, 2);

    //check if the 2 circles collides
    if (squareRadius < powf((c1Shape->center.x - c2Shape->center.x), 2) + powf((c1Shape->center.y - c2Shape->center.y), 2)) {
        return(false);
    }

    //Resolve the Collision
    Vector2 n = c2Shape->center - c1Shape->center;
    float d = sqrtf(powf(n.x, 2) + powf(n.y, 2));

    //Circles are not at the same position
    if (d != 0) {
        m->penetration = radiusLength - d;
        m->normal = n / d;

        return(true);
    }

    else {
        m->penetration = radiusLength;
        m->normal = Vector2(1.0f, 0.f);

        return(true);
    }
}

bool Rectangle_Collision(Manifold* m) 
{
    Object* r1 = m->A;
    Object* r2 = m->B;

    Rectangle* r1Shape = &(r1->rectangleObject);
    Rectangle* r2Shape = &(r2->rectangleObject);

    //Calcul of the x-axis overlap 
    float r1HalfX = (r1Shape->GetMax().x - r1Shape->GetMin().x) / 2.f;
    float r2HalfX = (r2Shape->GetMax().x - r2Shape->GetMin().x) / 2.f;

    Vector2 relPos = r2->pos - r1->pos;

    float xOverlap = r1HalfX + r2HalfX - abs(relPos.x + r2HalfX - r1HalfX);

    if (xOverlap > 0) 
    {
        //Calcul of the y-axis overlap
        float r1HalfY = (r1Shape->GetMax().y - r1Shape->GetMin().y) / 2.f;
        float r2HalfY = (r2Shape->GetMax().y - r2Shape->GetMin().y) / 2.f;

        float yOverlap = r1HalfY + r2HalfY - abs(relPos.y + r2HalfY - r1HalfY);

        if (yOverlap > 0) 
        {
            // Determine the minimum overlap and set penetration depth
            m->penetration = (xOverlap < yOverlap) ? xOverlap : yOverlap;

            if (xOverleap < yOverleap) 
            {
                if (relPos.x > 0)
                    m->normal = Vector2(1.f, 0.f);
                
                else 
                    m->normal = Vector2(-1.f, 0.f);
            }
            else {
                if (relPos.y > 0)
                    m->normal = Vector2(0.f, 1.f);
                
                else 
                    m->normal = Vector2(0.f, -1.f);
                
            }

            return(true);
            
        }
    }

    return(false);
}

bool RectangleCircle_Collision(Manifold* m) {

    Object* r = m->A;
    Object* c = m->B;

    Rectangle* rShape = dynamic_cast<Rectangle*>(r->shape);
    Circle* cShape = dynamic_cast<Circle*>(c->shape);

    if (cShape && rShape)
    {
        // Calculate circle center in the coordinate system of the rectangle
        Vector2i circleCenterInRectSpace = c->position - r->position;

        // Closest point on the rectangle to the circle
        Vector2i closestPoint = std::clamp(circleCenterInRectSpace, rShape->GetMin(), rShape->GetMax());

        // Calculate the vector from the circle center to the closest point
        Vector2i circleToClosest = circleCenterInRectSpace - closestPoint;

        float distanceSquared = static_cast<float>(circleToClosest.Dot(circleToClosest));

        // Check for collision
        if (distanceSquared <= powf(cShape->GetRadius(), 2))
        {
            float distance = sqrtf(distanceSquared);
            m->penetration = cShape->GetRadius() - distance;
            m->normal = (distance > 0) ? circleToClosest / distance : Vector2i(0.f, 1.f);

            return true;
        }
    }
}

