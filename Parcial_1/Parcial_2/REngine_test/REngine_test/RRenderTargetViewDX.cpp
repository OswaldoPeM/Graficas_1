#include "RRenderTargetViewDX.h"
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>


void * RRenderTargetViewDX::getRenderTargetView()
{
	return reinterpret_cast<void*>(m_RenderTargetView);
}

bool RRenderTargetViewDX::init()
{
	return false;
}

void RRenderTargetViewDX::render()
{
}

void RRenderTargetViewDX::update()
{
}

void RRenderTargetViewDX::destroy()
{
}

RRenderTargetViewDX::RRenderTargetViewDX()
{
}


RRenderTargetViewDX::~RRenderTargetViewDX()
{
}
