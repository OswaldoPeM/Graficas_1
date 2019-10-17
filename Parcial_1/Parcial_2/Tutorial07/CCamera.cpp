#include "CCamera.h"



CCamera::CCamera()
{
}


CCamera::~CCamera()
{
}

XMVECTOR * CCamera::getEye()
{
	return &Eye;
}

XMVECTOR * CCamera::getLookAt()
{
	return &LookAt;
}

XMVECTOR * CCamera::getUp()
{
	return &Up;
}

XMVECTOR * CCamera::getFront()
{
	return &Front;
}

XMVECTOR * CCamera::getRight()
{
	return &Right;
}

XMMATRIX  CCamera::getViewMatrix()
{
	return view;
}

void CCamera::setEye(XMVECTOR * vec)
{ 
	Eye = *vec;
}

void CCamera::setLookAt(XMVECTOR * vec)
{
	LookAt = *vec;
}

void CCamera::setUp(XMVECTOR * vec)
{
	Up = *vec;
}

void CCamera::setFront(XMVECTOR * vec)
{
	Front = *vec;
}

void CCamera::setRight(XMVECTOR * vec)
{
	Right = *vec;
}

void CCamera::setViewMatrix()
{
	view = XMMatrixLookAtLH(Eye, LookAt, Up);

}

void CCamera::moveLeft()
{
	Eye -= Right * movementMagnitude;
	LookAt -= Right * movementMagnitude;
	
}

void CCamera::moveRight()
{
	Eye += Right * movementMagnitude;
	LookAt += Right * movementMagnitude;
	
}

void CCamera::moveUp()
{
	Eye += Up*movementMagnitude*movementFix;
	LookAt += Up*movementMagnitude*movementFix;
	
}

void CCamera::moveDown()
{
	Eye -= Up * movementMagnitude*movementFix;
	LookAt -= Up * movementMagnitude*movementFix;
	
}

void CCamera::moveForward()
{
	Eye += Front * movementMagnitude;
	LookAt += Front * movementMagnitude;
}

void CCamera::moveBack()
{
	Eye -= Front * movementMagnitude;
	LookAt -= Front * movementMagnitude;
	
}

void CCamera::rotate(POINT* vec)
{
	Eye += Right * lookRotationMagnitude * (vec->x);
	update();
	Eye -= Up * lookRotationMagnitude * (vec->y);
}

void CCamera::updateLookAt()
{
}


bool CCamera::init()
{
	update();
	setViewMatrix();
	return true;
}

void CCamera::render()
{
}

void CCamera::update()
{
	Front = XMVector4Normalize(LookAt - Eye);
	Right = XMVector4Normalize(XMVector3Cross(Up, Front));
	Up = XMVector4Normalize(XMVector3Cross(Front, Right)); 
	LookAt =  Front+Eye;
}

void CCamera::destroy()
{
}
