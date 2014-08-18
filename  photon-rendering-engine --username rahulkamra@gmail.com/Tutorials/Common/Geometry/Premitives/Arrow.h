#pragma once
class Arrow : public Mesh
{

public:
	Arrow() :Mesh(ShapeGenerator::makeArrow())
	{
	}
	~Arrow()
	{
		meshData->cleanup();
	}

};
