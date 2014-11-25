#pragma once
#include <iostream>
#include <Common\GameObj\Transform.h>

class Shader;
class Material
{
private:
	
public:
	Material();
	~Material();

	Shader* shader;
	void virtual addUniforms(Transform transform, Shader* shader);
	virtual void bind();

};


