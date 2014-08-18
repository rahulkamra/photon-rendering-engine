#pragma once
#include "Common\GameObj\GameObj.h";
#include <Utils\ColorUtils.h>
#include <Common\Geometry\Mesh.h>
class Plane : public Mesh
{

public:
	Plane(int dimensions = 10) :Mesh(ShapeGenerator::makePlane(dimensions))
	{
		
	}

	~Plane()
	{
		meshData->cleanup();
	}
};