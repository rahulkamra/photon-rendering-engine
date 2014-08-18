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
	glm::vec3 forward =  (glm::vec3)(glm::vec4(0, 0, 1, 0) * this->rotationMatrix);
	forward = glm::normalize(forward);
	return forward;
}