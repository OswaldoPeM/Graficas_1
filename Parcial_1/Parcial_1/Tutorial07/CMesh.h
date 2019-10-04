#pragma once

#include"CBuffer.h"
#include"CDevice.h"
#include"CVertexShader.h"
#include"CPixelShader.h"
#include"CSamplerState.h"

#include"CInterfaceDevice.h"
#include"stb_image.h"
#include"dependences/Assimp/include/assimp/scene.h"
#include"dependences/Assimp/include/assimp/ai_assert.h"
#include"dependences/Assimp/include/assimp/cimport.h"
#include"dependences/Assimp/include/assimp/postprocess.h"
#include"dependences/Assimp/include/assimp/Importer.hpp"

class CMesh
{
	
	CBuffer VertexBuffer;
	CBuffer IndexBuffer;
	unsigned int numVertex, numIndex;
	XMMATRIX Position;
	unsigned int materialIndex;
	SimpleVertex *vertices = NULL;
	WORD *indices = NULL;

public:
	
	CBuffer* getVertexBuffer();
	CBuffer* getIndexBuffer();
	unsigned int getNumV();
	unsigned int getNumI();
	unsigned int getMatIndx();
	XMMATRIX getPosition();

	void setPosition(XMMATRIX pos);

	bool init();
	void render();
	void update();
	void destroy();


	CMesh();
	CMesh(aiMesh* mesh);
	~CMesh();
};

