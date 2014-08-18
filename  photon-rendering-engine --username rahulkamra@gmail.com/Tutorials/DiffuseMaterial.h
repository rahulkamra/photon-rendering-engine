#pragma once
#include "Common\Materials\Material.h"

class DiffuseMaterial : public Material
{
	
	GLuint getShaderId();
	void virtual addUniforms(Transform transform);
	void bind();

};
