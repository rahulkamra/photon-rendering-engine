#include "Electron.h"
#include <Common\Renderer\BasicMeshRenderer.h>
#include "Common\Renderer\NormalsRenderer.h"
#include <vector>
#include <GL/freeglut.h>
#include <Common\Geometry\Premitives\Cube.h>
#include <Common\Materials\MaterialsList.h>
#include <Common\Materials\MaterialsManager.h>
#include "Lights\Lights.h"


glm::vec3 Electron::ambientLight(1.0f, 1.0f, 1.0f);

vector<BaseLight*> Electron::lights;
BaseLight* Electron::activeLight;

vector<GameObj*> Electron::gameObjs;

GameObj* Electron::root;



void Electron::render()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	addLightsAttrib();


	if (lights.size() == 0)
	{
		root->render();
	}
	else
	{
		for (int count = 0; count < lights.size(); count++)
		{
			activeLight = lights.at(count);
			root->render();
		}
	}

	glutSwapBuffers();
}


void Electron::add(GameObj* gameObj)
{
	root->addChild(gameObj);

	//gameObjs.push_back(gameObj);
}


void Electron::addLightsAttrib()
{
	/*if (lights.size() > 0)
	{
		vec3 light = lights.at(0);
		GLuint directionalLightUniformLocation = glGetUniformLocation(basicrenderer.shaderProgramId, "directionalLight");
		glUniform3fv(directionalLightUniformLocation, 1, &light[0]);
	}*/

}

void Electron::addLight(BaseLight* light)
{
	
	lights.push_back(light);
	//if (showGadget)
	//{
		//Cube gadget;
		//gadget.translate(lightSource);
		//gadget.scale(vec3(0.05f, 0.05f, 0.05f));
		//basicrenderer.addItem(gadget);
	//}
	
}


void Electron::init()
{
	lights;
	root = new GameObj();
	/*for (int count = 0; count < MaterialsList::allShaders.size(); count++)
	{
		string eachItem = MaterialsList::allShaders.at(count);

		string shaderName = eachItem;
		string vertexShaderFileName = VERTEX_SHADER_PATH(shaderName);
		string fragmentShaderFileName = FRAGMENT_SHADER_PATH(shaderName);

		MaterialsManager::registerMaterial(shaderName.c_str(), vertexShaderFileName.c_str(), fragmentShaderFileName.c_str());
	}*/
}