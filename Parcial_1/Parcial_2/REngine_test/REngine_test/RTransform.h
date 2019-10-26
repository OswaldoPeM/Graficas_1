#pragma once
#include "RComponent.h"
#include "requerimientos.h"

struct RTransform_Desc{
	glm::mat4 POSITION;
	glm::vec3 SCALE;
	glm::vec3 ROTATION;
};

class RTransform :
	public RComponent
{
	glm::mat4 world;
	glm::vec3 m_scale;
	glm::vec3 m_rotation;
public:

	glm::mat4* getPos();
	glm::vec3* getScale();
	glm::vec3* getRotation();

	void setPos(glm::mat4 pos);
	void setScale(glm::vec3 scale);
	void setRotation(glm::vec3 rotation);

	bool init(RTransform_Desc& desc);
	void render();
	void update();
	void destroy();

	RTransform();
	~RTransform();
};

