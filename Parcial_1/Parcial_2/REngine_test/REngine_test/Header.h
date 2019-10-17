#pragma once

#define DX



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
	*Math library
*/
#include"dependences/INCLUDES/glmLib/glm.hpp"

/**
	*Individual Includes by api
 */
#ifdef DX
	#include <d3d11.h>
	//#include <d3dx11.h>
	#include <d3dcompiler.h>
	//#include <xnamath.h>
	#include"dependences/ImGuiDirectX/imgui.h"
	#include "dependences/ImGuiDirectX/imgui_impl_win32.h"
	#include "dependences/ImGuiDirectX/imgui_impl_dx11.h"
#elif GL
	#include"dependences/INCLUDES/freeglut/include/GL/freeglut.h"
	#include"dependences/INCLUDES/glew-1.11.0/include/GL/glew.h"

#endif // DX

