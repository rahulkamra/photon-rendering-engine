#include <DiffuseMaterial.h>
#include "Common\Materials\MaterialsManager.h"
#include "Common\Materials\MaterialsList.h"
#include "Common\Lights\Lights.h"
#include "Electron.h"


void DiffuseMaterial::bind()
{
	BaseLight* activeLight = Electron::activeLight;
	activeLight->bind();//when this material is binded the active light is binded
}

GLuint DiffuseMaterial::getShaderId()
{
	BaseLight* activeLight = Electron::activeLight;
	return activeLight->getShaderId();
}


void DiffuseMaterial::addUniforms(Transform transform)
{
	Material::addUniforms(transform);
	BaseLight* light = Electron::activeLight;
	if (light == NULL)
		return;

	light->updateUniforms(this);
	
}