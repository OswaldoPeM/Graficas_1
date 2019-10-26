#pragma once
#include"dependences/INCLUDES/glmLib/glm.hpp"
#include"dependences/INCLUDES/glmLib/gtc/matrix_transform.hpp"
#include "dependences/INCLUDES/glmLib/gtc/type_ptr.hpp"

namespace RMath{

	/*
	glm::mat4 RMatrixLookAtLH(glm::vec3 EYE, glm::vec3 LOOKAT, glm::vec3 UP) {

		glm::mat4 MATRIX;
		glm::vec3 X, Y, Z;

		Z = EYE - LOOKAT;
		Z = glm::normalize(Z);
		Y = UP;

		X = glm::cross(Y, Z);
		Y = glm::cross(Z, X);

		X = glm::normalize(Z);
		Y = glm::normalize(Y);

		MATRIX[0][0] = X.x;
		MATRIX[1][0] = X.y;
		MATRIX[2][0] = X.z;
		MATRIX[3][0] = glm::dot(-X, EYE);
		MATRIX[0][1] = Y.x;
		MATRIX[1][1] = Y.y;
		MATRIX[2][1] = Y.z;
		MATRIX[3][1] = glm::dot(-Y, EYE);
		MATRIX[0][2] = Z.x;
		MATRIX[1][2] = Z.y;
		MATRIX[2][2] = Z.z;
		MATRIX[3][2] = glm::dot(-Z, EYE);
		MATRIX[0][3] = 0;
		MATRIX[1][3] = 0;
		MATRIX[2][3] = 0;
		MATRIX[3][3] = 1.0f;

		return MATRIX;
	}
	*/
	///*glm::mat4 RMatrixPerspectiveFoV
	//(
	//	float FovAngleY,
	//	float AspectRatio,
	//	float NearZ,
	//	float FarZ
	//) 
	//{
	//	glm::mat4  *to_return;
	//	float tan_half_angle;


	//	tan_half_angle = tan(angle / 2);
	//	mat_set(to_return, 1, 1, 1 / (ratio * tan_half_angle));
	//	mat_set(to_return, 2, 2, 1 / (tan_half_angle));
	//	mat_set(to_return, 3, 3, -(far + near) / (far - near));
	//	mat_set(to_return, 4, 3, -1);
	//	mat_set(to_return, 3, 4, -(2 * far * near) / (far - near));
	//	return (to_return);
	//	return M;
	//}*/
}
namespace Rformat {
	//encontrar manera luego
	std::wstring s2ws(const std::string& s) {
		int len;
		int slength = (int)s.length() + 1;
		//len = MultiByteToWideChar(0, 0, s.c_str(), slength, 0, 0);
		wchar_t* buf = new wchar_t[len];
		//MultiByteToWideChar(0, 0, s.c_str(), slength, buf, len);
		std::wstring r(buf);
		delete[] buf;
		return r;
	}
}