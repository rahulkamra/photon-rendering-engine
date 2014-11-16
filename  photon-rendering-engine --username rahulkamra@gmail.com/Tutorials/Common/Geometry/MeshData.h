#pragma once
#include <GL\glew.h>
#include <Common\Vertex.h>


class MeshData
{

private :
	bool requireResync = true;
	
public:
	MeshData(Vertex* vertices, GLuint numVertices, GLushort* indices, GLuint numIndices);
	MeshData();
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
	void bind();
	void cleanup();
};