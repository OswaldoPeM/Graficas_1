#pragma once
#define DX 1
//#define GL 2



/**
	*Global Includes
*/

#include<vector>
/**
	*assimp
*/
#include"dependences/Assimp/include/assimp/scene.h"
#include"dependences/Assimp/include/assimp/ai_assert.h"
#include"dependences/Assimp/include/assimp/cimport.h"
#include"dependences/Assimp/include/assimp/postprocess.h"
#include"dependences/Assimp/include/assimp/Importer.hpp"


/**
	*Math library.
*/
#include"dependences/INCLUDES/glmLib/glm.hpp"

/**
	*Structures & enums.
 */
#include "structures.h"
#include "enumers.h"

/**
	*ImGui includes.
*/
#include"dependences/ImGui/imgui.h"
#include "dependences/ImGui/imgui_impl_win32.h"

 /**
	*Individual Includes by api.
 */

#ifdef DX 
#define UNICODE
	#include <d3d11.h>
	#include <d3dx11.h>
	#include <d3dcompiler.h>
	//#include <xnamath.h>
	#include "dependences/ImGui/imgui_impl_dx11.h"
#elif GL 
	#include"dependences/INCLUDES/freeglut/include/GL/freeglut.h"
	#include"dependences/INCLUDES/OpenGLRoot/GLEW/include/GL/glew.h"
	#include "dependences/ImGui/imgui_impl_opengl3.h"
#endif // DX



