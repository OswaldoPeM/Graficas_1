#include "CVertexShader.h"



ID3D11VertexShader ** CVertexShader::getVertexShader()
{
	return &ptr_vertexShader;
}

bool CVertexShader::init()
{
	return false;
}

void CVertexShader::render()
{
}

void CVertexShader::update()
{
}

void CVertexShader::destroy()
{
	if (ptr_vertexShader)ptr_vertexShader->Release();
	delete this;
}

CVertexShader::CVertexShader()
{
}


CVertexShader::~CVertexShader()
{
}
