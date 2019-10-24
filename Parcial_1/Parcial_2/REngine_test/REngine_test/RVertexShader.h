#pragma once
#include"Header.h"
#include"RShader.h"

class RVertexShader
	:public RShader
{
#ifdef DX
	ID3D11VertexShader* m_VertexShader;
#endif
public:
#ifdef DX
	ID3D11VertexShader** getVertexShader() { return &m_VertexShader; }
#endif
	
	RVertexShader();
	~RVertexShader();
};

