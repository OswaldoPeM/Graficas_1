#pragma once
#include "RProgramShader.h"
class ID3D10Blob;
class RProgramShaderDX :
	public RProgramShader
{
	ID3D10Blob* pVSBlob;
public:

	virtual void* getVertexShader()override;
	virtual void* getPixelShader()override;
	virtual void* getInputLayout()override;
	virtual void* getBlob() override;
	virtual void
		chargeShader
		(
			const char * vertex_file_path,
			const char * fragment_file_path
		) override;

	virtual bool inti() override;
	virtual void render() override;
	virtual void update() override;
	virtual void destroy() override;

	RProgramShaderDX();
	virtual ~RProgramShaderDX();
};

