#pragma once

#include"CBuffer.h"
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
	XMMATRIX Position;
	unsigned int materialIndex;
	SimpleVertex *vertices = NULL;
	WORD *indices = NULL;

public:
	
	CBuffer* getVertexBuffer();
	CBuffer* getIndexBuffer();
	XMMATRIX* getPosition();

	bool init();
	void render();
	void update();
	void destroy();


	CMesh();
	CMesh(aiMesh* mesh);
	~CMesh();
};

