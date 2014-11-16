#include "Material.h"
#include "Camera.h"
#include "Electron.h"
#include "MaterialsManager.h"

Material::Material()
{
	
}


GLuint inline Material::getShaderId()
{
	return MaterialsManager::getMaterial(MaterialsList::AMBIENT_MATERIAL);
}

void inline Material::addTextureUniform(std::string name, GLuint samplerId)
{
	Texture* texture = GetTexture(name);
	texture->bind(samplerId);
}
void Material::addMat4(std::string name, glm::mat4 matrix)
{
	GLint location = glGetUniformLocation(getShaderId(), name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
}
void Material::addVec3(std::string name, glm::vec3 vector)
{
	GLuint location = glGetUniformLocation(getShaderId(), name.c_str());
	glUniform3fv(location, 1, &vector[0]);
}
void Material::addFloat(std::string name, float value)
{
	GLuint location = glGetUniformLocation(getShaderId(), name.c_str());
	glUniform1f(location, value);
}



void Material::addUniforms(Transform transform)
{
	glm::mat4 modelViewProjection = Camera::getCamera()->worldToProjection(transform.modelTransformtionMatrix());
	glm::mat4 model = transform.modelTransformtionMatrix();

	addMat4("mvp", modelViewProjection);
	addMat4("modelToWorld", model);
	addVec3("cameraWorld", Camera::getCamera()->position);
	addVec3("ambientLight", vec3(1.0f, 1.0f, 1.0f));
}
void Material::bind()
{
	glUseProgram(getShaderId());
}
Material::~Material()
{
}

AmbientMaterial::AmbientMaterial()
{
	TextureData* textureData = new TextureData("res/textures/black.png");
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