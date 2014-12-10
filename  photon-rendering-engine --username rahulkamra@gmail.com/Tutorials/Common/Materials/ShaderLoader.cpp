#include "ShaderLoader.h"
#include <vector>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <ogldev_util.h>
#include <fstream>
#include <Utils\StringUtils.h>

#define VERTEX_SHADER_PATH(shaderName) "Shaders/"+shaderName+".vs"
#define FRAGMENT_SHADER_PATH(shaderName) "Shaders/"+shaderName+".fs"
#define INCLUDE_SHADER_FILE_PATH(fileName) "Shaders/"+fileName

map<const string, ShaderData*> ShaderLoader::materialMap;

ShaderLoader::ShaderLoader()
{
}


ShaderLoader::~ShaderLoader()
{
}

void ShaderLoader::registerMaterial(const string name)
{
	string vertexShaderFileName = VERTEX_SHADER_PATH(name);
	string fragmentShaderFileName = FRAGMENT_SHADER_PATH(name);

	GLuint shaderProgram = compileShader(vertexShaderFileName, fragmentShaderFileName);

	materialMap[name] = new ShaderData(shaderProgram);

}
ShaderData* ShaderLoader::getMaterial(const string name)
{
	if (!materialMap[name])
		registerMaterial(name);

	return materialMap[name];
}


GLuint ShaderLoader::compileShader(const string vertexFilePath, const  string fragmentFilePath)
{
	GLuint shaderProgram = glCreateProgram();
	if (shaderProgram == 0) {
		fprintf(stderr, "Error creating shader program\n");
		exit(1);
	}
	AddShader(shaderProgram, vertexFilePath, GL_VERTEX_SHADER);
	AddShader(shaderProgram, fragmentFilePath, GL_FRAGMENT_SHADER);

	GLint Success = 0;
	GLchar ErrorLog[1024] = { 0 };
	glValidateProgram(shaderProgram);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &Success);

	if (Success == 0)
	{
		glGetProgramInfoLog(shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
		while (1);
		exit(1);
	}
	LogShaderObjects(shaderProgram,vertexFilePath);
	return shaderProgram;
}



void ShaderLoader::LogShaderObjects(GLuint shaderProgram, const string fileName)
{
	GLint count = 0;

	GLint numActiveAttribs = 0;
	GLint numActiveUniforms = 0;
	glGetProgramiv(shaderProgram, GL_ACTIVE_ATTRIBUTES, &numActiveAttribs);
	glGetProgramiv(shaderProgram, GL_ACTIVE_UNIFORMS, &numActiveUniforms);

	GLint maxAttribNameLength = 0;
	glGetProgramiv(shaderProgram, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxAttribNameLength);
	std::vector<GLchar> nameData(maxAttribNameLength);

	for (int attrib = 0; attrib < numActiveAttribs; ++attrib)
	{
		GLint arraySize = 0;
		GLenum type = 0;
		GLsizei actualLength = 0;
		glGetActiveAttrib(shaderProgram, attrib, nameData.size(), &actualLength, &arraySize, &type, &nameData[0]);
		std::string name((char*)&nameData[0], actualLength);

		//cout << name << "\n";
	}

	std::vector<GLchar> _nameData(256);
	for (int unif = 0; unif < numActiveUniforms; ++unif)
	{
		GLint arraySize = 0;
		GLenum type = 0;
		GLsizei actualLength = 0;
		glGetActiveUniform(shaderProgram, unif, _nameData.size(), &actualLength, &arraySize, &type, &_nameData[0]);
		std::string name((char*)&_nameData[0], actualLength);

		//cout << name << "\n";
	}
	//cout << "---End Shader --" << "  "<< fileName << "\n";
}


std::string ShaderLoader::LoadShader(const std::string& filePath)
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

void ShaderLoader::AddShader(GLuint shaderProgram, const string& filePath, GLenum shaderType)
{
	string shaderText = LoadShader(filePath.c_str());

	GLuint shaderObj = glCreateShader(shaderType);
	if (shaderObj == 0)
	{
		fprintf(stderr, "Error Creating Shader type %d", shaderType);
		exit(1);
	}

	const GLchar *p[1];
	p[0] = shaderText.c_str();

	GLint lenghts[1];
	lenghts[0] = strlen(shaderText.c_str());
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
