#include "Electron.h"
#include <Common\Renderer\BasicMeshRenderer.h>
#include "Common\Renderer\NormalsRenderer.h"
#include <vector>
#include <GL/freeglut.h>
#include <Common\Geometry\Premitives\Cube.h>
#include <Common\Materials\MaterialsList.h>
#include <Common\Materials\MaterialsManager.h>
#include <MeshRenderingComponent.h>
#include "Lights\Lights.h"
#include "Shader.h"

const int Electron::PHASE_FORWARD_RENDERING = 100;
const int Electron::PHASE_DEFFERED_RENDERING = 200;
const int Electron::PHASE_WIDGETS_RENDERING = 300;


glm::vec3 Electron::ambientLight(1.0f, 1.0f, 1.0f);

vector<BaseLight*> Electron::lights;
BaseLight* Electron::activeLight;

vector<GameObj*> Electron::gameObjs;

vector<MeshRenderingComponent*> Electron::forwardRenderingComponents;
vector<MeshRenderingComponent*> Electron::deferredRenderingComponents;
vector<MeshRenderingComponent*> Electron::widgetsRenderingComponents;



GameObj* Electron::root;
int Electron::currentPhaseRendering;



void Electron::render()
{
	forwardRenderingComponents.clear();
	deferredRenderingComponents.clear();
	widgetsRenderingComponents.clear();

	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	root->render(); // the rendering compoenents will be rendered later

	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LESS);
	glDisable(GL_BLEND);

	drawPhase(forwardRenderingComponents);



	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);
	glDepthMask(GL_FALSE);
	glDepthFunc(GL_EQUAL);


	for (int count = 0; count < lights.size(); count++)
	{
		activeLight = lights.at(count);
		activeLight->bind();
		activeLight->updateUniforms();
		drawPhase(forwardRenderingComponents);
	}
		
	
	
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LESS);
	glDisable(GL_BLEND);
	
	activeLight = NULL;

	drawPhase(deferredRenderingComponents);
	drawPhase(widgetsRenderingComponents);

	

	glClear(GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
	
}


void Electron::drawPhase(vector<MeshRenderingComponent*> renderingComponents , Material* material)
{
	
	for (int count = 0; count < renderingComponents.size(); count++)
	{
		MeshRenderingComponent* eachComponent = renderingComponents.at(count);
		Shader* shader;

		if (Electron::activeLight)
		{
			shader = Electron::activeLight->shader;
		}
		else
		{
			eachComponent->getMaterial()->bind();
			shader = eachComponent->getMaterial()->shader;

		}
		eachComponent->draw(shader);
	}
}


void Electron::addRenderingComponent(MeshRenderingComponent* meshRenderingComponent)
{
	switch (meshRenderingComponent->phase)
	{
		case Electron::PHASE_FORWARD_RENDERING:
		{
		   forwardRenderingComponents.push_back(meshRenderingComponent);
		   break;
		}
		case Electron::PHASE_DEFFERED_RENDERING:
		{
			deferredRenderingComponents.push_back(meshRenderingComponent);
			break;
		}

		case Electron::PHASE_WIDGETS_RENDERING:
		{
			widgetsRenderingComponents.push_back(meshRenderingComponent);
			break;
		}
	}
}
void Electron::add(GameObj* gameObj)
{
	root->addChild(gameObj);
}


void Electron::addLight(BaseLight* light)
{
	lights.push_back(light);
}


void Electron::init()
{
	root = new GameObj();
}