#include <GL/glew.h>
#include <assert.h>
#include <ogldev_util.h>
#include <ogldev_types.h>
#include <iostream>
#include <stdio.h>
#include <math_3d.h>
#include "MyClass.h"
#include <Common\Vertex.h>
#include <Common\ShapeGenerator.h>
#include <glm\vec3.hpp>
#include <glm\vec2.hpp>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <vector>
#include <SDL.h>
#include <Common\GameObj\GameObj.h>
#include <Camera.h>
#include "CameraController.h";
#include "Common\Renderer\BasicMeshRenderer.h";
#include <TextureData.h>
#include <Texture.h>
#include "Common\Geometry\Premitives\Premitives.h"
#include "Common\Materials\ShaderLoader.h"
#include "Common\Materials\MaterialsList.h"
#include <MeshRenderingComponent.h>
#include "Electron.h";
#include "Common\Lights\Lights.h";
#include "DiffuseMaterial.h"

#include "glm\gtx\euler_angles.hpp"

#include "glm\gtc\quaternion.hpp"
#include "glm\gtx\quaternion.hpp"
#include <EMap.h>

using namespace std;
using glm::vec3;
using glm::mat4;

GLuint IBO;
GLuint VBO;
char* pVSFileName = "Camera/shader.vs";
char* pFSFileName = "Camera/shader.fs";
GLuint shaderProgram;

#define PI 3.14159265359

int width = 1024;
int height = 768;

int CameraController::mouseX = 0;
int CameraController::mouseY = 0;

int CameraController::previousX = 0;
int CameraController::previousY = 0;

int CameraController::currentDownButton = 0;

float CameraController::previousRotationX = 0;
float CameraController::previousRotationY = 0;

bool CameraController::_isMouseDown = false;

void mouseMove(int x, int y)
{
	CameraController::updateMouse(x,y);
}


void updateMousePosition(int x, int y)
{
	CameraController::updateMousePosition(x, y);
}

void mouseDownUp(int button, int state, int x, int y)
{
	if (state == SDL_PRESSED)
	{
		CameraController::handleDown(button);
	}


	if (state == SDL_RELEASED)
	{
		CameraController::handleUp();
	}
}


void keySpecialUp(int key, int x, int y) 
{
	switch (key)
	{
	case SDLK_LEFT:
		Camera::getCamera()->moveLeft(0.2f);
		break;

	case SDLK_RIGHT:
		Camera::getCamera()->moveRight(0.2f);
		break;

	case SDLK_UP:
		Camera::getCamera()->moveForward(0.2f);
		break;

	case SDLK_DOWN:
		Camera::getCamera()->moveBackward(0.2f);
		break;

	case SDLK_PAGEUP:
		Camera::getCamera()->moveUp(0.2f);
		break;

	case SDLK_PAGEDOWN:
		Camera::getCamera()->moveDown(0.2f);
			break;

	}

}


void mouseWheel(int dir)
{
	if (dir > 0)
	{
		CameraController::mouseWheelUp();
	}
	else
	{
		CameraController::mouseWheelDown();
	}

	return;
}

void init()
{
	glEnable(GL_DEPTH_TEST);
	Camera* camera = new Camera();
	Camera::setCamera(camera);
	Camera::getCamera()->transform.rotate(Quaternion(glm::vec3(10.0f, 0.0f, 0.0f)));


	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		while (1);
		return;
	}

	Electron::init();

	

	//Triangle triangle;
	//triangle.translate(vec3(0, -2.0f, -6.0f));
	//Electron::add(triangle);

	//Cube cube;
	//Electron::add(cube);


	GameObj* arrow = new GameObj();
	arrow->transform.translate(vec3(0, -2.0f, -6.0f));
	arrow->addComponent(new MeshRenderingComponent(new Arrow(), new DiffuseMaterial()));
	Electron::add(arrow);

	GameObj* plane = new GameObj();
	plane->showAxis();
	plane->transform.translate(vec3(0, -2.0f, -6.0f));
	plane->addComponent(new MeshRenderingComponent(new Plane(), new DiffuseMaterial()));
	Electron::add(plane);


	GameObj* teapot = new GameObj();
	teapot->addComponent(new MeshRenderingComponent(new TeaPot(), new DiffuseMaterial()));
	teapot->showAxis();
	teapot->transform.translate(vec3(1.5f, -2.0f, -6.0f));
	teapot->transform.rotate(Quaternion(270.0f, vec3(1.0f, 0.0f, 0.0f)));
	teapot->transform.scale(vec3(0.5f, 0.5f, 0.5f));
	Electron::add(teapot);

	GameObj* pyramid = new GameObj();
	pyramid->addComponent(new MeshRenderingComponent(new Pyramid(), new DiffuseMaterial()));
	pyramid->transform.translate(vec3(-3.5f, -1.8f, -6.0f));
	pyramid->transform.scale(vec3(0.5f, 0.5f, 0.5f));
	Electron::add(pyramid);


	GameObj* customMesh = ShapeGenerator::createShapeFromFile("res/models/phoenix_ugv.md2");
	customMesh->transform.translate(vec3(-1.5, -1.8f, -6.0f));
	customMesh->transform.scale(vec3(0.02f, 0.02f, 0.02f));

	Electron::add(customMesh);


	GameObj* torus = new GameObj();
	torus->addComponent(new MeshRenderingComponent(new Torus(), new DiffuseMaterial(NULL, 8.0f, 3.0f)));
	torus->transform.translate(vec3(-3.5f, -1.8f, -6.0f));
	torus->transform.scale(vec3(0.5f, 0.5f, 0.5f));
	Electron::add(torus);

	Electron::ambientLight = vec3(0.1f, 0.1f, 0.1f);

	GameObj* pointLightGreen = new GameObj();
	pointLightGreen->addComponent(new PointLight(Attenuation(), glm::vec3(0, 1, 0), 10));

	pointLightGreen->addComponent(new WidgetRenderingComponent(new LineMesh(ShapeGenerator::createDirectionalWidget(0.2, 50, 5))));
	//pointLightGreen->showAxis();
	pointLightGreen->transform.translate(vec3(-2.5, 0, -5.5f));
	pointLightGreen->transform.rotate(Quaternion(180, vec3(0, 1, 0)));
	pointLightGreen->transform.rotate(Quaternion(45, vec3(1, 0, 0)));
	pointLightGreen->transform.scale(vec3(0.1f, 0.1f, 0.1f));
	Electron::add(pointLightGreen);


	GameObj* pointLightRed = new GameObj();
	pointLightRed->addComponent(new PointLight(Attenuation(), glm::vec3(1, 0, 0)));
	pointLightRed->addComponent(new WidgetRenderingComponent(new LineMesh(ShapeGenerator::createDirectionalWidget(0.2, 50, 5))));
	pointLightRed->transform.translate(vec3(1, 0.5, -6.0f));
	pointLightRed->transform.rotate(Quaternion(180, vec3(0, 1, 0)));
	pointLightRed->transform.rotate(Quaternion(45, vec3(1, 0, 0)));
	pointLightRed->transform.scale(vec3(0.1f, 0.1f, 0.1f));
	Electron::add(pointLightRed);


	GameObj* pointLightBlue = new GameObj();
	pointLightBlue->addComponent(new SpotLight(Attenuation(), glm::vec3(0, 0, 1)));
	pointLightBlue->addComponent(new WidgetRenderingComponent(new LineMesh(ShapeGenerator::createDirectionalWidget(0.2, 50, 5))));
	pointLightBlue->showAxis();
	pointLightBlue->transform.translate(vec3(0, -1, -6.0f));
	pointLightBlue->transform.rotate(Quaternion(180, vec3(0, 1, 0)));
	pointLightBlue->transform.rotate(Quaternion(90, vec3(1, 0, 0)));
	pointLightBlue->transform.scale(vec3(0.1f, 0.1f, 0.1f));
	Electron::add(pointLightBlue);


	GameObj* directionalLightYellow = new GameObj();
	directionalLightYellow->addComponent(new DirectionalLight(glm::vec3(0.1, 0.1, 0.1)));
	directionalLightYellow->addComponent(new WidgetRenderingComponent(new LineMesh(ShapeGenerator::createDirectionalWidget(0.2, 50, 5))));
	directionalLightYellow->transform.translate(vec3(3, -1, -6.0f));
	directionalLightYellow->transform.scale(vec3(0.1f, 0.1f, 0.1f));
	directionalLightYellow->transform.rotate(Quaternion(glm::vec3(45, 0, 0)));
	Electron::add(directionalLightYellow);



	GameObj* triangle = new GameObj();
	//directionalLightYellow->addComponent(new DirectionalLight(glm::vec3(0.5, 0.5, 0.5)));
	//directionalLightYellow->addComponent(new WidgetRenderingComponent(new LineMesh(ShapeGenerator::createDirectionalWidget(0.2, 50, 5))));
	triangle->transform.translate(vec3(0, -1, -2.0f));
	triangle->transform.scale(vec3(0.1f, 0.1f, 0.1f));
	//triangle->transform.rotate(Quaternion(glm::vec3(45, 0, 0)));


	TextureData* textureData = new TextureData("res/textures/test.png");
	textureData->load();

	Texture* texture = new Texture(textureData);
	triangle->addComponent(
		new MeshRenderingComponent(
		new Mesh(
		ShapeGenerator::makeTriangle()
		), new DiffuseMaterial(texture)));
	triangle->showAxis();
	Electron::add(triangle);

	Transform trans;
	trans.translate(glm::vec3(100, 100, 0));

	trans.rotate(Quaternion(glm::vec3(90, 180, -270)));



	EMap<int, int> emap;
	emap.set(1, 100);
	boost::optional<int> intValue =  emap.get(1);

	if (intValue)
		cout << *intValue;
	else
		cout << "Valur Not Found";

	
	//

	//glm::vec3 a;
	//EMap<int, glm::vec3> emap1;
	//emap1.set(1, a);
	//boost::optional<glm::vec3> value   = emap1.get(3);

	//cout << emap1.get(3);



}


static GameObj* arrow;
int main(int argc, char** argv)
{
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = SDL_CreateWindow("Hello",
		100,
		100,
		1024,
		768, SDL_WINDOW_OPENGL);

	if (window == NULL) {
		// In the event that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	
	// The window is open: enter program loop (see SDL_PollEvent)

	bool done = false;
	SDL_Event event;
	Electron::init();
	glClearColor(0, 1, 0, 1);

	

	SDL_GLContext maincontext; /* Our opengl context handle */
	maincontext = SDL_GL_CreateContext(window);

	GLint GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult)
	{
		printf("ERROR: %s\n", glewGetErrorString(GlewInitResult));
		exit(EXIT_FAILURE);
	}

	
	init();
	
	

	while (!done)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				done = true;
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP)
			{
				mouseDownUp(event.button.button, event.button.state, 0, 0);
			}
			else if (event.type == SDL_MOUSEMOTION)
			{
				updateMousePosition(event.button.x, event.button.y);
				mouseMove(event.button.x, event.button.y);
			}
			else if (event.type == SDL_MOUSEWHEEL)
			{
				mouseWheel(event.wheel.y);
			}
			else if (event.type == SDL_KEYDOWN)
			{
				keySpecialUp(event.key.keysym.sym, 0, 0);
				
			}


			Electron::render();
			SDL_GL_SwapWindow(window);
		}
	}
	// Close and destroy the window
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;

}




void testForInverseMatrix()
{
	glm::mat4 translate;
	glm::mat4 rotate;
	glm::mat4 scale;

	translate = glm::translate(translate, glm::vec3(1, 0, 0));
	rotate = glm::rotate(rotate, 45.0f, glm::vec3(1, 0, 0));
	scale = glm::scale(scale, glm::vec3(2, 2, 2));
	
	glm::mat4 transfomation = translate * rotate * scale;
	glm::mat4 transfomationInverse = glm::inverse(transfomation);

	glm::mat4 realInverse = glm::inverse(scale) * glm::inverse(rotate) * glm::inverse(translate);
	//glm::eulerAngles()
	
	int index = 3;
	cout << transfomationInverse[index].x << "   " << transfomationInverse[index].y << " " << transfomationInverse[index].z << "\n";
	cout << realInverse[index].x << " " << realInverse[index].y << " " << realInverse[index].z;
}


void testForFowardVector()
{

}