/********************************************************************/
/**
* @LC     16/10/2019
* @file   RActor.h
* @Author Oswaldo Perez Macias
* @date   16/10/2019
* @brief  RActor.h class definition
* @bug	  No known bugs.
*/
/********************************************************************/

/************************************************************************/
/* Header include files									                */
/************************************************************************/
#pragma once
/************************************************************************/
/* Header Class inclusion								                */
/************************************************************************/
#include<vector>
#include"requerimientos.h"
#include"RComponent.h"

class RActor
{

public:
	std::vector<RComponent*> m_componentes;
	void addComp(RComponent* comp);
	void destroyComp(int index);


	bool init();
	void render();
	void update();
	void destroy();
	RActor();
	~RActor();
};

