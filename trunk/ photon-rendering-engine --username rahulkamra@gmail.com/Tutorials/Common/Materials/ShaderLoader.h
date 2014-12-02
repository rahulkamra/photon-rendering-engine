#pragma once
#include <stdio.h>
#include <iostream>
#include <GL/glew.h>
#include <map>
#include <GL\glut.h>
#include <ShaderData.h>

using namespace std;


class ShaderLoader
{
public:
	ShaderLoader();
	~ShaderLoader();
	
	
	static ShaderData* getMaterial(const string name);
private :
	static map<const string, ShaderData*> materialMap;
	static GLuint compileShader(const string vertexFilePath, const string fragmentFilePath);
	static std::string LoadShader(const std::string& filePath);
	static void AddShader(GLuint shaderProgram, const string& filePath, GLenum shaderType);
	static void AddShaderOfType(GLuint shaderProgram , const string* filePath, GLenum shaderType);

	static void LogShaderObjects(GLuint shaderProgram , const string fileName);
	static void registerMaterial(const string name);
};

