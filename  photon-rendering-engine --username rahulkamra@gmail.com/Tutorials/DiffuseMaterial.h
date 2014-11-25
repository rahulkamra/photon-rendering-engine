#pragma once
#include "Common\Materials\Material.h"

class DiffuseMaterial : public Material
{
private:
	static Texture* DEFAULT_DIFFUSE_TEXTURE;
	Texture* diffuseTexture;
public:
	DiffuseMaterial(Texture* diffuseTexture = NULL);
	void addUniforms(Transform transform, Shader* shader);
	void bind();

};
