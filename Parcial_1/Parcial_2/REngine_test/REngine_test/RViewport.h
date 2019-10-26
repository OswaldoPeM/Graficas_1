#pragma once
#include"requerimientos.h"

class RViewport
{
	VIEWPORT m_viewport;
public:

	VIEWPORT* getViewport() { return &m_viewport; }

	bool init(VIEWPORT &viewport);
	void render();
	void update();
	void destroy();

	RViewport();
	~RViewport();
};

