#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\quaternion.hpp>
#include <MathDefine.h>
class Quaternion
{
private:
	glm::quat nativeQuat;
	
public:
	Quaternion(float angle, glm::vec3 axis);
	Quaternion(glm::vec3 eulerAngles);
	Quaternion();
	Quaternion(glm::quat);
	

	glm::mat4x4 toMat4x4();
	glm::vec3 toEuler();
	glm::quat lookAt(glm::vec3 position, glm::vec3 viewDirection, glm::vec3 upVector);

	Quaternion operator*(const Quaternion& b);
	

	~Quaternion();
};

