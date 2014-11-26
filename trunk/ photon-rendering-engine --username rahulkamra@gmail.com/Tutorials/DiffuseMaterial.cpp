#include <DiffuseMaterial.h>
#include "Common\Materials\ShaderLoader.h"
#include "Common\Materials\MaterialsList.h"
#include "Common\Lights\Lights.h"
#include "Electron.h"
#include "Camera.h"
#include <Shader.h>

Texture* DiffuseMaterial::DEFAULT_DIFFUSE_TEXTURE = NULL;

void DiffuseMaterial::bind()
{
	Material::bind();
}

DiffuseMaterial::DiffuseMaterial(Texture* diffuseTexture, float specularPower, float specularIntensity)
{
	if (DiffuseMaterial::DEFAULT_DIFFUSE_TEXTURE == NULL)
	{
		TextureData* textureData = new TextureData("res/textures/black.png");
		textureData->load();
		DiffuseMaterial::DEFAULT_DIFFUSE_TEXTURE = new Texture(textureData);
	}

	
	if (diffuseTexture == NULL)
	{
		this->diffuseTexture = DiffuseMaterial::DEFAULT_DIFFUSE_TEXTURE;
	}
	else
	{
		this->diffuseTexture = diffuseTexture;
	}

	this->specularPower = specularPower;
	this->specularIntensity = specularIntensity;

	this->shader = new Shader(MaterialsList::DIFFUSE_MATERIAL);
	this->AddTexture("diffuse", diffuseTexture);
	

}
void DiffuseMaterial::updateUniforms(Transform transform, Shader* shader)
{
	this->shader->addTexture("diffuse", this->diffuseTexture);
	Material::updateUniforms(transform, shader);
	
}


void DiffuseMaterial::updateLightUniforms()
{
	if (Electron::activeLight)
	{
		Electron::activeLight->shader->addFloat("specularPower", specularPower);
		Electron::activeLight->shader->addFloat("specularIntensity", specularIntensity);
		Electron::activeLight->shader->addVec3("cameraWorld", Camera::getCamera()->transform.getPosition());
	}
}