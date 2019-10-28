#include "RPixelShaderDX.h"
#include <d3d11.h>
#include <d3dx11.h>


void * RPixelShaderDX::getPixelShader()
{
	return	reinterpret_cast<void*>(m_pixelShader);
}

bool RPixelShaderDX::init()
{
	return false;
}

void RPixelShaderDX::render()
{
}

void RPixelShaderDX::update()
{
}

void RPixelShaderDX::destroy()
{
}

RPixelShaderDX::RPixelShaderDX()
{
}


RPixelShaderDX::~RPixelShaderDX()
{
}
