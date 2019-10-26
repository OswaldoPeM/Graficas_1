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

RCamaraManager::RCamaraManager()
{
}


RCamaraManager::~RCamaraManager()
{
}
