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

bool CCamera::init()
{
	Front = XMVector4Normalize(LookAt - Eye);
	Right = XMVector4Normalize(XMVector3Cross(Up, Front));
	Up = XMVector4Normalize(XMVector3Cross(Front, Right)); 
	LookAt = Eye + Front;

	return true;
}
