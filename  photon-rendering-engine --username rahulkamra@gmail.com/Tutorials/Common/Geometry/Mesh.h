#pragma once
#include <GL/glew.h>
#include <assert.h>
#include <ogldev_util.h>
#include <ogldev_types.h>
#include <vector>
#include <Common\Geometry\MeshData.h>
#include "Common\GameObj\Transform.h"
#include "Common\Materials\Material.h"
class Mesh
{


public:
	Mesh(vector<MeshData*> meshData);
	Mesh(MeshData* meshData);
	~Mesh();

	vector<MeshData*> meshData;
	void cleanup();
	void virtual draw(Transform modelToWorld);

};


class LineMesh :public Mesh
{
	
public:
	void virtual draw(Transform modelToWorld);
	LineMesh(MeshData* meshData);
};


