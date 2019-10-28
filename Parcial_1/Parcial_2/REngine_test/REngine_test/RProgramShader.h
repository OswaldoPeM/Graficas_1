#pragma once
#include"requerimientos.h"
class RVertexShader;
class RPixelShader;
class RInputLayout;

class RProgramShader
{

protected:
	RVertexShader *m_VertexShader;
	RPixelShader *m_PixelShader;
	RInputLayout *m_InputLayout;
public:
	virtual void* getVertexShader() = 0;
	virtual void* getPixelShader() = 0;
	virtual void* getInputLayout() = 0;
	virtual void* getBlob() = 0;

	virtual void
		chargeShader
		(
			const char * vertex_file_path,
			const char * fragment_file_path
		) = 0;

	virtual bool inti() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void destroy() = 0;


	RProgramShader();
	~RProgramShader();
};

