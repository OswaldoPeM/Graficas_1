#include "CViewport.h"



D3D11_VIEWPORT * CViewport::getVP()
{
	return &viewport;
}

bool CViewport::init(FLOAT TopLeftX, FLOAT TopLeftY, FLOAT Width, FLOAT Height, FLOAT MinDepth, FLOAT MaxDepth)
{
	viewport = {
		TopLeftX,
		TopLeftY,
		Width,
		Height,
		MinDepth,
		MaxDepth 
	};
	return true;
}

CViewport::CViewport()
{
}


CViewport::~CViewport()
{
}
