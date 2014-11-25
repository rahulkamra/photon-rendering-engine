#include "Material.h"
#include "Camera.h"
#include "Electron.h"
#include "MaterialsManager.h"
#include <Shader.h>

Material::Material()
{
	this->shader = new Shader(MaterialsList::DEFAULT);
}

void Material::addUniforms(Transform transform , Shader* shader)
{
	glm::mat4 modelViewProjection = Camera::getCamera()->worldToProjection(transform.modelTransformtionMatrix());
	glm::mat4 model = transform.modelTransformtionMatrix();
	shader->addMat4("mvp", modelViewProjection);
	shader->addMat4("modelToWorld", model);
	shader->addVec3("cameraWorld", Camera::getCamera()->position);
	shader->addVec3("ambientLight", Electron::ambientLight);
	//addTextureUniform("diffuse", 0);
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