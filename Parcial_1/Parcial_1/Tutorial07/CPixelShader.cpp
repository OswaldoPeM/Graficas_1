#include "CPixelShader.h"



ID3D11PixelShader ** CPixelShader::getPixelShader()
{
	return &ptr_PixelShader;
}

void CPixelShader::destroy()
{
	if (ptr_PixelShader)ptr_PixelShader->Release();
	delete this;
}

CPixelShader::CPixelShader()
{
}


CPixelShader::~CPixelShader()
{
}
