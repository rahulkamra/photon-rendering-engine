#pragma once
#include "Common\GameObj\GameComponent.h"
#include "Electron.h"
class Material;
class MeshRenderingComponent : public GameComponent
{

private:
	Mesh* mesh;
	Material* material;

public:
	int phase = Electron::PHASE_FORWARD_RENDERING;
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
		
		Electron::addRenderingComponent(this);
	}

	virtual void draw()
	{
		material->bind();
		material->addUniforms(parent->transform);
		mesh->draw(parent->transform, *material);
	}

};



class WidgetRenderingComponent : public MeshRenderingComponent
{
public:
	WidgetRenderingComponent(Mesh* mesh) :MeshRenderingComponent(mesh,new Material())
	{
		phase = Electron::PHASE_WIDGETS_RENDERING;
	}
};