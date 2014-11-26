#include "Common\Geometry\MeshData.h"
#include <GL\glew.h>
#include <Common\Vertex.h>

MeshData::MeshData(Vertex* vertices, GLuint numVertices, GLushort* indices, GLuint numIndices)
{
	this->vertices = vertices;
	this->numVertices = numVertices;
	this->indices = indices;
	this->numIndices = numIndices;
}
MeshData::MeshData()
{

}

void MeshData::bind()
{
	if (requireResync)
	{
		createIndexBuffer();
		createVertexBuffer();
		createVertexArrays();
		requireResync = false;
	}

	glBindVertexArray(this->vertexArrayId);
}
GLsizeiptr MeshData::vertexBufferSize() const
{
	return numVertices * sizeof(Vertex);
}


GLsizeiptr MeshData::indexBufferSize() const
{
	return numIndices * sizeof(GLushort);
}

void  MeshData::createVertexArrays()
{
	glGenVertexArrays(1, &vertexArrayId);
	glBindVertexArray(vertexArrayId);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	GLsizei sizeOfVertex = 11 * sizeof(float);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeOfVertex, (void *)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeOfVertex, (void *)(sizeof(float)* 3));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeOfVertex, (void *)(sizeof(float)* 6));
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeOfVertex, (void *)(sizeof(float)* 9));


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	glBindVertexArray(0);
	glDisableVertexAttribArray (0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(3);
}


void MeshData::createIndexBuffer()
{
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBufferSize(), indices, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


void MeshData::createVertexBuffer()
{

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexBufferSize(), vertices, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void MeshData::cleanup()
{
	delete[] vertices;
	delete[] indices;
	numVertices = numIndices = 0;
}