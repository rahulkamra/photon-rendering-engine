#pragma once
#include "Common\GameObj\GameComponent.h"
class Material;
class MeshRenderingComponent : public GameComponent
{

private:
	Mesh* mesh;
	Material* material;

public:
	MeshRenderingComponent(Mesh* mesh, Material* material)
	{
		this->mesh = mesh;
		this->material = material;
	}


	~MeshRenderingComponent()
	{
		//We need mesh data and keep a track of how many objects are using mesh data and then delete the mesh
	}


	virtual void render()
	{
		material->bind();
		material->addUniforms(parent->transform);
		mesh->draw(parent->transform, *material);
	}
};