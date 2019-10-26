#include "RAABB.h"



bool RAABB::init(glm::vec3 &max, glm::vec3 &min)
{
	m_vertex[0]	= 
		glm::vec3{ min.x,max.y,min.z};

	m_vertex[1]	= 
		glm::vec3{ max.x,max.y,min.z};

	m_vertex[2]	= 
		glm::vec3{ min.x,min.y,min.z};

	m_vertex[3]	= 
		glm::vec3{ max.x,min.y,min.z};

	m_vertex[4]	= 
		glm::vec3{ min.x,max.y,max.z};

	m_vertex[5]	= 
		glm::vec3{ max.x,max.y,max.z};

	m_vertex[6]	= 
		glm::vec3{ min.x,min.y,max.z};

	m_vertex[7]	= 
		glm::vec3{ max.x,min.y,max.z};

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

}

RAABB::RAABB()
{
}


RAABB::~RAABB()
{
}
