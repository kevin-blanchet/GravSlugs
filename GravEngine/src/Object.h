#pragma once

#include "Vector2.h"
#include "Shape.h"

class Object
{
protected:
    float m_mass;
    float m_inverseMass;
    float m_restitution;
    float m_inertia;
    float m_inverseInertia;
    float m_angularVelocity;
    float m_angle;               /*!< angle en radians*/

public:
    PhysicShape* shape;
    Vector2i position;
    Vector2i velocity;
    Vector2i acceleration;

    Object();
    Object(const Vector2i pos, const Vector2i vel, const Vector2i acc, const float rest);

    void Update(float timeStep);

    // Getters
    float getMass() const { return m_mass; }
    float getInverseMass() const { return m_inverseMass; }
    float getRestitution() const { return m_restitution; }
    float getInertia() const { return m_inertia; }
    float getInverseInertia() const { return m_inverseInertia; }
    float getAngularVelocity() const { return m_angularVelocity; }
    float getAngle() const { return m_angle; }

    // Setters
    void setMass(float mass) { m_mass = mass; }
    void setInverseMass(float inverseMass) { m_inverseMass = inverseMass; }
    void setRestitution(float restitution) { m_restitution = restitution; }
    void setInertia(float inertia) { m_inertia = inertia; }
    void setInverseInertia(float inverseInertia) { m_inverseInertia = inverseInertia; }
    void setAngularVelocity(float angularVelocity) { m_angularVelocity = angularVelocity; }
    void setAngle(float angle) { m_angle = angle; }

    void setShape(PhysicShape* newShape) { shape = newShape; }
    void setPosition(const Vector2i& newPos) { position = newPos; }
    void setVelocity(const Vector2i& newVel) { velocity = newVel; }
    void setAcceleration(const Vector2i& newAcc) { acceleration = newAcc; }

    void applyImpulse(const Vector2i impulse, const Vector2i contact);
};