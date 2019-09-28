#pragma once
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>

class CVertexShader
{
	ID3D11VertexShader* ptr_vertexShader = NULL;
public:
	ID3D11VertexShader** getVertexShader();

	bool init();
	void render();
	void update();
	void destroy();

	CVertexShader();
	~CVertexShader();
};

