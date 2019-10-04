#pragma once
#include <d3d11.h>
#include <d3dx11.h>
class CViewport
{
	D3D11_VIEWPORT viewport;
public:
	D3D11_VIEWPORT* getVP();

	bool init(
		FLOAT TopLeftX,
		FLOAT TopLeftY,
		FLOAT Width,
		FLOAT Height,
		FLOAT MinDepth,
		FLOAT MaxDepth);
	CViewport();
	~CViewport();
};

