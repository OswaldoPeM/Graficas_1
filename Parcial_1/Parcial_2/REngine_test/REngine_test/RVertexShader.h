#pragma once
#include"Header.h"

class RVertexShader
{
#ifdef DX
	ID3D11VertexShader* m_VertexShader;
	ID3DBlob* pVSBlob = NULL;
	ID3D11InputLayout* m_VertexLayout = NULL;
	std::vector<D3D11_INPUT_ELEMENT_DESC> inputLayoutDesc;
#elif GL
	unsigned int m_VertexShader;
#endif // DX

public:
#ifdef DX
	ID3DBlob* getBlob() { return pVSBlob; }
	ID3D11InputLayout** getInputLayout() { return &m_VertexLayout; }
	std::vector<D3D11_INPUT_ELEMENT_DESC> getVecILDesc() { return inputLayoutDesc; }
#endif // DX

	void* getVertexShader() { return m_VertexShader; }
	
	int CompileShaderFromFile(const wchar_t * szFileName, const char * szEntryPoint,
		const char * szShaderModel, ID3DBlob ** ppBlobOut);
	int CreateInputLayoutDescFromVertexShaderSignature();

	RVertexShader();
	~RVertexShader();
};

