
#define WIN32 1

#include <GL/glew.h>
#include <assert.h>
#include <ogldev_util.h>
#include <ogldev_types.h>
#include <GL/freeglut.h>
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

#include <Common\GameObj\GameObj.h>
#include <Camera.h>
#include "CameraController.h";
#include "Common\Renderer\BasicMeshRenderer.h";

#include "Common\Geometry\Premitives\Premitives.h"
#include "Common\Materials\MaterialsManager.h"
#include "Common\Materials\MaterialsList.h"
#include <MeshRenderingComponent.h>
#include "Electron.h";
#include "Common\Lights\Lights.h";
#include "DiffuseMaterial.h"

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


bool CameraController::_isMouseDown = false;

static void enterFrame()
{
	glutPostRedisplay();
	
}


static void InitializeGlutCallbacks()
{
	glutIdleFunc(enterFrame);
	glutDisplayFunc(Electron::render);
	//glutDisplayFunc(draw);
	
}



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
	if (state == GLUT_DOWN)
	{
		CameraController::handleDown(button);
	}


	if (state == GLUT_UP)
	{
		CameraController::handleUp();
	}
}


void keySpecialUp(int key, int x, int y) 
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		Camera::getCamera()->moveLeft(0.2f);
		break;

	case GLUT_KEY_RIGHT:
		Camera::getCamera()->moveRight(0.2f);
		break;

	case GLUT_KEY_UP:
		Camera::getCamera()->moveForward(0.2f);
		break;

	case GLUT_KEY_DOWN:
		Camera::getCamera()->moveBackward(0.2f);
		break;

	case GLUT_KEY_PAGE_UP:
		Camera::getCamera()->moveUp();
		break;

	case GLUT_KEY_PAGE_DOWN:
		Camera::getCamera()->moveDown();
			break;

	}

}


void mouseWheel(int button, int dir, int x, int y)
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

int main(int argc, char** argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Tutorial 01");
	glEnable(GL_DEPTH_TEST);
	InitializeGlutCallbacks();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	Camera* camera = new Camera();
	Camera::setCamera(camera);

	glutMotionFunc(mouseMove);
	glutPassiveMotionFunc(updateMousePosition);
	glutMouseFunc(mouseDownUp);
	glutMouseWheelFunc(mouseWheel);


	glutSpecialUpFunc(keySpecialUp);

	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		while (1);
		return 1;
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
	plane->transform.translate(vec3(0, -2.0f, -6.0f));
	plane->addComponent(new MeshRenderingComponent(new Plane(), new DiffuseMaterial()));
	Electron::add(plane);


	GameObj* teapot = new GameObj();
	teapot->addComponent(new MeshRenderingComponent(new TeaPot(), new DiffuseMaterial()));
	teapot->addComponent(new WidgetRenderingComponent(new LineMesh(ShapeGenerator::createAxis())));
	teapot->transform.translate(vec3(1.5f, -2.0f, -6.0f));
	teapot->transform.rotate(270.0f, vec3(1.0f, 0.0f, 0.0f));
	teapot->transform.scale(vec3(0.5f, 0.5f, 0.5f));
	Electron::add(teapot);

	GameObj* pyramid = new GameObj();
	pyramid->addComponent(new MeshRenderingComponent(new Pyramid(), new DiffuseMaterial()));
	pyramid->transform.translate(vec3(-2.5f, -1.8f, -6.0f));
	pyramid->transform.scale(vec3(0.5f, 0.5f, 0.5f));
	Electron::add(pyramid);

	GameObj* torus = new GameObj();
	torus->addComponent(new MeshRenderingComponent(new Torus(), new DiffuseMaterial()));
	torus->transform.translate(vec3(-2.5f, -1.8f, -6.0f));
	torus->transform.scale(vec3(0.5f, 0.5f, 0.5f));
	Electron::add(torus);

	Electron::ambientLight = vec3(1.0f, 0.5f, 0.1f);


	GameObj* light = new GameObj();
	light->addComponent(new DirectionalLight());
	light->addComponent(new WidgetRenderingComponent(new LineMesh(ShapeGenerator::createDirectionalWidget(0.2,50,5))));
	light->addComponent(new WidgetRenderingComponent(new LineMesh(ShapeGenerator::createAxis())));
	light->transform.translate(vec3(0, 0, -6.0f));
	light->transform.rotate(0.0f,vec3(1,0,0));
	light->transform.scale(vec3(0.1f, 0.1f, 0.1f));
	Electron::add(light);

	glutMainLoop();

}
