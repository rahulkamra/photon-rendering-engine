#pragma once

#include <glm\vec3.hpp>
#include <glm\vec2.hpp>
#include <glm\gtx\transform.hpp>
#include <Camera.h>
#include <stdio.h>
#include <iostream>
#include <GL/freeglut.h>
#include <Magick++.h>

using glm::vec2;

class CameraController
{

private :
	static int mouseX;
	static int mouseY;

	static int previousX;
	static int previousY;

	static bool _isMouseDown;

	static int currentDownButton;

public :
	static void updateMouse(int x, int y)
	{
		
		vec2 delta = vec2(previousX, previousY) - vec2(x, y);

		Camera* camera = Camera::getCamera();
		if (currentDownButton == GLUT_RIGHT_BUTTON)
		{
			float speed = 0.1f;
			vec3 globalUp = glm::vec3(0, 1, 0);
			vec3 globalRight = glm::vec3(1, 0, 0);

			camera->viewDirection = glm::mat3(glm::rotate(delta.x*speed, globalUp)) * camera->viewDirection;
			camera->viewDirection = glm::mat3(glm::rotate(-delta.y*speed, globalRight)) * camera->viewDirection;
		}
		else if (currentDownButton == GLUT_MIDDLE_BUTTON)
		{
			camera->moveRight(delta.x*0.01);
			camera->moveForward(-delta.y*0.01);
		}
		
		previousX = x;
		previousY = y;
	}

	static void updateMousePosition(int x, int y)
	{
		mouseX = x;
		mouseY = y;
	}
	static void handleDown(int button)
	{
		currentDownButton = button;

		previousX = mouseX;
		previousY = mouseY;
		CameraController::_isMouseDown = true;
	}

	static void handleUp()
	{
		currentDownButton = 0;
		CameraController::_isMouseDown = false;
	}


	static void mouseWheelUp()
	{
		Camera::getCamera()->moveUp();
	}

	static void mouseWheelDown()
	{
		Camera::getCamera()->moveDown();
	}
};

