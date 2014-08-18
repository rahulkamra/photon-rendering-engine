#include <Camera.h>
#include <GL/glew.h>

Camera* Camera::camera;

Camera::Camera() : viewDirection(0.0f, 0.0f, -1.0f), UP(0.0f,1.0f,0.0f)
{
}

glm::mat4 Camera::getWorldToView() const
{
	return glm::lookAt(position, position + viewDirection, UP);
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
	position += UP*distance;
}
void Camera::moveBackward(float distance)
{
	position -= UP*distance;
}
void Camera::moveLeft(float distance)
{
	position -= getRIGHT()*distance;
}
void Camera::moveRight(float distance)
{
	position += getRIGHT()*distance;
}
void Camera::moveUp()
{
	position += viewDirection*MOVE_SPEED;
}
void Camera::moveDown()
{
	position -= viewDirection*MOVE_SPEED;
}



