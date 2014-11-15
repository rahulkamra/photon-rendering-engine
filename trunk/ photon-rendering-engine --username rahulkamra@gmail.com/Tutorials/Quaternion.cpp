#include "Quaternion.h"


Quaternion::Quaternion()
{
	nativeQuat = glm::quat();
}
Quaternion::Quaternion(float angle, glm::vec3 axis)
{
	nativeQuat =  glm::angleAxis(angle, axis);
}

Quaternion::Quaternion(glm::vec3 eulerAngles)
{

	eulerAngles = glm::vec3(ToRadian(eulerAngles.x), ToRadian(eulerAngles.y), ToRadian(eulerAngles.z));
	nativeQuat =  glm::quat(eulerAngles);
}

Quaternion::Quaternion(glm::quat quat)
{
	this->nativeQuat = quat;
}


glm::mat4x4 Quaternion::toMat4x4()
{
	return glm::mat4_cast(nativeQuat);
}
glm::vec3 Quaternion::toEuler()
{
	return glm::eulerAngles(nativeQuat);
}
glm::quat Quaternion::lookAt(glm::vec3 position, glm::vec3 viewDirection, glm::vec3 upVector)
{
	glm::mat4x4 mat4 = glm::lookAt(position, viewDirection, upVector);
	return glm::quat(mat4);
}

Quaternion Quaternion::operator*(const Quaternion& b)
{
	return Quaternion(this->nativeQuat * b.nativeQuat);
}

Quaternion::~Quaternion()
{
}
