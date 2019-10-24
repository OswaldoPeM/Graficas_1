#include "RDepthStencilViewDX.h"
#include <d3d11.h>
#include <d3dx11.h>




void * RDepthStencilViewDX::getDSV()
{
	return reinterpret_cast<void*>(m_pDepthStencilView);
}

bool RDepthStencilViewDX::inti(STENCIL_VIEW_DESC desc)
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
