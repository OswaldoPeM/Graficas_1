#pragma once
#include "RVertexShader.h"
class RVertexShaderDX :
	public RVertexShader
{
	ID3D11VertexShader* m_pVertexShader;
public:
	virtual void* getVertexShader() override;

	virtual bool init() override;
	virtual void render() override;
	virtual void update() override;
	virtual void destroy() override;

	RVertexShaderDX();
	~RVertexShaderDX();
};

