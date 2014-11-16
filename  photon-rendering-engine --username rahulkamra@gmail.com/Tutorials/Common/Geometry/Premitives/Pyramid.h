#pragma once

class Pyramid : public Mesh
{

public:

	Pyramid() :Mesh(ShapeGenerator::makePyramid())
	{
	}

	~Pyramid()
	{
		this->cleanup();

	}

};

