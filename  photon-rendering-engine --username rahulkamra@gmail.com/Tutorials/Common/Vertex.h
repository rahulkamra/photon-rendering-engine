#pragma once
#include <glm\glm.hpp>
#include <ogldev_types.h>
#include <ogldev_util.h>
#include <GL/glew.h>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec3 normal;

	GLsizei getSize()
	{
		return 9 * sizeof(float);
	}

	

};


struct VertexUV 
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec3 normal;
	glm::vec2 uv;

	GLsizei getSize()
	{
		return 11 * sizeof(float);
	}
};
