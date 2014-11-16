#pragma once
#include "Common\GameObj\GameObj.h";
#include <Utils\ColorUtils.h>
#include <Common\Geometry\Mesh.h>
class Plane : public Mesh
{

public:
	Plane(int dimensions = 10,glm::vec3 color = glm::vec3(0.2,0.2,0.2)) :Mesh(ShapeGenerator::makePlane(dimensions,color,false))
	{
		
	}

	~Plane()
	{
		this->cleanup();
	}
};