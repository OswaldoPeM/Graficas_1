#pragma once
#include"requerimientos.h"
class RVertexShader;

class RProgramShader
{

protected:
	RVertexShader *m_VertexShader;
public:
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

