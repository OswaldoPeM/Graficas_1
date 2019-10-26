#pragma once
#include"RShader.h"
class RVertexShader
	:public RShader
{
public:
	virtual void* getVertexShader() = 0;

	virtual bool init() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void destroy() = 0;

	RVertexShader();
	virtual ~RVertexShader();
};

