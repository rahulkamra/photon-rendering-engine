#pragma once
#include <Utils\ColorUtils.h>
#include "Common\Geometry\Premitives\TeapotData.h"

class TeaPot : public Mesh
{

public:
	TeaPot(int tesselation = 10, const glm::mat4& lidTransform = mat4()) :Mesh(ShapeGenerator::makeTeapot(tesselation, lidTransform))
	{
		
	}
	~TeaPot()
	{
		meshData->cleanup();
	}
};
