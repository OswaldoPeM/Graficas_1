#include "CMeshManager.h"



std::vector<CMesh>* CMeshManager::getMeshes()
{
	return &meshes;
}

bool CMeshManager::init(const std::string & pFile, unsigned int pFlags)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(pFile, pFlags);

	for (unsigned int i = 0; i < scene->mNumMeshes; i++)
	{
		meshes.push_back(CMesh(scene->mMeshes[i]));
	}

	for (unsigned int i = 0; i < scene->mNumMaterials; i++)
	{
		scene->mMaterials[i];
	}
	for (unsigned int i = 0; i < scene->mNumTextures; i++)
	{
		scene->mTextures[i];
	}
	return true;
}

void CMeshManager::render()
{
}

void CMeshManager::update()
{
	//stbi_load_from_file()
}

void CMeshManager::destroy()
{
	for (unsigned int i = 0; i < meshes.size(); i++)
	{
		meshes[i].destroy();
	}
	delete this;
}

CMeshManager::CMeshManager()
{
}


CMeshManager::~CMeshManager()
{
}
