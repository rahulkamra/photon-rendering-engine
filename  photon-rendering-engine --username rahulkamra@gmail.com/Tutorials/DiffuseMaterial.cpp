#include <DiffuseMaterial.h>
#include "Common\Materials\MaterialsManager.h"
#include "Common\Materials\MaterialsList.h"
#include "Common\Lights\Lights.h"
#include "Electron.h"
#include <Shader.h>

Texture* DiffuseMaterial::DEFAULT_DIFFUSE_TEXTURE = NULL;

void DiffuseMaterial::bind()
{
	Material::bind();
}

DiffuseMaterial::DiffuseMaterial(Texture* diffuseTexture)
{
	if (DiffuseMaterial::DEFAULT_DIFFUSE_TEXTURE == NULL)
	{
		TextureData* textureData = new TextureData("res/textures/white.png");
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

	this->shader = new Shader(MaterialsList::DIFFUSE_MATERIAL_TEXTURE);
	this->AddTexture("diffuse", diffuseTexture);
	

}
void DiffuseMaterial::addUniforms(Transform transform, Shader* shader)
{
	this->shader->addTexture("diffuse", this->diffuseTexture);
	Material::addUniforms(transform,shader);
	
}