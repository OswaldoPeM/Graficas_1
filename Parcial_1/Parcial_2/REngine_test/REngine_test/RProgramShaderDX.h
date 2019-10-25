#pragma once
#include "RProgramShader.h"
class RProgramShaderDX :
	public RProgramShader
{

public:
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

