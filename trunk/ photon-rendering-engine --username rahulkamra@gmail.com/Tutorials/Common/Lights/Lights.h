#pragma once
#include "Common\GameObj\GameComponent.h"
#include <GL\glew.h>
#include <glm\glm.hpp>

class Material;
class BaseLight : public GameComponent
{

public:
	BaseLight(glm::vec3 color = glm::vec3(1, 1, 1));
	
	glm::vec3 color;
	void addedToGameObj();
	void virtual bind();
	GLuint virtual getShaderId();
	virtual void addedToStage();
	void virtual updateUniforms(Material* material);
};

class DirectionalLight : public BaseLight
{
public:
	DirectionalLight(glm::vec3 color = glm::vec3(1, 1, 1));
	GLuint virtual getShaderId();
	void virtual updateUniforms(Material* material);
};


class PointLight : public BaseLight
{
public:
	PointLight(glm::vec3 color = glm::vec3(1,1,1));
	GLuint virtual getShaderId();
	void virtual updateUniforms(Material* material);
};


