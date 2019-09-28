#include "CShaderResourceView.h"



ID3D11ShaderResourceView ** CShaderResourceView::getTextureRV()
{
	return &g_pTextureRV;
}

void CShaderResourceView::destoy()
{
	if (g_pTextureRV)g_pTextureRV->Release();
	delete this;
}

CShaderResourceView::CShaderResourceView()
{
}


CShaderResourceView::~CShaderResourceView()
{
}
