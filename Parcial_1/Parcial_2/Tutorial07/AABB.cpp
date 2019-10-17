#include "AABB.h"



void AABB::setMaxX(FLOAT &x)
{ 
	maximo.x = x;
}

void AABB::setMaxY(FLOAT &y)
{
	maximo.y = y;
}

void AABB::setMaxZ(FLOAT& z)
{
	maximo.z = z;
}

void AABB::setMinX(FLOAT& x)
{
	minimo.x = x;
}

void AABB::setMinY(FLOAT &y)
{
	minimo.y = y;
}

void AABB::setMinZ(FLOAT& z)
{
	minimo.z = z;
}

bool AABB::init()
{
	return true;
}

bool AABB::init(XMFLOAT4 &max, XMFLOAT4 &min)
{
	maximo = max;
	minimo = min;
	return true;
}

void AABB::render()
{
}

void AABB::update()
{
}

void AABB::destroy()
{
}

AABB::AABB() :
	maximo(FLT_MIN, FLT_MIN, FLT_MIN, 0),
	minimo(FLT_MAX, FLT_MAX, FLT_MAX, 0)
{
}


AABB::~AABB()
{
}
