#pragma once
#include "RPixelShader.h"
class ID3D11PixelShader;

class RPixelShaderDX :
	public RPixelShader
{
	ID3D11PixelShader* m_pixelShader;
public:
	virtual void* getPixelShader() override;

	virtual bool init() override;
	virtual void render() override;
	virtual void update() override;
	virtual void destroy() override;

	RPixelShaderDX();
	~RPixelShaderDX();
};

