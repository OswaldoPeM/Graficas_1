#pragma once
#include <string>
#include"requerimientos.h"
class RShaderResourceView
{
public:
	virtual void* getResourceView() = 0;

	virtual bool init(std::string path) = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void destroy() = 0;

	RShaderResourceView();
	virtual ~RShaderResourceView();
};

