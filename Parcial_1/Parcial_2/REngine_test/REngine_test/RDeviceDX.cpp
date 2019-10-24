#include "RDeviceDX.h"
#include <d3d11.h>
#include <d3dx11.h>


void * RDeviceDX::getDevice()
{
	return reinterpret_cast<void*>(m_pDevice);
}

int RDeviceDX::CreateBuffer(RBuffer & buffer, RDevice * device)
{
	return 0;
}

RDeviceDX::RDeviceDX()
{
}


RDeviceDX::~RDeviceDX()
{
}
