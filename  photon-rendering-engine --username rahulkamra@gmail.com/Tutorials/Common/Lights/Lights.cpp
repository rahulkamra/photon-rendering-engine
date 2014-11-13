#include "Lights.h"
#include "Electron.h"
#include "Common\Materials\MaterialsManager.h"


void BaseLight::addedToGameObj(){}
void BaseLight::updateUniforms(Material* material){};

BaseLight::BaseLight(glm::vec3 color)
{
	this->color = color;
}

GLuint BaseLight::getShaderId(){ return 0; }

void BaseLight::addedToStage()
{
	Electron::lights.push_back(this);
}



void BaseLight::bind()
{
	glUseProgram(getShaderId());
}


/*

*/

DirectionalLight::DirectionalLight(glm::vec3 color) :BaseLight(color)
{
	this->color = color;
}

GLuint DirectionalLight::getShaderId()
{
	return MaterialsManager::getMaterial(MaterialsList::DIRECTIONAL_LIGHT);
}



void DirectionalLight::updateUniforms(Material* material)
{
	BaseLight::updateUniforms(material);
	glm::vec3 forward =  parent->transform.forward();
	material->addVec3("directionalLight.direction", parent->transform.forward());
	material->addVec3("directionalLight.light.color",color);
	material->addVec3("ambientLight", Electron::ambientLight);
}



PointLight::PointLight(Attenuation attenuation, glm::vec3 color, float range) :BaseLight(color)
{
	this->attenuation = attenuation;
	this->range = range;

}


GLuint PointLight::getShaderId()
{
	return MaterialsManager::getMaterial(MaterialsList::POINT_LIGHT);
}



void PointLight::updateUniforms(Material* material)
{
	material->addVec3("pointLight.position", parent->transform.getPosition());
	material->addVec3("pointLight.light.color", color);

	material->addFloat("pointLight.attenuation.constant", attenuation.constant);
	material->addFloat("pointLight.attenuation.linear", attenuation.linear);
	material->addFloat("pointLight.attenuation.quadratic", attenuation.quadratic);

	material->addFloat("pointLight.range", this->range);
	material->addVec3("ambientLight", Electron::ambientLight);

}


SpotLight::SpotLight(Attenuation attenuation, glm::vec3 color, float range, float cutoff) :PointLight(attenuation,color,range)
{
	this->cutoff = cutoff;
}


GLuint SpotLight::getShaderId()
{
	return MaterialsManager::getMaterial(MaterialsList::SPOT_LIGHT);
}

void SpotLight::updateUniforms(Material* material)
{
	material->addVec3("spotLight.position", parent->transform.getPosition());
	material->addVec3("spotLight.light.color", color);

	material->addFloat("spotLight.attenuation.constant", attenuation.constant);
	material->addFloat("spotLight.attenuation.linear", attenuation.linear);
	material->addFloat("spotLight.attenuation.quadratic", attenuation.quadratic);
	
	material->addVec3("spotLight.direction", parent->transform.forward());

	material->addFloat("spotLight.cutoff", this->cutoff);

	material->addFloat("spotLight.range", this->range);
	material->addVec3("ambientLight", Electron::ambientLight);


}
