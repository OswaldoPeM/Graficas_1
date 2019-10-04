#pragma once
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <string>

class CShaderResourceView
{
	ID3D11ShaderResourceView* g_pTextureRV=NULL;
	std::wstring ddsPath;
public:

	ID3D11ShaderResourceView** getTextureRV();
	LPCWSTR getPath();
	void setPath(LPCWSTR path);
	void destoy();





	std::wstring s2ws(const std::string& s);
	CShaderResourceView();
	CShaderResourceView(std::string path);
	~CShaderResourceView();
};

