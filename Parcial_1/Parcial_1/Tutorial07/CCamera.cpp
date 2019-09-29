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

XMMATRIX * CCamera::getMView()
{
	return &view;
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

void CCamera::moveLeft()
{
	Eye -= Right * movementMagnitude;
}

void CCamera::moveRight()
{
	Eye += Right * movementMagnitude;
}

void CCamera::moveUp()
{
	Eye += Up * movementMagnitude;	
}

void CCamera::moveDown()
{
	Eye -= Up * movementMagnitude;	
}

void CCamera::moveForward()
{
	Eye += Front * movementMagnitude;
}

void CCamera::moveBack()
{
	Eye -= Front * movementMagnitude;
}

void CCamera::rotate(XMVECTOR * vec)
{

}


bool CCamera::init()
{
	update();
	return true;
}

void CCamera::update()
{
	Front = XMVector4Normalize(LookAt - Eye);
	Right = XMVector4Normalize(XMVector3Cross(Up, Front));
	Up = XMVector4Normalize(XMVector3Cross(Front, Right)); 
	LookAt = Eye + Front;
}
