#pragma once

class Triangle : public Mesh
{

public:
	Triangle() :Mesh(ShapeGenerator::makeTriangle())
	{

	}
	~Triangle()
	{
		meshData->cleanup();

	}
};
