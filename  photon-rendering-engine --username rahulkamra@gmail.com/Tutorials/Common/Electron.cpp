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

	if (lights.size() == 0)
	{
		drawPhase(forwardRenderingComponents);
	}
	else
	{
		for (int count = 0; count < lights.size(); count++)
		{
			activeLight = lights.at(count);
			drawPhase(forwardRenderingComponents);
		}
	}

	drawPhase(deferredRenderingComponents);

	glClear(GL_DEPTH_BUFFER_BIT);
	drawPhase(widgetsRenderingComponents);

	glutSwapBuffers();
}


void Electron::drawPhase(vector<MeshRenderingComponent*> renderingComponents)
{
	for (int count = 0; count < renderingComponents.size(); count++)
	{
		MeshRenderingComponent* eachComponent = renderingComponents.at(count);
		eachComponent->draw();
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