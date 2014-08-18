#pragma once

class Torus : public Mesh
{
public:
	Torus() :Mesh(ShapeGenerator::makeTorus())
	{
	}
	~Torus()
	{
		meshData->cleanup();
	}

private:

};
