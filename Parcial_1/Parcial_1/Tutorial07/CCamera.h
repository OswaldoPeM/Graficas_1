#pragma once
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>
/*definicion de vista ortografica https://en.wikipedia.org/wiki/Orthographic_projection , 
https://computergraphics.stackexchange.com/questions/2383/whats-the-difference-between-orthographic-and-perspective-projection ,
https://people.cs.clemson.edu/~dhouse/courses/405/notes/projections.pdf */
typedef enum ProjectionType {
	ORTOGRAPHIC,
	PERSPECTIVE
};


class CCamera
{
	float magnitude = 0.3f;
	XMVECTOR Eye = XMVectorSet(0.0f, 1.0f, -6.0f, 0.0f);
	XMVECTOR LookAt = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR Up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR Front = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	XMVECTOR Right = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	ProjectionType projectionType;
	XMMATRIX projection;

public:

	XMVECTOR* getEye();
	XMVECTOR* getLookAt();
	XMVECTOR* getUp();
	XMVECTOR* getFront();
	XMVECTOR* getRight();

	void setEye(XMVECTOR* vec);
	void setLookAt(XMVECTOR* vec);
	void setUp(XMVECTOR* vec);

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void moveForward();
	void moveBack();

	bool init();
	void render();
	void update();
	void destroy();

	CCamera();
	~CCamera();
};

