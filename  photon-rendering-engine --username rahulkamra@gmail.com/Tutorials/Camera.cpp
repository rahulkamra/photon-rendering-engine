#include <Camera.h>
#include <GL/glew.h>
#include <stdio.h>
#include <iostream>

Camera* Camera::camera;

Camera::Camera() 
{
}

glm::mat4 Camera::getWorldToView() const
{
	return glm::inverse(transform.modelTransformtionMatrix());//This is the inverse because we want world to view , the transformation matrix is camera to the world.	
	//return glm::lookAt(position, position + viewDirection, UP);
}


glm::mat4 Camera::getProjectionMatrix() const
{
	return glm::perspective(fieldOfView, aspectRatio, nearPlane, farPlane);
}


glm::mat4  Camera::worldToProjection(mat4 worldMatrix) const
{
	return Camera::getCamera()->getProjectionMatrix() * Camera::getCamera()->getWorldToView()* worldMatrix;
}


const float MOVE_SPEED = 0.1f;

void Camera::moveForward(float distance)
{
	transform.translate(transform.forward()*distance);
	//position += UP*distance;
}
void Camera::moveBackward(float distance)
{
	transform.translate(transform.backward()*distance);
	//position -= UP*distance;
}
void Camera::moveLeft(float distance)
{
	transform.translate(transform.left()*distance);
}
void Camera::moveRight(float distance)
{
	transform.translate(transform.right()*distance);
}
void Camera::moveUp(float distance)
{
	transform.translate(transform.up()*distance);
}
void Camera::moveDown(float distance)
{
	transform.translate(transform.down()*distance);
}



