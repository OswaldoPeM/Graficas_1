#include "CTexture.h"



ID3D11Texture2D ** CTexture::getTexture()
{
	return &Texture;
}

D3D11_TEXTURE2D_DESC * CTexture::getTexDesc()
{
	return &TextureDesc;
}

void CTexture::setTexture(CDepthStencilView DepthStencil)
{
	Texture = *DepthStencil.getDepthStencil();
}

void CTexture::setTextureDescValues(
	UINT Width,
	UINT Height,
	UINT MipLevels,
	UINT ArraySize,
	DXGI_FORMAT Format,
	DXGI_SAMPLE_DESC SampleDesc,
	D3D11_USAGE Usage, 
	UINT BindFlags, 
	UINT CPUAccessFlags, 
	UINT MiscFlags)
{
	TextureDesc = { 
		Width,
		Height,
		MipLevels,
		ArraySize,
		Format,
		SampleDesc,
		Usage,
		BindFlags,
		CPUAccessFlags,
		MiscFlags };
}

void CTexture::Realase()
{
	Texture->Release();
}

CTexture::CTexture()
{
}


CTexture::~CTexture()
{
}
