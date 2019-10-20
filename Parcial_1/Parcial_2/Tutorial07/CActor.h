#pragma once
#include"CComp.h"
#include<vector>
class CActor
{
	std::vector<CComp> componentes;
public:

	std::vector<CComp>* getComp();

	void addComp(CComp* comp);
	void destroyComp(int index);


	bool init();
	void render();
	void update();
	void destroy();

	CActor();
	~CActor();
};

