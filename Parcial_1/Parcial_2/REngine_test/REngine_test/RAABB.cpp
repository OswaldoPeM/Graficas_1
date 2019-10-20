#include "RAABB.h"



bool RAABB::init()
{
	return true;
}

void RAABB::render()
{
}

void RAABB::update()
{
}

void RAABB::destroy()
{
	free(this);
}

RAABB::RAABB(Rvertex4f & max, Rvertex4f & min) :
	m_vertex{
		{ min.x,max.y,min.z,1},{ max.x,max.y,min.z,1},
		{ min.x,min.y,min.z,1},{ max.x,min.y,min.z,1},
		{ min.x,max.y,max.z,1},{ max.x,max.y,max.z,1},
		{ min.x,min.y,max.z,1},{ max.x,min.y,max.z,1}}
{
}

RAABB::RAABB()
{
}


RAABB::~RAABB()
{
}
