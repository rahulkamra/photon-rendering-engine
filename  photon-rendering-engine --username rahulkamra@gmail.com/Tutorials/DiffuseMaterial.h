#pragma once
#include "Common\Materials\Material.h"

class DiffuseMaterial : public Material
{
private:
	static Texture* DEFAULT_DIFFUSE_TEXTURE;
	Texture* diffuseTexture;
	float specularPower;
	float specularIntensity;
public:
	DiffuseMaterial(Texture* diffuseTexture = NULL,float specularPower = 8.0,float specularIntensity = 1.0);
	void updateUniforms(Transform transform, Shader* shader);
	void bind();

};
