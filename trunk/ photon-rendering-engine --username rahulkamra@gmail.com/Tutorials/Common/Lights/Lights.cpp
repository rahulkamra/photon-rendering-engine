#include "Lights.h"
#include "Electron.h"
#include "Common\Materials\MaterialsManager.h"


void BaseLight::addedToGameObj(){}
void BaseLight::updateUniforms(Material* material){}
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


GLuint DirectionalLight::getShaderId()
{
	return MaterialsManager::getMaterial(MaterialsList::DIRECTIONAL_LIGHT);
}



void DirectionalLight::updateUniforms(Material* material)
{
	glm::vec3 forward =  parent->transform.forward();
	material->addVec3("directionalLight.direction", parent->transform.forward());
}


GLuint PointLight::getShaderId()
{
	return MaterialsManager::getMaterial(MaterialsList::POINT_LIGHT);
}



void PointLight::updateUniforms(Material* material)
{
	material->addVec3("pointLight.position", parent->transform.getPosition());
}