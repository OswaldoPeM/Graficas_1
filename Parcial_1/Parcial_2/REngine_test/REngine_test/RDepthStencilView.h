#pragma once
#include "requerimientos.h"

class RDepthStencilView
{
protected:
	STENCIL_VIEW_DESC stencilVDesc;
public:
	virtual void* getDSV() = 0;	

	virtual bool inti(STENCIL_VIEW_DESC desc) = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void destroy() = 0;
	RDepthStencilView();
	~RDepthStencilView();
};

