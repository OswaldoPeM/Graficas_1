#pragma once
#include "CComp.h"
class Transform :
	public CComp
{
	XMMATRIX world;
	float m_scale;
	float m_rotation;
public:

	XMMATRIX* getPos();
	float getScale();
	float getRotation();

	void setPos(XMMATRIX pos);
	void setScale(float scale);
	void setRotation(float rotation);

	bool init();
	void render();
	void update();
	void destroy();

	Transform();
	~Transform();
};

