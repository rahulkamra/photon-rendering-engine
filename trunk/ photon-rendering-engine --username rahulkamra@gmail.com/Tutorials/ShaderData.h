#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include <GL/glew.h>
#include <stdio.h>
#include <iostream>

class ShaderData
{
public:

	ShaderData(GLuint shaperProgram);
	~ShaderData();

private:
	 std::vector<std::string> uniforms;
	 std::vector<std::string> attributes;

	 void extractUniforms();
	 void extractAttributes();

	 void initialize();
	 GLuint shaderProgram;
	 void logShaderObjects(GLuint shaderProgram);

	 void updateUniforms();
};

