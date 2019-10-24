#include "RProgramShader.h"
#include "RRenderManager.h"



void RProgramShader::chargeShader(const char * vertex_file_path, const char * fragment_file_path)
{

#ifdef DX
	ID3D10Blob * pErroMsg = nullptr;
	if (pVSBlob != nullptr)
	{
		pVSBlob->Release();
	}
#elif OPENGL
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
#endif // DX
	// Create the shaders
	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if (VertexShaderStream.is_open()) {
		std::stringstream ss;
		ss << VertexShaderStream.rdbuf();
		VertexShaderCode = ss.str();
		//cout << VertexShaderCode << "\n";
		VertexShaderStream.close();
	}
	else {
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
		system("pause");
		return;
	}
	auto	vertexShader = VertexShaderCode;
#if DX
	HRESULT hr = D3DCompile(
		vertexShader.c_str(),
		vertexShader.length(),
		nullptr,
		nullptr,
		nullptr,
		"VS", "vs_4_0",
		D3DCOMPILE_ENABLE_STRICTNESS, 0,
		&pVSBlob,
		&pErroMsg);
	if (pErroMsg)
	{
		SIZE_T msgSize = pErroMsg->GetBufferSize();
		std::string msg;
		msg.resize(msgSize);
		memcpy(&msg[0], pErroMsg->GetBufferPointer(), msgSize);
		pErroMsg->Release();
		OutputDebugStringA(msg.c_str());
	}
	if (FAILED(hr))
	{	
	}
	RRenderManager::CreateVertexShader(*this, RRenderManager::InstancePtr()->getDevice());


	//PIXEL SHADER	
	pErroMsg = nullptr;
	if (pVSBlob != nullptr)
	{
		pVSBlob->Release();
	}
#endif // DX
	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if (FragmentShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << FragmentShaderStream.rdbuf();
		FragmentShaderCode = sstr.str();
		FragmentShaderStream.close();
	}
	else {
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", fragment_file_path);
		getchar();
		return;
	}
#ifdef DX
	auto FrameShader = FragmentShaderCode;
	//Microsoft::WRL::ComPtr<ID3DBlob> blob;
	hr = D3DCompile(
		FragmentShaderCode.c_str(),
		FragmentShaderCode.length(),
		nullptr,
		nullptr,
		nullptr,
		"PS", "ps_4_0",
		D3DCOMPILE_ENABLE_STRICTNESS, 0,
		&pVSBlob,
		&pErroMsg);
	if (pErroMsg)
	{
		SIZE_T msgSize = pErroMsg->GetBufferSize();
		std::string msg;
		msg.resize(msgSize);
		memcpy(&msg[0], pErroMsg->GetBufferPointer(), msgSize);
		pErroMsg->Release();
		OutputDebugStringA(msg.c_str());
	}
	if (!hr)
	{
		std::cout << "can't compile pixel shader\n";
	}
	RRenderManager::CreatePixelShader(*this, RRenderManager::InstancePtr()->getDevice());
	
#elif OPENGL
	GLint Result = GL_FALSE;
	int InfoLogLength;
	// Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
	glCompileShader(VertexShaderID);
	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0)
	{
		std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}
	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(FragmentShaderID);
	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0)
	{
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}
	// Link the program
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);
	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0)
	{
		std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}
	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);
	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);
	programShader.ID = ProgramID;
#endif // DX
}

RProgramShader::RProgramShader()
{
}


RProgramShader::~RProgramShader()
{
}
