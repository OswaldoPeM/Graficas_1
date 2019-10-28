#pragma once
#include"requerimientos.h"


class RViewport
{
public:	
	virtual void* getViewport()=0;
	virtual bool init(VIEWPORT &viewport)=0;
	virtual void render()=0;
	virtual void update()=0;
	virtual void destroy()=0;

	RViewport();
	~RViewport();
};

