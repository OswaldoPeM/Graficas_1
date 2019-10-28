#pragma once
#include "RViewport.h"
class RViewportDX :
	public RViewport
{
	VIEWPORT* m_viewport;
public:
	virtual void* getViewport() override;

	virtual bool init(VIEWPORT &viewport)override;
	virtual void render()override;
	virtual void update()override;
	virtual void destroy()override;

	RViewportDX();
	~RViewportDX();
};

