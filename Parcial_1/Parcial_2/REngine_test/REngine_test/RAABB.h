/********************************************************************/
/**
* @LC     16/10/2019
* @file   RAABB.h
* @Author Oswaldo Perez Macias
* @date   16/10/2019
* @brief  RAABB.h class definition
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

#include "RComponent.h"
#include"requerimientos.h"


class RAABB :
	public RComponent
{
	/**
	  **array of vertex that represents a box.
	  *[0]Back	Top		Left
	  *[1]Back	Top		Right 
	  *[2]Back	Bottom	Left 
	  *[3]Back	Bottom	Right
	  *[4]Front	Top		Left 
	  *[5]Front	Top		Right
	  *[6]Front	Bottom	Left
	  *[7]Front	Bottom	Right 
	*/
	glm::vec4 m_vertex[8];
public:

	bool init();
	void render();
	void update();
	void destroy();

	RAABB(glm::vec4 &max, glm::vec4 &min);
	RAABB();
	~RAABB();
};

