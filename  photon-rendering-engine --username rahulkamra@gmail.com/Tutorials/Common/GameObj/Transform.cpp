#include "Transform.h"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <iostream>
#include <stdio.h>
using namespace std;

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

void Transform::rotate(Quaternion quat)
{
	this->quaterion =  quat;
}


void Transform::scale(glm::vec3 scale)
{
	
	this->scaleMatrix = glm::scale(scaleMatrix, scale);
}

glm::mat4 Transform::modelTransformtionMatrix()
{
	return this->translationMatrix * this->quaterion.toMat4x4() * this->scaleMatrix;
}


glm::vec3 Transform::forward()
{
	glm::mat4 mat = modelTransformtionMatrix();
	glm::vec3 forward = glm::vec3(mat[2][0], mat[2][1], mat[2][2]);
	forward = glm::normalize(forward);
	return forward;
}

glm::vec3 Transform::backward()
{
	return -forward();
}

glm::vec3 Transform::right()
{
	glm::mat4 mat = modelTransformtionMatrix();
	glm::vec3 right = glm::vec3(mat[0][0], mat[0][1], mat[0][2]);
	right = glm::normalize(right);
	return right;
}

glm::vec3 Transform::left()
{
	return -right();
}


glm::vec3 Transform::up()
{
	glm::mat4 mat = modelTransformtionMatrix();
	glm::vec3 up = glm::vec3(mat[1][0], mat[1][1], mat[1][2]);
	up = glm::normalize(up);
	return up;
}


glm::vec3 Transform::down()
{
	return -up();
}

glm::vec3 Transform::getPosition()
{

	glm::vec3 position = (glm::vec3)(modelTransformtionMatrix()*glm::vec4(0, 0, 0, 1));
//	glm::vec3 position = glm::vec3(translationMatrix[0][3], translationMatrix[1][3], translationMatrix[2][3])

	return position;
}
