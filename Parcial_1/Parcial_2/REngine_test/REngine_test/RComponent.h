/********************************************************************/
/**
* @LC     16/10/2019
* @file   RComponent.h
* @Author Oswaldo Perez Macias
* @date   16/10/2019
* @brief  RComponent.h class definition
* @bug	  No known bugs.
*/
/********************************************************************/

/************************************************************************/
/* Header include files									                */
/************************************************************************/
#pragma once
#include"requerimientos.h"

enum ComponentType
{
	Transform,
	Model,
	AABB,
	Sphere
};
/************************************************************************/
/* Header Class inclusion								                */
/************************************************************************/
class RComponent 
{
	int m_index;
public:
	virtual int getIndex() = 0;
	virtual void setIndex(int index) = 0;

	virtual bool init() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void destroy() = 0;

	RComponent();
	~RComponent();
};

