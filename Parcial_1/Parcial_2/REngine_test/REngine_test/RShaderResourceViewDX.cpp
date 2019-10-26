#include "RShaderResourceViewDX.h"
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>



std::wstring RShaderResourceViewDX::s2ws(const std::string & s)
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

void * RShaderResourceViewDX::getResourceView()
{
	return reinterpret_cast<void*>(m_ResourceView);
}

bool RShaderResourceViewDX::init(std::string path)
{
	m_path = s2ws(path);
	return true;
}

void RShaderResourceViewDX::render()
{
}

void RShaderResourceViewDX::update()
{
}

void RShaderResourceViewDX::destroy()
{
}

RShaderResourceViewDX::RShaderResourceViewDX()
{
}


RShaderResourceViewDX::~RShaderResourceViewDX()
{
}
