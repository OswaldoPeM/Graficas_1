#include "RinputLayoutDX.h"
#include <d3d11.h>
#include <d3dx11.h>




void * RinputLayoutDX::getIL()
{
	return reinterpret_cast<void*> (m_pInputLayout);
}

bool RinputLayoutDX::init(INPUT_ELEMENT_DESC desc)
{
	m_InputLayoutDesc = desc;
	return true;
}

RinputLayoutDX::RinputLayoutDX()
{
}


RinputLayoutDX::~RinputLayoutDX()
{
}
