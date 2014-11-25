#include "Material.h"
#include "Camera.h"
#include "Electron.h"
#include "MaterialsManager.h"
#include <Shader.h>

Material::Material()
{
	this->shader = new Shader(MaterialsList::DIFFUSE_MATERIAL);
}

void Material::addUniforms(Transform transform , Shader* shader)
{
	glm::mat4 modelViewProjection = Camera::getCamera()->worldToProjection(transform.modelTransformtionMatrix());
	glm::mat4 model = transform.modelTransformtionMatrix();
	shader->addMat4("mvp", modelViewProjection);
	shader->addMat4("modelToWorld", model);
	shader->addVec3("cameraWorld", Camera::getCamera()->position);
	shader->addVec3("ambientLight", Electron::ambientLight);
	//shader->addTextureUniform("diffuse", 0);

	//typeid(Electron::ambientLight).
	
	//if (typedef(modelViewProjection) == glm::mat4)
	//{

	//}

	//addTextureUniform("diffuse", 0);
}
void Material::bind()
{
	shader->bind();
}
Material::~Material()
{
}

/*
AmbientMaterial::AmbientMaterial()
{
	TextureData* textureData = new TextureData("res/models/phoenix.pcx");
	textureData->load();
	Texture* texture = new Texture(textureData);
	this->AddTexture("diffuse", texture);
}
AmbientMaterial::AmbientMaterial(Texture* diffuseTexture)
{
	this->AddTexture("diffuse", diffuseTexture);
}



void AmbientMaterial::addUniforms(Transform transform)
{
	glm::mat4 modelViewProjection = Camera::getCamera()->worldToProjection(transform.modelTransformtionMatrix());
	glm::mat4 model = transform.modelTransformtionMatrix();

	addMat4("mvp", modelViewProjection);
	addMat4("modelToWorld", model);
	addVec3("cameraWorld", Camera::getCamera()->position);
	addVec3("ambientLight", Electron::ambientLight);
	addTextureUniform("diffuse", 0);

}
*/