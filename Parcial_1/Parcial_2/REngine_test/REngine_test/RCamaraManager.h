#pragma once
#include<vector>
#include"requerimientos.h"
class RCamera;

class RCamaraManager
{
	std::vector<RCamera> m_cameras;
	int activeCameraIndex = 0;
public:
	RCamera* getActiveCamera();
	glm::mat4 getProjectionMatrix();
	glm::mat4 getViewMatrix();

	void setProjectionMatrix(unsigned int width, unsigned int height);
	void swichProjection(unsigned int width, unsigned int height);
	void actLookAt();

	void move(glm::vec4* mat);
	void rotate(RPoint* vec);

	bool init();
	void render();
	void update();
	void destroy();
	RCamaraManager();
	~RCamaraManager();
};

