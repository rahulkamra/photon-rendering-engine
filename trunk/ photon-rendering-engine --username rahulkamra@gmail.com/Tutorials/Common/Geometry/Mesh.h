#pragma once
#include <GL/glew.h>
#include <assert.h>
#include <ogldev_util.h>
#include <ogldev_types.h>
#include <Common\Geometry\MeshData.h>
#include "Common\GameObj\Transform.h"
#include "Common\Materials\Material.h"
class Mesh
{


public:
	Mesh(MeshData* meshData);
	~Mesh();

	MeshData* meshData;
	void virtual draw(Transform modelToWorld, Material& material);

};


class LineMesh :public Mesh
{
	void virtual draw(Transform modelToWorld, Material& material);
};


