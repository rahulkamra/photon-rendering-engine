#pragma once
#include <glm\gtc\matrix_transform.hpp>

using glm::vec3;
using glm::mat4;

class Camera
{

	
	static Camera* camera;
	

	

public:
	vec3 position;
	Camera();
	vec3 viewDirection;
	vec3 UP;
	glm::mat4 getWorldToView() const;
	glm::mat4 getProjectionMatrix() const;
	glm::mat4 worldToProjection(mat4 worldMatrix) const;

	void moveForward(float distance);
	void moveBackward(float distance);
	void moveLeft(float distance);
	void moveRight(float distance);
	void moveUp();
	void moveDown();

	float fieldOfView = 60.0f;
	float aspectRatio = 1024.0f / 768.0f;
	float nearPlane = 0.1f;
	float farPlane = 60.0f;

	static Camera* getCamera()
	{
		return  Camera::camera;
	}

	static void setCamera(Camera* _camera)
	{
		Camera::camera = _camera;
	}

	vec3 getRIGHT()
	{
		return glm::normalize(glm::cross(camera->viewDirection, camera->UP));
	}
};


