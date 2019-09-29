#include "CCameraManager.h"



CCamera * CCameraManager::getCamera()
{
	return &camera;
}

XMMATRIX  CCameraManager::getProjectionMatrix()
{
	return projection;
}

XMMATRIX  CCameraManager::getViewMatrix()
{
	return camera.getViewMatrix();
}

void CCameraManager::setProjectionMatrix(UINT width, UINT height)
{
	AR = width / (FLOAT)height;
	projection = (isPerspective) ? XMMatrixPerspectiveFovLH(FoV, AR, Near, Far) :
		XMMatrixOrthographicLH(width / 90, height / 90, Near, Far);
}

void CCameraManager::swichProjection(UINT width, UINT height)
{
	isPerspective = !isPerspective;
	setProjectionMatrix(width, height);
}

void CCameraManager::actLookAt()
{
	camera.updateLookAt();
}

void CCameraManager::move(XMFLOAT3 * mat)
{
	if (mat->x > 0)camera.moveRight();
	if (mat->x < 0)camera.moveLeft();
	if (mat->y > 0)camera.moveUp();
	if (mat->y < 0)camera.moveDown();
	if (mat->z > 0)camera.moveForward();
	if (mat->z < 0)camera.moveBack();

	camera.update();
	camera.setViewMatrix();



}

void CCameraManager::rotate(XMVECTOR * vec)
{
	camera.rotate(vec);
	camera.update();
}

bool CCameraManager::init()
{
	camera.init();
	return false;
}

void CCameraManager::render()
{
}

void CCameraManager::update()
{
}

void CCameraManager::destroy()
{
	camera.destroy();
	delete this;
}

CCameraManager::CCameraManager()
{
}


CCameraManager::~CCameraManager()
{
}
