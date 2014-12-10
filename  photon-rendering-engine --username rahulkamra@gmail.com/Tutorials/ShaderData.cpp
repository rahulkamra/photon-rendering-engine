#include "ShaderData.h"


ShaderData::ShaderData(GLuint shaderProgram)
{
	this->shaderProgram = shaderProgram;
	initialize();
}


ShaderData::~ShaderData()
{
}


void ShaderData::extractUniforms()
{
	GLint numActiveUniforms = 0;
	glGetProgramiv(shaderProgram, GL_ACTIVE_UNIFORMS, &numActiveUniforms);

	std::vector<GLchar> nameData(256);
	for (int unif = 0; unif < numActiveUniforms; ++unif)
	{
		GLint arraySize = 0;
		GLenum type = 0;
		GLsizei actualLength = 0;
		glGetActiveUniform(shaderProgram, unif, nameData.size(), &actualLength, &arraySize, &type, &nameData[0]);
		std::string name((char*)&nameData[0], actualLength);

		addUniformType(name, type);

		if (type == (int)GL_FLOAT)
		{
			floatUniforms.push_back(name);
			
		}
		else if (type == (int)GL_FLOAT_VEC3)
		{
			vec3Uniforms.push_back(name);
		}
		else if (type == (int)GL_FLOAT_MAT3)
		{
			mat4Uniforms.push_back(name);
		}
		else if (type == (int)GL_FLOAT_MAT4)
		{
			mat3Uniforms.push_back(name);
		}
		else if (type == (int)GL_SAMPLER_2D)
		{
			sampler2DUniforms.push_back(name);
		}
		else
		{
			std::cout << "undefined type " << type  <<  " with name : " << name <<  "\n";
		}

		uniforms.push_back(name);
	}
}


void ShaderData::addUniformType(std::string name, int type)
{
	uniformType.set(name, type);
}


int ShaderData::getUniformType(std::string uniformName)
{
	boost::optional<int> value =  uniformType.get(uniformName);
	if (value)
	{
		return *value;
	}
	else
	{
		return 0;
	}
}

void ShaderData::extractAttributes()
{
	GLint numActiveAttribs = 0;
	glGetProgramiv(shaderProgram, GL_ACTIVE_ATTRIBUTES, &numActiveAttribs);
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
		attributes.push_back(name);
	}
}

void ShaderData::logShaderObjects()
{
	for (int count = 0; count < uniforms.size(); ++count)
	{
		//std::cout << "Uniform Found "  << uniforms.at(count) << "\n";
	}
}

void ShaderData::initialize()
{
	extractUniforms();
	extractAttributes();
	logShaderObjects();
}



