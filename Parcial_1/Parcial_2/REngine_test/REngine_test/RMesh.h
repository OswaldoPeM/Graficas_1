#pragma once
#include "requerimientos.h"

class RBuffer;
class RMesh
{
	RBuffer* VertexBuffer;
	RBuffer* IndexBuffer;
	unsigned int numVertex;
	unsigned int numIndex;
	SimpleVertex* vertices= NULL;
	unsigned int* indices = NULL;
public:
	RMesh();
	~RMesh();
};

