#include "CCameraManager.h"



CCamera * CCameraManager::getCamera()
{
	return &camera;
}

void CCameraManager::destroy()
{
	camera.destroy();
}

CCameraManager::CCameraManager()
{
}


CCameraManager::~CCameraManager()
{
}
