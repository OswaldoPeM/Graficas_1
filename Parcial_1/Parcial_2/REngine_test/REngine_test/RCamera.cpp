#include "RCamera.h"



RCamera::RCamera()
{
}


RCamera::~RCamera()
{
}

glm::vec3 * RCamera::getEye()
{
	return &Eye;
}

glm::vec3 * RCamera::getLookAt()
{
	return &LookAt;
}

glm::vec3 * RCamera::getUp()
{
	return &Up;
}

glm::vec3 * RCamera::getFront()
{
	return &Front;
}

glm::vec3 * RCamera::getRight()
{
	return &Right;
}

glm::mat4 RCamera::getViewMatrix()
{
	return view;
}

glm::mat4 RCamera::getProjMatrix()
{
	return projection;
}

void RCamera::setEye(glm::vec3 * vec)
{
	Eye = *vec;
}

void RCamera::setLookAt(glm::vec3 * vec)
{
	LookAt = *vec;
}

void RCamera::setUp(glm::vec3 * vec)
{
	Up = *vec;
}

void RCamera::setFront(glm::vec3 * vec)
{
	Front = *vec;
}

void RCamera::setRight(glm::vec3 * vec)
{
	Right = *vec;
}

void RCamera::setViewMatrix()
{
	view = glm::lookAtLH(Eye, LookAt, Up);
}

void RCamera::setProjectionMatrix(unsigned int width, unsigned int height)
{

}

void RCamera::swichProjection(unsigned int width, unsigned int height)
{
	isPerspective = !isPerspective;
	AR = width / (float)height;
	/*projection = (isPerspective) ? XMMatrixPerspectiveFovLH(FoV, AR, Near, Far) :
		XMMatrixOrthographicLH(width / 90, height / 90, Near, Far);*/
		
}

void RCamera::moveLeft()
{
	Eye -= Right * movementMagnitude;
	LookAt -= Right * movementMagnitude;
}


void RCamera::moveRight()
{
	Eye += Right * movementMagnitude;
	LookAt += Right * movementMagnitude;

}

void RCamera::moveUp()
{
	Eye += Up * movementMagnitude*movementFix;
	LookAt += Up * movementMagnitude*movementFix;

}

void RCamera::moveDown()
{
	Eye -= Up * movementMagnitude*movementFix;
	LookAt -= Up * movementMagnitude*movementFix;

}

void RCamera::moveForward()
{
	Eye += Front * movementMagnitude;
	LookAt += Front * movementMagnitude;
}

void RCamera::moveBack()
{
	Eye -= Front * movementMagnitude;
	LookAt -= Front * movementMagnitude;

}

void RCamera::rotate(RPoint* vec)
{
	Eye += Right * (lookRotationMagnitude * (vec->x));
	update();
	Eye -= Up * (lookRotationMagnitude * (vec->y));
}

bool RCamera::init()
{
	update();
	setViewMatrix();
	return true;
}

void RCamera::render()
{
}

void RCamera::update()
{

	Front = glm::normalize(LookAt - Eye);
	Right = glm::normalize(glm::cross(Up, Front));
	Up = glm::normalize(glm::cross(Front, Right));
	LookAt = Front + Eye;

}

void RCamera::destroy()
{
}
