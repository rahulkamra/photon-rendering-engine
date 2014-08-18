#include "Lights.h"
#include "Electron.h"
#include "Common\Materials\MaterialsManager.h"


void BaseLight::addedToGameObj()
{
	Electron::lights.push_back(this);
}

BaseLight::BaseLight()
{

}
BaseLight::~BaseLight()
{

}

/*

*/
DirectionalLight::DirectionalLight()
{
	
}
DirectionalLight::~DirectionalLight()
{
}

void DirectionalLight::bind()
{
	glUseProgram(getShaderId());
}

GLuint DirectionalLight::getShaderId()
{
	return MaterialsManager::getMaterial(MaterialsList::DIRECTIONAL_LIGHT);
}



void DirectionalLight::updateUniforms(Material* material)
{
	glm::vec3 forward =  parent->transform.forward();
	material->addVec3("directionalLight.direction", parent->transform.forward());
}
