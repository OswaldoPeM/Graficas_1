#pragma once
#include "CCamera.h"

class CCameraManager
{
	CCamera camera;

	bool isPerspective;
	
	float Near = 0.001f;
	float Far = 100.0f;
	float FoV = XM_PIDIV4;
	float AR;
	XMMATRIX projection;

public:

	CCamera* getCamera();
	XMMATRIX getProjectionMatrix();
	XMMATRIX getViewMatrix();

	void setProjectionMatrix(UINT width, UINT height);
	void swichProjection(UINT width, UINT height);
	void actLookAt();

	void move(XMFLOAT3* mat);
	void rotate(POINT* vec);

	bool init();
	void render();
	void update();
	void destroy();

	CCameraManager();
	~CCameraManager();
};

