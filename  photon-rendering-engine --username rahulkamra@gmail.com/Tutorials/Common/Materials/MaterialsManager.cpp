#include "MaterialsManager.h"
#include <vector>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <ogldev_util.h>
#include <fstream>
#include <Utils\StringUtils.h>

#define VERTEX_SHADER_PATH(shaderName) "Shaders/"+shaderName+".vs"
#define FRAGMENT_SHADER_PATH(shaderName) "Shaders/"+shaderName+".fs"
#define INCLUDE_SHADER_FILE_PATH(fileName) "Shaders/"+fileName

map<const string, GLuint> MaterialsManager::materialMap;

MaterialsManager::MaterialsManager()
{
}


MaterialsManager::~MaterialsManager()
{
}

void MaterialsManager::registerMaterial(const string name)
{
	string vertexShaderFileName = VERTEX_SHADER_PATH(name);
	string fragmentShaderFileName = FRAGMENT_SHADER_PATH(name);

	GLuint shaderProgram = compileShader(vertexShaderFileName, fragmentShaderFileName);
	materialMap[name] = shaderProgram;

}
GLuint MaterialsManager::getMaterial(const string name)
{
	if (!materialMap[name])
		registerMaterial(name);

	return materialMap[name];
}


GLuint MaterialsManager::compileShader(const string vertexFilePath, const  string fragmentFilePath)
{
	GLuint shaderProgram = glCreateProgram();
	if (shaderProgram == 0) {
		fprintf(stderr, "Error creating shader program\n");
		exit(1);
	}

	string vs, fs;

	vs = LoadShader(vertexFilePath.c_str());
	fs = LoadShader(fragmentFilePath.c_str());

	/*if (!ReadFile(vertexFilePath.c_str(), vs))
	{
		while (1);
		exit(1);
	}

	if (!ReadFile(fragmentFilePath.c_str(), fs))
	{
		while (1);
		exit(1);
	}*/

	AddShader(shaderProgram, vs.c_str(), GL_VERTEX_SHADER);
	AddShader(shaderProgram, fs.c_str(), GL_FRAGMENT_SHADER);

	GLint Success = 0;
	GLchar ErrorLog[1024] = { 0 };

	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &Success);

	if (Success == 0)
	{
		glGetProgramInfoLog(shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
		while (1);
		exit(1);
	}

	glValidateProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &Success);

	if (Success == 0)
	{
		glGetProgramInfoLog(shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
		while (1);
		exit(1);
	}

	return shaderProgram;
}


std::string MaterialsManager::LoadShader(const std::string& filePath)
{
	std::ifstream file;
	file.open(filePath);

	std::string output;
	std::string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);

			if (line.find("#include") == std::string::npos)
				output.append(line + "\n");
			else
			{
				std::string includeFileName = StringUtils::Split(line, ' ')[1];
				includeFileName = includeFileName.substr(1, includeFileName.length() - 2);

				std::string toAppend = LoadShader(INCLUDE_SHADER_FILE_PATH(includeFileName));
				output.append(toAppend + "\n");
			}
		}
	}
	else
	{
		std::cerr << "Unable to load shader: " << filePath << std::endl;
	}

	return output;
}

void MaterialsManager::AddShader(GLuint shaderProgram, const char *shaderText, GLenum shaderType)
{
	GLuint shaderObj = glCreateShader(shaderType);
	if (shaderObj == 0)
	{
		fprintf(stderr, "Error Creating Shader type %d", shaderType);
		exit(1);
	}

	const GLchar *p[1];
	p[0] = shaderText;

	GLint lenghts[1];
	lenghts[0] = strlen(shaderText);
	glShaderSource(shaderObj, 1, p, lenghts);

	glCompileShader(shaderObj);

	GLint success;
	glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &success);

	if (!success) {
		GLchar InfoLog[1024];
		glGetShaderInfoLog(shaderObj, 1024, NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", shaderType, InfoLog);
		while (1);
	}

	glAttachShader(shaderProgram, shaderObj);
	glDeleteShader(shaderObj);
}
