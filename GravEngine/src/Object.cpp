#include "Object.h"

Object::Object()
{
    setPosition(0);
    setVelocity(0);
    setAcceleration(0);
    setMass(1);
    setRestitution(0);
    setAngularVelocity(0);
    setAngleRad(0);
    setInertia(0);
}

Object::Object(const Vector2i pos, const Vector2i vel, const Vector2i acc, const float rest)
{
    m_position = pos;
    m_velocity = vel;
    m_acceleration = acc;
    m_estitution = rest;
    setMass(1);
    setAngularVelocity(0);
    setAngleRad(0);
    setInertia(0);
}

void Object::Update()
{

}