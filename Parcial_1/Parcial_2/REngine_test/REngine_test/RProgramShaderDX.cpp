#include "RProgramShaderDX.h"
#include<sstream>
#include<fstream>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>


void RProgramShaderDX::chargeShader(const char * vertex_file_path, const char * fragment_file_path)
{
	ID3D10Blob* pVSBlob;
	ID3D10Blob* pErroMsg = nullptr;
	if (pVSBlob != nullptr) {
		pVSBlob->Release();
	}

	// Create the shaders
	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if (VertexShaderStream.is_open()) {
		std::stringstream ss;
		ss << VertexShaderStream.rdbuf();
		VertexShaderCode = ss.str();
		VertexShaderStream.close();
	}
	else {
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
		getchar();
		return;
	}
	auto vertexShader = VertexShaderCode;

	HRESULT hr = D3DCompile(
		vertexShader.c_str(),
		vertexShader.length(),
		nullptr,
		nullptr,
		nullptr,
		"VS", "vs_4_0",
		D3DCOMPILE_ENABLE_STRICTNESS, 0,
		&pVSBlob,
		&pErroMsg);
	if (pErroMsg)
	{
		SIZE_T msgSize = pErroMsg->GetBufferSize();
		string msg;
		msg.resize(msgSize);
		memcpy(&msg[0], pErroMsg->GetBufferPointer(), msgSize);
		pErroMsg->Release();
		OutputDebugStringA(msg.c_str());
	}
	if (FAILED(hr))
	{
		cout << "can't compile pixel shader\n";
	}
	device.m_pd3dDevice->CreateVertexShader(device.pVSBlob->GetBufferPointer(), device.pVSBlob->GetBufferSize(), NULL, &programShader.m_VertexS.m_pVertexShader);

	//PIXEL SHADER	
#

	pErroMsg = nullptr;
	if (device.pVSBlob != nullptr)
	{
		device.pVSBlob->Release();
	}
	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if (FragmentShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << FragmentShaderStream.rdbuf();
		FragmentShaderCode = sstr.str();
		//cout << FragmentShaderCode << "\n";
		FragmentShaderStream.close();
	}
	else {
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", fragment_file_path);
		getchar();
		return;
	}

	auto FrameShader = FragmentShaderCode;
	//Microsoft::WRL::ComPtr<ID3DBlob> blob;
	hr = D3DCompile(
		FragmentShaderCode.c_str(),
		FragmentShaderCode.length(),
		nullptr,
		nullptr,
		nullptr,
		"PS", "ps_4_0",
		D3DCOMPILE_ENABLE_STRICTNESS, 0,
		&device.pVSBlob,
		&pErroMsg);
	if (pErroMsg)
	{
		SIZE_T msgSize = pErroMsg->GetBufferSize();
		string msg;
		msg.resize(msgSize);
		memcpy(&msg[0], pErroMsg->GetBufferPointer(), msgSize);
		pErroMsg->Release();
		OutputDebugStringA(msg.c_str());
	}
	if (!hr)
	{
		cout << "can't compile pixel shader\n";
	}
	device.m_pd3dDevice->CreatePixelShader(device.pVSBlob->GetBufferPointer(), device.pVSBlob->GetBufferSize(), NULL, &programShader.m_PixelS.m_pPixelShader);

	return;
}

RProgramShaderDX::RProgramShaderDX()
{
}


RProgramShaderDX::~RProgramShaderDX()
{
}
