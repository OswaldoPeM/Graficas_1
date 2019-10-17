#pragma once
#include<vector>

#include"CMesh.h"
#include"CComp.h"
#include"CShaderResourceView.h"
struct RenderBuffers {
	CBuffer* NCh;
	CBuffer* ChR;
	CBuffer* ChEF;
	CVertexShader* VS;
	CPixelShader* PS;
	CSamplerState* SS;
};
class CMeshManager : public CComp
{
	std::vector<CMesh> meshes;
	std::vector<CShaderResourceView> ResourcesView;


public:
	
	std::vector<CMesh>* getMeshes();
	std::vector<CShaderResourceView>* getTexture();

	bool init(const std::string& pFile, unsigned int pFlags, CDevice* Device);
	bool init();
	void render(CInterfaceDevice* DeviceContext, RenderBuffers SB );
	void render();
	void update();
	void destroy();

	CMeshManager();
	~CMeshManager();
};

