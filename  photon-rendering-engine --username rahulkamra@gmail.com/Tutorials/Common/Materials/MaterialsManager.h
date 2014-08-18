#pragma once
#include <stdio.h>
#include <iostream>
#include <GL/glew.h>
#include <map>
#include <GL\glut.h>

using namespace std;


class MaterialsManager
{
public:
	MaterialsManager();
	~MaterialsManager();
	
	static void registerMaterial(const string name);
	static GLuint getMaterial(const string name);
private :
	static map<const string, GLuint> materialMap;
	static GLuint compileShader(const string vertexFilePath, const string fragmentFilePath);
	static std::string LoadShader(const std::string& filePath);
	static void AddShader(GLuint shaderProgram, const char *shaderText, GLenum shaderType);
};

