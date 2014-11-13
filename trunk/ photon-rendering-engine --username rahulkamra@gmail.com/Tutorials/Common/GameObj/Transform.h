#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\quaternion.hpp>
#include <Quaternion.h>
class Transform
{

private:
	
public:
	Transform();
	~Transform();

	glm::mat4 localMatrix;
	glm::mat4 translationMatrix;
	glm::mat4 scaleMatrix;
	Quaternion quaterion;
	
	void translate(glm::vec3 translate);
	void rotate(Quaternion quat);
	void scale(glm::vec3 scale);
	glm::mat4 modelTransformtionMatrix();

	glm::vec3 forward();
	glm::vec3 backward();
	glm::vec3 right();
	glm::vec3 left();

	glm::vec3 up();
	glm::vec3 down();

	glm::vec3 getPosition();

	glm::vec3 lookAt(glm::vec3 position , glm::vec3 upVector);
};

