#pragma once
#include<vector>

#include"CMesh.h"
#include"CShaderResourceView.h"

class CMeshManager
{
	std::vector<CMesh> meshes;
	std::vector<CShaderResourceView> ResourcesView;

public:
	
	std::vector<CMesh>* getMeshes();

	bool init(const std::string& pFile, unsigned int pFlags);
	void render();
	void update();
	void destroy();

	CMeshManager();
	~CMeshManager();
};

