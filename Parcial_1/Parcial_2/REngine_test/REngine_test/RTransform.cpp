#include "RTransform.h"



RTransform::RTransform()
{
}


RTransform::~RTransform()
{
}

void RTransform::setPos(glm::vec3 pos)
{
}

void RTransform::setScale(glm::vec3 scale)
{
	m_scale = scale;
}

void RTransform::setRotation(glm::vec3 rotation)
{
	m_rotation = rotation;
}

bool RTransform::init(RTransform_Desc & desc)
{
	world = glm::identity<glm::mat4>();
	m_scale = desc.SCALE;
	m_rotation = desc.ROTATION;
	m_pos = desc.POSITION;

	//glm::rotate(world,m_rotation, m_rotation);
	return true;
}

void RTransform::render()
{
}

void RTransform::update()
{
}

void RTransform::destroy()
{
}
