#include "RBufferDX.h"
#include <d3d11.h>
#include <d3dx11.h>



void * RBufferDX::getBuffer()
{
	return reinterpret_cast<void*>(m_pBuffer);
}

bool RBufferDX::init(BufferDesc & desData)
{
	m_description = desData.desc;
	m_initData = desData.data;

	return false;
}

void RBufferDX::render()
{
}

void RBufferDX::update()
{
}

void RBufferDX::destroy()
{
}

RBufferDX::RBufferDX()
{
}


RBufferDX::~RBufferDX()
{
	m_pBuffer->Release();
}
