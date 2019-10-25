#pragma once
#include "RInputLayout.h"

class RShader
{
protected:
public:
	virtual bool init() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void destroy() = 0;
	RShader();
	~RShader();
};

