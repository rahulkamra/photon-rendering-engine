#include "Transform.h"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

Transform::Transform()
{
}


Transform::~Transform()
{
}


void Transform::translate(glm::vec3 translate)
{
	this->translationMatrix = glm::translate(translationMatrix, translate);
}

void Transform::rotate(float angle, glm::vec3 axis)
{
	this->rotationMatrix = glm::rotate(rotationMatrix, angle, axis);
}

void Transform::scale(glm::vec3 scale)
{
	
	this->scaleMatrix = glm::scale(scaleMatrix, scale);
}

glm::mat4 Transform::modelTransformtionMatrix() const
{
	return this->translationMatrix * this->rotationMatrix * this->scaleMatrix;
}


glm::vec3 Transform::forward()
{
	glm::vec3 forward = (glm::vec3)(modelTransformtionMatrix()*glm::vec4(0, 0, 1, 0));
	forward = glm::normalize(forward);
	return forward;
}


glm::vec3 Transform::getPosition()
{
	glm::vec3 position = (glm::vec3)(translationMatrix*glm::vec4(0, 0, 0, 1));
	return position;
}