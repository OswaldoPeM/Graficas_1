#include "RTextureDX.h"
#include <d3d11.h>
#include <d3dx11.h>



void* RTextureDX::getTexture()
{
	return reinterpret_cast<void*>(m_pTexture);
}

void * RTextureDX::getTextDesc()
{
	return reinterpret_cast<void*>(&m_TextureDesc);
}

bool RTextureDX::init(TEXTURE2D_DESC & desc)
{
	m_TextureDesc = desc;

	return true;
}

void RTextureDX::render()
{
}

void RTextureDX::update()
{
}

void RTextureDX::destroy()
{
}

RTextureDX::RTextureDX()
{
}


RTextureDX::~RTextureDX()
{
}
