#pragma once
#include "CCamera.h"

class CCameraManager
{
	CCamera camera;
	bool isPerspective;


	XMMATRIX projection;
public:

	CCamera* getCamera();

	bool init();
	void render();
	void update();
	void destroy();

	CCameraManager();
	~CCameraManager();
};

