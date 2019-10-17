#pragma once
#include "CComp.h"
class AABB :
	public CComp
{

	XMFLOAT4 maximo;
	XMFLOAT4 minimo;
public:
	void setMaxX(FLOAT &x);
	void setMaxY(FLOAT &y);
	void setMaxZ(FLOAT &z);
	void setMinX(FLOAT &x);
	void setMinY(FLOAT &y);
	void setMinZ(FLOAT &z);

	bool init();
	bool init(XMFLOAT4 &max, XMFLOAT4 &min);
	void render();
	void update();
	void destroy();

	AABB();
	~AABB();
};

