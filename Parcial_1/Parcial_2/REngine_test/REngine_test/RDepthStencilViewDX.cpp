#include "RDepthStencilViewDX.h"



void * RDepthStencilViewDX::getDSV()
{
	return reinterpret_cast<void*>(m_pDepthStencilView);
}

RDepthStencilViewDX::RDepthStencilViewDX()
{
}


RDepthStencilViewDX::~RDepthStencilViewDX()
{
}
