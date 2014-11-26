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

void BaseLight::bind()
{
	shader->bind();
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
	
	shader->addVec3("directionalLight.direction", parent->transform.forward());
	shader->addVec3("directionalLight.light.color", color);
	//shader->addVec3("ambientLight", Electron::ambientLight);
}



PointLight::PointLight(Attenuation attenuation, glm::vec3 color, float range) :BaseLight(color)
{
	this->attenuation = attenuation;
	this->range = range;
	setShader(new Shader(MaterialsList::POINT_LIGHT));
}

void PointLight::updateUniforms()
{
	shader->addVec3("pointLight.position", parent->transform.getPosition());
	shader->addVec3("pointLight.light.color", color);

	shader->addFloat("pointLight.attenuation.constant", attenuation.constant);
	shader->addFloat("pointLight.attenuation.linear", attenuation.linear);
	shader->addFloat("pointLight.attenuation.quadratic", attenuation.quadratic);

	shader->addFloat("pointLight.range", this->range);
	shader->addVec3("ambientLight", Electron::ambientLight);

}


SpotLight::SpotLight(Attenuation attenuation, glm::vec3 color, float range, float cutoff) :PointLight(attenuation,color,range)
{
	this->cutoff = cutoff;
	setShader(new Shader(MaterialsList::SPOT_LIGHT));
}

void SpotLight::updateUniforms()
{
	shader->addVec3("spotLight.position", parent->transform.getPosition());
	shader->addVec3("spotLight.light.color", color);

	shader->addFloat("spotLight.attenuation.constant", attenuation.constant);
	shader->addFloat("spotLight.attenuation.linear", attenuation.linear);
	shader->addFloat("spotLight.attenuation.quadratic", attenuation.quadratic);
	
	glm::vec3 forw = parent->transform.forward();

	shader->addVec3("spotLight.direction", parent->transform.forward());

	shader->addFloat("spotLight.cutoff", this->cutoff);

	shader->addFloat("spotLight.range", this->range);



}
