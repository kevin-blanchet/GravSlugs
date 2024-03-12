#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <Vector2.h>

using CircleShape = sf::CircleShape;
using RectanlgeShape = sf::RectangleShape;


enum ShapeType
{
    CIRCLE,
    RECTANGLE
};

class PhysicShape
{
protected:
    ShapeType type;

public:
    PhysicShape();
    void setType(ShapeType t);
    ShapeType GetType();
};


class Circle : public PhysicShape
{
private:
    float m_radius;
    Vector2i m_center;

public:
    Circle() { type = CIRCLE; }
    Circle(const float radius) { type = CIRCLE; m_radius = radius };

    void SetRadius(const float radius) { m_radius = radius };
    void SetCenter(const Vector2i center) { m_center = center };

    Vector2i GetCenter() const { return m_center };
    float GetRadius() const { return m_radius };
};

class Rectangle : public PhysicsShape
{
private:
    Vector2i halfExtent;
public:
    Rectangle();
    Rectangle(const Vector2i& origin, const Vector2i& halfExtent); /
        float GetHeight()const;
    float GetWidth() const;
    Vector2i GetMin() const;
    Vector2i GetMax() const;
    void SetHalfExtent(const Vector2i halfExt);
    Vector2i GetHalfExtent() const;

};



