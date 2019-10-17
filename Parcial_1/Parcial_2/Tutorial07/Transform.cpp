#include "Transform.h"



XMMATRIX* Transform::getPos()
{
	return &world;
}

float Transform::getScale()
{
	return m_scale;
}

float Transform::getRotation()
{
	return m_rotation;
}

void Transform::setPos(XMMATRIX pos)
{
}

void Transform::setScale(float scale)
{
	m_scale = scale;
}

void Transform::setRotation(float rotation)
{
	m_rotation = rotation;
}

bool Transform::init()
{
	return true;
}

void Transform::render()
{
}

void Transform::update()
{
}

void Transform::destroy()
{
}

Transform::Transform()
{
}


Transform::~Transform()
{
}
