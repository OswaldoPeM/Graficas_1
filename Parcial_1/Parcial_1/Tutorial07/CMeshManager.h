#pragma once
#include<vector>

#include"CMesh.h"
#include"CShaderResourceView.h"
struct shadersBuffers {
	CBuffer* NCh;
	CBuffer* ChR;
	CBuffer* ChEF;
	CVertexShader* VS;
	CPixelShader* PS;
	CSamplerState* SS;
};
class CMeshManager
{
	std::vector<CMesh> meshes;
	std::vector<CShaderResourceView> ResourcesView;


public:
	
	std::vector<CMesh>* getMeshes();
	std::vector<CShaderResourceView>* getTexture();

	bool init(const std::string& pFile, unsigned int pFlags, CDevice* Device);
	void render(CInterfaceDevice* DeviceContext, shadersBuffers SB );
	void update();
	void destroy();

	CMeshManager();
	~CMeshManager();
};

