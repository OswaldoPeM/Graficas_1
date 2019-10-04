#include "CMesh.h"



CMesh::CMesh()
{
}

CMesh::CMesh(aiMesh * mesh)
{
	materialIndex = mesh->mMaterialIndex;
	Position = XMMatrixIdentity();
	numVertex = mesh->mNumVertices;
	numIndex = mesh->mNumFaces;
	vertices=(SimpleVertex*)malloc(mesh->mNumVertices * sizeof(SimpleVertex));
	indices = (WORD*)malloc(mesh->mNumFaces * 3 * sizeof(WORD));

	for (int i = 0; i < mesh->mNumVertices; i++)
	{
		vertices[i] = {
			XMFLOAT4(
				mesh->mVertices[i].x,
				 mesh->mVertices[i].y,
				 mesh->mVertices[i].z,
				 1),
				XMFLOAT2(
				 (float)mesh->mTextureCoords[0][i].x ,
				 (float)mesh->mTextureCoords[0][i].y )
		};
	}
	for (int i = 0, j = 0; i < mesh->mNumFaces; i++)
	{
		indices[j++] = mesh->mFaces[i].mIndices[0];
		indices[j++] = mesh->mFaces[i].mIndices[1];
		indices[j++] = mesh->mFaces[i].mIndices[2];
	}
	VertexBuffer.init(mesh->mNumVertices, VERTEX, vertices);
	IndexBuffer.init(mesh->mNumFaces * 3, INDEX, indices);
}


CMesh::~CMesh()
{
}

CBuffer * CMesh::getVertexBuffer()
{
	return &VertexBuffer;
}

CBuffer * CMesh::getIndexBuffer()
{
	return &IndexBuffer;
}

unsigned int CMesh::getNumV()
{
	return numVertex;
}

unsigned int CMesh::getNumI()
{
	return numIndex;
}

unsigned int CMesh::getMatIndx()
{
	return materialIndex;
}

XMMATRIX  CMesh::getPosition()
{
	return Position;
}

void CMesh::setPosition(XMMATRIX pos)
{
	Position = pos;
}

bool CMesh::init()
{
	return false;
}

void CMesh::render()
{
}

void CMesh::update()
{
}

void CMesh::destroy()
{
	//if (VertexBuffer)VertexBuffer->destroy();
	//if (IndexBuffer) IndexBuffer->destroy();
	if (vertices)free(vertices);
	if (indices)free(indices);
}
