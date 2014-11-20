#include "Mesh.h"
#include "Camera.h"
#include "Electron.h"
#include "Common\Materials\Material.h"
#include "Common\Materials\MaterialsManager.h"
#include "Common\Lights\DiffuseLightManager.h"

Mesh::Mesh(vector<MeshData*> meshData)
{
	this->meshData = meshData;
}

Mesh::Mesh(MeshData* meshData)
{
	this->meshData.push_back(meshData);
}

Mesh::~Mesh()
{
	//glDeleteBuffers(1, &IBO);
	//glDeleteBuffers(1, &VBO);
}

void Mesh::cleanup()
{
	for (int count = 0; count < this->meshData.size(); count++)
	{
		MeshData* _meshData = this->meshData.at(count);
		_meshData->cleanup();
	}
}

void Mesh::draw(Transform modelToWorld)
{
	for (int count = 0; count < this->meshData.size(); count++)
	{
		MeshData* _meshData = this->meshData.at(count);
		_meshData->bind();
		glDrawElements(GL_TRIANGLES, _meshData->numIndices, GL_UNSIGNED_SHORT, (void *)0);
		glBindVertexArray(0);

	}

	


	
}


void LineMesh::draw(Transform modelToWorld)
{
	for (int count = 0; count < this->meshData.size(); count++)
	{
		MeshData* _meshData = this->meshData.at(count);
		_meshData->bind();
		glDrawElements(GL_LINES, _meshData->numIndices, GL_UNSIGNED_SHORT, (void *)0);
		glBindVertexArray(0);
	}
	
}



LineMesh::LineMesh(MeshData* meshData) :Mesh(meshData)
{
	
}

