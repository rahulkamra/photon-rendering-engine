
#define WIN32 1
#define GLM_FORCE_RADIANS

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

#include "glm\gtx\euler_angles.hpp"

#include "glm\gtc\quaternion.hpp"
#include "glm\gtx\quaternion.hpp"

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
		Camera::getCamera()->moveUp(0.2f);
		break;

	case GLUT_KEY_PAGE_DOWN:
		Camera::getCamera()->moveDown(0.2f);
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

static GameObj* arrow;
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
	pyramid->transform.translate(vec3(-2.5f, -1.8f, -6.0f));
	pyramid->transform.scale(vec3(0.5f, 0.5f, 0.5f));
	Electron::add(pyramid);

	GameObj* torus = new GameObj();
	torus->addComponent(new MeshRenderingComponent(new Torus(), new DiffuseMaterial()));
	torus->transform.translate(vec3(-2.5f, -1.8f, -6.0f));
	torus->transform.scale(vec3(0.5f, 0.5f, 0.5f));
	Electron::add(torus);

	Electron::ambientLight = vec3(0.2f, 0.2f, 0.2f);

	GameObj* pointLightGreen = new GameObj();
	pointLightGreen->addComponent(new PointLight(Attenuation(), glm::vec3(0, 1, 0),10));

	pointLightGreen->addComponent(new WidgetRenderingComponent(new LineMesh(ShapeGenerator::createDirectionalWidget(0.2, 50, 5))));
	//directionalLight->showAxis();
	pointLightGreen->transform.translate(vec3(-1, -1, -6.0f));
	pointLightGreen->transform.rotate(Quaternion(180, vec3(0, 1, 0)));
	pointLightGreen->transform.rotate(Quaternion(45, vec3(1, 0, 0)));
	pointLightGreen->transform.scale(vec3(0.1f, 0.1f, 0.1f));
	//Electron::add(pointLightGreen);


	GameObj* pointLightRed = new GameObj();
	pointLightRed->addComponent(new PointLight(Attenuation(), glm::vec3(1, 0, 0)));
	pointLightRed->addComponent(new WidgetRenderingComponent(new LineMesh(ShapeGenerator::createDirectionalWidget(0.2, 50, 5))));
	pointLightRed->transform.translate(vec3(3, -1, -6.0f));
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
	directionalLightYellow->addComponent(new DirectionalLight(glm::vec3(0.5, 0.5, 0.5)));
	directionalLightYellow->addComponent(new WidgetRenderingComponent(new LineMesh(ShapeGenerator::createDirectionalWidget(0.2, 50, 5))));
	directionalLightYellow->transform.translate(vec3(3, -1, -6.0f));
	directionalLightYellow->transform.scale(vec3(0.1f, 0.1f, 0.1f));
	//directionalLightYellow->transform.rotate(Quaternion(glm::vec3(45, 0, 0)));
	Electron::add(directionalLightYellow);


	Transform trans;
	//trans.translate(glm::vec3(100,100,0));
	
	trans.rotate(Quaternion(glm::vec3(90, 180, -270)));
	glutMainLoop();

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
