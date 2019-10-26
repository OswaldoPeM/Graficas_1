#include "RSamplerStateDX.h"
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>


void * RSamplerStateDX::getSamplerLinear()
{
	return reinterpret_cast<void*>(m_samplerLinear);
}

bool RSamplerStateDX::init()
{
	return false;
}

void RSamplerStateDX::render()
{
}

void RSamplerStateDX::update()
{
}

void RSamplerStateDX::destroy()
{
}

RSamplerStateDX::RSamplerStateDX()
{
}


RSamplerStateDX::~RSamplerStateDX()
{
}
