#pragma once
#include <fstream>
#include <sstream>
#include "RPixelShader.h"
#include "RVertexShader.h"
class RProgramShader
{
public:

	virtual void
		chargeShader
		(
			const char * vertex_file_path,
			const char * fragment_file_path
		) = 0;



	RProgramShader();
	~RProgramShader();
};

