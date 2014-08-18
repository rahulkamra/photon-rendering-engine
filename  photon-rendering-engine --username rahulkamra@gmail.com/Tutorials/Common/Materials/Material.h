#pragma once
#include <iostream>
#include <GL\glew.h>
#include <glm\gtc\matrix_transform.hpp>
#include <Common\GameObj\Transform.h>

class Material
{
public:
	Material();
	~Material();

	void inline addMat4(std::string name, glm::mat4 matrix);
	void inline addVec3(std::string name, glm::vec3 vector);
	GLuint virtual inline getShaderId();
	void virtual addUniforms(Transform transform);
	virtual void bind();


};


class AmbientMaterial : public Material
{
public:
	void virtual addUniforms(Transform transform);

};

