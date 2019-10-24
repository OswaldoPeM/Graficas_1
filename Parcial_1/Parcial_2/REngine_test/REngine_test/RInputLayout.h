#pragma once

#include"requerimientos.h"

class RInputLayout
{
protected:
	INPUT_ELEMENT_DESC m_InputLayoutDesc;
public:
	virtual void* getIL() = 0;
	

	virtual bool init(INPUT_ELEMENT_DESC desc) = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void destroy() = 0;
	RInputLayout();
	virtual ~RInputLayout();
};

