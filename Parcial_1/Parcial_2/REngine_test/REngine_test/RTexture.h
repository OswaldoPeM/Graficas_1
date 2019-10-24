#pragma once
#include"requerimientos.h"

class RTexture
{
protected:	
	TEXTURE2D_DESC m_TextureDesc;
public:
	virtual void* getTexture() = 0;

	virtual bool init(TEXTURE2D_DESC& desc) = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void destroy() = 0;
	RTexture();
	virtual ~RTexture();
};

