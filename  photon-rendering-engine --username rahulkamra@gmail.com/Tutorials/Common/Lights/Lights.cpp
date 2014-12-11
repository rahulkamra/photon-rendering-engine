#include "Lights.h"
#include "Electron.h"
#include <Shader.h>
#include "Common\Materials\ShaderLoader.h"


void BaseLight::addedToGameObj(){}
void BaseLight::updateUniforms(){};

BaseLight::BaseLight(glm::vec3 color)
{
	this->color = color;
}

void BaseLight::setShader(Shader* shader)
{
	this->shader = shader;
}
void BaseLight::addedToStage()
{
	Electron::lights.push_back(this);
}

/*

*/

DirectionalLight::DirectionalLight(glm::vec3 color) :BaseLight(color)
{
	this->color = color;
	setShader(new Shader(MaterialsList::DIRECTIONAL_LIGHT));
}


void DirectionalLight::updateUniforms()
{
	BaseLight::updateUniforms();
}



PointLight::PointLight(Attenuation attenuation, glm::vec3 color, float range) :BaseLight(color)
{
	this->attenuation = attenuation;
	this->range = range;
	setShader(new Shader(MaterialsList::POINT_LIGHT));
}

void PointLight::updateUniforms()
{
	BaseLight::updateUniforms();
}


SpotLight::SpotLight(Attenuation attenuation, glm::vec3 color, float range, float cutoff) :PointLight(attenuation,color,range)
{
	this->cutoff = cutoff;
	setShader(new Shader(MaterialsList::SPOT_LIGHT));
}

void SpotLight::updateUniforms()
{
	BaseLight::updateUniforms();
}
