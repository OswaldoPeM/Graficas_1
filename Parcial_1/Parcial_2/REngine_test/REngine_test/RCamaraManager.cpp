#include "RCamaraManager.h"
#include"RCamera.h"


RCamera * RCamaraManager::getActiveCamera()
{
	return &m_cameras[activeCameraIndex];
}

glm::mat4 RCamaraManager::getProjectionMatrix()
{
	return m_cameras[activeCameraIndex].getProjMatrix();
}

glm::mat4 RCamaraManager::getViewMatrix()
{
	return m_cameras[activeCameraIndex].getViewMatrix();
}

void RCamaraManager::setProjectionMatrix(unsigned int width, unsigned int height)
{
	m_cameras[activeCameraIndex].setProjectionMatrix(width, height);
}

void RCamaraManager::swichProjection(unsigned int width, unsigned int height)
{
	m_cameras[activeCameraIndex].swichProjection(width, height);
}

void RCamaraManager::actLookAt()
{
}

void RCamaraManager::move(glm::vec4 * mat)
{
}

void RCamaraManager::rotate(RPoint * vec)
{
}

bool RCamaraManager::init()
{
	return false;
}

void RCamaraManager::render()
{
}

void RCamaraManager::update()
{
}

void RCamaraManager::destroy()
{
}

RCamaraManager::RCamaraManager()
{
}


RCamaraManager::~RCamaraManager()
{
}
