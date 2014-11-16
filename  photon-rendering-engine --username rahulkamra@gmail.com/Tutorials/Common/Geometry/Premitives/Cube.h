#pragma once


class Cube : public Mesh
{

public:

	Cube() :Mesh(ShapeGenerator::makeCube())
	{

	}

	~Cube()
	{
		this->cleanup();
	}

};

