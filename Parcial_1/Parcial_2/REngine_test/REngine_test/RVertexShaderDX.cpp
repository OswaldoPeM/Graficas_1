#include "RVertexShaderDX.h"
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>


void * RVertexShaderDX::getVertexShader()
{
	return reinterpret_cast<void*>(m_pVertexShader);
}

RVertexShaderDX::RVertexShaderDX()
{
}


RVertexShaderDX::~RVertexShaderDX()
{
}
