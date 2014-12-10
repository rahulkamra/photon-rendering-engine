#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include <EMap.h>
#include <GL/glew.h>
#include <stdio.h>
#include <iostream>

class ShaderData
{
public:

	GLuint shaderProgram;
	std::vector<std::string> uniforms;

	std::vector<std::string> vec3Uniforms;
	std::vector<std::string> floatUniforms;
	std::vector<std::string> mat4Uniforms;
	std::vector<std::string> mat3Uniforms;
	std::vector<std::string> sampler2DUniforms;

	std::vector<std::string> attributes;
	int getUniformType(std::string uniformName);
	ShaderData(GLuint shaperProgram);
	~ShaderData();

private:
	EMap<std::string, int> uniformType;

	void extractUniforms();
	void extractAttributes();

	void initialize();
	void logShaderObjects();

	void addUniformType(std::string uniformName, int uniformType);


};

