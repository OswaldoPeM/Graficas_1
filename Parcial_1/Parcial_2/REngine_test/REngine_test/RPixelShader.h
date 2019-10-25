#pragma once
#include"RShader.h"
class RPixelShader
	:public RShader
{
public:
	virtual void* getPixelShader() = 0;

	virtual bool init() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void destroy() = 0;
	RPixelShader();
	~RPixelShader();
};

