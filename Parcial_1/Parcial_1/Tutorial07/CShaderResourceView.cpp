#include "CShaderResourceView.h"



ID3D11ShaderResourceView ** CShaderResourceView::getTextureRV()
{
	return &g_pTextureRV;
}

LPCWSTR CShaderResourceView::getPath()
{
	return ddsPath.c_str();
}

void CShaderResourceView::setPath(LPCWSTR path)
{
	ddsPath = path;
}

void CShaderResourceView::destoy()
{
	if (g_pTextureRV)g_pTextureRV->Release();
	delete this;
}

std::wstring CShaderResourceView::s2ws(const std::string & s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

CShaderResourceView::CShaderResourceView()
{
}

CShaderResourceView::CShaderResourceView(std::string path)
{
	std::wstring stemp = s2ws(path);
	ddsPath = stemp;
}


CShaderResourceView::~CShaderResourceView()
{
}
