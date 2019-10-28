#include "RinputLayoutDX.h"
#include <d3d11.h>
#include <d3dx11.h>




void * RInputLayoutDX::getIL()
{
	return reinterpret_cast<void*> (m_pInputLayout);
}

bool RInputLayoutDX::init(INPUT_ELEMENT_DESC desc)
{
	m_InputLayoutDesc = desc;
	return true;
}

void RInputLayoutDX::render()
{
}

void RInputLayoutDX::update()
{
}

void RInputLayoutDX::destroy()
{
}

RInputLayoutDX::RInputLayoutDX()
{
}


RInputLayoutDX::~RInputLayoutDX()
{
}
