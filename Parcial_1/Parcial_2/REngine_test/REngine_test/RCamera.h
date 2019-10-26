#pragma once
#include"requerimientos.h"

class RCamera
{
protected:
	float Near = 0.001f;
	float Far = 100.0f;
	float FoV = 0.785398163f;
	float AR;

	float movementMagnitude = 0.01f;
	float movementFix = 12.5;
	float lookRotationMagnitude = 0.01f;

	bool isPerspective=true;

	glm::vec3 Eye = glm::vec3(0.0f, 1.0f, -6.0f);
	glm::vec3 LookAt = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 Front = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 Right = glm::vec3(1.0f, 0.0f, 0.0f);

	glm::mat4 view;
	glm::mat4 projection;
public:
	glm::vec3* getEye();
	glm::vec3* getLookAt();
	glm::vec3* getUp();
	glm::vec3* getFront();
	glm::vec3* getRight();
	glm::mat4 getViewMatrix();
	glm::mat4 getProjMatrix();


	void rotate(RPoint* vec);
	void setEye(glm::vec3* vec);
	void setLookAt(glm::vec3* vec);
	void setUp(glm::vec3* vec);
	void setFront(glm::vec3* vec);
	void setRight(glm::vec3* vec);
	void setViewMatrix();
	void setProjectionMatrix(unsigned int width, unsigned int height);
	void swichProjection(unsigned int width, unsigned int height);

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void moveForward();
	void moveBack();

	bool init();
	void render();
	void update();
	void destroy();

	RCamera();
	~RCamera();
};

