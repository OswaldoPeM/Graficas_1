#pragma once
#include"requerimientos.h"

class RSamplerState
{
protected:
	SAMPLER_DESC samplerDesc;
public:
	virtual void* getSamplerLinear() = 0;
	virtual void* getSamplerDesc() = 0;
	virtual bool init() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void destroy() = 0;
	RSamplerState();
	virtual ~RSamplerState();
};

