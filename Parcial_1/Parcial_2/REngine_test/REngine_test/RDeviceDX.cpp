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

int RDeviceDX::CreateVertexShader(RProgramShader & programShader, RDevice * _p_device)
{
	return 0;
}

int RDeviceDX::CreateInputLayout(RProgramShader & programShader, RDevice * _p_device)
{
	return 0;
}

int RDeviceDX::CreatePixelShader(RProgramShader & programShader, RDevice * _p_device)
{
	return 0;
}

int RDeviceDX::CreateTexture2D(RTexture2D & Texture, RDevice * _p_device)
{
	return 0;
}

int RDeviceDX::CreateRenderTargetView(RRenderTargetView & renderTargetView, RDevice * _p_device)
{
	return 0;
}

int RDeviceDX::CreateDepthStencilView(RDepthStencilView & depthStencilView, RDevice * _p_device)
{
	return 0;
}

int RDeviceDX::CreateSamplerState(RSamplerState & samplerState, RDevice * _p_device)
{
	return 0;
}

RDeviceDX::RDeviceDX()
{
}


RDeviceDX::~RDeviceDX()
{
}
