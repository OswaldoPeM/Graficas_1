#include "RDepthStencilViewDX.h"
#include "RTextureDX.h"

#include <d3d11.h>
#include <d3dx11.h>




void * RDepthStencilViewDX::getDSV()
{
	return reinterpret_cast<void*>(m_pDepthStencilView);
}

void * RDepthStencilViewDX::getDSVdesc()
{
	return reinterpret_cast<void*>(&stencilVDesc);
}

void * RDepthStencilViewDX::getTexture()
{
	return m_texture->getTexture();
}

void * RDepthStencilViewDX::getTextDesc()
{
	return m_texture->getTextDesc();
}

bool RDepthStencilViewDX::inti(STENCIL_VIEW_DESC desc, TEXTURE2D_DESC tDesc)
{
	stencilVDesc = desc;
	return false;
}

void RDepthStencilViewDX::render()
{
}

void RDepthStencilViewDX::update()
{
}

void RDepthStencilViewDX::destroy()
{
}

RDepthStencilViewDX::RDepthStencilViewDX()
{
}


RDepthStencilViewDX::~RDepthStencilViewDX()
{
}
