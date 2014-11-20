#pragma once
#include "Common\Materials\Material.h"

class DiffuseMaterial : public Material
{
	
	void virtual addUniforms(Transform transform);
	void bind();

};
