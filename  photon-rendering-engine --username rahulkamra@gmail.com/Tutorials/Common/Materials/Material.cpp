#include "Material.h"
#include "Camera.h"
#include "Electron.h"
#include "ShaderLoader.h"
#include <Shader.h>

Material::Material()
{
	this->shader = new Shader(MaterialsList::DEFAULT);
}

void Material::updateUniforms(Transform transform, Shader* shader)
{
}

void Material::addFloat(std::string name, float value)
{
	floatMap.insert(std::pair<std::string, float>(name, value));
}
void Material::addVec3(std::string name, glm::vec3 value)
{
	vec3Map.insert(std::pair<std::string, glm::vec3>(name, value));
}

float Material::getFloat(std::string name)
{
	return floatMap[name];
}

glm::vec3 Material::getVec3(std::string name)
{
	return vec3Map[name];
}


void Material::AddTexture(const std::string& name, Texture* value)
{
	m_textureMap.insert(std::pair<std::string, Texture*>(name, value));
}

Texture* Material::GetTexture(const std::string& name)
{
	std::map<std::string, Texture*>::const_iterator it = m_textureMap.find(name);
	if (it != m_textureMap.end())
		return it->second;

	return 0;
}


void Material::bind()
{
	shader->bind();
}
Material::~Material()
{
}