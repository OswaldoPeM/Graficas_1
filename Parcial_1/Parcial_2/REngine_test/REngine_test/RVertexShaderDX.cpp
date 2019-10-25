#include "RVertexShaderDX.h"
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>


void * RVertexShaderDX::getVertexShader()
{
	return reinterpret_cast<void*>(m_pVertexShader);
}

bool RVertexShaderDX::init()
{
	return false;
}

void RVertexShaderDX::render()
{
}

void RVertexShaderDX::update()
{
}

void RVertexShaderDX::destroy()
{
}

RVertexShaderDX::RVertexShaderDX()
{
}


RVertexShaderDX::~RVertexShaderDX()
{
	if (m_pVertexShader)
	{
		m_pVertexShader->Release();
	}
}
