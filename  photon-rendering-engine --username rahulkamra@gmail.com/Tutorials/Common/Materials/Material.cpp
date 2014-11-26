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
	glm::mat4 modelViewProjection = Camera::getCamera()->worldToProjection(transform.modelTransformtionMatrix());
	glm::mat4 model = transform.modelTransformtionMatrix();
	shader->addMat4("mvp", modelViewProjection);
	shader->addMat4("modelToWorld", model);
	shader->addVec3("ambientLight", Electron::ambientLight);
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