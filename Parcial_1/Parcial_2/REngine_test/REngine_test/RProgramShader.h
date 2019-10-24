#pragma once
#include <fstream>
#include <sstream>
#include "RPixelShader.h"
#include "RVertexShader.h"
class RProgramShader
{
#ifdef DX
	RVertexShader * m_VertexShader;
	RPixelShader  * m_PixelShader;
	
	ID3DBlob* pVSBlob = nullptr;
	RInputLayout* m_VertexLayout = nullptr;
	std::vector<D3D11_INPUT_ELEMENT_DESC> inputLayoutDesc;
#elif GL
	unsigned int m_VertexShader;
	unsigned int m_PixelShader;
#endif // DX

public:
#ifdef DX

	ID3DBlob* getBlob() { return pVSBlob; }
	ID3D11InputLayout** getInputLayout() { return (ID3D11InputLayout**)m_VertexLayout->getIL(); }
	std::vector<D3D11_INPUT_ELEMENT_DESC> getVecILDesc() { return inputLayoutDesc; }
	RVertexShader* getVS() { return m_VertexShader; }
	RPixelShader* getPS() { return m_PixelShader; }
#endif // DX

	void chargeShader(const char * vertex_file_path, const char * fragment_file_path);


	RProgramShader();
	~RProgramShader();
};

