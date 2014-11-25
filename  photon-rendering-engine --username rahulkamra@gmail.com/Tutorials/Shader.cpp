#include "Shader.h"
#include <Common\Materials\MaterialsManager.h>
#include <Common\Materials\MaterialsList.h>


Shader::Shader(std::string fileName)
{
	shaderId = MaterialsManager::getMaterial(fileName);
}


Shader::~Shader()
{
}


void Shader::addTextureUniform(std::string name, GLuint samplerId)
{
	Texture* texture = GetTexture(name);
	texture->bind(samplerId);
}
void Shader::addMat4(std::string name, glm::mat4 matrix)
{
	GLint location = glGetUniformLocation(getShaderId(), name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
}
void Shader::addVec3(std::string name, glm::vec3 vector)
{
	GLuint location = glGetUniformLocation(getShaderId(), name.c_str());
	glUniform3fv(location, 1, &vector[0]);
}
void Shader::addFloat(std::string name, float value)
{
	GLuint location = glGetUniformLocation(getShaderId(), name.c_str());
	glUniform1f(location, value);
}

GLuint Shader::getShaderId()
{
	return shaderId;
}

void Shader::bind()
{
	glUseProgram(shaderId);
}
inline void Shader::AddTexture(const std::string& name, Texture* value)
{
	m_textureMap.insert(std::pair<std::string, Texture*>(name, value));
}

inline Texture* Shader::GetTexture(const std::string& name) const
{
	std::map<std::string, Texture*>::const_iterator it = m_textureMap.find(name);
	if (it != m_textureMap.end())
		return it->second;

	return 0;
}