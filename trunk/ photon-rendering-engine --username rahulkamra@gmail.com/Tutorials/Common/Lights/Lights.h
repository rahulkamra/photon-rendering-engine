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

class Attenuation
{
public:
	float constant = 0;
	float linear = 0;
	float quadratic = 1;

};


class PointLight : public BaseLight
{	
public:
	Attenuation attenuation;
	float range;
	PointLight(Attenuation attenuation, glm::vec3 color = glm::vec3(1, 1, 1), float range = 1.0f);
	GLuint virtual getShaderId();
	void virtual updateUniforms(Material* material);
};


class SpotLight : public PointLight
{
public:
	float cutoff;
	GLuint virtual getShaderId();
	void virtual updateUniforms(Material* material);
	SpotLight(Attenuation attenuation, glm::vec3 color = glm::vec3(1, 1, 1), float range = 10.0f,float cutoff = 0.7f);
};



