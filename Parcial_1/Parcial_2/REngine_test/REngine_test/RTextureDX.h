#pragma once
#include "RTexture.h"
class ID3D11Texture2D;
class RTextureDX :
	public RTexture
{
	ID3D11Texture2D* m_pTexture;
public:
	virtual void* getTexture()override;
	virtual void* getTextDesc()override;

	virtual bool init(TEXTURE2D_DESC& desc) override;
	virtual void render() override;
	virtual void update() override;
	virtual void destroy() override;

	RTextureDX();
	virtual ~RTextureDX();
};

