#pragma once
#include "RShaderResourceView.h"
class ID3D11ShaderResourceView;
class RShaderResourceViewDX :
	public RShaderResourceView
{
	ID3D11ShaderResourceView* m_ResourceView;
	std::wstring m_path;
	std::wstring s2ws(const std::string& s);
public:
	virtual void* getResourceView() override;

	virtual bool init(std::string path) override;
	virtual void render() override;
	virtual void update() override;
	virtual void destroy() override;

	RShaderResourceViewDX();
	virtual ~RShaderResourceViewDX();
};

