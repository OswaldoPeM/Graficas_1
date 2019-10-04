#pragma once

#include"CDepthStencilView.h"

enum DataType
{
	dds=0,
	tga=1,
};
class CTexture
{
	ID3D11Texture2D* Texture = NULL;
	D3D11_TEXTURE2D_DESC TextureDesc;
public:
	ID3D11Texture2D** getTexture();
	D3D11_TEXTURE2D_DESC *getTexDesc();

	void setTexture(CDepthStencilView DepthStencil);

	void setTextureDescValues(
		UINT Width,
		UINT Height,
		UINT MipLevels,
		UINT ArraySize,
		DXGI_FORMAT Format,
		DXGI_SAMPLE_DESC SampleDesc,
		D3D11_USAGE Usage,
		UINT BindFlags,
		UINT CPUAccessFlags,
		UINT MiscFlags);

	void Realase();

	CTexture();
	~CTexture();
};

