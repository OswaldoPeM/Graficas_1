#include "CMeshManager.h"



std::vector<CMesh>* CMeshManager::getMeshes()
{
	return &meshes;
}

std::vector<CShaderResourceView>* CMeshManager::getTexture()
{
	return &ResourcesView;
}

bool CMeshManager::init(const std::string & pFile, unsigned int pFlags, CDevice* Device)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(pFile, pFlags);

	for (unsigned int i = 0; i < scene->mNumMeshes; i++)
	{
		meshes.push_back(CMesh(scene->mMeshes[i]));

	}

	for (unsigned int i = 0; i < scene->mNumMaterials; i++)
	{
		const aiMaterial* pMaterial = scene->mMaterials[i];


		if (pMaterial->GetTextureCount(aiTextureType_DIFFUSE) > 0) {
			aiString Path;

			if (pMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &Path, NULL, NULL, NULL, NULL, NULL) == AI_SUCCESS) {
				
				std::string FullPath = "resources//";
				FullPath = FullPath + Path.data;
				FullPath[FullPath.size() - 3] = 'd';
				FullPath[FullPath.size() - 2] = 'd';
				FullPath[FullPath.size() - 1] = 's';
				ResourcesView.push_back(CShaderResourceView(FullPath));
				
			}
		}

	}
	return true;
}

bool CMeshManager::init()
{
	return false;
}

void CMeshManager::render(CInterfaceDevice* DeviceContext, RenderBuffers SB)
{
	CBChangesEveryFrame cb;
	XMFLOAT4 g_vMeshColor(1.0f, 1.0f, 1.0f, 1.0f);
	static float t = 0.0f;
	t += (float)XM_PI * 0.000125f;

	for (unsigned int i = 0; i < meshes.size(); i++)
	{
		t = (i & 1) ? -t : t;
		meshes[i].setPosition(XMMatrixRotationY(t*i));

		cb.vMeshColor = g_vMeshColor;
		cb.mWorld = XMMatrixTranspose(meshes[i].getPosition());
		UINT stride = sizeof(SimpleVertex);
		UINT offset = 0;

		DeviceContext->VSSetShader(*SB.VS->getVertexShader(), NULL, 0);
		DeviceContext->VSSetConstantBuffers(0, 1, SB.NCh->getBuffer());
		DeviceContext->VSSetConstantBuffers(1, 1, SB.ChR->getBuffer());
		DeviceContext->VSSetConstantBuffers(2, 1, SB.ChEF->getBuffer());
		DeviceContext->PSSetShader(*SB.PS->getPixelShader(), NULL, 0);
		DeviceContext->PSSetConstantBuffers(2, 1, SB.ChEF->getBuffer());
		DeviceContext->PSSetShaderResources(0, 1, ResourcesView[meshes[i].getMatIndx()].getTextureRV());

		DeviceContext->UpdateSubresource(
			*SB.ChEF->getBuffer(),
			0, 
			NULL,
			&cb,
			0, 
			0);
		DeviceContext->IASetVertexBuffers(
			0,
			1,
			meshes[i].getVertexBuffer()->getBuffer(), 
			&stride,
			&offset);
		DeviceContext->IASetIndexBuffer(
			*meshes[i].getIndexBuffer()->getBuffer(),
			DXGI_FORMAT_R16_UINT,
			0);
		DeviceContext->PSSetSamplers(0, 1, SB.SS->getSamplerLinear());
		DeviceContext->DrawIndexed(meshes[i].getNumI()*3, 0, 0);
		t = (i & 1) ? -t : t;
	}
}

void CMeshManager::render()
{
}

void CMeshManager::update()
{
	
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
