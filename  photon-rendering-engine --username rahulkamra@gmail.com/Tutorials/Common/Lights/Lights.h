#pragma once
#include "Common\GameObj\GameComponent.h"
#include <GL\glew.h>
#include <glm\glm.hpp>

class Material;
class Shader;

class BaseLight : public GameComponent
{

protected:
	void setShader(Shader* shader);

public:
	BaseLight(glm::vec3 color = glm::vec3(1, 1, 1));
	
	glm::vec3 color;
	void addedToGameObj();
	void virtual bind();
	virtual void addedToStage();
	Shader* shader;

	void virtual updateUniforms();
};

class DirectionalLight : public BaseLight
{
public:
	DirectionalLight(glm::vec3 color = glm::vec3(1, 1, 1));
	void virtual updateUniforms();
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
	void virtual updateUniforms();
};


class SpotLight : public PointLight
{
public:
	float cutoff;
	void virtual updateUniforms();
	SpotLight(Attenuation attenuation, glm::vec3 color = glm::vec3(1, 1, 1), float range = 10.0f,float cutoff = 0.7f);
};



