#include "RViewportDX.h"
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>


void * RViewportDX::getViewport()
{
	return reinterpret_cast<void*>(m_viewport);
}

bool RViewportDX::init(VIEWPORT & viewport)
{
	*m_viewport = viewport;
	return false;
}

void RViewportDX::render()
{
}

void RViewportDX::update()
{
}

void RViewportDX::destroy()
{
}

RViewportDX::RViewportDX()
{
}


RViewportDX::~RViewportDX()
{
}
