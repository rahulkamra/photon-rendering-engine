#include <DiffuseMaterial.h>
#include "Common\Materials\ShaderLoader.h"
#include "Common\Materials\MaterialsList.h"
#include "Common\Lights\Lights.h"
#include "Electron.h"
#include "Camera.h"
#include <Shader.h>

Texture* DiffuseMaterial::DEFAULT_DIFFUSE_TEXTURE = NULL;

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
	this->AddTexture("diffuse", this->diffuseTexture);
	

}
void DiffuseMaterial::updateUniforms(Transform transform, Shader* shader)
{
	Material::updateUniforms(transform, shader);
	this->addFloat("specularPower", specularPower);
	this->addFloat("specularIntensity", specularIntensity);
}
