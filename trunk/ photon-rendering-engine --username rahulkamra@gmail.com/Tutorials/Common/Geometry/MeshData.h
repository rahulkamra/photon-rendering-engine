#pragma once
#include <GL\glew.h>
#include <Common\Vertex.h>


class MeshData
{

public:
	MeshData(Vertex* vertices, GLuint numVertices, GLushort* indices, GLuint numIndices);

	Vertex* vertices;
	GLuint numVertices;
	GLushort* indices;
	GLuint numIndices;

	GLsizeiptr vertexBufferSize() const;
	GLsizeiptr indexBufferSize() const;

	GLuint vertexArrayId;
	GLuint IBO;
	GLuint VBO;

	void createIndexBuffer();
	void createVertexBuffer();
	void createVertexArrays();

	void cleanup();
};