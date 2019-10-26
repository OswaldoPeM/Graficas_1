#include "RTransform.h"



RTransform::RTransform()
{
}


RTransform::~RTransform()
{
}

void RTransform::setPos(glm::mat4 pos)
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
	m_scale = desc.SCALE;
	m_rotation = desc.ROTATION;
	world = desc.POSITION;

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
