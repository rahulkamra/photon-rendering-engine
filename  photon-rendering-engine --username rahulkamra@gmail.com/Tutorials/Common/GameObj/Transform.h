#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

class Transform
{

private:
	glm::mat4 localMatrix;
	glm::mat4 translationMatrix;
	glm::mat4 scaleMatrix;
	glm::mat4 rotationMatrix;


public:
	Transform();
	~Transform();


	void translate(glm::vec3 translate);
	void rotate(float angle, glm::vec3 axis);
	void scale(glm::vec3 scale);
	glm::mat4 modelTransformtionMatrix() const;

	glm::vec3 forward();
	glm::vec3 getPosition();
};

